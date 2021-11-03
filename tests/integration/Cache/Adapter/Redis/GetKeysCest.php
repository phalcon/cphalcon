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

namespace Phalcon\Tests\Integration\Cache\Adapter\Redis;

use IntegrationTester;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Cache\Exception as CacheException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as HelperException;
use Phalcon\Tests\Fixtures\Traits\RedisTrait;

use function getOptionsRedis;

class GetKeysCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: getKeys()
     *
     * @param IntegrationTester $I
     *
     * @throws HelperException
     * @throws CacheException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterRedisGetKeys(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - getKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $I->assertTrue($adapter->clear());

        $adapter->set('key-1', 'test');
        $adapter->set('key-2', 'test');
        $adapter->set('one-1', 'test');
        $adapter->set('one-2', 'test');

        $actual = $adapter->has('key-1');
        $I->assertTrue($actual);
        $actual = $adapter->has('key-2');
        $I->assertTrue($actual);
        $actual = $adapter->has('one-1');
        $I->assertTrue($actual);
        $actual = $adapter->has('one-2');
        $I->assertTrue($actual);

        $expected = [
            'ph-reds-key-1',
            'ph-reds-key-2',
            'ph-reds-one-1',
            'ph-reds-one-2',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);

        $expected = [
            'ph-reds-one-1',
            'ph-reds-one-2',
        ];
        $actual   = $adapter->getKeys("one");
        sort($actual);
        $I->assertEquals($expected, $actual);
    }
}
