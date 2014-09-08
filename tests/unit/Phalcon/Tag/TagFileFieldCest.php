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

class TagFileFieldCest extends TagBase
{
    /**
     * Tests fileField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldBasic(CodeGuy $I)
    {
        $this->fileFieldBasic($I, false);
    }

    /**
     * Tests fileField with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldBasicXHTML(CodeGuy $I)
    {
        $this->fileFieldBasic($I, true);
    }

    /**
     * Tests fileField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithArrayBasic(CodeGuy $I)
    {
        $this->fileFieldWithArrayBasic($I, false);
    }

    /**
     * Tests fileField with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->fileFieldWithArrayBasic($I, true);
    }

    /**
     * Tests fileField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithIdInParameters(CodeGuy $I)
    {
        $this->fileFieldWithIdInParameters($I, false);
    }

    /**
     * Tests fileField with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->fileFieldWithIdInParameters($I, true);
    }

    /**
     * Tests fileField with name and no id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->fileFieldWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests fileField with name and no id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->fileFieldWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests fileField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldSetDefault(CodeGuy $I)
    {
        $this->fileFieldSetDefault($I, false);
    }

    /**
     * Tests fileField with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldSetDefaultXHTML(CodeGuy $I)
    {
        $this->fileFieldSetDefault($I, true);
    }

    /**
     * Tests fileField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldDisplayTo(CodeGuy $I)
    {
        $this->fileFieldDisplayTo($I, false);
    }

    /**
     * Tests fileField with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldDisplayToXHTML(CodeGuy $I)
    {
        $this->fileFieldDisplayTo($I, true);
    }

    /**
     * Tests fileField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->fileFieldSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests fileField with setDefault to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->fileFieldSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests fileField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->fileFieldDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests fileField with displayTo to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testFileFieldDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->fileFieldDisplayToElementNotPresent($I, true);
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
    private function fileFieldBasic(CodeGuy $I, $xhtml)
    {
        $options  = 'some_field_name';
        $expected = '<input type="file" id="some_field_name" '
                  . 'name="some_field_name"';

        $this->runBasic('fileField', $I, $options, $expected, $xhtml);
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
    private function fileFieldWithArrayBasic(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="file" id="some_field_name" '
                  . 'name="some_field_name" class="some_class"';

        $this->runWithArrayBasic('fileField', $I, $options, $expected, $xhtml);
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
    private function fileFieldWithIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_id" name="some_field_name" '
                  . 'class="some_class" size="10"';

        $this->runWithIdInParameters('fileField', $I, $options, $expected, $xhtml);
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
    private function fileFieldWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_field_name" '
                  . 'name="some_other_name" class="some_class" size="10"';

        $this->runWithNameAndNotIdInParameters(
            'fileField',
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
    private function fileFieldSetDefault(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runSetDefault(
            'fileField',
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
    private function fileFieldDisplayTo(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"';

        $this->runDisplayTo(
            'fileField',
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
    private function fileFieldSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_field" '
                  . 'name="some_field" class="some_class" '
                  . 'size="10"';

        $this->runSetDefault(
            'fileField',
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
    private function fileFieldDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="file" id="some_field" '
                  . 'name="some_field" class="some_class" '
                  . 'size="10"';

        $this->runDisplayTo(
            'fileField',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }
}
