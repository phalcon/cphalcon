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

class ViewEnginesTest extends PHPUnit_Framework_TestCase {

	protected function _loadMustache(){
		$this->markTestSkipped('Mustache engine could not be found');
		if(!class_exists('Mustache_Autoloader')){
			$path = 'unit-tests/engines/mustache.php/src/Mustache/Autoloader.php';
			if(file_exists($path)){
				require $path;
				Mustache_Autoloader::register();
			} else {
				$this->markTestSkipped('Mustache engine could not be found');
				return false;
			}
		}
		return true;
	}

	protected function _loadTwig(){
		if(!class_exists('Twig_Autoloader')){
			$path = 'unit-tests/engines/Twig/lib/Twig/Autoloader.php';
			if(file_exists($path)){
				require $path;
				Twig_Autoloader::register();
			} else {
				$this->markTestSkipped('Twig engine could not be found');
				return false;
			}
		}
		return true;
	}

	public function testMustacheEngine(){

		if($this->_loadMustache()==false){
			return;
		}

		$view = new Phalcon\View();
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.mhtml' => 'Mustache'
		));

		$view->setParamToView('name', 'Sonny');

		$view->start();
		$view->setRenderLevel(Phalcon\View::LEVEL_ACTION_VIEW);
		$view->render('test4', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Hello Sonny');

		$view->setParamToView('some_eval', true);

		$view->start();
		$view->setRenderLevel(Phalcon\View::LEVEL_LAYOUT);
		$view->render('test4', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Well, this is the view content: Hello Sonny.'."\n");
	}

	public function testMustacheMixedEngine(){

		if($this->_loadMustache()==false){
			return;
		}

		$view = new Phalcon\View();
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.phtml' => 'Php',
			'.mhtml' => 'Mustache'
		));

		$view->setParamToView('name', 'Sonny');

		$view->start();
		$view->setRenderLevel(Phalcon\View::LEVEL_LAYOUT);
		$view->render('test6', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Well, this is the view content: Hello Sonny.');
	}

	public function testTwigEngine(){

		if($this->_loadTwig()==false){
			return;
		}

		$view = new Phalcon\View();
		$view->setViewsDir('unit-tests/views/');

		$view->registerEngines(array(
			'.twig' => 'Twig'
		));

		$view->setParamToView('song', 'Rock n roll');

		$view->start();
		$view->setRenderLevel(Phalcon\View::LEVEL_ACTION_VIEW);
		$view->render('test7', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Hello Rock n roll!');

		$view->setParamToView('some_eval', true);

		$view->start();
		$view->setRenderLevel(Phalcon\View::LEVEL_LAYOUT);
		$view->render('test7', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'Clearly, the song is: Hello Rock n roll!.'."\n");
	}

}
