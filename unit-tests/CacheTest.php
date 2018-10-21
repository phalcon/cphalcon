<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

require_once 'helpers/xcache.php';

use PHPUnit\Framework\TestCase;

class CacheTest extends TestCase
{

	public function setUp()
	{
		date_default_timezone_set('UTC');
		if (!file_exists('unit-tests/cache/')) {
			mkdir("unit-tests/cache/", 0766);
		}

		$iterator = new DirectoryIterator('unit-tests/cache/');
		foreach ($iterator as $item) {
			if (!$item->isDir()) {
				unlink($item->getPathname());
			}
		}
	}

	public function testDataFileCacheIncrement()
	{
		$frontCache = new Phalcon\Cache\Frontend\Data();

		$cache = new Phalcon\Cache\Backend\File($frontCache, array(
			'cacheDir' => 'unit-tests/cache/'
		));
		$cache->delete('foo');
		$cache->save('foo', "1");
		$this->assertEquals(2, $cache->increment('foo'));

		$this->assertEquals($cache->get('foo'), 2);

		$this->assertEquals($cache->increment('foo', 5), 7);
	}

	public function testDataFileCacheDecrement()
	{
		$frontCache = new Phalcon\Cache\Frontend\Data();

		$cache = new Phalcon\Cache\Backend\File($frontCache, array(
			'cacheDir' => 'unit-tests/cache/'
		));
		$cache->delete('foo');
		$cache->save('foo', "100");
		$this->assertEquals(99, $cache->decrement('foo'));

		$this->assertEquals(95, $cache->decrement('foo', 4));
	}

	/**
	 * @expectedException \Exception
	 */
	public function testDataFileCacheUnsafeKey()
	{
		$frontCache = new Phalcon\Cache\Frontend\Data();

		$cache = new Phalcon\Cache\Backend\File($frontCache, array(
			'cacheDir' => 'unit-tests/cache/',
			'safekey' => true,
			'prefix' => '!@(##' // should throw an exception, only a-zA-Z09_-. are allowed
		));
	}

	protected function _prepareApc()
	{

		if (!function_exists('apc_fetch')) {
			$this->markTestSkipped('apc extension is not loaded');
			return false;
		}

		if (ini_get('apc.enable_cli') != 1) {
			$this->markTestSkipped('apc.enable_cli must be set to 1');
			return false;
		}

		foreach (new APCIterator('user') as $counter) {
			apc_delete($counter['key']);
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
			0 => 'test-output'
		));

