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

	/**
	 * @requires extension fileinfo
	 */
	public function testEncryption()
	{

		$tests = array(
			mt_rand(0, 100) => 'Some text',
			md5(uniqid()) => str_repeat('x', mt_rand(1, 255)),
			time() => str_shuffle('abcdefeghijklmnopqrst'),
			'le$ki' => null
		);

		$encrypt = new Phalcon\Crypt();

		foreach (array(MCRYPT_MODE_ECB, MCRYPT_MODE_CBC, MCRYPT_MODE_CFB, MCRYPT_MODE_CFB, MCRYPT_MODE_NOFB) as $mode) {
			$encrypt->setMode($mode);

			foreach ($tests as $key => $test) {
				$encrypt->setKey($key);
				$encryption = $encrypt->encrypt($test);
				$this->assertEquals(rtrim($encrypt->decrypt($encryption), "\0"), $test);
			}

			foreach ($tests as $key => $test) {
				$encryption = $encrypt->encrypt($test, $key);
				$this->assertEquals(rtrim($encrypt->decrypt($encryption, $key), "\0"), $test);
			}
		}
	}

	/**
	 * @requires extension fileinfo
	 */
	public function testPadding()
	{
		$texts = array('');
		$key   = '0123456789ABCDEF0123456789ABCDEF';
		$modes = array('ecb', 'cbc', 'cfb');
		$pads  = array(
			Phalcon\Crypt::PADDING_ANSI_X_923, Phalcon\Crypt::PADDING_PKCS7,
			Phalcon\Crypt::PADDING_ISO_10126, Phalcon\Crypt::PADDING_ISO_IEC_7816_4,
			Phalcon\Crypt::PADDING_ZERO, Phalcon\Crypt::PADDING_SPACE
		);

		for ($i=1; $i<128; ++$i) {
			$texts[] = str_repeat('A', $i);
		}

		$crypt = new Phalcon\Crypt();
		$crypt->setCipher(MCRYPT_RIJNDAEL_256)->setKey($key);

		foreach ($pads as $padding) {
			$crypt->setPadding($padding);
			foreach ($modes as $mode) {
				$crypt->setMode($mode);

				foreach ($texts as $text) {
					$encrypted = $crypt->encrypt($text);
					$actual    = $crypt->decrypt($encrypted);

					$this->assertEquals($actual, $text);
				}
			}
		}
	}

	/**
	 * @requires extension fileinfo
	 */
	public function testEncryptBase64()
	{
		$crypt = new \Phalcon\Crypt();
		$crypt->setPadding(\Phalcon\Crypt::PADDING_ANSI_X_923);

		$key = 'phalcon';
		$text = 'https://github.com/phalcon/cphalcon/issues?state=open';

		$encrypted = $crypt->encryptBase64($text, $key);
		$actual = $crypt->decryptBase64($encrypted, $key);
		$this->assertEquals($actual, $text);

		$encrypted = $crypt->encryptBase64($text, $key, TRUE);
		$actual = $crypt->decryptBase64($encrypted, $key, TRUE);
		$this->assertEquals($actual, $text);
	}
}
