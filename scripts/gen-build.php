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
		'assets/filters/jsminifier.h',
		'mvc/model/query/parser.h',
		'mvc/model/query/scanner.h',
		'mvc/model/query/phql.h',
		'mvc/view/engine/volt/parser.h',
		'mvc/view/engine/volt/scanner.h',
		'mvc/view/engine/volt/volt.h',
		'annotations/parser.h',
		'annotations/scanner.h',
		'annotations/annot.h',
		'kernel/main.h',
		'kernel/memory.h',
		'kernel/fcall.h',
		'kernel/array.h',
		'kernel/object.h',
		'kernel/string.h',
		'kernel/filter.h',
		'kernel/file.h',
		'kernel/operators.h',
		'kernel/concat.h',
		'kernel/exception.h',
		'kernel/require.h',
		'kernel/alternative/fcall.h',
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
		'kernel/alternative/fcall.c'
	);

	private $_exclusions = array(
		'ext/annotations/base.c' => true,
		'ext/annotations/lemon.c' => true,
		'ext/annotations/lempar.c' => true,
		'ext/mvc/model/query/base.c' => true,
		'ext/mvc/model/query/lemon.c' => true,
		'ext/mvc/model/query/lempar.c' => true,
		'ext/mvc/view/engine/volt/base.c' => true,
		'ext/mvc/view/engine/volt/lemon.c' => true,
		'ext/mvc/view/engine/volt/lempar.c' => true,
	);

	public function generate($path, $destination='build/', $calculateHashKeys=false)
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
#include "ext/standard/php_math.h"
#include "ext/standard/php_array.h"
#include "ext/standard/html.h"
#include "ext/spl/spl_heap.h"

#if HAVE_BUNDLED_PCRE
#include "ext/pcre/php_pcre.h"
#endif

#include "Zend/zend_API.h"
#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"
#include "Zend/zend_execute.h"

