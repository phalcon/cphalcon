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

class SessionTest extends PHPUnit_Framework_TestCase {

  public function testSession(){

    Phalcon_Session::start();    

    Phalcon_Session::set('lol', 'value');

    $this->assertEquals(Phalcon_Session::get('lol'), 'value');

    Phalcon_Session::setOptions(array(
      'uniqueId' => 'unique-session'
    ));

    $this->assertEquals(Phalcon_Session::get('lol'), '');

    Phalcon_Session::set('lol', 'another-value');
    $this->assertEquals(Phalcon_Session::get('lol'), 'another-value');    

  }

}