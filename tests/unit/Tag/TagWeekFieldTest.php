<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagWeekFieldTest
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
class TagWeekFieldTest extends UnitTest
{
    /**
     * Tests weekField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testWeekFieldStringParameter()
    {
        $this->specify(
            "weekField with string parameter returns invalid HTML Strict",
            function () {
                $options  = 'x_name';
                $expected = '<input type="week" id="x_name" name="x_name"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "weekField with string parameter returns invalid HTML XHTML",
            function () {
                $options  = 'x_name';
                $expected = '<input type="week" id="x_name" name="x_name"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests weekField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testWeekFieldArrayParameter()
    {
        $this->specify(
            "weekField with array parameter returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="week" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "weekField with array parameter returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="week" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests weekField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testWeekFieldArrayParameterWithId()
    {
        $this->specify(
            "weekField with array parameter with id returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="week" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "weekField with array parameter with id returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="week" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests weekField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testWeekFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "weekField with array parameter with name no id returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "weekField with array parameter with name no id returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests weekField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testWeekFieldWithSetDefault()
    {
        $this->specify(
            "weekField with setDefault returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "weekField with setDefault returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests weekField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testWeekFieldWithDisplayTo()
    {
        $this->specify(
            "weekField with displayTo returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "weekField with displayTo returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests weekField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testWeekFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "weekField with setDefault and element not present returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "weekField with setDefault and element not present returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests weekField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testWeekFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "weekField with displayTo and element not present returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "weekField with displayTo and element not present returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="week" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'weekField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
