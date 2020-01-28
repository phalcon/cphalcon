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

namespace Phalcon\Test\Integration\Mvc\Router\Group;

use IntegrationTester;
use Phalcon\Mvc\Router\Group;

class GetRoutesCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: getRoutes()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcRouterGroupGetRoutes(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - getRoutes()');

        $group = new Group();

        $getRoute = $group->addGet(
            '/docs/index',
            [
                'controller' => 'documentation4',
                'action'     => 'index',
            ]
        );

        $postRoute = $group->addPost(
            '/docs/index',
            [
                'controller' => 'documentation3',
                'action'     => 'index',
            ]
        );

        $I->assertCount(
            2,
            $group->getRoutes()
        );

        $I->assertEquals(
            [
                $getRoute,
                $postRoute,
            ],
            $group->getRoutes()
        );
    }
}
