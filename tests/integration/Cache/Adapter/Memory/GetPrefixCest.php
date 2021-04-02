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

class GetPrefixCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Memory :: getPrefix()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterMemoryGetSetPrefix(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - getPrefix()');

        $serializer = new SerializerFactory();

        $adapter = new Memory(
            $serializer,
            [
                'prefix' => 'my-prefix',
            ]
        );

        $I->assertEquals(
            'my-prefix',
            $adapter->getPrefix()
        );
    }

    /**
     * Tests Phalcon\Cache\Adapter\Memory :: getPrefix() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-31
     */
    public function cacheAdapterMemoryGetSetPrefixDefault(IntegrationTester $I)
    {
        $I->wantToTest('Cache\Adapter\Memory - getPrefix() - default');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $I->assertEquals(
            'ph-memo-',
            $adapter->getPrefix()
        );
    }
}
