<?php
/**
 * TagTelFieldCest.php
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

class TagTelFieldCest extends TagBase
{
    /**
     * Tests telField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldBasic(CodeGuy $I)
    {
        $this->telFieldBasic($I, false);
    }

    /**
     * Tests telField with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldBasicXHTML(CodeGuy $I)
    {
        $this->telFieldBasic($I, true);
    }

    /**
     * Tests telField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldWithArrayBasic(CodeGuy $I)
    {
        $this->telFieldWithArrayBasic($I, false);
    }

    /**
     * Tests telField with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->telFieldWithArrayBasic($I, true);
    }

    /**
     * Tests telField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldWithIdInParameters(CodeGuy $I)
    {
        $this->telFieldWithIdInParameters($I, false);
    }

    /**
     * Tests telField with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->telFieldWithIdInParameters($I, true);
    }

    /**
     * Tests telField with name and no id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->telFieldWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests telField with name and no id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->telFieldWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests telField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldSetDefault(CodeGuy $I)
    {
        $this->telFieldSetDefault($I, false);
    }

    /**
     * Tests telField with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldSetDefaultXHTML(CodeGuy $I)
    {
        $this->telFieldSetDefault($I, true);
    }

    /**
     * Tests telField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldDisplayTo(CodeGuy $I)
    {
        $this->telFieldDisplayTo($I, false);
    }

    /**
     * Tests telField with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldDisplayToXHTML(CodeGuy $I)
    {
        $this->telFieldDisplayTo($I, true);
    }

    /**
     * Tests telField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->telFieldSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests telField with setDefault to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->telFieldSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests telField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->telFieldDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests telField with displayTo to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testTelFieldDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->telFieldDisplayToElementNotPresent($I, true);
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
    private function telFieldBasic(CodeGuy $I, $xhtml)
    {
        $options  = 'some_field_name';
        $expected = '<input type="tel" id="some_field_name" '
            . 'name="some_field_name" value=""';

        $this->runBasic('telField', $I, $options, $expected, $xhtml);
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
    private function telFieldWithArrayBasic(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="tel" id="some_field_name" '
            . 'name="some_field_name" value="" class="some_class"';

        $this->runWithArrayBasic('telField', $I, $options, $expected, $xhtml);
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
    private function telFieldWithIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="tel" id="some_id" name="some_field_name" '
            . 'value="" class="some_class" size="10"';

        $this->runWithIdInParameters('telField', $I, $options, $expected, $xhtml);
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
    private function telFieldWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="tel" id="some_field_name" '
            . 'name="some_other_name" value="" class="some_class" '
            . 'size="10"';

        $this->runWithNameAndNotIdInParameters(
            'telField',
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
    private function telFieldSetDefault(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="tel" id="some_field_name" '
            . 'name="some_field_name" value="some_default_value" '
            . 'class="some_class" size="10"';

        $this->runSetDefault(
            'telField',
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
    private function telFieldDisplayTo(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="tel" id="some_field_name" '
            . 'name="some_field_name" value="some_default_value" '
            . 'class="some_class" size="10"';

        $this->runDisplayTo(
            'telField',
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
    private function telFieldSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="tel" id="some_field" '
            . 'name="some_field" value="" class="some_class" '
            . 'size="10"';

        $this->runSetDefault(
            'telField',
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
    private function telFieldDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="tel" id="some_field" '
            . 'name="some_field" value="" class="some_class" '
            . 'size="10"';

        $this->runDisplayTo(
            'telField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }
}
