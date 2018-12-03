<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator\Uniqueness;

use IntegrationTester;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Uniqueness :: validate()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorUniquenessValidate(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Uniqueness - validate()");
        $I->skipTest("Need implementation");
    }
}
