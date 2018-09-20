<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

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
class TagSelectStaticTest extends UnitTest
{
    /**
     * Tests selectStatic with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticStringParameter()
    {
        $this->specify(
            "selectStatic with string parameter returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameter()
    {
        $this->specify(
            "selectStatic with array parameter returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
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
    public function testSelectStaticArrayParameterWithId()
    {
        $this->specify(
            "selectStatic with array parameter with id returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
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
    public function testSelectStaticArrayParameterWithNameNoId()
    {
        $this->specify(
            "selectStatic with array parameter with name no id returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with value in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithValue()
    {
        $this->specify(
            "selectStatic with array parameter with value returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithSetDefault()
    {
        $this->specify(
            "selectStatic with setDefault returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithDisplayTo()
    {
        $this->specify(
            "selectStatic with setDefault returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "selectStatic with setDefault and element not present returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithDisplayToElementNotPresent()
    {
        $this->specify(
            "selectStatic with displayTo and element not present returns invalid HTML Strict",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameter()
    {
        $this->specify(
            "selectStatic with array parameter returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
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
    public function testSelectStaticOptGroupArrayParameterWithId()
    {
        $this->specify(
            "selectStatic with array parameter with id returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
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
    public function testSelectStaticOptGroupArrayParameterWithNameNoId()
    {
        $this->specify(
            "selectStatic with array parameter with name no id returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with value in parameters
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithValue()
    {
        $this->specify(
            "selectStatic with array parameter with value returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithSetDefault()
    {
        $this->specify(
            "selectStatic with setDefault returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithDisplayTo()
    {
        $this->specify(
            "selectStatic with setDefault returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithSetDefaultElementNotPresent()
    {
        $this->specify(
            "selectStatic with setDefault and element not present returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithDisplayToElementNotPresent()
    {
        $this->specify(
            "selectStatic with displayTo and element not present returns invalid HTML",
            function () {
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

                expect($actual)->equals($expected);
            }
        );
    }
}
