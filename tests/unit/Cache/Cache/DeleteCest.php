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
 * Class DeleteCest
 */
class DeleteCest
{
    /**
     * Tests Phalcon\Cache\Cache :: delete()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheDelete(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - delete()');

        $adapter = new Cache(new Apcu());

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $I->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key1);
        $I->assertTrue($actual);

        $actual = $adapter->has($key1);
        $I->assertFalse($actual);
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Cache\Cache :: delete() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheDeleteException(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - delete() - exception');

        $I->expectThrowable(
            new InvalidArgumentException('The key contains invalid characters'),
            function () {
                $adapter = new Cache(new Apcu());
                $value   = $adapter->delete('abc$^');
            }
        );
    }
}
