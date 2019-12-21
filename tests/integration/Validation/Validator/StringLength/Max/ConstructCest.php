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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\StringLength\Max;

class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\StringLength\Max :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMaxConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - __construct()');

        $validator = new Max();

        $this->checkConstruct($I, $validator);
    }
}
