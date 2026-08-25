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
use Phalcon\Queue\Exceptions\Exception;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use ReflectionMethod;

use function str_repeat;

final class BeanstalkConnectionTubeGuardTest extends AbstractUnitTestCase
{
    /**
     * A legal tube name must not be rejected: 200 bytes is the protocol
     * maximum and the full punctuation set is allowed, with a hyphen in any
     * position other than the first. The guard is checked on its own, so no
     * socket is opened.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testTubeCommandsAcceptLegalNames(): void
    {
        $connection = new BeanstalkConnection();
        $guard      = new ReflectionMethod(
            BeanstalkConnection::class,
            'assertValidTube'
        );

        $names = [
            'default',
            str_repeat('a', 200),
            'tube+/;.$_()-name',
        ];

        $accepted = [];
        foreach ($names as $name) {
            $guard->invoke($connection, $name);
            $accepted[] = $name;
        }

        $this->assertSame($names, $accepted);
    }

    /**
     * A tube name carrying CR/LF would inject arbitrary Beanstalkd commands.
     * Every tube-bearing command must reject it before any socket write.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-24
     */
    public function testTubeCommandsRejectCrlfInjection(): void
    {
        $connection = new BeanstalkConnection();
        $payload    = "default\r\nput 0 0 0 5\r\nhello";

        $operations = [
            fn() => $connection->useTube($payload),
            fn() => $connection->watchTube($payload),
            fn() => $connection->ignoreTube($payload),
            fn() => $connection->statsTube($payload),
        ];

        foreach ($operations as $operation) {
            try {
                $operation();
                $this->fail('Expected Exception for a CR/LF tube name');
            } catch (Exception $exception) {
                $this->assertSame('Invalid tube name', $exception->getMessage());
            }
        }
    }

    /**
     * A leading hyphen and a name longer than the 200 byte protocol maximum
     * are rejected before any socket write.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testTubeCommandsRejectLeadingHyphenAndOverlongName(): void
    {
        $connection = new BeanstalkConnection();

        $payloads = [
            '-tube',
            str_repeat('a', 201),
        ];

        foreach ($payloads as $payload) {
            try {
                $connection->useTube($payload);
                $this->fail('Expected Exception for an illegal tube name');
            } catch (Exception $exception) {
                $this->assertSame('Invalid tube name', $exception->getMessage());
            }
        }
    }
}
