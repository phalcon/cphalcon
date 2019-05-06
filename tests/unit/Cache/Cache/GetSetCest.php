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

namespace Phalcon\Test\Unit\Cache\Cache;

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Cache;
use Phalcon\Cache\Exception\InvalidArgumentException;
use UnitTester;
use function uniqid;

/**
 * Class GetSetCest
 */
class GetSetCest
{
    /**
     * Tests Phalcon\Cache\Cache :: get()/set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheSetGet(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - get()');

        $adapter = new Cache(new Apcu());

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $I->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);

        $expected = 'test';
        $actual   = $adapter->get($key1);
        $I->assertEquals($expected, $actual);

        $expected = 'test';
        $actual   = $adapter->get($key2);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Cache :: get() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheGetSetException(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - get() - exception');

        $I->expectThrowable(
            new InvalidArgumentException('The key contains invalid characters'),
            function () {
                $adapter = new Cache(new Apcu());
                $value   = $adapter->get('abc$^');
            }
        );

        $I->expectThrowable(
            new InvalidArgumentException('The key contains invalid characters'),
            function () {
                $adapter = new Cache(new Apcu());
                $value   = $adapter->set('abc$^', 'test');
            }
        );
    }
}
