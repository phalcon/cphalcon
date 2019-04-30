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

use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;
use function getOptionsLibmemcached;

/**
 * Class HasCest
 */
class HasCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterLibmemcachedGetSetHas(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - has()');
        $adapter = new Libmemcached(getOptionsLibmemcached());

        $key = uniqid();

        $actual = $adapter->has($key);
        $I->assertFalse($actual);

        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);
    }
}
