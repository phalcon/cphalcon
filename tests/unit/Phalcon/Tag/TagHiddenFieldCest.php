<?php
/**
 * TagHiddenFieldCest.php
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

class TagHiddenFieldCest extends TagBase
{
    /**
     * Tests hiddenField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldBasic(CodeGuy $I)
    {
        $this->hiddenFieldBasic($I, false);
    }

    /**
     * Tests hiddenField with string as a parameter XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldBasicXHTML(CodeGuy $I)
    {
        $this->hiddenFieldBasic($I, true);
    }

    /**
     * Tests hiddenField with array as parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldWithArrayBasic(CodeGuy $I)
    {
        $this->hiddenFieldWithArrayBasic($I, false);
    }

    /**
     * Tests hiddenField with array as parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldWithArrayBasicXHTML(CodeGuy $I)
    {
        $this->hiddenFieldWithArrayBasic($I, true);
    }

    /**
     * Tests hiddenField with id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldWithIdInParameters(CodeGuy $I)
    {
        $this->hiddenFieldWithIdInParameters($I, false);
    }

    /**
     * Tests hiddenField with id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldWithIdInParametersXHTML(CodeGuy $I)
    {
        $this->hiddenFieldWithIdInParameters($I, true);
    }

    /**
     * Tests hiddenField with name and no id in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldWithNameAndNotIdInParameters(CodeGuy $I)
    {
        $this->hiddenFieldWithNameAndNotIdInParameters($I, false);
    }

    /**
     * Tests hiddenField with name and no id in parameters XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldWithNameAndNotIdInParametersXHTML(CodeGuy $I)
    {
        $this->hiddenFieldWithNameAndNotIdInParameters($I, true);
    }

    /**
     * Tests hiddenField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldSetDefault(CodeGuy $I)
    {
        $this->hiddenFieldSetDefault($I, false);
    }

    /**
     * Tests hiddenField with setDefault XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldSetDefaultXHTML(CodeGuy $I)
    {
        $this->hiddenFieldSetDefault($I, true);
    }

    /**
     * Tests hiddenField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldDisplayTo(CodeGuy $I)
    {
        $this->hiddenFieldDisplayTo($I, false);
    }

    /**
     * Tests hiddenField with displayTo XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldDisplayToXHTML(CodeGuy $I)
    {
        $this->hiddenFieldDisplayTo($I, true);
    }

    /**
     * Tests hiddenField with setDefault to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldSetDefaultElementNotPresent(CodeGuy $I)
    {
        $this->hiddenFieldSetDefaultElementNotPresent($I, false);
    }

    /**
     * Tests hiddenField with setDefault to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldSetDefaultElementNotPresentXHTML(CodeGuy $I)
    {
        $this->hiddenFieldSetDefaultElementNotPresent($I, true);
    }

    /**
     * Tests hiddenField with displayTo to an non existent element
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldDisplayToElementNotPresent(CodeGuy $I)
    {
        $this->hiddenFieldDisplayToElementNotPresent($I, false);
    }

    /**
     * Tests hiddenField with displayTo to an non existent element XHTML
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     *
     * @param CodeGuy $I
     */
    public function testHiddenFieldDisplayToElementNotPresentXHTML(CodeGuy $I)
    {
        $this->hiddenFieldDisplayToElementNotPresent($I, true);
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
    private function hiddenFieldBasic(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $suffix   = ($xhtml) ? ' />'    : '>';
        $message  = ($xhtml) ? ' XHTML' : '';

        $options  = 'some_field_name';
        $expected = '<input type="hidden" id="some_field_name" '
                  . 'name="some_field_name"'
                  . $suffix;
        $actual   = PhTag::hiddenField($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField basic' . $message)
        );
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
    private function hiddenFieldWithArrayBasic(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $suffix  = ($xhtml) ? ' />'    : '>';
        $message = ($xhtml) ? ' XHTML' : '';
        $options = array(
            'some_field_name',
            'class' => 'some_class',
        );
        $expected = '<input type="hidden" id="some_field_name" '
                  . 'name="some_field_name" class="some_class"'
                  . $suffix;
        $actual   = PhTag::hiddenField($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField basic with array' . $message)
        );
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
    private function hiddenFieldWithIdInParameters(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $suffix   = ($xhtml) ? ' />'    : '>';
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'id'    => 'some_id',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="hidden" id="some_id" name="some_field_name" '
                  . 'class="some_class" size="10"'
                  . $suffix;
        $actual   = PhTag::hiddenField($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with id in parameters' . $message)
        );
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
    private function hiddenFieldWithNameAndNotIdInParameters(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $suffix   = ($xhtml) ? ' />'    : '>';
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'name'  => 'some_other_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        $expected = '<input type="hidden" id="some_field_name" '
                  . 'name="some_other_name" class="some_class" size="10"'
                  . $suffix;
        $actual   = PhTag::hiddenField($options);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf(
                $this->message,
                'hiddenField with name and id in parameters' . $message
            )
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
    private function hiddenFieldSetDefault(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $suffix   = ($xhtml) ? ' />'    : '>';
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field_name', 'some_default_value');
        $expected = '<input type="hidden" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"'
                  . $suffix;
        $actual   = PhTag::hiddenField($options);
        PhTag::setDefault('some_field_name', '');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with setDefault' . $message)
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
    private function hiddenFieldDisplayTo(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $suffix   = ($xhtml) ? ' />'    : '>';
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field_name', 'some_default_value');
        $expected = '<input type="hidden" id="some_field_name" '
                  . 'name="some_field_name" value="some_default_value" '
                  . 'class="some_class" size="10"'
                  . $suffix;
        $actual   = PhTag::hiddenField($options);
        PhTag::displayTo('some_field_name', '');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with displayTo' . $message)
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
    private function hiddenFieldSetDefaultElementNotPresent(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $suffix   = ($xhtml) ? ' />'    : '>';
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::setDefault('some_field', 'some_default_value');
        $expected = '<input type="hidden" id="some_field_name" '
                  . 'name="some_field_name" value="" class="some_class" '
                  . 'size="10"'
                  . $suffix;
        $actual   = PhTag::hiddenField($options);
        PhTag::setDefault('some_field', '');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with setDefault' . $message)
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
    private function hiddenFieldDisplayToElementNotPresent(CodeGuy $I, $xhtml)
    {
        if ($xhtml) {
            PhTag::setDocType(PhTag::XHTML10_STRICT);
        } else {
            PhTag::setDocType('');
        }

        $suffix   = ($xhtml) ? ' />'    : '>';
        $message  = ($xhtml) ? ' XHTML' : '';

        $options = array(
            'some_field_name',
            'class' => 'some_class',
            'size'  => '10',
        );
        PhTag::displayTo('some_field', 'some_default_value');
        $expected = '<input type="hidden" id="some_field_name" '
                  . 'name="some_field_name" value="" class="some_class" '
                  . 'size="10"'
                  . $suffix;
        $actual   = PhTag::hiddenField($options);
        PhTag::displayTo('some_field', '');

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'hiddenField with displayTo' . $message)
        );
    }
}
