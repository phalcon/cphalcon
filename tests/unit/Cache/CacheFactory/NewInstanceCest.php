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

namespace Phalcon\Test\Unit\Cache\CacheFactory;

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Cache;
use Phalcon\Cache\CacheFactory;
use Psr\SimpleCache\CacheInterface;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Cache\CacheFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-03
     */
    public function cacheCacheFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Cache\CacheFactory - newInstance()');

        $factory = new CacheFactory();
        $adapter = $factory->newInstance(new Apcu());

        $class = Cache::class;
        $I->assertInstanceOf($class, $adapter);

        $class = CacheInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
