<?php
/**
 * TagSubmitButtonCest.php
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

class TagSubmitButtonCest extends TagBase
{
    /**
     * Tests submitButton with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonBasic(CodeGuy $I)
    {
        $this->submitButtonBasic($I, false);
    }

    /**
     * Tests submitButton with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonBasicXHTML(CodeGuy $I)
    {
        $this->submitButtonBasic($I, true);
    }

    /**
     * Tests submitButton with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonWithArrayBasic(CodeGuy $I)
    {
        $this->submitButtonWithArrayBasic($I, false);
    }

    /**
     * Tests submitButton with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->submitButtonWithArrayBasic($I, true);
    }

    /**
     * Tests submitButton with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonWithIdInParameters(CodeGuy $I)
    {
        $this->submitButtonWithIdInParameters($I, false);
    }

    /**
     * Tests submitButton with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->submitButtonWithIdInParameters($I, true);
    }

    /**
     * Tests submitButton with name and no id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->submitButtonWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests submitButton with name and no id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->submitButtonWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests submitButton with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonSetDefault(CodeGuy $I)
    {
        $this->submitButtonSetDefault($I, false);
    }

    /**
     * Tests submitButton with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonSetDefaultXHTML(CodeGuy $I)
    {
        $this->submitButtonSetDefault($I, true);
    }

    /**
     * Tests submitButton with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonDisplayTo(CodeGuy $I)
    {
        $this->submitButtonDisplayTo($I, false);
    }

    /**
     * Tests submitButton with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonDisplayToXHTML(CodeGuy $I)
    {
        $this->submitButtonDisplayTo($I, true);
    }

    /**
     * Tests submitButton with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->submitButtonSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests submitButton with setDefault to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->submitButtonSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests submitButton with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->submitButtonDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests submitButton with displayTo to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testSubmitButtonDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->submitButtonDisplayToElementNotPresent($I, true);
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
    private function submitButtonBasic(CodeGuy $I, $xhtml)
    {
        $options  = 'some_field_name';
        $expected = '<input type="submit" value="some_field_name"';

        $this->runBasic('submitButton', $I, $options, $expected, $xhtml);
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
    private function submitButtonWithArrayBasic(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="submit" value="some_field_name" '
                  . 'class="some_class"';

        $this->runWithArrayBasic('submitButton', $I, $options, $expected, $xhtml);
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
    private function submitButtonWithIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" id="some_id" '
                  . 'value="some_field_name" class="some_class" size="10"';

        $this->runWithIdInParameters('submitButton', $I, $options, $expected, $xhtml);
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
    private function submitButtonWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" name="some_other_name" '
                  . 'value="some_field_name" class="some_class" '
                  . 'size="10"';

        $this->runWithNameAndNotIdInParameters(
            'submitButton',
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
    private function submitButtonSetDefault(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" value="some_field_name" '
                  . 'class="some_class" size="10"';

        $this->runSetDefault(
            'submitButton',
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
    private function submitButtonDisplayTo(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" value="some_field_name" '
                  . 'class="some_class" size="10"';

        $this->runDisplayTo(
            'submitButton',
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
    private function submitButtonSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" value="some_field" '
                  . 'class="some_class" size="10"';

        $this->runSetDefault(
            'submitButton',
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
    private function submitButtonDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        $options = array(
            'some_field',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="submit" value="some_field" '
                  . 'class="some_class" size="10"';

        $this->runDisplayTo(
            'submitButton',
            $I,
            $options,
            $expected,
            $xhtml
        );
    }
}
