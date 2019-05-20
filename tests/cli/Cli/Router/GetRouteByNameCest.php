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

namespace Phalcon\Test\Cli\Cli\Router;

use CliTester;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetRouteByNameCest
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
            $usersAdd,
            $router->getRouteByName('usersAdd')
        );

        $I->assertEquals(
            $usersAdd,
            $router->getRouteByName('usersAdd')
        );

        $I->assertEquals(
            $usersFind,
            $router->getRouteById(0)
        );
    }
}
