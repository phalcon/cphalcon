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

class FilterAlphanumCest extends FilterBase
{
    /**
     * Tests Alphanum with an integer using constant
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2015-04-21
     */
    public function testSanitizeAlphanumIntegerConstant(UnitTester $I)
    {
        $expected = '0';
        $value    = 0;
        $this->sanitizer($I, Filter::FILTER_ALPHANUM, $expected, $value);
    }

    /**
     * Tests Alphanum with an integer
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeAlphanumInteger(UnitTester $I)
    {
        $expected = '0';
        $value    = 0;
        $this->sanitizer($I, 'alphanum', $expected, $value);
    }

    /**
     * Tests Alphanum with a null
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeAlphanumNull(UnitTester $I)
    {
        $expected = '';
        $value    = null;
        $this->sanitizer($I, 'alphanum', $expected, $value);
    }

    /**
     * Tests Alphanum with a mixed string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeAlphanumMixed(UnitTester $I)
    {
        $expected = 'a5xkat1sXan';
        $value    = '?a&5xka\tŧ?1-s.Xa[\n';
        $this->sanitizer($I, 'alphanum', $expected, $value);
    }
}
