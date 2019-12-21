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

namespace Phalcon\Test\Unit\Storage\Adapter\Redis;

use Phalcon\Storage\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function getOptionsRedis;

class GetSetDefaultSerializerCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Redis ::
     * getDefaultSerializer()/setDefaultSerializer()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-13
     */
    public function storageAdapterRedisGetKeys(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - getDefaultSerializer()/setDefaultSerializer()');

        $serializer = new SerializerFactory();

        $adapter = new Redis(
            $serializer,
            getOptionsRedis()
        );

        $I->assertEquals(
            'Php',
            $adapter->getDefaultSerializer()
        );

        $adapter->setDefaultSerializer('Base64');

        $I->assertEquals(
            'Base64',
            $adapter->getDefaultSerializer()
        );
    }
}
