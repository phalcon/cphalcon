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

class TagTextAreaCest extends TagBase
{
    /**
     * Tests textArea with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<textarea id="x_name" name="x_name">'
            . '</textarea';

        $this->testFieldParameter(
            $I,
            'textArea',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests textArea with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<textarea id="x_name" name="x_name" '
            . 'class="x_class"></textarea';

        $this->testFieldParameter(
            $I,
            'textArea',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests textArea with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_id" name="x_name" '
            . 'class="x_class" size="10"></textarea';

        $this->testFieldParameter(
            $I,
            'textArea',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests textArea with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_name" name="x_other" '
            . 'class="x_class" size="10"></textarea';

        $this->testFieldParameter(
            $I,
            'textArea',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests textArea with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_name" name="x_other" '
            . 'class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter(
            $I,
            'textArea',
            $options,
            $expected,
            false,
            'setDefault'
        );
    }

    /**
     * Tests textArea with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_name" name="x_other" '
            . 'class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter(
            $I,
            'textArea',
            $options,
            $expected,
            false,
            'displayTo'
        );
    }

    /**
     * Tests textArea with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_name" name="x_other" '
            . 'class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter(
            $I,
            'textArea',
            $options,
            $expected,
            false,
            'setDefault'
        );
    }

    /**
     * Tests textArea with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testTextAreaWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<textarea id="x_name" name="x_other" '
            . 'class="x_class" size="10">x_value</textarea';

        $this->testFieldParameter(
            $I,
            'textArea',
            $options,
            $expected,
            false,
            'displayTo'
        );
    }

    /**
     * Tests textArea with displayTo and newline in value
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testTextAreaWithDisplayToAndNewlineInValue(UnitTester $I)
    {
        $options  = 'x_name';
        $value    = "\r\nx_content";
        $expected = '<textarea id="x_name" name="x_name">'
            . $value
            . '</textarea>';

        Tag::setDefault('x_name', $value);
        $actual = Tag::textArea($options);
        Tag::setDefault('x_name', '');

        $I->assertEquals($expected, $actual);
    }
}
