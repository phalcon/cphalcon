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

namespace Phalcon\Test\Unit\Storage\Adapter\Stream;

use function outputDir;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use function uniqid;
use UnitTester;

class ClearCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: clear()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterStreamClear(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - clear()');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'cacheDir' => outputDir(),
            ]
        );

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $I->assertTrue($actual);

        $adapter->set($key2, 'test');
        $I->assertTrue(
            $adapter->has($key2)
        );

        $I->assertTrue(
            $adapter->clear()
        );

        $I->assertFalse(
            $adapter->has($key1)
        );

        $I->assertFalse(
            $adapter->has($key2)
        );
    }

    /**
     * Tests Phalcon\Storage\Adapter\Stream :: clear() - twice
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-31
     */
    public function storageAdapterStreamClearTwice(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - clear() - twice');

        $serializer = new SerializerFactory();

        $adapter = new Stream(
            $serializer,
            [
                'cacheDir' => outputDir(),
            ]
        );

        $key1 = uniqid();
        $key2 = uniqid();
        $adapter->set($key1, 'test');
        $actual = $adapter->has($key1);
        $I->assertTrue($actual);

        $adapter->set($key2, 'test');
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);

        $actual = $adapter->clear();
        $I->assertTrue($actual);

        $actual = $adapter->clear();
        $I->assertTrue($actual);
    }
}
