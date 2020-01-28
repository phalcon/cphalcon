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

namespace Phalcon\Test\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Mvc\Router;

class ClearCest
{
    /**
     * Tests Phalcon\Mvc\Router :: clear()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcRouterClear(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - clear()');

        $router = new Router(false);

        $router->addGet(
            '/docs/index',
            [
                'controller' => 'documentation4',
                'action'     => 'index',
            ]
        );

        $I->assertCount(
            1,
            $router->getRoutes()
        );

        $router->clear();

        $I->assertCount(
            0,
            $router->getRoutes()
        );
    }
}
