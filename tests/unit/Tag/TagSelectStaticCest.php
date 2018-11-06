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

use Phalcon\Tag;
use Phalcon\Test\Unit\Tag\Helper\TagBase;
use UnitTester;

/**
 * \Phalcon\Test\Unit\Tag\TagSelectStaticTest
 * Tests the \Phalcon\Tag component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
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
class TagSelectStaticTest extends TagBase
{
    /**
     * Tests selectStatic with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticStringParameter(UnitTester $I)
    {
        $this->specify(
            "selectStatic with string parameter returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $name    = 'x_name';
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_name" name="x_name">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($name, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameter(UnitTester $I)
    {
        $this->specify(
            "selectStatic with array parameter returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'class' => 'x_class',
                ];
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_name" name="x_name" class="x_class">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with array as a parameters and id in it
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithId(UnitTester $I)
    {
        $this->specify(
            "selectStatic with array parameter with id returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                ];
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with name and no id in parameter
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithNameNoId(UnitTester $I)
    {
        $this->specify(
            "selectStatic with array parameter with name no id returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                ];
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with value in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithValue(UnitTester $I)
    {
        $this->specify(
            "selectStatic with array parameter with value returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'value' => 'I',
                    'class' => 'x_class',
                ];
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_name" name="x_name" class="x_class">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithSetDefault(UnitTester $I)
    {
        $this->specify(
            "selectStatic with setDefault returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
                          . '</select>';
                Tag::setDefault('x_name', 'I');
                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithDisplayTo(UnitTester $I)
    {
        $this->specify(
            "selectStatic with setDefault returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
                          . '</select>';
                Tag::displayTo('x_name', 'I');
                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "selectStatic with setDefault and element not present returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                          . '</select>';
                Tag::setDefault('x_name', 'Z');
                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithDisplayToElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "selectStatic with displayTo and element not present returns invalid HTML Strict",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                          . '</select>';
                Tag::displayTo('x_name', 'Z');
                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameter(UnitTester $I)
    {
        $this->specify(
            "selectStatic with array parameter returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    "x_name",
                    [
                        "Active" => [
                            'A1' => 'A One',
                            'A2' => 'A Two',
                        ],
                        "B" => "B One"
                    ]
                ];
                $expected = '<select id="x_name" name="x_name">' . PHP_EOL
                          . chr(9) . '<optgroup label="Active">' . PHP_EOL
                          . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
                          . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
                          . chr(9) . '</optgroup>' . PHP_EOL
                          . chr(9) . '<option value="B">B One</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($params);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with array as a parameters and id in it
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithId(UnitTester $I)
    {
        $this->specify(
            "selectStatic with array parameter with id returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                ];
                $options = [
                    "Active" => [
                        'A1' => 'A One',
                        'A2' => 'A Two',
                    ],
                    "B" => "B One"
                ];
                $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
                          . chr(9) . '<optgroup label="Active">' . PHP_EOL
                          . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
                          . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
                          . chr(9) . '</optgroup>' . PHP_EOL
                          . chr(9) . '<option value="B">B One</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with name and no id in parameter
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithNameNoId(UnitTester $I)
    {
        $this->specify(
            "selectStatic with array parameter with name no id returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'id'    => 'x_id',
                    'class' => 'x_class',
                ];
                $options = [
                    "Active" => [
                        'A1' => 'A One',
                        'A2' => 'A Two',
                    ],
                    "B" => "B One"
                ];
                $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
                          . chr(9) . '<optgroup label="Active">' . PHP_EOL
                          . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
                          . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
                          . chr(9) . '</optgroup>' . PHP_EOL
                          . chr(9) . '<option value="B">B One</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with value in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithValue(UnitTester $I)
    {
        $this->specify(
            "selectStatic with array parameter with value returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'value' => 'A1',
                    'class' => 'x_class',
                ];
                $options = [
                    "Active" => [
                        'A1' => 'A One',
                        'A2' => 'A Two',
                    ],
                    "B" => "B One"
                ];
                $expected = '<select id="x_name" name="x_name" class="x_class">' . PHP_EOL
                          . chr(9) . '<optgroup label="Active">' . PHP_EOL
                          . chr(9) . '<option selected="selected" value="A1">A One</option>' . PHP_EOL
                          . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
                          . chr(9) . '</optgroup>' . PHP_EOL
                          . chr(9) . '<option value="B">B One</option>' . PHP_EOL
                          . '</select>';

                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithSetDefault(UnitTester $I)
    {
        $this->specify(
            "selectStatic with setDefault returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $options = [
                    "Active" => [
                        'A1' => 'A One',
                        'A2' => 'A Two',
                    ],
                    "B" => "B One"
                ];
                $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
                          . chr(9) . '<optgroup label="Active">' . PHP_EOL
                          . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
                          . chr(9) . '<option selected="selected" value="A2">A Two</option>' . PHP_EOL
                          . chr(9) . '</optgroup>' . PHP_EOL
                          . chr(9) . '<option value="B">B One</option>' . PHP_EOL
                          . '</select>';

                Tag::setDefault('x_name', 'A2');
                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithDisplayTo(UnitTester $I)
    {
        $this->specify(
            "selectStatic with setDefault returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $options = [
                    "Active" => [
                        'A1' => 'A One',
                        'A2' => 'A Two',
                    ],
                    "B" => "B One"
                ];
                $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
                          . chr(9) . '<optgroup label="Active">' . PHP_EOL
                          . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
                          . chr(9) . '<option selected="selected" value="A2">A Two</option>' . PHP_EOL
                          . chr(9) . '</optgroup>' . PHP_EOL
                          . chr(9) . '<option value="B">B One</option>' . PHP_EOL
                          . '</select>';

                Tag::displayTo('x_name', 'A2');
                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "selectStatic with setDefault and element not present returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $options = [
                    "Active" => [
                        'A1' => 'A One',
                        'A2' => 'A Two',
                    ],
                    "B" => "B One"
                ];

                $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
                          . chr(9) . '<optgroup label="Active">' . PHP_EOL
                          . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
                          . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
                          . chr(9) . '</optgroup>' . PHP_EOL
                          . chr(9) . '<option value="B">B One</option>' . PHP_EOL
                          . '</select>';

                Tag::setDefault('x_name', 'I');
                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }

    /**
     * Tests selectStatic with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithDisplayToElementNotPresent(UnitTester $I)
    {
        $this->specify(
            "selectStatic with displayTo and element not present returns invalid HTML",
            function (UnitTester $I) {
                Tag::resetInput();
                $params = [
                    'x_name',
                    'name'  => 'x_other',
                    'class' => 'x_class',
                    'size'  => '10',
                ];
                $options = [
                    "Active" => [
                        'A1' => 'A One',
                        'A2' => 'A Two',
                    ],
                    "B" => "B One"
                ];
                $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
                          . chr(9) . '<optgroup label="Active">' . PHP_EOL
                          . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
                          . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
                          . chr(9) . '</optgroup>' . PHP_EOL
                          . chr(9) . '<option value="B">B One</option>' . PHP_EOL
                          . '</select>';

                Tag::displayTo('x_name', 'I');
                $actual   = Tag::selectStatic($params, $options);
                Tag::resetInput();

                $I->assertEquals($expected, $actual);
            }
        );
    }
}
