
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/file.h"


/**
 * Phalcon\Translate\Adapter\Csv
 *
 * Allows to define translation lists using CSV file
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Csv, phalcon, translate_adapter_csv, phalcon_translate_adapter_ce, phalcon_translate_adapter_csv_method_entry, 0);

	zend_declare_property_null(phalcon_translate_adapter_csv_ce, SL("_translate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_translate_adapter_csv_ce->create_object = zephir_init_properties_Phalcon_Translate_Adapter_Csv;

	zend_class_implements(phalcon_translate_adapter_csv_ce TSRMLS_CC, 1, phalcon_translate_adapterinterface_ce);
	zend_class_implements(phalcon_translate_adapter_csv_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\Csv constructor
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, *_1, *_2, *_3, *_4;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;



	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_csv_ce, this_ptr, "__construct", &_0, 426, options);
	zephir_check_call_status();
	if (!(zephir_array_isset_string(options, SS("content")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'content' is required", "phalcon/translate/adapter/csv.zep", 43);
		return;
	}
	zephir_array_fetch_string(&_1, options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 46 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, ";", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "\"", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_load", NULL, 427, _1, _2, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Load translates from file
 *
 * @param string file
 * @param int length
 * @param string delimiter
 * @param string enclosure
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, _load) {

	zend_bool _6;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *file, *length, *delimiter, *enclosure, *data = NULL, *fileHandler = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2, *_4, _5 = zval_used_for_init, *_7, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &file, &length, &delimiter, &enclosure);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "rb", 0);
	ZEPHIR_CALL_FUNCTION(&fileHandler, "fopen", NULL, 292, file, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(fileHandler) != IS_RESOURCE) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_translate_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Error opening translation file '", file, "'");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 9, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/translate/adapter/csv.zep", 64 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		ZEPHIR_CALL_FUNCTION(&data, "fgetcsv", &_3, 428, fileHandler, length, delimiter, enclosure);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(data)) {
			break;
		}
		zephir_array_fetch_long(&_4, data, 0, PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 74 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 1);
		ZEPHIR_INIT_NVAR(_1);
		zephir_substr(_1, _4, 0 , 1 , 0);
		_6 = ZEPHIR_IS_STRING_IDENTICAL(_1, "#");
		if (!(_6)) {
			_6 = !(zephir_array_isset_long(data, 1));
		}
		if (_6) {
			continue;
		}
		zephir_array_fetch_long(&_7, data, 1, PH_NOISY | PH_READONLY, "phalcon/translate/adapter/csv.zep", 78 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_long(&_8, data, 0, PH_NOISY, "phalcon/translate/adapter/csv.zep", 78 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_translate"), _8, _7 TSRMLS_CC);
	}
	zephir_fclose(fileHandler TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the translation related to the given key
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *placeholders = NULL, *translation = NULL, *_0;
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
	if (!(zephir_array_isset_fetch(&translation, _0, index, 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(translation, index);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, translation, placeholders);
	zephir_check_call_status();
	RETURN_MM();

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

static zend_object_value zephir_init_properties_Phalcon_Translate_Adapter_Csv(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_translate"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("_translate"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

