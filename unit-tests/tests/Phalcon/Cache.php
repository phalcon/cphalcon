<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

class CacheTest extends PHPUnit_Framework_TestCase
{

    public function setUp()
    {
        $iterator = new DirectoryIterator('unit-tests/cache/');
        foreach ($iterator as $item) {
            if (!$item->isDir()) {
                unlink($item->getPathname());
            }
        }
    }

    public function testOutputFileCache()
    {

        $time = date('H:i:s');

        $frontCache = new Phalcon\Cache\Frontend\Output(array(
            'lifetime' => 2
        ));

        $cache = new Phalcon\Cache\Backend\File($frontCache, array(
            'cacheDir' => 'unit-tests/cache/',
            'prefix' => 'unit'
        ));

        $this->assertFalse($cache->isStarted());

        ob_start();

        //First time cache
        $content = $cache->start('testoutput');
        $this->assertTrue($cache->isStarted());

        if ($content !== null) {
            $this->assertTrue(false);
        }

        echo $time;
        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $this->assertEquals($time, $obContent);
        $this->assertTrue(file_exists('unit-tests/cache/unittestoutput'));

        //Same cache
        $content = $cache->start('testoutput');
        $this->assertTrue($cache->isStarted());

        if ($content === null) {
            $this->assertTrue(false);
        }

        $this->assertEquals($time, $obContent);

        //Refresh cache
        sleep(3);

        $time2 = date('H:i:s');

        ob_start();

        $content = $cache->start('testoutput');
        $this->assertTrue($cache->isStarted());

        if ($content !== null) {
            $this->assertTrue(false);
        }

        echo $time2;
        $cache->save(null, null, null, true);

        $obContent2 = ob_get_contents();
        ob_end_clean();

        $this->assertNotEquals($time, $obContent2);
        $this->assertEquals($time2, $obContent2);

        //Check keys
        $keys = $cache->queryKeys();
        $this->assertEquals($keys, array(
            0 => 'unittestoutput',
        ));

        //Exists?
        $this->assertTrue($cache->exists('testoutput'));

        //Delete cache
        $this->assertTrue($cache->delete('testoutput'));

    }

    public function testDataFileCache()
    {

        $frontCache = new Phalcon\Cache\Frontend\Data();

        $cache = new Phalcon\Cache\Backend\File($frontCache, array(
            'cacheDir' => 'unit-tests/cache/'
        ));

        $this->assertFalse($cache->isStarted());

        //Save
        $cache->save('test-data', "nothing interesting");

        $this->assertTrue(file_exists('unit-tests/cache/testdata'));

        //Get
        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, "nothing interesting");

        //Save
        $cache->save('test-data', "sure, nothing interesting");

