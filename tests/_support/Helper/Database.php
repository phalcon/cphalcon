<?php

namespace Helper;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

use Codeception\Exception\ModuleException;
use Codeception\TestInterface;
use PDO;
use Phalcon\DataMapper\Pdo\Connection;

use function date;
use function env;
use function getenv;
use function getOptionsMysql;
use function getOptionsPostgresql;
use function getOptionsSqlite;
use function sprintf;

/**
 * Class Database
 *
 * @property string $driver
 * @property string $password
 * @property string $username
 */
class Database extends \Codeception\Module
{
    /**
     * @var string
     */
    private $driver = 'sqlite';

    /**
     * @var string
     */
    private $password   = '';

    /**
     * @var string
     */
    private $username   = '';

    /**
     * @param TestInterface $test
     */
    public function _before(TestInterface $test)
    {
        $driver = $test->getMetadata()->getCurrent('env');
        if (!empty($driver)) {
            $this->driver = $driver;
        }

        parent::_before($test);
    }

    /**
     * @return string
     */
    public function getDriver(): string
    {
        return $this->driver;
    }

    /**
     * @return PDO
     * @throws ModuleException
     */
    public function getConnection(): PDO
    {
        return $this->getModule('Db')->_getDbh();
    }

    /**
     * @return array
     */
    public function getDatabaseOptions(): array
    {
        switch ($this->driver) {
            case 'pgsql':
            case 'postgres':
                return getOptionsPostgresql();
            case 'sqlsrv':
                return getOptionsSqlite();
            case 'mysql':
                return getOptionsMysql();
            default:
                return [];
        }
    }

    /**
     * @return string
     */
    public function getDatabaseDsn(): string
    {
        switch ($this->driver) {
            case 'mysql':
                $this->password = env('DATA_MYSQL_PASS', '');
                $this->username = env('DATA_MYSQL_USER', 'root');

                return sprintf(
                    "mysql:host=%s;dbname=%s;charset=utf8mb4;port=%s",
                    env('DATA_MYSQL_HOST', '127.0.0.1'),
                    env('DATA_MYSQL_NAME', 'phalcon'),
                    env('DATA_MYSQL_PORT', 3306)
                );
            case 'pgsql':
            case 'postgres':
                $this->password = env('DATA_POSTGRES_PASS', '');
                $this->username = env('DATA_POSTGRES_USER', 'postgres');

                return sprintf(
                    "pgsql:host=%s;dbname=%s;user=%s;password=%s",
                    env('DATA_POSTGRES_HOST', '127.0.0.1'),
                    getenv('DATA_POSTGRES_NAME', 'phalcon'),
                    $this->username,
                    $this->password
                );
            case 'sqlite':
                return sprintf(
                    'sqlite:%s',
                    env('DATA_SQLITE_NAME', 'memory')
                );

            case 'sqlsrv':
                return "";
                break;
            default:
                return "sqlite:memory";
        }
    }

    /**
     * @param string $driver
     *
     * @return string
     */
    public function getDatabaseNow(string $driver): string
    {
        switch ($driver) {
            case "sqlite":
                return date("'Y-m-d H:i:s'");
            default:
                return "NOW()";
        }
    }

    /**
     * @return string
     */
    public function getDatabasePassword(): string
    {
        return $this->password;
    }

    /**
     * @return string
     */
    public function getDatabaseUsername(): string
    {
        return $this->username;
    }

    /**
     * @return Connection
     */
    public function getDataMapperConnection(): Connection
    {
        return new Connection(
            $this->getDatabaseDsn(),
            $this->getDatabaseUsername(),
            $this->getDatabasePassword()
        );
    }
}
