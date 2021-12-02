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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Filter\Validation\Validator\StringLength\Min;

class SetTemplateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength\Min :: setTemplate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function filterValidationValidatorStringLengthMinSetTemplate(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - setTemplate()');

        $validator = new Min();

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $I->assertInstanceOf(Min::class, $actual, 'Instance of Min');

        $I->assertEquals(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}
