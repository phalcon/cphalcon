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

/**
 * Class SetFormatCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class SetFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: setFormat()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterLineSetFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - setFormat()');
        $formatter = new Line();

        $format = '%message%-[%date%]-[%type%]';
        $formatter->setFormat($format);

        $expected = $format;
        $actual   = $formatter->getFormat();
        $I->assertEquals($expected, $actual);
    }
}
