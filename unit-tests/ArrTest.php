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
    |          ZhuZongXin <dreamsxin@qq.com>                                 |
    |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
	+------------------------------------------------------------------------+
*/

class ArrTest extends PHPUnit_Framework_TestCase
{

	public function test()
	{
		$array = array('theme' => array('one' => array('color' => array('red', 'blur', 'green'), 'fontsize' => '12'), 'two' => array('color' => array(1, 2, 3))), 'path' => 'path1');
		$noarray = 'array';
		$keys = array('theme', '*', 'color');
/*
		$ret = \Phalcon\Utils\Arr::is_assoc(array('red', 'blur', 'green'));
		$this->assertTrue(!$ret);

		$ret = \Phalcon\Utils\Arr::is_assoc($array);
		$this->assertTrue($ret);

		$ret = \Phalcon\Utils\Arr::is_array($array);
		$this->assertTrue($ret);

		$ret = \Phalcon\Utils\Arr::is_array(new ArrayObject);
		$this->assertTrue($ret);

		$ret = \Phalcon\Utils\Arr::is_array($noarray);
		$this->assertTrue(!$ret);

		$ret = \Phalcon\Utils\Arr::path($array, $keys);
		$this->assertEquals($ret, array(array('red', 'blur', 'green'), array(1, 2, 3))); 
*/
		\Phalcon\Utils\Arr::set_path($array, $keys, array('while', 'black'));
		$this->assertEquals($array, array('theme' => array('one' => array('color' => array('while', 'black'), 'fontsize' => '12'), 'two' => array('color' => array('while', 'black'))), 'path' => 'path1'));
		/*
		$ret = \Phalcon\Utils\Arr::range(5, 20);
		$this->assertEquals($ret, array(5 => 5, 10 => 10, 15 => 15, 20 => 20));

		$ret = \Phalcon\Utils\Arr::get($array, 'theme');
		$this->assertEquals($ret, array('one' => array('color' => array('while', 'black'), 'fontsize' => '12'), 'two' => array('color' => array('while', 'black'))));

		$ret = \Phalcon\Utils\Arr::extract($array, array('theme.one.color', 'path'));
		$this->assertEquals($ret, array('theme' => array('one' => array('color' => array('while', 'black'))), 'path' => 'path1'));

		$array = array(array('color' => 'green'), array('color' => 'red'));
		$ret = \Phalcon\Utils\Arr::pluck($array, 'color');
		$this->assertEquals($ret, array('green', 'red'));

		$array = array(5 => "orange", 3 => "banana");
		$ret = \Phalcon\Utils\Arr::unshift($array, 1, array('red', 'blur', 'green'));
		$this->assertEquals($ret, array(1 => array('red', 'blur', 'green'), 5 => "orange", 3 => "banana"));

		$array = array(' 1 <script></script>', ' 2 xxx ');
		$ret = \Phalcon\Utils\Arr::map(array('strip_tags', 'trim'), $array);
		$this->assertEquals($ret, array('1', '2 xxx'));

		$john = array('name' => 'john', 'children' => array('fred', 'paul', 'sally', 'jane'));
		$mary = array('name' => 'mary', 'children' => array('jane', 'myleft'));
		$ret = \Phalcon\Utils\Arr::merge($john, $mary);
		$this->assertEquals($ret, array('name' => 'mary', 'children' => array('fred', 'paul', 'sally', 'jane', 'myleft')));

		$a1 = array('name' => 'john', 'mood' => 'happy', 'food' => 'bacon');
		$a2 = array('name' => 'jack', 'food' => 'tacos', 'drink' => 'beer');
		$ret = \Phalcon\Utils\Arr::overwrite($a1, $a2);
		$this->assertEquals($ret, array('name' => 'jack', 'mood' => 'happy', 'food' => 'tacos'));

		$ret = \Phalcon\Utils\Arr::callback('Foo::bar(apple,orange)');
		$this->assertEquals($ret, array(array('Foo', 'bar'), array('apple', 'orange')));

		$array = array('set' => array('one' => 'something'), 'two' => 'other');
		$ret = \Phalcon\Utils\Arr::flatten($array);
		$this->assertEquals($ret, array('one' => 'something', 'two' => 'other'));
		*/
	}
}