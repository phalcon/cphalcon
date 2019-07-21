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

namespace Phalcon\Test\Unit\Cache\Adapter\Memory;

use Phalcon\Cache\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class DecrementCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: decrement()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
