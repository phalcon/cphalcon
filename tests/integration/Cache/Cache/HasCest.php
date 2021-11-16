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

namespace Phalcon\Tests\Integration\Cache\Cache;

use IntegrationTester;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Cache\Exception\InvalidArgumentException;
use Phalcon\Storage\SerializerFactory;

use function uniqid;

class HasCest
{
    /**
     * Tests Phalcon\Cache :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cacheCacheHas(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Cache - has()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('apcu');

        $adapter = new Cache($instance);
        $key     = uniqid();

        $I->assertFalse($adapter->has($key));

        $adapter->set($key, 'test');
        $I->assertTrue($adapter->has($key));
    }

    /**
     * Tests Phalcon\Cache :: has() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cacheCacheHasException(IntegrationTester $I)
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
