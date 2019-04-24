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

namespace Phalcon\Test\Unit\Cache\Adapter\Redis;

use Phalcon\Cache\Adapter\Redis;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

/**
 * Class DecrementCest
 */
class DecrementCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: decrement()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterRedisDecrement(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - decrement()');
        $I->skipTest('Check this');
        $adapter = new Redis($this->getOptions());

        $key    = uniqid();
        $result = $adapter->set($key, 100);
        $I->assertTrue($result);

        $expected = 99;
        $actual   = $adapter->decrement($key);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        $expected = 90;
        $actual   = $adapter->decrement($key, 9);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }
}
