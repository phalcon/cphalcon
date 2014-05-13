<?php

class JsonRpcClientTest extends PHPUnit_Framework_TestCase
{
	public function testClient()
	{
		$data = array('message' => 'helloword');

		$client = new Phalcon\Http\Client\Adapter\Stream('http://localhost/edu/php/passport/public/');

		$rpc = new Phalcon\JsonRpc\Client($client);
		$response = $rpc->call('index/index', array(1, 2));
		var_dump($response);
	}
}
