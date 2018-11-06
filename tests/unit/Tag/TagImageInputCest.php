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

class TagImageInputCest extends TagBase
{
    /**
     * Tests imageInput with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="image" value="x_name"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="image" value="x_name"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests imageInput with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputArrayParameter(UnitTester $I)
    {
        $options = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="image" value="x_name" '
                  . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            false
        );

        $options = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="image" value="x_name" '
                  . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests imageInput with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputArrayParameterWithId(UnitTester $I)
    {
        $options = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10'
        ];
        $expected = '<input type="image" id="x_id" value="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
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
        $expected = '<input type="image" id="x_id" value="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests imageInput with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputArrayParameterWithNameNoId(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="image" name="x_other" value="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
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
        $expected = '<input type="image" name="x_other" value="x_name" '
                  . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests imageInput with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputWithSetDefault(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="image" name="x_other" '
                  . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
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
        $expected = '<input type="image" name="x_other" '
                  . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests imageInput with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputWithDisplayTo(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="image" name="x_other" '
                  . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
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
        $expected = '<input type="image" name="x_other" '
                  . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests imageInput with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="image" name="x_other" '
                  . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
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
        $expected = '<input type="image" name="x_other" '
                  . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests imageInput with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testImageInputWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="image" name="x_other" '
                  . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
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
        $expected = '<input type="image" name="x_other" '
                  . 'value="x_name" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
