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

namespace Phalcon\Tests\Integration\Forms\Element\Submit;

use IntegrationTester;

/**
 * Class GetUserOptionCest
 */
class GetUserOptionCest
{
    /**
     * Tests Phalcon\Forms\Element\Submit :: getUserOption()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementSubmitGetUserOption(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Submit - getUserOption()');
        $I->skipTest('Need implementation');
    }
}
