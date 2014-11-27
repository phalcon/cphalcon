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

/**
 * Phalcon\Config\Adapter
 *
 * Base class for Phalcon\Config adapters
 */
zend_class_entry *phalcon_config_adapter_ce;

PHP_METHOD(Phalcon_Config_Adapter, __construct);
PHP_METHOD(Phalcon_Config_Adapter, setBasePath);
PHP_METHOD(Phalcon_Config_Adapter, getBasePath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_INFO(0, absolutePath)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_config_adapter_method_entry[] = {
	PHP_ME(Phalcon_Config_Adapter, __construct, arginfo_phalcon_config_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_Adapter, setBasePath, arginfo_phalcon_config_adapterinterface_setbasepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config_Adapter, getBasePath, NULL, ZEND_ACC_PUBLIC)

	ZEND_FENTRY(load, NULL, arginfo_phalcon_config_adapter_load, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};

/**
 * Phalcon\Config\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config, Adapter, config_adapter, phalcon_config_ce, phalcon_config_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_string(phalcon_config_adapter_ce, SL("_basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

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
		PHALCON_CALL_SELF(NULL, "load", file_path, absolute_path);
	}

	PHALCON_MM_RESTORE();
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
	phalcon_update_property_this(this_ptr, SL("_basePath"), *base_path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Gets base path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Config_Adapter, getBasePath){

	RETURN_MEMBER(this_ptr, "_basePath");
}
