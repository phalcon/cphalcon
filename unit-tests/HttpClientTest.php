<?php

class HttpClientTest extends PHPUnit_Framework_TestCase
{
	public function testHeader()
	{
		$header = new Phalcon\Http\Client\Header();
		$header->parse("HTTP/1.0 200 OK\r\nLocation:phalconphp.com");

		$this->assertEquals($header->get('Location'), 'phalconphp.com');
	}

	public function testUri()
	{
		$url = 'http://phalconphp.com/';

		$uri = new Phalcon\Http\Uri($url);
		$this->assertEquals($uri->build(), 'http://phalconphp.com/');

		$uri = $uri->resolve('index');
		$this->assertEquals($uri->build(), 'http://phalconphp.com/index');
	}

	public function testCurl()
	{
		if (!extension_loaded('curl')) {
			$this->markTestSkipped('Warning: curl extension is not loaded');
			return false;
		}
	
		$client = new Phalcon\Http\Client\Adapter\Curl('http://baidu.com/');

		$response = $client->get();

		$this->assertEquals($response->getStatusCode(), 200);
	}

	public function testStream()
	{
		/*
		$client = new Phalcon\Http\Client\Adapter\Stream('http://baidu.com/');

		$response = $client->get();

		$this->assertEquals($response->getStatusCode(), 200);
		*/
	}

	public function testFactory()
	{
		/*
		$client = Phalcon\Http\Client::factory('http://localhost/');

		$response = $client->get();

		$this->assertEquals($response->getStatusCode(), 200);
		*/
	}

	public function testRest()
	{
		/*
		$client = Phalcon\Http\Client::factory('http://localhost/');
		$client->setData(json_encode(array('query' => 'pahlcon')), 'application/json');
		$response = $client->get();

		$this->assertEquals($response->getStatusCode(), 200);
		*/
	}

	public function testUpload()
	{
		/*
		$client = Phalcon\Http\Client::factory('http://localhost/');
		$client->setData(array(
				new CURLFile('phalcon.jpg')
		));
		// or
		$client->setFiles('phalcon.jpg');
		// or
		$client->setFiles(array('phalcon.jpg'));
		$response = $client->post();
		*/
	}
}
