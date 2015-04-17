<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Piotr Gasiorowski <p.gasiorowski@vipserv.org>                 |
  +------------------------------------------------------------------------+
*/

use Phalcon\Di;
use Phalcon\Cache\Frontend\Output as FrontendCache;
use Phalcon\Cache\Backend\File as BackendCache;
use Phalcon\Mvc\View as View;

class ViewCacheTest extends PHPUnit_Framework_TestCase
{

	public function setUp()
	{
		if (file_exists('unit-tests/cache/')) {
			foreach (new DirectoryIterator('unit-tests/cache/') as $item) {
				$item->isDir() or unlink($item->getPathname());
			}
		} else {
			mkdir('unit-tests/cache');
		}
	}

	public function ytestCacheMethods()
	{
		$di = $this->_getDi();
		$view = new View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$this->assertEquals($view, $view->start());
		$this->assertEquals($view, $view->cache(true));
		$this->assertEquals($view, $view->render('test2', 'index'));
		$this->assertEquals($view, $view->finish());
	}

	public function testCacheDI()
	{
		$date = date("r");
		$content = '<html>' . $date . '</html>' . PHP_EOL;

		$di = $this->_getDi();
		$view = new View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');
		$view->setVar("date", $date);

		//First hit
		$view->start();
		$view->cache(true);
		$view->render('test8', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

		$view->reset();

		//Second hit
		$view->start();
		$view->cache(true);
		$view->render('test8', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

		$view->reset();

		sleep(1);

		$view->setVar("date", date("r"));

		//Third hit after 1 second
		$view->start();
		$view->cache(true);
		$view->render('test8', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

		$view->reset();

		//Four hit
		$view->start();
		$view->cache(true);
		$view->render('test8', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

	}

	public function testViewCacheIndependency()
	{
		$date = date("r");
		$content = '<html>'.$date.'</html>'.PHP_EOL;

		$di = $this->_getDi();
		$view = new View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');
		$view->setVar("date", $date);

		//First hit
		$view->start();
		$view->cache(true);
		$view->render('test8', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

		$di2 = $this->_getDi();
		$view2 = new View();
		$view2->setDI($di2);
		$view2->setViewsDir('unit-tests/views/');

		//Second hit
		$view2->start();
		$view2->cache(true);
		$view2->render('test8', 'index');
		$view2->finish();
		$this->assertEquals($view2->getContent(), $content);
	}

	public function testViewOptions()
	{
		$config = array(
			'cache' => array(
				'service' => 'otherCache',
			)
		);
		$date = date("r");
		$content = '<html>'.$date.'</html>'.PHP_EOL;

		$di = $this->_getDi('otherCache');
		$view = new View($config);
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');
		$view->setVar("date", $date);

		$view->start();
		$view->cache(true);
		$view->render('test8', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

		$view->reset();

		sleep(1);

		$view->setVar("date", date("r"));

		$view->start();
		$view->cache(true);
		$view->render('test8', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), $content);

	}

	private function _getDi($service = 'viewCache', $lifetime = 60)
	{
		$di = new Di;
		$frontendCache = new FrontendCache(array('lifetime' => $lifetime));
		$backendCache = new BackendCache($frontendCache, array('cacheDir' => 'unit-tests/cache/'));
		$di->set($service, $backendCache);
		return $di;
	}

	public static function tearDownAfterClass()
	{
		if (file_exists('unit-tests/cache/')) {
			foreach (new DirectoryIterator('unit-tests/cache/') as $item) {
				$item->isDir() or unlink($item->getPathname());
			}
		} else {
			mkdir('unit-tests/cache');
		}
	}

}
