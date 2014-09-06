<?php
/**
 * TagCheckFieldCest.php
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
use \Phalcon\DI\FactoryDefault as PhDI;
use \Phalcon\Tag as PhTag;

class TagCheckFieldCest
{
    private $message = "%s does not return proper html element";

    public function _before()
    {
        $di = new PhDI();
        PhDI::reset();
        PhTag::setDI($di);
    }

    /**
     * Tests checkField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldBasic(CodeGuy $I)
    {
        $this->checkFieldBasic($I, false);
    }

    /**
     * Tests checkField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldWithArrayBasic(CodeGuy $I)
    {
        $this->checkFieldWithArrayBasic($I, false);
    }

    /**
     * Tests checkField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldWithIdInParameters(CodeGuy $I)
    {
        $this->checkFieldWithIdInParameters($I, false);
    }

    /**
     * Tests checkField with name and not id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->checkFieldWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests checkField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldSetDefault(CodeGuy $I)
    {
        $this->checkFieldSetDefault($I, false);
    }

    /**
     * Tests checkField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldDisplayTo(CodeGuy $I)
    {
        $this->checkFieldDisplayTo($I, false);
    }

    /**
     * Tests checkField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->checkFieldSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests checkField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->checkFieldDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests checkField with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldBasicXHTML(CodeGuy $I)
    {
        $this->checkFieldBasic($I, true);
    }

    /**
     * Tests checkField with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->checkFieldWithArrayBasic($I, true);
    }

    /**
     * Tests checkField with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->checkFieldWithIdInParameters($I, true);
    }

    /**
     * Tests checkField with name and not id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->checkFieldWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests checkField with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldSetDefaultXHTML(CodeGuy $I)
    {
        $this->checkFieldSetDefault($I, true);
    }

    /**
     * Tests checkField with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldDisplayToXHTML(CodeGuy $I)
    {
        $this->checkFieldDisplayTo($I, true);
    }

    /**
     * Tests checkField with setDefault and element not present XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->checkFieldSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests checkField with displayTo and element not present XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testCheckFieldDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->checkFieldDisplayToElementNotPresent($I, true);
    }

    /**
     * Private functions
     */
    /**
     * Runs the test with string as a parameter for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function checkFieldBasic(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDoctype('');
        }

        $options  = 'some_field_name';
        $suffix   = ($xhtml) ? ' />'    : ">";
        $message  = ($xhtml) ? ' XHTML' : '';
        $expected = '<input type="checkbox" id="some_field_name" '
                  . 'name="some_field_name"'
                  . (($xhtml) ? ' value=""' : '')
                  . $suffix;
        $actual   = PhTag::checkField($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField basic' . $message)
        );
    }

    /**
     * Runs the test with array as a parameter for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function checkFieldWithArrayBasic(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDoctype('');
        }

        $suffix   = ($xhtml) ? ' />'    : ">";
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="checkbox" id="some_field_name" '
                  . 'name="some_field_name" '
                  . (($xhtml) ? 'value="" ' : '')
                  . 'class="some_class"'
                  . $suffix;
        $actual   = PhTag::checkField($options);
        if ($xhtml) {
            PhTag::setDoctype('');
        }

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField basic with array' . $message)
        );
    }

    /**
     * Runs the test with id in parameters for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function checkFieldWithIdInParameters(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDoctype('');
        }

        $suffix   = ($xhtml) ? " />"    : ">";
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="checkbox" id="some_id" '
                  . 'name="some_field_name" '
                  . (($xhtml) ? 'value="" ' : '')
                  . 'class="some_class" size="10"'
                  . $suffix;
        $actual   = PhTag::checkField($options);
        if ($xhtml) {
            PhTag::setDoctype('');
        }

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField with id in parameters' . $message)
        );
    }

    /**
     * Runs the test with name and not id in parameters XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function checkFieldWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDoctype('');
        }

        $suffix   = ($xhtml) ? " />"    : ">";
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="checkbox" id="some_field_name" '
                  . 'name="some_other_name" '
                  . (($xhtml) ? 'value="" ' : '')
                  . 'class="some_class" size="10"'
                  . $suffix;
        $actual   = PhTag::checkField($options);
        if ($xhtml) {
            PhTag::setDoctype('');
        }

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'checkField with name and id in parameters' . $message
            )
        );
    }

    /**
     * Runs the test with setDefault for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function checkFieldSetDefault(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDoctype('');
        }

        $suffix   = ($xhtml) ? " />"    : ">";
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="checkbox" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10" checked="checked"'
                  . $suffix;
        $actual   = PhTag::checkField($options);
        PhTag::setDefault('some_field_name', '');
        if ($xhtml) {
            PhTag::setDoctype('');
        }

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField with setDefault' . $message)
        );
    }

    /**
     * Runs the test with displayTo for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function checkFieldDisplayTo(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDoctype('');
        }

        $suffix   = ($xhtml) ? " />"    : ">";
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="checkbox" id="some_field_name" '
            . 'name="some_field_name" value="some_default_value" '
            . 'class="some_class" size="10" checked="checked"'
            . $suffix;
        $actual   = PhTag::checkField($options);
        PhTag::displayTo('some_field_name', '');
        if ($xhtml) {
            PhTag::setDoctype('');
        }

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'checkField with displayTo' . $message)
        );
    }

    /**
     * Runs the test with setDefault and element not present for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function checkFieldSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDoctype('');
        }

        $suffix   = ($xhtml) ? " />"    : ">";
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="checkbox" id="some_field_name" '
            . 'name="some_field_name" value="" class="some_class" '
            . 'size="10"'
            . $suffix;
        $actual   = PhTag::checkField($options);
        PhTag::setDefault('some_field', '');
        if ($xhtml) {
            PhTag::setDoctype('');
        }

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'checkField with setDefault and element not present' . $message
            )
        );
    }

    /**
     * Runs the test with displayTo and element not present for XHTML or not
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     * @param Boolean $xhtml
     */
    private function checkFieldDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDoctype(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDoctype('');
        }

        $suffix   = ($xhtml) ? " />"    : ">";
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="checkbox" id="some_field_name" '
            . 'name="some_field_name" value="" class="some_class" '
            . 'size="10"'
            . $suffix;
        $actual   = PhTag::checkField($options);
        PhTag::displayTo('some_field', '');
        if ($xhtml) {
            PhTag::setDoctype('');
        }

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'checkField with displayTo and element not present' . $message
            )
        );
    }
}
