<?php
/**
 * FilterIntegerTest.php
 * \Phalcon\Text\FilterIntegerTest
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

class FilterIntegerTest extends Helper\FilterBase
{
    /**
     * Tests sanitizing an integer with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerInteger()
    {
        $this->specify(
            "sanitizing integer with int filter not correct",
            function () {
                $this->sanitizer('int', 1000, 1000);
            }
        );
    }

    /**
     * Tests sanitizing a hex with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerHex()
    {
        $this->specify(
            "sanitizing hex with int filter not correct",
            function () {
                $this->sanitizer('int', '0xFFA', 0xFFA);
            }
        );
    }

    /**
     * Tests sanitizing a string number with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerStringNumber()
    {
        $this->specify(
            "sanitizing string number with int filter not correct",
            function () {
                $this->sanitizer('int', '1000', '1000');
            }
        );
    }

    /**
     * Tests sanitizing a string with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerString()
    {
        $this->specify(
            "sanitizing string with int filter not correct",
            function () {
                $this->sanitizer('int', '', 'lol');
            }
        );
    }

    /**
     * Tests sanitizing a string with integer filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeIntegerStringCombined()
    {
        $this->specify(
            "sanitizing string combined with int filter not correct",
            function () {
                $this->sanitizer('int', '10001901', '!100a019.01a');
            }
        );
    }
}
