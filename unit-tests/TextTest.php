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

class TextTest extends PHPUnit_Framework_TestCase
{

	public function testCamelize()
	{
		$camelizeTests = array (
		  'camelize' => 'Camelize',
		  'CameLiZe' => 'Camelize',
		  'cAmeLize' => 'Camelize',
		  '_camelize' => 'Camelize',
		  '123camelize' => '123camelize',
		  'c_a_m_e_l_i_z_e' => 'CAMELIZE',
		  'Camelize' => 'Camelize',
		  'camel_ize' => 'CamelIze',
		  'CameLize' => 'Camelize',
		  'c-a-m-e-l-i-z-e' => 'CAMELIZE',
		  'camel-ize' => 'CamelIze',
		);
		foreach ($camelizeTests as $str => $camelized) {
			$this->assertEquals($camelized, \Phalcon\Text::camelize($str));
		}

	}

	public function testUncamelize()
	{
		$uncamelizeTests = array (
		  'camelize' => 'camelize',
		  'CameLiZe' => 'came_li_ze',
		  'cAmeLize' => 'c_ame_lize',
		  '_camelize' => '_camelize',
		  '123camelize' => '123camelize',
		  'c_a_m_e_l_i_z_e' => 'c_a_m_e_l_i_z_e',
		  'Camelize' => 'camelize',
		  'camel_ize' => 'camel_ize',
		  'CameLize' => 'came_lize',
		);
		foreach ($uncamelizeTests as $str => $camelized) {
			$this->assertEquals($camelized, \Phalcon\Text::uncamelize($str));
		}
	}


}