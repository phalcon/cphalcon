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
use Phalcon\Mvc\Router\Group;
use Phalcon\Test\Fixtures\Traits\RouterTrait;

class AddPurgeCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router\Group :: addPurge()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcRouterGroupAddPurge(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addPurge()');

        $router = $this->getRouter(false);

        $group = new Group();

        $group->addPurge(
            '/docs/index',
            [
                'controller' => 'documentation9',
                'action'     => 'index',
            ]
        );

        $router->mount($group);


        $_SERVER['REQUEST_METHOD'] = 'PURGE';

        $router->handle('/docs/index');


        $I->assertEquals(
            'documentation9',
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
