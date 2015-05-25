
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


/**
 * Phalcon\Config\Adapter\Json
 *
 * Reads JSON files and converts them to Phalcon\Config objects.
 *
 * Given the following configuration file:
 *
 *<code>
 * {"phalcon":{"baseuri":"\/phalcon\/"},"models":{"metadata":"memory"}}
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new Phalcon\Config\Adapter\Json("path/config.json");
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Json, phalcon, config_adapter_json, phalcon_config_ce, phalcon_config_adapter_json_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Json constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Json, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *filePath_param = NULL, *_1, *_2;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_file_get_contents(_2, filePath TSRMLS_CC);
	zephir_json_decode(_1, &(_1), _2, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_json_ce, this_ptr, "__construct", &_0, 58, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

