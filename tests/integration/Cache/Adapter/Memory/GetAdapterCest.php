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

namespace Phalcon\Test\Integration\Cache\Adapter\Memory;

use Phalcon\Cache\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use IntegrationTester;

class GetAdapterCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: getAdapter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-14
     */
    public function cacheAdapterMemoryGetAdapter(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - getAdapter()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $I->assertNull(
            $adapter->getAdapter()
        );
    }
}
