<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Min;

class GetAdviceCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Min :: getAdvice()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMinGetAdvice(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - getAdvice()');

        $validator = new Min();

        $expected = "Field :field must be at least :min characters long";
        $I->assertEquals($expected, $validator->getAdvice(), 'Default advice message for Min');

        $validator->setAdvice('');

        $expected = "The field :field is not valid for " . Min::class;
        $I->assertEquals($expected, $validator->getAdvice(), 'Default advice message');

        $expected = 'New custom advice';
        $validator->setAdvice($expected);

        $I->assertEquals($expected, $validator->getAdvice(), 'New advice message');
    }
}
