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

namespace Phalcon\Test\Unit\Validation\Validator\CreditCard;

use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Validation\Validator\CreditCard :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function validationValidatorCreditCardConstruct(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\CreditCard - __construct()');

        $I->skipTest('Need implementation');
    }
}
