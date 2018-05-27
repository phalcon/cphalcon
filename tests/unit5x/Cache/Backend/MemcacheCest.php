<?php

namespace Phalcon\Test\Unit5x\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Exception;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Frontend\Output;
use Phalcon\Cache\Backend\Memcache;

/**
 * Phalcon\Test\Unit5x\Cache\Backend\MemcacheCest
 * Tests the \Phalcon\Cache\Backend\Memcache component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit5x\Cache\Backend
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MemcacheCest
{
    public function _before(UnitTester $I)
    {
        if (!extension_loaded('memcache')) {
            throw new \PHPUnit_Framework_SkippedTestError(
                'Warning: memcache extension is not loaded'
            );
        }
    }

    public function increment(UnitTester $I)
    {
        $I->wantTo('Increment counter by using Memcache as cache backend');

        $key = 'increment';
        $cache = $this->getDataCache(null, 20);

        $I->dontSeeInMemcached($key);
        $I->haveInMemcached($key, 1);

        $I->assertEquals(2, $cache->increment($key));
        $I->seeInMemcached($key, 2);

        $I->assertEquals(4, $cache->increment($key, 2));
        $I->seeInMemcached($key, 4);

        $I->assertEquals(14, $cache->increment($key, 10));
        $I->seeInMemcached($key, 14);
    }

    public function decrement(UnitTester $I)
    {
        $I->wantTo('Decrement counter by using Memcache as cache backend');

        $key = 'decrement';
        $cache = $this->getDataCache(null, 20);

        $I->dontSeeInMemcached($key);
        $I->haveInMemcached($key, 100);

        $I->assertEquals(99, $cache->decrement($key));
        $I->seeInMemcached($key, 99);

        $I->assertEquals(97, $cache->decrement($key, 2));
        $I->seeInMemcached($key, 97);

        $I->assertEquals(87, $cache->decrement($key, 10));
        $I->seeInMemcached($key, 87);
    }

    public function get(UnitTester $I)
    {
        $I->wantTo('Get data by using Memcache as cache backend');

        $key = 'data-get';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = $this->getDataCache(null, 20);

        $I->haveInMemcached($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key'));

        $data = 'sure, nothing interesting';

        $I->haveInMemcached($key, serialize($data));
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

        $key = 'memcached-data-get-test';
        $data = $data = 'this is a test';;

        $cache = $this->getDataCache(null, 20);

        $I->haveInMemcached($key, serialize($data));

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
        $I->wantTo('Save data by using Memcache as cache backend');

        $key = 'data-save';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = $this->getDataCache(null, 20);

        $I->dontSeeInMemcached($key);
        $cache->save('data-save', $data);

        $I->seeInMemcached($key, serialize($data));

        $data = 'sure, nothing interesting';

        $I->dontSeeInMemcached('non-existent-key');

        $cache->save('data-save', $data);
        $I->seeInMemcached($key, serialize($data));
    }

    public function delete(UnitTester $I)
    {
        $I->wantTo(/** @lang text */
            'Delete from cache by using Memcache as cache backend'
        );

        $cache = $this->getDataCache(null, 20);

        $I->assertFalse($cache->delete('non-existent-keys'));

        $I->haveInMemcached('some-key-to-delete', 1);

        $I->assertTrue($cache->delete('some-key-to-delete'));
        $I->dontSeeInMemcached('some-key-to-delete');
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/12182
     * @param UnitTester $I
     */
    public function flush(UnitTester $I)
    {
        $I->wantTo('Flush cache by using Memcache as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getDataCache($statsKey, $lifetime);

        $key1 = 'data-flush-1';
        $key2 = 'data-flush-2';

        $I->haveInMemcached($key1, 1);
        $I->haveInMemcached($key2, 2);

        $I->haveInMemcached($statsKey, [$key1 => $lifetime, $key2 => $lifetime]);

        $I->assertTrue($cache->flush());

        $I->dontSeeInMemcached($key1);
        $I->dontSeeInMemcached($key2);

        $I->dontSeeInMemcached($statsKey);
    }

    public function queryKeys(UnitTester $I)
    {
        $I->wantTo('Get cache keys by using Memcache as cache backend');

        $lifetime = 20;
        $statsKey = '_PHCM';
        $cache = $this->getDataCache($statsKey, $lifetime);

        $I->haveInMemcached('a', 1);
        $I->haveInMemcached('b', 2);
        $I->haveInMemcached('c', 3);

        $I->haveInMemcached($statsKey, ['a' => $lifetime, 'b' => $lifetime, 'c' => $lifetime]);

        $keys = $cache->queryKeys();
        sort($keys);

        $I->assertEquals($keys, ['a', 'b', 'c']);
    }

    public function queryKeysWithoutStatsKey(UnitTester $I)
    {
        $I->wantTo(
            'Catch exception during the attempt getting cache keys by using Memcache as cache backend without statsKey'
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
        $I->wantTo('Cache output fragments by using Memcache as cache backend');

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
        $I->seeInMemcached('test-output', $time);

        // Expect same cache
        $content = $cache->start('test-output');
        $I->assertNotNull($content);

        $I->assertEquals($time, $obContent);
        $I->seeInMemcached('test-output', $time);

        sleep($lifetime);
        $content = $cache->start('test-output');

        $I->assertNull($content);
        $I->dontSeeInMemcached('test-output');
    }

    protected function getOutputCache($ttl = 0)
    {
        $config = [
            'host' => env('TEST_MC_HOST', '127.0.0.1'),
            'port' => env('TEST_MC_PORT', 11211),
        ];

        return new Memcache(new Output(['lifetime' => $ttl]), $config);
    }

    protected function getDataCache($statsKey = null, $ttl = 0)
    {
        $config = [
            'host' => env('TEST_MC_HOST', '127.0.0.1'),
            'port' => env('TEST_MC_PORT', 11211),
        ];

        if ($statsKey !== null) {
            $config['statsKey'] = $statsKey;
        }

        return new Memcache(new Data(['lifetime' => $ttl]), $config);
    }
}
