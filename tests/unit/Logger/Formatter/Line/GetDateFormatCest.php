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

use Phalcon\Logger\Formatter\Line;
use UnitTester;

class GetDateFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: getDateFormat()
     */
    public function loggerFormatterLineGetDateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - getDateFormat()');
        $formatter = new Line();

        $expected = 'D, d M y H:i:s O';
        $actual   = $formatter->getDateFormat();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\Formatter\Line :: getDateFormat() - custom
     */
    public function loggerFormatterLineGetDateFormatCustom(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - getDateFormat() - custom');
        $formatter = new Line('', 'Ymd-His');

        $expected = 'Ymd-His';
        $actual   = $formatter->getDateFormat();
        $I->assertEquals($expected, $actual);
    }
}
