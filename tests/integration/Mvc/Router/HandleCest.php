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
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Router;

/**
 * Class HandleCest
 */
class HandleCest
{
    /**
     * Tests Phalcon\Mvc\Router :: handle()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterHandle(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - handle()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Mvc\Router :: handle() - numeric
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-17
     */
    public function mvcRouterHandleNumeric(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - handle() - numeric');

        $router = new Router();

        $di = new FactoryDefault();

        $router->setDI($di);
        $router->handle('/12/34/56');

        $I->assertEquals(
            '12',
            $router->getControllerName()
        );

        $I->assertEquals(
            '34',
            $router->getActionName()
        );

        $I->assertEquals(
            ['56'],
            $router->getParams()
        );
    }
}
