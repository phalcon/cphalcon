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

	public function testView(){

		$view = new Phalcon_View();
		$view->setViewsDir('tests/views/');
		$this->assertEquals($view->getViewsDir(), 'tests/views/');

		//Render
		$view->start();
		$view->render('test2', 'index');
		$view->finish();
		$this->assertEquals($view->getContent(), 'here');		

		$view->start();
		$view->render('test3', 'other');
		$view->finish();
		$this->assertEquals($view->getContent(), 'lolhere');
		
		//Variables
		$view->setParamToView('born', 'this');

		$view->start();
		$view->render('test3', 'another');
		$view->finish();

		$this->assertEquals($view->getContent(), 'lolthis');			

		//Templates
		$view->setTemplateAfter('test');

		$view->start();
		$view->render('test3', 'other');
		$view->finish();

		$this->assertEquals($view->getContent(), 'zuplolhere');		

	}
}