        //Get
        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, "sure, nothing interesting");

        //Exists
        $this->assertTrue($cache->exists('test-data'));

        //Delete
        $this->assertTrue($cache->delete('test-data'));

    }

    private function _prepareMemcached()
    {

        if (!extension_loaded('memcache')) {
            $this->markTestSkipped('Warning: memcache extension is not loaded');
            return false;
        }

        return false;

        $memcache = new Memcache();
        $this->assertFalse(!$memcache->connect('127.0.0.1', 11211));

        return $memcache;
    }

    public function testOutputMemcacheCache()
    {

        $memcache = $this->_prepareMemcached();
        if (!$memcache) {
            return false;
        }

        $memcache->delete('test-output');

        $time = date('H:i:s');

        $frontCache = new Phalcon\Cache\Frontend\Output(array(
            'lifetime' => 2
        ));

        $cache = new Phalcon\Cache\Backend\Memcache($frontCache);

        ob_start();

        //First time cache
        $content = $cache->start('test-output');
        if ($content !== null) {
            $this->assertTrue(false);
        }

        echo $time;

        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $this->assertEquals($time, $obContent);
        $this->assertEquals($time, $memcache->get('test-output'));

        //Expect same cache
        $content = $cache->start('test-output');
        if ($content === null) {
            $this->assertTrue(false);
        }

        $this->assertEquals($time, $obContent);

        //Refresh cache
        sleep(3);

        $time2 = date('H:i:s');

        ob_start();

        $content = $cache->start('test-output');
        if($content!==null){
            $this->assertTrue(false);
        }
        echo $time2;
        $cache->save(null, null, null, true);

        $obContent2 = ob_get_contents();
        ob_end_clean();

        $this->assertNotEquals($time, $obContent2);
        $this->assertEquals($time2, $obContent2);
        $this->assertEquals($time2, $memcache->get('test-output'));

        //Check if exists
        $this->assertTrue($cache->exists('test-output'));

        //Delete entry from cache
        $this->assertTrue($cache->delete('test-output'));

        $memcache->close();

    }

    public function testDataMemcachedCache()
    {

        $memcache = $this->_prepareMemcached();
        if (!$memcache) {
            return false;
        }

        $memcache->delete('test-data');

        $frontCache = new Phalcon\Cache\Frontend\Data();

        $cache = new Phalcon\Cache\Backend\Memcache($frontCache, array(
            'host' => '127.0.0.1',
            'port' => '11211'
        ));

        $data = array(1, 2, 3, 4, 5);

        $cache->save('test-data', $data);

        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, $data);

        $cache->save('test-data', "sure, nothing interesting");

        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, "sure, nothing interesting");

        $this->assertEquals($cache->queryKeys(), array(
            0 => 'test-data',
        ));

        //Check if exists
        $this->assertTrue($cache->exists('test-data'));

        //Delete
        $this->assertTrue($cache->delete('test-data'));

    }

    protected function _prepareApc()
    {

        if (!extension_loaded('apc')) {
            $this->markTestSkipped('apc extension is not loaded');
            return false;
        }

        return true;
    }

    public function testOutputApcCache()
    {

        $ready = $this->_prepareApc();
        if (!$ready) {
            return false;
        }

        apc_delete('_PHCAtest-output');

        $time = date('H:i:s');

        $frontCache = new Phalcon\Cache\Frontend\Output(array(
            'lifetime' => 2
        ));

        $cache = new Phalcon\Cache\Backend\Apc($frontCache);

        ob_start();

        //First time cache
        $content = $cache->start('test-output');
        if ($content !== null) {
            $this->assertTrue(false);
        }

        echo $time;

        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $this->assertEquals($time, $obContent);
        $this->assertEquals($time, apc_fetch('_PHCAtest-output'));

        //Expect same cache
        $content = $cache->start('test-output');
        if ($content === null) {
            $this->assertTrue(false);
        }

        $this->assertEquals($content, $obContent);
        $this->assertEquals($content, apc_fetch('_PHCAtest-output'));

        //Query keys
        $keys = $cache->queryKeys();
        $this->assertEquals($keys, array(
            0 => '_PHCAtest-output',
        ));

        //Delete entry from cache
        $this->assertTrue($cache->delete('test-output'));

    }

    public function testDataApcCache()
    {

        $ready = $this->_prepareApc();
        if (!$ready) {
            return false;
        }

        apc_delete('_PHCAtest-data');

        $frontCache = new Phalcon\Cache\Frontend\Data();

        $cache = new Phalcon\Cache\Backend\Apc($frontCache);

        $data = array(1, 2, 3, 4, 5);

        $cache->save('test-data', $data);

        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, $data);

        $cache->save('test-data', "sure, nothing interesting");

        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, "sure, nothing interesting");

        $this->assertTrue($cache->delete('test-data'));

    }

    protected function _prepareMongo()
    {

        if (!extension_loaded('mongo')) {
            $this->markTestSkipped('mongo extension is not loaded');
            return false;
        }

        return true;
    }

    public function testOutputMongoCache()
    {

        $ready = $this->_prepareMongo();
        if (!$ready) {
            return false;
        }

        //remove existing
        $mongo = new Mongo();
        $database = $mongo->phalcon_test;
        $collection = $database->caches;
        $collection->remove();

        $time = date('H:i:s');

        $frontCache = new Phalcon\Cache\Frontend\Output(array(
            'lifetime' => 2
        ));

        $cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
            'server' => 'mongodb://localhost',
            'db' => 'phalcon_test',
            'collection' => 'caches'
        ));

        ob_start();

        //First time cache
        $content = $cache->start('test-output');
        if ($content !== null) {
            $this->assertTrue(false);
        }

        echo $time;

        $cache->save(null, null, null, true);

        $obContent = ob_get_contents();
        ob_end_clean();

        $this->assertEquals($time, $obContent);

        $document = $collection->findOne(array('key' => 'test-output'));
        $this->assertTrue(is_array($document));
        $this->assertEquals($time, $document['data']);

        //Expect same cache
        $content = $cache->start('test-output');
        if ($content === null) {
            $this->assertTrue(false);
        }

        $document = $collection->findOne(array('key' => 'test-output'));
        $this->assertTrue(is_array($document));
        $this->assertEquals($time, $document['data']);

        //Query keys
        $keys = $cache->queryKeys();
        $this->assertEquals($keys, array(
            0 => 'test-output',
        ));

        //Exists
        $this->assertTrue($cache->exists('test-output'));

        //Delete entry from cache
        $this->assertTrue($cache->delete('test-output'));

    }

    public function testDataMongoCache()
    {

        $ready = $this->_prepareMongo();
        if (!$ready) {
            return false;
        }

        //remove existing
        $mongo = new Mongo();
        $database = $mongo->phalcon_test;
        $collection = $database->caches;
        $collection->remove();

        $frontCache = new Phalcon\Cache\Frontend\Data();

        $cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
            'mongo' => $mongo,
            'db' => 'phalcon_test',
            'collection' => 'caches'
        ));

        $data = array(1, 2, 3, 4, 5);

        $cache->save('test-data', $data);

        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, $data);

        $cache->save('test-data', "sure, nothing interesting");

        $cachedContent = $cache->get('test-data');
        $this->assertEquals($cachedContent, "sure, nothing interesting");

        //Exists
        $this->assertTrue($cache->exists('test-data'));

        $this->assertTrue($cache->delete('test-data'));

    }

}