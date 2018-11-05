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

class FilterUpperLowerCest extends FilterBase
{
    /**
     * Tests lower all
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeLowerAll(UnitTester $I)
    {
        $expected = 'hello';
        $value    = 'HELLO';
        $this->sanitizer($I, 'lower', $expected, $value);
    }

    /**
     * Tests lower mixed
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeLowerMixed(UnitTester $I)
    {
        $expected = 'hello';
        $value    = 'HeLlo';
        $this->sanitizer($I, 'lower', $expected, $value);
    }

    /**
     * Tests upper all
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeUpperAll(UnitTester $I)
    {
        $expected = 'HELLO';
        $value    = 'hello';
        $this->sanitizer($I, 'upper', $expected, $value);
    }

    /**
     * Tests upper mixed
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeUpperMixed(UnitTester $I)
    {
        $expected = 'HELLO';
        $value    = 'HeLlo';
        $this->sanitizer($I, 'upper', $expected, $value);
    }
}
