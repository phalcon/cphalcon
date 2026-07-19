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

namespace Phalcon\Tests\Unit\ADR\Router\Router;

use Phalcon\ADR\Exceptions\MethodNotAllowed;
use Phalcon\ADR\Middleware\TimingMiddleware;
use Phalcon\ADR\Router\Router;
use Phalcon\Contracts\ADR\Router\RouterMatch;
use Phalcon\Http\Request;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class MatchTest extends AbstractUnitTestCase
{
    private const BASE = 'Phalcon\\Tests\\Support\\ADR\\Action';

    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() resolves a class + positional attributes
     */
    public function testAdrRouterRouterMatchResolvesByConvention(): void
    {
        $_SERVER['REQUEST_URI']    = '/posts/42';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())->setBaseNamespace(self::BASE);

        $match = $router->match(new Request());

        $this->assertInstanceOf(RouterMatch::class, $match);
        $this->assertSame(self::BASE . '\\Posts\\GetPosts', $match->getAction());
        $this->assertSame([0 => '42'], $match->getAttributes());
        $this->assertSame([], $match->getMiddleware());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() returns null (404) when nothing matches
     */
    public function testAdrRouterRouterMatchReturnsNull(): void
    {
        $_SERVER['REQUEST_URI']    = '/nope';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())->setBaseNamespace(self::BASE);

        $this->assertNull($router->match(new Request()));
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() stacks namespace-prefix middleware
     */
    public function testAdrRouterRouterMatchStacksNamespaceMiddleware(): void
    {
        $_SERVER['REQUEST_URI']    = '/admin';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setMiddlewareMap(['\\Admin\\' => [TimingMiddleware::class]]);

        $match = $router->match(new Request());

        $this->assertSame(self::BASE . '\\Admin\\GetAdmin', $match->getAction());
        $this->assertSame([TimingMiddleware::class], $match->getMiddleware());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() throws 405 when the path exists under another verb
     */
    public function testAdrRouterRouterMatchThrowsMethodNotAllowed(): void
    {
        $_SERVER['REQUEST_URI']    = '/posts/42';
        $_SERVER['REQUEST_METHOD'] = 'DELETE';

        $router = (new Router())->setBaseNamespace(self::BASE);

        $this->expectException(MethodNotAllowed::class);

        $router->match(new Request());
    }
}
