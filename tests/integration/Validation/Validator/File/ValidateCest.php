<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator\File;

use IntegrationTester;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\File :: validate()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorFileValidate(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\File - validate()");
        $I->skipTest("Need implementation");
    }
}
