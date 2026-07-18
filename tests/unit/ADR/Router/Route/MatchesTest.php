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

namespace Phalcon\Tests\Unit\ADR\Router\Route;

use Phalcon\ADR\Router\Route;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class MatchesTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Router\Route :: matches() extracts named parameters
     */
    public function testAdrRouterRouteMatchesExtractsParameters(): void
    {
        $route = new Route('/posts/{id}', 'ShowAction', ['GET']);

        $this->assertSame(['id' => '42'], $route->matches('/posts/42'));
        $this->assertFalse($route->matches('/users/42'));
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Route :: matches() honors a regex constraint
     */
    public function testAdrRouterRouteMatchesHonorsConstraint(): void
    {
        $route = new Route('/posts/{id:[0-9]+}', 'ShowAction', ['GET']);

        $this->assertSame(['id' => '42'], $route->matches('/posts/42'));
        $this->assertFalse($route->matches('/posts/abc'));
    }
}
