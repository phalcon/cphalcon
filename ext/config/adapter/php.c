
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
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/file.h"

/**
 * Phalcon\Config\Adapter\Php
 *
 * Reads php files and converts them to Phalcon\Config objects.
 *
 * Given the next configuration file:
 *
 *<code>
 *<?php
 *return array(
 *	'database' => array(
 *		'adapter' => 'Mysql',
 *		'host' => 'localhost',
 *		'username' => 'scott',
 *		'password' => 'cheetah',
 *		'dbname' => 'test_db'
 *	),
 *
 *	'phalcon' => array(
 *		'controllersDir' => '../app/controllers/',
 *		'modelsDir' => '../app/models/',
 *		'viewsDir' => '../app/views/'
 *));
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 *	$config = new Phalcon\Config\Adapter\Php("path/config.php");
 *	echo $config->phalcon->controllersDir;
 *	echo $config->database->username;
 *</code>
 *
 */

/**
 * Phalcon\Config\Adapter\Php phptializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Php){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Php, config_adapter_php, phalcon_config_ce, phalcon_config_adapter_php_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Php constructor
 *
 * @param string $filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Php, __construct){

	zval *file_path, *config, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &file_path);

	PHALCON_INIT_VAR(config);
	if (phalcon_require_ret(config, file_path TSRMLS_CC) == FAILURE) {			
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Configuration file ", file_path, " can't be loaded");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_config_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Calls the Phalcon\Config constructor
	 */
	phalcon_call_parent_p1_noret(this_ptr, phalcon_config_adapter_php_ce, "__construct", config);
	
	PHALCON_MM_RESTORE();
}

