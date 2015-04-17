<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
	|          Vladimir Kolesnikov <vladimir@extrememember.com>              |
	+------------------------------------------------------------------------+
*/

class RequestTest extends PHPUnit_Framework_TestCase
{

	public function testHasFiles()
	{
		$request = new \Phalcon\Http\Request();

		$_FILES = array(
			'test' => array(
				'name'     => 'name',
				'type'     => 'text/plain',
				'size'     => 1,
				'tmp_name' => 'tmp_name',
				'error'    => 0,
			)
		);

		$this->assertEquals($request->hasFiles(false), 1);
		$this->assertEquals($request->hasFiles(true), 1);

		$_FILES = array(
			'test' => array(
				'name'     => array('name1', 'name2'),
				'type'     => array('text/plain', 'text/plain'),
				'size'     => array(1, 1),
				'tmp_name' => array('tmp_name1', 'tmp_name2'),
				'error'    => array(0, 0),
			)
		);

		$this->assertEquals($request->hasFiles(false), 2);
		$this->assertEquals($request->hasFiles(true), 2);

		$_FILES = array (
			'photo' => array(
				'name' => array(
					0 => '',
					1 => '',
					2 => array(0 => '', 1 => '', 2 => ''),
					3 => array(0 => ''),
					4 => array(
						0 => array(0 => ''),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => ''),
							),
						),
					),
				),
				'type' => array(
					0 => '',
					1 => '',
					2 => array(0 => '', 1 => '', 2 => ''),
					3 => array(0 => ''),
					4 => array(
						0 => array(0 => ''),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => ''),
							),
						),
					),
				),
				'tmp_name' => array(
					0 => '',
					1 => '',
					2 => array(0 => '', 1 => '', 2 => ''),
					3 => array(0 => ''),
					4 => array(
						0 => array(0 => ''),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => ''),
							),
						),
					),
				),
				'error' => array(
					0 => 4,
					1 => 4,
					2 => array(0 => 4, 1 => 4, 2 => 4),
					3 => array(0 => 4),
					4 => array(
						0 => array(0 => 4),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => 4),
							),
						),
					),
				),
				'size' => array(
					0 => 0,
					1 => 0,
					2 => array(0 => 0, 1 => 0, 2 => 0),
					3 => array(0 => 0),
					4 => array(
						0 => array(0 => 0),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => 0),
							),
						),
					),
				),
			),
			'test' => array(
				'name' => '',
				'type' => '',
				'tmp_name' => '',
				'error' => 4,
				'size' => 0,
			),
		);

		$this->assertEquals($request->hasFiles(false), 9);
		$this->assertEquals($request->hasFiles(true), 0);
	}

	public function testGetUploadedFiles()
	{
		$request = new \Phalcon\Http\Request();

		$_FILES = array (
			'photo' => array(
				'name' => array(0 => 'f0', 1 => 'f1', 2 => array(0 => 'f2', 1 => 'f3'), 3 => array(0 => array(0 => array(0 => array(0 => 'f4'))))),
				'type' => array(0 => 'text/plain', 1 => 'text/csv', 2 => array(0 => 'image/png', 1 => 'image/gif'), 3 => array(0 => array(0 => array(0 => array(0 => 'application/octet-stream'))))),
				'tmp_name' => array(0 => 't0', 1 => 't1', 2 => array(0 => 't2', 1 => 't3'), 3 => array(0 => array(0 => array(0 => array(0 => 't4'))))),
				'error' => array(0 => 0, 1 => 0, 2 => array(0 => 0, 1 => 0), 3 => array(0 => array(0 => array(0 => array(0 => 8))))),
				'size' => array(0 => 10, 1 => 20, 2 => array(0 => 30, 1 => 40), 3 => array(0 => array(0 => array(0 => array(0 => 50))))),
			),
		);

		$all        = $request->getUploadedFiles(false);
		$successful = $request->getUploadedFiles(true);

		$this->assertEquals(count($all), 5);
		$this->assertEquals(count($successful), 4);

		for ($i=0; $i<=4; ++$i) {
			$this->assertFalse($all[$i]->isUploadedFile());
		}

		$keys = array('photo.0', 'photo.1', 'photo.2.0', 'photo.2.1', 'photo.3.0.0.0.0');
		for ($i=0; $i<=4; ++$i) {
			$this->assertEquals($all[$i]->getKey(), $keys[$i]);
		}

		$this->assertEquals($all[0]->getName(), 'f0');
		$this->assertEquals($all[1]->getName(), 'f1');
		$this->assertEquals($all[2]->getName(), 'f2');
		$this->assertEquals($all[3]->getName(), 'f3');
		$this->assertEquals($all[4]->getName(), 'f4');

		$this->assertEquals($all[0]->getTempName(), 't0');
		$this->assertEquals($all[1]->getTempName(), 't1');
		$this->assertEquals($all[2]->getTempName(), 't2');
		$this->assertEquals($all[3]->getTempName(), 't3');
		$this->assertEquals($all[4]->getTempName(), 't4');

		$this->assertEquals($successful[0]->getName(), 'f0');
		$this->assertEquals($successful[1]->getName(), 'f1');
		$this->assertEquals($successful[2]->getName(), 'f2');
		$this->assertEquals($successful[3]->getName(), 'f3');

		$this->assertEquals($successful[0]->getTempName(), 't0');
		$this->assertEquals($successful[1]->getTempName(), 't1');
		$this->assertEquals($successful[2]->getTempName(), 't2');
		$this->assertEquals($successful[3]->getTempName(), 't3');
	}

	public function xtestGetAuth()
	{
		$orgServer = $_SERVER;

		$request = new \Phalcon\Http\Request();

		$_SERVER = array(
			'PHP_AUTH_USER'	=> 'myleft',
			'PHP_AUTH_PW'	=> '123456'
		);

		$data = array('username' => 'myleft', 'password' => '123456');

		$auth = $request->getBasicAuth();

		$this->assertEquals($auth, $data);

		$_SERVER = array(
			'PHP_AUTH_DIGEST' => 'Digest username="myleft", realm="myleft", qop="auth", algorithm="MD5", uri="http://localhost:81/", nonce="nonce", nc=nc, cnonce="cnonce", opaque="opaque", response="response"'
		);

		$data = array('username' => 'myleft', 'realm' => 'myleft', 'qop' => 'auth', 'algorithm' => 'MD5', 'uri' => 'http://localhost:81/', 'nonce' => 'nonce', 'nc' => 'nc', 'cnonce' => 'cnonce', 'opaque' => 'opaque', 'response' => 'response');

		$auth = $request->getDigestAuth();
		$this->assertEquals($auth, $data);

		$_SERVER = array(
			'PHP_AUTH_DIGEST' => 'Digest username=myleft, realm=myleft, qop=auth, algorithm=MD5, uri=http://localhost:81/, nonce=nonce, nc=nc, cnonce=cnonce, opaque=opaque, response=response'
		);

		$auth = $request->getDigestAuth();
		$this->assertEquals($auth, $data);

		$_SERVER = array(
			'PHP_AUTH_DIGEST' => 'Digest username=myleft realm=myleft qop=auth algorithm=MD5 uri=http://localhost:81/ nonce=nonce nc=nc cnonce=cnonce opaque=opaque response=response'
		);

		$auth = $request->getDigestAuth();
		$this->assertEquals($auth, $data);

		$_SERVER = $orgServer;
	}

	public function testIssues1226()
	{
		$di = new Phalcon\DI\FactoryDefault();

		$request = new \Phalcon\Http\Request();
		$request->setDI($di);

		$_REQUEST = $_GET = $_POST = array(
			'id' => 1,
			'num' => 'a1a',
			'age' => 'aa',
			'phone' => ''
		);

		// get
		$this->assertEquals($request->get('id', 'int', 100), 1);

		$this->assertEquals($request->get('num', 'int', 100), 1);

		$age = $request->get('age', 'int', 100);

		$this->assertTrue(empty($age));
		$this->assertEquals($request->get('age', 'int', 100, TRUE), 100);

		$phone = $request->get('phone', 'int', 100);
		$this->assertTrue(empty($phone));
		$this->assertEquals($request->get('phone', 'int', 100, TRUE), 100);

		// getQuery
		$this->assertEquals($request->getQuery('id', 'int', 100), 1);

		$this->assertEquals($request->getQuery('num', 'int', 100), 1);

		$age = $request->getQuery('age', 'int', 100);

		$this->assertTrue(empty($age));
		$this->assertEquals($request->getQuery('age', 'int', 100, TRUE), 100);

		$phone = $request->getQuery('phone', 'int', 100);
		$this->assertTrue(empty($phone));
		$this->assertEquals($request->getQuery('phone', 'int', 100, TRUE), 100);

		// getPost
		$this->assertEquals($request->getPost('id', 'int', 100), 1);

		$this->assertEquals($request->getPost('num', 'int', 100), 1);

		$age = $request->getPost('age', 'int', 100);

		$this->assertTrue(empty($age));
		$this->assertEquals($request->getPost('age', 'int', 100, TRUE), 100);

		$phone = $request->getPost('phone', 'int', 100);
		$this->assertTrue(empty($phone));
		$this->assertEquals($request->getPost('phone', 'int', 100, TRUE), 100);
	}

	public function testIssues1265()
	{
		$di = new Phalcon\DI\FactoryDefault();

		$request = new \Phalcon\Http\Request();
		$request->setDI($di);

		$_REQUEST = $_GET = $_POST = array(
			'string' => 'hello',
			'array' => array('string' => 'world')
		);

		// get
		$this->assertEquals($request->get('string', 'string'), 'hello');
		$this->assertEquals($request->get('string', 'string', NULL, TRUE, TRUE), 'hello');

		$this->assertEquals($request->get('array', 'string'), array('string' => 'world'));
		$this->assertEquals($request->get('array', 'string', NULL, TRUE, TRUE), NULL);

		// getQuery
		$this->assertEquals($request->getQuery('string', 'string'), 'hello');
		$this->assertEquals($request->getQuery('string', 'string', NULL, TRUE, TRUE), 'hello');

		$this->assertEquals($request->getQuery('array', 'string'), array('string' => 'world'));
		$this->assertEquals($request->getQuery('array', 'string', NULL, TRUE, TRUE), NULL);

		// getPost
		$this->assertEquals($request->getPost('string', 'string'), 'hello');
		$this->assertEquals($request->getPost('string', 'string', NULL, TRUE, TRUE), 'hello');

		$this->assertEquals($request->getPost('array', 'string'), array('string' => 'world'));
		$this->assertEquals($request->getPost('array', 'string', NULL, TRUE, TRUE), NULL);
	}

	/**
	 * @requires extension fileinfo
	 */
	public function testIssues1442()
	{
		$request = new \Phalcon\Http\Request();

		$_FILES = array (
			'test' => array(
				'name'		=> 'test',
				'type'		=> 'text/plain',
				'tmp_name'	=> 'unit-tests/assets/phalconphp.jpg',
				'size'		=> 1,
				'error'		=> 0,
			)
		);

		foreach ($request->getUploadedFiles(TRUE) as $file) {
			$this->assertEquals($file->getType(), 'text/plain');
			$this->assertEquals($file->getRealType(), 'image/jpeg');
		}
	}

	public function testIssues2294()
	{
		$_SERVER['HTTP_FOO'] = 'Bar';
		$_SERVER['HTTP_BLA_BLA'] = 'boo';
		$_SERVER['HTTP_AUTH'] = true;

		$request = new \Phalcon\Http\Request();

		$oldheaders = $_SERVER;
		$headers = array();

		foreach($oldheaders as $key => $value) {
			if (strpos($key, 'HTTP_') === 0) {
			    $key = explode('_', ltrim($key, 'HTTP_'));
			    array_walk($key, function(&$k) { $k = ucfirst(strtolower($k)); });
			    $key = implode('-', $key);
			    $headers[$key] = $value;
			}
		}

		$this->assertEquals($request->getHeaders(), $headers);
	}
}
