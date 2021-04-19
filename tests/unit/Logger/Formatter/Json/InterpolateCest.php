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

namespace Phalcon\Test\Unit\Logger\Formatter\Json;

use Phalcon\Logger;
use Phalcon\Logger\Formatter\Json;
use Phalcon\Logger\Item;
use UnitTester;

class InterpolateCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Json :: interpolate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonInterpolate(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - interpolate()');

        $formatter = new Json();

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
     * Tests Phalcon\Logger\Formatter\Json :: interpolate() - format
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonInterpolateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - interpolate() - format()');

        $formatter = new Json();
        $message   = 'The sky is {color}';
        $context   = [
            'color' => 'blue',
        ];
        $time      = time();
        $item      = new Item(
            $message,
            'debug',
            Logger::DEBUG,
            $time,
            $context
        );

        $expected = sprintf(
            '{"type":"debug","message":"The sky is blue","timestamp":"%s"}',
            date('c', $time)
        );

        $actual = $formatter->format($item);

        $I->assertEquals($expected, $actual);
    }
}
