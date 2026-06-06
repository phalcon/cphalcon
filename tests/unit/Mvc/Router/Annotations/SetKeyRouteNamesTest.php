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
use Phalcon\Tests\AbstractUnitTestCase;

final class SetKeyRouteNamesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsSetKeyRouteNames(): void
    {
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

        // Looking up a route by name lazily builds the name => position map
        $this->assertSame($usersAdd, $router->getRouteByName('usersAdd'));

        $this->assertSame(
            [
                'usersFind' => 0,
                'usersAdd'  => 1,
            ],
            $router->getKeyRouteNames()
        );

        $names = [
            'usersAdd'  => 0,
            'usersFind' => 1,
        ];

        $router->setKeyRouteNames($names);

        $this->assertSame($names, $router->getKeyRouteNames());
    }
}
