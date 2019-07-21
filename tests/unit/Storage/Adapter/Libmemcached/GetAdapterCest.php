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

use Memcached;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;
use function getOptionsLibmemcached;

class GetAdapterCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: getAdapter()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-14
     */
    public function storageAdapterLibmemcachedGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Libmemcached - getAdapter()');

        $serializer = new SerializerFactory();

        $adapter = new Libmemcached(
            $serializer,
            getOptionsLibmemcached()
        );

        $I->assertInstanceOf(
            Memcached::class,
            $adapter->getAdapter()
        );
    }
}
