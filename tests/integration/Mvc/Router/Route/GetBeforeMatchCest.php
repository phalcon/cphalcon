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

namespace Phalcon\Test\Integration\Mvc\Router\Route;

use IntegrationTester;

/**
 * Class GetBeforeMatchCest
 */
class GetBeforeMatchCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: getBeforeMatch()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterRouteGetBeforeMatch(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - getBeforeMatch()');
        $I->skipTest('Need implementation');
    }
}
