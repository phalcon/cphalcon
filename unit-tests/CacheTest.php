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

class CacheTest extends PHPUnit_Framework_TestCase {

	public function testOutputFileCache(){

		$frontendOptions = array(
			'lifetime' => 2
		);

		$backendOptions = array(
			'cacheDir' => 'unit-tests/cache/'
		);

		@unlink('unit-tests/cache/testoutput');

		$time = date('H:i:s');

		$cache = Phalcon_Cache::factory('Output', 'File', $frontendOptions, $backendOptions);
		$this->assertInstanceOf('Phalcon_Cache_Backend_File', $cache);
		$this->assertInstanceOf('Phalcon_Cache_Frontend_Output', $cache->getFrontend());

		ob_start();

		//First time cache
		$content = $cache->start('testoutput');
		if($content!==null){
			$this->assertTrue(false);
		}
		echo $time;
		$cache->save(null, null, null, true);

		$obContent = ob_get_contents();
		ob_end_clean();

		$this->assertEquals($time, $obContent);
		$this->assertTrue(file_exists('unit-tests/cache/testoutput'));

		//Same cache
		$content = $cache->start('testoutput');
		if($content===null){
			$this->assertTrue(false);
		}

		$this->assertEquals($time, $obContent);

		//Refresh cache
		sleep(3);

		$time2 = date('H:i:s');

		ob_start();

		$content = $cache->start('testoutput');
		if($content!==null){
			$this->assertTrue(false);
		}
		echo $time2;
		$cache->save(null, null, null, true);

		$obContent2 = ob_get_contents();
		ob_end_clean();

		$this->assertNotEquals($time, $obContent2);
		$this->assertEquals($time2, $obContent2);

		$this->assertTrue($cache->delete('testoutput'));

	}

	public function testDataFileCache(){

		$backendOptions = array(
			'cacheDir' => 'unit-tests/cache/'
		);

		@unlink('unit-tests/cache/testdata');

		$cache = Phalcon_Cache::factory('Data', 'File', null, $backendOptions);
		$this->assertInstanceOf('Phalcon_Cache_Backend_File', $cache);
		$this->assertInstanceOf('Phalcon_Cache_Frontend_Data', $cache->getFrontend());

		$cache->save('test-data', "nothing interesting");

		$this->assertTrue(file_exists('unit-tests/cache/testdata'));

		$cachedContent = $cache->get('test-data');
		$this->assertEquals($cachedContent, "nothing interesting");

		$cache->save('test-data', "sure, nothing interesting");

		$cachedContent = $cache->get('test-data');
		$this->assertEquals($cachedContent, "sure, nothing interesting");

		$this->assertTrue($cache->delete('test-data'));

	}

	private function _prepareMemcached(){

		if(!extension_loaded('memcache')){
			echo 'Warning: memcache extension is not loaded', PHP_EOL;
			return false;
		}

		$memcache = new Memcache();
		$this->assertFalse(!$memcache->connect('localhost', 11211));

		return $memcache;
	}

	public function testOutputMemcacheCache(){

		$memcache = $this->_prepareMemcached();
		if(!$memcache){
			return false;
		}

		$memcache->delete('test-output');

		$frontendOptions = array(
			'lifetime' => 2
		);

		$time = date('H:i:s');

		$cache = Phalcon_Cache::factory('Output', 'Memcache', $frontendOptions, array());
		$this->assertInstanceOf('Phalcon_Cache_Backend_Memcache', $cache);
		$this->assertInstanceOf('Phalcon_Cache_Frontend_Output', $cache->getFrontend());

		ob_start();

		//First time cache
		$content = $cache->start('test-output');
		if($content!==null){
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
		if($content===null){
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

		//Delete entry from cache
		$this->assertTrue($cache->delete('test-output'));

		$memcache->close();

	}

	public function testDataMemcachedCache(){

		$memcache = $this->_prepareMemcached();
		if(!$memcache){
			return false;
		}

		$memcache->delete('test-data');

		$backendOptions = array(
			'host' => 'localhost',
			'port' => '11211'
		);

		$cache = Phalcon_Cache::factory('Data', 'Memcache', array(), $backendOptions);
		$this->assertInstanceOf('Phalcon_Cache_Backend_Memcache', $cache);
		$this->assertInstanceOf('Phalcon_Cache_Frontend_Data', $cache->getFrontend());

		$data = array(1, 2, 3, 4, 5);

		$cache->save('test-data', $data);

		$cachedContent = $cache->get('test-data');
		$this->assertEquals($cachedContent, $data);

		$cache->save('test-data', "sure, nothing interesting");

		$cachedContent = $cache->get('test-data');
		$this->assertEquals($cachedContent, "sure, nothing interesting");

		$this->assertTrue($cache->delete('test-data'));

	}

	protected function _prepareApc(){

		if(!extension_loaded('apc')){
			echo 'Warning: apc extension is not loaded', PHP_EOL;
			return false;
		}

		return true;
	}

	public function testOutputApcCache(){

		$ready = $this->_prepareApc();
		if(!$ready){
			return false;
		}

		apc_delete('test-output');

		$frontendOptions = array(
			'lifetime' => 2
		);

		$time = date('H:i:s');

		$cache = Phalcon_Cache::factory('Output', 'Apc', $frontendOptions, array());
		$this->assertInstanceOf('Phalcon_Cache_Backend_Apc', $cache);
		$this->assertInstanceOf('Phalcon_Cache_Frontend_Output', $cache->getFrontend());

		ob_start();

		//First time cache
		$content = $cache->start('test-output');
		if($content!==null){
			$this->assertTrue(false);
		}

		echo $time;

		$cache->save(null, null, null, true);

		$obContent = ob_get_contents();
		ob_end_clean();

		$this->assertEquals($time, $obContent);
		$this->assertEquals($time, apc_fetch('test-output'));

		//Expect same cache
		$content = $cache->start('test-output');
		if($content===null){
			$this->assertTrue(false);
		}

		$this->assertEquals($content, $obContent);
		$this->assertEquals($content, apc_fetch('test-output'));

		//Delete entry from cache
		$this->assertTrue($cache->delete('test-output'));

	}

	public function testDataApcCache(){

		$ready = $this->_prepareApc();
		if(!$ready){
			return false;
		}

		apc_delete('test-data');

		$cache = Phalcon_Cache::factory('Data', 'Apc');
		$this->assertInstanceOf('Phalcon_Cache_Backend_Apc', $cache);
		$this->assertInstanceOf('Phalcon_Cache_Frontend_Data', $cache->getFrontend());

		$data = array(1, 2, 3, 4, 5);

		$cache->save('test-data', $data);

		$cachedContent = $cache->get('test-data');
		$this->assertEquals($cachedContent, $data);

		$cache->save('test-data', "sure, nothing interesting");

		$cachedContent = $cache->get('test-data');
		$this->assertEquals($cachedContent, "sure, nothing interesting");

		$this->assertTrue($cache->delete('test-data'));

	}

}