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
use Phalcon\Test\Fixtures\Traits\RouterTrait;

class AddGetCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: addGet()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcRouterAddGet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addGet()');

        $router = $this->getRouter(false);

        $router->addGet(
            '/docs/index',
            [
                'controller' => 'documentation4',
                'action'     => 'index',
            ]
        );


        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router->handle('/docs/index');


        $I->assertEquals(
            'documentation4',
            $router->getControllerName()
        );

        $I->assertEquals(
            'index',
            $router->getActionName()
        );

        $I->assertEquals(
            [],
            $router->getParams()
        );
    }
}
