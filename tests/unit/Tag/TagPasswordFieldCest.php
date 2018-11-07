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

class TagPasswordFieldCest extends TagBase
{
    /**
     * Tests passwordField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="password" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="password" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests passwordField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="password" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="password" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests passwordField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="password" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
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
        $expected = '<input type="password" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests passwordField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
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
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests passwordField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
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
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests passwordField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
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
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests passwordField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
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
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests passwordField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testPasswordFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
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
        $expected = '<input type="password" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'passwordField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
