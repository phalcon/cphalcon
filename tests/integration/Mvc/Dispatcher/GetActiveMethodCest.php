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

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use IntegrationTester;

/**
 * Class GetActiveMethodCest
 */
class GetActiveMethodCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getActiveMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcDispatcherGetActiveMethod(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getActiveMethod()');
        $I->skipTest('Need implementation');
    }
}
