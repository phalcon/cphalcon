<?php

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

class FilterFloatCest extends FilterBase
{
    /**
     * Tests sanitizing a float with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatFloat(UnitTester $I)
    {
        $this->sanitizer($I, 'float', 1000.01, '1000.01');
    }

    /**
     * Tests sanitizing a hex with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatHex(UnitTester $I)
    {
        $this->sanitizer($I, 'float', 0xFFA, 0xFFA);
    }

    /**
     * Tests sanitizing a string number with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatStringNumber(UnitTester $I)
    {
        $this->sanitizer($I, 'float', '1000.01', '1000.01');
    }

    /**
     * Tests sanitizing a string with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatString(UnitTester $I)
    {
        $this->sanitizer($I, 'float', '', 'lol');
    }

    /**
     * Tests sanitizing a string with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatStringCombined(UnitTester $I)
    {
        $this->sanitizer($I, 'float', '10001901.01', '!10001901.01a');
    }
}
