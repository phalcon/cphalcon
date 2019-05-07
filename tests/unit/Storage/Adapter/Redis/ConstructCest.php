<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Storage\Adapter\Redis;

use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;
use function getOptionsRedis;

class ConstructCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-09
     */
    public function storageAdapterRedisConstruct(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - __construct()');

        $serializer = new SerializerFactory();
        $adapter    = new Redis($serializer, getOptionsRedis());

        $class = Redis::class;
        $I->assertInstanceOf($class, $adapter);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
