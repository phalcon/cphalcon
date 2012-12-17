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

class TextTest extends PHPUnit_Framework_TestCase
{

	public function testCamelize()
	{
		$camelizeTests = array (
			'' => '',
			'camelize' => 'Camelize',
			'CameLiZe' => 'Camelize',
			'cAmeLize' => 'Camelize',
			'_camelize' => 'Camelize',
			'123camelize' => '123camelize',
			'c_a_m_e_l_i_z_e' => 'CAMELIZE',
			'Camelize' => 'Camelize',
			'camel_ize' => 'CamelIze',
			'CameLize' => 'Camelize',
			'c-a-m-e-l-i-z-e' => 'CAMELIZE',
			'camel-ize' => 'CamelIze',
		);
		foreach ($camelizeTests as $str => $camelized) {
			$this->assertEquals($camelized, \Phalcon\Text::camelize($str));
		}

	}

	public function testUncamelize()
	{
		$uncamelizeTests = array (
			'' => '',
			'camelize' => 'camelize',
			'CameLiZe' => 'came_li_ze',
			'cAmeLize' => 'c_ame_lize',
			'_camelize' => '_camelize',
			'123camelize' => '123camelize',
			'c_a_m_e_l_i_z_e' => 'c_a_m_e_l_i_z_e',
			'Camelize' => 'camelize',
			'camel_ize' => 'camel_ize',
			'CameLize' => 'came_lize',
		);
		foreach ($uncamelizeTests as $str => $camelized) {
			$this->assertEquals($camelized, \Phalcon\Text::uncamelize($str));
		}
	}

	public function testIncrement()
	{
		$this->assertEquals(Phalcon\Text::increment('file'), 'file_1');
		$this->assertEquals(Phalcon\Text::increment('file_1'), 'file_2');
		$this->assertEquals(Phalcon\Text::increment('file_2'), 'file_3');
		$this->assertEquals(Phalcon\Text::increment('file_'), 'file_1');
	}

	public function testStartsWith()
	{
		$this->assertFalse(Phalcon\Text::startsWith("", ""));
		$this->assertFalse(Phalcon\Text::startsWith("", "hello"));
		$this->assertTrue(Phalcon\Text::startsWith("Hello", "H"));
		$this->assertTrue(Phalcon\Text::startsWith("Hello", "He"));
		$this->assertTrue(Phalcon\Text::startsWith("Hello", "Hello"));
		$this->assertFalse(Phalcon\Text::startsWith("Hello", "hel"));
		$this->assertFalse(Phalcon\Text::startsWith("Hello", "hello"));
		$this->assertFalse(Phalcon\Text::startsWith("Hello", "hello", true));
		$this->assertTrue(Phalcon\Text::startsWith("Hello", "hello", false));
		$this->assertTrue(Phalcon\Text::startsWith("Hello", "h", false));
	}

	public function testEndsWith()
	{
		$this->assertFalse(Phalcon\Text::endsWith("", ""));
		$this->assertFalse(Phalcon\Text::endsWith("", "hello"));
		$this->assertTrue(Phalcon\Text::endsWith("Hello", "o"));
		$this->assertTrue(Phalcon\Text::endsWith("Hello", "lo"));
		$this->assertTrue(Phalcon\Text::endsWith("Hello", "Hello"));
		$this->assertFalse(Phalcon\Text::endsWith("Hello", "LLO"));
		$this->assertFalse(Phalcon\Text::endsWith("Hello", "hello"));
		$this->assertFalse(Phalcon\Text::endsWith("Hello", "hello", true));
		$this->assertTrue(Phalcon\Text::endsWith("Hello", "hello", false));
		$this->assertTrue(Phalcon\Text::endsWith("Hello", "o", false));
	}

	public function testUpper()
	{
		$this->assertEquals(Phalcon\Text::upper('hello'), 'HELLO');
		$this->assertEquals(Phalcon\Text::upper('HELLO'), 'HELLO');
		$this->assertEquals(Phalcon\Text::upper('1234'), '1234');
	}

	public function testLower()
	{
		$this->assertEquals(Phalcon\Text::lower('hello'), 'hello');
		$this->assertEquals(Phalcon\Text::lower('HELLO'), 'hello');
		$this->assertEquals(Phalcon\Text::lower('1234'), '1234');
	}

	public function testRandom()
	{
		for ($i = 1; $i<10; $i++) {
			$text = Phalcon\Text::random(Phalcon\Text::RANDOM_ALNUM, $i);
			$this->assertEquals(preg_match('/[a-zA-Z0-9]+/', $text, $matches), 1);
			$this->assertEquals($matches[0], $text);
			$this->assertEquals(strlen($text), $i);
		}
		for ($i = 1; $i<10; $i++) {
			$text = Phalcon\Text::random(Phalcon\Text::RANDOM_ALPHA, $i);
			$this->assertEquals(preg_match('/[a-zA-Z]+/', $text, $matches), 1);
			$this->assertEquals($matches[0], $text);
			$this->assertEquals(strlen($text), $i);
		}
		for ($i = 1; $i<10; $i++) {
			$text = Phalcon\Text::random(Phalcon\Text::RANDOM_HEXDEC, $i);
			$this->assertEquals(preg_match('/[a-f0-9]+/', $text, $matches), 1);
			$this->assertEquals($matches[0], $text);
			$this->assertEquals(strlen($text), $i);
		}
		for ($i = 1; $i<10; $i++) {
			$text = Phalcon\Text::random(Phalcon\Text::RANDOM_NUMERIC, $i);
			$this->assertEquals(preg_match('/[0-9]+/', $text, $matches), 1);
			$this->assertEquals($matches[0], $text);
			$this->assertEquals(strlen($text), $i);
		}
		for ($i = 1; $i<10; $i++) {
			$text = Phalcon\Text::random(Phalcon\Text::RANDOM_NOZERO, $i);
			$this->assertEquals(preg_match('/[1-9]+/', $text, $matches), 1);
			$this->assertEquals($matches[0], $text);
			$this->assertEquals(strlen($text), $i);
		}
	}

}