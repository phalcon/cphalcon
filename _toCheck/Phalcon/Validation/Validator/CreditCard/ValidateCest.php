<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\CreditCard;

use UnitTester;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\CreditCard :: validate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorCreditcardValidate(UnitTester $I)
    {
        $I->wantToTest("Validation\Validator\CreditCard - validate()");
        $I->skipTest("Need implementation");
    }
}
