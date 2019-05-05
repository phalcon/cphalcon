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

namespace Phalcon\Test\Unit\Cache\Cache;

use Phalcon\Cache\Adapter\Apcu;
use Phalcon\Cache\Cache;
use Phalcon\Cache\Exception\InvalidArgumentException;
use UnitTester;
use function uniqid;

/**
 * Class DeleteMultipleCest
 */
class DeleteMultipleCest
{
    /**
     * Tests Phalcon\Cache\Cache :: deleteMultiple()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheDeleteMultiple(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - deleteMultiple()');

        $adapter = new Cache(new Apcu());

        $key1 = uniqid();
        $key2 = uniqid();
        $key3 = uniqid();
        $adapter->setMultiple(
            [
                $key1 => 'test1',
                $key2 => 'test2',
                $key3 => 'test3',
            ]
        );

        $actual = $adapter->has($key1);
        $I->assertTrue($actual);
        $actual = $adapter->has($key2);
        $I->assertTrue($actual);
        $actual = $adapter->has($key3);
        $I->assertTrue($actual);

        $actual = $adapter->deleteMultiple([$key1, $key2]);
        $I->assertTrue($actual);

        $actual = $adapter->has($key1);
        $I->assertFalse($actual);
        $actual = $adapter->has($key2);
        $I->assertFalse($actual);
        $actual = $adapter->has($key3);
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Cache\Cache :: deleteMultiple() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-01
     */
    public function cacheCacheDeleteMultipleException(UnitTester $I)
    {
        $I->wantToTest('Cache\Cache - deleteMultiple() - exception');

        $I->expectThrowable(
            new InvalidArgumentException('The keys need to be an array or instance of Traversable'),
            function () {
                $adapter = new Cache(new Apcu());
                $actual  = $adapter->deleteMultiple(1234);
            }
        );
    }
}
