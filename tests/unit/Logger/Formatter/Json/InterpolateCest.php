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

use Phalcon\Logger\Formatter\Json;
use Phalcon\Logger\Item;
use Phalcon\Logger\Logger;
use UnitTester;

class InterpolateCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Json :: interpolate()
     *
     * @author Phalcon Team <team@phalconphp.com>
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

        $item = new Item(
            $message,
            'debug',
            Logger::DEBUG,
            $time,
            $context
        );

        $expected = sprintf(
            '{"type":"debug","message":"The sky is blue","timestamp":"%s"}%s',
            date('D, d M y H:i:s O', $time),
            PHP_EOL
        );

        $I->assertEquals(
            $expected,
            $formatter->format($item)
        );
    }
}
