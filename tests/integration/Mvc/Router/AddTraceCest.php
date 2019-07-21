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

class AddTraceCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: addTrace()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-04-17
     */
    public function mvcRouterAddTrace(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - addTrace()');

        $router = $this->getRouter(false);

        $router->addTrace(
            '/docs/index',
            [
                'controller' => 'documentation10',
                'action'     => 'index',
            ]
        );



        $_SERVER['REQUEST_METHOD'] = 'TRACE';

        $router->handle('/docs/index');



        $I->assertEquals(
            'documentation10',
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
