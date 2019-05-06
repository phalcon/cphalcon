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
 * Class HasCest
 */
class HasCest
{
    /**
     * Tests Phalcon\Cache\Cache :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheHas(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - has()');

        $adapter = new Cache(new Apcu());

        $key = uniqid();

        $actual = $adapter->has($key);
        $I->assertFalse($actual);

        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Cache\Cache :: has() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheHasException(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - has() - exception');

        $I->expectThrowable(
            new InvalidArgumentException('The key contains invalid characters'),
            function () {
                $adapter = new Cache(new Apcu());
                $value   = $adapter->has('abc$^');
            }
        );
    }
}
