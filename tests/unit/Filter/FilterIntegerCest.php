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

namespace Phalcon\Test\Unit\Filter;

use Phalcon\Filter;
use Phalcon\Test\Unit\Filter\Helper\FilterBase;
use UnitTester;

class FilterIntegerCest extends FilterBase
{
    /**
     * Tests sanitizing an integer with abs integer filter with constant
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2015-04-21
     */
    public function testSanitizeAbsIntegerInteger(UnitTester $I)
    {
        $this->sanitizer($I, Filter::FILTER_ABSINT, 125, -125);
    }

    /**
     * Tests sanitizing a string  with abs integer filter with constant
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2015-04-21
     */
    public function testSanitizeAbsIntegerString(UnitTester $I)
    {
        $this->sanitizer($I, Filter::FILTER_ABSINT, 125, '-125');
    }

    /**
     * Tests sanitizing an integer with integer filter with constant
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2015-04-21
     */
    public function testSanitizeIntegerIntegerConstant(UnitTester $I)
    {
        $this->sanitizer($I, Filter::FILTER_INT, 1000, 1000);
    }

    /**
     * Tests sanitizing an integer with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerInteger(UnitTester $I)
    {
        $this->sanitizer($I, 'int', 1000, 1000);
    }

    /**
     * Tests sanitizing a hex with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerHex(UnitTester $I)
    {
        $this->sanitizer($I, 'int', 0xFFA, 0xFFA);
    }

    /**
     * Tests sanitizing a string number with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerStringNumber(UnitTester $I)
    {
        $this->sanitizer($I, 'int', '1000', '1000');
    }

    /**
     * Tests sanitizing a string with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerString(UnitTester $I)
    {
        $this->sanitizer($I, 'int', '', 'lol');
    }

    /**
     * Tests sanitizing a string with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerStringCombined(UnitTester $I)
    {
        $this->sanitizer($I, 'int', '10001901', '!100a019.01a');
    }
}
