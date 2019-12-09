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

namespace Phalcon\Test\Cli\Cli\Router;

use CliTester;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetRouteByIdCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function testNamedRoutes(CliTester $I)
    {
        Route::reset();

        $router = new Router(false);

        $usersFind = $router->add('api users find')->setName('usersFind');
        $usersAdd  = $router->add('api users add')->setName('usersAdd');

        $I->assertEquals(
            $usersFind,
            $router->getRouteById(
                $usersFind->getRouteId()
            )
        );

        $I->assertEquals(
            $usersAdd,
            $router->getRouteById(
                $usersAdd->getRouteId()
            )
        );
    }
}
