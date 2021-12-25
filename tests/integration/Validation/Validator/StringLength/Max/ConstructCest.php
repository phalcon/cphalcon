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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\ValidationTrait;
use Phalcon\Filter\Validation\Validator\StringLength\Max;

class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength\Max :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function filterValidationValidatorStringLengthMaxConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - __construct()');

        $validator = new Max();

        $this->checkConstruct($I, $validator);
    }
}
