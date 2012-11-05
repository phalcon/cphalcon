<?php
/**
 * UnitTest.php
 * Filter_UnitTest
 *
 * Tests the \Phalcon\Filter component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use Phalcon\Filter as Flt;

class Filter_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests the filter with a string (US characters)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSanitizeStringStringFilter()
    {
        $filter = new Flt;

        $source = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>';

        $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
        $actual   = $filter->sanitize($source, 'string');

        $this->assertEquals(
            $expected,
            $actual,
            'String filter with latin does not return correct data'
        );
    }

    /**
     * Tests the filter with a string (International characters)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSanitizeStringUTF8StringFilter()
    {
        $filter = new Flt;

        $source = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>';

        $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
        $actual   = $filter->sanitize($source, 'string');

        $this->assertEquals(
            $expected,
            $actual,
            'String filter with UTF8 does not return correct data'
        );
    }

    /**
     * Tests the filter with an array filter (US characters)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSanitizeStringArrayFilter()
    {
        $filter = new Flt;

        $source = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+<>';

        $expected = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';
        $actual   = $filter->sanitize($source, array('string'));

        $this->assertEquals(
            $expected,
            $actual,
            'String filter with latin does not return correct data'
        );
    }

    /**
     * Tests the filter with an array filter (International characters)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSanitizeStringUTF8ArrayFilter()
    {
        $filter = new Flt;

        $source = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+<>';

        $expected = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';
        $actual   = $filter->sanitize($source, array('string'));

        $this->assertEquals(
            $expected,
            $actual,
            'String filter with UTF8 does not return correct data'
        );
    }

    /**
     * Tests the filter with a string (no filtering) (US characters)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSanitizeStringStringFilterValidString()
    {
        $filter = new Flt;

        $source = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';

        $expected = $source;
        $actual   = $filter->sanitize($source, 'string');

        $this->assertEquals(
            $expected,
            $actual,
            'String filter with latin does not return correct data'
        );
    }

    /**
     * Tests the filter with a string (no filtering) (International characters)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSanitizeStringUTF8StringFilterValidString()
    {
        $filter = new Flt;

        $source = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';

        $expected = $source;
        $actual   = $filter->sanitize($source, 'string');

        $this->assertEquals(
            $expected,
            $actual,
            'String filter with UTF8 does not return correct data'
        );
    }

    /**
     * Tests the filter with an array filter (no filtering) (US characters)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSanitizeArrayFilterValidString()
    {
        $filter = new Flt;

        $source = 'abcdefghijklmnopqrstuvwzyx1234567890!@#$%^&*()_ `~=+';

        $expected = $source;
        $actual   = $filter->sanitize($source, array('string'));

        $this->assertEquals(
            $expected,
            $actual,
            'String filter with latin does not return correct data'
        );
    }

    /**
     * Tests the filter with an array filter (no filtering)
     * (International characters)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSanitizeUTF8ArrayFilterValidStringNoFilter()
    {
        $filter = new Flt;

        $source = 'buenos días123καλημέρα!@#$%^&*早安()_ `~=+';

        $expected = $source;
        $actual   = $filter->sanitize($source, array('string'));

        $this->assertEquals(
            $expected,
            $actual,
            'String filter with UTF8 does not return correct data'
        );
    }

//    public function testSanitizeInt()
//    {
//
//        $filter = new Phalcon\Filter();
//
//        $value = $filter->sanitize(1000, "int");
//        $this->assertEquals($value, "1000");
//
//        $value = $filter->sanitize(0xFFA, "int");
//        $this->assertEquals($value, "0xFFA");
//
//        $value = $filter->sanitize("1000", "int");
//        $this->assertEquals($value, "1000");
//
//        $value = $filter->sanitize("lol", "int");
//        $this->assertEquals($value, "");
//
//        $value = $filter->sanitize("!100a019", "int");
//        $this->assertEquals($value, "100019");
//
//    }
//
//    public function testSanitizeFloat()
//    {
//        $filter = new Phalcon\Filter();
//
//        $value = $filter->sanitize(11.10, "float");
//        $this->assertEquals($value, "11.10");
//
//        $value = $filter->sanitize("11.10", "float");
//        $this->assertEquals($value, "11.10");
//
//        $value = $filter->sanitize("!100a019.01a", "float");
//        $this->assertEquals($value, "100019.01");
//
//    }
//
//    public function testSanitizeEmail()
//    {
//        $filter = new Phalcon\Filter();
//
//        $value = $filter->sanitize("some(one)@exa\\mple.com", "email");
//        $this->assertEquals($value, "someone@example.com");
//    }
//
//    public function testSanitizeAlphanum()
//    {
//
//        $filter = new Phalcon\Filter();
//
//        $value = $filter->sanitize(0, "alphanum");
//        $this->assertEquals($value, "0");
//
//        $value = $filter->sanitize(null, "alphanum");
//        $this->assertEquals($value, "");
//
//        $value = $filter->sanitize("?a&5xka\tŧ?1-s.Xa[\n", "alphanum");
//        $this->assertEquals($value, "a5xka1sXa");
//
//    }
//
//    public function testSanitizeStriptags()
//    {
//
//        $filter = new Phalcon\Filter();
//
//        $value = $filter->sanitize("<h1>Hello</h1>", "striptags");
//        $this->assertEquals($value, "Hello");
//
//        $value = $filter->sanitize("<h1><p>Hello</h1>", "striptags");
//        $this->assertEquals($value, "Hello");
//
//        $value = $filter->sanitize("<", "striptags");
//        $this->assertEquals($value, "");
//
//    }
//
//    public function testSanitizeTrim()
//    {
//
//        $filter = new Phalcon\Filter();
//
//        $value = $filter->sanitize(" Hello   ", "trim");
//        $this->assertEquals($value, "Hello");
//
//        $value = $filter->sanitize("Hello   ", "trim");
//        $this->assertEquals($value, "Hello");
//
//        $value = $filter->sanitize("   Hello", "trim");
//        $this->assertEquals($value, "Hello");
//
//        $value = $filter->sanitize("HELLO", "lower");
//        $this->assertEquals($value, "hello");
//
//        $value = $filter->sanitize("hello", "upper");
//        $this->assertEquals($value, "HELLO");
//
//    }
//
//    public function testMultiple()
//    {
//
//        $filter = new Phalcon\Filter();
//
//        $value = $filter->sanitize("   lol<<   ", array("string", "trim"));
//        $this->assertEquals($value, "lol");
//    }
//
//    public function testAddFilter()
//    {
//        $filter = new Phalcon\Filter();
//
//        $filter->add('md5', function($value) {
//            $filtered = preg_replace('/[^0-9a-f]/', '', $value);
//            if (strlen($filtered) != 32) {
//                return false;
//            }
//            return $value;
//        });
//
//        $filter->add('ipv4', new IPv4Filter());
//
//        $this->assertFalse($filter->sanitize('Lladlad12', 'md5'), false);
//        $this->assertEquals($filter->sanitize(md5('why?'), 'md5'), md5('why?'));
//
//        $this->assertEquals($filter->sanitize('00:1c:42:bf:71:22', 'ipv4'), null);
//        $this->assertEquals($filter->sanitize('127.0.0.1', 'ipv4'), '127.0.0.1');
//
//    }

}

