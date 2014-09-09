<?php
/**
 * TagLinkToCest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
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

namespace Phalcon\Tests\unit\Phalcon\Tag;

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagLinkToCest extends TagBase
{
    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
//    public function testGet(CodeGuy $I)
//    {
//        $actual = Version::get();
//
//        $I->assertTrue(
//            is_string($actual),
//            'get() does not return a string'
//        );
//    }

    // -------------------------------------------------------------------------
    // linkTo
    // -------------------------------------------------------------------------
    /**
     * Tests linkTo with string as url and name parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-08
     */
    public function testLinkToWithStringAsURLAndName(CodeGuy $I)
    {
        $url  = 'some_url';
        $name = 'some_name';

        $expected = '<a href="/some_url">some_name</a>';
        $actual   = PhTag::linkTo($url, $name);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'linkTo with strings as parameters')
        );
    }

    /**
     * Tests linkTo with empty string as URL and string as name parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-08
     */
    public function testLinkToWithEmptyStringAsURLAndStringAsName(CodeGuy $I)
    {
        $url  = '';
        $name = 'some_name';

        $expected = '<a href="/">some_name</a>';
        $actual   = PhTag::linkTo($url, $name);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'linkTo with empty URL and string as name')
        );
    }

    /**
     * Tests linkTo with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-08
     */
    public function testLinkToWithArrayBasic(CodeGuy $I)
    {
        $params = array(
            'some_url',
            'some_name',
        );
        $expected = '<a href="/some_url">some_name</a>';
        $actual   = PhTag::linkTo($params);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'linkTo with array as parameters')
        );
    }

    /**
     * Tests linkTo with named array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-08
     */
    public function testLinkToWithArrayNamedBasic(CodeGuy $I)
    {
        $params = array(
            'action' => 'some_url',
            'text'   => 'some_name',
        );
        $expected = '<a href="/some_url">some_name</a>';
        $actual   = PhTag::linkTo($params);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'linkTo with named array as parameters basic'
            )
        );
    }

    /**
     * Tests linkTo with named array as parameters (more than the basic)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-08
     */
    public function testLinkToWithArrayNamed(CodeGuy $I)
    {
        $params = array(
            'action' => 'some_url',
            'text'   => 'some_name',
            'class'  => 'btn btn-primary',
        );
        $expected = '<a href="/some_url" class="btn btn-primary">some_name</a>';
        $actual   = PhTag::linkTo($params);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'linkTo with named array as parameters (full params)'
            )
        );
    }


    public function testIssue1679(CodeGuy $I)
    {
        // local
        $html = PhTag::linkTo('signup/register', 'Register Here!');
        $I->assertEquals($html, '<a href="/signup/register">Register Here!</a>');

        $html = PhTag::linkTo(array('signup/register', 'Register Here!'));
        $I->assertEquals($html, '<a href="/signup/register">Register Here!</a>');

        $html = PhTag::linkTo(array('signup/register', 'Register Here!', 'class' => 'btn-primary'));
        $I->assertEquals($html, '<a href="/signup/register" class="btn-primary">Register Here!</a>');

        // remote
        $html = PhTag::linkTo('http://phalconphp.com/en/', 'Phalcon Home', FALSE);
        $I->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

        $html = PhTag::linkTo(array('http://phalconphp.com/en/', 'Phalcon Home', FALSE));
        $I->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

        $html = PhTag::linkTo(array('http://phalconphp.com/en/', 'text' => 'Phalcon Home', 'local' => FALSE));
        $I->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

        $html = PhTag::linkTo('mailto:dreamsxin@gmail.com', 'dreamsxin@gmail.com', FALSE);
        $I->assertEquals($html, '<a href="mailto:dreamsxin@gmail.com">dreamsxin@gmail.com</a>');
    }
}
