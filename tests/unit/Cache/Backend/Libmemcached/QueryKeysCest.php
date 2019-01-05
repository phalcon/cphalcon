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

namespace Phalcon\Test\Unit\Cache\Backend\Libmemcached;

use Phalcon\Cache\Exception;
use Phalcon\Test\Fixtures\Traits\Cache\LibmemcachedTrait;
use UnitTester;

/**
 * Class QueryKeysCest
 */
class QueryKeysCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: queryKeys()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedQueryKeys(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - queryKeys()');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache    = $this->getDataCache($statsKey);

        $I->haveInLibmemcached("a", 1);
        $I->haveInLibmemcached("b", 2);
        $I->haveInLibmemcached("c", 3);

        $I->haveInLibmemcached($statsKey, ['a' => $lifetime, 'b' => $lifetime, 'c' => $lifetime]);

        $keys = $cache->queryKeys();
        sort($keys);

        $I->assertEquals(['a', 'b', 'c'], $keys);
    }

    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: queryKeys() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedQueryKeysEmpty(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - queryKeys() - empty');

        $statsKey = '_PHCM';
        $cache    = $this->getDataCache($statsKey);

        $I->assertEquals([], $cache->queryKeys());
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/11024
     * @param UnitTester $I
     */
    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: queryKeys() - prefixed
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedQueryKeysPrefixed(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - queryKeys() - prefixed');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache    = $this->getDataCache($statsKey);

        $I->haveInLibmemcached('prefix1-myKey', ['a', 'b']);
        $I->haveInLibmemcached('prefix2-myKey', ['x', 'z']);

        $I->haveInLibmemcached($statsKey, ['prefix1-myKey' => $lifetime, 'prefix2-myKey' => $lifetime]);

        $I->assertEquals([0 => 'prefix1-myKey'], $cache->queryKeys('prefix1'));
        $I->assertEquals([1 => 'prefix2-myKey'], $cache->queryKeys('prefix2'));
        $I->assertCount(2, $cache->queryKeys('prefix'));

        $I->assertEquals([], $cache->queryKeys('prefix123'));
    }

    /**
     * Tests Phalcon\Cache\Backend\Libmemcached :: queryKeys() - without stats
     * key exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheBackendLibmemcachedQueryKeysNoStatsKeyException(UnitTester $I)
    {
        $I->wantToTest('Cache\Backend\Libmemcached - queryKeys() - no stats key exception');

        $I->expectThrowable(
            new Exception(
                "Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!"
            ),
            function () {
                $cache = $this->getDataCache(null, 1);
                $cache->queryKeys();
            }
        );
    }
}
