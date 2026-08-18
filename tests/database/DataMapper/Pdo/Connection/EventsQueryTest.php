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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\DataMapper\Pdo\Events;
use Phalcon\DataMapper\Pdo\Exception\OperationCancelled;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class EventsQueryTest extends AbstractDatabaseTestCase
{
    public function testDMPdoConnectionExecCancelled(): void
    {
        $manager = new Manager();
        $manager->attach(
            Events::BEFORE_EXEC,
            function ($event) {
                $event->stop();

                return false;
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $this->expectException(OperationCancelled::class);
        $this->expectExceptionMessage(
            "Operation cancelled by a listener of 'dm:beforeExec'"
        );

        $connection->exec('delete from co_invoices');
    }

    public function testDMPdoConnectionExecFiresEvents(): void
    {
        $migration = new InvoicesMigration(self::getPdoConnection());
        $migration->clear();
        $migration->insert(1);
        $migration->insert(2);

        $fired   = [];
        $manager = new Manager();

        $manager->attach(
            Events::BEFORE_EXEC,
            function ($event, $source, $data) use (&$fired) {
                $fired['before'] = $data;
            }
        );
        $manager->attach(
            Events::AFTER_EXEC,
            function ($event, $source, $data) use (&$fired) {
                $fired['after'] = $data;
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $connection->exec(
            'update co_invoices set inv_total = inv_total + 100'
        );

        $this->assertSame(
            'update co_invoices set inv_total = inv_total + 100',
            $fired['before']['statement']
        );

        // assertEquals, not assertSame - drivers differ on the returned type,
        // which is why the existing ExecTest also uses assertEquals
        $this->assertEquals(2, $fired['after']['affectedRows']);
    }

    public function testDMPdoConnectionQueryCancelled(): void
    {
        $manager = new Manager();
        $manager->attach(
            Events::BEFORE_QUERY,
            function ($event) {
                $event->stop();

                return false;
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $this->expectException(OperationCancelled::class);
        $this->expectExceptionMessage(
            "Operation cancelled by a listener of 'dm:beforeQuery'"
        );

        $connection->query('select * from co_invoices');
    }

    public function testDMPdoConnectionQueryFiresEvents(): void
    {
        $migration = new InvoicesMigration(self::getPdoConnection());
        $migration->clear();
        $migration->insert(1);

        $fired   = [];
        $manager = new Manager();

        $manager->attach(
            Events::BEFORE_QUERY,
            function ($event, $source, $data) use (&$fired) {
                $fired['before'] = $data;
            }
        );
        $manager->attach(
            Events::AFTER_QUERY,
            function ($event, $source, $data) use (&$fired) {
                $fired['after'] = $data;
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $connection->query('select * from co_invoices');

        $this->assertSame(
            'select * from co_invoices',
            $fired['before']['statement']
        );
        $this->assertSame(
            ['select * from co_invoices'],
            $fired['before']['arguments']
        );
        $this->assertSame(
            'select * from co_invoices',
            $fired['after']['statement']
        );
    }

    public function testDMPdoConnectionPrepareFiresNoOperationEvents(): void
    {
        $fired   = [];
        $manager = new Manager();

        foreach (
            [
                Events::BEFORE_QUERY,
                Events::AFTER_QUERY,
                Events::BEFORE_PERFORM,
                Events::AFTER_PERFORM,
                Events::BEFORE_EXEC,
                Events::AFTER_EXEC,
            ] as $name
        ) {
            $manager->attach(
                $name,
                function () use (&$fired, $name) {
                    $fired[] = $name;
                }
            );
        }

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $connection->prepare('select * from co_invoices');

        $this->assertSame([], $fired);
    }

    public function testDMPdoConnectionPerformCancelled(): void
    {
        $manager = new Manager();
        $manager->attach(
            Events::BEFORE_PERFORM,
            function ($event) {
                $event->stop();

                return false;
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $this->expectException(OperationCancelled::class);
        $this->expectExceptionMessage(
            "Operation cancelled by a listener of 'dm:beforePerform'"
        );

        $connection->perform('select * from co_invoices');
    }

    public function testDMPdoConnectionPerformFiresEvents(): void
    {
        $migration = new InvoicesMigration(self::getPdoConnection());
        $migration->clear();
        $migration->insert(1);

        $fired   = [];
        $manager = new Manager();

        $manager->attach(
            Events::BEFORE_PERFORM,
            function ($event, $source, $data) use (&$fired) {
                $fired['before'] = $data;
            }
        );
        $manager->attach(
            Events::AFTER_PERFORM,
            function ($event, $source, $data) use (&$fired) {
                $fired['after'] = $data;
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        // positional placeholders are 0-based here - performBind() adds 1
        $connection->perform(
            'select * from co_invoices where inv_id = ?',
            [0 => 1]
        );

        $this->assertArrayHasKey('before', $fired);
        $this->assertArrayHasKey('after', $fired);
        $this->assertSame(
            'select * from co_invoices where inv_id = ?',
            $fired['before']['statement']
        );
        $this->assertSame([0 => 1], $fired['before']['values']);
        $this->assertSame(
            'select * from co_invoices where inv_id = ?',
            $fired['after']['statement']
        );
    }
}
