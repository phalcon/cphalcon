
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

#include "config/adapter/yaml.h"
#include "pconfig.h"

#include "kernel/main.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Config\Adapter\Yaml
 *
 * Reads JSON files and converts them to Phalcon\Config objects.
 *
 * Given the following configuration file:
 *
 *<code>
 *phalcon
 *  baseuri: /phalcon/
 *models:
 *  metadata: memory
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 *	$config = new Phalcon\Config\Adapter\Yaml("path/config.yaml");
 *	echo $config->phalcon->baseuri;
 *	echo $config->models->metadata;
 *</code>
 *
 */
zend_class_entry *phalcon_config_adapter_yaml_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_yaml___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

PHP_METHOD(Phalcon_Config_Adapter_Yaml, __construct);

static const zend_function_entry phalcon_config_adapter_yaml_method_entry[] = {
	PHP_ME(Phalcon_Config_Adapter_Yaml, __construct, arginfo_phalcon_config_adapter_yaml___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};


/**
 * Phalcon\Config\Adapter\Yaml initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Yaml){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Yaml, config_adapter_yaml, phalcon_config_ce, phalcon_config_adapter_yaml_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Yaml constructor
 *
 * @param string $filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Yaml, __construct){

	zval *file_path, *array = NULL;

	phalcon_fetch_params(0, 1, 0, &file_path);

	PHALCON_CALL_FUNCTIONW(&array, "yaml_parse_file", file_path);

	if (Z_TYPE_P(array) != IS_ARRAY) {
		ZVAL_NULL(array);
		zval_ptr_dtor(&array);
		return;
	}

	phalcon_config_construct_internal(getThis(), array TSRMLS_CC);
	zval_ptr_dtor(&array);
}
