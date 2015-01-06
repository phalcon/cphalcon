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

require 'php-tests/tests/PhalconTestHelper.php';

error_reporting(E_ALL | E_NOTICE | E_STRICT);

class PHPUnit_Framework_TestCase
{

	public function assertInstanceOf($className, $object)
	{
		if (get_class($object) != $className) {
			throw new Exception('Not instance of '.$className.', actually: '.get_class($object));
		}
	}

	public function assertEquals($a, $b)
	{
		if ($a != $b) {
			if(is_array($a) && is_array($b)){
				foreach($a as $k => $v){
					if(isset($b[$k])){
						if ($v != $b[$k]) {
							print_r($v);
							echo PHP_EOL;
							print_r($b[$k]);
						}
					} else {
						print_r($v);
						echo PHP_EOL;
						echo 'Not exists';
					}
				}
				throw new Exception('Not equals');
			} else {
				throw new Exception('Not equals '.print_r($a, true).' != '.print_r($b, true));
			}
		}
	}

	public function assertNotEquals($a, $b)
	{
		if ($a == $b) {
			throw new Exception('Equals '.$a.'=='.$b);
		}
	}

	public function assertFalse($a)
	{
		if ($a) {
			throw new Exception('Not false');
		}
	}

	public function assertTrue($a)
	{
		if (!$a) {
			throw new Exception('Not true');
		}
	}

	public function assertGreaterThan($a, $b)
	{
		if ($b <= $a){
			throw new Exception('Not greater than');
		}
	}

	public function markTestSkipped($message)
	{
		echo 'Skipped: ' . $message . PHP_EOL;
	}

	public static function main($className)
	{
		echo 'Testing ', $className, ' ';
		if (class_exists($className, false)) {
			$class = new $className();
			if (method_exists($class, 'setUp')) {
				$class->setUp();
			}
			$reflectionClass = new ReflectionClass($class);
			$hasSetup = $reflectionClass->hasMethod('setUp');
			foreach ($reflectionClass->getMethods() as $method) {
				$methodName = $method->getName();
				if (substr($methodName, 0, 4) == 'test') {
					if ($hasSetup) {
						$class->setUp();
					}
					$class->$methodName();
				}
			}
			echo '[OK]', ' (', memory_get_usage(true), ') (', memory_get_usage(false), ')', PHP_EOL;
		} else {
			echo '[FAILED]', PHP_EOL;
		}

	}

}

if (PHP_OS == 'Linux') {
	if (isset($_SERVER['LOGNAME']) && $_SERVER['LOGNAME']=='gutierrezandresfelipe') {
		chdir('/home/gutierrezandresfelipe/cphalcon');
	}
}

if (!extension_loaded('phalcon')) {
	throw new Exception("Sorry, but phalcon extension is not loaded");
}

try {
	if (isset($_SERVER['argv'][1])) {

		echo $_SERVER['argv'][1], PHP_EOL;

		$file = $_SERVER['argv'][1];
		require $_SERVER['argv'][1];

		PHPUnit_Framework_TestCase::main('Phalcon\Test\View\Engines\Volt\UnitTest');
	}
} catch(Exception $e){
	echo $e->getMessage(), PHP_EOL;
	echo $e->getTraceAsString(), PHP_EOL;
	//print_r($e->getTrace());
}

