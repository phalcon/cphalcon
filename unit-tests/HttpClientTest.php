<?php

class HttpClientTest extends PHPUnit_Framework_TestCase
{
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
		$client = new Phalcon\Http\Client\Adapter\Curl('http://phalconphp.com/');

		$response = $client->get();

		$this->assertEquals($response->getStatusCode(), 200);
	}
}
