<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file LICENSE.txt.                             |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

namespace Phalcon\Test\Unit\Cache\Backend;

use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Backend\Memory;
use Phalcon\Cache\Backend\Mongo;
use Phalcon\Cache\Backend\Xcache;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Frontend\Output;
use UnitTester;

class CacheCest
{
    public function _before(UnitTester $I)
    {
        date_default_timezone_set('UTC');
    }

    public function testDataFileCacheIncrement(UnitTester $I)
    {
        $frontCache = new Data();

        $cache = new File($frontCache, [
            'cacheDir' => cacheFolder(),
        ]);
        $cache->delete('foo');
        $cache->save('foo', "1");
        $I->assertEquals(2, $cache->increment('foo'));

        $I->assertEquals($cache->get('foo'), 2);

        $I->assertEquals($cache->increment('foo', 5), 7);
    }

    public function testDataFileCacheDecrement(UnitTester $I)
    {
        $frontCache = new Data();

        $cache = new File($frontCache, [
            'cacheDir' => cacheFolder(),
        ]);
        $cache->delete('foo');
        $cache->save('foo', "100");
        $I->assertEquals(99, $cache->decrement('foo'));

        $I->assertEquals(95, $cache->decrement('foo', 4));
    }

    /**
     * @expectedException \Exception
     */
    public function testDataFileCacheUnsafeKey(UnitTester $I)
    {
        $I->expectThrowable(
            \Exception::class,
            function () {
                $frontCache = new Data();

                $cache = new File($frontCache, [
                    'cacheDir' => cacheFolder(),
                    'safekey'  => true,
                    'prefix'   => '!@(##' // should throw an exception, only a-zA-Z09_-. are allowed
                ]);
            }
        );
    }

    public function testCacheFileFlush(UnitTester $I)
    {
        $frontCache = new Data(['lifetime' => 10]);

        // File
        $cache = new File($frontCache, [
            'cacheDir' => cacheFolder(),
        ]);

        $cache->save('data', "1");
        $cache->save('data2', "2");

        $I->assertTrue($cache->flush());

        $I->assertFileNotExists('unit-tests/cache/data');
        $I->assertFileNotExists('unit-tests/cache/data2');
    }

    public function testCacheMemoryFlush(UnitTester $I)
    {
        $frontCache = new Data(['lifetime' => 10]);

        // Memory
        $cache = new Memory($frontCache);

        $cache->save('data', "1");
        $cache->save('data2', "2");

        $I->assertTrue($cache->flush());

        $I->assertFalse($cache->exists('data'));
        $I->assertFalse($cache->exists('data2'));
    }

    public function testOutputMongoCache(UnitTester $I)
    {

        list($ready, $collection) = $this->_prepareMongo($I);
        if (!$ready) {
            return false;
        }

        $time = date('H:i:s');

        $frontCache = new Output([
            'lifetime' => 3,
        ]);

        $cache = new Mongo($frontCache, [
            'server'     => 'mongodb://' . DATA_MONGODB_HOST,
            'db'         => 'phalcon_test',
            'collection' => 'caches',
        ]);

        ob_start();

        //First time cache
        $content = $cache->start('test-output');
        $I->assertNull($content);

        echo $time;

        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $I->assertEquals($time, $obContent);

        $document = $collection->findOne(['key' => 'test-output']);
        $I->assertInternalType('array', $document);
        $I->assertEquals($time, $document['data']);

        //Expect same cache
        $content = $cache->start('test-output');
        $I->assertNotNull($content);

        $document = $collection->findOne(['key' => 'test-output']);
        $I->assertInternalType('array', $document);
        $I->assertEquals($time, $document['data']);

        //Query keys
        $keys = $cache->queryKeys();
        $I->assertEquals($keys, [
            0 => 'test-output',
        ]);

        //Exists
        $I->assertTrue($cache->exists('test-output'));

        //Delete entry from cache
        $I->assertTrue($cache->delete('test-output'));
    }

    protected function _prepareMongo(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('mongo');

        //remove existing
        if (class_exists('MongoClient', false)) {
            $mongo = new \MongoClient();
        } else {
            $mongo = new \Mongo();
        }
        $database   = $mongo->phalcon_test;
        $collection = $database->caches;
        $collection->remove();

        return [$mongo, $collection];
    }

    public function testDataMongoCache(UnitTester $I)
    {
        list($ready, $collection) = $this->_prepareMongo($I);
        if (!$ready) {
            return false;
        }

        // Travis can be slow, especially when Valgrind is used
        $frontCache = new Data(['lifetime' => 900]);

        $cache = new Mongo($frontCache, [
            'mongo'      => $ready,
            'db'         => 'phalcon_test',
            'collection' => 'caches',
        ]);

        $data = [1, 2, 3, 4, 5];

        $cache->save('test-data', $data);

        $cachedContent = $cache->get('test-data');
        $I->assertEquals($cachedContent, $data);

        $cache->save('test-data', "sure, nothing interesting");

        $cachedContent = $cache->get('test-data');
        $I->assertEquals($cachedContent, "sure, nothing interesting");

        //Exists
        $I->assertTrue($cache->exists('test-data'));

        $I->assertTrue($cache->delete('test-data'));
    }

    public function testMongoIncrement(UnitTester $I)
    {
        list($ready, $collection) = $this->_prepareMongo($I);
        if (!$ready) {
            return false;
        }

        $frontCache = new Data(
            ['lifetime' => 200]
        );

        $cache = new Mongo($frontCache, [
            'mongo'      => $ready,
            'db'         => 'phalcon_test',
            'collection' => 'caches',
        ]);

        $cache->delete('foo');

        $cache->save('foo', 1);
        $I->assertEquals(1, $cache->get('foo'));

        $I->assertEquals(2, $cache->increment('foo'));
        $I->assertEquals(4, $cache->increment('foo', 2));
        $I->assertEquals(4, $cache->get('foo'));

        $I->assertEquals(14, $cache->increment('foo', 10));
    }

    public function testMongoDecrement(UnitTester $I)
    {
        list($ready, $collection) = $this->_prepareMongo($I);
        if (!$ready) {
            return false;
        }

        $frontCache = new Data([
            'lifetime' => 200,
        ]);

        $cache = new Mongo($frontCache, [
            'mongo'      => $ready,
            'db'         => 'phalcon_test',
            'collection' => 'caches',
        ]);
        $cache->delete('foo');
        $cache->save('foo', 100);

        $I->assertEquals(99, $cache->decrement('foo'));
        $I->assertEquals(89, $cache->decrement('foo', 10));
        $I->assertEquals(89, $cache->get('foo'));
        $I->assertEquals(1, $cache->decrement('foo', 88));
    }

    public function testCacheMongoFlush(UnitTester $I)
    {
        // Mongo
        list($ready, $collection) = $this->_prepareMongo($I);
        if (!$ready) {
            return false;
        }

        $frontCache = new Data([
            'lifetime' => 10,
        ]);

        $cache = new Mongo($frontCache, [
            'mongo'      => $ready,
            'db'         => 'phalcon_test',
            'collection' => 'caches',
        ]);

        $cache->save('data', "1");
        $cache->save('data2', "2");

        $I->assertTrue($cache->flush());

        $I->assertFalse($cache->exists('data'));
        $I->assertFalse($cache->exists('data2'));
    }
}
