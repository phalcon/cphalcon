<?php

class JsonRpcClientTest extends PHPUnit_Framework_TestCase
{
	public function testClient()
	{
		$data = array('message' => 'helloword');

		$client = new Phalcon\Http\Client\Adapter\Stream('http://rpc.edu.local');

		$rpc = new Phalcon\JsonRpc\Client($client);

		$response = $rpc->call('index/index', $data);

		var_dump($response);
	}
}
