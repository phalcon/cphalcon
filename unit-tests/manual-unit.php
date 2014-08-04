<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

if (function_exists('xhprof_enable')) {
	xhprof_enable(XHPROF_FLAGS_CPU + XHPROF_FLAGS_MEMORY);
}

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

	public function assertCount($cnt, $a)
	{
		if (count($a) != $cnt) {
			throw new Exception('count');
		}
	}

	public function assertEmpty($v)
	{
		if (!empty($v)) {
			throw new Exception('not empty');
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

			gc_collect_cycles();

			$m = microtime(true);
			$mm = memory_get_usage(true);
			$mf = memory_get_usage(false);

			foreach ($reflectionClass->getMethods() as $method) {
				$methodName = $method->getName();
				if (substr($methodName, 0, 4) == 'test') {
					if ($hasSetup) {
						$class->setUp();
					}
					$class->$methodName();
				}
			}
			echo '[OK]', ' (', memory_get_usage(true) - $mm, ') (', memory_get_usage(false) - $mf, ') (', sprintf("%.4f", (microtime(true) - $m) * 1000), ')', PHP_EOL;
		} else {
			echo '[FAILED]', PHP_EOL;
		}

	}

}

if (PHP_OS == 'Linux') {
	if(isset($_SERVER['LOGNAME']) && $_SERVER['LOGNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/cphalcon');
	}
}

if (!extension_loaded('phalcon')) {
	throw new Exception("Sorry, but phalcon extension is not loaded");
}

try {
	if (isset($_SERVER['argv'][1])) {
		$file = $_SERVER['argv'][1];
		require $_SERVER['argv'][1];
		if (isset($_SERVER['argv'][2])) {
			$className = $_SERVER['argv'][2];
		} else {
			if (preg_match('#/([a-zA-Z0-9]+)\.php$#', $_SERVER['argv'][1], $matches)) {
				$className = $matches[1];
			} else {
				throw new Exception("class-name plz");
			}
		}
		PHPUnit_Framework_TestCase::main($className);
	} else {
		$xml = simplexml_load_file('unit-tests/phpunit.xml');
		foreach ($xml->testsuites as $suite) {
			foreach ($suite->testsuite->file as $file) {
				$fileName = (string) $file;
				if (preg_match('#/([a-zA-Z0-9]+)\.php$#', $fileName, $matches)) {
					require $fileName;
					PHPUnit_Framework_TestCase::main($matches[1]);
				} else {
					throw new Exception("$file plz");
				}
			}
		}
	}
}
catch(Exception $e){
	echo $e->getMessage(), PHP_EOL;
	echo $e->getFile(), ' ', $e->getLine(), PHP_EOL;
	echo $e->getTraceAsString(), PHP_EOL;
	//print_r($e->getTrace());
}

if (function_exists('xhprof_enable')) {

	$xhprof_data = xhprof_disable('/tmp');

	$XHPROF_ROOT = "/var/www/xhprof/";
	include_once $XHPROF_ROOT . "/xhprof_lib/utils/xhprof_lib.php";
	include_once $XHPROF_ROOT . "/xhprof_lib/utils/xhprof_runs.php";

	$xhprof_runs = new XHProfRuns_Default();
	$run_id = $xhprof_runs->save_run($xhprof_data, "xhprof_testing");

	echo "http://192.168.0.27/xhprof/xhprof_html/index.php?run={$run_id}&source=xhprof_testing\n";

}
