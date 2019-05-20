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

namespace Phalcon\Test\Cli\Cli\Router\Route;

use CliTester;
use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetPathsCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    public function testShortPaths(CliTester $I)
    {
        Route::reset();

        $router = new Router(false);


        $route = $router->add('route0', 'Feed');

        $I->assertEquals(
            [
                'task' => 'feed',
            ],
            $route->getPaths()
        );


        $route = $router->add('route1', 'Feed::get');

        $I->assertEquals(
            [
                'task'   => 'feed',
                'action' => 'get',
            ],
            $route->getPaths()
        );


        $route = $router->add('route2', 'News::Posts::show');

        $I->assertEquals(
            [
                'module' => 'News',
                'task'   => 'posts',
                'action' => 'show',
            ],
            $route->getPaths()
        );


        $route = $router->add('route3', 'MyApp\\Tasks\\Posts::show');

        $I->assertEquals(
            [
                'namespace' => 'MyApp\\Tasks',
                'task'      => 'posts',
                'action'    => 'show',
            ],
            $route->getPaths()
        );


        $route = $router->add('route3', 'News::MyApp\\Tasks\\Posts::show');

        $I->assertEquals(
            [
                'module'    => 'News',
                'namespace' => 'MyApp\\Tasks',
                'task'      => 'posts',
                'action'    => 'show',
            ],
            $route->getPaths()
        );


        $route = $router->add('route3', '\\Posts::show');

        $I->assertEquals(
            [
                'task'   => 'posts',
                'action' => 'show',
            ],
            $route->getPaths()
        );
    }
}
