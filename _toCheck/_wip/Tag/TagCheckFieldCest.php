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
use Phalcon\Test\Unit\Tag\Helper\TagHelper;
use UnitTester;

class TagCheckFieldCest extends TagHelper
{
    /**
     * Tests checkField with string as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="checkbox" id="x_name" name="x_name"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="checkbox" id="x_name" name="x_name"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests checkField with array as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="checkbox" id="x_name" name="x_name" '
            . 'class="x_class"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="checkbox" id="x_name" name="x_name" '
            . 'class="x_class"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests checkField with array as a parameters and id in it
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            true
        );

        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests checkField with name and no id in parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" name="x_other" '
            . 'class="x_class" size="10"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" name="x_other" '
            . 'class="x_class" size="10"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests checkField with setDefault
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            false,
            'setDefault'
        );

        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests checkField with displayTo
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            false,
            'displayTo'
        );

        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests checkField with setDefault and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" name="x_other" '
            . 'value="x_value" class="x_class" size="10" '
            . 'checked="checked"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            false,
            'setDefault'
        );

        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" name="x_other" '
            . 'value="x_value" class="x_class" size="10" '
            . 'checked="checked"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests checkField with displayTo and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testCheckFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" name="x_other" '
            . 'value="x_value" class="x_class" size="10" '
            . 'checked="checked"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            false,
            'displayTo'
        );

        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="checkbox" id="x_name" name="x_other" '
            . 'value="x_value" class="x_class" size="10" '
            . 'checked="checked"';
        $this->testFieldParameter(
            $I,
            'checkField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests checkField with setDefault and with a value of zero
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12316
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-12-19
     */
    public function shouldGenerateCheckFieldAsCheckedWhenValueIsZeroAndDefaultIsZero(UnitTester $I)
    {
        $examples = [
            [0, "0", '<input type="checkbox" id="demo-0" name="demo-0" value="0" checked="checked">'],
            [0, 0, '<input type="checkbox" id="demo-0" name="demo-0" value="0" checked="checked">'],
            ["0", 0, '<input type="checkbox" id="demo-0" name="demo-0" value="0" checked="checked">'],
            ["0", "0", '<input type="checkbox" id="demo-0" name="demo-0" value="0" checked="checked">'],
        ];

        foreach ($examples as $example) {
            $value    = $example[0];
            $default  = $example[1];
            $expected = $example[2];

            Tag::resetInput();
            Tag::setDocType(Tag::HTML5);
            Tag::setDefault("demo-0", $default);

            $actual = Tag::checkField(['demo-0', 'value' => $value]);
            $I->assertEquals($expected, $actual);
        }
    }
}
