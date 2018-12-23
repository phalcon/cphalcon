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

namespace Phalcon\Test\Unit\Cache\Backend\Redis;

use Phalcon\Cache\Backend\Redis;
use Phalcon\Cache\BackendInterface;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Backend\Redis :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendRedisConstruct(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Redis - __construct()');
        $cache  = new Redis(new Data(['lifetime' => 20]), $this->options);
        $class  = BackendInterface::class;
        $actual = $cache;
        $I->assertInstanceOf($class, $actual);
    }
}
