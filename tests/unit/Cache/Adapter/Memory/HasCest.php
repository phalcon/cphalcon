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

class HasCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
