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

namespace Phalcon\Tests\Cli\Cli\Router;

use CliTester;
use Phalcon\Cli\Router;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetRoutesCest
{
    use DiTrait;

    public function _before(CliTester $I)
    {
        $this->setNewCliFactoryDefault();
    }

    /**
     * Tests Phalcon\Cli\Router :: getRoutes()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-03
     */
    public function cliRouterGetRoutes(CliTester $I)
    {
        $I->wantToTest('Cli\Router - getRoutes()');

        Router\Route::reset();
        $router = new Router(false);

        $expected = [];
        $actual   = $router->getRoutes();
        $I->assertSame($expected, $actual);

        $usersFind = $router->add('api users find')
                            ->setName('usersFind')
        ;
        $usersAdd  = $router->add('api users add')
                            ->setName('usersAdd')
        ;

        $expected = [
            0 => $usersFind,
            1 => $usersAdd,
        ];
        $actual   = $router->getRoutes();
        $I->assertSame($expected, $actual);
    }
}
