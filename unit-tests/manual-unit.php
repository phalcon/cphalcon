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

error_reporting(E_ALL | E_NOTICE | E_STRICT);

class PHPUnit_Framework_TestCase {

	public function assertInstanceOf($className, $object){
		if(get_class($object)!=$className){
			throw new Exception('Not instance of '.get_class($object));
		}
	}

	public function assertEquals($a, $b){
		if($a!=$b){
			throw new Exception('Not equals '.$a.' != '.print_r($b, true));
		}
	}

	public function assertNotEquals($a, $b){
		if($a==$b){
			throw new Exception('Equals '.$a.'=='.$b);
		}
	}

	public function assertFalse($a){
		if($a){
			throw new Exception('Not false');
		}
	}

	public function assertTrue($a){
		if(!$a){
			throw new Exception('Not true');
		}
	}

	public function assertGreaterThan(){
		return true;
	}

	public static function main($className){
		echo 'Testing ', $className, ' ';
		if(class_exists($className, false)){
			$class = new $className();
			if(method_exists($class, 'setUp')){
				$class->setUp();
			}
			$reflectionClass = new ReflectionClass($class);
			$hasSetup = $reflectionClass->hasMethod('setUp');
			foreach($reflectionClass->getMethods() as $method){
				$methodName = $method->getName();
				if(substr($methodName, 0, 4)=='test'){
					if($hasSetup){
						$class->setUp();
					}
					$class->$methodName();
				}
			}
		}
		echo '[OK]', PHP_EOL;
	}

}

if(PHP_OS=='Linux'){
	if(isset($_SERVER['LOGNAME']) && $_SERVER['LOGNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/cphalcon');
	}
}

if(!extension_loaded('phalcon')){
	throw new Exception("Sorry, but phalcon extension is not loaded");
}

if(isset($_SERVER['argv'][1])){
	$file = $_SERVER['argv'][1];
	require $_SERVER['argv'][1];
	if(isset($_SERVER['argv'][2])){
		$className = $_SERVER['argv'][2];
	} else {
		if(preg_match('#/([a-zA-Z0-9]+)\.php$#', $_SERVER['argv'][1], $matches)){
			$className = $matches[1];
		} else {
			throw new Exception("class-name plz");
		}
	}
	PHPUnit_Framework_TestCase::main($className);
} else {
	$xml = simplexml_load_file('unit-tests/phpunit.xml');
	foreach($xml->testsuites as $suite){
		foreach($suite->testsuite->file as $file){
			$fileName = (string) $file;
			if(preg_match('#/([a-zA-Z0-9]+)\.php$#', $fileName, $matches)){
				require $fileName;
				PHPUnit_Framework_TestCase::main($matches[1]);
			} else {
				throw new Exception("$file plz");
			}
		}
	}
}
