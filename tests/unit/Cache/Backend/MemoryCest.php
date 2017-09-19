<?php

namespace Phalcon\Test\Unit\Cache\Backend;

use UnitTester;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Frontend\None;
use Phalcon\Cache\Backend\Memory;

/**
 * \Phalcon\Test\Unit\Cache\Backend\MemoryCest
 * Tests the \Phalcon\Cache\Backend\Memory component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
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
class MemoryCest
{
    public function get(UnitTester $I)
    {
        $I->wantTo('Get cached by using Memory as cache backend');

        $key = 'data-get';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Memory(new Data(['lifetime' => 20]));

        $I->setProtectedProperty($cache, '_data', [$key => serialize($data)]);

        $I->assertEquals($data, $cache->get($key));
        $I->assertNull($cache->get('non-existent-key'));

        $I->assertEquals([$key => serialize($data)], $I->getProtectedProperty($cache, '_data'));

        $I->setProtectedProperty($cache, '_data', [$key => 100]);
        $I->assertEquals(100, $cache->get($key));

        $I->assertEquals([$key => 100], $I->getProtectedProperty($cache, '_data'));
    }

    public function save(UnitTester $I)
    {
        $I->wantTo('Save data by using Memory as cache backend');

        $key = 'data-save';
        $data = [uniqid(), gethostname(), microtime(), get_include_path(), time()];

        $cache = new Memory(new Data(['lifetime' => 20]));
        $I->assertNull($cache->get($key));

        $I->assertTrue($cache->save($key, $data));
        $I->assertEquals($data, $cache->get($key));
        $I->assertEquals([$key => serialize($data)], $I->getProtectedProperty($cache, '_data'));

        $I->assertTrue($cache->save($key, 2017));
        $I->assertEquals(2017, $cache->get($key));
        $I->assertEquals([$key => 2017], $I->getProtectedProperty($cache, '_data'));
    }

    public function delete(UnitTester $I)
    {
        $I->wantTo(/** @lang text */
            'Delete from cache by using Memory as cache backend'
        );

        $key = 'data-delete';

        $cache = new Memory(new Data(['lifetime' => 20]));
        $I->assertNull($I->getProtectedProperty($cache, '_data'));

        $I->setProtectedProperty($cache, '_data', [$key => 100]);

        $I->assertTrue($cache->delete($key));
        //$I->assertNull($I->getProtectedProperty($cache, '_data'));
        codecept_debug($I->getProtectedProperty($cache, '_data'));
        $I->assertFalse($cache->delete($key));
    }

    public function increment(UnitTester $I)
    {
        $I->wantTo('Increment counter by using Memory as cache backend');

        $key = 'increment';
        $cache = new Memory(new Data(['lifetime' => 20]));

        $I->setProtectedProperty($cache, '_data', [$key => 20]);

        $I->assertEquals(21, $cache->increment($key));
        $I->assertEquals(24, $cache->increment($key, 3));
        $I->assertEquals(54, $cache->increment($key, 30));

        $I->assertEquals([$key => 54], $I->getProtectedProperty($cache, '_data'));
    }

    public function decrement(UnitTester $I)
    {
        $I->wantTo('Decrement counter by using Memory as cache backend');

        $key = 'decrement';
        $cache = new Memory(new Data(['lifetime' => 20]));

        $I->setProtectedProperty($cache, '_data', [$key => 100]);

        $I->assertEquals(99, $cache->decrement($key));
        $I->assertEquals(96, $cache->decrement($key, 3));
        $I->assertEquals(6, $cache->decrement($key, 90));

        $I->assertEquals([$key => 6], $I->getProtectedProperty($cache, '_data'));
    }

    public function dataNone(UnitTester $I)
    {
        $I->wantTo("Use Memory cache with None frontend");

        $frontend = new None(['lifetime' => 10]);
        $backend  = new Memory($frontend);

        $I->assertFalse($backend->isStarted());

        $backend->save('test-data', 'nothing interesting');
        $I->assertEquals('nothing interesting', $backend->get('test-data'));

        $backend->save('test-data', 'something interesting');
        $I->assertEquals('something interesting', $backend->get('test-data'));

        $I->assertTrue($backend->exists('test-data'));
        $I->assertTrue($backend->delete('test-data'));

        $string = str_repeat('a', 5000000);

        $backend->save('test-data', $string);

        $s1 = $backend->get('test-data');
        $s2 = $backend->get('test-data');
        $s3 = $backend->get('test-data');

        $I->assertEquals($s1, $s2);
        $I->assertEquals($s1, $s3);
        $I->assertEquals(strlen($s1), 5000000);
        $I->assertEquals($s1, $string);

        $I->assertTrue($backend->delete('test-data'));

        unset($s1, $s2, $s3);

        gc_collect_cycles();

        $s1 = $frontend->afterRetrieve($string);
        $s2 = $frontend->afterRetrieve($string);
        $s3 = $frontend->afterRetrieve($string);

        $I->assertEquals($s1, $s2);
        $I->assertEquals($s1, $s3);
        $I->assertEquals($s1, $string);
    }
}
