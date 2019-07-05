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

use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache;
use Phalcon\Cache\Exception\InvalidArgumentException;
use Phalcon\Storage\SerializerFactory;
use function uniqid;
use UnitTester;

class HasCest
{
    /**
     * Tests Phalcon\Cache :: has()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheHas(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - has()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('apcu');

        $adapter = new Cache($instance);

        $key = uniqid();

        $I->assertFalse(
            $adapter->has($key)
        );

        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );
    }

    /**
     * Tests Phalcon\Cache :: has() - exception
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
                $serializer = new SerializerFactory();
                $factory    = new AdapterFactory($serializer);
                $instance   = $factory->newInstance('apcu');

                $adapter = new Cache($instance);

                $value = $adapter->has('abc$^');
            }
        );
    }
}
