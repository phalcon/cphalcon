<?php

declare(strict_types=1);

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use PDO;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class EventsTest extends AbstractUnitTestCase
{
    public static function eventsProvider(): array
    {
        return [
            ['SELECT 1', 'query', ['beforeQuery', 'afterQuery']],
            ['CREATE TABLE test (id INT)', 'execute', ['beforeQuery', 'afterQuery']],
            ['', 'commit', ['beginTransaction', 'commitTransaction', 'transactionCommitted']],
            ['', 'rollback', ['beginTransaction', 'rollbackTransaction', 'transactionRolledBack']],
        ];
    }

    public function testBadCommit(): void
    {
        $mockPDO = $this->getMockBuilder(PDO::class)
            ->disableOriginalConstructor()
            ->onlyMethods(['commit'])
            ->getMock();

        $mockPDO->expects($this->once())->method('commit')->willReturn(false);

        $connection = new Sqlite([
            'dbname' => ':memory:',
        ]);
        $ref = new \ReflectionObject($connection);

        $property = $ref->getProperty('pdo');
        $property->setValue($connection, $mockPDO);

        $property = $ref->getProperty('transactionLevel');
        $property->setValue($connection, 1);

        $manager = new Manager();
        $connection->setEventsManager($manager);

        $listener = new class {
            public array $events = [];

            public function commitTransaction($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }
            public function transactionCommitted($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }
        };

        $manager->attach('db', $listener);

        $connection->commit();
        $this->assertContains('commitTransaction', $listener->events);
        $this->assertNotContains('transactionCommitted', $listener->events);
    }

    #[DataProvider('eventsProvider')]
    public function testEvents($sql, $event, array $expectedEvents = []): void
    {
        $connection = new Sqlite([
            'dbname' => ':memory:',
        ]);

        $manager = new Manager();
        $connection->setEventsManager($manager);

        $listener = new class {
            public array $events = [];

            public function beforeQuery($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }

            public function afterQuery($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }

            public function commitTransaction($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }

            public function beginTransaction($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }

            public function transactionCommitted($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }

            public function rollbackTransaction($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }

            public function transactionRolledBack($event, $adapter, mixed $data = null)
            {
                $this->events[] = __FUNCTION__;
            }
        };

        $manager->attach('db', $listener);

        // Execute the SQL and check events based on the example data
        switch ($event) {
            case 'query':
                $connection->query($sql);
                break;

            case 'execute':
                $connection->execute($sql);
                break;

            case 'commit':
                $connection->begin();
                $connection->execute(
                    'CREATE TABLE test (id INT)'
                );
                $connection->commit();
                break;

            case 'rollback':
                $connection->begin();
                $connection->execute(
                    'CREATE TABLE test (id INT)'
                ); // Needs a query inside transaction for rollback to trigger
                $connection->rollback();
                break;
        }

        foreach ($expectedEvents as $expectedEvent) {
            $this->assertContains($expectedEvent, $listener->events);
        }
    }
}
