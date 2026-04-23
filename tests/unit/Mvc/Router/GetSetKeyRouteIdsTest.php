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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class GetSetKeyRouteIdsTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterGetKeyRouteIds(): void
    {
        Route::reset();

        $router = $this->getRouter(false);

        $usersFind = $router
            ->add('/api/users/find')
            ->setHttpMethods('GET')
            ->setName('usersFind')
        ;
        $usersAdd  = $router
            ->add('/api/users/add')
            ->setHttpMethods('POST')
            ->setName('usersAdd')
        ;

        $expected = $usersFind;
        $actual   = $router->getRouteById(0);
        $this->assertSame($expected, $actual);

        $expected = [0 => 0];
        $actual   = $router->getKeyRouteIds();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-11-07
     */
    public function testMvcRouterGetSetKeyRouteIds(): void
    {
        Route::reset();

        $router    = $this->getRouter(false);
        $usersFind = $router
            ->add('/api/users/find')
            ->setHttpMethods('GET')
            ->setName('usersFind')
        ;
        $usersAdd  = $router
            ->add('/api/users/add')
            ->setHttpMethods('POST')
            ->setName('usersAdd')
        ;

        $expected = $usersFind;
        $actual   = $router->getRouteById(0);
        $this->assertSame($expected, $actual);

        $expected = [0 => 0];
        $actual   = $router->getKeyRouteIds();
        $this->assertSame($expected, $actual);

        $router->setKeyRouteIds([1 => 0]);

        $expected = [1 => 0];
        $actual   = $router->getKeyRouteIds();
        $this->assertSame($expected, $actual);
    }
}
