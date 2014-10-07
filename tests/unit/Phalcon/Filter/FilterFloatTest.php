<?php
/**
 * FilterFloatTest.php
 * \Phalcon\Text\FilterFloatTest
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

class FilterFloatTest extends Helper\FilterBase
{
    /**
     * Tests sanitizing a float with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatFloat()
    {
        $this->specify(
            "sanitizing float with float filter not correct",
            function () {
                $this->sanitizer('float', 1000.01, '1000.01');
            }
        );
    }

    /**
     * Tests sanitizing a hex with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatHex()
    {
        $this->specify(
            "sanitizing hex with float filter not correct",
            function () {
                $this->sanitizer('float', '0xFFA', 0xFFA);
            }
        );
    }

    /**
     * Tests sanitizing a string number with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatStringNumber()
    {
        $this->specify(
            "sanitizing string number with float filter not correct",
            function () {
                $this->sanitizer('float', '1000.01', '1000.01');
            }
        );
    }

    /**
     * Tests sanitizing a string with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatString()
    {
        $this->specify(
            "sanitizing string with float filter not correct",
            function () {
                $this->sanitizer('float', '', 'lol');
            }
        );
    }

    /**
     * Tests sanitizing a string with float filter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testSanitizeFloatStringCombined()
    {
        $this->specify(
            "sanitizing string combined with float filter not correct",
            function () {
                $this->sanitizer('float', '10001901.01', '!10001901.01a');
            }
        );
    }
}
