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

namespace Phalcon\Tests\Unit\Logger\Formatter\Line;

use Phalcon\Logger\Formatter\Line;
use UnitTester;

class GetSetFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: getFormat()/setFormat()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerFormatterLineGetSetFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - getFormat()/setFormat()');

        $newFormat = '%message%-[%date%]-[%level%]';

        /**
         * Default
         */
        $formatter = new Line();

        $expected = '[%date%][%level%] %message%';
        $actual   = $formatter->getFormat();
        $I->assertEquals($expected, $actual);

        /**
         * Set with constructor
         */
        $formatter = new Line($newFormat);

        $expected = $newFormat;
        $actual   = $formatter->getFormat();
        $I->assertEquals($expected, $actual);

        /**
         * Set with setFormat()
         */
        $formatter = new Line($newFormat);
        $formatter->setFormat($newFormat);

        $expected = $newFormat;
        $actual   = $formatter->getFormat();
        $I->assertEquals($expected, $actual);
    }
}
