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

use Phalcon\Contracts\Events\EventsAware;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\DataMapper\Pdo\Events;
use Phalcon\DataMapper\Pdo\Exception\Exception;
use Phalcon\DataMapper\Pdo\Exception\OperationCancelled;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetSetEventsManagerTest extends AbstractDatabaseTestCase
{
    public function testDMPdoConnectionGetSetEventsManager(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();

        $this->assertNull($connection->getEventsManager());

        $manager = new Manager();
        $connection->setEventsManager($manager);

        $this->assertSame($manager, $connection->getEventsManager());
    }

    public function testDMPdoConnectionIsEventsAware(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();

        $this->assertInstanceOf(EventsAware::class, $connection);
    }

    public function testDMPdoEventConstants(): void
    {
        $this->assertSame('dm:beforeConnect', Events::BEFORE_CONNECT);
        $this->assertSame('dm:afterConnect', Events::AFTER_CONNECT);
        $this->assertSame('dm:beforeDisconnect', Events::BEFORE_DISCONNECT);
        $this->assertSame('dm:afterDisconnect', Events::AFTER_DISCONNECT);
        $this->assertSame('dm:beforePerform', Events::BEFORE_PERFORM);
        $this->assertSame('dm:afterPerform', Events::AFTER_PERFORM);
        $this->assertSame('dm:beforeExec', Events::BEFORE_EXEC);
        $this->assertSame('dm:afterExec', Events::AFTER_EXEC);
        $this->assertSame(
            'dm:beforeBeginTransaction',
            Events::BEFORE_BEGIN_TRANSACTION
        );
        $this->assertSame(
            'dm:afterBeginTransaction',
            Events::AFTER_BEGIN_TRANSACTION
        );
        $this->assertSame('dm:beforeCommit', Events::BEFORE_COMMIT);
        $this->assertSame('dm:afterCommit', Events::AFTER_COMMIT);
        $this->assertSame('dm:beforeRollBack', Events::BEFORE_ROLLBACK);
        $this->assertSame('dm:afterRollBack', Events::AFTER_ROLLBACK);
        $this->assertSame('dm:connectionLost', Events::CONNECTION_LOST);
    }

    public function testDMPdoOperationCancelledMessage(): void
    {
        $exception = new OperationCancelled(Events::BEFORE_PERFORM);

        $this->assertInstanceOf(Exception::class, $exception);
        $this->assertSame(
            "Operation cancelled by a listener of 'dm:beforePerform'",
            $exception->getMessage()
        );
    }
}
