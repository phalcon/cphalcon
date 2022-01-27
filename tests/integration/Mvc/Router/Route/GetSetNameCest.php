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
use Phalcon\Mvc\Router\Route;

use function uniqid;

class GetSetNameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: getName()/setName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-01-27
     */
    public function mvcRouterRouteGetSetName(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - getName()/setName()');

        $route = new Route('test');

        $actual = $route->getName();
        $I->assertNull($actual);

        $name = uniqid();
        $route->setName($name);

        $expected = $name;
        $actual   = $route->getName();
        $I->assertSame($expected, $actual);
    }
}
