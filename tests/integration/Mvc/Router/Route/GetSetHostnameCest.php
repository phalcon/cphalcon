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

class GetSetHostnameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: getHostname()/setHostname()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-01-27
     */
    public function mvcRouterRouteGetSetHostname(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - getHostname()/setHostname()');

        $route = new Route('test');

        $actual = $route->getHostname();
        $I->assertNull($actual);

        $name = uniqid();
        $route->setHostname($name);

        $expected = $name;
        $actual   = $route->getHostname();
        $I->assertSame($expected, $actual);
    }
}
