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

namespace Phalcon\Tests\Integration\Mvc\Router\Group;

use IntegrationTester;
use Phalcon\Mvc\Router\Group;
use Phalcon\Tests\Fixtures\Traits\RouterTrait;

class AddCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router\Group :: add()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcRouterGroupAdd(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\ - add()');

        $router = $this->getRouter(false);

        $group = new Group();

        $group->add(
            '/docs/index',
            [
                'controller' => 'documentation11',
                'action'     => 'index',
            ]
        );

        $router->mount($group);

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
