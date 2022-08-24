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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\CreditCard;

use IntegrationTester;
use Phalcon\Filter\Validation\Validator\CreditCard;
use Phalcon\Tests\Fixtures\Traits\ValidationTrait;

/**
 * Class SetOptionCest
 */
class SetOptionCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Filter\Validation\Validator\CreditCard :: setOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterValidationValidatorCreditCardSetOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\CreditCard - setOption()');

        $validator = new CreditCard();

        $this->checkSetOption($I, $validator);
    }
}
