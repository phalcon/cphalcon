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

class AddOptionsCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router\Group :: addOptions()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcRouterGroupAddOptions(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addOptions()');

        $router = $this->getRouter(false);

        $group = new Group();

        $group->addOptions(
            '/docs/index',
            [
                'controller' => 'documentation7',
                'action'     => 'index',
            ]
        );

        $router->mount($group);


        $_SERVER['REQUEST_METHOD'] = 'OPTIONS';

        $router->handle('/docs/index');


        $I->assertEquals(
            'documentation7',
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
