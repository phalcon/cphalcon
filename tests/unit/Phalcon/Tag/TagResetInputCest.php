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
    // resetInput
    // -------------------------------------------------------------------------
    /**
     * Tests resetInput (after a setDefault)
     *
     * @issue 53
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testResetInputSetDefaultT53()
    {
        $options  = 'some_field_name';
        $expected = '<input type="text" id="some_field_name" name="some_field_name" value="Wall-E">';
        \Phalcon\Tag::setDefault('some_field_name', 'Wall-E');
        $actual   = \Phalcon\Tag::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'resetInput before contains a value')
        );
        \Phalcon\Tag::resetInput();

        $expected = '<input type="text" id="some_field_name" name="some_field_name" value="">';
        $actual   = \Phalcon\Tag::textField($options);
        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'resetInput after contains a value')
        );
    }

    /**
     * Tests resetInput (after a displayTo)
     *
     * @issue 53
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testResetInputDisplayToT53()
    {
        $options  = 'some_field_name';
        $expected = '<input type="text" id="some_field_name" name="some_field_name" value="Wall-E">';
        \Phalcon\Tag::displayTo('some_field_name', 'Wall-E');
        $actual   = \Phalcon\Tag::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'resetInput before contains a value')
        );
        \Phalcon\Tag::resetInput();

        $expected = '<input type="text" id="some_field_name" name="some_field_name" value="">';
        $actual   = \Phalcon\Tag::textField($options);
        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'resetInput after contains a value')
        );
    }

    /**
     * Tests resetInput (after a setDefault)
     *
     * @issue 53
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testResetInputSetDefaultXHTMLT53()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="text" id="some_field_name" name="some_field_name" value="Wall-E" />';
        \Phalcon\Tag::setDefault('some_field_name', 'Wall-E');
        $actual   = \Phalcon\Tag::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML resetInput before contains a value')
        );
        \Phalcon\Tag::resetInput();

        $expected = '<input type="text" id="some_field_name" name="some_field_name" value="" />';
        $actual   = \Phalcon\Tag::textField($options);
        \Phalcon\Tag::setDoctype('');
        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML resetInput after contains a value')
        );
    }

    /**
     * Tests resetInput (after a displayTo)
     *
     * @issue 53
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testResetInputDisplayToXHTMLT53()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="text" id="some_field_name" name="some_field_name" value="Wall-E" />';
        \Phalcon\Tag::displayTo('some_field_name', 'Wall-E');
        $actual   = \Phalcon\Tag::textField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML resetInput before contains a value')
        );
        \Phalcon\Tag::resetInput();

        $expected = '<input type="text" id="some_field_name" name="some_field_name" value="" />';
        $actual   = \Phalcon\Tag::textField($options);
        \Phalcon\Tag::setDoctype('');
        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML resetInput after contains a value')
        );
    }

}
