<?php
/**
 * TagColorFieldCest.php
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

class TagColorFieldCest extends TagBase
{
    /**
     * Tests colorField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldBasic(CodeGuy $I)
    {
        $this->colorFieldBasic($I, false);
    }

    /**
     * Tests colorField with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldBasicXHTML(CodeGuy $I)
    {
        $this->colorFieldBasic($I, true);
    }

    /**
     * Tests colorField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldWithArrayBasic(CodeGuy $I)
    {
        $this->colorFieldWithArrayBasic($I, false);
    }

    /**
     * Tests colorField with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->colorFieldWithArrayBasic($I, true);
    }

    /**
     * Tests colorField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldWithIdInParameters(CodeGuy $I)
    {
        $this->colorFieldWithIdInParameters($I, false);
    }

    /**
     * Tests colorField with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->colorFieldWithIdInParameters($I, true);
    }

    /**
     * Tests colorField with name and no id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->colorFieldWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests colorField with name and no id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->colorFieldWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests colorField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldSetDefault(CodeGuy $I)
    {
        $this->colorFieldSetDefault($I, false);
    }

    /**
     * Tests colorField with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldSetDefaultXHTML(CodeGuy $I)
    {
        $this->colorFieldSetDefault($I, true);
    }

    /**
     * Tests colorField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldDisplayTo(CodeGuy $I)
    {
        $this->colorFieldDisplayTo($I, false);
    }

    /**
     * Tests colorField with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldDisplayToXHTML(CodeGuy $I)
    {
        $this->colorFieldDisplayTo($I, true);
    }

    /**
     * Tests colorField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->colorFieldSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests colorField with setDefault to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->colorFieldSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests colorField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->colorFieldDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests colorField with displayTo to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testColorFieldDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->colorFieldDisplayToElementNotPresent($I, true);
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
    private function colorFieldBasic(CodeGuy $I, $xhtml)
    {
        $options  = 'some_field_name';
        $expected = '<input type="color" id="some_field_name" '
                  . 'name="some_field_name" value=""';

        $this->runBasic('colorField', $I, $options, $expected, $xhtml);
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
    private function colorFieldWithArrayBasic(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="color" id="some_field_name" '
                  . 'name="some_field_name" value="" class="some_class"';

        $this->runWithArrayBasic('colorField', $I, $options, $expected, $xhtml);
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
    private function colorFieldWithIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="color" id="some_id" name="some_field_name" '
                  . 'value="" class="some_class" size="10"';

        $this->runWithIdInParameters('colorField', $I, $options, $expected, $xhtml);
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
    private function colorFieldWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="color" id="some_field_name" '
                  . 'name="some_other_name" value="" class="some_class" '
                  . 'size="10"';

        $this->runWithNameAndNotIdInParameters(
            'colorField',
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
    private function colorFieldSetDefault(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="color" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runSetDefault(
            'colorField',
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
    private function colorFieldDisplayTo(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="color" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runDisplayTo(
            'colorField',
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
    private function colorFieldSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="color" id="some_field" '
                  . 'name="some_field" value="" class="some_class" '
                  . 'size="10"';

        $this->runSetDefault(
            'colorField',
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
    private function colorFieldDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="color" id="some_field" '
                  . 'name="some_field" value="" class="some_class" '
                  . 'size="10"';

        $this->runDisplayTo(
            'colorField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }
}
