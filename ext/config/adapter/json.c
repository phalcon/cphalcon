
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

#include "config/adapter/json.h"
#include "pconfig.h"

#include "kernel/main.h"
#include "kernel/file.h"
#include "kernel/string.h"

/**
 * Phalcon\Config\Adapter\Json
 *
 * Reads JSON files and converts them to Phalcon\Config objects.
 *
 * Given the following configuration file:
 *
 *<code>
 *{"phalcon":{"baseuri":"\/phalcon\/"},"models":{"metadata":"memory"}}
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 *	$config = new Phalcon\Config\Adapter\Json("path/config.json");
 *	echo $config->phalcon->baseuri;
 *	echo $config->models->metadata;
 *</code>
 *
 */
zend_class_entry *phalcon_config_adapter_json_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_json___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

PHP_METHOD(Phalcon_Config_Adapter_Json, __construct);

static const zend_function_entry phalcon_config_adapter_json_method_entry[] = {
	PHP_ME(Phalcon_Config_Adapter_Json, __construct, arginfo_phalcon_config_adapter_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};


/**
 * Phalcon\Config\Adapter\Json initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Json){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Json, config_adapter_json, phalcon_config_ce, phalcon_config_adapter_json_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Json constructor
 *
 * @param string $filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Json, __construct){

	zval *file_path, *contents, *array;

	phalcon_fetch_params(0, 1, 0, &file_path);

	ALLOC_INIT_ZVAL(contents);
	ALLOC_INIT_ZVAL(array);
	phalcon_file_get_contents(contents, file_path TSRMLS_CC);

	if (Z_TYPE_P(contents) == IS_STRING) {
		if (FAILURE == phalcon_json_decode(array, contents, 1 TSRMLS_CC)) {
			zval_ptr_dtor(&contents);
			zval_ptr_dtor(&array);
			return;
		}
	}

	zval_ptr_dtor(&contents);

	if (Z_TYPE_P(array) != IS_ARRAY) {
		zval_dtor(array);
		array_init_size(array, 0);
	}

	phalcon_config_construct_internal(getThis(), array TSRMLS_CC);
	zval_ptr_dtor(&array);
}
