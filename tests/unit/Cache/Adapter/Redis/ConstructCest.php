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

use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-09
     */
    public function storageAdapterRedisConstruct(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - __construct()');
        $adapter = new Redis($this->getOptions());

        $class = Redis::class;
        $I->assertInstanceOf($class, $adapter);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
