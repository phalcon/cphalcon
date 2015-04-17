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

class RestHandler
{

	protected $_access = 0;

	protected $_trace = array();

	public function find()
	{
		$this->_access++;
		$this->_trace[] = 'find';
	}

	public function save()
	{
		$this->_access++;
		$this->_trace[] = 'save';
	}

	public function delete()
	{
		$this->_access++;
		$this->_trace[] = 'delete';
	}

	public function getNumberAccess()
	{
		return $this->_access;
	}

	public function getTrace()
	{
		return $this->_trace;
	}

}

class MicroMvcTest extends PHPUnit_Framework_TestCase
{

	public function testMicroClass()
	{

		$handler = new RestHandler($this);

		$app = new Phalcon\Mvc\Micro();

		$app->get('/api/site', array($handler, 'find'));
		$app->post('/api/site/save', array($handler, 'save'));
		$app->delete('/api/site/delete/1', array($handler, 'delete'));

		//Getting the url from _url using GET
		$_SERVER['REQUEST_METHOD'] = 'GET';
		$_GET['_url'] = '/api/site';

		$app->handle();

		$this->assertEquals($handler->getNumberAccess(), 1);
		$this->assertEquals($handler->getTrace(), array('find'));

		//Getting the url from _url using POST
		$_SERVER['REQUEST_METHOD'] = 'POST';
		$_GET['_url'] = '/api/site/save';

		$app->handle();

		$this->assertEquals($handler->getNumberAccess(), 2);
		$this->assertEquals($handler->getTrace(), array('find', 'save'));

		//Passing directly a URI
		$_SERVER['REQUEST_METHOD'] = 'DELETE';
		$_GET['_url'] = null;

		$app->handle('/api/site/delete/1');

		$this->assertEquals($handler->getNumberAccess(), 3);
		$this->assertEquals($handler->getTrace(), array('find', 'save', 'delete'));
	}

	/**
	 * Tests the notFound
	 *
	 * @issue T169
	 * @author Nikos Dimopoulos <nikos@niden.net>
	 * @since 2012-11-06
	*/
	public function testMicroNotFound_T169()
	{

		$handler = new RestHandler($this);
		$app = new \Phalcon\Mvc\Micro();

		$app->get('/api/site', array($handler, 'find'));
		$app->post('/api/site/save', array($handler, 'save'));

		$flag = false;

		$app->notFound(function () use (&$flag) {
			$flag = true;
		});

		$_SERVER['REQUEST_METHOD'] = 'GET';
		$_GET['_url'] = '/fourohfour';

		$app->handle();

		$this->assertTrue($flag);
	}

}
