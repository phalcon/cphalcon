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
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class SelectStaticCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: selectStatic() - string as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticStringParameter(UnitTester $I)
    {
        Tag::resetInput();
        $name     = 'x_name';
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($name, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - array as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameter(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'class' => 'x_class',
        ];
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - array as a parameters and id in it
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithId(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
        ];
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - name and no id in parameter
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithNameNoId(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
        ];
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - value in parameters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticArrayParameterWithValue(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'value' => 'I',
            'class' => 'x_class',
        ];
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - setDefault
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithSetDefault(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        Tag::setDefault('x_name', 'I');
        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - displayTo
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithDisplayTo(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        Tag::displayTo('x_name', 'I');
        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - setDefault and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithSetDefaultElementNotPresent(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        Tag::setDefault('x_name', 'Z');
        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - displayTo and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticWithDisplayToElementNotPresent(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $options  = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';
        Tag::displayTo('x_name', 'Z');
        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - array as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameter(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            "x_name",
            [
                "Active" => [
                    'A1' => 'A One',
                    'A2' => 'A Two',
                ],
                "B"      => "B One",
            ],
        ];
        $expected = '<select id="x_name" name="x_name">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($params);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - array as a parameters and id in it
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithId(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
        ];
        $options  = [
            "Active" => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            "B"      => "B One",
        ];
        $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - name and no id in parameter
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithNameNoId(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
        ];
        $options  = [
            "Active" => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            "B"      => "B One",
        ];
        $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - value in parameters
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupArrayParameterWithValue(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'value' => 'A1',
            'class' => 'x_class',
        ];
        $options  = [
            "Active" => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            "B"      => "B One",
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option selected="selected" value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - setDefault
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithSetDefault(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $options  = [
            "Active" => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            "B"      => "B One",
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        Tag::setDefault('x_name', 'A2');
        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - displayTo
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithDisplayTo(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $options  = [
            "Active" => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            "B"      => "B One",
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        Tag::displayTo('x_name', 'A2');
        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - setDefault and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithSetDefaultElementNotPresent(UnitTester $I)
    {
        Tag::resetInput();
        $params  = [
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
            "B"      => "B One",
        ];

        $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        Tag::setDefault('x_name', 'I');
        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - displayTo and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSelectStaticOptGroupWithDisplayToElementNotPresent(UnitTester $I)
    {
        Tag::resetInput();
        $params   = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $options  = [
            "Active" => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            "B"      => "B One",
        ];
        $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        Tag::displayTo('x_name', 'I');
        $actual = Tag::selectStatic($params, $options);
        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }
}
