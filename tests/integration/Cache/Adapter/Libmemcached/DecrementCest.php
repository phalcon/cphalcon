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

namespace Phalcon\Tests\Integration\Cache\Adapter\Libmemcached;

use IntegrationTester;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as HelperException;
use Phalcon\Tests\Fixtures\Traits\LibmemcachedTrait;

use function getOptionsLibmemcached;

class DecrementCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: decrement()
     */
    /**
     * @param IntegrationTester $I
     *
     * @throws Exception
     * @throws HelperException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageAdapterLibmemcachedDecrement(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - decrement()');

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

        $key    = uniqid();
        $actual = $adapter->set($key, 100);
        $I->assertTrue($actual);

        $expected = 99;
        $actual   = $adapter->decrement($key);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        $expected = 90;
        $actual   = $adapter->decrement($key, 9);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        /**
         * unknown key
         */
        $key    = uniqid();
        $actual = $adapter->decrement($key);
        $I->assertFalse($actual);
    }
}
