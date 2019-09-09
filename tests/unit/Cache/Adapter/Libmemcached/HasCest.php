<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Adapter\Libmemcached;

use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;
use function getOptionsLibmemcached;

class HasCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterLibmemcachedGetSetHas(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - has()');

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached($serializer, getOptionsLibmemcached());

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
