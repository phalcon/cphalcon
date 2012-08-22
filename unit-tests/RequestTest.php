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

class RequestTest extends PHPUnit_Framework_TestCase
{

	private $_request;

	public function setUp()
	{

		$di = new Phalcon\DI();

		$di->set('filter', function(){
			return new Phalcon\Filter();
		});

		$this->_request = new Phalcon\Http\Request();
		$this->_request->setDI($di);
	}

	public function testInstanceOf()
	{
		$this->assertInstanceOf('Phalcon\Http\Request', $this->_request);
	}

	public function testInput()
	{

		$value = $this->_request->getPost('lol');
		$this->assertEquals($value, '');

		$_POST['test'] = 1;
		$value = $this->_request->getPost('test');
		$this->assertEquals($value, 1);

		$_POST['test'] = "lol<";
		$value = $this->_request->getPost('test', 'string');
		$this->assertEquals($value, 'lol');

		$_POST['test'] = "lol<";
		$value = $this->_request->getPost('test', array('string'));
		$this->assertEquals($value, 'lol');

	}

	public function testHeader()
	{

		$header = $this->_request->getHeader('LOL');
		$this->assertEquals($header, '');

		$_SERVER['HTTP_LOL'] = 'zup';
		$header = $this->_request->getHeader('LOL');
		$this->assertEquals($header, 'zup');

	}

	public function testIsAjax()
	{

		$isAjax = $this->_request->isAjax();
		$this->assertFalse($isAjax);

		$_SERVER['HTTP_X_REQUESTED_WITH'] = 'XMLHttpRequest';
		$isAjax = $this->_request->isAjax();
		$this->assertTrue($isAjax);

	}

	public function testScheme()
	{

		$this->assertEquals($this->_request->getScheme(), 'http');

		$_SERVER['HTTP_HTTPS'] = 'on';
		$this->assertEquals($this->_request->getScheme(), 'https');

	}

	public function testIsSecureRequest()
	{
		$_SERVER['HTTP_HTTPS'] = 'on';
		$this->assertTrue($this->_request->isSecureRequest());
	}


	public function testServerAddress()
	{

		$this->assertEquals($this->_request->getServerAddress(), '127.0.0.1');

		$_SERVER['SERVER_ADDR'] = '192.168.0.1';
		$this->assertEquals($this->_request->getServerAddress(), '192.168.0.1');
	}

	public function testHttpHost()
	{

		$_SERVER['HTTP_HTTPS'] = 'off';
		$_SERVER['HTTP_SERVER_NAME'] = 'localhost';
		$_SERVER['HTTP_SERVER_PORT'] = 80;
		$this->assertEquals($this->_request->getHttpHost(), 'localhost');

		$_SERVER['HTTP_HTTPS'] = 'on';
		$_SERVER['HTTP_SERVER_NAME'] = 'localhost';
		$_SERVER['HTTP_SERVER_PORT'] = 80;
		$this->assertEquals($this->_request->getHttpHost(), 'localhost:80');

		$_SERVER['HTTP_HTTPS'] = 'on';
		$_SERVER['HTTP_SERVER_NAME'] = 'localhost';
		$_SERVER['HTTP_SERVER_PORT'] = 443;
		$this->assertEquals($this->_request->getHttpHost(), 'localhost');

	}

	public function testMethod()
	{

		$_SERVER['REQUEST_METHOD'] = 'POST';
		$this->assertEquals($this->_request->getMethod(), 'POST');
		$this->assertTrue($this->_request->isPost());
		$this->assertFalse($this->_request->isGet());

		$_SERVER['REQUEST_METHOD'] = 'GET';
		$this->assertEquals($this->_request->getMethod(), 'GET');
		$this->assertTrue($this->_request->isGet());
		$this->assertFalse($this->_request->isPost());

		$_SERVER['REQUEST_METHOD'] = 'PUT';
		$this->assertEquals($this->_request->getMethod(), 'PUT');
		$this->assertTrue($this->_request->isPut());

		$_SERVER['REQUEST_METHOD'] = 'DELETE';
		$this->assertEquals($this->_request->getMethod(), 'DELETE');
		$this->assertTrue($this->_request->isDelete());

		$_SERVER['REQUEST_METHOD'] = 'OPTIONS';
		$this->assertEquals($this->_request->getMethod(), 'OPTIONS');
		$this->assertTrue($this->_request->isOptions());

		$_SERVER['REQUEST_METHOD'] = 'POST';
		$this->assertTrue($this->_request->isMethod('POST'));
		$this->assertTrue($this->_request->isMethod(array('GET', 'POST')));

		$_SERVER['REQUEST_METHOD'] = 'GET';
		$this->assertTrue($this->_request->isMethod('GET'));
		$this->assertTrue($this->_request->isMethod(array('GET', 'POST')));

	}

	public function testAcceptableContent()
	{

		$_SERVER['HTTP_ACCEPT'] = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8';
		$accept = $this->_request->getAcceptableContent();
		$this->assertEquals(count($accept), 4);

		$firstAccept = $accept[0];
		$this->assertEquals($firstAccept['accept'], 'text/html');
		$this->assertEquals($firstAccept['quality'], 1);

		$lastAccept = $accept[3];
		$this->assertEquals($lastAccept['accept'], '*/*');
		$this->assertEquals($lastAccept['quality'], 0.8);

		$this->assertEquals($this->_request->getBestAccept(), 'text/html');

	}

	public function testAcceptableCharsets()
	{

		$_SERVER['HTTP_ACCEPT_CHARSET'] = 'iso-8859-5,unicode-1-1;q=0.8';
		$accept = $this->_request->getClientCharsets();
		$this->assertEquals(count($accept), 2);

		$firstAccept = $accept[0];
		$this->assertEquals($firstAccept['charset'], 'iso-8859-5');
		$this->assertEquals($firstAccept['quality'], 1);

		$lastAccept = $accept[1];
		$this->assertEquals($lastAccept['charset'], 'unicode-1-1');
		$this->assertEquals($lastAccept['quality'], 0.8);

		$this->assertEquals($this->_request->getBestCharset(), 'iso-8859-5');

	}

	public function testAcceptableLanguage()
	{

		$_SERVER['HTTP_ACCEPT_LANGUAGE'] = 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3';
		$accept = $this->_request->getLanguages();
		$this->assertEquals(count($accept), 4);

		$firstAccept = $accept[0];
		$this->assertEquals($firstAccept['language'], 'es');
		$this->assertEquals($firstAccept['quality'], 1);

		$lastAccept = $accept[3];
		$this->assertEquals($lastAccept['language'], 'en-us');
		$this->assertEquals($lastAccept['quality'], 0.3);

		$this->assertEquals($this->_request->getBestLanguage(), 'es');

	}


}
