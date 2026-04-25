<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests;

use PDO;
use Phalcon\DataMapper\Pdo\Connection;
use ReflectionClass;
use ReflectionException;

use function array_filter;
use function date;
use function env;
use function explode;
use function file_exists;
use function file_get_contents;
use function get_class;
use function getOptionsMysql;
use function getOptionsPostgresql;
use function getOptionsSqlite;
use function implode;
use function is_string;
use function preg_match;
use function preg_split;
use function sprintf;
use function strlen;
use function substr;
use function trim;

use const PREG_SPLIT_NO_EMPTY;

abstract class AbstractDatabaseTestCase extends AbstractUnitTestCase
{
    /**
     * @var PDO|null
     */
    private static ?PDO $connection = null;

    /**
     * @var bool
     */
    private static bool $schemaLoaded = false;

    /**
     * @var string
     */
    private static string $driver = 'sqlite';

    /**
     * @var string
     */
    private static string $password = '';

    /**
     * @var string
     */
    private static string $username = '';

    /**
     * @return PDO|null
     */
    public static function getConnection(): PDO | null
    {
        return self::$connection;
    }

    /**
     * @return Connection
     */
    public static function getDataMapperConnection(): Connection
    {
        return new Connection(
            self::getDatabaseDsn(),
            self::getDatabaseUsername(),
            self::getDatabasePassword()
        );
    }

    /**
     * @return string
     */
    public static function getDatabaseDsn(): string
    {
        switch (self::$driver) {
            case 'mysql':
                self::$password = env('DATA_MYSQL_PASS', '');
                self::$username = env('DATA_MYSQL_USER', 'root');

                return sprintf(
                    "mysql:host=%s;dbname=%s;charset=utf8mb4;port=%s",
                    env('DATA_MYSQL_HOST', '127.0.0.1'),
                    env('DATA_MYSQL_NAME', 'phalcon'),
                    env('DATA_MYSQL_PORT', 3306)
                );
            case 'pgsql':
            case 'postgres':
                self::$password = env('DATA_POSTGRES_PASS', '');
                self::$username = env('DATA_POSTGRES_USER', 'postgres');

                return sprintf(
                    "pgsql:host=%s;dbname=%s;user=%s;password=%s",
                    env('DATA_POSTGRES_HOST', '127.0.0.1'),
                    env('DATA_POSTGRES_NAME', 'phalcon'),
                    self::$username,
                    self::$password
                );
            case 'sqlite':
                return sprintf(
                    'sqlite:%s',
                    env('DATA_SQLITE_NAME', 'memory')
                );

            case 'sqlsrv':
                return "";
            default:
                return "sqlite:memory";
        }
    }

    /**
     * @param string $driver
     *
     * @return string
     */
    public static function getDatabaseNow(string $driver): string
    {
        switch ($driver) {
            case "sqlite":
                return date("'Y-m-d H:i:s'");
            default:
                return "NOW()";
        }
    }

    /**
     * @return array
     */
    public static function getDatabaseOptions(): array
    {

        return match (self::$driver) {
            'pgsql', 'postgres' => getOptionsPostgresql(),
            'sqlsrv' => getOptionsSqlite(),
            'mysql' => getOptionsMysql(),
            default => [],
        };
    }

    /**
     * @return string
     */
    public static function getDatabasePassword(): string
    {
        return self::$password;
    }

    /**
     * @return string
     */
    public static function getDatabaseUsername(): string
    {
        return self::$username;
    }

    /**
     * @return string
     */
    public static function getDriver(): string
    {
        return self::$driver;
    }

    /**
     * @param string $table
     * @param array  $criteria
     *
     * @return void
     */
    public function assertInDatabase(string $table, array $criteria = []): void
    {
        $records = $this->getFromDatabase($table, $criteria);

        $this->assertNotEmpty($records);
    }

    /**
     * @param string $table
     * @param array  $criteria
     *
     * @return void
     */
    public function assertNotInDatabase(string $table, array $criteria = []): void
    {
        $records = $this->getFromDatabase($table, $criteria);

        $this->assertEmpty($records);
    }

    /**
     * @return void
     */
    public static function setUpBeforeClass(): void
    {
        self::$driver = env('driver');

        if (self::$connection === null) {
            /**
             * username and password are populated here
             */
            $dsn = self::getDatabaseDsn();

            self::$connection = new PDO(
                $dsn,
                self::$username,
                self::$password
            );

            if (self::$driver === 'sqlite') {
                self::$connection->exec('PRAGMA journal_mode = WAL');
            }

            $queries = explode(';', env('initial_queries', ''));
            $queries = array_filter($queries);
            foreach ($queries as $query) {
                self::$connection->exec($query);
            }
        }

        if (!self::$schemaLoaded) {
            $dumpFile = env('dump_file', '');
            if (file_exists($dumpFile)) {
                $sql = file_get_contents($dumpFile);
                self::load(
                    preg_split('#\r\n|\n|\r#', $sql, -1, PREG_SPLIT_NO_EMPTY)
                );
            }

            self::$schemaLoaded = true;
        }
    }

    /**
     * @return void
     */
    public static function tearDownAfterClass(): void
    {
    }

    /**
     * Load a SQL file into the database
     *
     * @param array $sql
     *
     * @return void
     */
    private static function load(array $sql): void
    {
        $query           = '';
        $delimiter       = ';';
        $delimiterLength = 1;

        foreach ($sql as $singleSql) {
            $singleSql = trim($singleSql);

            // Skip empty lines and comments
            if ($singleSql === '' || $singleSql[0] === '-' || $singleSql[0] === '#') {
                continue;
            }

            // Handle delimiter change
            if (preg_match('#DELIMITER ([\;\$\|\\\]+)#i', $singleSql, $match)) {
                $delimiter       = $match[1];
                $delimiterLength = strlen($delimiter);
                continue;
            }

            $query .= "\n" . $singleSql;

            // Skip delimiter check when inside a PostgreSQL dollar-quoted block
            // ($TAG$...$TAG$ pairs must be balanced before we can split)
            if (
                preg_match_all('/\$[A-Za-z0-9_]*\$/', $query, $matches) &&
                count($matches[0]) % 2 !== 0
            ) {
                continue;
            }

            // Execute the query if it ends with the delimiter
            if (substr($query, -$delimiterLength) === $delimiter) {
                self::$connection->exec(substr($query, 0, -$delimiterLength));
                $query = '';
            }
        }

        // Execute any remaining query
        if ($query !== '') {
            self::$connection->exec($query);
        }
    }

    /**
     * Return records from the database
     *
     * @param string $table
     * @param array  $criteria
     *
     * @return array
     */
    protected function getFromDatabase(string $table, array $criteria = []): array
    {
        $sql   = 'SELECT * FROM ' . $table . ' WHERE ';
        $where = [];
        foreach ($criteria as $key => $value) {
            $val = $value;
            if (is_string($value)) {
                $val = "'" . $value . "'";
            }

            $where[] = $key . ' = ' . $val;
        }
        $sql .= implode(' AND ', $where);

        $connection = self::$connection;
        $result     = $connection->query($sql);
        $records    = $result->fetchAll(PDO::FETCH_ASSOC);

        return $records;
    }

    /**
     * @param object $object
     * @param string $methodName
     * @param array  $parameters
     *
     * @return mixed
     * @throws ReflectionException
     */
    protected function invokeMethod(
        object $object,
        string $methodName,
        array $parameters = []
    ): mixed {
        $reflection = new ReflectionClass(get_class($object));
        $method     = $reflection->getMethod($methodName);
        $method->setAccessible(true);

        return $method->invokeArgs($object, $parameters);
    }
}
