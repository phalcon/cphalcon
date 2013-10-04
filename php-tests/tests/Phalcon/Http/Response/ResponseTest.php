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

namespace Phalcon\Test\Http\Response;

class ResponseTest extends \PHPUnit_Framework_TestCase
{

	private $_response;

	public function setUp()
	{
		$di = new \Phalcon\DI();

		$di->set('url', function(){
			$url = new \Phalcon\Mvc\Url();
			$url->setBaseUri('/');
			return $url;
		});

		$this->_response = new \Phalcon\Http\Response();

		$this->_response->setDI($di);
	}

	public function testSetHeader()
	{

		$this->_response->resetHeaders();

		$this->_response->setHeader('Content-Type', 'text/html');

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'text/html',
			)
		)), $this->_response->getHeaders());

		$this->_response->setHeader('Content-Length', '1234');

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
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

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
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

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 404 Not Found' => '',
			)
		)), $this->_response->getHeaders());

	}
	
	public function testToArrayHeader()
	{

		$this->_response->resetHeaders();

		$this->_response->setHeader('Content-Type', 'text/html');
		$this->_response->setHeader('Content-Length', '1234');
		
		$headers = $this->_response->getHeaders();
		$headersArray = $headers->toArray();
		
		$this->assertArrayHasKey('Content-Type', $headersArray);
		$this->assertArrayHasKey('Content-Length', $headersArray);
		$this->assertEquals('text/html', $headersArray['Content-Type']);
		$this->assertEquals('1234', $headersArray['Content-Length']);
	}

	public function testSetContentType()
	{

		//Without charset
		$this->_response->resetHeaders();

		$this->_response->setContentType('application/json');

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'application/json'
			)
		)), $this->_response->getHeaders());

		//With charset
		$this->_response->resetHeaders();

		$this->_response->setContentType('application/json', 'utf-8');

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'Content-Type' => 'application/json; charset=utf-8'
			)
		)), $this->_response->getHeaders());
	}

	public function testNotModifiedHeader()
	{

		$this->_response->resetHeaders();

		$this->_response->setNotModified();

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 304 Not modified' => false,
				'Status' => '304 Not modified'
			)
		)), $this->_response->getHeaders());

	}

	public function testRedirect()
	{


		//local URI
		$this->_response->resetHeaders();

		$this->_response->redirect("some/local/uri");

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 302 Found' => false,
				'Status' => '302 Found',
				'Location' => '/some/local/uri'
			)
		)), $this->_response->getHeaders());

		//Full URL
		$this->_response->resetHeaders();

		$this->_response->redirect("http://google.com", true);

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 302 Found' => false,
				'Status' => '302 Found',
				'Location' => 'http://google.com'
			)
		)), $this->_response->getHeaders());

		//HTTP code
		$this->_response->resetHeaders();

		$this->_response->redirect("http://google.com", true, 301);

		$this->assertEquals(\Phalcon\Http\Response\Headers::__set_state(array(
			'_headers' => array(
				'HTTP/1.1 301 Moved Permanently' => false,
				'Status' => '301 Moved Permanently',
				'Location' => 'http://google.com'
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

	public function testSetFileToSend()
	{
		$filename = __FILE__;
		$this->_response->setFileToSend($filename);
		ob_start();
		$this->_response->send();
		$actual   = ob_get_clean();
		$expected = file_get_contents($filename);
		$this->assertEquals($actual, $expected);
		$this->assertEquals($this->_response->isSent(), true);
	}
}
