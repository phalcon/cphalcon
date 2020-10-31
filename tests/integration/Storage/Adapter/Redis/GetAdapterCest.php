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

namespace Phalcon\Test\Integration\Storage\Adapter\Redis;

use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use IntegrationTester;

use function getOptionsRedis;

class GetAdapterCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: getAdapter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-14
     */
    public function storageAdapterRedisGetAdapter(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - getAdapter()');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $class  = \Redis::class;
        $actual = $adapter->getAdapter();
        $I->assertInstanceOf($class, $actual);
    }
}
