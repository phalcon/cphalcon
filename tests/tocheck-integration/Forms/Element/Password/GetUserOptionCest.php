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

namespace Phalcon\Test\Integration\Forms\Element\Password;

use IntegrationTester;

/**
 * Class GetUserOptionCest
 */
class GetUserOptionCest
{
    /**
     * Tests Phalcon\Forms\Element\Password :: getUserOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementPasswordGetUserOption(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Password - getUserOption()');
        $I->skipTest('Need implementation');
    }
}
