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

class NotFoundCest
{
    use RouterTrait;

    /**
     * Tests setting notFound handler
     *
     * @author Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since  2013-03-01
     */
    public function testSettingNotFoundPaths(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - notFound()');

        $router = $this->getRouter(false);

        $router->notFound(
            [
                'module'     => 'module',
                'namespace'  => 'namespace',
                'controller' => 'controller',
                'action'     => 'action',
            ]
        );

        $router->handle('/');


        $I->assertEquals(
            'controller',
            $router->getControllerName()
        );

        $I->assertEquals(
            'action',
            $router->getActionName()
        );

        $I->assertEquals(
            'module',
            $router->getModuleName()
        );

        $I->assertEquals(
            'namespace',
            $router->getNamespaceName()
        );
    }
}
