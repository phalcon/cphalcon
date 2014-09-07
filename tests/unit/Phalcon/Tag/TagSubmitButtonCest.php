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
    // submitButton
    // -------------------------------------------------------------------------
    /**
     * Tests submitButton with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="submit" value="some_field_name">';
        $actual   = PhTag::submitButton($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton basic')
        );
    }

    /**
     * Tests submitButton with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
//        $expected = '<input type="submit" value="some_field_name" '
//                  . 'class="some_class">';
        $expected = '<input type="submit" value="some_field_name" class="some_class">';
        $actual   = PhTag::submitButton($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton basic with array')
        );
    }

    /**
     * Tests submitButton with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" id="some_id" value="some_field_name" class="some_class" size="10">';
        $actual   = PhTag::submitButton($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with id in parameters')
        );
    }

    /**
     * Tests submitButton with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" name="some_other_name" value="some_field_name" class="some_class" size="10">';
        $actual   = PhTag::submitButton($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'submitButton with name and id in parameters'
            )
        );
    }

    /**
     * Tests submitButton with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="submit" value="some_field_name" class="some_class" size="10">';
        $actual   = PhTag::submitButton($options);
        PhTag::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with setDefault')
        );
    }

    /**
     * Tests submitButton with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="submit" value="some_field_name" class="some_class" size="10">';
        $actual   = PhTag::submitButton($options);
        PhTag::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with displayTo')
        );
    }

    /**
     * Tests submitButton with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="submit" value="some_field_name" class="some_class" size="10">';
        $actual   = PhTag::submitButton($options);
        PhTag::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with setDefault')
        );
    }

    /**
     * Tests submitButton with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="submit" value="some_field_name" class="some_class" size="10">';
        $actual   = PhTag::submitButton($options);
        PhTag::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'submitButton with displayTo')
        );
    }

    /**
     * Tests submitButton with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonBasicXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="submit" value="some_field_name" />';
        $actual   = PhTag::submitButton($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton basic')
        );
    }

    /**
     * Tests submitButton with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonWithArrayBasicXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );

        $expected = '<input type="submit" value="some_field_name" class="some_class" />';
        $actual   = PhTag::submitButton($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton basic with array')
        );
    }

    /**
     * Tests submitButton with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonWithIdInParametersXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" id="some_id" value="some_field_name" class="some_class" size="10" />';
        $actual   = PhTag::submitButton($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with id in parameters')
        );
    }

    /**
     * Tests submitButton with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonWithNameAndNotIdInParametersXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" name="some_other_name" value="some_field_name" class="some_class" size="10" />';
        $actual   = PhTag::submitButton($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'submitButton with name and id in parameters'
            )
        );
    }

    /**
     * Tests submitButton with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonSetDefaultXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="submit" value="some_field_name" class="some_class" size="10" />';
        $actual   = PhTag::submitButton($options);
        PhTag::setDefault('some_field_name', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with setDefault')
        );
    }

    /**
     * Tests submitButton with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonDisplayToXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="submit" value="some_field_name" class="some_class" size="10" />';
        $actual   = PhTag::submitButton($options);
        PhTag::displayTo('some_field_name', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with displayTo')
        );
    }

    /**
     * Tests submitButton with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonSetDefaultElementNotPresentXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="submit" value="some_field_name" class="some_class" size="10" />';
        $actual   = PhTag::submitButton($options);
        PhTag::setDefault('some_field', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with setDefault')
        );
    }

    /**
     * Tests submitButton with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * @todo   Fix the order
     */
    public function testSubmitButtonDisplayToElementNotPresentXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="submit" value="some_field_name" class="some_class" size="10" />';
        $actual   = PhTag::submitButton($options);
        PhTag::displayTo('some_field', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML submitButton with displayTo')
        );
    }
}
