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
final class EventsConnectTest extends AbstractDatabaseTestCase
{
    public function testDMPdoConnectionConnectCancelled(): void
    {
        $manager = new Manager();
        $manager->attach(
            Events::BEFORE_CONNECT,
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
            "Operation cancelled by a listener of 'dm:beforeConnect'"
        );

        $connection->connect();
    }

    public function testDMPdoConnectionConnectFiresEvents(): void
    {
        $fired   = [];
        $manager = new Manager();

        $manager->attach(
            Events::BEFORE_CONNECT,
            function () use (&$fired) {
                $fired[] = 'before';
            }
        );
        $manager->attach(
            Events::AFTER_CONNECT,
            function () use (&$fired) {
                $fired[] = 'after';
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $connection->connect();

        $this->assertSame(['before', 'after'], $fired);

        // connect() is idempotent - a second call must not fire again
        $connection->connect();

        $this->assertSame(['before', 'after'], $fired);
    }

    public function testDMPdoConnectionDisconnectCancelledStaysConnected(): void
    {
        $manager = new Manager();
        $manager->attach(
            Events::BEFORE_DISCONNECT,
            function ($event) {
                $event->stop();

                return false;
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->connect();
        $connection->setEventsManager($manager);

        try {
            $connection->disconnect();
            $this->fail('OperationCancelled was not thrown');
        } catch (OperationCancelled $exception) {
            $this->assertTrue($connection->isConnected());
        }
    }

    public function testDMPdoConnectionDisconnectFiresEvents(): void
    {
        $fired   = [];
        $manager = new Manager();

        $manager->attach(
            Events::BEFORE_DISCONNECT,
            function () use (&$fired) {
                $fired[] = 'before';
            }
        );
        $manager->attach(
            Events::AFTER_DISCONNECT,
            function () use (&$fired) {
                $fired[] = 'after';
            }
        );

        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $connection->setEventsManager($manager);

        $connection->connect();
        $connection->disconnect();

        $this->assertSame(['before', 'after'], $fired);
        $this->assertFalse($connection->isConnected());
    }
}
