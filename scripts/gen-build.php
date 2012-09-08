<?php

/**
 * Build_Generator script
 *
 * Use this script to generate the build files in build/
 *
 * Usage: php scripts/gen-build.php
 *
 * Build scripts join the whole framework into a single file called phalcon.c
 * External symbol declarations are removed in order to produce a smaller compilation object
 */

class Build_Generator {

	private $_fileHandler;

	private $_headers = array();

	private $_kernelHeaders = array(
		'mvc/model/query/parser.h',
		'mvc/model/query/scanner.h',
		'mvc/model/query/lang.h',
		'kernel/main.h',
		'kernel/memory.h',
		'kernel/fcall.h',
		'kernel/array.h',
		'kernel/object.h',
		'kernel/operators.h',
		'kernel/concat.h',
		'kernel/exception.h',
		'kernel/require.h',
	);

	private $_kernelSources = array(
		'kernel/main.c',
		'kernel/memory.c',
		'kernel/fcall.c',
		'kernel/array.c',
		'kernel/object.c',
		'kernel/operators.c',
		'kernel/concat.c',
		'kernel/exception.c',
		'kernel/require.c',
	);

	private $_exclusions = array(
		'ext/mvc/model/query/base.c' => true,
		'ext/mvc/model/query/lemon.c' => true,
		'ext/mvc/model/query/lempar.c' => true,
	);

	public function __construct($path)
	{

		$this->_fileHandler = fopen('build/phalcon.c', 'w');

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
#include "ext/standard/php_string.h"

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
	}

	/**
	 * Creates the phalcon.c removing extern declaration
	 */
	private function _createHeader($path)
	{

		$fp = fopen('build/phalcon.h', 'w');
		foreach (file($path.'phalcon.h') as $line) {
			$line = preg_replace('/^extern /', '', $line);
			fputs($fp, $line);
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
					continue;
				}
				if (strpos($itemPath, '/kernel/') !== false) {
					continue;
				}
				if (strpos($itemPath, '/phalcon.c') !== false) {
					continue;
				}
				if (isset($this->_exclusions[$itemPath])){
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
			if($trimLine=='/*'||$trimLine=='/**'){
				$openComment = true;
			}
			if($openComment===false){
				if (preg_match('/^#include /', $line)) {
					continue;
				}
				if (preg_match('/^#line /', $line)) {
					continue;
				}
				$line = preg_replace('/^extern /', '', $line);
				fputs($fileHandler, $line);
			}
			if($trimLine=='*/'){
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
					continue;
				}
				if (strpos($line, 'kernel/') !== false) {
					continue;
				}
				if (strpos($line, 'php_') !== false) {
					continue;
				}
				if(in_array($matches[1], $exceptions)){
					continue;
				}
				if(strpos($matches[1], '/')===false){
					$headerPath = str_replace('ext/', '', dirname($path).'/'.$matches[1]);
				} else {
					$headerPath =$matches[1];
				}
				$this->_headers[$headerPath] = true;
			}
		}
	}

}

//Create the builds files based on the following directory
$build = new Build_Generator('ext/');

