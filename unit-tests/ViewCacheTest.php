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

class ViewCacheTest extends PHPUnit_Framework_TestCase {

	public function setUp(){
		$iterator = new DirectoryIterator('unit-tests/cache/');
		foreach($iterator as $item){
			if(!$item->isDir()){
				unlink($item->getPathname());
			}
		}
	}

	public function testSetCache(){

		$view = new Phalcon_View();
		$view->setViewsDir('unit-tests/views/');

		$frontendOptions = array(
			'lifetime' => 60
		);

		$backendOptions = array(
			'cacheDir' => 'unit-tests/cache/'
		);

		$cache = Phalcon_Cache::factory('Output', 'File', $frontendOptions, $backendOptions);
		$view->setCache($cache);

		$date = date("r");

		$content = '<html>'.$date.'</html>'.PHP_EOL;

		$view->setVar("date", $date);

		$view->start();
		$view->cache(true);
		$view->render('test8', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

		sleep(1);

		$view->setVar("date", date("r"));

		$view->start();
		$view->cache(true);
		$view->render('test8', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

	}

	public function testViewOptions(){

		$config = new stdClass();
		$config->cache = new stdClass();
		$config->cache->adapter = 'File';
		$config->cache->lifetime = 3600;
		$config->cache->cacheDir = 'unit-tests/cache/';

		$view = new Phalcon_View($config);
		$view->setViewsDir('unit-tests/views/');

		$date = date("r");

		$content = '<html>'.$date.'</html>'.PHP_EOL;

		$view->setVar("date", $date);

		$view->start();
		$view->cache(true);
		$view->render('test8', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

		sleep(1);

		$view->setVar("date", date("r"));

		$view->start();
		$view->cache(true);
		$view->render('test8', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

	}

	public function testCacheOptions(){

		$view = new Phalcon_View();
		$view->setViewsDir('unit-tests/views/');

		$options = array(
			'adapter' => 'File',
			'lifetime' => 86400,
			'cacheDir' => 'unit-tests/cache/',
			'key' => 'my-view-cache',
		);

		$date = date("r");

		$content = '<html>'.$date.'</html>'.PHP_EOL;

		$view->setVar("date", $date);

		$view->start();
		$view->cache($options);
		$view->render('test8', 'leother');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

		sleep(1);

		$view->setVar("date", date("r"));

		$view->start();
		$view->cache($options);
		$view->render('test8', 'leother');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

	}

}
