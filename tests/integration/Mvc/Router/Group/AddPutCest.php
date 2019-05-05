<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Router\Group;

use IntegrationTester;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Group;
use Phalcon\Test\Fixtures\Traits\RouterTrait;

class AddPutCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router\Group :: addPut()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcRouterGroupAddPut(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addPut()');

        $router = $this->getRouter(false);

        $group = new Group();

        $group->addPut(
            '/docs/index',
            [
                'controller' => 'documentation5',
                'action'     => 'index',
            ]
        );

        $router->mount($group);



        $_SERVER['REQUEST_METHOD'] = 'PUT';

        $router->handle('/docs/index');



        $I->assertEquals(
            'documentation5',
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
