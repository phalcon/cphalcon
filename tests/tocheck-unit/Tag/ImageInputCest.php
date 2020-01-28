<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

class ImageInputCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: imageInput() - string as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagImageInputStringParameter(UnitTester $I)
    {
        $I->wantToTest('Tag :: imageInput() - string as a parameter');
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
     * Tests Phalcon\Tag :: imageInput() - array as a parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagImageInputArrayParameter(UnitTester $I)
    {
        $I->wantToTest('Tag :: imageInput() - array as a parameter');
        $options  = [
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

        $options  = [
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
     * Tests Phalcon\Tag :: imageInput() - array as a parameters and id in it
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagImageInputArrayParameterWithId(UnitTester $I)
    {
        $I->wantToTest('Tag :: imageInput() - array as a parameters and id in it');
        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
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

        $options  = [
            'x_name',
            'id'    => 'x_id',
            'class' => 'x_class',
            'size'  => '10',
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
     * Tests Phalcon\Tag :: imageInput() - name and no id in parameter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagImageInputArrayParameterWithNameNoId(UnitTester $I)
    {
        $I->wantToTest('Tag :: imageInput() - name and no id in parameter');
        $options  = [
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
            false
        );

        $options  = [
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
            true
        );
    }

    /**
     * Tests Phalcon\Tag :: imageInput() - setDefault
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagImageInputWithSetDefault(UnitTester $I)
    {
        $I->wantToTest('Tag :: imageInput() - setDefault()');
        $options  = [
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

        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="image" '
            . 'name="x_other" value="x_name" class="x_class" '
            . 'size="10"';

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
     * Tests Phalcon\Tag :: imageInput() - displayTo
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagImageInputWithDisplayTo(UnitTester $I)
    {
        $I->wantToTest('Tag :: imageInput() - displayTo()');
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="image" '
            . 'name="x_other" value="x_name" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
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
        $expected = '<input type="image" '
            . 'name="x_other" value="x_name" class="x_class" '
            . 'size="10"';

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
     * Tests Phalcon\Tag :: imageInput() - setDefault and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagImageInputWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Tag :: imageInput() - setDefault() and element not present');
        $options  = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];
        $expected = '<input type="image" '
            . 'name="x_other" value="x_name" class="x_class" '
            . 'size="10"';

        $this->testFieldParameter(
            $I,
            'imageInput',
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
        $expected = '<input type="image" '
            . 'name="x_other" value="x_name" class="x_class" '
            . 'size="10"';

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
     * Tests Phalcon\Tag :: imageInput() - displayTo and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagImageInputWithDisplayToElementNotPresent(UnitTester $I)
    {
        $I->wantToTest('Tag :: imageInput() - displayTo() and element not present');

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="image" name="x_other" value="x_name" class="x_class" size="10"';

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

        $expected = '<input type="image" name="x_other" value="x_name" class="x_class" size="10"';

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
