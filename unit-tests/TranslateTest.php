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

		$parameters = array(
			'en' => array(
				'hello-key' => array(
					'params' => array('name' => 'Sonny'),
					'expected' => 'Hello Sonny'
				),
				'song-key' => array(
					'params' => array('name' => 'Sonny', 'song' => 'scary movies'),
					'expected' => 'The song is Sonny, scary movies'
				),
			),
			'es' => array(
				'hello-key' => array(
					'params' => array('name' => 'Sonny'),
					'expected' => 'Hola Sonny'
				),
				'song-key' => array(
					'params' => array('name' => 'Sonny', 'song' => 'scary movies'),
					'expected' => 'La canción es Sonny, scary movies'
				),
			),
			'fr' => array(
				'hello-key' => array(
					'params' => array('name' => 'Sonny'),
					'expected' => 'Bonjour Sonny'
				),
				'song-key' => array(
					'params' => array('name' => 'Sonny', 'song' => 'scary movies'),
					'expected' => 'La chanson est Sonny, scary movies'
				),
			),
		);

		foreach($messages as $key => $value){
			if(isset($parameters[$key])){
				$this->assertTrue(isset($translate[$key]));
				$this->assertEquals($translate->_($key, $parameters[$key]['params']), $parameters[$key]['expected']);
			} else {
				$this->assertTrue(isset($translate[$key]));
				$this->assertEquals($translate[$key], $value);
				$this->assertEquals($translate->_($key), $value);
			}
		}
	}

	public function testDict(){
		foreach(array('en', 'es', 'fr') as $lang){
			$this->_getMessages($lang);
		}
	}

}