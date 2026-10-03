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

namespace Phalcon\Tests\Unit\Mvc\Router\Route;

use Phalcon\Mvc\Router\Route;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetIndexDataTest extends AbstractUnitTestCase
{
    /**
     * getIndexData() returns the values of the six getters, in order.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    public function testMvcRouterRouteGetIndexData(): void
    {
        $route = new Route('/users/{id:[0-9]+}', ['controller' => 'users'], ['GET', 'POST']);

        $actual = $route->getIndexData();

        $this->assertSame(
            [
                ['GET', 'POST'],
                '#^/users/([0-9]+)$#u',
                null,
                null,
                null,
                $route->getRouteId(),
            ],
            $actual
        );
    }

    /**
     * getIndexData() returns the compiled host name and the beforeMatch
     * callback, and the compiled host name stays in the route.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-03
     */
    public function testMvcRouterRouteGetIndexDataWithHostnameAndBeforeMatch(): void
    {
        $callback = static fn (): bool => true;
        $route    = new Route('/about', ['controller' => 'about']);
        $route->setHostname('([a-z]+).example.com');
        $route->beforeMatch($callback);

        $actual = $route->getIndexData();

        $this->assertSame(
            [
                null,
                '/about',
                '([a-z]+).example.com',
                '#^([a-z]+).example.com(:[[:digit:]]+)?$#i',
                $callback,
                $route->getRouteId(),
            ],
            $actual
        );
        $this->assertSame($actual[3], $route->getCompiledHostName());
    }
}
