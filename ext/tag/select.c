
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

#include "tag/select.h"
#include "tag.h"
#include "tag/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/object.h"

/**
 * Phalcon\Tag\Select
 *
 * Generates a SELECT html tag using a static array of values or a Phalcon\Mvc\Model resultset
 */
zend_class_entry *phalcon_tag_select_ce;

PHP_METHOD(Phalcon_Tag_Select, selectField);
PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset);
PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select_selectfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_tag_select_method_entry[] = {
	PHP_ME(Phalcon_Tag_Select, selectField, arginfo_phalcon_tag_select_selectfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag_Select, _optionsFromResultset, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag_Select, _optionsFromArray, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Tag\Select initializer
 */
PHALCON_INIT_CLASS(Phalcon_Tag_Select){

	PHALCON_REGISTER_CLASS(Phalcon\\Tag, Select, tag_select, phalcon_tag_select_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Generates a SELECT tag
 *
 * @param array $parameters
 * @param array $data
 */
PHP_METHOD(Phalcon_Tag_Select, selectField){

	zval *parameters, *data = NULL, *params = NULL, *id = NULL, *name, *value = NULL;
	zval *use_empty = NULL, *empty_value = NULL, *empty_text = NULL, *code;
	zval *close_option, *options = NULL, *using = NULL;
	zval *resultset_options = NULL, *array_options = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &parameters, &data);
	
	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init_size(params, 2);
		phalcon_array_append(&params, parameters, 0);
		phalcon_array_append(&params, data, 0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	if (!phalcon_array_isset_long(params, 0)) {
		PHALCON_OBS_VAR(id);
		phalcon_array_fetch_string(&id, params, SL("id"), PH_NOISY);
		phalcon_array_update_long(&params, 0, id, PH_COPY | PH_SEPARATE);
	}
	
	PHALCON_OBS_NVAR(id);
	phalcon_array_fetch_long(&id, params, 0, PH_NOISY);
	if (!phalcon_array_isset_string(params, SS("name"))) {
		phalcon_array_update_string(&params, SL("name"), id, PH_COPY | PH_SEPARATE);
	} else {
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, params, SL("name"), PH_NOISY);
		if (!zend_is_true(name)) {
			phalcon_array_update_string(&params, SL("name"), id, PH_COPY | PH_SEPARATE);
		}
	}
	
	/** 
	 * Automatically assign the id if the name is not an array
	 */
	if (!phalcon_memnstr_str(id, SL("["))) {
		if (!phalcon_array_isset_string(params, SS("id"))) {
			phalcon_array_update_string(&params, SL("id"), id, PH_COPY | PH_SEPARATE);
		}
	}
	
	if (!phalcon_array_isset_string(params, SS("value"))) {
		PHALCON_CALL_CE_STATIC(&value, phalcon_tag_ce, "getvalue", id, params);
	} else {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch_string(&value, params, SL("value"), PH_NOISY);
		phalcon_array_unset_string(&params, SS("value"), PH_SEPARATE);
	}
	
	PHALCON_INIT_VAR(use_empty);
	ZVAL_FALSE(use_empty);
	if (phalcon_array_isset_string(params, SS("useEmpty"))) {
		if (!phalcon_array_isset_string(params, SS("emptyValue"))) {
			PHALCON_INIT_VAR(empty_value);
			ZVAL_EMPTY_STRING(empty_value);
		} else {
			PHALCON_OBS_NVAR(empty_value);
			phalcon_array_fetch_string(&empty_value, params, SL("emptyValue"), PH_NOISY);
			phalcon_array_unset_string(&params, SS("emptyValue"), PH_SEPARATE);
		}
		if (!phalcon_array_isset_string(params, SS("emptyText"))) {
			PHALCON_INIT_VAR(empty_text);
			ZVAL_STRING(empty_text, "Choose...", 1);
		} else {
			PHALCON_OBS_NVAR(empty_text);
			phalcon_array_fetch_string(&empty_text, params, SL("emptyText"), PH_NOISY);
			phalcon_array_unset_string(&params, SS("emptyText"), PH_SEPARATE);
		}
	
		PHALCON_OBS_NVAR(use_empty);
		phalcon_array_fetch_string(&use_empty, params, SL("useEmpty"), PH_NOISY);
		phalcon_array_unset_string(&params, SS("useEmpty"), PH_SEPARATE);
	}
	
	if (phalcon_array_isset_string_fetch(&using, params, SS("using"))) {
		phalcon_array_unset_string(&params, SS("using"), PH_SEPARATE);
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<select", 1);
	{
		zend_class_entry *scope = EG(scope);
		EG(scope) = phalcon_tag_ce;
		phalcon_tag_render_attributes(code, params TSRMLS_CC);
		EG(scope) = scope;
	}
	
	phalcon_concat_self_str(&code, SL(">" PHP_EOL) TSRMLS_CC);
	
	PHALCON_INIT_VAR(close_option);
	ZVAL_STRING(close_option, "</option>" PHP_EOL, 1);
	if (zend_is_true(use_empty)) {
		/** 
		 * Create an empty value
		 */
		PHALCON_SCONCAT_SVSVV(code, "\t<option value=\"", empty_value, "\">", empty_text, close_option);
	}
	
	if (phalcon_array_isset_long(params, 1)) {
		PHALCON_OBS_VAR(options);
		phalcon_array_fetch_long(&options, params, 1, PH_NOISY);
	} else {
		PHALCON_CPY_WRT(options, data);
	}

	if (Z_TYPE_P(options) == IS_OBJECT) {
		/** 
		 * The options is a resultset
		 */
		if (using == NULL) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "The 'using' parameter is required");
			return;
		}

		if (Z_TYPE_P(using) != IS_ARRAY && Z_TYPE_P(using) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an Array");
			return;
		}

		/** 
		 * Create the SELECT's option from a resultset
		 */
		PHALCON_CALL_SELF(&resultset_options, "_optionsfromresultset", options, using, value, close_option);
		phalcon_concat_self(&code, resultset_options TSRMLS_CC);
	} else if (Z_TYPE_P(options) == IS_ARRAY) {
		/**
		 * Create the SELECT's option from an array
		 */
		PHALCON_CALL_SELF(&array_options, "_optionsfromarray", options, value, close_option);
		phalcon_concat_self(&code, array_options TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Invalid data provided to SELECT helper");
		return;
	}
	
	phalcon_concat_self_str(&code, SL("</select>") TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Generate the OPTION tags based on a resulset
 *
 * @param Phalcon\Mvc\Model $resultset
 * @param array $using
 * @param mixed value
 * @param string $closeOption
 */
PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset){

	zval *resultset, *using, *value, *close_option;
	zval *code, *params = NULL, *option = NULL, *using_zero = NULL, *using_one = NULL;
	zval *option_value = NULL, *option_text = NULL, *code_option = NULL;
	zval *r0 = NULL, *escaped;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &resultset, &using, &value, &close_option);
	
	PHALCON_INIT_VAR(code);
	ZVAL_EMPTY_STRING(code);
	
	PHALCON_INIT_VAR(params);
	/**/

	PHALCON_CALL_METHOD(NULL, resultset, "rewind");
	
	PHALCON_INIT_VAR(escaped);

	while (1) {
		PHALCON_CALL_METHOD(&r0, resultset, "valid");
		if (PHALCON_IS_NOT_FALSE(r0)) {
		} else {
			break;
		}
	
		/** 
		 * Get the current option
		 */
		PHALCON_CALL_METHOD(&option, resultset, "current");
		if (Z_TYPE_P(using) == IS_ARRAY) { 
	
			PHALCON_OBS_NVAR(using_zero);
			phalcon_array_fetch_long(&using_zero, using, 0, PH_NOISY);
	
			PHALCON_OBS_NVAR(using_one);
			phalcon_array_fetch_long(&using_one, using, 1, PH_NOISY);
			if (Z_TYPE_P(option) == IS_OBJECT) {
				if (phalcon_method_exists_ex(option, SS("readattribute") TSRMLS_CC) == SUCCESS) {
					/** 
					 * Read the value attribute from the model
					 */
					PHALCON_CALL_METHOD(&option_value, option, "readattribute", using_zero);
	
					/** 
					 * Read the text attribute from the model
					 */
					PHALCON_CALL_METHOD(&option_text, option, "readattribute", using_one);
				} else {
					/** 
					 * Read the variable directly from the model/object
					 */
					PHALCON_OBS_NVAR(option_value);
					phalcon_read_property_zval(&option_value, option, using_zero, PH_NOISY TSRMLS_CC);
	
					/** 
					 * Read the text directly from the model/object
					 */
					PHALCON_OBS_NVAR(option_text);
					phalcon_read_property_zval(&option_text, option, using_one, PH_NOISY TSRMLS_CC);
				}
			} else {
				if (Z_TYPE_P(option) == IS_ARRAY) { 
					/** 
					 * Read the variable directly from the model/object
					 */
					PHALCON_OBS_NVAR(option_value);
					phalcon_array_fetch(&option_value, option, using_zero, PH_NOISY);
	
					/** 
					 * Read the text directly from the model/object
					 */
					PHALCON_OBS_NVAR(option_text);
					phalcon_array_fetch(&option_text, option, using_one, PH_NOISY);
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Resultset returned an invalid value");
					return;
				}
			}
	
			/** 
			 * If the value is equal to the option's value we mark it as selected
			 */
			phalcon_htmlspecialchars(escaped, option_value, NULL, NULL TSRMLS_CC);
			if (Z_TYPE_P(value) == IS_ARRAY) { 
				if (phalcon_fast_in_array(option_value, value TSRMLS_CC)) {
					PHALCON_SCONCAT_SVSVV(code, "\t<option selected=\"selected\" value=\"", escaped, "\">", option_text, close_option);
				} else {
					PHALCON_SCONCAT_SVSVV(code, "\t<option value=\"", escaped, "\">", option_text, close_option);
				}
			} else {
				if (PHALCON_IS_EQUAL(option_value, value)) {
					PHALCON_SCONCAT_SVSVV(code, "\t<option selected=\"selected\" value=\"", escaped, "\">", option_text, close_option);
				} else {
					PHALCON_SCONCAT_SVSVV(code, "\t<option value=\"", escaped, "\">", option_text, close_option);
				}
			}
		} else {
			/** 
			 * Check if using is a closure
			 */
			if (Z_TYPE_P(using) == IS_OBJECT) {
				if (Z_TYPE_P(params) == IS_NULL) {
					PHALCON_INIT_NVAR(params);
					array_init(params);
				}
				phalcon_array_update_long(&params, 0, option, PH_COPY | PH_SEPARATE);

				PHALCON_INIT_NVAR(code_option);/**/
				PHALCON_CALL_USER_FUNC_ARRAY(code_option, using, params);
				phalcon_concat_self(&code, code_option TSRMLS_CC);
			}
		}
	
		PHALCON_CALL_METHOD(NULL, resultset, "next");
	}
	
	RETURN_CTOR(code);
}

/**
 * Generate the OPTION tags based on an array
 *
 * @param Phalcon\Mvc\ModelInterface $resultset
 * @param array $using
 * @param mixed value
 * @param string $closeOption
 */
PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray){

	zval *data, *value, *close_option, *code, *option_text = NULL;
	zval *option_value = NULL, *escaped, *array_options = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &data, &value, &close_option);
	
	PHALCON_INIT_VAR(code);
	ZVAL_EMPTY_STRING(code);
	
	phalcon_is_iterable(data, &ah0, &hp0, 0, 0);
	
	PHALCON_INIT_VAR(escaped);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(option_value, ah0, hp0);
		PHALCON_GET_HVALUE(option_text);

		if (Z_TYPE_P(option_text) == IS_ARRAY) {
			phalcon_htmlspecialchars(escaped, option_value, NULL, NULL TSRMLS_CC);

			PHALCON_CALL_SELF(&array_options, "_optionsfromarray", option_text, value, close_option);

			PHALCON_SCONCAT_SVSVS(code, "\t<optgroup label=\"", escaped, "\">" PHP_EOL, array_options, "\t</optgroup>" PHP_EOL);
		} else {
			phalcon_htmlspecialchars(escaped, option_value, NULL, NULL TSRMLS_CC);
		
			if (Z_TYPE_P(value) == IS_ARRAY) { 
				if (phalcon_fast_in_array(option_value, value TSRMLS_CC)) {
					PHALCON_SCONCAT_SVSVV(code, "\t<option selected=\"selected\" value=\"", escaped, "\">", option_text, close_option);
				} else {
					PHALCON_SCONCAT_SVSVV(code, "\t<option value=\"", escaped, "\">", option_text, close_option);
				}
			} else {
				if (PHALCON_IS_EQUAL(option_value, value)) {
					PHALCON_SCONCAT_SVSVV(code, "\t<option selected=\"selected\" value=\"", escaped, "\">", option_text, close_option);
				} else {
					PHALCON_SCONCAT_SVSVV(code, "\t<option value=\"", escaped, "\">", option_text, close_option);
				}
			}
		}
		
		zval_dtor(escaped);
		ZVAL_NULL(escaped);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(code);
}
