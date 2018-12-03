<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator\Digit;

use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\Digit;
use IntegrationTester;

class HasOptionCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\Digit :: hasOption()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorDigitHasOption(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Digit - hasOption()");
        $validator = new Digit(['message' => 'This is a message']);
        $this->checkHasOption($I, $validator);
    }
}
