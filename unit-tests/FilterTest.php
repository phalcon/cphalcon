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

class IPv4Filter {

	public function filter($value){
		return filter_var($value, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);
	}

}

class FilterTest extends PHPUnit_Framework_TestCase
{

	public function testSanitizeString()
	{

		$filter = new Phalcon\Filter();

		$value = $filter->sanitize("lol", "string");
		$this->assertEquals($value, "lol");

		$value = $filter->sanitize("lol", array("string"));
		$this->assertEquals($value, "lol");

		$value = $filter->sanitize("lol<<", "string");
		$this->assertEquals($value, "lol");

	}

	public function testSanitizeInt()
	{

		$filter = new Phalcon\Filter();

		$value = $filter->sanitize(1000, "int");
		$this->assertEquals($value, "1000");

		$value = $filter->sanitize(0xFFA, "int");
		$this->assertEquals($value, "0xFFA");

		$value = $filter->sanitize("1000", "int");
		$this->assertEquals($value, "1000");

		$value = $filter->sanitize("lol", "int");
		$this->assertEquals($value, "");

		$value = $filter->sanitize("!100a019", "int");
		$this->assertEquals($value, "100019");

	}

	public function testSanitizeFloat()
	{
		$filter = new Phalcon\Filter();

		$value = $filter->sanitize(11.10, "float");
		$this->assertEquals($value, "11.10");

		$value = $filter->sanitize("11.10", "float");
		$this->assertEquals($value, "11.10");

		$value = $filter->sanitize("!100a019.01a", "float");
		$this->assertEquals($value, "100019.01");

	}

	public function testSanitizeEmail()
	{
		$filter = new Phalcon\Filter();

		$value = $filter->sanitize("some(one)@exa\\mple.com", "email");
		$this->assertEquals($value, "someone@example.com");
	}

	public function testSanitizeAlphanum()
	{

		$filter = new Phalcon\Filter();

		$value = $filter->sanitize(0, "alphanum");
		$this->assertEquals($value, "0");

		$value = $filter->sanitize(null, "alphanum");
		$this->assertEquals($value, "");

		$value = $filter->sanitize("?a&5xka\tŧ?1-s.Xa[\n", "alphanum");
		$this->assertEquals($value, "a5xka1sXa");

	}

	public function testSanitizeStriptags()
	{

		$filter = new Phalcon\Filter();

		$value = $filter->sanitize("<h1>Hello</h1>", "striptags");
		$this->assertEquals($value, "Hello");

		$value = $filter->sanitize("<h1><p>Hello</h1>", "striptags");
		$this->assertEquals($value, "Hello");

		$value = $filter->sanitize("<", "striptags");
		$this->assertEquals($value, "");

	}

	public function testSanitizeTrim()
	{

		$filter = new Phalcon\Filter();

		$value = $filter->sanitize(" Hello   ", "trim");
		$this->assertEquals($value, "Hello");

		$value = $filter->sanitize("Hello   ", "trim");
		$this->assertEquals($value, "Hello");

		$value = $filter->sanitize("   Hello", "trim");
		$this->assertEquals($value, "Hello");

		$value = $filter->sanitize("HELLO", "lower");
		$this->assertEquals($value, "hello");

		$value = $filter->sanitize("hello", "upper");
		$this->assertEquals($value, "HELLO");

	}

	public function testMultiple()
	{

		$filter = new Phalcon\Filter();

		$value = $filter->sanitize("   lol<<   ", array("string", "trim"));
		$this->assertEquals($value, "lol");
	}

	public function testAddFilter()
	{
		$filter = new Phalcon\Filter();

		$filter->add('md5', function($value) {
			$filtered = preg_replace('/[^0-9a-f]/', '', $value);
			if (strlen($filtered) != 32) {
				return false;
			}
			return $value;
		});

		$filter->add('ipv4', new IPv4Filter());

		$this->assertFalse($filter->sanitize('Lladlad12', 'md5'), false);
		$this->assertEquals($filter->sanitize(md5('why?'), 'md5'), md5('why?'));

		$this->assertEquals($filter->sanitize('00:1c:42:bf:71:22', 'ipv4'), null);
		$this->assertEquals($filter->sanitize('127.0.0.1', 'ipv4'), '127.0.0.1');

	}

}