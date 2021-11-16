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

namespace Phalcon\Tests\Integration\Mvc\Router;

use IntegrationTester;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\Fixtures\Traits\RouterTrait;

class AttachCest
{
    use RouterTrait;

    /**
     * Tests Phalcon\Mvc\Router :: attach()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13326
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-03-24
     */
    public function shouldAttachRoute(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router - attach()');

        $router = $this->getRouter(false);


        $I->assertCount(
            0,
            $router->getRoutes()
        );


        $router->attach(
            new Route(
                '/about',
                'About::index',
                [
                    'GET',
                    'HEAD',
                ]
            ),
            Router::POSITION_FIRST
        );


        $I->assertCount(
            1,
            $router->getRoutes()
        );
    }
}
