
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Select_ResultsetData)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Helper\\Input\\Select, ResultsetData, phalcon, html_helper_input_select_resultsetdata, phalcon_html_helper_input_select_resultsetdata_method_entry, 0);

	/**
	 * @var ResultsetInterface
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("resultset"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("using"), ZEND_ACC_PROTECTED);
	phalcon_html_helper_input_select_resultsetdata_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_Input_Select_ResultsetData;

	zend_class_implements(phalcon_html_helper_input_select_resultsetdata_ce, 1, phalcon_html_helper_input_select_selectdatainterface_ce);
	return SUCCESS;
}

/**
 * @param ResultsetInterface resultset
 * @param array              using
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval using;
	zval *resultset, resultset_sub, *using_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&using);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(resultset, phalcon_mvc_model_resultsetinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(using, using_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &resultset, &using_param);
	zephir_get_arrval(&using, using_param);
	if (UNEXPECTED(zephir_fast_count_int(&using) != 2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The 'using' parameter requires exactly two values", "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 37);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("resultset"), resultset);
	zephir_update_property_zval(this_ptr, ZEND_STRL("using"), &using);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, getOptions)
{
	zval option, optionText, optionValue, options, usingZero, usingOne, _0, _1, _2, *_3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&usingZero);
	ZVAL_UNDEF(&usingOne);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("using"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&usingZero);
	zephir_array_fetch_long(&usingZero, &_0, 0, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 51);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("using"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&usingOne);
	zephir_array_fetch_long(&usingOne, &_1, 1, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 52);
	ZEPHIR_INIT_VAR(&options);
	array_init(&options);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("resultset"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 78);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
		{
			ZEPHIR_INIT_NVAR(&option);
			ZVAL_COPY(&option, _3);
			if (Z_TYPE_P(&option) == IS_OBJECT) {
				if ((zephir_method_exists_ex(&option, ZEND_STRL("readattribute")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&optionValue, &option, "readattribute", NULL, 0, &usingZero);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&optionText, &option, "readattribute", NULL, 0, &usingOne);
					zephir_check_call_status();
				} else {
					ZEPHIR_OBS_NVAR(&optionValue);
					zephir_read_property_zval(&optionValue, &option, &usingZero, PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(&optionText);
					zephir_read_property_zval(&optionText, &option, &usingOne, PH_NOISY_CC);
				}
			} else {
				if (UNEXPECTED(Z_TYPE_P(&option) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Resultset returned an invalid value", "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 68);
					return;
				}
				ZEPHIR_OBS_NVAR(&optionValue);
				zephir_array_fetch(&optionValue, &option, &usingZero, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 71);
				ZEPHIR_OBS_NVAR(&optionText);
				zephir_array_fetch(&optionText, &option, &usingOne, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 72);
			}
			zephir_array_update_zval(&options, &optionValue, &optionText, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&option, &_2, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&option) == IS_OBJECT) {
					if ((zephir_method_exists_ex(&option, ZEND_STRL("readattribute")) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(&optionValue, &option, "readattribute", NULL, 0, &usingZero);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&optionText, &option, "readattribute", NULL, 0, &usingOne);
						zephir_check_call_status();
					} else {
						ZEPHIR_OBS_NVAR(&optionValue);
						zephir_read_property_zval(&optionValue, &option, &usingZero, PH_NOISY_CC);
						ZEPHIR_OBS_NVAR(&optionText);
						zephir_read_property_zval(&optionText, &option, &usingOne, PH_NOISY_CC);
					}
				} else {
					if (UNEXPECTED(Z_TYPE_P(&option) != IS_ARRAY)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Resultset returned an invalid value", "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 68);
						return;
					}
					ZEPHIR_OBS_NVAR(&optionValue);
					zephir_array_fetch(&optionValue, &option, &usingZero, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 71);
					ZEPHIR_OBS_NVAR(&optionText);
					zephir_array_fetch(&optionText, &option, &usingOne, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 72);
				}
				zephir_array_update_zval(&options, &optionValue, &optionText, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&option);
	RETURN_CCTOR(&options);
}

zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_Select_ResultsetData(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("using"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("using"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

