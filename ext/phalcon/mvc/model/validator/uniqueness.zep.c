
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"


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
/**
 * Phalcon\Mvc\Model\Validator\Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Uniqueness as Uniqueness;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new Uniqueness(array(
 *          "field" => 'email'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Uniqueness) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Uniqueness, phalcon, mvc_model_validator_uniqueness, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_uniqueness_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_uniqueness_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Uniqueness, validate) {

	zephir_nts_static zephir_fcall_cache_entry *_20 = NULL;
	zend_class_entry *_18;
	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2, *_13;
	HashPosition _1, _12;
	int number, ZEPHIR_LAST_CALL_STATUS;
	zval *record, *field = NULL, *dependencyInjector = NULL, *metaData = NULL, *message = NULL, *bindTypes, *bindDataTypes = NULL, *columnMap = NULL, *conditions, *bindParams, *composeField = NULL, *columnField = NULL, *bindType = NULL, *primaryField = NULL, *attributeField = NULL, *params, *className, *replacePairs = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL, _7 = zval_used_for_init, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, **_14, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_19 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	if (!(zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'record' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&dependencyInjector, record, "getdi", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&metaData, dependencyInjector, "getshared", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, record);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, record);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(bindParams);
	array_init(bindParams);
	number = 0;
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "field", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/mvc/model/validator/uniqueness.zep", 123);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(composeField, _3);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(columnField);
				if (!(zephir_array_isset_fetch(&columnField, columnMap, composeField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_4);
					object_init_ex(_4, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SVS(_5, "Column '", composeField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4, "phalcon/mvc/model/validator/uniqueness.zep", 100 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(columnField, composeField);
			}
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, columnField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "Column '", columnField, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "phalcon/mvc/model/validator/uniqueness.zep", 110 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, number);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSV(_4, "[", composeField, "] = ?", &_7);
			zephir_array_append(&conditions, _4, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 116);
			ZEPHIR_CALL_METHOD(&_8, record, "readattribute", NULL, composeField);
			zephir_check_call_status();
			zephir_array_append(&bindParams, _8, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 117);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 118);
			number++;
		}
	} else {
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(columnField);
			if (!(zephir_array_isset_fetch(&columnField, columnMap, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_9);
				object_init_ex(_9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_10);
				ZEPHIR_CONCAT_SVS(_10, "Column '", field, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_6, _10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9, "phalcon/mvc/model/validator/uniqueness.zep", 130 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(columnField, field);
		}
		ZEPHIR_OBS_NVAR(bindType);
		if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, columnField, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_LNVAR(_9);
			object_init_ex(_9, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVS(_10, "Column '", columnField, "' isn't part of the table columns");
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_6, _10);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9, "phalcon/mvc/model/validator/uniqueness.zep", 140 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_SVS(_9, "[", field, "] = ?0");
		zephir_array_append(&conditions, _9, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 146);
		ZEPHIR_CALL_METHOD(&_8, record, "readattribute", NULL, field);
		zephir_check_call_status();
		zephir_array_append(&bindParams, _8, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 147);
		zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 148);
		number++;
	}
	ZEPHIR_CALL_METHOD(&_11, record, "getoperationmade", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_11, 2)) {
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, record);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		ZEPHIR_CALL_METHOD(&_8, metaData, "getprimarykeyattributes", NULL, record);
		zephir_check_call_status();
		zephir_is_iterable(_8, &_13, &_12, 0, 0, "phalcon/mvc/model/validator/uniqueness.zep", 193);
		for (
		  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _14);
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, primaryField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_LNVAR(_15);
				object_init_ex(_15, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_16);
				ZEPHIR_CONCAT_SVS(_16, "Column '", primaryField, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _15, "__construct", &_6, _16);
				zephir_check_call_status();
				zephir_throw_exception_debug(_15, "phalcon/mvc/model/validator/uniqueness.zep", 170 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, primaryField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_LNVAR(_9);
					object_init_ex(_9, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_10);
					ZEPHIR_CONCAT_SVS(_10, "Column '", primaryField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_6, _10);
					zephir_check_call_status();
					zephir_throw_exception_debug(_9, "phalcon/mvc/model/validator/uniqueness.zep", 178 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, primaryField);
			}
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, number);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSV(_4, "[", attributeField, "] <> ?", &_7);
			zephir_array_append(&conditions, _4, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 187);
			ZEPHIR_CALL_METHOD(&_17, record, "readattribute", NULL, primaryField);
			zephir_check_call_status();
			zephir_array_append(&bindParams, _17, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 188);
			zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model/validator/uniqueness.zep", 189);
			number++;
		}
	}
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	zephir_array_update_string(&params, SL("di"), &dependencyInjector, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_join_str(_0, SL(" AND "), conditions TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&params, SL("bindTypes"), &bindTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	_18 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_8, _18, "count", NULL, params);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(_8, 0)) {
		ZEPHIR_INIT_VAR(_19);
		ZVAL_STRING(_19, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _19);
		zephir_check_temp_parameter(_19);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(message);
			if (Z_TYPE_P(field) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(replacePairs);
				array_init_size(replacePairs, 2);
				ZEPHIR_INIT_NVAR(_19);
				zephir_fast_join_str(_19, SL(", "), field TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":fields"), &_19, PH_COPY | PH_SEPARATE);
				ZVAL_STRING(message, "Value of fields: :fields are already present in another record", 1);
			} else {
				ZVAL_STRING(message, "Value of field: ':field' is already present in another record", 1);
			}
		}
		ZEPHIR_CALL_FUNCTION(&_8, "strtr", &_20, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_19);
		ZVAL_STRING(_19, "Unique", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, _8, field, _19);
		zephir_check_temp_parameter(_19);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

