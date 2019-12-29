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

namespace Phalcon\Test\Unit\Cache\Adapter\Redis;

use Phalcon\Cache\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

use function getOptionsRedis;

class GetPrefixCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: getPrefix()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterRedisGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - getPrefix()');

        $serializer = new SerializerFactory();
        $adapter    = new Redis(
            $serializer,
            array_merge(
                getOptionsRedis(),
                [
                    'prefix' => 'my-prefix',
                ]
            )
        );

        $expected = 'my-prefix';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: getPrefix() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterRedisGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - getPrefix() - default');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $expected = 'ph-reds-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
