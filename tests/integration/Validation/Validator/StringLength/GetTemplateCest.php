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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength;

use Phalcon\Filter\Validation\Validator\StringLength;
use IntegrationTester;

class GetTemplateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength :: getTemplate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function filterValidationValidatorStringLengthGetTemplate(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - getTemplate()');

        $validator = new StringLength();

        $expected = 'The field :field is not valid for ' . StringLength::class;

        $I->assertEquals(
            $expected,
            $validator->getTemplate(),
            'Default template message'
        );

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $I->assertInstanceOf(StringLength::class, $actual, 'Instance of StringLenght');

        $I->assertEquals(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}
