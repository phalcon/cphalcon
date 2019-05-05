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

use function getOptionsRedis;
use Phalcon\Cache\Adapter\Redis;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

/**
 * Class GetPrefixCest
 */
class GetPrefixCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: getPrefix()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterRedisGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - getPrefix()');
        $factory = new SerializerFactory();
        $adapter = new Redis(
            $factory,
            array_merge(
                $this->getOptions(),
                [
                    'prefix' => 'my-prefix',
                ]
            )
        );

        $expected = 'my-prefix';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Redis :: getPrefix() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterRedisGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Redis - getPrefix() - default');
        $factory = new SerializerFactory();
        $adapter = new Redis($factory, getOptionsRedis());

        $expected = 'ph-reds-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
