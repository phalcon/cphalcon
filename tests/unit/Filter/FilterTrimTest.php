<?php

namespace Phalcon\Test\Unit\Filter;

/**
 * \Phalcon\Test\Unit\Filter\FilterTrimTest
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
class FilterTrimTest extends Helper\FilterBase
{
    /**
     * Tests Trim left
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeTrimLeft()
    {
        $this->specify(
            "trim left is not correct",
            function () {
                $expected = 'Hello';
                $value    = '  Hello';
                $this->sanitizer('trim', $expected, $value);
            }
        );
    }

    /**
     * Tests Trim right
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeTrimRight()
    {
        $this->specify(
            "trim right is not correct",
            function () {
                $expected = 'Hello';
                $value    = 'Hello    ';
                $this->sanitizer('trim', $expected, $value);
            }
        );
    }

    /**
     * Tests Trim both
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeTrimBoth()
    {
        $this->specify(
            "trim both is not correct",
            function () {
                $expected = 'Hello';
                $value    = '  Hello    ';
                $this->sanitizer('trim', $expected, $value);
            }
        );
    }
}
