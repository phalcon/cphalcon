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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/

#include "pconfig.h"
#include "config/adapter.h"
#include "config/adapterinterface.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

/**
 * Phalcon\Config\Adapter
 *
 * Base class for Phalcon\Config adapters
 */
zend_class_entry *phalcon_config_adapter_ce;

PHP_METHOD(Phalcon_Config_Adapter, __construct);
PHP_METHOD(Phalcon_Config_Adapter, factory);
PHP_METHOD(Phalcon_Config_Adapter, setBasePath);
PHP_METHOD(Phalcon_Config_Adapter, getBasePath);
PHP_METHOD(Phalcon_Config_Adapter, load);

static const zend_function_entry phalcon_config_adapter_method_entry[] = {
	PHP_ME(Phalcon_Config_Adapter, __construct, arginfo_phalcon_config_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_Adapter, factory, arginfo_phalcon_config_adapter_factory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Config_Adapter, setBasePath, arginfo_phalcon_config_adapterinterface_setbasepath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Config_Adapter, getBasePath, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Config_Adapter, load, arginfo_phalcon_config_adapterinterface_load, ZEND_ACC_PUBLIC)

	ZEND_FENTRY(read, NULL, arginfo_phalcon_config_adapter_read, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};

/**
 * Phalcon\Config\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config, Adapter, config_adapter, phalcon_config_ce, phalcon_config_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_string(phalcon_config_adapter_ce, SL("_basePath"), "", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_null(phalcon_config_adapter_ce, SL("_instances"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_config_adapter_ce TSRMLS_CC, 1, phalcon_config_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter constructor
 *
 * @param string $filePath
 * @param string $absolutePath
 */
PHP_METHOD(Phalcon_Config_Adapter, __construct){

	zval *file_path = NULL, *absolute_path = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &file_path, &absolute_path);

	if (absolute_path == NULL) {
		absolute_path = PHALCON_GLOBAL(z_false);
	}

	if (file_path) {
		PHALCON_CALL_SELF(NULL, "read", file_path, absolute_path);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Phalcon\Config\Adapter factory
 *
 * @param string $filePath
 * @param string $absolutePath
 */
PHP_METHOD(Phalcon_Config_Adapter, factory){

	zval *file_path = NULL, *absolute_path = NULL, *instances, *instance = NULL, *class_name;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &file_path, &absolute_path);

	instances = phalcon_fetch_static_property_ce(phalcon_config_adapter_ce, SL("_instances") TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&instance, instances, file_path)) {
		PHALCON_INIT_VAR(class_name);
		phalcon_get_called_class(class_name  TSRMLS_CC);
		ce0 = phalcon_fetch_class(class_name TSRMLS_CC);

		object_init_ex(return_value, ce0);

		if (file_path) {
			if (absolute_path == NULL) {
				absolute_path = PHALCON_GLOBAL(z_false);
			}

			PHALCON_CALL_METHOD(NULL, return_value, "__construct", file_path, absolute_path);
		} else {
			PHALCON_CALL_METHOD(NULL, return_value, "__construct");
		}

		phalcon_update_static_property_array_multi_ce(phalcon_config_adapter_ce, SL("_instances"), return_value TSRMLS_CC, SL("z"), 1, file_path);
		RETURN_MM();
	}

	RETURN_CTOR(instance);
}

/**
 * Sets base path
 *
 * @param string $basePath
 * @return Phalcon\Config\Adapter
 */
PHP_METHOD(Phalcon_Config_Adapter, setBasePath){

	zval **base_path;

	phalcon_fetch_params_ex(1, 0, &base_path);

	phalcon_add_trailing_slash(base_path);
	phalcon_update_static_property_ce(phalcon_config_adapter_ce, SL("_basePath"), *base_path TSRMLS_CC);
}

/**
 * Gets base path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Config_Adapter, getBasePath){

	zval *base_path;
	
	base_path = phalcon_fetch_static_property_ce(phalcon_config_adapter_ce, SL("_basePath") TSRMLS_CC);

	RETURN_ZVAL(base_path, 1, 0);
}

/**
 * Load a configuration
 *
 * @param string $filePath
 * @param string $absolutePath
 */
PHP_METHOD(Phalcon_Config_Adapter, load){

	zval *file_path = NULL, *absolute_path = NULL, *class_name;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &file_path, &absolute_path);

	PHALCON_INIT_VAR(class_name);
	phalcon_get_called_class(class_name  TSRMLS_CC);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);

	object_init_ex(return_value, ce0);

	if (file_path) {
		if (absolute_path == NULL) {
			absolute_path = PHALCON_GLOBAL(z_false);
		}

		PHALCON_RETURN_CALL_STATICW("factory", file_path, absolute_path);
	} else {
		PHALCON_RETURN_CALL_STATICW("factory");
	}

	PHALCON_MM_RESTORE();
}
