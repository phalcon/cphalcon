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

class FilterTest extends PHPUnit_Framework_TestCase {

	public function testSanitize(){

		$filter = new Phalcon_Filter();

		$value = $filter->sanitize("lol", "string");
		$this->assertEquals($value, "lol");

		$value = $filter->sanitize("lol", array("string"));
		$this->assertEquals($value, "lol");

		$value = $filter->sanitize("lol<<", "string");
		$this->assertEquals($value, "lol");

		$value = $filter->sanitize("lol", "int");
		$this->assertEquals($value, "");

		$value = $filter->sanitize("!100a019", "int");
		$this->assertEquals($value, "100019");

		$value = $filter->sanitize("!100a019.01a", "float");
		$this->assertEquals($value, "100019.01");

		$value = $filter->sanitize("some(one)@exa\\mple.com", "email");
		$this->assertEquals($value, "someone@example.com");

		$value = $filter->sanitize("?a&5xka\tŧ?1-s.Xa[\n", "alphanum");
		$this->assertEquals($value, "a5xka1sXa");

		$value = $filter->filter("<h1>Hello</h1>", "striptags");
		$this->assertEquals($value, "Hello");

		$value = $filter->filter("<h1><p>Hello</h1>", "striptags");
		$this->assertEquals($value, "Hello");

		$value = $filter->filter(" Hello   ", "extraspaces");
		$this->assertEquals($value, "Hello");

		$value = $filter->filter("Hello   ", "extraspaces");
		$this->assertEquals($value, "Hello");

		$value = $filter->filter("   Hello", "extraspaces");
		$this->assertEquals($value, "Hello");

		$value = $filter->sanitizeAndFilter("   lol<<   ", array("string", "extraspaces"));
		$this->assertEquals($value, "lol");

	}

}