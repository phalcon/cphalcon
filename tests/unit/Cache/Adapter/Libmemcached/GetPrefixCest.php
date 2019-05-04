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

namespace Phalcon\Test\Unit\Cache\Adapter\Libmemcached;

use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;
use function getOptionsLibmemcached;

/**
 * Class GetPrefixCest
 */
class GetPrefixCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: getPrefix()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function cacheAdapterLibmemcachedGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - getPrefix()');
        $factory = new SerializerFactory();
        $adapter = new Libmemcached(
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
     * Tests Phalcon\Cache\Adapter\Libmemcached :: getPrefix() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function cacheAdapterLibmemcachedGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - getPrefix() - default');
        $factory = new SerializerFactory();
        $adapter = new Libmemcached($factory, getOptionsLibmemcached());

        $expected = 'ph-memc-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
