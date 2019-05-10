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

namespace Phalcon\Test\Integration\Validation\Validator\CreditCard;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\CreditCard;

/**
 * Class SetOptionCest
 */
class SetOptionCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\CreditCard :: setOption()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorCreditCardSetOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\CreditCard - setOption()');

        $validator = new CreditCard();

        $this->checkSetOption($I, $validator);
    }
}
