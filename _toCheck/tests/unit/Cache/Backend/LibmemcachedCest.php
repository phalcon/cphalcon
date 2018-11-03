<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Exception;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Frontend\Output;
use Phalcon\Cache\Backend\Libmemcached;
use PHPUnit\Framework\SkippedTestError;

/**
 * \Phalcon\Test\Unit\Cache\Backend\LibmemcachedCest
 * Tests the \Phalcon\Cache\Backend\Libmemcached component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Cache\Backend
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
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
            throw new SkippedTestError(
                'Warning: memcached extension is not loaded'
            );
        }
    }

    public function increment(UnitTester $I)
    {
        $I->wantTo('Increment counter by using Libmemcached as cache backend');

        $key = 'increment';
        $cache = $this->getDataCache(null, 20);

        $I->dontSeeInLibmemcached($key);
        $I->haveInLibmemcached($key, 1);

        $I->assertEquals(2, $cache->increment($key));
        $I->seeInLibmemcached($key, 2);

        $I->assertEquals(4, $cache->increment($key, 2));
        $I->seeInLibmemcached($key, 4);

        $I->assertEquals(14, $cache->increment($key, 10));
        $I->seeInLibmemcached($key, 14);
    }

    public function decrement(UnitTester $I)
    {
        $I->wantTo('Decrement counter by using Libmemcached as cache backend');

        $key = 'decrement';
        $cache = $this->getDataCache(null, 20);

        $I->dontSeeInLibmemcached($key);
        $I->haveInLibmemcached($key, 100);

        $I->assertEquals(99, $cache->decrement($key));
        $I->seeInLibmemcached($key, 99);

        $I->assertEquals(97, $cache->decrement($key, 2));
        $I->seeInLibmemcached($key, 97);

        $I->assertEquals(87, $cache->decrement($key, 10));
        $I->seeInLibmemcached($key, 87);
    }

    public function get(UnitTester $I)
    {
        $I->wantTo('Get data by using Libmemcached as cache backend');

        $key = 'data-get';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = $this->getDataCache(null, 20);

        $I->haveInLibmemcached($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key'));

        $data = 'sure, nothing interesting';

        $I->haveInLibmemcached($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key-2'));
    }

    /**
     * @param UnitTester $I
     * @issue https://github.com/phalcon/cphalcon/issues/13092
     */
    public function shouldGetTheSameValueRegardlessOfTheNumberOfRequests(UnitTester $I)
    {
        $I->wantTo('Get the same data from the Memcache regardless of the number of requests');

        $key = 'libmemcached-data-get-test';
        $data = 'this is a test';

        $cache = $this->getDataCache(null, 20);

        $I->haveInLibmemcached($key, serialize($data));

        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals($data, $cache->get($key));
    }

    public function save(UnitTester $I)
    {
        $I->wantTo('Save data by using Libmemcached as cache backend');

        $key = 'data-save';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = $this->getDataCache(null, 20);

        $I->dontSeeInLibmemcached($key);
        $cache->save('data-save', $data);

        $I->seeInLibmemcached($key, serialize($data));

        $data = 'sure, nothing interesting';

        $I->dontSeeInLibmemcached('non-existent-key');

        $cache->save('data-save', $data);
        $I->seeInLibmemcached($key, serialize($data));
    }

    public function delete(UnitTester $I)
    {
        $I->wantTo(/** @lang text */
            'Delete from cache by using Libmemcached as cache backend'
        );

        $cache = $this->getDataCache(null, 20);

        $I->assertFalse($cache->delete('non-existent-keys'));

        $I->haveInLibmemcached('some-key-to-delete', 1);

        $I->assertTrue($cache->delete('some-key-to-delete'));
        $I->dontSeeInLibmemcached('some-key-to-delete');
    }

    public function flush(UnitTester $I)
    {
        $I->wantTo('Flush cache by using Libmemcached as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getDataCache($statsKey, $lifetime);

        $I->haveInLibmemcached('data-flush-1', 1);
        $I->haveInLibmemcached('data-flush-2', 2);
        $I->haveInLibmemcached('data-flush-3', 3);

        $I->haveInLibmemcached(
            $statsKey,
            ['data-flush-1' => $lifetime, 'data-flush-2' => $lifetime, 'data-flush-3' => $lifetime]
        );

        $I->assertTrue($cache->flush());

        $I->dontSeeInLibmemcached('data-flush-1');
        $I->dontSeeInLibmemcached('data-flush-2');
        $I->dontSeeInLibmemcached('data-flush-3');

        $I->dontSeeInLibmemcached($statsKey);
    }

    public function emptyQueryKeys(UnitTester $I)
    {
        $I->wantToTest('Getting empty keys list by using Libmemcached as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getDataCache($statsKey, $lifetime);

        $I->assertEquals([], $cache->queryKeys());
    }

    public function queryKeys(UnitTester $I)
    {
        $I->wantToTest('Getting cache keys by using Libmemcached as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getDataCache($statsKey, $lifetime);

        $I->haveInLibmemcached("a", 1);
        $I->haveInLibmemcached("b", 2);
        $I->haveInLibmemcached("c", 3);

        $I->haveInLibmemcached($statsKey, ['a' => $lifetime, 'b' => $lifetime, 'c' => $lifetime]);

        $keys = $cache->queryKeys();
        sort($keys);

        $I->assertEquals(['a', 'b', 'c'], $keys);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/11024
     * @param UnitTester $I
     */
    public function prefixedQueryKeys(UnitTester $I)
    {
        $I->wantToTest('Getting prefixed cache keys by using Libmemcached as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getDataCache($statsKey, $lifetime);

        $I->haveInLibmemcached('prefix1-myKey', ['a', 'b']);
        $I->haveInLibmemcached('prefix2-myKey', ['x', 'z']);

        $I->haveInLibmemcached($statsKey, ['prefix1-myKey' => $lifetime, 'prefix2-myKey' => $lifetime]);

        $I->assertEquals([0 => 'prefix1-myKey'], $cache->queryKeys('prefix1'));
        $I->assertEquals([1 => 'prefix2-myKey'], $cache->queryKeys('prefix2'));
        $I->assertCount(2, $cache->queryKeys('prefix'));

        $I->assertEquals([], $cache->queryKeys('prefix123'));
    }

    public function queryKeysWithoutStatsKey(UnitTester $I)
    {
        $I->wantTo(
            'Catch exception during the attempt getting cache keys by using ' .
            'Libmemcached as cache backend without statsKey'
        );

        $cache = $this->getDataCache(null, 1);

        $I->expectException(
            new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!"),
            function () use ($cache) {
                $cache->queryKeys();
            }
        );
    }

    public function output(UnitTester $I)
    {
        $I->wantTo('Cache output fragments by using Libmemcached as cache backend');

        $time = date('H:i:s');
        $lifetime = 2;
        $cache = $this->getOutputCache($lifetime);

        ob_start();

        // First time cache
        $content = $cache->start('test-output');
        $I->assertNull($content);

        echo $time;
        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $I->assertEquals($time, $obContent);
        $I->seeInLibmemcached('test-output', $time);

        // Expect same cache
        $content = $cache->start('test-output');
        $I->assertNotNull($content);

        $I->assertEquals($time, $obContent);
        $I->seeInLibmemcached('test-output', $time);

        sleep($lifetime);
        $content = $cache->start('test-output');

        $I->assertNull($content);
        $I->dontSeeInLibmemcached('test-output');
    }

    protected function getDataCache($statsKey = null, $ttl = 0)
    {
        $config = [
            'client'  => [],
            'servers' => [
                [
                    'host'   => env('TEST_MC_HOST', '127.0.0.1'),
                    'port'   => env('TEST_MC_PORT', 11211),
                    'weight' => env('TEST_MC_WEIGHT', 1),
                ]
            ],
        ];

        if ($statsKey !== null) {
            $config['statsKey'] = $statsKey;
        }

        return new Libmemcached(new Data(['lifetime' => $ttl]), $config);
    }

    protected function getOutputCache($ttl = 0)
    {
        $config = [
            'client'  => [],
            'servers' => [
                [
                    'host'   => env('TEST_MC_HOST', '127.0.0.1'),
                    'port'   => env('TEST_MC_PORT', 11211),
                    'weight' => env('TEST_MC_WEIGHT', 1),
                ]
            ],
        ];

        return new Libmemcached(new Output(['lifetime' => $ttl]), $config);
    }
}
