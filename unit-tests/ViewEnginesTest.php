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
  +------------------------------------------------------------------------+
*/

/**
 * Adapter to use Mustache library as templating engine
 */
class My_Mustache_Engine extends \Phalcon\Mvc\View\Engine implements \Phalcon\Mvc\View\EngineInterface
{

	protected $_mustache;

	protected $_params;

	public function __construct(\Phalcon\Mvc\ViewBaseInterface $view, \Phalcon\DiInterface $di = null)
	{
		$this->_mustache = new Mustache_Engine();
		parent::__construct($view, $di);
	}

	public function render($path, $params, $mustClean=false)
	{
		if (!isset($params['content'])) {
			$params['content'] = $this->_view->getContent();
		}

		$content = $this->_mustache->render(file_get_contents($path), $params);
		if ($mustClean) {
			$this->_view->setContent($content);
		} else {
			echo $content;
		}
	}

}

/**
 * Adapter to use Twig library as templating engine
 */
class My_Twig_Engine extends \Phalcon\Mvc\View\Engine implements \Phalcon\Mvc\View\EngineInterface
{

	protected $_twig;

	public function __construct(\Phalcon\Mvc\ViewBaseInterface $view, \Phalcon\DiInterface $di = null)
	{
		$loader = new Twig_Loader_Filesystem($view->getViewsDir());
		$this->_twig = new Twig_Environment($loader);
		parent::__construct($view, $di);
	}

	public function render($path, $params, $mustClean=false)
	{
		$view = $this->_view;
		if (!isset($params['content'])) {
			$params['content'] = $view->getContent();
		}

		if (!isset($params['view'])) {
			$params['view'] = $view;
		}

		$relativePath = str_replace($view->getViewsDir(), '', $path);
		$content = $this->_twig->render($relativePath, $params);
		if ($mustClean) {
			$this->_view->setContent($content);
		} else {
			echo $content;
		}
	}

}

class ViewEnginesTest extends PHPUnit_Framework_TestCase
{

	protected function _loadMustache()
	{
		if (!class_exists('Mustache_Autoloader')) {
			$path = 'unit-tests/engines/mustache.php/src/Mustache/Autoloader.php';
			if (file_exists($path)) {
				require $path;
				Mustache_Autoloader::register();
			} else {
				$this->markTestSkipped('Mustache engine could not be found');
				return false;
			}
		}
		return true;
	}

	protected function _loadTwig()
	{
		if (!class_exists('Twig_Autoloader')) {
			$path = 'unit-tests/engines/Twig/lib/Twig/Autoloader.php';
			if (file_exists($path)) {
				require $path;
				Twig_Autoloader::register();
			} else {
				$this->markTestSkipped('Twig engine could not be found');
				return false;
			}
		}
		return true;
	}

	public function testGetRegisteredEngines()
	{
		$expected = array(
			'.mhtml' => 'My_Mustache_Engine',
			'.phtml' => 'Phalcon\Mvc\View\Engine\Php',
			'.twig'  => 'My_Twig_Engine',
			'.volt'  => 'Phalcon\Mvc\View\Engine\Volt',
		);

		$di   = new Phalcon\DI();
		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines($expected);
		$this->assertEquals($expected, $view->getRegisteredEngines());
	}

	public function testMustacheEngine()
	{

		if ($this->_loadMustache() == false) {
			return;
		}

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.mhtml' => 'My_Mustache_Engine'
		));

		$view->setParamToView('name', 'Sonny');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_ACTION_VIEW);
		$view->render('test4', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Hello Sonny');

		$view->setParamToView('some_eval', true);

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test4', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Well, this is the view content: Hello Sonny.'."\n");
	}

	public function testMustacheMixedEngine()
	{

		if ($this->_loadMustache()==false) {
			return;
		}

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.phtml' => 'Phalcon\Mvc\View\Engine\Php',
			'.mhtml' => 'My_Mustache_Engine'
		));

		$view->setParamToView('name', 'Sonny');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test6', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Well, this is the view content: Hello Sonny.');
	}

	public function testMustacheMixedEnginePartials()
	{

		if ($this->_loadMustache()==false) {
			return;
		}

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.mhtml' => 'My_Mustache_Engine',
			'.phtml' => 'Phalcon\Mvc\View\Engine\Php',
		));

		$view->setParamToView('name', 'Sonny');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test6', 'info');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Well, this is the view content: Hello Sonny.');
	}

	public function testTwigEngine()
	{

		if ($this->_loadTwig() == false) {
			return;
		}

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.twig' => 'My_Twig_Engine'
		));

		$view->setParamToView('song', 'Rock n roll');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_ACTION_VIEW);
		$view->render('test7', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Hello Rock n roll!');

		$view->setParamToView('some_eval', true);

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test7', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Clearly, the song is: Hello Rock n roll!.'."\n");
	}

	public function testTwigMixedEngine()
	{

		if ($this->_loadTwig()==false) {
			return;
		}

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.phtml' => 'Phalcon\Mvc\View\Engine\Php',
			'.twig' => 'My_Twig_Engine'
		));

		$view->setParamToView('name', 'Sonny');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test12', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Well, this is the view content: Hello Sonny.');
	}

	public function testTwigMixedEnginePartials()
	{

		if ($this->_loadTwig()==false) {
			return;
		}

		$di = new Phalcon\DI();

		$view = new Phalcon\Mvc\View();
		$view->setDI($di);
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.twig' => 'My_Twig_Engine',
			'.phtml' => 'Phalcon\Mvc\View\Engine\Php'
		));

		$view->setParamToView('name', 'Sonny');

		$view->start();
		$view->setRenderLevel(Phalcon\Mvc\View::LEVEL_LAYOUT);
		$view->render('test12', 'info');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Well, this is the view content: Hello Sonny.');
	}

}
