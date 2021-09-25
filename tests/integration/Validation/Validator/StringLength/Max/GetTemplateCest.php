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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Max;

class GetTemplateCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Max :: getTemplate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMaxGetTemplate(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - getTemplate()');

        $validator = new Max();

        $expected = 'Field :field must not exceed :max characters long';
        $I->assertEquals($expected, $validator->getTemplate(), 'Default template message for Max');

        $validator->setTemplate('');

        $expected = 'The field :field is not valid for ' . Max::class;
        $I->assertEquals($expected, $validator->getTemplate(), 'Default template message');

        $expected = 'New custom template';
        $validator->setTemplate($expected);

        $I->assertEquals($expected, $validator->getTemplate(), 'New template message');
    }
}
