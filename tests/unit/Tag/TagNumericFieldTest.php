<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagNumericFieldTest
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
class TagNumericFieldTest extends UnitTest
{
    /**
     * Tests numericField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNumericFieldStringParameter()
    {
        $this->specify(
            "numericField with string parameter returns invalid HTML Strict",
            function () {
                $options  = 'x_name';
                $expected = '<input type="number" id="x_name" name="x_name"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "numericField with string parameter returns invalid HTML XHTML",
            function () {
                $options  = 'x_name';
                $expected = '<input type="number" id="x_name" name="x_name"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests numericField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNumericFieldArrayParameter()
    {
        $this->specify(
            "numericField with array parameter returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="number" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "numericField with array parameter returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="number" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests numericField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNumericFieldArrayParameterWithId()
    {
        $this->specify(
            "numericField with array parameter with id returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="number" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "numericField with array parameter with id returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="number" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests numericField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNumericFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "numericField with array parameter with name no id returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "numericField with array parameter with name no id returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests numericField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNumericFieldWithSetDefault()
    {
        $this->specify(
            "numericField with setDefault returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "numericField with setDefault returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests numericField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNumericFieldWithDisplayTo()
    {
        $this->specify(
            "numericField with displayTo returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "numericField with displayTo returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests numericField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNumericFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "numericField with setDefault and element not present returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "numericField with setDefault and element not present returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests numericField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testNumericFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "numericField with displayTo and element not present returns invalid HTML Strict",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "numericField with displayTo and element not present returns invalid HTML XHTML",
            function () {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="number" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'numericField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
