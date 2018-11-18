<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Exception;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Backend\Redis;
use Phalcon\Cache\Frontend\Output;
use PHPUnit\Framework\SkippedTestError;

/**
 * Phalcon\Test\Unit\Cache\Backend\RedisCest
 *
 * Tests the \Phalcon\Cache\Backend\Redis component
 *
 * @package Phalcon\Test\Unit\Cache\Backend
 */
class RedisCest
{
    public function _before(UnitTester $I)
    {
        $I->wantToTest('Redis cache backend');

        if (!extension_loaded('redis')) {
            throw new SkippedTestError(
                'Warning: redis extension is not loaded'
            );
        }
    }

    public function increment(UnitTester $I)
    {
        $I->wantTo('Increment counter by using Redis as cache backend');

        $key = '_PHCR' . 'increment';
        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->dontSeeInRedis($key);
        $I->haveInRedis('string', $key, 1);

        $I->assertEquals(2, $cache->increment('increment'));
        $I->seeInRedis($key, 2);

        $I->assertEquals(4, $cache->increment('increment', 2));
        $I->seeInRedis($key, 4);

        $I->assertEquals(14, $cache->increment('increment', 10));
        $I->seeInRedis($key, 14);
    }

    public function decrement(UnitTester $I)
    {
        $I->wantTo('Decrement counter by using Redis as cache backend');

        $key = '_PHCR' . 'decrement';
        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->dontSeeInRedis($key);
        $I->haveInRedis('string', $key, 100);

        $I->assertEquals(99, $cache->decrement('decrement'));
        $I->seeInRedis($key, 99);

        $I->assertEquals(97, $cache->decrement('decrement', 2));
        $I->seeInRedis($key, 97);

        $I->assertEquals(87, $cache->decrement('decrement', 10));
        $I->seeInRedis($key, 87);
    }

