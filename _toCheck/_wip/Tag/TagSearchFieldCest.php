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

class TagSearchFieldCest extends TagBase
{
    /**
     * Tests searchField with string as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="search" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="search" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests searchField with array as a parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="search" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="search" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests searchField with array as a parameters and id in it
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="search" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
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
        $expected = '<input type="search" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests searchField with name and no id in parameter
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
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
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests searchField with setDefault
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
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
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests searchField with displayTo
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
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
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests searchField with setDefault and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
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
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests searchField with displayTo and element not present
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testSearchFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
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
        $expected = '<input type="search" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'searchField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
