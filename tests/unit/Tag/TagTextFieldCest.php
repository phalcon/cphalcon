<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Unit\Tag\Helper\TagBase;
use UnitTester;

/**
 * \Phalcon\Test\Unit\Tag\TagTextFieldTest
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
class TagTextFieldTest extends TagBase
{
    /**
     * Tests textField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextFieldStringParameter(UnitTester $I)
    {
        $this->specify(
            "textField with string parameter returns invalid HTML Strict",
            function (UnitTester $I) {
                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" name="x_name"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "textField with string parameter returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options  = 'x_name';
                $expected = '<input type="text" id="x_name" name="x_name"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests textField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextFieldArrayParameter(UnitTester $I)
    {
        $this->specify(
            "textField with array parameter returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="text" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "textField with array parameter returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $expected = '<input type="text" id="x_name" name="x_name" '
                          . 'class="x_class"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests textField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextFieldArrayParameterWithId(UnitTester $I)
    {
        $this->specify(
            "textField with array parameter with id returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="text" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    true
                );
            }
        );

        $this->specify(
            "textField with array parameter with id returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                    'size'  => '10'
                ];
                $expected = '<input type="text" id="x_id" name="x_name" '
                          . 'class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    true
                );
            }
        );
    }

    /**
     * Tests textField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $this->specify(
            "textField with array parameter with name no id returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    false
                );
            }
        );

        $this->specify(
            "textField with array parameter with name no id returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" class="x_class" size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    false
                );
            }
        );
    }

    /**
     * Tests textField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextFieldWithSetDefault(UnitTester $I)
    {
        $this->specify(
            "textField with setDefault returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "textField with setDefault returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests textField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextFieldWithDisplayTo(UnitTester $I)
    {
        $this->specify(
            "textField with displayTo returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "textField with displayTo returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }

    /**
     * Tests textField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "textField with setDefault and element not present returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    false,
                    'setDefault'
                );
            }
        );

        $this->specify(
            "textField with setDefault and element not present returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    true,
                    'setDefault'
                );
            }
        );
    }

    /**
     * Tests textField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "textField with displayTo and element not present returns invalid HTML Strict",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    false,
                    'displayTo'
                );
            }
        );

        $this->specify(
            "textField with displayTo and element not present returns invalid HTML XHTML",
            function (UnitTester $I) {
                $options = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $expected = '<input type="text" id="x_name" '
                          . 'name="x_other" value="x_value" class="x_class" '
                          . 'size="10"';

                $this->testFieldParameter(
            $I,
            'textField',
                    $options,
                    $expected,
                    true,
                    'displayTo'
                );
            }
        );
    }
}
