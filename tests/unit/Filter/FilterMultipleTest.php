<?php

namespace Phalcon\Test\Unit\Filter;

/**
 * \Phalcon\Test\Unit\Filter\FilterMultipleTest
 * Tests the \Phalcon\Filter component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Filter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FilterMultipleTest extends Helper\FilterBase
{
    /**
     * Tests sanitizing string with filters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStringWithMultipleFilters()
    {
        $this->specify(
            "string with multiple filters does not return the correct result",
            function () {
                $expected = 'lol';
                $value    = '    lol<<<   ';
                $this->sanitizer(['string', 'trim'], $expected, $value);
            }
        );
    }

    /**
     * Tests sanitizing array with filters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeArray()
    {
        $this->specify(
            "array does not return the correct result",
            function () {
                $expected = ['1', '2', '3'];
                $value    = [' 1 ', '  2', '3  '];
                $this->sanitizer('trim', $expected, $value);
            }
        );
    }

    /**
     * Tests sanitizing array with multiple filters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeArrayWithMultipleFilters()
    {
        $this->specify(
            "array with multiple filters does not return the correct result",
            function () {
                $expected = ['1', '2', '3'];
                $value    = [' <a href="a">1</a> ', '  <h1>2</h1>', '<p>3</p>'];
                $this->sanitizer(['trim', 'striptags'], $expected, $value);
            }
        );
    }
}
