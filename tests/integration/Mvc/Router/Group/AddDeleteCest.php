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

class AddDeleteCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router\Group :: addDelete()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcRouterGroupAddDelete(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - addDelete()');

        $router = $this->getRouter(false);

        $group = new Group();

        $group->addDelete(
            '/docs/index',
            [
                'controller' => 'documentation6',
                'action'     => 'index',
            ]
        );

        $router->mount($group);


        $_SERVER['REQUEST_METHOD'] = 'DELETE';

        $router->handle('/docs/index');


        $I->assertEquals(
            'documentation6',
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
