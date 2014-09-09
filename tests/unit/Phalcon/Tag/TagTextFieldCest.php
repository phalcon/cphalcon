<?php
/**
 * TagTextFieldCest.php
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

class TagTextFieldCest extends TagBase
{
    /**
     * Tests testField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     * 
     * @param CodeGuy $I
     */
    public function testTextFieldBasic(CodeGuy $I)
    {
        $this->textFieldBasic($I, false);
    }

    /**
     * Tests testField with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldBasicXHTML(CodeGuy $I)
    {
        $this->textFieldBasic($I, true);
    }

    /**
     * Tests textField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldWithArrayBasic(CodeGuy $I)
    {
        $this->textFieldWithArrayBasic($I, false);
    }

    /**
     * Tests textField with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->textFieldWithArrayBasic($I, true);
    }

    /**
     * Tests textField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldWithIdInParameters(CodeGuy $I)
    {
        $this->textFieldWithIdInParameters($I, false);
    }

    /**
     * Tests textField with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->textFieldWithIdInParameters($I, true);
    }

    /**
     * Tests textField with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->textFieldWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests textField with name and not id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->textFieldWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests textField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldSetDefault(CodeGuy $I)
    {
        $this->textFieldSetDefault($I, false);
    }

    /**
     * Tests textField with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldSetDefaultXHTML(CodeGuy $I)
    {
        $this->textFieldSetDefault($I, true);
    }

    /**
     * Tests textField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldDisplayTo(CodeGuy $I)
    {
        $this->textFieldDisplayTo($I, false);
    }

    /**
     * Tests textField with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldDisplayToXHTML(CodeGuy $I)
    {
        $this->textFieldDisplayTo($I, true);
    }

    /**
     * Tests textField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->textFieldSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests textField with setDefault to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->textFieldSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests textField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->textFieldDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests textField with displayTo to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTextFieldDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->textFieldDisplayToElementNotPresent($I, true);
    }

    /**
     * PRIVATE METHODS
     */
    /**
     * Runs tests with string as a parameter for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function textFieldBasic(CodeGuy $I, $xhtml)
    {
        $options  = 'some_field_name';
        $expected = '<input type="text" id="some_field_name" '
                  . 'name="some_field_name" value=""';

        $this->runBasic('textField', $I, $options, $expected, $xhtml);
    }

    /**
     * Runs tests with array as parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function textFieldWithArrayBasic(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="text" id="some_field_name" '
                  . 'name="some_field_name" value="" class="some_class"';

        $this->runWithArrayBasic('textField', $I, $options, $expected, $xhtml);
    }

    /**
     * Runs tests with id in parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function textFieldWithIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" id="some_id" name="some_field_name" '
                  . 'value="" class="some_class" size="10"';

        $this->runWithIdInParameters(
            'textField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }

    /**
     * Runs tests with name and not id in parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function textFieldWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" id="some_field_name" '
                  . 'name="some_other_name" value="" class="some_class" '
                  . 'size="10"';

        $this->runWithNameAndNotIdInParameters(
            'textField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }

    /**
     * Runs tests with setDefault for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function textFieldSetDefault(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );

        $expected = '<input type="text" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runSetDefault(
            'textField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }

    /**
     * Runs tests with displayTo for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function textFieldDisplayTo(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runDisplayTo(
            'textField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }

    /**
     * Runs tests with setDefault to an non existent element for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function textFieldSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" id="some_field" '
                  . 'name="some_field" value="" class="some_class" '
                  . 'size="10"';

        $this->runSetDefault(
            'textField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }

    /**
     * Runs tests with displayTo to an non existent element for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function textFieldDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="text" id="some_field" '
                  . 'name="some_field" value="" class="some_class" '
                  . 'size="10"';

        $this->runDisplayTo(
            'textField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }
}
