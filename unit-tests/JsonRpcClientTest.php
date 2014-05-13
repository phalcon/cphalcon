<?php

class JsonRpcClientTest extends PHPUnit_Framework_TestCase
{
	public function testClient()
	{
		$data = array('message' => 'helloword');

		$client = new Phalcon\Http\Client\Adapter\Stream('http://phalcon.com');

		$rpc = new Phalcon\JsonRpc\Client($client);
	}
}
