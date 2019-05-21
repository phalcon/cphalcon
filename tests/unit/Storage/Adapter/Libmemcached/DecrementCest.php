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

namespace Phalcon\Test\Unit\Storage\Adapter\Libmemcached;

use function getOptionsLibmemcached;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;

class DecrementCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: decrement()
     *
     * @throws Exception
     * @since  2019-03-31
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function storageAdapterLibmemcachedDecrement(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - decrement()');

        $serializer = new SerializerFactory();

        $adapter = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );



        $key = 'cache-data';

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



        /**
         * unknown key
         */
        $key = 'unknown';

        $I->assertFalse(
            $adapter->decrement($key)
        );
    }
}
