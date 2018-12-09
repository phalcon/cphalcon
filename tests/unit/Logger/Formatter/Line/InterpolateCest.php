<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Formatter\Line;

use Phalcon\Logger;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Item;
use UnitTester;

/**
 * Class InterpolateCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class InterpolateCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: interpolate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterLineInterpolate(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - interpolate()');
        $formatter = new Line();

        $message = 'The sky is {color}';
        $context = [
            'color' => 'blue',
        ];

        $expected = 'The sky is blue';
        $actual   = $formatter->interpolate($message, $context);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\Formatter\Line :: interpolate() - format
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
        $item = new Item($message, 'debug', Logger::DEBUG, $time, $context);

        $expected = sprintf('[%s][debug] The sky is blue', date('D, d M y H:i:s O', $time)) . PHP_EOL;
        $actual   = $formatter->format($item);
        $I->assertEquals($expected, $actual);
    }
}
