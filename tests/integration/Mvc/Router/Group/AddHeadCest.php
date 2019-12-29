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

namespace Phalcon\Test\Integration\Mvc\Router\Group;

use IntegrationTester;
use Phalcon\Mvc\Router\Group;
use Phalcon\Test\Fixtures\Traits\RouterTrait;

class AddHeadCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router\Group :: addHead()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcRouterGroupAddHead(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addHead()');

        $router = $this->getRouter(false);

        $group = new Group();

        $group->addHead(
            '/docs/index',
            [
                'controller' => 'documentation8',
                'action'     => 'index',
            ]
        );

        $router->mount($group);


        $_SERVER['REQUEST_METHOD'] = 'HEAD';

        $router->handle('/docs/index');


        $I->assertEquals(
            'documentation8',
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
