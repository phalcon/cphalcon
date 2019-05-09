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

namespace Phalcon\Test\Unit\Storage\Adapter\Libmemcached;

use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;
use function getOptionsLibmemcached;

class GetPrefixCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: getPrefix()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterLibmemcachedGetSetPrefix(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - getPrefix()');

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached(
            $serializer,
            array_merge(
                getOptionsLibmemcached(),
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
     * Tests Phalcon\Storage\Adapter\Libmemcached :: getPrefix() - default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterLibmemcachedGetSetPrefixDefault(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - getPrefix() - default');

        $serializer = new SerializerFactory();
        $adapter    = new Libmemcached($serializer, getOptionsLibmemcached());

        $expected = 'ph-memc-';
        $actual   = $adapter->getPrefix();
        $I->assertEquals($expected, $actual);
    }
}
