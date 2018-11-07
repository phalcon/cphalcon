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

class TagDateTimeLocalFieldCest extends TagBase
{
    /**
     * Tests dateTimeLocalField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeLocalFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_name"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_name"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests dateTimeLocalField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeLocalFieldArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="datetime-local" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="datetime-local" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests dateTimeLocalField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeLocalFieldArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="datetime-local" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
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
        $expected = '<input type="datetime-local" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests dateTimeLocalField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeLocalFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
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
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests dateTimeLocalField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeLocalFieldWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
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
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests dateTimeLocalField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeLocalFieldWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
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
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests dateTimeLocalField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeLocalFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
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
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests dateTimeLocalField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateTimeLocalFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
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
        $expected = '<input type="datetime-local" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateTimeLocalField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
