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

class MyMiddleware implements Phalcon\Mvc\Micro\MiddlewareInterface
{
	protected $_number = 0;

	public function call(\Phalcon\Mvc\Micro $application)
	{
		$this->_number++;
	}

	public function getNumber()
	{
		return $this->_number;
	}
}

class MyMiddlewareStop implements Phalcon\Mvc\Micro\MiddlewareInterface
{
	protected $_number = 0;

	public function call(\Phalcon\Mvc\Micro $application)
	{
		$application->stop();
		$this->_number++;
	}

	public function getNumber()
	{
		return $this->_number;
	}
}

class MicroMvcMiddlewareTest extends PHPUnit_Framework_TestCase
{

	public function testMicroMiddlewareSimple()
	{

		$app = new Phalcon\Mvc\Micro();

		$app->map('/api/site', function(){
			return true;
		});

		$trace = 0;

		$app->before(function() use (&$trace) {
			$trace++;
		});

		$app->before(function() use (&$trace) {
			$trace++;
		});

		$app->after(function() use (&$trace) {
			$trace++;
		});

		$app->after(function() use (&$trace) {
			$trace++;
		});

		$app->finish(function() use (&$trace) {
			$trace++;
		});

		$app->finish(function() use (&$trace) {
			$trace++;
		});

		$app->handle('/api/site');

		$this->assertEquals($trace, 6);
	}

	public function testMicroMiddlewareClasses()
	{

		$app = new Phalcon\Mvc\Micro();

		$app->map('/api/site', function(){
			return true;
		});

		$middleware = new MyMiddleware();

		$app->before($middleware);
		$app->before($middleware);

		$app->after($middleware);
		$app->after($middleware);

		$app->finish($middleware);
		$app->finish($middleware);

		$app->handle('/api/site');

		$this->assertEquals($middleware->getNumber(), 6);
	}

	public function testMicroStopMiddlewareClasses()
	{

		$app = new Phalcon\Mvc\Micro();

		$app->map('/api/site', function(){
			return true;
		});

		$middleware = new MyMiddlewareStop();

		$app->before($middleware);
		$app->before($middleware);

		$app->after($middleware);
		$app->after($middleware);

		$app->finish($middleware);
		$app->finish($middleware);

		$app->handle('/api/site');

		$this->assertEquals($middleware->getNumber(), 3);
	}

}
