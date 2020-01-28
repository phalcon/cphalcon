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

use Phalcon\Logger\Formatter\Line;
use UnitTester;

class SetDateFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: setDateFormat()
     */
    public function loggerFormatterLineSetDateFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - setDateFormat()');
        $formatter = new Line();

        $format = 'YmdHis';
        $formatter->setDateFormat($format);

        $expected = $format;
        $actual   = $formatter->getDateFormat();
        $I->assertEquals($expected, $actual);
    }
}
