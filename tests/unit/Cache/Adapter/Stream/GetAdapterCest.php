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

namespace Phalcon\Test\Unit\Cache\Adapter\Stream;

use Phalcon\Cache\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class GetAdapterCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: getAdapter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function cacheAdapterStreamGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - getAdapter()');

        $serializer = new SerializerFactory();
        $adapter    = new Stream($serializer, ['storageDir' => '/tmp']);

        $actual = $adapter->getAdapter();
        $I->assertNull($actual);
    }
}
