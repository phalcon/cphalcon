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

namespace Phalcon\Tests\Integration\Validation\Validator\Callback;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\ValidationTrait;
use Phalcon\Filter\Validation\Validator\Callback;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Filter\Validation\Validator\Callback :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterValidationValidatorCallbackConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Callback - __construct()');

        $validator = new Callback();

        $this->checkConstruct($I, $validator);
    }
}
