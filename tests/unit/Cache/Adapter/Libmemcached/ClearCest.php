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

use Exception;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;
use function getOptionsLibmemcached;

/**
 * Class ClearCest
 */
class ClearCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: clear()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2019-03-31
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function cacheAdapterLibmemcachedClear(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - clear()');
        $factory = new SerializerFactory();
        $adapter = new Libmemcached($factory, getOptionsLibmemcached());

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $I->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);

        $actual = $adapter->clear();
        $I->assertTrue($actual);

        $actual = $adapter->has($key1);
        $I->assertFalse($actual);

        $actual = $adapter->has($key2);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: clear() - twice
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2019-03-31
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function cacheAdapterLibmemcachedClearTwice(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - clear() - twice');
        $factory = new SerializerFactory();
        $adapter = new Libmemcached($factory, getOptionsLibmemcached());

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $I->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);

        $actual = $adapter->clear();
        $I->assertTrue($actual);

        $actual = $adapter->clear();
        $I->assertTrue($actual);
    }
}
