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

class FilterTrimCest extends FilterBase
{
    /**
     * Tests Trim left
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeTrimLeft(UnitTester $I)
    {
        $expected = 'Hello';
        $value    = '  Hello';
        $this->sanitizer($I, 'trim', $expected, $value);
    }

    /**
     * Tests Trim right
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeTrimRight(UnitTester $I)
    {
        $expected = 'Hello';
        $value    = 'Hello    ';
        $this->sanitizer($I, 'trim', $expected, $value);
    }

    /**
     * Tests Trim both
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeTrimBoth(UnitTester $I)
    {
        $expected = 'Hello';
        $value    = '  Hello    ';
        $this->sanitizer($I, 'trim', $expected, $value);
    }
}
