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

class TranslateTest extends PHPUnit_Framework_TestCase {

	protected function _getMessages($lang){
		require 'unit-tests/messages/'.$lang.'.php';
		$translate = new Phalcon_Translate('Array', array(
			'content' => $messages
		));
		foreach($messages as $key => $value){
			$this->assertTrue(isset($translate[$key]));
			$this->assertEquals($translate[$key], $value);
			$this->assertEquals($translate->_($key), $value);
		}
	}

	public function testDict(){
		foreach(array('en', 'es', 'fr') as $lang){
			$this->_getMessages($lang);
		}
	}

}