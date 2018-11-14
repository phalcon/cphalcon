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

class TagRangeFieldCest extends TagBase
{
    /**
     * Tests rangeField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="range" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="range" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests rangeField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="range" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="range" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests rangeField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="range" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
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
        $expected = '<input type="range" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests rangeField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
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
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests rangeField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
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
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests rangeField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
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
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests rangeField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
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
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests rangeField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRangeFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
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
        $expected = '<input type="range" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'rangeField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
