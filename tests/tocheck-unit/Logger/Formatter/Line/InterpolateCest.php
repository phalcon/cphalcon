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

namespace Phalcon\Test\Unit\Logger\Formatter\Line;

use Phalcon\Logger;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Item;
use UnitTester;

class InterpolateCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: interpolate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterLineInterpolate(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - interpolate()');

        $formatter = new Line();

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
     * Tests Phalcon\Logger\Formatter\Line :: interpolate() - format
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerFormatterLineInterpolateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - interpolate() - format()');

        $formatter = new Line();

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

        $expected = sprintf(
            '[%s][debug] The sky is blue',
            date('c', $time)
        );

        $I->assertEquals(
            $expected,
            $formatter->format($item)
        );
    }

    /**
     * Tests Phalcon\Logger\Formatter\Line :: interpolate() - empty
     */
    public function loggerFormatterLineInterpolateEmpty(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - interpolate() - empty');
        $formatter = new Line();

        $message = 'The sky is {color}';
        $context = [];

        $expected = 'The sky is {color}';
        $actual   = $formatter->interpolate($message, $context);
        $I->assertEquals($expected, $actual);
    }
}
