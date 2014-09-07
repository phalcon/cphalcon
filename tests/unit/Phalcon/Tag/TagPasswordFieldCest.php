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
    // passwordField
    // -------------------------------------------------------------------------
    /**
     * Tests passwordField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testPasswordFieldBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="">';
        $actual   = \Phalcon\Tag::passwordField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField basic')
        );
    }

    /**
     * Tests passwordField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testPasswordFieldWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class">';
        $actual   = \Phalcon\Tag::passwordField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField basic with array')
        );
    }

    /**
     * Tests passwordField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testPasswordFieldWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = \Phalcon\Tag::passwordField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with id in parameters')
        );
    }

    /**
     * Tests passwordField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testPasswordFieldWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
        $actual   = \Phalcon\Tag::passwordField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'passwordField with name and id in parameters'
            )
        );
    }

    /**
     * Tests passwordField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testPasswordFieldSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        \Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with setDefault')
        );
    }

    /**
     * Tests passwordField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testPasswordFieldDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        \Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with displayTo')
        );
    }

    /**
     * Tests passwordField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testPasswordFieldSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        \Phalcon\Tag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with setDefault')
        );
    }

    /**
     * Tests passwordField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-29
     */
    public function testPasswordFieldDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        \Phalcon\Tag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'passwordField with displayTo')
        );
    }

    /**
     * Tests passwordField with string as a parameter
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testPasswordFieldBasicXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="" />';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField basic')
        );
    }

    /**
     * Tests passwordField with array as parameters
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testPasswordFieldWithArrayBasicXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" />';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField basic with array')
        );
    }

    /**
     * Tests passwordField with id in parameters
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testPasswordFieldWithIdInParametersXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with id in parameters')
        );
    }

    /**
     * Tests passwordField with name and not id in parameters
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testPasswordFieldWithNameAndNotIdInParametersXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'passwordField with name and id in parameters'
            )
        );
    }

    /**
     * Tests passwordField with setDefault
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testPasswordFieldSetDefaultXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        \Phalcon\Tag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::setDefault('some_field_name', '');
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with setDefault')
        );
    }

    /**
     * Tests passwordField with displayTo
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testPasswordFieldDisplayToXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        \Phalcon\Tag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::displayTo('some_field_name', '');
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with displayTo')
        );
    }

    /**
     * Tests passwordField with setDefault to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testPasswordFieldSetDefaultElementNotPresentXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        \Phalcon\Tag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::setDefault('some_field', '');
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with setDefault')
        );
    }

    /**
     * Tests passwordField with displayTo to an non existent element
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-10-26
     */
    public function testPasswordFieldDisplayToElementNotPresentXHTML()
    {
        \Phalcon\Tag::setDoctype(\Phalcon\Tag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        \Phalcon\Tag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="password" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = \Phalcon\Tag::passwordField($options);
        \Phalcon\Tag::displayTo('some_field', '');
        \Phalcon\Tag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML passwordField with displayTo')
        );
    }

}
