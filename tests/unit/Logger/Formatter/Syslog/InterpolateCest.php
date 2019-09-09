<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Formatter\Syslog;

use Phalcon\Logger\Formatter\Syslog;
use Phalcon\Logger\Item;
use Phalcon\Logger;
use UnitTester;

class InterpolateCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Syslog :: interpolate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterSyslogInterpolate(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Syslog - interpolate()');

        $formatter = new Syslog();

        $I->assertEquals(
            'The sky is blue',
            $formatter->interpolate(
                'The sky is {color}',
                [
                    'color' => 'blue',
                ]
            )
        );
    }

    /**
     * Tests Phalcon\Logger\Formatter\Syslog :: interpolate() - format
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterSyslogInterpolateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Syslog - interpolate() - format()');

        $formatter = new Syslog();

        $message = 'The sky is {color}';

        $context = [
            'color' => 'blue',
        ];

        $time = time();

        $item = new Item(
            $message,
            'debug',
            Logger::DEBUG,
            $time,
            $context
        );

        $I->assertEquals(
            [
                Logger::DEBUG,
                'The sky is blue',
            ],
            $formatter->format($item)
        );
    }
}
