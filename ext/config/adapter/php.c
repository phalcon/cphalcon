
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

#include "config/adapter/php.h"
#include "config/exception.h"
#include "pconfig.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/require.h"

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
zend_class_entry *phalcon_config_adapter_php_ce;

PHP_METHOD(Phalcon_Config_Adapter_Php, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_php___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_config_adapter_php_method_entry[] = {
	PHP_ME(Phalcon_Config_Adapter_Php, __construct, arginfo_phalcon_config_adapter_php___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

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

	zval **file_path, *config = NULL;

	phalcon_fetch_params_ex(1, 0, &file_path);
	PHALCON_ENSURE_IS_STRING(file_path);

	if (phalcon_require_ret(&config, Z_STRVAL_PP(file_path) TSRMLS_CC) == FAILURE) {
		zend_throw_exception_ex(phalcon_config_exception_ce, 0 TSRMLS_CC, "Configuration file '%s' cannot be loaded", Z_STRVAL_PP(file_path));
		return;
	}

	PHALCON_MM_GROW();
	Z_DELREF_P(config);
	PHALCON_CALL_PARENT(NULL, phalcon_config_adapter_php_ce, this_ptr, "__construct", config);
	PHALCON_MM_RESTORE();
}
