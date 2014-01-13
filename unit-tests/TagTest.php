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
		$di = new Phalcon\DI\FactoryDefault();
		\Phalcon\Tag::setDI($di);

		$html = \Phalcon\Tag::radioField(array(
		    'test',
		    'value' => 1,
		    'checked' => 'checked'
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos !== FALSE);

		$html = \Phalcon\Tag::radioField(array(
		    'test',
		    'value' => 0
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos === FALSE);

		\Phalcon\Tag::setDefault("test", "0");
		$html = \Phalcon\Tag::radioField(array(
		    'test',
		    'value' => 0
		));
		$pos = strpos($html, 'checked="checked"');
		$this->assertTrue($pos !== FALSE);
	 }

	public function testIssue1486()
	{
		$di = new Phalcon\DI\FactoryDefault();
		$di->getshared('url')->setBaseUri('/');
		\Phalcon\Tag::setDI($di);

		$html = \Phalcon\Tag::stylesheetLink('css/phalcon.css');
		$this->assertEquals($html, '<link rel="stylesheet" href="/css/phalcon.css" type="text/css" />'.PHP_EOL);

		$html = \Phalcon\Tag::stylesheetLink(array('css/phalcon.css'));
		$this->assertEquals($html, '<link rel="stylesheet" href="/css/phalcon.css" type="text/css" />'.PHP_EOL);

		$html = \Phalcon\Tag::javascriptInclude('js/phalcon.js');
		$this->assertEquals($html, '<script src="/js/phalcon.js" type="text/javascript"></script>'.PHP_EOL);

		$html = \Phalcon\Tag::javascriptInclude(array('js/phalcon.js'));
		$this->assertEquals($html, '<script src="/js/phalcon.js" type="text/javascript"></script>'.PHP_EOL);
	 }

	public function testIssue1662()
	{
		$di = new Phalcon\DI\FactoryDefault();
		\Phalcon\Tag::setDI($di);

		\Phalcon\Tag::setDocType(Phalcon\Tag::HTML5);

		$html = \Phalcon\Tag::getDocType();
		$this->assertEquals($html, '<!DOCTYPE html>'.PHP_EOL);
	}
}
