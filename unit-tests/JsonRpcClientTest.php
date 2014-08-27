<?php

/*
 * Server demo
error_reporting(E_ALL);

try {
        $loader = new \Phalcon\Loader();

        $loader->registerDirs(
                array(
                        __DIR__ . '/controllers/',
                )
        )->register();

        $di = new \Phalcon\DI\FactoryDefault();
        $di->set('url', function () use ($config) {
                $url = new \Phalcon\Mvc\Url();
                $url->setBaseUri('jsonrpc');
                return $url;
        }, true);

        $application = new \Phalcon\Mvc\JsonRpc($di);

        echo $application->handle()->getContent();
} catch (\Exception $e) {
        echo $e->getMessage();
}              
*/

class JsonRpcClientTest extends PHPUnit_Framework_TestCase
{
	public function testClient()
	{
		$client = new Phalcon\Http\Client\Adapter\Stream('http://myleftstudio.com/jsonrpc/');

		$rpc = new Phalcon\JsonRpc\Client($client);
		$response = $rpc->call('index/index', array('message' => 'helloword'));
	}
}
