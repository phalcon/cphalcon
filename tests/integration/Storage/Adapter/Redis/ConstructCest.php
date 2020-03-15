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

use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use IntegrationTester;

use function getOptionsRedis;

class ConstructCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-09
     */
    public function storageAdapterRedisConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - __construct()');

        $serializer = new SerializerFactory();

        $adapter = new Redis(
            $serializer,
            getOptionsRedis()
        );

        $I->assertInstanceOf(
            Redis::class,
            $adapter
        );

        $I->assertInstanceOf(
            AdapterInterface::class,
            $adapter
        );
    }
}
