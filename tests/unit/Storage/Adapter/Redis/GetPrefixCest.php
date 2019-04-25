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

namespace Phalcon\Test\Unit\Storage\Adapter\Redis;

use Phalcon\Storage\Adapter\Redis;
use Phalcon\Test\Fixtures\Traits\RedisTrait;
use UnitTester;

/**
 * Class GetPrefixCest
 */
class GetPrefixCest
{
    use RedisTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Redis :: getPrefix()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterRedisGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - getPrefix()');
        $adapter = new Redis(
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
     * Tests Phalcon\Storage\Adapter\Redis :: getPrefix() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterRedisGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Redis - getPrefix() - default');
        $adapter = new Redis($this->getOptions());

        $expected = 'ph-reds-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
