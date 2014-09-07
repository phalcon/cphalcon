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
    // radioField
    // -------------------------------------------------------------------------
    /**
     * Tests radioField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="">';
        $actual   = PhTag::radioField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField basic')
        );
    }

    /**
     * Tests radioField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class">';
        $actual   = PhTag::radioField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField basic with array')
        );
    }

    /**
     * Tests radioField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="radio" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = PhTag::radioField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with id in parameters')
        );
    }

    /**
     * Tests radioField with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="radio" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
        $actual   = PhTag::radioField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'radioField with name and id in parameters'
            )
        );
    }

    /**
     * Tests radioField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked">';
        $actual   = PhTag::radioField($options);
        PhTag::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with setDefault')
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked">';
        $actual   = PhTag::radioField($options);
        PhTag::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with displayTo')
        );
    }

    /**
     * Tests radioField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = PhTag::radioField($options);
        PhTag::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with setDefault')
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = PhTag::radioField($options);
        PhTag::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'radioField with displayTo')
        );
    }

    /**
     * Tests radioField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldBasicXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" />';
        $actual   = PhTag::radioField($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField basic')
        );
    }

    /**
     * Tests radioField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldWithArrayBasicXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" />';
        $actual   = PhTag::radioField($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField basic with array')
        );
    }

    /**
     * Tests radioField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldWithIdInParametersXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="radio" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = PhTag::radioField($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with id in parameters')
        );
    }

    /**
     * Tests radioField with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldWithNameAndNotIdInParametersXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="radio" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
        $actual   = PhTag::radioField($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'radioField with name and id in parameters'
            )
        );
    }

    /**
     * Tests radioField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldSetDefaultXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked" />';
        $actual   = PhTag::radioField($options);
        PhTag::setDefault('some_field_name', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with setDefault')
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldDisplayToXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" checked="checked" />';
        $actual   = PhTag::radioField($options);
        PhTag::displayTo('some_field_name', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with displayTo')
        );
    }

    /**
     * Tests radioField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldSetDefaultElementNotPresentXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = PhTag::radioField($options);
        PhTag::setDefault('some_field', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with setDefault')
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-09-15
     */
    public function testRadioFieldDisplayToElementNotPresentXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="radio" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = PhTag::radioField($options);
        PhTag::displayTo('some_field', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML radioField with displayTo')
        );
    }
}
