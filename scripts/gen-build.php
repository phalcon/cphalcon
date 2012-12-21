<?php

/**
 * Build_Generator script
 *
 * Use this script to generate the build files in build/
 *
 * Usage: php scripts/gen-build.php
 *
 * Build scripts join the whole framework into a single file called phalcon.c
 * External symbol declarations are removed in order to produce a smaller compilation object in some old compilers
 *
 * Performs pre-calculations for hash keys on both string and long indexes
 */

class Build_Generator
{
	private $_path;

	private $_destination;

	private $_fileHandler;

	private $_headers = array();

	private $_exceptionHeaders = array();

	private $_kernelHeaders = array(
		'mvc/model/query/parser.h',
		'mvc/model/query/scanner.h',
		'mvc/model/query/phql.h',
		'mvc/view/engine/volt/parser.h',
		'mvc/view/engine/volt/scanner.h',
		'mvc/view/engine/volt/volt.h',
		'kernel/main.h',
		'kernel/memory.h',
		'kernel/fcall.h',
		'kernel/array.h',
		'kernel/object.h',
		'kernel/string.h',
		'kernel/filter.h',
		'kernel/operators.h',
		'kernel/concat.h',
		'kernel/exception.h',
		'kernel/require.h',
		'kernel/experimental/fcall.h',
	);

	private $_kernelSources = array(
		'kernel/main.c',
		'kernel/memory.c',
		'kernel/fcall.c',
		'kernel/array.c',
		'kernel/object.c',
		'kernel/string.c',
		'kernel/filter.c',
		'kernel/operators.c',
		'kernel/concat.c',
		'kernel/file.c',
		'kernel/exception.c',
		'kernel/require.c',
		'kernel/experimental/fcall.c'
	);

	private $_exclusions = array(
		'ext/mvc/model/query/base.c' => true,
		'ext/mvc/model/query/lemon.c' => true,
		'ext/mvc/model/query/lempar.c' => true,
		'ext/mvc/view/engine/volt/base.c' => true,
		'ext/mvc/view/engine/volt/lemon.c' => true,
		'ext/mvc/view/engine/volt/lempar.c' => true,
	);

