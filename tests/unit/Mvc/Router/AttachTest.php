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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class AttachTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/13326
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-03-24
     */
    public function testMvcRouterAttach(): void
    {
        $router = $this->getRouter(false);

        $expected = 0;
        $actual   = $router->getRoutes();
        $this->assertCount($expected, $actual);

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

        $expected = 1;
        $actual   = $router->getRoutes();
        $this->assertCount($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-11-07
     */
    public function testMvcRouterAttachException(): void
    {
        $this->expectException(Router\Exception::class);
        $this->expectExceptionMessage('Invalid route position');

        $router = $this->getRouter(false);
        $router->attach(
            new Route(
                '/about',
                'About::index',
                [
                    'GET',
                    'HEAD',
                ]
            ),
            99
        );
    }
}
