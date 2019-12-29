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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

use function outputDir;

class DecrementCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: decrement()
     *
     * @throws Exception
     * @since  2019-04-24
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function storageAdapterStreamDecrement(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - decrement()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'storageDir' => outputDir(),
            ]
        );

        $key = 'cache-data';

        $I->assertTrue(
            $adapter->set($key, 100)
        );

        $expected = 99;

        $I->assertEquals(
            $expected,
            $adapter->decrement($key)
        );

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );

        $expected = 90;
        $I->assertEquals(
            $expected,
            $adapter->decrement($key, 9)
        );

        $I->assertEquals(
            $expected,
            $adapter->get($key)
        );

        /**
         * unknown key
         */
        $key = 'unknown';

        $I->assertFalse(
            $adapter->decrement($key)
        );

        $I->safeDeleteDirectory(outputDir('ph-strm'));
    }
}
