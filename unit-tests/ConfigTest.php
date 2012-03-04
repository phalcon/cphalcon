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

class ConfigTest extends PHPUnit_Framework_TestCase {

	private $_config = array(
		"phalcon" => array(
			"baseuri" => "/phalcon/"
		),
		"models" => array(
			"metadata" => "memory"
		),
		"database" => array(
			"adapter" => "mysql",
			"host" => "localhost",
			"username" => "user",
			"password" => "passwd",
			"name" => "demo"
		),
		"test" => array(
			"parent" => array(
				"property" => 1,
			),
			"parent" => array(
				"property2" => "yeah"
			)
		)
	);

	private function _compareConfig($c, $config){

		foreach($c as $k => $v){
			$this->assertTrue(isset($config->$k));
			if(is_array($v)){				
				if(isset($config->$k)){					
					foreach($v as $kk => $vv){
						$this->assertTrue(isset($config->$k->$kk));
						if(isset($config->$k->$kk)){							
							if(is_array($vv)){
								foreach($vv as $kkk => $vvv){
									if(isset($config->$k->$kk->$kkk)){
										$this->assertTrue(isset($config->$k->$kk->$kkk));
										$this->assertEquals($vvv, $config->$k->$kk->$kkk);
									}
								}
							} else {
								$this->assertEquals($vv, $config->$k->$kk);								
							}
						} 
					}
				} 
			}
		}
		return true;
	}

	public function testIniConfig(){
		$config = new Phalcon_Config_Adapter_Ini('unit-tests/config/config.ini');		
		$this->assertTrue($this->_compareConfig($this->_config, $config));
	}

	public function testStandarConfig(){
		$config = new Phalcon_Config($this->_config);
		$this->_compareConfig($this->_config, $config);
	}

}
