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

use Phalcon\Test\Unit\Tag\Helper\TagHelper;
use UnitTester;

class TagFileFieldCest extends TagHelper
{
    /**
     * Tests fileField with string as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldStringParameter(UnitTester $I)
    {
        $options  = 'x_name';
        $expected = '<input type="file" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            false
        );

        $options  = 'x_name';
        $expected = '<input type="file" id="x_name" name="x_name"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests fileField with array as a parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldArrayParameter(UnitTester $I)
    {
        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="file" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            false
        );

        $options  = [
            'x_name',
            'class' => 'x_class',
        ];
        $expected = '<input type="file" id="x_name" name="x_name" '
            . 'class="x_class"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests fileField with array as a parameters and id in it
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldArrayParameterWithId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="file" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
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
        $expected = '<input type="file" id="x_id" name="x_name" '
            . 'class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            true
        );
    }

    /**
     * Tests fileField with name and no id in parameter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldArrayParameterWithNameNoId(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
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
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" class="x_class" size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            false
        );
    }

    /**
     * Tests fileField with setDefault
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldWithSetDefault(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
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
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests fileField with displayTo
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldWithDisplayTo(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
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
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }

    /**
     * Tests fileField with setDefault and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
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
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            true,
            'setDefault'
        );
    }

    /**
     * Tests fileField with displayTo and element not present
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-09-05
     */
    public function testFileFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
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
        $expected = '<input type="file" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'fileField',
            $options,
            $expected,
            true,
            'displayTo'
        );
    }
}
