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
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class EventsTransactionTest extends AbstractDatabaseTestCase
{
    public function testDMPdoConnectionBeginTransactionCancelled(): void
    {
        $manager = new Manager();
        $manager->attach(
            Events::BEFORE_BEGIN_TRANSACTION,
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
            "Operation cancelled by a listener of 'dm:beforeBeginTransaction'"
        );

        $connection->beginTransaction();
    }

    public function testDMPdoConnectionCommitCancelledLeavesTransactionOpen(): void
    {
        $manager = new Manager();
        $manager->attach(
            Events::BEFORE_COMMIT,
            function ($event) {
                $event->stop();

                return false;
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $connection->beginTransaction();

        try {
            $connection->commit();
            $this->fail('OperationCancelled was not thrown');
        } catch (OperationCancelled $exception) {
            $this->assertTrue($connection->inTransaction());
        }

        $connection->rollBack();
    }

    public function testDMPdoConnectionRollBackFiresEvents(): void
    {
        $fired   = [];
        $manager = new Manager();

        $manager->attach(
            Events::BEFORE_ROLLBACK,
            function () use (&$fired) {
                $fired[] = 'before';
            }
        );
        $manager->attach(
            Events::AFTER_ROLLBACK,
            function () use (&$fired) {
                $fired[] = 'after';
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $connection->beginTransaction();
        $connection->rollBack();

        $this->assertSame(['before', 'after'], $fired);
    }

    public function testDMPdoConnectionTransactionFiresEvents(): void
    {
        $fired   = [];
        $manager = new Manager();

        $names = [
            Events::BEFORE_BEGIN_TRANSACTION,
            Events::AFTER_BEGIN_TRANSACTION,
            Events::BEFORE_COMMIT,
            Events::AFTER_COMMIT,
        ];

        foreach ($names as $name) {
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

        $connection->beginTransaction();
        $connection->commit();

        $this->assertSame($names, $fired);
    }
}
