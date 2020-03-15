<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Storage\Adapter\Libmemcached;

use Memcached;
use Phalcon\Storage\Adapter\Libmemcached;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use IntegrationTester;

use function getOptionsLibmemcached;

class GetAdapterCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Libmemcached :: getAdapter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-14
     */
    public function storageAdapterLibmemcachedGetAdapter(IntegrationTester $I)
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
