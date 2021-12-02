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

class GetTemplateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength\Min :: getTemplate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function filterValidationValidatorStringLengthMinGetTemplate(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - getTemplate()');

        $validator = new Min();

        $expected = 'Field :field must be at least :min characters long';
        $I->assertEquals($expected, $validator->getTemplate(), 'Default template message for Min');

        $validator->setTemplate('');

        $expected = 'The field :field is not valid for ' . Min::class;
        $I->assertEquals($expected, $validator->getTemplate(), 'Default template message');

        $expected = 'New custom template';
        $validator->setTemplate($expected);

        $I->assertEquals($expected, $validator->getTemplate(), 'New template message');
    }
}
