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

namespace Phalcon\Test\Unit\Cache\Adapter\Apcu;

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

class ClearCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: clear()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterApcuClear(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - clear()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key1 = uniqid();
        $key2 = uniqid();


        $adapter->set($key1, 'test');

        $I->assertTrue(
            $adapter->has($key1)
        );


        $adapter->set($key2, 'test');

        $I->assertTrue(
            $adapter->has($key2)
        );

        $I->assertTrue(
            $adapter->clear()
        );

        $I->assertFalse(
            $adapter->has($key1)
        );

        $I->assertFalse(
            $adapter->has($key2)
        );
    }

    /**
     * Tests Phalcon\Cache\Adapter\Apcu :: clear() - twice
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterApcuClearTwice(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Apcu - clear() - twice');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $key1 = uniqid();
        $key2 = uniqid();

        $adapter->set($key1, 'test');

        $I->assertTrue(
            $adapter->has($key1)
        );


        $adapter->set($key2, 'test');

        $I->assertTrue(
            $adapter->has($key2)
        );

        $I->assertTrue(
            $adapter->clear()
        );

        $I->assertTrue(
            $adapter->clear()
        );
    }
}
