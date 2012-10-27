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

class ViewCacheTest extends PHPUnit_Framework_TestCase
{

	public function setUp()
	{
		$iterator = new DirectoryIterator('unit-tests/app/cache/');
		foreach ($iterator as $item) {
			if (!$item->isDir()) {
				unlink($item->getPathname());
			}
		}
	}

	public function testCacheDI()
	{

		$di = new Phalcon\DI();

		$di->set('viewCache', function(){
			$frontend = new Phalcon\Cache\Frontend\Output(array(
				'lifetime' => 60
			));
			return new Phalcon\Cache\Backend\File($frontend, array(
				'cacheDir' => 'unit-tests/app/cache/'
			));
		});

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);

		$view->setViewsDir('unit-tests/views/');

		$view->cache(true);

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

	public function testViewOptions()
	{

		$config = array(
			'cache' => array(
				'service' => 'otherCache',
			)
		);

		$di = new Phalcon\DI();

		$di->set('otherCache', function(){

			$frontend = new Phalcon\Cache\Frontend\Output(array(
				'lifetime' => 60
			));

			return new Phalcon\Cache\Backend\File($frontend, array(
				'cacheDir' => 'unit-tests/app/cache/'
			));

		});

		$view = new Phalcon\Mvc\View($config);
		$view->setDI($di);

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

}
