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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetRouteByIdTest extends AbstractUnitTestCase
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
        $actual   = $router->getRouteById($usersFind->getRouteId());
        $this->assertSame($expected, $actual);

        $expected = $usersAdd;
        $actual   = $router->getRouteById($usersAdd->getRouteId());
        $this->assertSame($expected, $actual);
    }
}
