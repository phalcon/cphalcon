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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Helpers\TagSetup;
use UnitTester;

class TextAreaCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: textArea() - string as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTextAreaStringParameter(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - string as a parameter');

        $options  = 'x_name';
        $expected = '<textarea id="x_name" name="x_name"></textarea';

        $this->testFieldParameter($I, 'textArea', $options, $expected);
    }

    /**
     * Tests Phalcon\Tag :: textArea() - array as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTextAreaArrayParameter(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - array as a parameter');

        $options = [
            'x_name',
            'class' => 'x_class',
        ];

        $expected = '<textarea id="x_name" name="x_name" class="x_class"></textarea';

        $this->testFieldParameter($I, 'textArea', $options, $expected);
    }

    /**
     * Tests Phalcon\Tag :: textArea() - array as a parameters and id in it
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTextAreaArrayParameterWithId(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - array as a parameters and id in it');

        $options = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<textarea id="x_id" name="x_name" class="x_class" size="10"></textarea';

        $this->testFieldParameter($I, 'textArea', $options, $expected);
    }

    /**
     * Tests Phalcon\Tag :: textArea() - name and no id in parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTextAreaArrayParameterWithNameNoId(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - name and no id in parameter');

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<textarea id="x_name" name="x_other" class="x_class" size="10"></textarea';

        $this->testFieldParameter($I, 'textArea', $options, $expected);
    }

    /**
     * Tests Phalcon\Tag :: textArea() - setDefault
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTextAreaWithSetDefault(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - setDefault()');

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<textarea id="x_name" name="x_other" class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter($I, 'textArea', $options, $expected, false, 'setDefault');
    }

    /**
     * Tests Phalcon\Tag :: textArea() - displayTo
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTextAreaWithDisplayTo(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - displayTo()');

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<textarea id="x_name" name="x_other" class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter($I, 'textArea', $options, $expected, false, 'displayTo');
    }

    /**
     * Tests Phalcon\Tag :: textArea() - setDefault and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTextAreaWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - setDefault() and element not present');

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<textarea id="x_name" name="x_other" class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter($I, 'textArea', $options, $expected, false, 'setDefault');
    }

    /**
     * Tests Phalcon\Tag :: textArea() - displayTo and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagTextAreaWithDisplayToElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - displayTo() and element not present');

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<textarea id="x_name" name="x_other" class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter($I, 'textArea', $options, $expected, false, 'displayTo');
    }

    /**
     * Tests Phalcon\Tag :: textArea() - displayTo and newline in value
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-03
     */
    public function tagTextAreaWithDisplayToAndNewlineInValue(UnitTester $I)
    {
        $I->wantToTest('Tag - textArea() - displayTo() and newline in value');

        $options  = 'x_name';
        $value    = "\r\nx_content";
        $expected = '<textarea id="x_name" name="x_name">' . $value . '</textarea>';

        Tag::setDefault('x_name', $value);

        $actual = Tag::textArea($options);

        Tag::setDefault('x_name', '');

        $I->assertEquals($expected, $actual);
    }
}
