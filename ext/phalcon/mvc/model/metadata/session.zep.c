
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\MetaData\Session
 *
 * Stores model meta-data in session. Data will erased when the session finishes.
 * Meta-data are permanent while the session is active.
 *
 * You can query the meta-data by printing $_SESSION['$PMM$']
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\Metadata\Session(
 *     [
 *        "prefix" => "my-app-id",
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Session) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Session, phalcon, mvc_model_metadata_session, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_session_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_session_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Session constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, __construct) {

	zval *options = NULL, options_sub, __$null, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefix);

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	if (zephir_array_isset_string_fetch(&prefix, options, SL("prefix"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_prefix"), &prefix);
	}

}

/**
 * Reads meta-data from $_SESSION
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _SESSION, metaData, status, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_CALL_FUNCTION(&status, "session_status", NULL, 336);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&status, 2)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "$PMM$", &_1);
	zephir_array_fetch(&_0, &_SESSION, &_2, PH_READONLY, "phalcon/mvc/model/metadata/session.zep", 64 TSRMLS_CC);
	if (zephir_array_isset_fetch(&metaData, &_0, &key, 1 TSRMLS_CC)) {
		RETURN_CTOR(&metaData);
	}
	RETURN_MM_NULL();

}

/**
 * Writes the meta-data to $_SESSION
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *key_param = NULL, *data_param = NULL, _SESSION, status, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 2, 0, &key_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	zephir_get_arrval(&data, data_param);


	ZEPHIR_CALL_FUNCTION(&status, "session_status", NULL, 336);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&status, 2)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "$PMM$", &_0);
	zephir_array_update_multi(&_SESSION, &data TSRMLS_CC, SL("zz"), 2, &_1, &key);
	ZEPHIR_MM_RESTORE();

}

