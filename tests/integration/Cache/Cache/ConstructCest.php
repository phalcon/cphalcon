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

namespace Phalcon\Tests\Integration\Cache\Cache;

use IntegrationTester;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Storage\SerializerFactory;
use Psr\SimpleCache\CacheInterface;

class ConstructCest
{
    /**
     * Tests Phalcon\Cache :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cacheCacheConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Cache - __construct()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $options    = [
            'defaultSerializer' => 'Json',
            'lifetime'          => 7200,
        ];

        $instance = $factory->newInstance('apcu', $options);

        $adapter = new Cache($instance);

        $I->assertInstanceOf(Cache::class, $adapter);
        $I->assertInstanceOf(CacheInterface::class, $adapter);
    }
}
