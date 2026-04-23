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

namespace Phalcon\Tests\Unit\Cli\Router;

use Phalcon\Cli\Router;
use Phalcon\Cli\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetRouteByNameTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function testNamedRoutes(): void
    {
        $this->setNewCliFactoryDefault();
        Route::reset();

        $router = new Router(false);

        $usersFind = $router->add('api users find')
                            ->setName('usersFind')
        ;
        $usersAdd  = $router->add('api users add')
                            ->setName('usersAdd')
        ;

        $expected = $usersFind;
        $actual   = $router->getRouteByName('usersFind');
        $this->assertSame($expected, $actual);

        $expected = $usersAdd;
        $actual   = $router->getRouteByName('usersAdd');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testCliRouterGetRouteByNameNotFound(): void
    {
        $this->setNewCliFactoryDefault();
        Route::reset();

        $router = new Router(false);
        $router->add('api users find')->setName('usersFind');

        $actual = $router->getRouteByName('doesNotExist');
        $this->assertFalse($actual);
    }
}
