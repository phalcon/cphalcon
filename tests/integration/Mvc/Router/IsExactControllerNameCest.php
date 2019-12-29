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

namespace Phalcon\Test\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Mvc\Router;

class IsExactControllerNameCest
{
    /**
     * Tests Phalcon\Mvc\Router :: isExactControllerName()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-04
     */
    public function mvcRouterIsExactControllerName(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - isExactControllerName()');

        $router = new Router(false);

        $I->assertTrue(
            $router->isExactControllerName()
        );
    }
}
