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

use Phalcon\Cache;
use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class GetAdapterCest
{
    /**
     * Tests Phalcon\Cache :: getAdapter()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - getAdapter()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $instance   = $factory->newInstance('apcu');

        $adapter = new Cache($instance);

        $I->assertInstanceOf(
            AdapterInterface::class,
            $adapter->getAdapter()
        );
    }
}
