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

final class BeanstalkConnectionTubeGuardTest extends AbstractUnitTestCase
{
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
}
