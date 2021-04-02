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

namespace Phalcon\Test\Integration\Cache\Adapter\Memory;

use Phalcon\Cache\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use IntegrationTester;

class GetKeysCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: getKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-13
     */
    public function cacheAdapterMemoryGetKeys(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - getKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $adapter->clear();


        $key = 'key-1';

        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );


        $key = 'key-2';

        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );


        $expected = [
            'ph-memo-key-1',
            'ph-memo-key-2',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Memory :: GetNoNExistingKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-03-28
     */
    public function cacheAdapterMemoryGetNoNExistingKeys(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - GetNoNExistingKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $adapter->clear();
        $key = 'random-non-existing-key';

        $I->assertNull($adapter->get($key));
        $I->assertEquals(123, $adapter->get($key, 123));
        $I->assertFalse($adapter->get($key, false));
    }
}
