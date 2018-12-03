<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator\Email;

use IntegrationTester;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Email :: validate()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorEmailValidate(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Email - validate()");
        $I->skipTest("Need implementation");
    }
}
