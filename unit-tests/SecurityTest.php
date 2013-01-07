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

class SecurityTest extends PHPUnit_Framework_TestCase
{

	public function testHash()
	{
		$security = new Phalcon\Security();

		for ($i = 8; $i < 12; $i++) {
			$hash = $security->hash('a', $i);
			$this->assertTrue($security->checkHash('a', $hash));
		}

		for ($i = 8; $i < 12; $i++) {
			$hash = $security->hash('aaaaaaaaaaaaaa', $i);
			$this->assertTrue($security->checkHash('aaaaaaaaaaaaaa', $hash));
		}
	}

}
