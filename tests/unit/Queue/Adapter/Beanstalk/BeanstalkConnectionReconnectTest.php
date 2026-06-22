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
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionMethod;

use function array_slice;
use function array_values;
use function count;
use function strlen;

/**
 * Verifies that a reconnect replays the tube selection the caller established.
 * The socket is mocked, so no Beanstalkd server is needed: writes are captured
 * and status reads return a canned response.
 */
final class BeanstalkConnectionReconnectTest extends AbstractUnitTestCase
{
    public function testRestoreSessionDoesNothingForAFreshConnection(): void
    {
        $commands   = [];
        $connection = $this->spyConnection($commands, ['USING']);

        $this->restoreSession($connection);

        $this->assertSame([], $commands);
    }

    public function testRestoreSessionReplaysTheUsedTube(): void
    {
        $commands   = [];
        $connection = $this->spyConnection($commands, ['USING']);

        $connection->useTube('jobs');
        $replayStart = count($commands);

        $this->restoreSession($connection);

        $this->assertSame(
            ['use jobs'],
            array_values(array_slice($commands, $replayStart))
        );
    }

    public function testRestoreSessionReplaysTheWatchedTubes(): void
    {
        $commands   = [];
        $connection = $this->spyConnection($commands, ['WATCHING']);

        $connection->watchTube('emails');
        $connection->ignoreTube('default');
        $replayStart = count($commands);

        $this->restoreSession($connection);

        $this->assertSame(
            ['watch emails', 'ignore default'],
            array_values(array_slice($commands, $replayStart))
        );
    }

    /**
     * Builds a BeanstalkConnection whose socket writes are captured into
     * $commands and whose status reads return $status, so the protocol layer
     * runs without a server.
     *
     * @param string[] $commands captured command buffer (by reference)
     * @param string[] $status   canned readStatus() response
     */
    private function spyConnection(array &$commands, array $status): BeanstalkConnection
    {
        $connection = $this->getMockBuilder(BeanstalkConnection::class)
            ->setConstructorArgs(['127.0.0.1', 11300])
            ->onlyMethods(['write', 'readStatus'])
            ->getMock()
        ;

        $capture = function (string $data) use (&$commands): int {
            $commands[] = $data;

            return strlen($data);
        };

        $connection->method('write')->willReturnCallback($capture);
        $connection->method('readStatus')->willReturn($status);

        return $connection;
    }

    private function restoreSession(BeanstalkConnection $connection): void
    {
        $method = new ReflectionMethod(BeanstalkConnection::class, 'restoreSession');
        $method->setAccessible(true);
        $method->invoke($connection);
    }
}
