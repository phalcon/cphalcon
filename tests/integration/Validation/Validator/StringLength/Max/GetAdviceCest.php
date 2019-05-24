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

namespace Phalcon\Test\Unit\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Validation\Validator\StringLength\Max;

class GetAdviceCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Max :: getAdvice()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMaxGetAdvice(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - getAdvice()');

        $validator = new Max();

        $expected = "Field :field must not exceed :max characters long";
        $I->assertEquals($expected, $validator->getAdvice(), 'Default advice message for Max');

        $validator->setAdvice('');

        $expected = "The field :field is not valid for " . Max::class;
        $I->assertEquals($expected, $validator->getAdvice(), 'Default advice message');

        $expected = 'New custom advice';
        $validator->setAdvice($expected);

        $I->assertEquals($expected, $validator->getAdvice(), 'New advice message');
    }
}
