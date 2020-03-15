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

use function outputDir;
use function uniqid;

class HasCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-24
     */
    public function storageAdapterStreamHas(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - has()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $key = uniqid();

        $I->assertFalse(
            $adapter->has($key)
        );

        $adapter->set($key, 'test');

        $I->assertTrue(
            $adapter->has($key)
        );
    }
}
