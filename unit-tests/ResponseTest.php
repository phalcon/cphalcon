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

class ResponseTest extends PHPUnit_Framework_TestCase
{

	private $_response;

	public function setUp()
	{
		$this->_response = new Phalcon\Http\Response();
	}

	public function testInstanceOf()
	{
		$this->assertInstanceOf('Phalcon\Http\Response', $this->_response);
	}

	public function testSetHeader()
	{

		$this->_response->resetHeaders();

		$this->_response->setHeader('Content-Type', 'text/html');

		$this->assertEquals(Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'text/html',
			)
		)), $this->_response->getHeaders());

		$this->_response->setHeader('Content-Length', '1234');

		$this->assertEquals(Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'text/html',
				'Content-Length' => '1234'
			)
		)), $this->_response->getHeaders());

	}

	public function testSetStatusHeader()
	{

		$this->_response->resetHeaders();

		$this->_response->setStatusCode(404, "Not Found");

		$this->assertEquals(Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 404 Not Found' => '',
				'Status' => '404 Not Found'
			)
		)), $this->_response->getHeaders());

	}

	public function testSetRawHeader()
	{

		$this->_response->resetHeaders();

		$this->_response->setRawHeader("HTTP/1.1 404 Not Found");

		$this->assertEquals(Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 404 Not Found' => '',
			)
		)), $this->_response->getHeaders());

	}

	public function testNotModifiedHeader()
	{

		$this->_response->resetHeaders();

		$this->_response->setNotModified();

		$this->assertEquals(Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 304 Not modified' => false,
				'Status' => '304 Not modified'
			)
		)), $this->_response->getHeaders());

	}

	public function testContent()
	{

		$this->_response->setContent('<h1>Hello');
		$this->assertEquals($this->_response->getContent(), '<h1>Hello');

		$this->_response->appendContent('</h1>');
		$this->assertEquals($this->_response->getContent(), '<h1>Hello</h1>');

	}

}