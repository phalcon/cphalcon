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

class SetTemplatesCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Max :: setTemplates()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMaxSetTemplates(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - setTemplates()');

        $validator = new Max();

        $expected = [
            'key-1' => 'value-1',
            'key-2' => 'value-2',
            'key-3' => 'value-3',
        ];

        $actual = $validator->setTemplates($expected);

        $I->assertInstanceOf(Max::class, $actual, 'Instance of Max');

        $I->assertEquals(
            $expected,
            $validator->getTemplates(),
            'Get equals templates'
        );
    }
}
