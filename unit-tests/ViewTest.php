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

class ViewTest extends PHPUnit_Framework_TestCase {

	public function testStandardRender(){
		$view = new Phalcon\View();
		$view->setBasePath(__DIR__.'/../');

		$view->setViewsDir('unit-tests/views/');
		$this->assertEquals($view->getViewsDir(), 'unit-tests/views/');

		//Standard Render
		$view->start();
		$view->render('test2', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>here</html>'.PHP_EOL);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolhere</html>'.PHP_EOL);

		//Variables
		$view->setParamToView('a_cool_var', 'le-this');

		$view->start();
		$view->render('test3', 'another');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>lol<p>le-this</p></html>'.PHP_EOL);

		//Templates
		$view->setTemplateAfter('test');

		$view->start();
		$view->render('test3', 'other');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>zuplolhere</html>'.PHP_EOL);

		$view->cleanTemplateAfter();

		//Render Levels
		$view->setRenderLevel(Phalcon\View::LEVEL_MAIN_LAYOUT);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolhere</html>'.PHP_EOL);

		$view->setRenderLevel(Phalcon\View::LEVEL_LAYOUT);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'lolhere');

		$view->setRenderLevel(Phalcon\View::LEVEL_ACTION_VIEW);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'here');

		//Pick View
		$view->setRenderLevel(Phalcon\View::LEVEL_MAIN_LAYOUT);
		$view->start();
		$view->pick('test3/yup');
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolyup</html>'.PHP_EOL);

	}

	public function testPartials(){

		$view = new Phalcon\View();
		$view->setBasePath(__DIR__.'/../');

		$view->setViewsDir('unit-tests/views/');
		$this->assertEquals($view->getViewsDir(), 'unit-tests/views/');

		$view->setParamToView('cool_var', 'le-this');

		$view->start();
		$view->render('test5', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>Hey, this is a partial, also le-this</html>'.PHP_EOL);

		$view->start();
		$view->render('test9', 'index');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>Hey, this is a partial, also le-this<br />Hey, this is a second partial, also le-this</html>'.PHP_EOL);

	}

}
