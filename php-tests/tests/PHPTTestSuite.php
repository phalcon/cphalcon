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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

class PHPTTestSuite extends PHPUnit_Framework_TestCase
{
	public static function suite()
	{
		if (empty($_ENV)) {
			if (isset($_SERVER['PATH'])) {
				$_ENV['PATH'] = $_SERVER['PATH'];
			}
			else {
				$_ENV['PATH'] = getenv('PATH');
			}
		}

		$directory = __DIR__ . '/../../ext/tests/';

		$facade = new File_Iterator_Facade;
		$files  = $facade->getFilesAsArray($directory, '.phpt');

		$suite = new PHPUnit_Framework_TestSuite();

		foreach ($files as $file) {
			$c = file_get_contents($file);
			if (!preg_match('/^--(?:PUT|(?:GZIP|DEFLATE)_POST|CGI)--$/m', $c)) {
				$suite->addTestFile($file);
			}
		}

		return $suite;
	}
}
