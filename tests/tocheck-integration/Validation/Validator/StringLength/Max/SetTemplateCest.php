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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Max;

class SetTemplateCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Max :: setTemplate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMaxSetTemplate(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - setTemplate()');

        $validator = new Max();

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $I->assertInstanceOf(Max::class, $actual, 'Instance of Max');

        $I->assertEquals(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}
