<?php
/**
 * FilterAlphanumTest.php
 * \Phalcon\Text\FilterAlphanumTest
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

use Phalcon\Filter;

class FilterAlphanumTest extends Helper\FilterBase
{
    /**
     * Tests Alphanum with an integer using constant
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2015-04-21
     */
    public function testSanitizeAlphanumIntegerConstant()
    {
        $this->specify(
            "Alphanum integer (constant) filter is not correct",
            function () {
                $expected = '0';
                $value    = 0;
                $this->sanitizer(Filter::FILTER_ALPHANUM, $expected, $value);
            }
        );
    }

    /**
     * Tests Alphanum with an integer
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeAlphanumInteger()
    {
        $this->specify(
            "Alphanum integer filter is not correct",
            function () {
                $expected = '0';
                $value    = 0;
                $this->sanitizer('alphanum', $expected, $value);
            }
        );
    }

    /**
     * Tests Alphanum with a null
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeAlphanumNull()
    {
        $this->specify(
            "Alphanum null filter is not correct",
            function () {
                $expected = '';
                $value    = null;
                $this->sanitizer('alphanum', $expected, $value);
            }
        );
    }

    /**
     * Tests Alphanum with a mixed string
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-30
     */
    public function testSanitizeAlphanumMixed()
    {
        $this->specify(
            "Alphanum mixed string filter is not correct",
            function () {
                $expected = 'a5xkat1sXan';
                $value    = '?a&5xka\tŧ?1-s.Xa[\n';
                $this->sanitizer('alphanum', $expected, $value);
            }
        );
    }
}
