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

namespace Phalcon\Tests\Integration\Cache\CacheFactory;

use IntegrationTester;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Cache\CacheFactory;
use Phalcon\Cache\Exception\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Cache\CacheInterface;

use function uniqid;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Cache\CacheFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cacheCacheFactoryNewInstance(IntegrationTester $I)
    {
        $I->wantToTest('Cache\CacheFactory - newInstance()');

        $serializer     = new SerializerFactory();
        $adapterFactory = new AdapterFactory($serializer);
        $cacheFactory   = new CacheFactory($adapterFactory);
        $adapter        = $cacheFactory->newInstance('apcu');

        $I->assertInstanceOf(Cache::class, $adapter);
        $I->assertInstanceOf(CacheInterface::class, $adapter);
    }

    /**
     * Tests Phalcon\Cache\CacheFactory :: newInstance() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-03-05
     */
    public function cacheCacheFactoryNewInstanceException(IntegrationTester $I)
    {
        $I->wantToTest('Cache\CacheFactory - newInstance() - exception');

        $name = uniqid();
        $I->expectThrowable(
            new Exception('Service ' . $name . ' is not registered'),
            function () use ($name) {
                $cacheFactory = new CacheFactory(
                    new AdapterFactory(
                        new SerializerFactory()
                    )
                );

                $cacheFactory->newInstance($name);
            }
        );
    }
}