	public function __construct($path, $destination='build/', $calculateHashKeys=false)
	{

		$this->_path = $path;

		$this->_destination = $destination;

		$this->_calculateHashKeys = $calculateHashKeys;

		$this->_fileHandler = fopen($destination.'phalcon.c', 'w');

		fputs($this->_fileHandler, '/**'.PHP_EOL.PHP_EOL.file_get_contents('docs/LICENSE.txt').'*/'.PHP_EOL);

		fputs($this->_fileHandler, '
#include <stdio.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "main/php_main.h"
#include "main/php_streams.h"
#include "ext/standard/php_string.h"
#include "ext/standard/php_smart_str.h"
#include "ext/pdo/php_pdo_driver.h"
#include "ext/standard/php_filestat.h"
#include "ext/standard/php_rand.h"
#include "ext/standard/php_lcg.h"

#include "Zend/zend_API.h"
#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"
#include "Zend/zend_execute.h"

');

		$this->_createHeader($path);

		foreach ($this->_kernelHeaders as $source) {
			$this->_appendSource($path.$source);
		}

		foreach ($this->_kernelSources as $source) {
			$this->_appendSource($path.$source);
		}

		/** C-files are scanned looking for headers */
		$this->_recursiveAction($path, array($this, '_checkHeaders'));

		/** Found headers are included at the beginning of the file */
		foreach ($this->_headers as $source => $one) {
			if(!in_array($source, $this->_kernelHeaders)){
				$this->_appendSource($path.$source);
			}
		}

		/** Scan all c-files again and append it to phalcon.c */
		$this->_recursiveAction($path, array($this, '_appendSource'));

		$this->_appendSource($path."phalcon.c");
	}

	/**
	 * Creates the phalcon.c removing extern declaration
	 */
	private function _createHeader($path)
	{
		$fp = fopen($this->_destination.'phalcon.h', 'w');
		foreach (file($path.'phalcon.h') as $line) {
			if (preg_match('/^#include "(.*)"/', $line, $matches)) {
				$openComment = false;
				foreach(file($path.$matches[1]) as $hline){
					$trimLine = trim($hline);
					if ($trimLine=='/*'||$trimLine=='/**') {
						$openComment = true;
					}
					if ($openComment===false) {
						$hline = preg_replace('/^extern /', '', $hline);
						fputs($fp, $hline);
					}
					if ($trimLine=='*/'||$trimLine=='**/') {
						$openComment = false;
					}
				}
				$this->_exceptionHeaders[$matches[1]] = true;
			} else {
				$line = preg_replace('/^extern /', '', $line);
				fputs($fp, $line);
			}
		}
		fclose($fp);
	}

	/**
	 * Scans recursively a directory and apply an action to each c-file found
	 */
	private function _recursiveAction($path, $handler)
	{
		$iterator = new DirectoryIterator($path);
		foreach ($iterator as $item) {
			if ($item->isDir()) {
				$fileName = $item->getFileName();
				if ($fileName != '.' && $fileName != '..') {
					$this->_recursiveAction($item->getPathname(), $handler);
				}
			} else {
				$itemPath = $item->getPathname();
				if (!preg_match('/\.c$/', $itemPath)) {
					//echo $itemPath, PHP_EOL;
					continue;
				}
				if (strpos($itemPath, '/kernel/') !== false) {
					//echo $itemPath, PHP_EOL;
					continue;
				}
				if (strpos($itemPath, '/phalcon.c') !== false) {
					//echo $itemPath, PHP_EOL;
					continue;
				}
				if (isset($this->_exclusions[$itemPath])){
					//echo $itemPath, PHP_EOL;
					continue;
				}
				call_user_func_array($handler, array($itemPath));
			}
		}
	}

	/**
	 * Appends the source to phalcon.c removing some directives, external symbol declarations and most comments
	 */
	private function _appendSource($path)
	{
		$openComment = false;
		$fileHandler = $this->_fileHandler;
		$exceptions = array('php.h', 'config.h', 'php_phalcon.h', 'phalcon.h');
		foreach (file($path) as $line) {

			$trimLine = trim($line);

			if ($trimLine == '/*' || $trimLine == '/**') {
				$openComment = true;
			}

			if ($openComment === false) {

				if (preg_match('/^#include /', $line)) {
					//echo $line, PHP_EOL;
					continue;
				}

				if (preg_match('/^#line /', $line)) {
					//echo $line, PHP_EOL;
					continue;
				}

				if (preg_match('/^PHALCON_DOC_METHOD/', $line)) {
					//echo $line, PHP_EOL;
					continue;
				}

				if (preg_match('/^extern ([A-Za-z\_]+)/', $line, $matches)) {
					if ($matches[1] == 'ZEND_API' || $matches[1] == 'PHPAPI') {
						fputs($fileHandler, $line);
					} else {
						$line = str_replace("extern ", "", $line);
						fputs($fileHandler, $line);
					}
					continue;
				}

				if ($this->_calculateHashKeys) {

					/**
					 * Pre-compute the hash key for isset using strings
					 */
					if (preg_match('/phalcon_array_isset_string\(([a-zA-Z\_]+), SS\("([a-zA-Z\_]+)"\)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_array_isset_quick_string('.$matches[1].', SS("'.$matches[2].'"), '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					/**
					 * Pre-compute the hash key for reading elements using hashes
					 */
					if (preg_match('/phalcon_array_fetch_string\(\&([a-zA-Z\_]+), ([a-zA-Z\_]+), SL\("([a-zA-Z\_]+)"\), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'phalcon_array_fetch_quick_string(&'.$matches[1].', '.$matches[2].', SS("'.$matches[3].'"), '.$key.'UL, '.$matches[4].')', $line);
						fputs($fileHandler, $line);
						continue;

					}

					/**
					 * Pre-compute hash for updating elements
					 */
					if (preg_match('/phalcon_array_update_string\(\&([a-zA-Z\_]+), SL\("([a-zA-Z\_]+)"\), \&([a-zA-Z\_]+), (.+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_array_update_quick_string(&'.$matches[1].', SS("'.$matches[2].'"), '.$key.'UL, &'.$matches[3].', '.$matches[4].')', $line);
						fputs($fileHandler, $line);
						continue;
					}

					/**
					 * Pre-compute hash for method calls
					 */
					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_1_NORETURN\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_1_NORETURN_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_2_NORETURN\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_2_NORETURN_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$matches[4].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_2\(([a-zA-Z\_]+), ([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_2_KEY('.$matches[1].', '.$matches[2].', "'.$matches[3].'", '.$matches[4].', '.$matches[5].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_3_NORETURN\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_3_NORETURN_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$matches[4].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_4_NORETURN\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_4_NORETURN_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$matches[4].', '.$matches[5].', '.$matches[6].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

				}

				fputs($fileHandler, $line);
			}

			if ($trimLine == '*/' || $trimLine == '**/') {
				$openComment = false;
			}
		}
		fputs($fileHandler, PHP_EOL.PHP_EOL);
	}

	/**
	 * Check for headers in the c-files different than kernel or zend ones
	 */
	private function _checkHeaders($path)
	{
		$exceptions = array('php.h', 'config.h', 'php_phalcon.h', 'phalcon.h');
		foreach (file($path) as $line) {
			if (preg_match('/^#include "(.+)"/', $line, $matches)) {

				if (strpos($line, 'Zend/') !== false) {
					//echo $line, PHP_EOL;
					continue;
				}

				if (strpos($line, 'kernel/') !== false) {
					//echo $line, PHP_EOL;
					continue;
				}

				if (strpos($line, 'php_') !== false) {
					//echo $line, PHP_EOL;
					continue;
				}

				if(in_array($matches[1], $exceptions)){
					//echo $line, PHP_EOL;
					continue;
				}

				if(!isset($this->_exceptionHeaders[$matches[1]])){
					if(strpos($matches[1], '/')===false){
						$headerPath = str_replace($this->_path, '', dirname($path).'/'.$matches[1]);
					} else {
						$headerPath = $matches[1];
					}
					$this->_headers[$headerPath] = true;
				}
			}
		}
	}

}

//Create the builds files based on the following directory
$build = new Build_Generator('ext/', 'build/', false);

//echo chr(97);
