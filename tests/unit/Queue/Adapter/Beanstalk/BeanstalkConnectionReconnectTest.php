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

namespace Phalcon\Tests\Unit\Queue\Adapter\Beanstalk;

use Phalcon\Queue\Adapter\Beanstalk\BeanstalkConnection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Fake\FakeBeanstalkConnection;
use ReflectionMethod;

use function array_slice;
use function array_values;
use function count;

/**
 * Verifies that a reconnect replays the tube selection the caller established.
 * The socket is faked, so no Beanstalkd server is needed: writes are captured
 * and status reads return a canned response.
 */
final class BeanstalkConnectionReconnectTest extends AbstractUnitTestCase
{
    public function testRestoreSessionDoesNothingForAFreshConnection(): void
    {
        $connection = $this->spyConnection(['USING']);

        $this->restoreSession($connection);

        $this->assertSame([], $connection->commands);
    }

    public function testRestoreSessionReplaysTheUsedTube(): void
    {
        $connection = $this->spyConnection(['USING']);

        $connection->useTube('jobs');
        $replayStart = count($connection->commands);

        $this->restoreSession($connection);

        $this->assertSame(
            ['use jobs'],
            array_values(array_slice($connection->commands, $replayStart))
        );
    }

    public function testRestoreSessionReplaysTheWatchedTubes(): void
    {
        $connection = $this->spyConnection(['WATCHING']);

        $connection->watchTube('emails');
        $connection->ignoreTube('default');
        $replayStart = count($connection->commands);

        $this->restoreSession($connection);

        $this->assertSame(
            ['watch emails', 'ignore default'],
            array_values(array_slice($connection->commands, $replayStart))
        );
    }

    private function restoreSession(BeanstalkConnection $connection): void
    {
        $method = new ReflectionMethod(BeanstalkConnection::class, 'restoreSession');
        $method->invoke($connection);
    }

    /**
     * Builds a connection that captures its socket writes and returns $status
     * from every status read, so the protocol layer runs without a server.
     *
     * @param string[] $status canned readStatus() response
     */
    private function spyConnection(array $status): FakeBeanstalkConnection
    {
        $connection         = new FakeBeanstalkConnection('127.0.0.1', 11300);
        $connection->status = $status;

        return $connection;
    }
}
