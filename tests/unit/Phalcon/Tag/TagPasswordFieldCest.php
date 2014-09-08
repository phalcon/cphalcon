<?php
/**
 * TagPasswordFieldCest.php
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

class TagPasswordFieldCest extends TagBase
{
    /**
     * Tests passwordField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldBasic(CodeGuy $I)
    {
        $this->passwordFieldBasic($I, false);
    }

    /**
     * Tests passwordField with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldBasicXHTML(CodeGuy $I)
    {
        $this->passwordFieldBasic($I, true);
    }

    /**
     * Tests passwordField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldWithArrayBasic(CodeGuy $I)
    {
        $this->passwordFieldWithArrayBasic($I, false);
    }

    /**
     * Tests passwordField with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->passwordFieldWithArrayBasic($I, true);
    }

    /**
     * Tests passwordField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldWithIdInParameters(CodeGuy $I)
    {
        $this->passwordFieldWithIdInParameters($I, false);
    }

    /**
     * Tests passwordField with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->passwordFieldWithIdInParameters($I, true);
    }

    /**
     * Tests passwordField with name and no id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->passwordFieldWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests passwordField with name and no id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->passwordFieldWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests passwordField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldSetDefault(CodeGuy $I)
    {
        $this->passwordFieldSetDefault($I, false);
    }

    /**
     * Tests passwordField with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldSetDefaultXHTML(CodeGuy $I)
    {
        $this->passwordFieldSetDefault($I, true);
    }

    /**
     * Tests passwordField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldDisplayTo(CodeGuy $I)
    {
        $this->passwordFieldDisplayTo($I, false);
    }

    /**
     * Tests passwordField with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldDisplayToXHTML(CodeGuy $I)
    {
        $this->passwordFieldDisplayTo($I, true);
    }

    /**
     * Tests passwordField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->passwordFieldSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests passwordField with setDefault to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->passwordFieldSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests passwordField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->passwordFieldDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests passwordField with displayTo to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testPasswordFieldDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->passwordFieldDisplayToElementNotPresent($I, true);
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
    private function passwordFieldBasic(CodeGuy $I, $xhtml)
    {
        $options  = 'some_field_name';
        $expected = '<input type="password" id="some_field_name" '
                  . 'name="some_field_name"';

        $this->runBasic('passwordField', $I, $options, $expected, $xhtml);
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
    private function passwordFieldWithArrayBasic(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="password" id="some_field_name" '
                  . 'name="some_field_name" class="some_class"';

        $this->runWithArrayBasic('passwordField', $I, $options, $expected, $xhtml);
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
    private function passwordFieldWithIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_id" name="some_field_name" '
                  . 'class="some_class" size="10"';

        $this->runWithIdInParameters('passwordField', $I, $options, $expected, $xhtml);
    }

    /**
     * Runs tests with name and no id in parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function passwordFieldWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_field_name" '
                  . 'name="some_other_name" class="some_class" size="10"';

        $this->runWithNameAndNotIdInParameters(
            'passwordField',
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
    private function passwordFieldSetDefault(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runSetDefault(
            'passwordField',
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
    private function passwordFieldDisplayTo(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runDisplayTo(
            'passwordField',
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
    private function passwordFieldSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_field" '
                  . 'name="some_field" class="some_class" '
                  . 'size="10"';

        $this->runSetDefault(
            'passwordField',
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
    private function passwordFieldDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="password" id="some_field" '
                  . 'name="some_field" class="some_class" '
                  . 'size="10"';

        $this->runDisplayTo(
            'passwordField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }
}
