<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class SelectStaticCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: selectStatic() - string as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticStringParameter(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - string as a parameter');

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

        $actual = Tag::selectStatic($name, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - array as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticArrayParameter(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - array as a parameter');

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

        $actual = Tag::selectStatic($params, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - array as a parameters and id in it
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticArrayParameterWithId(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - array as a parameters and id');

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

        $actual = Tag::selectStatic($params, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - name and no id in parameter
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticArrayParameterWithNameNoId(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - name and no id in parameter');

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

        $actual = Tag::selectStatic($params, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - value in parameters
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticArrayParameterWithValue(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - value in parameters');

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

        $actual = Tag::selectStatic($params, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - setDefault
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticWithSetDefault(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - setDefault()');

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

        $actual = Tag::selectStatic($params, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - displayTo
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticWithDisplayTo(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - displayTo()');

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

        $actual = Tag::selectStatic($params, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - setDefault and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - setDefault() and element not present');

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

        $actual = Tag::selectStatic($params, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - displayTo and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticWithDisplayToElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - displayTo() and element not present');

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

        $actual = Tag::selectStatic($params, $options);

        Tag::resetInput();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Tag :: selectStatic() - opt group array as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticOptGroupArrayParameter(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - opt group array as a parameter');

        Tag::resetInput();

        $params = [
            'x_name',
            [
                'Active' => [
                    'A1' => 'A One',
                    'A2' => 'A Two',
                ],
                'B'      => 'B One',
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticOptGroupArrayParameterWithId(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - opt group array as a parameters and id');

        Tag::resetInput();

        $params = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
        ];

        $options = [
            'Active' => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            'B'      => 'B One',
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
     * Tests Phalcon\Tag :: selectStatic() - opt group name and no id in
     * parameter
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticOptGroupArrayParameterWithNameNoId(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - name and no id in parameter');

        Tag::resetInput();

        $params = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
        ];

        $options = [
            'Active' => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            'B'      => 'B One',
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticOptGroupArrayParameterWithValue(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - opt group value in parameters');

        Tag::resetInput();

        $params = [
            'x_name',
            'value' => 'A1',
            'class' => 'x_class',
        ];

        $options = [
            'Active' => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            'B'      => 'B One',
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticOptGroupWithSetDefault(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - opt group setDefault()');

        Tag::resetInput();

        $params = [
            'x_name',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $options = [
            'Active' => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            'B'      => 'B One',
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticOptGroupWithDisplayTo(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - opt group displayTo()');

        Tag::resetInput();

        $params = [
            'x_name',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $options = [
            'Active' => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            'B'      => 'B One',
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticOptGroupWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - opt group setDefault() and element not present');

        Tag::resetInput();

        $params = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $options = [
            'Active' => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            'B'      => 'B One',
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagSelectStaticOptGroupWithDisplayToElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Tag - selectStatic() - opt group displayTo() and element not present');

        Tag::resetInput();

        $params = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $options = [
            'Active' => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            'B'      => 'B One',
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
