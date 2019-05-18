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

namespace Phalcon\Test\Unit\Cache\Adapter\Libmemcached;

use function getOptionsLibmemcached;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;

class GetKeysCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: getKeys()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-13
     */
    public function cacheAdapterLibmemcachedGetKeys(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - getKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached($serializer, getOptionsLibmemcached());

        $I->assertTrue(
            $adapter->clear()
        );

        $key = 'key-1';
        $adapter->set($key, 'test');
        $I->assertTrue(
            $adapter->has($key)
        );

        $key = 'key-2';
        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );

        $expected = [
            'ph-memc-key-1',
            'ph-memc-key-2',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);
    }
}
