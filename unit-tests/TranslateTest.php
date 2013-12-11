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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

class TranslateTest extends PHPUnit_Framework_TestCase
{
	public function testBasic()
	{
		$options = array(
			'content' => array(
				'Hello!'                 => 'Привет!',
				'Hello %fname% %lname%!' => 'Привет, %fname% %lname%!',
			),
		);

		$t = new \Phalcon\Translate\Adapter\NativeArray($options);
		$this->assertEquals($options['content']['Hello!'], $t['Hello!']);
		$this->assertTrue(isset($t['Hello!']));
		$this->assertFalse(isset($t['Hi there!']));

		$actual   = $t->_('Hello %fname% %lname%!', array('fname' => 'John', 'lname' => 'Doe'));
		$expected = 'Привет, John Doe!';
		$this->assertEquals($expected, $actual);
	}
}
