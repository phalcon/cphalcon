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

namespace Phalcon\Tests\Integration\Forms\Element\Radio;

use IntegrationTester;

/**
 * Class GetUserOptionCest
 */
class GetUserOptionCest
{
    /**
     * Tests Phalcon\Forms\Element\Radio :: getUserOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementRadioGetUserOption(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Radio - getUserOption()');
        $I->skipTest('Need implementation');
    }
}
