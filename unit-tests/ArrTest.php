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
		$color1 = array('red', 'blur', 'green');
		$color2 = array('while', 'black');
		$array = array('theme' => array('one' => array('color' => $color1), 'two' => array()));
		$noarray = 'array';

		$ret = \Phalcon\Arr::is_assoc($color1);

		$ret = \Phalcon\Arr::is_assoc($array);

		$ret = \Phalcon\Arr::is_array($array);

		$ret = \Phalcon\Arr::is_array($noarray);

		$ret = \Phalcon\Arr::path($array, 'theme.*.color');

		\Phalcon\Arr::set_path($array, 'theme.*.color', $color2);

		$ret = \Phalcon\Arr::range();
	}
}