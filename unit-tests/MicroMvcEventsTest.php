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

class MicroMvcEventsTest extends PHPUnit_Framework_TestCase
{

	public function testMicroBeforeHandlers()
	{

		$trace = array();

		$app = new Phalcon\Mvc\Micro();

		$app->before(function() use (&$trace) {
			$trace[] = 1;
			return false;
		});

		$app->before(function() use (&$trace) {
			$trace[] = 1;
			return false;
		});

		$app->map('/blog', function() use (&$trace) {
			$trace[] = 1;
		});

		$app->handle('/blog');

		$this->assertEquals(count($trace), 1);
	}

	public function testMicroAfterHandlers()
	{

		$trace = array();

		$app = new Phalcon\Mvc\Micro();

		$app->after(function() use (&$trace) {
			$trace[] = 1;
		});

		$app->after(function() use (&$trace) {
			$trace[] = 1;
		});

		$app->map('/blog', function() use (&$trace) {
			$trace[] = 1;
		});

		$app->handle('/blog');

		$this->assertEquals(count($trace), 3);
	}

	public function testMicroFinishHandlers()
	{

		$trace = array();

		$app = new Phalcon\Mvc\Micro();

		$app->finish(function() use (&$trace) {
			$trace[] = 1;
		});

		$app->finish(function() use (&$trace) {
			$trace[] = 1;
		});

		$app->map('/blog', function() use (&$trace) {
			$trace[] = 1;
		});

		$app->handle('/blog');

		$this->assertEquals(count($trace), 3);
	}

	public function testMicroEvents()
	{

		$trace = array();

		$eventsManager = new Phalcon\Events\Manager();

		$eventsManager->attach('micro', function($event) use (&$trace) {
			$trace[$event->getType()] = true;
		});

		$app = new Phalcon\Mvc\Micro();

		$app->setEventsManager($eventsManager);

		$app->map('/blog', function() {

		});

		$app->handle('/blog');

		$this->assertEquals($trace, array(
			'beforeHandleRoute' => true,
			'beforeExecuteRoute' => true,
			'afterExecuteRoute' => true,
			'afterHandleRoute' => true,
		));
	}

}

