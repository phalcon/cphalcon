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

namespace Phalcon\Test\Unit\Cache\Adapter\Memory;

use Phalcon\Cache\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class GetAdapterCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: getAdapter()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-14
     */
    public function cacheAdapterMemoryGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - getAdapter()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $I->assertNull(
            $adapter->getAdapter()
        );
    }
}