');

		$this->_createHeader($path);

		foreach ($this->_kernelHeaders as $source) {
			$this->_appendSource($path . $source);
		}

		foreach ($this->_kernelSources as $source) {
			$this->_appendSource($path . $source);
		}

		/** C-files are scanned looking for headers */
		$this->_recursiveAction($path, array($this, '_checkHeaders'));

		/** Found headers are included at the beginning of the file */
		foreach ($this->_headers as $source => $one) {
			if (!in_array($source, $this->_kernelHeaders)) {
				$this->_appendSource($path . $source);
			}
		}

		/** Scan all c-files again and append it to phalcon.c */
		$this->_recursiveAction($path, array($this, '_appendSource'));

		$this->_appendSource($path . "phalcon.c");

		$clines = '';
		$types = array('phalcon', 'phannot', 'phvolt', 'phql');
		foreach (file($this->_destination . 'phalcon.c') as $line) {

			foreach ($types as $type) {

				if (preg_match('/^int ' . $type . '_/i', $line)) {
					$line = 'static ' . $line;
				}

				if (preg_match('/^void ' . $type . '_/i', $line)) {
					$line = 'static ' . $line;
				}

			}

			if (preg_match('/PHP_METHOD\(([a-zA-Z0-9\_]+), ([a-zA-Z0-9\_]+)\)/', $line, $matches)) {
				$line = str_replace($matches[0], 'static PHP_METHOD('.$matches[1].', '.$matches[2].')', $line);
			}

			$clines .= $line;
		}

		file_put_contents($this->_destination . 'phalcon.c', $clines);

		$hlines = '';
		foreach (file($this->_destination . 'phalcon.h') as $line) {
			if (preg_match('/PHP_METHOD\(([a-zA-Z0-9\_]+), ([a-zA-Z0-9\_]+)\)/', $line, $matches)) {
				$line = str_replace($matches[0], 'static PHP_METHOD('.$matches[1].', '.$matches[2].')', $line);
			}
			$hlines .= $line;
		}
		file_put_contents($this->_destination . 'phalcon.h', $hlines);
	}

	/**
	 * Creates the phalcon.c removing extern declaration
	 */
	private function _createHeader($path)
	{
		$fp = fopen($this->_destination . 'phalcon.h', 'w');
		//echo $path.'phalcon.h', PHP_EOL;
		foreach (file($path . 'phalcon.h') as $line) {
			if (preg_match('/^#include "(.*)"/', $line, $matches)) {
				$openComment = false;
				//echo $path.$matches[1], PHP_EOL;
				foreach (file($path . $matches[1]) as $hline) {
					$trimLine = trim($hline);
					if ($trimLine == '/*' || $trimLine == '/**') {
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
		//echo $path, PHP_EOL;
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
					if (preg_match('/phalcon_array_isset_string\(([a-zA-Z\_]+), SS\("([a-zA-Z\_\-]+)"\)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_array_isset_quick_string('.$matches[1].', SS("'.$matches[2].'"), '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					/**
					 * Pre-compute the hash key for reading elements using hashes
					 */
					if (preg_match('/phalcon_array_fetch_string\(\&([a-zA-Z\_]+), ([a-zA-Z\_]+), SL\("([a-zA-Z\_\-]+)"\), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'phalcon_array_fetch_quick_string(&'.$matches[1].', '.$matches[2].', SS("'.$matches[3].'"), '.$key.'UL, '.$matches[4].')', $line);
						fputs($fileHandler, $line);
						continue;
					}

					/**
					 * Pre-compute hash for updating elements
					 */
					if (preg_match('/phalcon_array_update_string\(\&([a-zA-Z\_]+), SL\("([a-zA-Z\_\-]+)"\), \&([a-zA-Z\_]+), (.+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_array_update_quick_string(&'.$matches[1].', SS("'.$matches[2].'"), '.$key.'UL, &'.$matches[3].', '.$matches[4].')', $line);
						fputs($fileHandler, $line);
						continue;
					}

					/**
					 * Pre-compute hash key for method checking
					 */
					if (preg_match('/phalcon_method_exists_ex\(([a-zA-Z\_]+), SS\("([a-zA-Z\_\-]+)"\) TSRMLS_CC\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_method_quick_exists_ex('.$matches[1].', SS("'.$matches[2].'"), '.$key.'UL TSRMLS_CC)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					/**
					 * Pre-compute hash key for method checking
					 */
					if (preg_match('/phalcon_function_exists_ex\(SS\("([a-zA-Z\_\-]+)"\) TSRMLS_CC\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[1]);
						$line = str_replace($matches[0], 'phalcon_function_quick_exists_ex(SS("'.$matches[1].'"), '.$key.'UL TSRMLS_CC)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					/**
					 * Pre-compute hashes for method calls
					 */
					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_1_NORETURN\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_1_NORETURN_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/phalcon_call_method_p1_noret\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_call_method_p1_noret_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_1\(([a-zA-Z\_]+), ([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_1_KEY('.$matches[1].', '.$matches[2].', "'.$matches[3].'", '.$matches[4].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/phalcon_call_method_p1\(([a-zA-Z\_]+), ([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'phalcon_call_method_p1_KEY('.$matches[1].', '.$matches[2].', "'.$matches[3].'", '.$matches[4].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_2_NORETURN\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_2_NORETURN_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$matches[4].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/phalcon_call_method_p2_noret\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_call_method_p2_noret_key('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$matches[4].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_2\(([a-zA-Z\_]+), ([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_2_KEY('.$matches[1].', '.$matches[2].', "'.$matches[3].'", '.$matches[4].', '.$matches[5].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/phalcon_call_method_p2\(([a-zA-Z\_]+), ([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'phalcon_call_method_p2_key('.$matches[1].', '.$matches[2].', "'.$matches[3].'", '.$matches[4].', '.$matches[5].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_3_NORETURN\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_3_NORETURN_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$matches[4].', '.$matches[5].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/phalcon_call_method_p3_noret\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_call_method_p3_noret_key('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$matches[4].', '.$matches[5].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_3\(([a-zA-Z\_]+), ([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_3_KEY('.$matches[1].', '.$matches[2].', "'.$matches[3].'", '.$matches[4].', '.$matches[5].', '.$matches[6].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/phalcon_call_method_p3\(([a-zA-Z\_]+), ([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'phalcon_call_method_p3_key('.$matches[1].', '.$matches[2].', "'.$matches[3].'", '.$matches[4].', '.$matches[5].', '.$matches[6].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_4_NORETURN\(([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_4_NORETURN_KEY('.$matches[1].', "'.$matches[2].'", '.$matches[3].', '.$matches[4].', '.$matches[5].', '.$matches[6].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/PHALCON_CALL_METHOD_PARAMS_4\(([a-zA-Z\_]+), ([a-zA-Z\_]+), "([a-zA-Z\_]+)", ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+), ([a-zA-Z\_]+)\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[3]);
						$line = str_replace($matches[0], 'PHALCON_CALL_METHOD_PARAMS_4_KEY('.$matches[1].', '.$matches[2].', "'.$matches[3].'", '.$matches[4].', '.$matches[5].', '.$matches[6].', '.$matches[7].', '.$key.'UL)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/phalcon_read_property_this\(&([a-zA-Z\_]+), this_ptr, SL\("([a-zA-Z\_]+)"\), PH_NOISY_CC\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'phalcon_read_property_this_quick(&'.$matches[1].', this_ptr, SL("'.$matches[2].'"), '.$key.'UL, PH_NOISY_CC)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/phalcon_update_property_this\(this_ptr, SL\("([a-zA-Z\_]+)"\), ([a-zA-Z\_]+) TSRMLS_CC\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[1]);
						$line = str_replace($matches[0], 'phalcon_update_property_this_quick(this_ptr, SL("'.$matches[1].'"), '.$matches[2].', '.$key.'UL TSRMLS_CC)', $line);
						fputs($fileHandler, $line);
						continue;
					}

					if (preg_match('/RETURN_MEMBER\(([a-zA-Z\_]+), "([a-zA-Z\_]+)"\)/', $line, $matches)) {
						$key = Phalcon\Kernel::preComputeHashKey($matches[2]);
						$line = str_replace($matches[0], 'RETURN_MEMBER_QUICK('.$matches[1].', "'.$matches[2].'", '.$key.'UL)', $line);
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
		//echo $path, PHP_EOL;
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

				if (strpos($line, 'spl_') !== false) {
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

if (stripos(php_uname(), 'x86_64')!==false) {
	echo 'Generating 64bits build... ';
	$build = new Build_Generator();
	$build->generate('ext/', 'build/64bits/', true);
	echo 'OK', PHP_EOL;
} else {
	if (preg_match('/i[0-9]{1}86/', php_uname())) {
		echo 'Generating 32bits build... ';
		$build = new Build_Generator();
		$build->generate('ext/', 'build/32bits/', true);
		echo 'OK', PHP_EOL;
	}
}

echo 'Generating safe build... ';
$build = new Build_Generator();
$build->generate('ext/', 'build/safe/', false);
echo 'OK', PHP_EOL;

