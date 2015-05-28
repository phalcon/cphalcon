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
	| Authors: Andres Gutierrez <andres@phalconphp.com>                      |
	|          Eduar Carvajal <eduar@phalconphp.com>                         |
	+------------------------------------------------------------------------+
*/

use Phalcon\Mvc\Url;

class UrlTest extends PHPUnit_Framework_TestCase
{
	public function testGet()
	{
		$url = new Url();
		$url->setBaseUri('http://www.test.com/');

		$this->assertEquals('http://www.test.com/', $url->get(''));
		$this->assertEquals('http://www.test.com/', $url->get('/'));
		$this->assertEquals('http://www.test.com/path', $url->get('/path'));

		$url->setBaseUri('http://www.test.com/?_url=/');
		
		$this->assertEquals('http://www.test.com/?_url=/path&params=one', $url->get('/path', array('params' => 'one')));
	}
}
