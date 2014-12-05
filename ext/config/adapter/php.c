
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
#include "config/adapter.h"
#include "config/adapterinterface.h"
#include "config/exception.h"
#include "pconfig.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/concat.h"
#include "kernel/object.h"

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

PHP_METHOD(Phalcon_Config_Adapter_Php, read);

static const zend_function_entry phalcon_config_adapter_php_method_entry[] = {
	PHP_ME(Phalcon_Config_Adapter_Php, read, arginfo_phalcon_config_adapter_read, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

/**
 * Phalcon\Config\Adapter\Php phptializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Php){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Php, config_adapter_php, phalcon_config_adapter_ce, phalcon_config_adapter_php_method_entry, 0);

	zend_class_implements(phalcon_config_adapter_php_ce TSRMLS_CC, 1, phalcon_config_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Load config file
 *
 * @param string $filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Php, read){

	zval *file_path, *absolute_path = NULL, *config_dir_path, *base_path, *config = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &file_path, &absolute_path);
	PHALCON_ENSURE_IS_STRING(&file_path);

	if (absolute_path == NULL) {
		absolute_path = PHALCON_GLOBAL(z_false);
	}

	if (zend_is_true(absolute_path)) {
		PHALCON_CPY_WRT(config_dir_path, file_path);
	} else {
		base_path = phalcon_fetch_static_property_ce(phalcon_config_adapter_ce, SL("_basePath") TSRMLS_CC);

		PHALCON_INIT_VAR(config_dir_path);
		PHALCON_CONCAT_VV(config_dir_path, base_path, file_path);
	}

	PHALCON_OBS_VAR(config);
	if (phalcon_require_ret(&config, Z_STRVAL_P(config_dir_path) TSRMLS_CC) == FAILURE) {
		zend_throw_exception_ex(phalcon_config_exception_ce, 0 TSRMLS_CC, "Configuration file '%s' cannot be read", Z_STRVAL_P(config_dir_path));
		PHALCON_MM_RESTORE();
		return;
	}

	if (Z_TYPE_P(config) == IS_ARRAY) {
		phalcon_config_construct_internal(getThis(), config TSRMLS_CC);
	}

	RETURN_THIS();
}
