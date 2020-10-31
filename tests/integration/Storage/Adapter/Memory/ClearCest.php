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

namespace Phalcon\Test\Integration\Storage\Adapter\Memory;

use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use IntegrationTester;

class ClearCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Memory :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterMemoryClear(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Memory - clear()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $I->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);

        $actual = $adapter->clear();
        $I->assertTrue($actual);

        $actual = $adapter->has($key1);
        $I->assertFalse($actual);

        $actual = $adapter->has($key2);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Storage\Adapter\Memory :: clear() - twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function storageAdapterMemoryClearTwice(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Memory - clear() - twice');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $I->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);

        $actual = $adapter->clear();
        $I->assertTrue($actual);

        $actual = $adapter->clear();
        $I->assertTrue($actual);
    }
}
