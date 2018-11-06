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

class TagDateFieldCest extends TagBase
{
    /**
     * Tests dateField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="date" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="date" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests dateField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateFieldArrayParameter(UnitTester $I)
    {
        $options = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="date" id="x_name" name="x_name" '
                  . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            false
        );

        $options = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="date" id="x_name" name="x_name" '
                  . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests dateField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateFieldArrayParameterWithId(UnitTester $I)
    {
        $options = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10'
        ];
        $expected = '<input type="date" id="x_id" name="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
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
        $expected = '<input type="date" id="x_id" name="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests dateField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
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
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests dateField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateFieldWithSetDefault(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
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
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests dateField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateFieldWithDisplayTo(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
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
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests dateField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
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
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests dateField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDateFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
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
        $expected = '<input type="date" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'dateField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
