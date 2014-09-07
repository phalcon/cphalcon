<?php
/**
 * TagFileFieldCest.php
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

class TagFileFieldCest
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

    /**
     * Tests fileField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldBasic()
    {
        $options  = 'some_field_name';
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="">';
        $actual   = PhTag::fileField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField basic')
        );
    }

    /**
     * Tests fileField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithArrayBasic()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class">';
        $actual   = PhTag::fileField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField basic with array')
        );
    }

    /**
     * Tests fileField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithIdInParameters()
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_id" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = PhTag::fileField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with id in parameters')
        );
    }

    /**
     * Tests fileField with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithNameAndNotIdInParameters()
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_field_name" name="some_other_name" value="" class="some_class" size="10">';
        $actual   = PhTag::fileField($options);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'fileField with name and id in parameters'
            )
        );
    }

    /**
     * Tests fileField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldSetDefault()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
        $actual   = PhTag::fileField($options);
        PhTag::setDefault('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with setDefault')
        );
    }

    /**
     * Tests fileField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldDisplayTo()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10">';
        $actual   = PhTag::fileField($options);
        PhTag::displayTo('some_field_name', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with displayTo')
        );
    }

    /**
     * Tests fileField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldSetDefaultElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = PhTag::fileField($options);
        PhTag::setDefault('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with setDefault')
        );
    }

    /**
     * Tests fileField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldDisplayToElementNotPresent()
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" size="10">';
        $actual   = PhTag::fileField($options);
        PhTag::displayTo('some_field', '');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'fileField with displayTo')
        );
    }

    /**
     * Tests fileField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldBasicXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options  = 'some_field_name';
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="" />';
        $actual   = PhTag::fileField($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField basic')
        );
    }

    /**
     * Tests fileField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldWithArrayBasicXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" />';
        $actual   = PhTag::fileField($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField basic with array')
        );
    }

    /**
     * Tests fileField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldWithIdInParametersXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_id" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = PhTag::fileField($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with id in parameters')
        );
    }

    /**
     * Tests fileField with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldWithNameAndNotIdInParametersXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_field_name" name="some_other_name" value="" class="some_class" size="10" />';
        $actual   = PhTag::fileField($options);
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'fileField with name and id in parameters'
            )
        );
    }

    /**
     * Tests fileField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldSetDefaultXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
        $actual   = PhTag::fileField($options);
        PhTag::setDefault('some_field_name', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with setDefault')
        );
    }

    /**
     * Tests fileField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldDisplayToXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="some_default_value" class="some_class" size="10" />';
        $actual   = PhTag::fileField($options);
        PhTag::displayTo('some_field_name', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with displayTo')
        );
    }

    /**
     * Tests fileField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldSetDefaultElementNotPresentXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = PhTag::fileField($options);
        PhTag::setDefault('some_field', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with setDefault')
        );
    }

    /**
     * Tests fileField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldDisplayToElementNotPresentXHTML()
    {
        PhTag::setDoctype(PhTag::XHTML10_STRICT);
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="file" id="some_field_name" name="some_field_name" value="" class="some_class" size="10" />';
        $actual   = PhTag::fileField($options);
        PhTag::displayTo('some_field', '');
        PhTag::setDoctype('');

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'XHTML fileField with displayTo')
        );
    }
}
