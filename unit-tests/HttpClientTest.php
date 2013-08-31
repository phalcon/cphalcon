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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

class HttpClientTest extends PHPUnit_Framework_TestCase
{

	public function test()
	{		
		$url = 'http://phalconphp.com/';
		$method = 'POST';
		$data = array('key' => 'value', 'key1' => 'value1');
		try {
			//$client = new \Phalcon\Http\Client($url, 'POST');
			$client = new \Phalcon\Http\Client;
			$client->setUrl($url);
			$client->setMethod($method);

			// $client->setAuthentication('username', 'password');
			// $client->setDigestAuthentication('username', 'password');
			// $client->setBasicAuthentication('username', 'password');

			// Set post/put/other data
			$client->setData($data);

			// Upload file
			//$client->setFiles(array('unit-tests/assets/phalconphp.jpg'));
			
			$ret = $client->getUrl();
			$this->assertEquals($ret, $url);

			$ret = $client->getMethod();
			$this->assertEquals($ret, $method);

			$ret = $client->getData();
			$this->assertEquals($ret, $data);

			$ret = $client->send();
			$this->assertTrue($ret);
			
			// $ret = $client->getResponseHeaders();
			// $ret = $client->getResponseCookies();
			// $ret = $client->getResponseBody();
			// $ret = $client->getResponseCode();
			// $ret = $client->getResponseStatus();
		} catch (Exception $ex) {
		}
	}
}
