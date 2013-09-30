<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
		$options = array(
			'cgi' => PHP_BINDIR . DIRECTORY_SEPARATOR . 'php-cgi',
		);

		$directory = __DIR__ . '/../../ext/tests/';

		if (file_exists($options['cgi'])) {
			return new PHPUnit_Extensions_PhptTestSuite($directory, $options);
		}

		$facade = new File_Iterator_Facade;
		$files  = $facade->getFilesAsArray($directory, '.phpt');

		$suite = new PHPUnit_Framework_TestSuite();

		foreach ($files as $file) {
			$c = file_get_contents($file);
			if (!preg_match('/^--(?:POST(?:_RAW)?|UPLOAD|PUT|EXPECTHEADERS|(?:GZIP|DEFLATE)_POST|GET|COOKIE)--$/m', $c)) {
				$suite->addTestFile($file);
			}
		}

		return $suite;
	}
}


