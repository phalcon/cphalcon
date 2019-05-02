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
use Psr\SimpleCache\CacheInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Cache\Cache :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheConstruct(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - __construct()');

        $adapter = new Cache(new Apcu());

        $class = Cache::class;
        $I->assertInstanceOf($class, $adapter);

        $class = CacheInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
