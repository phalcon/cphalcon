
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Csv, phalcon, translate_adapter_csv, phalcon_translate_adapter_ce, phalcon_translate_adapter_csv_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_csv_ce, SL("_translate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_translate_adapter_csv_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);
	zend_class_implements(phalcon_translate_adapter_csv_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\Csv constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct) {

	zend_bool _14;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL;
	zval *options_param = NULL, *_0, *_1, *file = NULL, *_3, _4 = zval_used_for_init, *_6 = NULL, *_7, *_8, *data = NULL, *_9, *_10, *_12, _13 = zval_used_for_init, *_15, *_16 = NULL;
	zval *options = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_translate"), _0 TSRMLS_CC);
	if (!(zephir_array_isset_string(options, SS("content")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'content' is required", "phalcon/translate/adapter/csv.zep", 41);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 4);
	add_assoc_stringl_ex(_2, SS("delimiter"), SL(";"), 1);
	add_assoc_long_ex(_2, SS("length"), 0);
	add_assoc_stringl_ex(_2, SS("enclosure"), SL("\""), 1);
	zephir_fast_array_merge(_1, &(_2), &(options) TSRMLS_CC);
	ZEPHIR_CPY_WRT(options, _1);
	zephir_array_fetch_string(&_3, options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 51 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "rb", 0);
	ZEPHIR_CALL_FUNCTION(&file, "fopen", &_5, _3, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(file) != IS_RESOURCE) {
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, phalcon_translate_exception_ce);
		zephir_array_fetch_string(&_7, options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 54 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SVS(_8, "Error opening translation file '", _7, "'");
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, _8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6, "phalcon/translate/adapter/csv.zep", 54 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		zephir_array_fetch_string(&_7, options, SL("length"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		zephir_array_fetch_string(&_9, options, SL("delimiter"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		zephir_array_fetch_string(&_10, options, SL("enclosure"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 60 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&data, "fgetcsv", &_11, file, _7, _9, _10);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(data)) {
			break;
		}
		zephir_array_fetch_long(&_12, data, 0, PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 65 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, 1);
		ZEPHIR_INIT_NVAR(_6);
		zephir_substr(_6, _12, 0 , 1 , 0);
		_14 = ZEPHIR_IS_STRING_IDENTICAL(_6, "#");
		if (!(_14)) {
			_14 = !(zephir_array_isset_long(data, 1));
		}
		if (_14) {
			continue;
		}
		zephir_array_fetch_long(&_15, data, 1, PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 69 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_16);
		zephir_array_fetch_long(&_16, data, 0, PH_NOISY, "phalcon/translate/adapter/csv.zep", 69 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_translate"), _16, _15 TSRMLS_CC);
	}
	zephir_fclose(file TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the translation related to the given key
 *
 * @param string  index
 * @param array   placeholders
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *placeholders = NULL, *translation, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &placeholders);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(translation);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&translation, _0, index, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, translation, placeholders);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(index);

}

/**
 * Check whether is defined a translation key in the internal array
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists) {

	zval *index_param = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, index));

}

