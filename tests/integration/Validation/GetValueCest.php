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

namespace Phalcon\Tests\Integration\Validation;

use IntegrationTester;

/**
 * Class GetValueCest
 */
class GetValueCest
{
    /**
     * Tests Phalcon\Filter\Validation :: getValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function filterValidationGetValue(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getValue()');

        $I->skipTest('Need implementation');
    }
}
