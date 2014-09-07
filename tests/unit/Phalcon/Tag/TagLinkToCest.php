<?php
/**
 * TagCest.php
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

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagCest
{
    /**
     * Tests the get
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testGet(CodeGuy $I)
    {
        $actual = Version::get();

        $I->assertTrue(
            is_string($actual),
            'get() does not return a string'
        );
    }

    // -------------------------------------------------------------------------
    // linkTo
    // -------------------------------------------------------------------------
    /**
     * Tests linkTo with string as url and name parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-08
     */
    public function testLinkToWithStringAsURLAndName()
    {
        $url  = 'some_url';
        $name = 'some_name';

        $expected = '<a href="/some_url">some_name</a>';
        $actual   = PhTag::linkTo($url, $name);

        $this->assertEquals(
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
    public function testLinkToWithEmptyStringAsURLAndStringAsName()
    {
        $url  = '';
        $name = 'some_name';

        $expected = '<a href="/">some_name</a>';
        $actual   = PhTag::linkTo($url, $name);

        $this->assertEquals(
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
    public function testLinkToWithArrayBasic()
    {
        $params = array(
            'some_url',
            'some_name',
        );
        $expected = '<a href="/some_url">some_name</a>';
        $actual   = PhTag::linkTo($params);

        $this->assertEquals(
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
    public function testLinkToWithArrayNamedBasic()
    {
        $params = array(
            'action' => 'some_url',
            'text'   => 'some_name',
        );
        $expected = '<a href="/some_url">some_name</a>';
        $actual   = PhTag::linkTo($params);

        $this->assertEquals(
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
    public function testLinkToWithArrayNamed()
    {
        $params = array(
            'action' => 'some_url',
            'text'   => 'some_name',
            'class'  => 'btn btn-primary',
        );
        $expected = '<a href="/some_url" class="btn btn-primary">some_name</a>';
        $actual   = PhTag::linkTo($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'linkTo with named array as parameters (full params)'
            )
        );
    }


    public function testIssue1679()
    {
        $di = new Phalcon\DI\FactoryDefault();
        $di->getshared('url')->setBaseUri('/');
        PhTag::setDI($di);

        // local
        $html = Phalcon\Tag::linkTo('signup/register', 'Register Here!');
        $this->assertEquals($html, '<a href="/signup/register">Register Here!</a>');

        $html = Phalcon\Tag::linkTo(array('signup/register', 'Register Here!'));
        $this->assertEquals($html, '<a href="/signup/register">Register Here!</a>');

        $html = Phalcon\Tag::linkTo(array('signup/register', 'Register Here!', 'class' => 'btn-primary'));
        $this->assertEquals($html, '<a href="/signup/register" class="btn-primary">Register Here!</a>');

        // remote
        $html = Phalcon\Tag::linkTo('http://phalconphp.com/en/', 'Phalcon Home', FALSE);
        $this->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

        $html = Phalcon\Tag::linkTo(array('http://phalconphp.com/en/', 'Phalcon Home', FALSE));
        $this->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

        $html = Phalcon\Tag::linkTo(array('http://phalconphp.com/en/', 'text' => 'Phalcon Home', 'local' => FALSE));
        $this->assertEquals($html, '<a href="http://phalconphp.com/en/">Phalcon Home</a>');

        $html = Phalcon\Tag::linkTo('mailto:dreamsxin@gmail.com', 'dreamsxin@gmail.com', FALSE);
        $this->assertEquals($html, '<a href="mailto:dreamsxin@gmail.com">dreamsxin@gmail.com</a>');
    }
}
