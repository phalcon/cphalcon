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

namespace Phalcon\Tests\Integration\Mvc\Router\Route;

use IntegrationTester;
use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\Route;

use function uniqid;

class GetSetGroupCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: getGroup()/setGroup()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-01-27
     */
    public function mvcRouterRouteGetSetGroup(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - getGroup()/setGroup()');

        $route = new Route('test');

        $actual = $route->getGroup();
        $I->assertNull($actual);

        $group = new Group();
        $route->setGroup($group);

        $expected = $group;
        $actual   = $route->getGroup();
        $I->assertSame($expected, $actual);
    }
}
