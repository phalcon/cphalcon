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

namespace Phalcon\Test\Unit\Logger\Formatter\Json;

use Phalcon\Logger;
use Phalcon\Logger\Formatter\Json;
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
     * Tests Phalcon\Logger\Formatter\Json :: interpolate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonInterpolate(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - interpolate()');
        $formatter = new Json();

        $message = 'The sky is {color}';
        $context = [
            'color' => 'blue',
        ];

        $expected = 'The sky is blue';
        $actual   = $formatter->interpolate($message, $context);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\Formatter\Json :: interpolate() - format
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterJsonInterpolateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - interpolate() - format()');
        $formatter = new Json();

        $message = 'The sky is {color}';
        $context = [
            'color' => 'blue',
        ];

        $time = time();
        $item = new Item($message, 'debug', Logger::DEBUG, $time, $context);

        $expected = sprintf(
            '{"type":"debug","message":"The sky is blue","timestamp":"%s"}%s',
            date('D, d M y H:i:s O', $time),
            PHP_EOL
        );
        $actual   = $formatter->format($item);
        $I->assertEquals($expected, $actual);
    }
}
