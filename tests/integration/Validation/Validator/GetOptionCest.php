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

namespace Phalcon\Test\Integration\Validation\Validator;

use IntegrationTester;

/**
 * Class GetOptionCest
 */
class GetOptionCest
{
    /**
     * Tests Phalcon\Validation\Validator :: getOption()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorGetOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator - getOption()');
        $I->skipTest('Need implementation');
    }
}
