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

		$view = new Phalcon_View();
		$view->setViewsDir('unit-tests/views/');
		$this->assertEquals($view->getViewsDir(), 'unit-tests/views/');

		//Standard Render
		$view->start();
		$view->render('test2', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>here</html>');

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolhere</html>');

		//Variables
		$view->setParamToView('born', 'this');

		$view->start();
		$view->render('test3', 'another');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>lol<p>this</p></html>');

		//Templates
		$view->setTemplateAfter('test');

		$view->start();
		$view->render('test3', 'other');
		$view->finish();

		$this->assertEquals($view->getContent(), '<html>zuplolhere</html>');

		$view->cleanTemplateAfter();

		//Render Levels
		$view->setRenderLevel(Phalcon_View::LEVEL_MAIN_LAYOUT);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), '<html>lolhere</html>');

		$view->setRenderLevel(Phalcon_View::LEVEL_LAYOUT);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'lolhere');

		$view->setRenderLevel(Phalcon_View::LEVEL_ACTION_VIEW);

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'here');

	}
}