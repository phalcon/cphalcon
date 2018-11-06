<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagMonthFieldTest
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
class TagMonthFieldTest extends UnitTest
{
    /**
     * Tests monthField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testMonthFieldStringParameter()
    {
        $this->specify(
            "monthField with string parameter returns invalid HTML Strict",
            function () {
                $options  = 'x_name';
                $expected = '<input type="month" id="x_name" name="x_name"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "monthField with string parameter returns invalid HTML XHTML",
            function () {
                $options  = 'x_name';
                $expected = '<input type="month" id="x_name" name="x_name"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests monthField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testMonthFieldArrayParameter()
    {
        $this->specify(
            "monthField with array parameter returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="month" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "monthField with array parameter returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="month" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests monthField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testMonthFieldArrayParameterWithId()
    {
        $this->specify(
            "monthField with array parameter with id returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="month" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "monthField with array parameter with id returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="month" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests monthField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testMonthFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "monthField with array parameter with name no id returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "monthField with array parameter with name no id returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests monthField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testMonthFieldWithSetDefault()
    {
        $this->specify(
            "monthField with setDefault returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "monthField with setDefault returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests monthField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testMonthFieldWithDisplayTo()
    {
        $this->specify(
            "monthField with displayTo returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "monthField with displayTo returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests monthField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testMonthFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "monthField with setDefault and element not present returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "monthField with setDefault and element not present returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests monthField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testMonthFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "monthField with displayTo and element not present returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "monthField with displayTo and element not present returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="month" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'monthField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
