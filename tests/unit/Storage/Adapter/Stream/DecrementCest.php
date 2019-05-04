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

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use UnitTester;
use function outputDir;

/**
 * Class DecrementCest
 */
class DecrementCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Stream :: decrement()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @throws \Exception
     * @author Phalcon Team <team@phalconphp.com>
     *
     * @since  2019-04-24
     *
     */
    public function storageAdapterStreamDecrement(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Stream - decrement()');
        $factory = new SerializerFactory();
        $adapter = new Stream($factory, ['cacheDir' => outputDir()]);

        $key    = 'cache-data';
        $result = $adapter->set($key, 100);
        $I->assertTrue($result);

        $expected = 99;
        $actual   = $adapter->decrement($key);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        $expected = 90;
        $actual   = $adapter->decrement($key, 9);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        /**
         * unknown key
         */
        $key    = 'unknown';
        $result = $adapter->decrement($key);
        $I->assertFalse($result);
    }
}
