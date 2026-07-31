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

use Phalcon\ADR\Exceptions\ActionDirectoryNotSet;
use Phalcon\ADR\Exceptions\MethodNotAllowed;
use Phalcon\ADR\Middleware\TimingMiddleware;
use Phalcon\ADR\Router\Router;
use Phalcon\Contracts\ADR\Router\RouterMatch;
use Phalcon\Http\Request;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class MatchTest extends AbstractUnitTestCase
{
    private const BASE      = 'Phalcon\\Tests\\Support\\ADR\\Action';
    private const DIRECTORY = PATH_SUPPORT . 'ADR/Action';

    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() ignores the fused
     * operation form - nothing can be shadowed
     *
     * `Posts\GetPostsArchive` exists but there is no `Posts/Archive` directory,
     * so `archive` is a positional attribute of `GetPosts`. The class is
     * unreachable, and that is the guarantee: only the namespace decides.
     */
    public function testAdrRouterRouterMatchIgnoresFusedOperationForm(): void
    {
        $_SERVER['REQUEST_URI']    = '/posts/archive';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $match = $router->match(new Request());

        $this->assertInstanceOf(RouterMatch::class, $match);
        $this->assertSame(self::BASE . '\\Posts\\GetPosts', $match->getAction());
        $this->assertSame([0 => 'archive'], $match->getAttributes());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() resolves a class + positional attributes
     */
    public function testAdrRouterRouterMatchResolvesByConvention(): void
    {
        $_SERVER['REQUEST_URI']    = '/posts/42';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $match = $router->match(new Request());

        $this->assertInstanceOf(RouterMatch::class, $match);
        $this->assertSame(self::BASE . '\\Posts\\GetPosts', $match->getAction());
        $this->assertSame([0 => '42'], $match->getAttributes());
        $this->assertSame([], $match->getMiddleware());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() concatenates every static
     * segment into the class name
     */
    public function testAdrRouterRouterMatchResolvesNestedNamespace(): void
    {
        $_SERVER['REQUEST_URI']    = '/reports/daily';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $match = $router->match(new Request());

        $this->assertInstanceOf(RouterMatch::class, $match);
        $this->assertSame(
            self::BASE . '\\Reports\\Daily\\GetReportsDaily',
            $match->getAction()
        );
        $this->assertSame([], $match->getAttributes());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() resolves the root Action
     */
    public function testAdrRouterRouterMatchResolvesRootAction(): void
    {
        $_SERVER['REQUEST_URI']    = '/';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $match = $router->match(new Request());

        $this->assertInstanceOf(RouterMatch::class, $match);
        $this->assertSame(self::BASE . '\\Get', $match->getAction());
        $this->assertSame([], $match->getAttributes());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() returns null (404) when nothing matches
     */
    public function testAdrRouterRouterMatchReturnsNull(): void
    {
        $_SERVER['REQUEST_URI']    = '/nope';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

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
            ->setActionDirectory(self::DIRECTORY)
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

        $router = (new Router())
            ->setBaseNamespace(self::BASE)
            ->setActionDirectory(self::DIRECTORY);

        $this->expectException(MethodNotAllowed::class);

        $router->match(new Request());
    }

    /**
     * Unit Tests Phalcon\ADR\Router\Router :: match() throws when no action directory is set
     */
    public function testAdrRouterRouterMatchThrowsWithoutActionDirectory(): void
    {
        $_SERVER['REQUEST_URI']    = '/posts';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $router = (new Router())->setBaseNamespace(self::BASE);

        $this->expectException(ActionDirectoryNotSet::class);
        $this->expectExceptionMessage(
            'No action directory set; call setActionDirectory().'
        );

        $router->match(new Request());
    }
}
