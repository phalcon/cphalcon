<?php
/**
 * TagSelectStaticTest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
 *
 * Phalcon Framework
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

use \PhalconTest\Tag as PhTTag;

class TagSelectStaticTest extends Helper\TagBase
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

                PhTTag::resetInput();
                $name    = 'x_name';
                $options = [
                    'A' => 'Active',
                    'I' => 'Inactive',
                ];
                $expected = '<select id="x_name" name="x_name">' . PHP_EOL
                          . chr(9) . '<option value="A">Active</option>' . PHP_EOL
                          . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
                          . '</select>';

                $actual   = PhTTag::selectStatic($name, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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

                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with array as a parameters and id in it
     *
     * @issue  54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithId()
    {
        $this->specify(
            "selectStatic with array parameter with id returns invalid HTML",
            function () {

                PhTTag::resetInput();
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

                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with name and no id in parameter
     *
     * @issue  54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithNameNoId()
    {
        $this->specify(
            "selectStatic with array parameter with name no id returns invalid HTML",
            function () {

                PhTTag::resetInput();
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

                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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

                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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
                PhTTag::setDefault('x_name', 'I');
                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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
                PhTTag::displayTo('x_name', 'I');
                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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
                PhTTag::setDefault('x_name', 'Z');
                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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
                PhTTag::displayTo('x_name', 'Z');
                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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

                $actual   = PhTTag::selectStatic($params);
                PhTTag::resetInput();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with array as a parameters and id in it
     *
     * @issue  54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithId()
    {
        $this->specify(
            "selectStatic with array parameter with id returns invalid HTML",
            function () {

                PhTTag::resetInput();
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

                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests selectStatic with name and no id in parameter
     *
     * @issue  54
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithNameNoId()
    {
        $this->specify(
            "selectStatic with array parameter with name no id returns invalid HTML",
            function () {

                PhTTag::resetInput();
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

                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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

                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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

                PhTTag::setDefault('x_name', 'A2');
                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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

                PhTTag::displayTo('x_name', 'A2');
                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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

                PhTTag::setDefault('x_name', 'I');
                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

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

                PhTTag::resetInput();
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

                PhTTag::displayTo('x_name', 'I');
                $actual   = PhTTag::selectStatic($params, $options);
                PhTTag::resetInput();

                expect($actual)->equals($expected);
            }
        );
    }
}
