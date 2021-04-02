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

namespace Phalcon\Test\Integration\Storage\Adapter\Stream;

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use IntegrationTester;

class GetAdapterCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: getAdapter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function storageAdapterStreamGetAdapter(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - getAdapter()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => '/tmp',
            ]
        );

        $I->assertNull(
            $adapter->getAdapter()
        );
    }
}
