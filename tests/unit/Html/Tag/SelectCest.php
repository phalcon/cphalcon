<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\TagSetupTrait;
use UnitTester;

/**
 * Class SelectCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class SelectCest
{
    use DiTrait;
    use TagSetupTrait;

    /**
     * Tests Phalcon\Html\Tag :: select()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelect(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select()');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $data     = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_name">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = $tag->select($name, [], $data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - id
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectWithId(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - id');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'id'    => 'x_id',
            'class' => 'x_class',
        ];
        $data     = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_id" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = $tag->select($name, $params, $data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectWithName(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - name');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'name'  => 'x_other',
            'class' => 'x_class',
        ];
        $data     = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_other" class="x_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = $tag->select($name, $params, $data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - value
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectWithValue(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - value');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'value' => 'I',
            'class' => 'x_class',
        ];
        $data     = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = $tag->select($name, $params, $data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - setAttribute()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectSetAttribute(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - setAttribute()');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'class' => 'x_class',
            'size'  => '10',
        ];
        $data     = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option selected="selected" value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = $tag
            ->setAttribute('x_name', 'I')
            ->select($name, $params, $data)
        ;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - setAttribute() element not present
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectSetAttributeElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - setAttribute() element not present');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $data     = [
            'A' => 'Active',
            'I' => 'Inactive',
        ];
        $expected = '<select id="x_name" name="x_other" class="x_class" size="10">' . PHP_EOL
            . chr(9) . '<option value="A">Active</option>' . PHP_EOL
            . chr(9) . '<option value="I">Inactive</option>' . PHP_EOL
            . '</select>';

        $actual = $tag
            ->setAttribute('x_name', 'Z')
            ->select($name, $params, $data)
        ;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - optgroup array with id
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectOptGroupWithId(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - optgroup array with id');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'id'    => 'x_id',
            'class' => 'x_class',
        ];
        $data     = [
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

        $actual = $tag->select($name, $params, $data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - optgroup array without id
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/54
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectOptGroupWithoutId(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - optgroup array without id');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'class' => 'x_class',
        ];
        $data     = [
            "Active" => [
                'A1' => 'A One',
                'A2' => 'A Two',
            ],
            "B"      => "B One",
        ];
        $expected = '<select id="x_name" name="x_name" class="x_class">' . PHP_EOL
            . chr(9) . '<optgroup label="Active">' . PHP_EOL
            . chr(9) . '<option value="A1">A One</option>' . PHP_EOL
            . chr(9) . '<option value="A2">A Two</option>' . PHP_EOL
            . chr(9) . '</optgroup>' . PHP_EOL
            . chr(9) . '<option value="B">B One</option>' . PHP_EOL
            . '</select>';

        $actual = $tag->select($name, $params, $data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - optgroup array with value
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectOptGroupWithValue(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - optgroup array with value');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'value' => 'A1',
            'class' => 'x_class',
        ];
        $data     = [
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

        $actual = $tag->select($name, $params, $data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - optgroup setAttribute()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectOptGroupSetAttribute(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - optgroup setAttribute()');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'class' => 'x_class',
            'size'  => '10',
        ];
        $data     = [
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

        $actual = $tag
            ->setAttribute('x_name', 'A2')
            ->select($name, $params, $data)
        ;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: select() - optgroup setAttribute() element not
     * present
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function htmlTagSelectOptGroupSetAttributeElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - select() - optgroup setAttribute() element not present');
        $tag = new Tag();
        $tag->setDI($this->container);
        $name     = 'x_name';
        $params   = [
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $data     = [
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

        $actual = $tag
            ->setAttribute('x_name', 'Z')
            ->select($name, $params, $data)
        ;
        $I->assertEquals($expected, $actual);
    }
}
