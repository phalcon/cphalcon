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

use Phalcon\Cache\Adapter\Stream;
use UnitTester;
use function outputFolder;

/**
 * Class DeleteCest
 */
class DeleteCest
{
    /**
     * Tests Phalcon\Cache\Adapter\Stream :: delete()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamDelete(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - delete()');
        $adapter = new Stream(['cacheDir' => outputFolder()]);

        $key = 'cache-data';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertTrue($actual);

        $actual = $adapter->has($key);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: delete() - twice
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamDeleteTwice(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - delete() - twice');
        $adapter = new Stream(['cacheDir' => outputFolder()]);

        $key = 'cache-data';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertTrue($actual);

        $actual = $adapter->delete($key);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Cache\Adapter\Stream :: delete() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-24
     */
    public function storageAdapterStreamDeleteUnknown(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Stream - delete() - unknown');
        $adapter = new Stream(['cacheDir' => outputFolder()]);

        $key    = 'cache-data';
        $actual = $adapter->delete($key);
        $I->assertFalse($actual);
    }
}
