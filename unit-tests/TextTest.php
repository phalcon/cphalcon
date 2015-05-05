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
 | Authors: Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

use Phalcon\Text;

class TextTest extends PHPUnit_Framework_TestCase
{
	public function testCamelize()
	{
		$this->assertEquals(Text::camelize('coco_bongo'), 'CocoBongo');

		$this->assertEquals(Text::camelize('Test_strinG'), 'TestStrinG');
		$this->assertEquals(Text::camelize('Test_strinGvar'), 'TestStringvar');

		$this->assertEquals(Text::camelize('HELLO_WORLD'), 'HelloWorlD');

		$this->assertEquals(Text::camelize('HELLO'), 'HellO');
		$this->assertEquals(Text::camelize('HELLO_world'), 'HelloWorld');

		$this->assertEquals(Text::camelize('hello__world'), 'Hello_world');
	}

	public function testUncamelize()
	{
		$this->assertEquals(Text::uncamelize('CocoBongo'), 'coco_bongo');
		$this->assertEquals(Text::uncamelize('TestStrinG'), 'test_strin_g');
	}

	public function testIncrement()
	{
		$this->assertEquals($str = Text::increment('a'), 'a_1');
		$this->assertEquals($str = Text::increment($str), 'a_2');

		$this->assertEquals($str = Text::increment('b_43'), 'b_44');
		$this->assertEquals($str = Text::increment($str), 'b_45');

		// Test separator
		$this->assertEquals($str = Text::increment('a', '.'), 'a.1');
		$this->assertEquals($str = Text::increment($str, '.'), 'a.2');

		$this->assertEquals($str = Text::increment('b.43', '.'), 'b.44');
		$this->assertEquals($str = Text::increment($str, '.'), 'b.45');
	}

	public function testRandom()
	{
		// Test \Phalcon\Text::RANDOM_ALNUM or default
		$this->assertRegExp('#^[a-zA-Z0-9]{8}$#', Text::random());

		// Test \Phalcon\Text::RANDOM_ALPHA
		$this->assertRegExp('#^[a-zA-Z]{12}$#', Text::random(Text::RANDOM_ALPHA, 12));

		// Test \Phalcon\Text::RANDOM_HEXDEC
		$this->assertRegExp('#^[a-f0-9]{32}$#', Text::random(Text::RANDOM_HEXDEC, 32));

		// Test \Phalcon\Text::RANDOM_NOZERO
		$this->assertRegExp('#^[1-9]{6}$#', Text::random(Text::RANDOM_NOZERO, 6));

		// Test \Phalcon\Text::RANDOM_NUMERIC
		$this->assertRegExp('#^[0-9]{10}$#', Text::random(Text::RANDOM_NUMERIC, 10));
	}

	public function testStartsWith()
	{
		$this->assertTrue(Text::startsWith('Hello', 'He'));
		$this->assertTrue(Text::startsWith('Hello', 'he'));

		// Test don't ignore case
		$this->assertFalse(Text::startsWith('Hello', 'he', false));
	}

	public function testEndsWith()
	{
		$this->assertTrue(Text::endsWith('Hello', 'llo'));
		$this->assertTrue(Text::endsWith('Hello', 'LLO'));

		// Test don't ignore case
		$this->assertFalse(Text::endsWith('Hello', 'LLO', false));
	}

	public function testLower()
	{
		$this->assertEquals(Text::lower('hello world!'), 'hello world!');
		$this->assertEquals(Text::lower('HeLLo World!'), 'hello world!');
		$this->assertEquals(Text::lower('HELLO WORLD!'), 'hello world!');

		// Test multi-bytes encoding
		$this->assertEquals(Text::lower('привет мир!'), 'привет мир!');
		$this->assertEquals(Text::lower('ПриВЕт Мир!'), 'привет мир!');
		$this->assertEquals(Text::lower('ПРИВЕТ МИР!'), 'привет мир!');

		$this->assertEquals(Text::lower('männer'), 'männer');
		$this->assertEquals(Text::lower('mÄnnER'), 'männer');
		$this->assertEquals(Text::lower('MÄNNER'), 'männer');
	}

	public function testUpper()
	{
		$this->assertEquals(Text::upper('HELLO WORLD!'), 'HELLO WORLD!');
		$this->assertEquals(Text::upper('HeLLo World!'), 'HELLO WORLD!');
		$this->assertEquals(Text::upper('hello world!'), 'HELLO WORLD!');

		// Test multi-bytes encoding
		$this->assertEquals(Text::upper('ПРИВЕТ МИР!'), 'ПРИВЕТ МИР!');
		$this->assertEquals(Text::upper('ПриВЕт Мир!'), 'ПРИВЕТ МИР!');
		$this->assertEquals(Text::upper('привет мир!'), 'ПРИВЕТ МИР!');

		$this->assertEquals(Text::upper('MÄNNER'), 'MÄNNER');
		$this->assertEquals(Text::upper('mÄnnER'), 'MÄNNER');
		$this->assertEquals(Text::upper('männer'), 'MÄNNER');
	}

	public function testConcat()
	{
		$this->assertEquals(Text::concat('/', '/tmp/', '/folder_1/', '/folder_2', 'folder_3/'), '/tmp/folder_1/folder_2/folder_3/');
		$this->assertEquals(Text::concat('.', 'test.', '.test2', 'test', '.34'), 'test.test2.test.34');
	}
}