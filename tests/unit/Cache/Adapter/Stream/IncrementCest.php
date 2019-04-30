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

namespace Phalcon\Test\Unit\Cache\Adapter\Stream;

use function outputDir;
use Phalcon\Cache\Adapter\Stream;
use UnitTester;

/**
 * Class IncrementCest
 */
class IncrementCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: increment()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamIncrement(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - increment()');
        $adapter = new Stream(['cacheDir' => outputDir()]);

        $key    = 'cache-data';
        $result = $adapter->set($key, 1);
        $I->assertTrue($result);

        $expected = 2;
        $actual   = $adapter->increment($key);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        $expected = 10;
        $actual   = $adapter->increment($key, 8);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }
}
