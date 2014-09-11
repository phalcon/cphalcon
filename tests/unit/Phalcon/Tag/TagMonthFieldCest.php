<?php
/**
 * TagMonthFieldCest.php
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

class TagMonthFieldCest extends TagBase
{
    /**
     * Tests monthField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldBasic(CodeGuy $I)
    {
        $this->monthFieldBasic($I, false);
    }

    /**
     * Tests monthField with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldBasicXHTML(CodeGuy $I)
    {
        $this->monthFieldBasic($I, true);
    }

    /**
     * Tests monthField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldWithArrayBasic(CodeGuy $I)
    {
        $this->monthFieldWithArrayBasic($I, false);
    }

    /**
     * Tests monthField with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->monthFieldWithArrayBasic($I, true);
    }

    /**
     * Tests monthField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldWithIdInParameters(CodeGuy $I)
    {
        $this->monthFieldWithIdInParameters($I, false);
    }

    /**
     * Tests monthField with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->monthFieldWithIdInParameters($I, true);
    }

    /**
     * Tests monthField with name and no id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->monthFieldWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests monthField with name and no id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->monthFieldWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests monthField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldSetDefault(CodeGuy $I)
    {
        $this->monthFieldSetDefault($I, false);
    }

    /**
     * Tests monthField with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldSetDefaultXHTML(CodeGuy $I)
    {
        $this->monthFieldSetDefault($I, true);
    }

    /**
     * Tests monthField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldDisplayTo(CodeGuy $I)
    {
        $this->monthFieldDisplayTo($I, false);
    }

    /**
     * Tests monthField with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldDisplayToXHTML(CodeGuy $I)
    {
        $this->monthFieldDisplayTo($I, true);
    }

    /**
     * Tests monthField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->monthFieldSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests monthField with setDefault to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->monthFieldSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests monthField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->monthFieldDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests monthField with displayTo to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testMonthFieldDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->monthFieldDisplayToElementNotPresent($I, true);
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
    private function monthFieldBasic(CodeGuy $I, $xhtml)
    {
        $options  = 'some_field_name';
        $expected = '<input type="month" id="some_field_name" '
                  . 'name="some_field_name" value=""';

        $this->runBasic('monthField', $I, $options, $expected, $xhtml);
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
    private function monthFieldWithArrayBasic(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="month" id="some_field_name" '
                  . 'name="some_field_name" value="" class="some_class"';

        $this->runWithArrayBasic('monthField', $I, $options, $expected, $xhtml);
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
    private function monthFieldWithIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="month" id="some_id" name="some_field_name" '
                  . 'value="" class="some_class" size="10"';

        $this->runWithIdInParameters('monthField', $I, $options, $expected, $xhtml);
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
    private function monthFieldWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="month" id="some_field_name" '
                  . 'name="some_other_name" value="" class="some_class" '
                  . 'size="10"';

        $this->runWithNameAndNotIdInParameters(
            'monthField',
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
    private function monthFieldSetDefault(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="month" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runSetDefault(
            'monthField',
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
    private function monthFieldDisplayTo(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="month" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runDisplayTo(
            'monthField',
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
    private function monthFieldSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="month" id="some_field" '
                  . 'name="some_field" value="" class="some_class" '
                  . 'size="10"';

        $this->runSetDefault(
            'monthField',
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
    private function monthFieldDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="month" id="some_field" '
                  . 'name="some_field" value="" class="some_class" '
                  . 'size="10"';

        $this->runDisplayTo(
            'monthField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }
}
