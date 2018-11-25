<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\Between;

use UnitTester;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Between :: validate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorBetweenValidate(UnitTester $I)
    {
        $I->wantToTest("Validation\Validator\Between - validate()");
        $I->skipTest("Need implementation");
    }
}
