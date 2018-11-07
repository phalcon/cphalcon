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

class TagSubmitButtonCest extends TagBase
{
    /**
     * Tests submitField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="submit" value="x_name"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="submit" value="x_name"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests submitButton with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="submit" value="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="submit" value="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests submitButton with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="submit" id="x_id" value="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
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
        $expected = '<input type="submit" id="x_id" value="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests submitButton with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
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
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests submitButton with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
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
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests submitButton with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
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
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests submitButton with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
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
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests submitButton with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSubmitButtonWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
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
        $expected = '<input type="submit" name="x_other" '
            . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'submitButton',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