		//Delete entry from cache
		$this->assertTrue($cache->delete('test-output'));
	}

	protected function _prepareMongo()
	{

		if (!extension_loaded('mongo')) {
			$this->markTestSkipped('mongo extension is not loaded');
			return false;
		}

		//remove existing
		if (class_exists('MongoClient', false)) {
			$mongo = new MongoClient();
		} else {
			$mongo = new Mongo();
		}
		$database = $mongo->phalcon_test;
		$collection = $database->caches;
		$collection->remove();

		return array($mongo, $collection);
	}

	public function testOutputMongoCache()
	{

		list($ready, $collection) = $this->_prepareMongo();
		if (!$ready) {
			return false;
		}

		$time = date('H:i:s');

		$frontCache = new Phalcon\Cache\Frontend\Output(array(
			'lifetime' => 3
		));

		$cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
			'server' => 'mongodb://localhost',
			'db' => 'phalcon_test',
			'collection' => 'caches'
		));

		ob_start();

		//First time cache
		$content = $cache->start('test-output');
		$this->assertTrue($content === null);

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
		$this->assertFalse($content === null);

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
		list($ready, $collection) = $this->_prepareMongo();
		if (!$ready) {
			return false;
		}

		// Travis can be slow, especially when Valgrind is used
		$frontCache = new Phalcon\Cache\Frontend\Data(array('lifetime' => 900));

		$cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
			'mongo'      => $ready,
			'db'         => 'phalcon_test',
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

	public function testMongoIncrement()
	{
		list($ready, $collection) = $this->_prepareMongo();
		if (!$ready) {
			return false;
		}

		$frontCache = new Phalcon\Cache\Frontend\Data(
			array('lifetime' => 200)
		);

		$cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
			'mongo'      => $ready,
			'db'         => 'phalcon_test',
			'collection' => 'caches'
		));

		$cache->delete('foo');

		$cache->save('foo', 1);
		$this->assertEquals(1, $cache->get('foo'));

		$this->assertEquals(2, $cache->increment('foo'));
		$this->assertEquals(4, $cache->increment('foo', 2));
		$this->assertEquals(4, $cache->get('foo'));

		$this->assertEquals(14, $cache->increment('foo', 10));
	}

	public function testMongoDecrement()
	{
		list($ready, $collection) = $this->_prepareMongo();
		if (!$ready) {
			return false;
		}

		$frontCache = new Phalcon\Cache\Frontend\Data(array(
			'lifetime' => 200
		));

		$cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
			'mongo'      => $ready,
			'db'         => 'phalcon_test',
			'collection' => 'caches'
		));
		$cache->delete('foo');
		$cache->save('foo', 100);

		$this->assertEquals(99, $cache->decrement('foo'));
		$this->assertEquals(89, $cache->decrement('foo', 10));
		$this->assertEquals(89, $cache->get('foo'));
		$this->assertEquals(1, $cache->decrement('foo', 88));
	}

	protected function _prepareXcache()
	{
		return false;

		if (function_exists('xcache_emulation')) {
			return true;
		}

		if (!extension_loaded('xcache') || 'cli' == PHP_SAPI) {
			$this->markTestSkipped('xcache extension is not loaded');
			return false;
		}

		return true;
	}

	public function testOutputXcache()
	{

		$ready = $this->_prepareXcache();
		if (!$ready) {
			return false;
		}

		xcache_unset('_PHCXtest-output');

		$time = date('H:i:s');

		$frontCache = new Phalcon\Cache\Frontend\Output(array(
			'lifetime' => 2
		));

		$cache = new Phalcon\Cache\Backend\Xcache($frontCache, array(
			'statsKey' => '_PHCM'
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
		$this->assertEquals($time, xcache_get('_PHCXtest-output'));

		//Expect same cache
		$content = $cache->start('test-output');
		if ($content === null) {
			$this->assertTrue(false);
		}

		$this->assertEquals($content, $obContent);
		$this->assertEquals($content, xcache_get('_PHCXtest-output'));

		//Query keys
		$keys = $cache->queryKeys();
		$this->assertEquals($keys, array(
			0 => 'test-output',
		));

		//Delete entry from cache
		$this->assertTrue($cache->delete('test-output'));
	}

	public function testDataXcache()
	{
		$ready = $this->_prepareXcache();
		if (!$ready) {
			return false;
		}

		xcache_unset('_PHCXtest-data');

		$frontCache = new Phalcon\Cache\Frontend\Data();

		$cache = new Phalcon\Cache\Backend\Xcache($frontCache);

		$data = array(1, 2, 3, 4, 5);

		$cache->save('test-data', $data);

		$cachedContent = $cache->get('test-data');
		$this->assertEquals($cachedContent, $data);

		$cache->save('test-data', "sure, nothing interesting");

		$cachedContent = $cache->get('test-data');
		$this->assertEquals($cachedContent, "sure, nothing interesting");

		$this->assertTrue($cache->delete('test-data'));
	}

	public function xtestXcacheIncrement()
	{
		$ready = $this->_prepareXcache();
		if (!$ready) {
			return false;
		}

		$frontCache = new Phalcon\Cache\Frontend\Output(array(
			'lifetime' => 20
		));

		$cache = new Phalcon\Cache\Backend\Xcache($frontCache);
		$cache->delete('foo');

		$cache->save('foo', 1);
		$newValue = $cache->increment('foo');
		$this->assertEquals('2', $newValue);

		$newValue = $cache->increment('foo');
		$this->assertEquals('3', $newValue);

		$newValue = $cache->increment('foo', 4);
		$this->assertEquals('7', $newValue);
	}

	public function xtestXcacheDecr()
	{
		$ready = $this->_prepareXcache();
		if (!$ready) {
			return false;
		}

		$frontCache = new Phalcon\Cache\Frontend\Output(array(
			'lifetime' => 20
		));

		$cache = new Phalcon\Cache\Backend\Xcache($frontCache);
		$cache->delete('foo');

		$cache->save('foo', 20);
		$newValue = $cache->decrement('foo');
		$this->assertEquals('19', $newValue);

		$newValue = $cache->decrement('foo');
		$this->assertEquals('18', $newValue);

		$newValue = $cache->decrement('foo', 4);
		$this->assertEquals('14', $newValue);
	}

	public function testCacheFileFlush()
	{
		$frontCache = new Phalcon\Cache\Frontend\Data(array('lifetime' => 10));

		// File
		$cache = new Phalcon\Cache\Backend\File($frontCache, array(
			'cacheDir' => 'unit-tests/cache/',
		));

		$cache->save('data', "1");
		$cache->save('data2', "2");

		$this->assertTrue($cache->flush());

		$this->assertFalse(file_exists('unit-tests/cache/data'));
		$this->assertFalse(file_exists('unit-tests/cache/data2'));
	}

	public function testCacheMemoryFlush()
	{
		$frontCache = new Phalcon\Cache\Frontend\Data(array('lifetime' => 10));

		// Memory
		$cache = new Phalcon\Cache\Backend\Memory($frontCache);

		$cache->save('data', "1");
		$cache->save('data2', "2");

		$this->assertTrue($cache->flush());

		$this->assertFalse($cache->exists('data'));
		$this->assertFalse($cache->exists('data2'));
	}

	public function testCacheMongoFlush()
	{
		// Mongo
		list($ready, $collection) = $this->_prepareMongo();
		if (!$ready) {
			return false;
		}

		$frontCache = new Phalcon\Cache\Frontend\Data(array(
			'lifetime' => 10
		));

		$cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
			'mongo' => $ready,
			'db' => 'phalcon_test',
			'collection' => 'caches'
		));

		$cache->save('data', "1");
		$cache->save('data2', "2");

		$this->assertTrue($cache->flush());

		$this->assertFalse($cache->exists('data'));
		$this->assertFalse($cache->exists('data2'));
	}

	public function testCacheXcacheFlush()
	{
		$frontCache = new Phalcon\Cache\Frontend\Data(array('lifetime' => 10));

		// Xcache
		$ready = $this->_prepareXcache();
		if (!$ready) {
			return false;
		}

		$cache = new Phalcon\Cache\Backend\Xcache($frontCache, array(
			'statsKey' => '_PHCM'
		));

		$cache->save('data', "1");
		$cache->save('data2', "2");

		$this->assertTrue($cache->flush());

		$this->assertFalse($cache->exists('data'));
		$this->assertFalse($cache->exists('data2'));
	}
}
