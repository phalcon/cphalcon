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

use Phalcon\DI\FactoryDefault;
use Phalcon\Session\Bag;

class BagTest extends PHPUnit_Framework_TestCase
{
	/**
	 * @covers \Phalcon\Session\Bag::get()
	 * @covers \Phalcon\Session\Bag::set()
	 * @covers \Phalcon\Session\Bag::__get()
	 * @covers \Phalcon\Session\Bag::__set()
	 */
	public function testGetSet()
	{
		new FactoryDefault();
		@session_start();

		// Using getters and setters.

		$bag = new Bag('test1');
		$bag->set('a', ['b' => 'c']);
		$this->assertEquals(['b' => 'c'], $bag->get('a'));

		// Using direct access.

		$bag        = new Bag('test2');
		$bag->{'a'} = ['b' => 'c'];
		$this->assertEquals(['b' => 'c'], $bag->{'a'});

		// Using direct access with initialising a variable.

		$bag             = new Bag('test3');
		$bag->{'a'}['b'] = 'c';
		$this->assertEquals(['b' => 'c'], $bag->{'a'});
	}
}