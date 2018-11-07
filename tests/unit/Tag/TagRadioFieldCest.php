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

class TagRadioFieldCest extends TagBase
{
    /**
     * Tests radioField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="radio" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="radio" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests radioField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="radio" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="radio" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests radioField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="radio" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'radioField',
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
        $expected = '<input type="radio" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests radioField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'radioField',
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
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests radioField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';

        $this->testFieldParameter(
            $I,
            'radioField',
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
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests radioField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';

        $this->testFieldParameter(
            $I,
            'radioField',
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
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests radioField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';

        $this->testFieldParameter(
            $I,
            'radioField',
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
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests radioField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testRadioFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';

        $this->testFieldParameter(
            $I,
            'radioField',
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
        $expected = '<input type="radio" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10" checked="checked"';

        $this->testFieldParameter(
            $I,
            'radioField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
