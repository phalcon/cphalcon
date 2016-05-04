<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagTelFieldTest
 * Tests the \Phalcon\Tag component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Tag
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TagTelFieldTest extends UnitTest
{
    /**
     * Tests telField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTelFieldStringParameter()
    {
        $this->specify(
            "telField with string parameter returns invalid HTML Strict",
            function () {

                $options  = 'x_name';
                $expected = '<input type="tel" id="x_name" name="x_name"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "telField with string parameter returns invalid HTML XHTML",
            function () {

                $options  = 'x_name';
                $expected = '<input type="tel" id="x_name" name="x_name"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests telField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTelFieldArrayParameter()
    {
        $this->specify(
            "telField with array parameter returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="tel" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "telField with array parameter returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="tel" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests telField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTelFieldArrayParameterWithId()
    {
        $this->specify(
            "telField with array parameter with id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="tel" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "telField with array parameter with id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="tel" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests telField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTelFieldArrayParameterWithNameNoId()
    {
        $this->specify(
            "telField with array parameter with name no id returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "telField with array parameter with name no id returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests telField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTelFieldWithSetDefault()
    {
        $this->specify(
            "telField with setDefault returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "telField with setDefault returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests telField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTelFieldWithDisplayTo()
    {
        $this->specify(
            "telField with displayTo returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "telField with displayTo returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests telField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTelFieldWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "telField with setDefault and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "telField with setDefault and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests telField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTelFieldWithDisplayToElementNotPresent()
    {
        $this->specify(
            "telField with displayTo and element not present returns invalid HTML Strict",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "telField with displayTo and element not present returns invalid HTML XHTML",
            function () {

                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="tel" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->tester->testFieldParameter(
                    'telField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
