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
use UnitTester;

class DecrementCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: decrement()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterMemoryDecrement(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - decrement()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key = uniqid();

        $I->assertTrue(
            $adapter->set($key, 100)
        );


        $expected = 99;

        $I->assertEquals(
            $expected,
            $adapter->decrement($key)
        );

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );


        $expected = 90;

        $I->assertEquals(
            $expected,
            $adapter->decrement($key, 9)
        );

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );
    }
}
