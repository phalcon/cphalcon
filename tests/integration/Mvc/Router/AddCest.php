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

class AddCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: add()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcRouterAdd(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - add()');

        $router = $this->getRouter(false);

        $router->add(
            '/docs/index',
            [
                'controller' => 'documentation11',
                'action'     => 'index',
            ]
        );


        $router->handle('/docs/index');


        $I->assertEquals(
            'documentation11',
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
