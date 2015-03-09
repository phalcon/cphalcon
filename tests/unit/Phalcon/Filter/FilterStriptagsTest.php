<?php
/**
 * FilterStriptagsTest.php
 * \Phalcon\Text\FilterStriptagsTest
 *
 * Tests the Phalcon\Filter component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Filter;

class FilterStriptagsTest extends Helper\FilterBase
{
    /**
     * Tests striptags filter with html
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStriptagsHTML()
    {
        $this->specify(
            "striptags html filter is not correct",
            function () {
                $expected = 'Hello';
                $value    = '<h1>Hello</h1>';
                $this->sanitizer('striptags', $expected, $value);
            }
        );
    }

    /**
     * Tests striptags filter with broken html
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStriptagsBrokenHTML()
    {
        $this->specify(
            "striptags html filter is not correct",
            function () {
                $expected = 'Hello';
                $value    = '<h1><p>Hello</h1>';
                $this->sanitizer('striptags', $expected, $value);
            }
        );
    }

    /**
     * Tests striptags filter with single html tag
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeStriptagsSingle()
    {
        $this->specify(
            "striptags html filter is not correct",
            function () {
                $expected = '';
                $value    = '<';
                $this->sanitizer('striptags', $expected, $value);
            }
        );
    }
}
