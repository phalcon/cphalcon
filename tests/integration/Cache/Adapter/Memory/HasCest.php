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

class HasCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterMemoryGetSetHas(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - has()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $key = uniqid();

        $I->assertFalse(
            $adapter->has($key)
        );


        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );
    }
}
