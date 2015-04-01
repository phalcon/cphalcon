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

class AysncTest extends PHPUnit_Framework_TestCase
{
	public function test()
	{
		if (!function_exists('ftok') || !function_exists('pcntl_fork')) {
			$this->markTestSkipped('Test skipped');
			return;
		}

		Phalcon\Async::clear();

		$id1 = Phalcon\Async::call(function () {
			return 'one1';
		});
		$id2 = Phalcon\Async::call(function () {
			return 'one2';
		});

		$ret = Phalcon\Async::recvAll();

		$this->assertEquals($ret, array($id1 => 'one1', $id2 => 'one2'));
	}
}