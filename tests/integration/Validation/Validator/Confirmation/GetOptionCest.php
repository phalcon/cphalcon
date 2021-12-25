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

namespace Phalcon\Tests\Integration\Validation\Validator\Confirmation;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\ValidationTrait;
use Phalcon\Filter\Validation\Validator\Confirmation;

/**
 * Class GetOptionCest
 */
class GetOptionCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Filter\Validation\Validator\Confirmation :: getOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterValidationValidatorConfirmationGetOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Confirmation - getOption()');

        $validator = new Confirmation();

        $this->checkGetOption($I, $validator);
    }
}
