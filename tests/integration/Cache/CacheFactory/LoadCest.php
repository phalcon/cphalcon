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

namespace Phalcon\Test\Integration\Cache\CacheFactory;

use Phalcon\Cache;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\CacheFactory;
use Phalcon\Storage\Serializer\None;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use Psr\SimpleCache\CacheInterface;
use IntegrationTester;

class LoadCest
{
    use FactoryTrait;

    public function _before(IntegrationTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Cache\CacheFactory :: load()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function cacheCacheFactoryLoad(IntegrationTester $I)
    {
        $I->wantToTest('Cache\CacheFactory - load()');

        $options = $this->config->cache;
        $this->runTests($I, $options);
    }

    /**
     * Tests Phalcon\Cache\CacheFactory :: load()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-18
     */
    public function cacheCacheFactoryLoadArray(IntegrationTester $I)
    {
        $I->wantToTest('Cache\CacheFactory - load() - array');

        $options = $this->arrayConfig['cache'];
        $this->runTests($I, $options);
    }

    private function runTests(IntegrationTester $I, $options)
    {
        $cacheFactory = new CacheFactory(
            new AdapterFactory(new SerializerFactory())
        );

        $adapter = $cacheFactory->load($options);

        $I->assertInstanceOf(
            Cache::class,
            $adapter
        );

        $I->assertInstanceOf(
            CacheInterface::class,
            $adapter
        );
    }
}
