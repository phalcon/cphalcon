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

use Codeception\Example;
use Phalcon\Logger\Adapter\Syslog;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: __construct()
     *
     * @dataProvider getExamples
     *
     * @since        2019-10-14
     */
    public function loggerAdapterSyslogConstructOptionsCast(UnitTester $I, Example $example)
    {
        $I->wantToTest('Logger\Adapter\Syslog - __construct() - options');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter  = new Syslog($streamName, $example['options']);
        $property = $I->getProtectedProperty($adapter, $example['property']);

        $I->assertEquals(
            $example['expected'],
            $property
        );
    }

    private function getExamples(): array
    {
        return [
            [
                'options'  => [],
                'property' => 'option',
                'expected' => LOG_ODELAY,
            ],
            [
                'options'  => ['option' => LOG_ALERT | LOG_INFO],
                'property' => 'option',
                'expected' => LOG_ALERT | LOG_INFO,
            ],
            [
                'options'  => [],
                'property' => 'facility',
                'expected' => LOG_USER,
            ],
            [
                'options'  => ['facility' => LOG_DAEMON],
                'property' => 'facility',
                'expected' => LOG_DAEMON,
            ],
        ];
    }
}
