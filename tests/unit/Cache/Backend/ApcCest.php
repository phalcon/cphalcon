<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Frontend\Data;
use PHPUnit\Framework\SkippedTestError;

/**
 * \Phalcon\Test\Unit\Cache\Backend\ApcCest
 * Tests the \Phalcon\Cache\Backend\Apc component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
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
class ApcCest
{
    public function _before(UnitTester $I)
    {
        if (!extension_loaded('apc')) {
            throw new SkippedTestError(
                'Warning: apc extension is not loaded'
            );
        }

        if (!ini_get('apc.enabled') || (PHP_SAPI === 'cli' && !ini_get('apc.enable_cli'))) {
            throw new SkippedTestError(
                'Warning: apc.enable_cli must be set to "On"'
            );
        }

        if (extension_loaded('apcu') && version_compare(phpversion('apcu'), '5.1.6', '=')) {
            throw new SkippedTestError(
                'Warning: APCu v5.1.6 was broken. See: https://github.com/krakjoe/apcu/issues/203'
            );
        }
    }

    public function _after(UnitTester $I)
    {
        $I->flushApc();
    }

    public function increment(UnitTester $I)
    {
        $I->wantTo('Increment counter by using APC(u) as cache backend');

        $key   = '_PHCA' . 'increment';
        $cache = new Apc(new Data(['lifetime' => 20]));

        $I->dontSeeInApc($key);
        $I->haveInApc($key, 1);

        $I->assertEquals(2, $cache->increment('increment'));
        $I->seeInApc($key, 2);

        $I->assertEquals(4, $cache->increment('increment', 2));
        $I->seeInApc($key, 4);

        $I->assertEquals(14, $cache->increment('increment', 10));
        $I->seeInApc($key, 14);

        $key = '_PHCA' . 'increment-2';

        $I->dontSeeInApc($key);
        $I->haveInApc($key, 90);

        $I->assertEquals(91, $cache->increment('increment-2'));
        $I->seeInApc($key, 91);

        $I->assertEquals(97, $cache->increment('increment-2', 6));
        $I->seeInApc($key, 97);

        $I->assertEquals(200, $cache->increment('increment-2', 103));
        $I->seeInApc($key, 200);
    }

    public function decrement(UnitTester $I)
    {
        $I->wantTo('Decrement counter by using APC(u) as cache backend');

        $key   = '_PHCA' . 'decrement';
        $cache = new Apc(new Data(['lifetime' => 20]));

        $I->dontSeeInApc($key);
        $I->haveInApc($key, 100);

        $I->assertEquals(99, $cache->decrement('decrement'));
        $I->seeInApc($key, 99);

        $I->assertEquals(96, $cache->decrement('decrement', 3));
        $I->seeInApc($key, 96);

        $I->assertEquals(90, $cache->decrement('decrement', 6));
        $I->seeInApc($key, 90);

        $key = '_PHCA' . 'decrement-2';

        $I->dontSeeInApc($key);
        $I->haveInApc($key, 60);

        $I->assertEquals(59, $cache->decrement('decrement-2'));
        $I->seeInApc($key, 59);

        $I->assertEquals(47, $cache->decrement('decrement-2', 12));
        $I->seeInApc($key, 47);

        $I->assertEquals(7, $cache->decrement('decrement-2', 40));
        $I->seeInApc($key, 7);
    }

    public function get(UnitTester $I)
    {
        $I->wantTo('Get data by using APC(u) as cache backend');

        $key = '_PHCA' . 'data-get';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Apc(new Data(['lifetime' => 20]));

        $I->haveInApc($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key'));

        $data = 'sure, nothing interesting';

        $I->haveInApc($key, serialize($data));
        $I->assertEquals($data, $cache->get('data-get'));

        $I->assertNull($cache->get('non-existent-key-2'));
    }

    public function save(UnitTester $I)
    {
        $I->wantTo('Save data by using APC(u) as cache backend');

        $key = '_PHCA' . 'data-save';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Apc(new Data(['lifetime' => 20]));

        $I->dontSeeInApc($key);
        $cache->save('data-save', $data);

        $I->seeInApc($key, serialize($data));

        $data = 'sure, nothing interesting';

        $I->dontSeeInApc('non-existent-key', serialize($data));

        $cache->save('data-save', $data);
        $I->seeInApc($key, serialize($data));
    }

    public function delete(UnitTester $I)
    {
        $I->wantTo(/** @lang text */
            'Delete from cache by using APC(u) as cache backend'
        );

        $key = '_PHCA' . 'data-delete';
        $cache = new Apc(new Data(['lifetime' => 20]));

        $I->assertFalse($cache->delete('non-existent-keys'));

        $I->haveInApc($key, 1);

        $I->assertTrue($cache->delete('data-delete'));
        $I->dontSeeInApc($key);
    }

    public function flush(UnitTester $I)
    {
        $I->wantTo('Flush all cache by using APC(u) as cache backend');

        $cache = new Apc(new Data(['lifetime' => 20]));

        $key1 = '_PHCA' . 'app-data' . 'data-flush-1';
        $key2 = '_PHCA' . 'app-data' . 'data-flush-2';
        $key3 = '_PHCA' . 'data-flush-3';

        $I->haveInApc([$key1 => 1, $key2 => 2, $key3 => 3], null);

        $I->assertTrue($cache->flush());

        $I->dontSeeInApc($key1);
        $I->dontSeeInApc($key2);
        $I->dontSeeInApc($key3);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/12153
     * @param UnitTester $I
     */
    public function flushByPrefix(UnitTester $I)
    {
        $I->wantTo('Flush prefixed keys from cache by using APC(u) as cache backend');

        $prefix = 'app-data';
        $cache = new Apc(new Data(['lifetime' => 20]), ['prefix' => $prefix]);

        $key1 = '_PHCA' . 'app-data' . 'data-flush-1';
        $key2 = '_PHCA' . 'app-data' . 'data-flush-2';
        $key3 = '_PHCA' . 'data-flush-3';

        $I->haveInApc([$key1 => 1, $key2 => 2, $key3 => 3], null);

        $I->assertTrue($cache->flush());

        $I->dontSeeInApc($key1);
        $I->dontSeeInApc($key2);

        $I->assertEquals(3, $I->grabValueFromApc($key3));
    }

    public function queryKeys(UnitTester $I)
    {
        $I->wantTo('Get cache keys by using APC(u) as cache backend');

        $cache = new Apc(new Data(['lifetime' => 20]));

        $I->haveInApc(['_PHCAa' => 1, '_PHCAb' => 2, '_PHCAc' => 3], null);

        $keys = $cache->queryKeys();
        sort($keys);

        $I->assertEquals($keys, ['a', 'b', 'c']);
    }

    public function prefixedQueryKeys(UnitTester $I)
    {
        $I->wantTo('Get prefixed cache keys by using APC(u) as cache backend');

        $prefix = 'app-data';
        $cache = new Apc(new Data(['lifetime' => 20]), ['prefix' => $prefix]);

        $key1 = '_PHCA' . 'app-data' . 'data-key-1';
        $key2 = '_PHCA' . 'app-data' . 'data-key-2';
        $key3 = '_PHCA' . 'data-key-3';

        $I->haveInApc([$key1 => 1, $key2 => 2, $key3 => 3], null);

        $keys = $cache->queryKeys($prefix);
        sort($keys);

        $I->assertEquals($keys, ['app-datadata-key-1', 'app-datadata-key-2']);
    }
}
