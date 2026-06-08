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

namespace Phalcon\Tests\Unit\Mvc\Router\Annotations;

use Phalcon\Mvc\Router\Annotations;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetKeyRouteIdsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsSetKeyRouteIds(): void
    {
        Route::reset();

        $router = new Annotations(false);

        $usersFind = $router
            ->add('/api/users/find')
            ->setHttpMethods('GET')
            ->setName('usersFind')
        ;
        $usersAdd = $router
            ->add('/api/users/add')
            ->setHttpMethods('POST')
            ->setName('usersAdd')
        ;

        $this->assertSame($usersFind, $router->getRouteById(0));
        $this->assertSame([0 => 0], $router->getKeyRouteIds());

        $router->setKeyRouteIds([1 => 0]);

        $this->assertSame([1 => 0], $router->getKeyRouteIds());
    }
}
