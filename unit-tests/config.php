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

if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		$baseDir = '/home/gutierrezandresfelipe/phalcon';
		chdir($baseDir);
	}
}

function compare_config($c, $config){
	foreach($c as $k => $v){
		if(is_array($v)){
			if(isset($config->$k)){
				echo 'isset config->'.$k.' [OK]', PHP_EOL;
				foreach($v as $kk => $vv){
					if(isset($config->$k->$kk)){
						echo 'isset config->'.$k.'->'.$kk.' [OK]', PHP_EOL;
						if(is_array($vv)){
							foreach($vv as $kkk => $vvv){
								if(isset($config->$k->$kk->$kkk)){
									echo 'isset config->'.$k.'->'.$kk.'->'.$kkk.' [OK]', PHP_EOL;
									if($vvv==$config->$k->$kk->$kkk){
										echo 'equals config->'.$k.'->'.$kk.'->'.$kkk.' [OK]', PHP_EOL;
									} else {
										echo 'equals config->'.$k.'->'.$kk.'->'.$kkk.' [FAILED]', PHP_EOL;
										return false;
									}
								}
							}
						} else {
							if($vv==$config->$k->$kk){
								echo 'equals config->'.$k.'->'.$kk.' [OK]', PHP_EOL;
							} else {
								echo 'equals config->'.$k.'->'.$kk.' [FAILED]', PHP_EOL;
								return false;
							}
						}
					} else {
						echo 'isset config->'.$k.'->'.$kk.' [FAILED]', PHP_EOL;
						return false;
					}
				}
			} else {
				echo 'isset config->'.$k.' [FAILED]', PHP_EOL;
				return false;
			}
		}
	}
	return true;
}

try {

	$config = new Phalcon_Config_Adapter_Ini('tests/config.ini');


	$c = array(
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
	if(compare_config($c, $config)===false){
		return false;
	}

	$config = new Phalcon_Config($c);
	if(compare_config($c, $config)===false){
		return false;
	}


}
catch(Exception $e){

}
