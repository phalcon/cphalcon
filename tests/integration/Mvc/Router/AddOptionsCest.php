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
use Phalcon\Test\Fixtures\Traits\RouterTrait;

class AddOptionsCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: addOptions()
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2019-04-17
     */
    public function mvcRouterAddOptions(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addOptions()');

        $router = $this->getRouter(false);

        $router->addOptions(
            '/docs/index',
            [
                'controller' => 'documentation7',
                'action'     => 'index',
            ]
        );



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
