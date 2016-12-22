<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Backend\Libmemcached;

/**
 * \Phalcon\Test\Unit\Cache\Backend\LibmemcachedCest
 * Tests the \Phalcon\Cache\Backend\Libmemcached component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Cache\Backend
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class LibmemcachedCest
{
    public function _before(UnitTester $I)
    {
        if (!extension_loaded('memcached')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: memcached extension is not loaded'
            );
        }
    }

    public function emptyQueryKeys(UnitTester $I)
    {
        $I->wantToTest('Getting empty keys list by using Libmemcached as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getCache($statsKey, $lifetime);

        $I->assertEquals([], $cache->queryKeys());
    }

    public function queryKeys(UnitTester $I)
    {
        $I->wantToTest('Getting cache keys by using Libmemcached as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getCache($statsKey, $lifetime);

        $I->haveInLibmemcached("{$statsKey}a", 1);
        $I->haveInLibmemcached("{$statsKey}b", 2);
        $I->haveInLibmemcached("{$statsKey}c", 3);

        $I->haveInLibmemcached($statsKey, ['a' => $lifetime, 'b' => $lifetime, 'c' => $lifetime]);

        $keys = $cache->queryKeys();
        sort($keys);

        $I->assertEquals(['a', 'b', 'c'], $keys);
    }

    /**
     * @issue 11024
     * @param UnitTester $I
     */
    public function prefixedQueryKeys(UnitTester $I)
    {
        $I->wantToTest('Getting prefixed cache keys by using Libmemcached as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getCache($statsKey, $lifetime);

        $I->haveInLibmemcached("{$statsKey}prefix1-myKey", ['a', 'b']);
        $I->haveInLibmemcached("{$statsKey}prefix2-myKey", ['x', 'z']);

        $I->haveInLibmemcached($statsKey, ['prefix1-myKey' => $lifetime, 'prefix2-myKey' => $lifetime]);

        $I->assertEquals([0 => 'prefix1-myKey'], $cache->queryKeys('prefix1'));
        $I->assertEquals([1 => 'prefix2-myKey'], $cache->queryKeys('prefix2'));
        $I->assertCount(2, $cache->queryKeys('prefix'));

        $I->assertEquals([], $cache->queryKeys('prefix123'));
    }

    protected function getCache($statsKey = '_PHCM', $ttl = 0)
    {
        return new Libmemcached(
            new Data(['lifetime' => $ttl]),
            [
                'servers' => [
                    [
                        'host'   => env('TEST_MC_HOST', '127.0.0.1'),
                        'port'   => env('TEST_MC_PORT', 11211),
                        'weight' => env('TEST_MC_WEIGHT', 1),
                    ]
                ],
                'statsKey' => $statsKey,
                'client' => [
                    \Memcached::OPT_HASH => \Memcached::HASH_MD5,
                ],
            ]
        );
    }
}
