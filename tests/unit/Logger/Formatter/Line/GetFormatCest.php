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
 * Class GetFormatCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class GetFormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Line :: getFormat()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterLineGetFormat(UnitTester $I)
    {
        $I->wantToTest('Logger\Formatter\Line - getFormat()');
        $formatter = new Line();

        $expected = '[%date%][%type%] %message%';
        $actual   = $formatter->getFormat();
        $I->assertEquals($expected, $actual);
    }
}
