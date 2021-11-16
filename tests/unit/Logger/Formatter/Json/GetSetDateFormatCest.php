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

namespace Phalcon\Tests\Unit\Logger\Formatter\Json;

use Phalcon\Logger\Formatter\Json;
use UnitTester;

class GetSetDateFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Json :: setDateFormat()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerFormatterJsonGetSetDateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Json - getDateFormat()/setDateFormat()');

        $newFormat = 'YmdHis';

        /**
         * Default
         */
        $formatter = new Json();

        $expected = 'c';
        $actual   = $formatter->getDateFormat();
        $I->assertEquals($expected, $actual);

        /**
         * Set in constructor
         */
        $formatter = new Json($newFormat);

        $expected = $newFormat;
        $actual   = $formatter->getDateFormat();
        $I->assertEquals($expected, $actual);

        /**
         * Set in setDateFormat
         */
        $formatter = new Json();
        $formatter->setDateFormat($newFormat);

        $expected = $newFormat;
        $actual   = $formatter->getDateFormat();
        $I->assertEquals($expected, $actual);
    }
}
