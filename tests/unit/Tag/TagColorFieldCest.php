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

class TagColorFieldCest extends TagBase
{
    /**
     * Tests colorField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testColorFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="color" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="color" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests colorField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testColorFieldArrayParameter(UnitTester $I)
    {
        $options = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="color" id="x_name" name="x_name" '
                  . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            false
        );

        $options = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="color" id="x_name" name="x_name" '
                  . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests colorField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testColorFieldArrayParameterWithId(UnitTester $I)
    {
        $options = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10'
        ];
        $expected = '<input type="color" id="x_id" name="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            true
        );

        $options = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10'
        ];
        $expected = '<input type="color" id="x_id" name="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests colorField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testColorFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            false
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests colorField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testColorFieldWithSetDefault(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            false,
            'setDefault'
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests colorField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testColorFieldWithDisplayTo(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            false,
            'displayTo'
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests colorField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testColorFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            false,
            'setDefault'
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests colorField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testColorFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            false,
            'displayTo'
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="color" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'colorField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
