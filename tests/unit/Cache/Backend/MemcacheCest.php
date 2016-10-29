<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Exception;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Frontend\Output;
use Phalcon\Cache\Backend\Memcache;

/**
 * \Phalcon\Test\Unit\Cache\Backend\MemcacheCest
 * Tests the \Phalcon\Cache\Backend\Memcache component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
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
        $cache = new Memcache(new Data(['lifetime' => 20]), [
            'host' => TEST_MC_HOST,
            'port' => TEST_MC_PORT,
        ]);

        $I->dontSeeInMemcached($key);
        $I->haveInMemcached($key, 1);

        $I->assertEquals(2, $cache->increment($key));
        $I->seeInMemcached($key, 2);

        $I->assertEquals(4, $cache->increment($key, 2));
        $I->seeInMemcached($key, 4);

        $I->assertEquals(14, $cache->increment($key, 10));
        $I->seeInMemcached($key, 14);

        $I->clearMemcache();
    }

    public function decrement(UnitTester $I)
    {
        $I->wantTo('Decrement counter by using Memcache as cache backend');

        $key = 'decrement';
        $cache = new Memcache(new Data(['lifetime' => 20]), [
            'host' => TEST_MC_HOST,
            'port' => TEST_MC_PORT,
        ]);

        $I->dontSeeInMemcached($key);
        $I->haveInMemcached($key, 100);

        $I->assertEquals(99, $cache->decrement($key));
        $I->seeInMemcached($key, 99);

        $I->assertEquals(97, $cache->decrement($key, 2));
        $I->seeInMemcached($key, 97);

        $I->assertEquals(87, $cache->decrement($key, 10));
        $I->seeInMemcached($key, 87);

        $I->clearMemcache();
    }

    public function get(UnitTester $I)
    {
        $I->wantTo('Get data by using Memcache as cache backend');

        $key = 'data-get';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Memcache(new Data(['lifetime' => 20]), [
            'host' => TEST_MC_HOST,
            'port' => TEST_MC_PORT,
        ]);

        $I->haveInMemcached($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key'));

        $data = 'sure, nothing interesting';

        $I->haveInMemcached($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key-2'));

        $I->clearMemcache();
    }

    public function save(UnitTester $I)
    {
        $I->wantTo('Save data by using Memcache as cache backend');

        $key = 'data-save';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Memcache(new Data(['lifetime' => 20]), [
            'host' => TEST_MC_HOST,
            'port' => TEST_MC_PORT,
        ]);

        $I->dontSeeInMemcached($key);
        $cache->save('data-save', $data);

        $I->seeInMemcached($key, serialize($data));

        $data = 'sure, nothing interesting';

        $I->dontSeeInMemcached('non-existent-key', serialize($data));

        $cache->save('data-save', $data);
        $I->seeInMemcached($key, serialize($data));

        $I->clearMemcache();
    }

    public function delete(UnitTester $I)
    {
        $I->wantTo(/** @lang text */
            'Delete from cache by using Memcache as cache backend'
        );

        $cache = new Memcache(new Data(['lifetime' => 20]), [
            'host' => TEST_MC_HOST,
            'port' => TEST_MC_PORT,
        ]);

        $I->assertFalse($cache->delete('non-existent-keys'));

        $I->haveInMemcached('some-key-to-delete', 1);

        $I->assertTrue($cache->delete('some-key-to-delete'));
        $I->dontSeeInMemcached('some-key-to-delete');

        $I->clearMemcache();
    }

    /**
     * @issue 12182
     * @param UnitTester $I
     */
    public function flush(UnitTester $I)
    {
        $I->wantTo('Flush cache by using Memcache as cache backend');

        $cache = new Memcache(new Data(['lifetime' => 20]), [
            'host'     => TEST_MC_HOST,
            'port'     => TEST_MC_PORT,
            'statsKey' => '_PHCM',
        ]);

        $key1 = 'data-flush-1';
        $key2 = 'data-flush-2';

        $I->haveInMemcached($key1, 1);
        $I->haveInMemcached($key2, 2);

        $cache->save('data-flush-1', 1);
        $cache->save('data-flush-2', 2);

        $I->assertArrayHasKey('data-flush-1', $I->grabValueFromMemcached('_PHCM'));
        $I->assertArrayHasKey('data-flush-2', $I->grabValueFromMemcached('_PHCM'));

        $I->assertTrue($cache->flush());

        $I->dontSeeInMemcached($key1);
        $I->dontSeeInMemcached($key2);

        $I->assertFalse($I->grabValueFromMemcached('_PHCM'));

        $I->clearMemcache();
    }

    public function queryKeys(UnitTester $I)
    {
        $I->wantTo('Get cache keys by using Memcache as cache backend');

        $cache = new Memcache(new Data(['lifetime' => 20]), [
            'host'     => TEST_MC_HOST,
            'port'     => TEST_MC_PORT,
            'statsKey' => '_PHCM',
        ]);

        $I->haveInMemcached('_PHCM' . 'a', 1);
        $I->haveInMemcached('_PHCM' . 'b', 2);
        $I->haveInMemcached('_PHCM' . 'c', 3);

        $I->haveInMemcached('_PHCM', ['a' => 20, 'b' => 20, 'c' => 20]);

        $keys = $cache->queryKeys();
        sort($keys);

        $I->assertEquals($keys, ['a', 'b', 'c']);

        $I->clearMemcache();
    }

    public function queryKeysWithoutStatsKey(UnitTester $I)
    {
        $I->wantTo(
            'Catch exception during the attempt getting cache keys by using Memcache as cache backend without statsKey'
        );

        $cache = new Memcache(new Data(['lifetime' => 1]), [
            'host' => TEST_MC_HOST,
            'port' => TEST_MC_PORT,
        ]);

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
        $cache = new Memcache(new Output(['lifetime' => 2]), [
            'host' => TEST_MC_HOST,
            'port' => TEST_MC_PORT,
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
        $I->seeInMemcached('test-output', $time);

        // Expect same cache
        $content = $cache->start('test-output');
        $I->assertNotNull($content);

        $I->assertEquals($time, $obContent);
        $I->seeInMemcached('test-output', $time);

        sleep(2);
        $content = $cache->start('test-output');

        $I->assertNull($content);
        $I->dontSeeInMemcached('test-output');

        $I->clearMemcache();
    }
}