    public function exists(UnitTester $I)
    {
        $I->wantTo('Check if cache exists in cache by using Redis as cache backend');

        $key = '_PHCR' . 'data-exists';

        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->haveInRedis('string', $key, serialize($data));

        $I->assertTrue($cache->exists('data-exists'));
        $I->assertFalse($cache->exists('non-existent-key'));
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/12434
     * @param UnitTester $I
     */
    public function existsEmpty(UnitTester $I)
    {
        $I->wantTo('Check if cache exists for empty value in cache by using Redis as cache backend');

        $key = '_PHCR' . 'data-empty-exists';

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->haveInRedis('string', $key, '');

        $I->assertTrue($cache->exists('data-empty-exists'));
        $I->assertFalse($cache->exists('non-existent-key'));
    }

    public function get(UnitTester $I)
    {
        $I->wantTo('Get data by using Redis as cache backend');

        $key = '_PHCR' . 'data-get';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->haveInRedis('string', $key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get($key));

        $data = 'sure, nothing interesting';

        $I->haveInRedis('string', $key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get($key));
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/12437
     * @param UnitTester $I
     */
    public function getEmpty(UnitTester $I)
    {
        $I->wantTo('Get empty value by using Redis as cache backend');

        $key = '_PHCR' . 'data-empty-get';
        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->haveInRedis('string', $key, '');
        $I->assertSame('', $cache->get('data-empty-get'));
    }

    public function save(UnitTester $I)
    {
        $I->wantTo('Save data by using Redis as cache backend');

        $key = '_PHCR' . 'data-save';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->dontSeeInRedis($key);
        $cache->save('data-save', $data);

        $I->seeInRedis($key, serialize($data));

        $data = 'sure, nothing interesting';

        $I->dontSeeInRedis($key, serialize($data));

        $cache->save('data-save', $data);
        $I->seeInRedis($key, serialize($data));
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/12327
     * @param UnitTester $I
     */
    public function saveNonExpiring(UnitTester $I)
    {
        $I->wantTo('Save data termlessly by using Redis as cache backend');

        $key  = '_PHCR' . 'data-save-2';
        $data = 1000;

        $cache = new Redis(new Data(['lifetime' => 200]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->dontSeeInRedis($key);

        $cache->save('data-save-2', $data, -1);

        sleep(2);
        $I->seeInRedis($key);

        $cache->save('data-save-2', $data, 0);

        sleep(2);
        $I->seeInRedis($key);

        $cache->save('data-save-2', $data, 1);

        sleep(2);
        $I->dontSeeInRedis($key);
    }

    public function delete(UnitTester $I)
    {
        $I->wantTo(/** @lang text */
            'Delete from cache by using Redis as cache backend'
        );

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->assertFalse($cache->delete('non-existent-keys'));

        $I->haveInRedis('string', '_PHCR' . 'some-key-to-delete', 1);

        $I->assertTrue($cache->delete('some-key-to-delete'));
        $I->dontSeeInRedis('_PHCR' . 'some-key-to-delete');
    }

    public function flush(UnitTester $I)
    {
        $I->wantTo('Flush cache by using Redis as cache backend');

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
            'statsKey' => '_PHCR'
        ]);

        $key1 = '_PHCR' . 'data-flush-1';
        $key2 = '_PHCR' . 'data-flush-2';

        $I->haveInRedis('string', $key1, 1);
        $I->haveInRedis('string', $key2, 2);

        $I->haveInRedis('set', '_PHCR', 'data-flush-1');
        $I->haveInRedis('set', '_PHCR', 'data-flush-2');

        $cache->save('data-flush-1', 1);
        $cache->save('data-flush-2', 2);

        $I->assertTrue($cache->flush());

        $I->dontSeeInRedis($key1);
        $I->dontSeeInRedis($key2);
    }

    public function queryKeys(UnitTester $I)
    {
        $I->wantTo('Get cache keys by using Redis as cache backend');

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
            'statsKey' => '_PHCR'
        ]);

        $I->haveInRedis('string', '_PHCR' . 'a', 1);
        $I->haveInRedis('string', '_PHCR' . 'b', 2);
        $I->haveInRedis('string', '_PHCR' . 'c', 3);

        $I->haveInRedis('set', '_PHCR', 'a');
        $I->haveInRedis('set', '_PHCR', 'b');
        $I->haveInRedis('set', '_PHCR', 'c');

        $keys = $cache->queryKeys();
        sort($keys);

        $I->assertEquals(['a', 'b', 'c'], $keys);
    }

    public function queryKeysWithoutStatsKey(UnitTester $I)
    {
        $I->wantTo('Catch exception during the attempt getting cache keys by using Redis as cache backend without statsKey');

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        $I->expectException(
            new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!"),
            function () use ($cache) {
                $cache->queryKeys();
            }
        );
    }

    public function output(UnitTester $I)
    {
        $I->wantTo('Cache output fragments by using Redis as cache backend');

        $time = date('H:i:s');
        $cache = new Redis(new Output(['lifetime' => 2]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
        ]);

        ob_start();

        // First time cache
        $content = $cache->start('test-output');
        $I->assertNull($content);

        echo $time;
        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $I->assertEquals($time, $obContent);
        $I->seeInRedis('_PHCR' . 'test-output', $time);

        // Expect same cache
        $content = $cache->start('test-output');
        $I->assertNotNull($content);

        $I->assertEquals($time, $obContent);
        $I->seeInRedis('_PHCR' . 'test-output', $time);

        sleep(2);
        $content = $cache->start('test-output');

        $I->assertNull($content);
        $I->dontSeeInRedis('_PHCR' . 'test-output');
    }

    public function setTimeout(UnitTester $I)
    {
        $I->wantTo('Get data by using Redis as cache backend and set timeout');

        $key = '_PHCR' . 'data-get-timeout';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Redis(new Data(['lifetime' => 20]), [
            'host'  => env('TEST_RS_HOST', '127.0.0.1'),
            'port'  => env('TEST_RS_PORT', 6379),
            'index' => env('TEST_RS_DB', 0),
            'timeout' => 1,
        ]);

        $I->haveInRedis('string', $key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get-timeout'));

        $I->assertNull($cache->get($key));

        $data = 'sure, nothing interesting';

        $I->haveInRedis('string', $key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get-timeout'));

        $I->assertNull($cache->get($key));
    }
}
