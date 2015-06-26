
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
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


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
 * 'database' => array(
 *     'adapter' => 'Mysql',
 *     'host' => 'localhost',
 *     'username' => 'scott',
 *     'password' => 'cheetah',
 *     'dbname' => 'test_db'
 * ),
 *
 * phalcon' => array(
 *    'controllersDir' => '../app/controllers/',
 *    'modelsDir' => '../app/models/',
 *    'viewsDir' => '../app/views/'
 *));
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new Phalcon\Config\Adapter\Php("path/config.php");
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Php) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Php, phalcon, config_adapter_php, phalcon_config_ce, phalcon_config_adapter_php_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Php constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Php, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *filePath_param = NULL, *_1 = NULL;
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


	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1);
	if (zephir_require_zval_ret(&_1, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_php_ce, this_ptr, "__construct", &_0, 58, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

