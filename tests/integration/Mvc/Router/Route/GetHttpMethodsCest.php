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

namespace Phalcon\Test\Integration\Mvc\Router\Route;

use IntegrationTester;

/**
 * Class GetHttpMethodsCest
 */
class GetHttpMethodsCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: getHttpMethods()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterRouteGetHttpMethods(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - getHttpMethods()');
        $I->skipTest('Need implementation');
    }
}
