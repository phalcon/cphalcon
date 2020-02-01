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

namespace Phalcon\Test\Unit\Validation\Validator\StringLength;

use Phalcon\Validation\Validator\StringLength;
use UnitTester;

class GetValidatorsCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: getValidators()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthGetValidators(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - getValidators()');

        $validator = new StringLength();

        $I->assertTrue(is_array($validator->getValidators()), 'Is array');

        $I->assertEmpty($validator->getValidators(), 'Empty validators');
        $I->assertCount(0, $validator->getValidators(), 'Empty validators');

        $validator = new StringLength([
            'min' => 5,
            'max' => 15,
        ]);

        $I->assertTrue(is_array($validator->getValidators()), 'Is array');

        $I->assertNotEmpty($validator->getValidators(), 'Not empty validators');
        $I->assertCount(2, $validator->getValidators(), 'Has 2 validators');
    }
}
