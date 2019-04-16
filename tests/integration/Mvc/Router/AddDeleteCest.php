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

namespace Phalcon\Test\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Mvc\Router;
use Phalcon\Test\Fixtures\Traits\RouterTrait;

/**
 * Class AddDeleteCest
 */
class AddDeleteCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: addDelete()
     *
     * @param IntegrationTester $I
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcRouterAddDelete(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addDelete()');

        $router = $this->getRouter(false);

        $router->addDelete(
            '/docs/index',
            [
                'controller' => 'documentation6',
                'action'     => 'index',
            ]
        );



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
