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

class TagEmailFieldCest extends TagBase
{
    /**
     * Tests emailField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testEmailFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="email" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="email" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests emailField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testEmailFieldArrayParameter(UnitTester $I)
    {
        $options = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="email" id="x_name" name="x_name" '
                  . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            false
        );

        $options = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="email" id="x_name" name="x_name" '
                  . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests emailField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testEmailFieldArrayParameterWithId(UnitTester $I)
    {
        $options = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10'
        ];
        $expected = '<input type="email" id="x_id" name="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
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
        $expected = '<input type="email" id="x_id" name="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests emailField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testEmailFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
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
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests emailField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testEmailFieldWithSetDefault(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
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
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests emailField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testEmailFieldWithDisplayTo(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
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
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests emailField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testEmailFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
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
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests emailField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testEmailFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
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
        $expected = '<input type="email" id="x_name" '
                  . 'name="x_other" value="x_value" class="x_class" '
                  . 'size="10"';

        $this->testFieldParameter(
            $I,
            'emailField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
