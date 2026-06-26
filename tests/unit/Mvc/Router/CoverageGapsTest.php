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
use Phalcon\Mvc\Router\Exception;
use Phalcon\Mvc\Router\Route;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;
use PHPUnit\Framework\Attributes\BackupGlobals;

#[BackupGlobals(true)]
final class CoverageGapsTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * Converter applied to a captured value during handle(). Exercises the
     * `if (is_array($converters) && isset($converters[$part]))` branch
     * inside the matched-position arm of the main loop.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testConverterAppliedToMatchedValue(): void
    {
        $router = $this->getRouter(false);
        $router->add('/users/{id:[0-9]+}', ['controller' => 'users', 'id' => 1])
            ->convert('id', static fn(string $v): int => (int) $v * 2);

        $router->handle('/users/21');

        $params = $router->getParams();
        $this->assertSame(42, $params['id']);
    }

    /**
     * Converter is applied to a positional default when the regex did not
     * capture the value (the position is in `paths` but absent from
     * `$matches`). Exercises the converter branch under the `else` arm.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testConverterAppliedToPositionalDefault(): void
    {
        $router = $this->getRouter(false);
        $router->add('/items/{slug:[a-z-]+}', ['controller' => 'items', 'tag' => 99])
            ->convert('tag', static fn(int $v): string => 'tag-' . $v);

        $router->handle('/items/widget');

        $params = $router->getParams();
        $this->assertSame('tag-99', $params['tag']);
    }

    /**
     * Route::extractNamedParams returns false for an empty pattern.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testExtractNamedParamsEmptyPattern(): void
    {
        $route = new Route('/x');
        $this->assertFalse($route->extractNamedParams(''));
    }

    /**
     * extractNamedParams: regex metacharacters outside placeholders are
     * escaped to literals (`.`, `+`, `|`, `#`).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testExtractNamedParamsEscapesMetaCharacters(): void
    {
        $route  = new Route('/x');
        $result = $route->extractNamedParams('/foo.bar');

        $this->assertIsArray($result);
        [$compiled] = $result;
        $this->assertStringContainsString('foo\\.bar', $compiled);
    }

    /**
     * extractNamedParams: placeholder containing an illegal character
     * (space) is rejected.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testExtractNamedParamsIllegalChar(): void
    {
        $route  = new Route('/x');
        $result = $route->extractNamedParams('/items/{bad name}');

        $this->assertIsArray($result);
        [$compiled] = $result;
        $this->assertStringContainsString('{bad name}', $compiled);
    }

    /**
     * extractNamedParams: a placeholder whose first character is non-alpha
     * is rejected - the `{1bad}` literal is kept verbatim in the route.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testExtractNamedParamsInvalidFirstChar(): void
    {
        $route   = new Route('/x');
        $result  = $route->extractNamedParams('/items/{1bad}');

        $this->assertIsArray($result);
        [$compiled] = $result;
        $this->assertStringContainsString('{1bad}', $compiled);
    }

    /**
     * extractNamedParams: a placeholder whose regex part is already wrapped
     * in parentheses must not be wrapped again.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testExtractNamedParamsRegexAlreadyParenthesized(): void
    {
        $route  = new Route('/x');
        $result = $route->extractNamedParams('/items/{id:(\\d+)}');

        $this->assertIsArray($result);
        [$compiled, $matches] = $result;
        $this->assertSame(['id' => 1], $matches);
        $this->assertStringContainsString('(\\d+)', $compiled);
    }

    /**
     * getCompiledHostName accepts a pre-delimited regex (`#hostname#`) and
     * returns it verbatim.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testGetCompiledHostNamePreDelimited(): void
    {
        $route = new Route('/api');
        $route->setHostname('#^([a-z]+)\\.example\\.com$#i');

        $this->assertSame('#^([a-z]+)\\.example\\.com$#i', $route->getCompiledHostName());
    }

    /**
     * getRewriteUri returns "/" when neither source has a usable URI.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testGetRewriteUriDefaultsToRoot(): void
    {
        $router = $this->getRouter(true);

        unset($_GET['_url']);
        $router->handle('');

        // Default route does not match "/" alone, so no match - but the
        // codepath through getRewriteUri returning "/" is exercised.
        $this->assertFalse($router->wasMatched());
    }

    /**
     * getRewriteUri reads $_GET["_url"] when uriSource is URI_SOURCE_GET_URL
     * (the default).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testGetRewriteUriReadsGetUrl(): void
    {
        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about']);

        $_GET['_url'] = '/about';
        $router->handle('');

        $this->assertSame('about', $router->getControllerName());
        unset($_GET['_url']);
    }

    /**
     * getRewriteUri reads $_SERVER["REQUEST_URI"] when uriSource is
     * URI_SOURCE_SERVER_REQUEST_URI.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testGetRewriteUriReadsServerRequestUri(): void
    {
        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about']);
        $router->setUriSource(Router::URI_SOURCE_SERVER_REQUEST_URI);

        $_SERVER['REQUEST_URI'] = '/about';
        $router->handle('');

        $this->assertSame('about', $router->getControllerName());
    }

    /**
     * handle() with a query-string-only URI falls back to "/" after
     * extractRealUri returns an empty string. Exercises line 852.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testHandleQueryStringOnlyUriFallsBackToRoot(): void
    {
        $router = $this->getRouter(false);
        $router->add('/', ['controller' => 'home']);

        $router->handle('?foo=bar');

        $this->assertSame('home', $router->getControllerName());
    }

    /**
     * Hostname route in the main loop: HTTP_HOST set, literal hostname match.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testHostnameLiteralMatchInMainLoop(): void
    {
        $router = $this->getRouter(false);
        $router->add('/admin', ['controller' => 'admin'])
            ->setHostname('admin.example.com');

        $_SERVER['HTTP_HOST'] = 'admin.example.com';
        $router->handle('/admin');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('admin', $router->getControllerName());
    }

    /**
     * Hostname route in the main loop with HTTP_HOST mismatching the
     * constraint - route is skipped.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testHostnameLiteralMismatchInMainLoop(): void
    {
        $router = $this->getRouter(false);
        $router->add('/admin', ['controller' => 'admin'])
            ->setHostname('admin.example.com');

        $_SERVER['HTTP_HOST'] = 'www.example.com';
        $router->handle('/admin');

        $this->assertFalse($router->wasMatched());
    }

    /**
     * Hostname regex route matches via preg_match in the main loop.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testHostnameRegexMatchInMainLoop(): void
    {
        $router = $this->getRouter(false);
        $router->add('/api/{action}', ['controller' => 'api'])
            ->setHostname('([a-z]+)\\.example\\.com');

        $_SERVER['HTTP_HOST'] = 'tenant.example.com';
        $router->handle('/api/list');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('list', $router->getActionName());
    }

    /**
     * Hostname route with empty HTTP_HOST (CLI-like environment) - continue.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testHostnameRouteSkippedWhenHttpHostEmpty(): void
    {
        $router = $this->getRouter(false);
        $router->add('/admin', ['controller' => 'admin'])
            ->setHostname('admin.example.com');

        $_SERVER['HTTP_HOST'] = '';
        $router->handle('/admin');

        $this->assertFalse($router->wasMatched());
    }

    /**
     * loadFromConfig throws when 'routes' is not an array.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testLoadFromConfigRoutesNotArrayThrows(): void
    {
        $router = $this->getRouter(false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("'routes' must be an array");

        $router->loadFromConfig(['routes' => 'not-an-array']);
    }

    /**
     * mount() propagates the group's beforeMatch onto each child route.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMountAppliesGroupBeforeMatch(): void
    {
        $router = $this->getRouter(false);
        $group  = new \Phalcon\Mvc\Router\Group();
        $callback = static fn(): bool => false;
        $group->beforeMatch($callback);
        $group->add('/admin', ['controller' => 'admin']);

        $router->mount($group);

        $routes = $router->getRoutes();
        $this->assertSame($callback, end($routes)->getBeforeMatch());
    }

    /**
     * mount() throws when the group has no routes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMountEmptyGroupThrows(): void
    {
        $router = $this->getRouter(false);
        $group  = new \Phalcon\Mvc\Router\Group();

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('The group of routes does not contain any routes');

        $router->mount($group);
    }

    /**
     * mountGroupFromConfig: missing 'paths' throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMountGroupFromConfigMissingPathsThrows(): void
    {
        $router = $this->getRouter(false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Group route entry is missing 'paths'");

        $router->loadFromConfig([
            'groups' => [
                [
                    'prefix' => '/api',
                    'routes' => [
                        ['pattern' => '/users'],
                    ],
                ],
            ],
        ]);
    }

    /**
     * mountGroupFromConfig: missing 'pattern' throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMountGroupFromConfigMissingPatternThrows(): void
    {
        $router = $this->getRouter(false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Group route entry is missing 'pattern'");

        $router->loadFromConfig([
            'groups' => [
                [
                    'prefix' => '/api',
                    'routes' => [
                        ['paths' => ['controller' => 'users']],
                    ],
                ],
            ],
        ]);
    }

    /**
     * mountGroupFromConfig dispatches per the 'method' key (put, trace,
     * purge). Exercises the switch cases for the less-common verbs and
     * verifies the route is registered with the group prefix.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMountGroupFromConfigPutPurgeTraceMethods(): void
    {
        $router = $this->getRouter(false);

        $router->loadFromConfig([
            'groups' => [
                [
                    'prefix' => '/api',
                    'routes' => [
                        ['method' => 'put',   'pattern' => '/p', 'paths' => ['controller' => 'p'], 'name' => 'r_put'],
                        ['method' => 'purge', 'pattern' => '/q', 'paths' => ['controller' => 'q']],
                        ['method' => 'trace', 'pattern' => '/r', 'paths' => ['controller' => 'r']],
                    ],
                ],
            ],
        ]);

        $this->assertNotFalse($router->getRouteByName('r_put'));
    }

    /**
     * mountGroupFromConfig: a group entry without 'routes' as an array throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMountGroupFromConfigRoutesNotArrayThrows(): void
    {
        $router = $this->getRouter(false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Group 'routes' must be an array");

        $router->loadFromConfig([
            'groups' => [
                [
                    'prefix' => '/api',
                    'routes' => 'not-an-array',
                ],
            ],
        ]);
    }

    /**
     * mountGroupFromConfig throws on an unknown HTTP method.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMountGroupFromConfigUnknownMethodThrows(): void
    {
        $router = $this->getRouter(false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Unknown HTTP method 'bogus'");

        $router->loadFromConfig([
            'groups' => [
                [
                    'prefix' => '/api',
                    'routes' => [
                        ['method' => 'bogus', 'pattern' => '/x', 'paths' => ['controller' => 'x']],
                    ],
                ],
            ],
        ]);
    }

    /**
     * notFoundPaths fallback is used when no route matches.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testNotFoundPathsFallback(): void
    {
        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about']);
        $router->notFound([
            'controller' => 'errors',
            'action'     => 'notFound',
        ]);

        $router->handle('/nonexistent');

        // wasMatched is false (per current contract), but the not-found
        // paths populate the controller/action.
        $this->assertSame('errors', $router->getControllerName());
        $this->assertSame('notFound', $router->getActionName());
    }

    /**
     * paths entry with a non-string non-int position is silently skipped
     * (the `continue` at the `position` typecheck branch in handle()).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testPathsEntryWithNonScalarPositionIsSkipped(): void
    {
        $router = $this->getRouter(false);
        $router->add(
            '/widgets/{id:[0-9]+}',
            ['controller' => 'widgets', 'extra' => ['nested' => 'value']]
        );

        $router->handle('/widgets/7');

        $params = $router->getParams();
        // The non-scalar 'extra' position is skipped - but stays in $parts
        // (the foreach `continue` doesn't unset it).
        $this->assertSame(['nested' => 'value'], $params['extra']);
    }

    /**
     * Route::getRoutePaths() with single-token string syntax (controller only).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testRoutePathsControllerOnlyString(): void
    {
        $paths = Route::getRoutePaths('Users');

        $this->assertSame('Users', $paths['controller']);
        $this->assertArrayNotHasKey('action', $paths);
        $this->assertArrayNotHasKey('module', $paths);
    }

    /**
     * Route::getRoutePaths() with Module::Controller::Action string syntax.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testRoutePathsModuleControllerActionString(): void
    {
        $paths = Route::getRoutePaths('Backend::Users::index');

        $this->assertSame('Backend', $paths['module']);
        $this->assertSame('Users', $paths['controller']);
        $this->assertSame('index', $paths['action']);
    }

    /**
     * Route::getRoutePaths() with a namespaced controller name extracts the
     * namespace and the bare class.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testRoutePathsNamespacedController(): void
    {
        $paths = Route::getRoutePaths('App\\Controllers\\Users::index');

        $this->assertSame('App\\Controllers', $paths['namespace']);
        $this->assertSame('Users', $paths['controller']);
        $this->assertSame('index', $paths['action']);
    }

    /**
     * setUriSource is a setter - exercise it for coverage.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testSetUriSourceReturnsRouter(): void
    {
        $router = $this->getRouter(false);
        $result = $router->setUriSource(Router::URI_SOURCE_SERVER_REQUEST_URI);

        $this->assertSame($router, $result);
    }
}
