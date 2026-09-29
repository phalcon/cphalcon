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
use Phalcon\Http\ResponseInterface;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Model\MetaData\Stream;
use Phalcon\Tests\Benchmarks\Apps\Rest\Models\Robots;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

/**
 * Reference app: REST (Micro) with models on SQLite. Each call is one request.
 */
#[BeforeMethods('setUp')]
#[Revs(100)]
final class RestBench
{
    private const EXPECTED_CREATE = 'a92f2cfba39f3ef5da4fde808c217cf686d50bd7';

    private const EXPECTED_LIST   = '4a63cad4e32d423c8cc1e605a4d97d1475552dea';

    private const EXPECTED_SHOW   = 'fcbb54f542bcb030833edb6008d1c2d269f46538';

    private const ROWS            = 50;

    private const TYPES           = ['droid', 'mechanical', 'virtual'];

    private string $database = '';

    private string $metadata = '';

    public function setUp(): void
    {
        $fixtures       = dirname(__DIR__, 4) . '/.local/bench/fixtures/rest';
        $this->database = $fixtures . '/rest.sqlite';
        $this->metadata = $fixtures . '/metadata/';

        if (!is_dir($this->metadata)) {
            mkdir($this->metadata, 0777, true);
        }

        if (!file_exists($this->database)) {
            $this->createDatabase();
        }
    }

    public function benchCreate(): void
    {
        $this->request('POST', '/robots', self::EXPECTED_CREATE);
    }

    public function benchList(): void
    {
        $this->request('GET', '/robots', self::EXPECTED_LIST);
    }

    public function benchShow(): void
    {
        $this->request('GET', '/robots/7', self::EXPECTED_SHOW);
    }

    private function application(): Micro
    {
        /**
         * A new request: php-fpm clears the default container at the end of each request.
         * Without this, the models use the container (and the connection) of the first request.
         */
        Di::reset();

        $container = new FactoryDefault();
        $database  = $this->database;
        $metadata  = $this->metadata;

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

        /**
         * Micro binds the handlers to the application. Static closures cannot be bound.
         */
        $application = new Micro($container);
        $application->get(
            '/robots',
            function () use ($application): ResponseInterface {
                $robots = Robots::find(
                    [
                        'order' => 'id',
                        'limit' => 20,
                    ]
                );

                return $application->response->setJsonContent($robots->toArray());
            }
        );
        $application->get(
            '/robots/{id:[0-9]+}',
            function (string $id) use ($application): ResponseInterface {
                $robot = Robots::findFirst(
                    [
                        'conditions' => 'id = :id:',
                        'bind'       => ['id' => (int) $id],
                    ]
                );

                return $application->response->setJsonContent($robot->toArray());
            }
        );
        $application->post(
            '/robots',
            function () use ($application): ResponseInterface {
                /**
                 * The transaction rolls back, so the table does not change.
                 */
                $connection = $application->db;
                $connection->begin();

                $robot = new Robots();
                $robot->assign(
                    [
                        'name' => 'Robot new',
                        'type' => 'droid',
                        'year' => 2026,
                    ]
                );
                $saved = $robot->save();
                $data  = $robot->toArray();

                $connection->rollback();

                if (true !== $saved) {
                    throw new RuntimeException('Robots::save() failed');
                }

                return $application->response
                    ->setStatusCode(201)
                    ->setJsonContent($data);
            }
        );

        return $application;
    }

    private function createDatabase(): void
    {
        $temporary = $this->database . '.new';
        if (file_exists($temporary)) {
            unlink($temporary);
        }

        $connection = new PDO('sqlite:' . $temporary);
        $connection->exec((string) file_get_contents(__DIR__ . '/schema.sql'));

        $statement = $connection->prepare(
            'INSERT INTO robots (name, type, year) VALUES (:name, :type, :year)'
        );
        $connection->beginTransaction();
        for ($index = 1; $index <= self::ROWS; $index++) {
            $statement->execute(
                [
                    'name' => 'Robot ' . $index,
                    'type' => self::TYPES[$index % 3],
                    'year' => 1950 + $index,
                ]
            );
        }
        $connection->commit();

        unset($statement, $connection);
        rename($temporary, $this->database);
    }

    private function request(string $method, string $uri, string $expected): void
    {
        $_SERVER['REQUEST_METHOD'] = $method;
        $_SERVER['REQUEST_URI']    = $uri;

        ob_start();
        $this->application()->handle($uri);
        $body = ob_get_clean();

        $actual = sha1($body);
        if ($expected !== $actual) {
            throw new RuntimeException(
                sprintf('Unexpected body for %s %s (sha1 %s): %s', $method, $uri, $actual, $body)
            );
        }
    }
}
