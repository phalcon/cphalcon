
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Json, phalcon, config_adapter_json, phalcon_config_ce, phalcon_config_adapter_json_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Json constructor
 *
 * @param string filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Json, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *filePath_param = NULL, *_1, *_2;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		filePath = filePath_param;
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_file_get_contents(_2, filePath TSRMLS_CC);
	zephir_json_decode(_1, &(_1), _2, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_json_ce, this_ptr, "__construct", &_0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

