<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

class CryptTest extends PHPUnit_Framework_TestCase
{

	public function testEncryption()
	{

		$tests = array(
			mt_rand(0, 100) => 'Some text',
			md5(uniqid()) => str_repeat('x', mt_rand(1, 255)),
			time() => str_shuffle('abcdefeghijklmnopqrst'),
			'le$ki' => ''
		);

		$encrypt = new Phalcon\Crypt();
		foreach ($tests as $key => $test) {
			$encrypt->setKey($key);
			$encryption = $encrypt->encrypt($test);
			$this->assertEquals($encrypt->decrypt($encryption), $test);
		}

		foreach ($tests as $key => $test) {
			$encryption = $encrypt->encrypt($test, $key);
			$this->assertEquals($encrypt->decrypt($encryption, $key), $test);
		}

	}

}