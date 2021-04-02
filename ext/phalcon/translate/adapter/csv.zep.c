
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Translate\Adapter\Csv
 *
 * Allows to define translation lists using CSV file
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Csv, phalcon, translate_adapter_csv, phalcon_translate_adapter_abstractadapter_ce, phalcon_translate_adapter_csv_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_translate_adapter_csv_ce, SL("translate"), ZEND_ACC_PROTECTED);

	phalcon_translate_adapter_csv_ce->create_object = zephir_init_properties_Phalcon_Translate_Adapter_Csv;

	zend_class_implements(phalcon_translate_adapter_csv_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\Csv constructor
 *
 * @param array options = [
 *     'content' => '',
 *     'delimiter' => ';',
 *     'enclosure' => '"'
 * ]
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, delimiter, enclosure, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&enclosure);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &interpolator, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_csv_ce, getThis(), "__construct", &_0, 0, interpolator, &options);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_array_isset_string(&options, SL("content"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exception_ce, "Parameter 'content' is required", "phalcon/Translate/Adapter/Csv.zep", 45);
		return;
	}
	if (zephir_array_isset_string(&options, SL("delimiter"))) {
		ZEPHIR_OBS_VAR(&delimiter);
		zephir_array_fetch_string(&delimiter, &options, SL("delimiter"), PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 49);
	} else {
		ZEPHIR_INIT_NVAR(&delimiter);
		ZVAL_STRING(&delimiter, ";");
	}
	if (zephir_array_isset_string(&options, SL("enclosure"))) {
		ZEPHIR_OBS_VAR(&enclosure);
		zephir_array_fetch_string(&enclosure, &options, SL("enclosure"), PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 55);
	} else {
		ZEPHIR_INIT_NVAR(&enclosure);
		ZVAL_STRING(&enclosure, "\"");
	}
	zephir_array_fetch_string(&_1, &options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 60);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, &_1, &_2, &delimiter, &enclosure);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether is defined a translation key in the internal array
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL, _0;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
		ZVAL_EMPTY_STRING(&index);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &index));

}

/**
 * Returns the translation related to the given key
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *index_param = NULL, *placeholders_param = NULL, translation, _0;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(placeholders)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &placeholders_param);

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
		ZVAL_EMPTY_STRING(&index);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_OBS_VAR(&translation);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&translation, &_0, &index, 0))) {
		ZEPHIR_CPY_WRT(&translation, &index);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, &translation, &placeholders);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load translates from file
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, load) {

	zend_bool _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *length_param = NULL, *delimiter_param = NULL, *enclosure_param = NULL, data, fileHandler, _0, _1$$3, _3$$4, _5$$4, _6$$4, _7$$4, _9$$4, _10$$4;
	zval file, delimiter, enclosure, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&enclosure);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&fileHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(length)
		Z_PARAM_STR(delimiter)
		Z_PARAM_STR(enclosure)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &file_param, &length_param, &delimiter_param, &enclosure_param);

	zephir_get_strval(&file, file_param);
	length = zephir_get_intval(length_param);
	zephir_get_strval(&delimiter, delimiter_param);
	zephir_get_strval(&enclosure, enclosure_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rb");
	ZEPHIR_CALL_FUNCTION(&fileHandler, "fopen", NULL, 89, &file, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&fileHandler) != IS_RESOURCE)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_translate_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Error opening translation file '", &file, "'");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Translate/Adapter/Csv.zep", 97);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		ZVAL_LONG(&_3$$4, length);
		ZEPHIR_CALL_FUNCTION(&data, "fgetcsv", &_4, 0, &fileHandler, &_3$$4, &delimiter, &enclosure);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
			break;
		}
		zephir_array_fetch_long(&_5$$4, &data, 0, PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 107);
		ZVAL_LONG(&_3$$4, 0);
		ZVAL_LONG(&_6$$4, 1);
		ZEPHIR_INIT_NVAR(&_7$$4);
		zephir_substr(&_7$$4, &_5$$4, 0 , 1 , 0);
		_8$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_7$$4, "#");
		if (!(_8$$4)) {
			_8$$4 = !(zephir_array_isset_long(&data, 1));
		}
		if (_8$$4) {
			continue;
		}
		zephir_array_fetch_long(&_9$$4, &data, 1, PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 111);
		ZEPHIR_OBS_NVAR(&_10$$4);
		zephir_array_fetch_long(&_10$$4, &data, 0, PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 111);
		zephir_update_property_array(this_ptr, SL("translate"), &_10$$4, &_9$$4);
	}
	zephir_fclose(&fileHandler);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Translate_Adapter_Csv(zend_class_entry *class_type) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("translate"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

