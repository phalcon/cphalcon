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

namespace Phalcon\Tests\Benchmarks\Apps\Rest;

use PDO;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Model\MetaData\Stream;

/**
 * Shared setup of the REST reference app: SQLite database, container, rows.
 *
 * The methods are not static: the container binds the service closures to an object, and a
 * closure that is created in a static method cannot be bound.
 */
final class Fixture
{
    private const ROWS = 50;

    private const TYPES = ['droid', 'mechanical', 'virtual'];

    /**
     * A new default container with the database service and the model metadata service.
     */
    public function container(string $database, string $metadata): FactoryDefault
    {
        /**
         * A new request: php-fpm clears the default container at the end of each request.
         * Without this, the models use the container (and the connection) of the first request.
         */
        Di::reset();

        $container = new FactoryDefault();
        $container->setShared(
            'db',
            function () use ($database): Sqlite {
                return new Sqlite(['dbname' => $database]);
            }
        );
        $container->setShared(
            'modelsMetadata',
            function () use ($metadata): Stream {
                return new Stream(['metaDataDir' => $metadata]);
            }
        );

        return $container;
    }

    /**
     * The SQLite database file. It is created with 50 rows if it is missing.
     */
    public function database(): string
    {
        $database = $this->folder() . 'rest.sqlite';
        if (!file_exists($database)) {
            $this->createDatabase($database);
        }

        return $database;
    }

    /**
     * The folder for the model metadata files. It is created if it is missing.
     */
    public function metadata(): string
    {
        $metadata = $this->folder() . 'metadata/';
        if (!is_dir($metadata)) {
            mkdir($metadata, 0777, true);
        }

        return $metadata;
    }

    /**
     * The first <count> rows of the robots table.
     */
    public function rows(int $count): array
    {
        $rows = [];
        for ($index = 1; $index <= $count; $index++) {
            $rows[] = [
                'id'   => $index,
                'name' => 'Robot ' . $index,
                'type' => self::TYPES[$index % 3],
                'year' => 1950 + $index,
            ];
        }

        return $rows;
    }

    private function createDatabase(string $database): void
    {
        $temporary = $database . '.new';
        if (file_exists($temporary)) {
            unlink($temporary);
        }

        $connection = new PDO('sqlite:' . $temporary);
        $connection->exec((string) file_get_contents(__DIR__ . '/schema.sql'));

        $statement = $connection->prepare(
            'INSERT INTO robots (name, type, year) VALUES (:name, :type, :year)'
        );
        $connection->beginTransaction();
        foreach ($this->rows(self::ROWS) as $row) {
            $statement->execute(
                [
                    'name' => $row['name'],
                    'type' => $row['type'],
                    'year' => $row['year'],
                ]
            );
        }
        $connection->commit();

        unset($statement, $connection);
        rename($temporary, $database);
    }

    private function folder(): string
    {
        $folder = dirname(__DIR__, 4) . '/.local/bench/fixtures/rest/';
        if (!is_dir($folder)) {
            mkdir($folder, 0777, true);
        }

        return $folder;
    }
}
