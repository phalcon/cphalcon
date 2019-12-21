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
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetSetDICest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Router :: getDI()/setDI()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcRouterGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Router - getDI()/setDI()");

        $router = new Router();

        $di = new FactoryDefault();

        $router->setDI($di);

        $I->assertEquals(
            $di,
            $router->getDI()
        );
    }
}
