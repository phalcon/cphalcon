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
 * Class SetDefaultCest
 */
class SetDefaultCest
{
    /**
     * Tests Phalcon\Forms\Element\Submit :: setDefault()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementSubmitSetDefault(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Submit - setDefault()');
        $I->skipTest('Need implementation');
    }
}
