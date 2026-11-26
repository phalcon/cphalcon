<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Queue;

use Phalcon\Queue\Adapter\Beanstalk\BeanstalkConnection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

use function strlen;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/850
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: mixed, 1: string}>
     */
    public static function getTimeouts(): array
    {
        return [
            'null'   => [null, 'reserve'],
            'string' => ['10', 'reserve-with-timeout 10'],
            'abc'    => ['abc', 'reserve-with-timeout 0'],
            'true'   => [true, 'reserve-with-timeout 1'],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/850
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getTimeouts')]
    public function testQueueAdapterBeanstalkConnectionReserve(mixed $timeout, string $expected): void
    {
        $connection = new class () extends BeanstalkConnection {
            public string $sent = '';

            public function readStatus(): array
            {
                return [];
            }

            public function write(string $data): false | int
            {
                $this->sent = $data;

                return strlen($data);
            }
        };

        $this->assertNull($connection->reserve($timeout));
        $this->assertSame($expected, $connection->sent);
    }
}
