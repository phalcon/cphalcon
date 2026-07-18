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

use Phalcon\ADR\Router\Exceptions\MethodNotAllowed;
use Phalcon\ADR\Router\Router;
use Phalcon\Contracts\ADR\Router\RouterMatch;
use Phalcon\Http\Request;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class MatchTest extends AbstractUnitTestCase
{
    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() returns a match
     */
    public function testAdrRouterRouterMatchReturnsMatch(): void
    {
        $_SERVER['REQUEST_URI']    = '/posts/42';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = new Router();
        $router->get('/posts/{id}', 'ShowAction')->withName('posts.show');

        $match = $router->match(new Request());

        $this->assertInstanceOf(RouterMatch::class, $match);
        $this->assertSame('ShowAction', $match->getAction());
        $this->assertSame(['id' => '42'], $match->getAttributes());
        $this->assertSame('posts.show', $match->getName());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() returns null when nothing matches
     */
    public function testAdrRouterRouterMatchReturnsNull(): void
    {
        $_SERVER['REQUEST_URI']    = '/nope';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = new Router();
        $router->get('/posts/{id}', 'ShowAction');

        $this->assertNull($router->match(new Request()));
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() throws on a method mismatch
     */
    public function testAdrRouterRouterMatchThrowsMethodNotAllowed(): void
    {
        $_SERVER['REQUEST_URI']    = '/posts/42';
        $_SERVER['REQUEST_METHOD'] = 'DELETE';

        $router = new Router();
        $router->get('/posts/{id}', 'ShowAction');

        $this->expectException(MethodNotAllowed::class);

        $router->match(new Request());
    }
}
