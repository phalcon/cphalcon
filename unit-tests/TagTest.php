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

class DIDescendant extends Phalcon\DI {}

class TagTest extends PHPUnit_Framework_TestCase
{

	public function setUp()
	{
	}

	public function testIssue744()
	{
		$v = new Phalcon\Tag;

		try {
			$v->setDI(0);
			$this->assertTrue(false);
		}
		catch (Exception $e) {
			$this->assertTrue(true);
		}

		try {
			$v->setDI(new stdClass());
			$this->assertTrue(false);
		}
		catch (Exception $e) {
			$this->assertTrue(true);
		}

		try {
			$v->setDI(new Phalcon\DI());
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$v->setDI(new DIDescendant());
			$this->assertTrue(true);
		}
		catch (Exception $e) {
			$this->assertTrue(false);
		}

		try {
			$v->setDefaults(0);
			$this->assertTrue(false);
		}
		catch (Exception $e) {
			$this->assertTrue(true);
		}
	}

	public function testIssue947()
        {
		use Phalcon\Tag;
		$di = new Phalcon\DI\FactoryDefault();
		Tag::setDI($di);

		$html = Tag::radioField(array(
		    'test',
		    'value' => 1,
		    'checked' => 'checked'
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos !== FALSE);

		$html = Tag::radioField(array(
		    'test',
		    'value' => 0
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos === FALSE);

		Tag::setDefault("test", "0");
		$html = Tag::radioField(array(
		    'test',
		    'value' => 0
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos !== FALSE);
        }

}
