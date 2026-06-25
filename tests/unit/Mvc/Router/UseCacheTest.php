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

use Phalcon\Cache\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class UseCacheTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * Cache hit: useCache restores from cache without needing routes added.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testCacheHitRestoresWithoutAddingRoutes(): void
    {
        $cache = $this->newMemoryCache();
        $key   = 'phalcon.router.dispatcher';

        $primer = $this->getRouter(false);
        $primer->add('/about', ['controller' => 'about']);
        $cache->set($key, $primer->buildDispatcherDump());

        $router = $this->getRouter(false);
        $router->useCache($cache, $key);

        $router->handle('/about');

        $this->assertTrue($router->wasMatched());
        $this->assertSame('about', $router->getControllerName());
    }

    /**
     * Cache miss: after handle(), the dispatcher is written to the cache.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testCacheMissPopulatesCacheAfterHandle(): void
    {
        $cache = $this->newMemoryCache();
        $key   = 'phalcon.router.dispatcher';

        $router = $this->getRouter(false);
        $router->useCache($cache, $key);
        $router->add('/about', ['controller' => 'about']);

        $this->assertFalse($cache->has($key));

        $router->handle('/about');

        $this->assertTrue($cache->has($key));
        $stored = $cache->get($key);
        $this->assertIsArray($stored);
        $this->assertSame(1, $stored['version']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testUseCacheUsesDefaultKeyWhenNoneProvided(): void
    {
        $cache = $this->newMemoryCache();

        $router = $this->getRouter(false);
        $router->useCache($cache);
        $router->add('/about', ['controller' => 'about']);
        $router->handle('/about');

        $this->assertTrue($cache->has('phalcon.router.dispatcher'));
    }

    private function newMemoryCache(): Memory
    {
        return new Memory(new SerializerFactory(), ['defaultSerializer' => 'Php']);
    }
}
