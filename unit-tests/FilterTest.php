<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

class FilterTest extends PHPUnit_Framework_TestCase
{
	public function testXSS()
	{
		if (!class_exists('DOMDocument')) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		$str = '<strong style="color:blue">Click</strong><div>name</div>';
		$filter = new Phalcon\Filter;
		$ret = $filter->sanitize('<strong style="color:blue" onclick="alert(\'clicked\')">Click</strong><div style="color:expression(1+1)">name</div>', 'xssclean');

		$this->assertEquals($ret, $str);

		$ret = $filter->sanitize('1.1111', 'int!');
		$this->assertTrue(is_int($ret));

		$ret = $filter->sanitize('1.1111', 'float!');
		$this->assertTrue(is_float($ret));

		$ret = $filter->sanitize('-1.1111', 'abs');
		$this->assertTrue($ret === 1.1111);
	}
}