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

/**
 * Class GetRoutePathsCest
 */
class GetRoutePathsCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: getRoutePaths()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterRouteGetRoutePaths(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Route - getRoutePaths()');

        $arrayDefinition = ["controller" => 'FooBar', "action" => 'baz'];
        $stringDefinition = "FooBar::baz";

        $I->assertEquals($arrayDefinition, Route::getRoutePaths($arrayDefinition));
        $I->assertEquals($arrayDefinition, Route::getRoutePaths($stringDefinition));
    }
}
