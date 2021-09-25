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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tests\Fixtures\Helpers\TagHelper;
use UnitTester;

class CheckFieldCest extends TagHelper
{
    protected $function  = 'checkField';
    protected $inputType = 'checkbox';

    /**
     * Tests Phalcon\Tag :: weekField() - setDefault
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagFieldWithSetDefault(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Tag - %s() - setDefault()',
                $this->function
            )
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="' . $this->inputType . '" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" size="10" checked="checked"';

        $this->testFieldParameter($I, $this->function, $options, $expected, false, 'setDefault');
        $this->testFieldParameter($I, $this->function, $options, $expected, true, 'setDefault');
    }

    /**
     * Tests Phalcon\Tag :: weekField() - displayTo
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagFieldWithDisplayTo(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Tag - %s() - string displayTo()',
                $this->function
            )
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="' . $this->inputType . '" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" size="10" checked="checked"';

        $this->testFieldParameter($I, $this->function, $options, $expected, false, 'displayTo');
        $this->testFieldParameter($I, $this->function, $options, $expected, true, 'displayTo');
    }

    /**
     * Tests Phalcon\Tag :: weekField() - setDefault and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagFieldWithSetDefaultElementNotPresent(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Tag - %s() - setDefault() element not present',
                $this->function
            )
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="' . $this->inputType . '" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" size="10" checked="checked"';

        $this->testFieldParameter($I, $this->function, $options, $expected, false, 'setDefault');
        $this->testFieldParameter($I, $this->function, $options, $expected, true, 'setDefault');
    }

    /**
     * Tests Phalcon\Tag :: weekField() - displayTo and element not present
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-05
     */
    public function tagFieldWithDisplayToElementNotPresent(UnitTester $I)
    {
        $I->wantToTest(
            sprintf(
                'Tag - %s() - displayTo() element not present',
                $this->function
            )
        );

        $options = [
            'x_name',
            'name'  => 'x_other',
            'class' => 'x_class',
            'size'  => '10',
        ];

        $expected = '<input type="' . $this->inputType . '" id="x_name" '
            . 'name="x_other" value="x_value" class="x_class" size="10" checked="checked"';

        $this->testFieldParameter($I, $this->function, $options, $expected, false, 'displayTo');
        $this->testFieldParameter($I, $this->function, $options, $expected, true, 'displayTo');
    }
}
