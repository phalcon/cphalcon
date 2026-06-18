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

use Phalcon\Mvc\Router\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;
use PHPUnit\Framework\Attributes\BackupGlobals;

use function cacheDir;
use function file_put_contents;
use function glob;
use function uniqid;
use function unlink;

#[BackupGlobals(true)]
final class CachedDispatcherTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testBuildDumpHasVersionAndRoutesData(): void
    {
        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about']);

        $dump = $router->buildDispatcherDump();

        $this->assertSame(1, $dump['version']);
        $this->assertCount(1, $dump['routes']);
        $this->assertSame('/about', $dump['routes'][0]['pattern']);
        $this->assertSame(['controller' => 'about'], $dump['routes'][0]['paths']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testBuildDumpIncludesAllIndexKeys(): void
    {
        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about']);

        $dump = $router->buildDispatcherDump();

        foreach (
            [
            'version', 'routes',
            'methodRoutes', 'candidatesByMethod',
            'staticByMethod', 'staticShadowedByMethod',
            'hostnameByMethod', 'hostnameLessByMethod',
            'combinedRegexByMethod', 'combinedRegexDisabled', 'combinedRegexMarkMap',
            'routeMeta',
            ] as $key
        ) {
            $this->assertArrayHasKey($key, $dump, "dump missing key: $key");
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testBuildDumpStoresRouteIndicesNotObjects(): void
    {
        $router = $this->getRouter(false);
        $router->addGet('/users', ['controller' => 'users', 'action' => 'index']);
        $router->addPost('/users', ['controller' => 'users', 'action' => 'create']);

        $dump = $router->buildDispatcherDump();

        $this->assertIsInt($dump['methodRoutes']['GET'][0]);
        $this->assertIsInt($dump['methodRoutes']['POST'][0]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testBuildDumpStoresRouteClassName(): void
    {
        $router = $this->getRouter(false);
        $router->add('/about', ['controller' => 'about']);

        $dump = $router->buildDispatcherDump();

        $this->assertSame('Phalcon\\Mvc\\Router\\Route', $dump['routes'][0]['class']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testBuildDumpRejectsClosureBeforeMatch(): void
    {
        $router = $this->getRouter(false);
        $router->add('/admin', ['controller' => 'admin'])
            ->beforeMatch(static fn(): bool => false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/Closure beforeMatch/i');

        $router->buildDispatcherDump();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testBuildDumpRejectsClosureConverter(): void
    {
        $router = $this->getRouter(false);
        $router->add('/users/{id}', ['controller' => 'users'])
            ->convert('id', static fn(string $v): int => (int) $v);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/Closure converter/i');

        $router->buildDispatcherDump();
    }

    /**
     * Static-string callable (e.g., 'App\\Auth::check') and array-callable
     * ([class, 'method']) are both var_export-able and must NOT trigger
     * the closure veto.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testBuildDumpAllowsStringAndArrayCallables(): void
    {
        $router = $this->getRouter(false);
        $router->add('/x', ['controller' => 'x'])
            ->beforeMatch('intval');
        $router->add('/y', ['controller' => 'y'])
            ->beforeMatch(['Phalcon\\Tests\\Unit\\Mvc\\Router\\CachedDispatcherTest', 'fakeCallable']);

        $dump = $router->buildDispatcherDump();

        $this->assertSame('intval', $dump['routes'][0]['beforeMatch']);
        $this->assertSame(
            ['Phalcon\\Tests\\Unit\\Mvc\\Router\\CachedDispatcherTest', 'fakeCallable'],
            $dump['routes'][1]['beforeMatch']
        );
    }

    /**
     * Full round-trip: dump - fresh router - load - assert same match
     * behavior as the original.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testRoundTripPreservesMatchBehavior(): void
    {
        $original = $this->getRouter(false);
        $original->addGet('/users/{id:[0-9]+}', ['controller' => 'users', 'action' => 'show']);
        $original->add('/about', ['controller' => 'about', 'action' => 'index']);

        $dump = $original->buildDispatcherDump();

        $restored = $this->getRouter(false);
        $restored->loadDispatcherFromArray($dump);

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $restored->handle('/users/42');
        $this->assertSame('users', $restored->getControllerName());
        $this->assertSame('show', $restored->getActionName());

        $restored->handle('/about');
        $this->assertSame('about', $restored->getControllerName());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testRoundTripPreservesRouteIds(): void
    {
        $original   = $this->getRouter(false);
        $route      = $original->add('/about', ['controller' => 'about']);
        $originalId = $route->getRouteId();

        $dump     = $original->buildDispatcherDump();
        $restored = $this->getRouter(false);
        $restored->loadDispatcherFromArray($dump);

        $routes = $restored->getRoutes();
        $this->assertSame($originalId, $routes[0]->getRouteId());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testRoundTripPreservesRouteNames(): void
    {
        $original = $this->getRouter(false);
        $original->add('/about', ['controller' => 'about'])->setName('homepage');

        $restored = $this->getRouter(false);
        $restored->loadDispatcherFromArray($original->buildDispatcherDump());

        $byName = $restored->getRouteByName('homepage');
        $this->assertNotFalse($byName);
        $this->assertSame('/about', $byName->getPattern());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testRoundTripPreservesCombinedRegexFastPath(): void
    {
        $original = $this->getRouter(false);
        $original->add('/users/{id:[0-9]+}', ['controller' => 'users']);
        $original->add('/products/{slug:[a-z-]+}', ['controller' => 'products']);

        $restored = $this->getRouter(false);
        $restored->loadDispatcherFromArray($original->buildDispatcherDump());

        $restored->handle('/users/42');
        $this->assertSame('users', $restored->getControllerName());

        $restored->handle('/products/widget');
        $this->assertSame('products', $restored->getControllerName());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testLoadRejectsMissingVersion(): void
    {
        $router = $this->getRouter(false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/version/i');

        $router->loadDispatcherFromArray(['routes' => []]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testLoadRejectsUnsupportedVersion(): void
    {
        $router = $this->getRouter(false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/version/i');

        $router->loadDispatcherFromArray(['version' => 99, 'routes' => []]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testRoundTripWithStringBeforeMatchExecutes(): void
    {
        $router = $this->getRouter(false);
        $router->add('/x', ['controller' => 'x'])
            ->beforeMatch([self::class, 'returnTrue']);

        $dump     = $router->buildDispatcherDump();
        $restored = $this->getRouter(false);
        $restored->loadDispatcherFromArray($dump);

        $restored->handle('/x');
        $this->assertTrue($restored->wasMatched());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testFileRoundTripPreservesMatchBehavior(): void
    {
        $path = $this->makeCachePath();

        try {
            $original = $this->getRouter(false);
            $original->addGet('/users/{id:[0-9]+}', ['controller' => 'users', 'action' => 'show']);
            $original->dumpDispatcher($path);

            $this->assertFileExists($path);

            $restored = $this->getRouter(false);
            $restored->loadDispatcher($path);

            $_SERVER['REQUEST_METHOD'] = 'GET';
            $restored->handle('/users/42');
            $this->assertSame('users', $restored->getControllerName());
        } finally {
            @unlink($path);
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testLoadDispatcherThrowsOnMissingFile(): void
    {
        $router = $this->getRouter(false);

        $this->expectException(Exception::class);
        $this->expectExceptionMessageMatches('/not found/i');

        $router->loadDispatcher(cacheDir('_router_nonexistent_' . uniqid('', true) . '.php'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testLoadDispatcherThrowsOnCorruptFile(): void
    {
        $path = $this->makeCachePath();
        file_put_contents($path, "<?php return 'not-an-array';");

        try {
            $router = $this->getRouter(false);

            $this->expectException(Exception::class);
            $this->expectExceptionMessageMatches('/corrupt|invalid|array/i');

            $router->loadDispatcher($path);
        } finally {
            @unlink($path);
        }
    }

    /**
     * The dump file must not be left in a partial state - atomic write
     * via temp + rename. After a successful dump no temp file should remain.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testDumpDispatcherWritesAtomically(): void
    {
        $path = $this->makeCachePath();

        try {
            $router = $this->getRouter(false);
            $router->add('/about', ['controller' => 'about']);
            $router->dumpDispatcher($path);

            $tmps = glob($path . '.tmp.*');
            $this->assertSame([], $tmps);
        } finally {
            @unlink($path);
        }
    }

    public static function fakeCallable(): bool
    {
        return true;
    }

    public static function returnTrue(): bool
    {
        return true;
    }

    private function makeCachePath(): string
    {
        return cacheDir('_router_cache_' . uniqid('', true) . '.php');
    }
}
