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

class FilterStriptagsCest extends FilterBase
{
    /**
     * Tests striptags filter with html
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStriptagsHTML(UnitTester $I)
    {
        $expected = 'Hello';
        $value    = '<h1>Hello</h1>';
        $this->sanitizer($I, 'striptags', $expected, $value);
    }

    /**
     * Tests striptags filter with broken html
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStriptagsBrokenHTML(UnitTester $I)
    {
        $expected = 'Hello';
        $value    = '<h1><p>Hello</h1>';
        $this->sanitizer($I, 'striptags', $expected, $value);
    }

    /**
     * Tests striptags filter with single html tag
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStriptagsSingle(UnitTester $I)
    {
        $expected = '';
        $value    = '<';
        $this->sanitizer($I, 'striptags', $expected, $value);
    }
}
