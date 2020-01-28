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

class AddPurgeCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: addPurge()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcRouterAddPurge(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addPurge()');

        $router = $this->getRouter(false);

        $router->addPurge(
            '/docs/index',
            [
                'controller' => 'documentation9',
                'action'     => 'index',
            ]
        );


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
