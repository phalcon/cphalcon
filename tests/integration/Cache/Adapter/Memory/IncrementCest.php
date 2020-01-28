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

class IncrementCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: increment()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterMemoryIncrement(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - increment()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key = 'cache-data';

        $I->assertTrue(
            $adapter->set($key, 1)
        );

        $expected = 2;

        $I->assertEquals(
            $expected,
            $adapter->increment($key)
        );

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );

        $expected = 10;

        $I->assertEquals(
            $expected,
            $adapter->increment($key, 8)
        );

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );
    }
}
