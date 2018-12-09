<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Filter\Helper;

use Phalcon\Filter;
use UnitTester;

class FilterBase
{
    /**
     * Tests integers
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     *
     * @param string $filter
     * @param mixed  $expected
     * @param mixed  $value
     */
    protected function sanitizer(UnitTester $I, $filter, $expected, $value)
    {
        $fl     = new Filter();
        $actual = $fl->sanitize($value, $filter);
        $I->assertEquals($expected, $actual);
    }
}
