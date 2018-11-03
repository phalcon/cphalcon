<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagCheckFieldTest
 * Tests the \Phalcon\Tag component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Tag
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TagCheckFieldTest extends UnitTest
{
    /**
     * Tests checkField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldStringParameter()
    {
        $this->specify(
            "checkField with string parameter returns invalid HTML Strict",
            function () {
                $options  = 'x_name';
                $expected = '<input type="checkbox" id="x_name" name="x_name"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false
                );
            }
        );
        $this->specify(
            "checkField with string parameter returns invalid HTML XHTML",
            function () {
                $options  = 'x_name';
                $expected = '<input type="checkbox" id="x_name" name="x_name"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }
    /**
     * Tests checkField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameter()
    {
        $this->specify(
            "checkField with array parameter returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_name" '
                    . 'class="x_class"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false
                );
            }
        );
        $this->specify(
            "checkField with array parameter returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_name" '
                    . 'class="x_class"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }
    /**
     * Tests checkField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameterWithId()
    {
        $this->specify(
            "checkField with array parameter with id returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="checkbox" id="x_id" name="x_name" '
                    . 'class="x_class" size="10"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true
                );
            }
        );
        $this->specify(
            "checkField with array parameter with id returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="checkbox" id="x_id" name="x_name" '
                    . 'class="x_class" size="10"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }
    /**
     * Tests checkField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "checkField with array parameter with name no id returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                    . 'class="x_class" size="10"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false
                );
            }
        );
        $this->specify(
            "checkField with array parameter with name no id returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                    . 'class="x_class" size="10"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }
    /**
     * Tests checkField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithSetDefault()
    {
        $this->specify(
            "checkField with setDefault returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" '
                    . 'name="x_other" value="x_value" class="x_class" '
                    . 'size="10" checked="checked"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );
        $this->specify(
            "checkField with setDefault returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" '
                    . 'name="x_other" value="x_value" class="x_class" '
                    . 'size="10" checked="checked"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }
    /**
     * Tests checkField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithDisplayTo()
    {
        $this->specify(
            "checkField with displayTo returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" '
                    . 'name="x_other" value="x_value" class="x_class" '
                    . 'size="10" checked="checked"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );
        $this->specify(
            "checkField with displayTo returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" '
                    . 'name="x_other" value="x_value" class="x_class" '
                    . 'size="10" checked="checked"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
    /**
     * Tests checkField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "checkField with setDefault and element not present returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                    . 'value="x_value" class="x_class" size="10" '
                    . 'checked="checked"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );
        $this->specify(
            "checkField with setDefault and element not present returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                    . 'value="x_value" class="x_class" size="10" '
                    . 'checked="checked"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }
    /**
     * Tests checkField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "checkField with displayTo and element not present returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                    . 'value="x_value" class="x_class" size="10" '
                    . 'checked="checked"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );
        $this->specify(
            "checkField with displayTo and element not present returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="checkbox" id="x_name" name="x_other" '
                    . 'value="x_value" class="x_class" size="10" '
                    . 'checked="checked"';
                $this->tester->testFieldParameter(
                    'checkField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests checkField with setDefault and with a value of zero
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12316
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-12-19
     */
    public function shouldGenerateCheckFieldAsCheckedWhenValueIsZeroAndDefaultIsZero()
    {
        $this->specify(
            'The checkbox cannot have value 0 and be checked',
            function ($value, $default, $expected) {
                Tag::resetInput();
                Tag::setDocType(Tag::HTML5);
                Tag::setDefault("demo-0", $default);

                expect(Tag::checkField(['demo-0', 'value' => $value]))->equals($expected);
            },
            ['examples' => $this->nullableValueProvider()]
        );
    }

    protected function nullableValueProvider()
    {
        return [
            [ 0,  "0", '<input type="checkbox" id="demo-0" name="demo-0" value="0" checked="checked">'],
            [ 0,   0,  '<input type="checkbox" id="demo-0" name="demo-0" value="0" checked="checked">'],
            ["0",  0,  '<input type="checkbox" id="demo-0" name="demo-0" value="0" checked="checked">'],
            ["0", "0", '<input type="checkbox" id="demo-0" name="demo-0" value="0" checked="checked">'],
        ];
    }
}
