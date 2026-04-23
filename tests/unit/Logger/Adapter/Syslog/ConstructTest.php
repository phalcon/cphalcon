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

namespace Phalcon\Tests\Unit\Logger\Adapter\Syslog;

use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Tests\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        return [
            [
                [],
                'option',
                LOG_ODELAY,
            ],
            [
                ['option' => LOG_ALERT | LOG_INFO],
                'option',
                LOG_ALERT | LOG_INFO,
            ],
            [
                [],
                'facility',
                LOG_USER,
            ],
            [
                ['facility' => LOG_DAEMON],
                'facility',
                LOG_DAEMON,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testLoggerAdapterSyslogConstructOptionsCast(
        array $options,
        string $property,
        int $expected
    ): void {
        $streamName = $this->getNewFileName('log', 'log');

        $adapter  = new Syslog($streamName, $options);
        $property = $this->getProtectedProperty($adapter, $property);

        $this->assertSame($expected, $property);
    }
}
