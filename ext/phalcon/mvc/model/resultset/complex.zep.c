
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 *
 * @template TKey of int
 * @template TValue of mixed
 *
 * @phpstan-import-type mvc_resultset_complex_state from MvcTypes
 * @phpstan-import-type mvc_resultset_object_column from MvcTypes
 * @phpstan-import-type mvc_resultset_scalar_column from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Complex, phalcon, mvc_model_resultset_complex, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_complex_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_complex_ce, SL("columnTypes"), ZEND_ACC_PROTECTED);
	/**
	 * Unserialised result-set hydrated all rows already. unserialise() sets
	 * disableHydration to true
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_resultset_complex_ce, SL("disableHydration"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_model_resultset_complex_ce, SL("resultsetRowClass"), "", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Resultset\Complex constructor
 *
 * @param array                $columnTypes
 * @param ResultInterface|null $result
 * @param mixed|null           $cache
 * @param string               $resultsetRowClass
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *resultsetRowClass = NULL;
	zval *columnTypes, columnTypes_sub, *result = NULL, result_sub, *cache = NULL, cache_sub, resultsetRowClass_zv, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnTypes_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_UNDEF(&resultsetRowClass_zv);
	ZVAL_NULL(&__$null);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("resultsetRowClass", 17, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(columnTypes)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(result, phalcon_db_resultinterface_ce)
		Z_PARAM_ZVAL_OR_NULL(cache)
		Z_PARAM_STR(resultsetRowClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	columnTypes = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		result = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cache = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}
	if (!resultsetRowClass) {
		resultsetRowClass = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&resultsetRowClass_zv);
		ZVAL_STR(&resultsetRowClass_zv, resultsetRowClass);
	} else {
		zephir_memory_observe(&resultsetRowClass_zv);
	ZVAL_STR_COPY(&resultsetRowClass_zv, resultsetRowClass);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1105, columnTypes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1106, &resultsetRowClass_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_complex_ce, getThis(), "__construct", NULL, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __serialize)
{
	zval records, cache, columnTypes, hydrateMode, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&columnTypes);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("hydrateMode", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&records, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1107, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1105, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columnTypes, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1108, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&hydrateMode, &_0);
	zephir_create_array(return_value, 4, 0);
	zephir_array_update_string(return_value, SL("cache"), &cache, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("rows"), &records, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("columnTypes"), &columnTypes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("hydrateMode"), &hydrateMode, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, __$true, __$false, _0, _1, _2, _3, _4, _5;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("disableHydration", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("rows", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("count", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("hydrateMode", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1109, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1109, &__$false);
	}
	zephir_array_fetch_string(&_0, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 116);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1110, &_0);
	zephir_array_fetch_string(&_1, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 117);
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, zephir_fast_count_int(&_1));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1111, &_2);
	zephir_array_fetch_string(&_3, &data, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 118);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1107, &_3);
	zephir_array_fetch_string(&_4, &data, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 119);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1105, &_4);
	zephir_array_fetch_string(&_5, &data, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 120);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1108, &_5);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current)
{
	zend_class_entry *_31$$22, *_60$$46;
	zend_string *_8;
	zend_ulong _7;
	zend_bool allNull = 0, _39, _16$$13, _21$$13, _46$$37, _51$$37;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_23 = NULL, *_32 = NULL, *_35 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;
	zval __$true, __$false, row, hydrateMode, eager, alias, activeRow, type, column, columnValue, value, attribute, source, attributes, columnMap, rowModel, keepSnapshots, sqlAlias, modelName, _0, _1, *_4, _5, *_6, _38, _2$$6, _3$$7, _9$$12, *_11$$13, _12$$13, *_13$$13, _15$$13, *_18$$13, _19$$13, *_20$$13, _22$$13, _24$$13, _14$$14, _17$$15, _25$$20, _26$$20, _27$$22, _29$$22, _30$$22, _28$$23, _33$$25, _34$$25, _36$$31, _37$$31, _40$$36, *_41$$37, _42$$37, *_43$$37, _45$$37, *_48$$37, _49$$37, *_50$$37, _52$$37, _53$$37, _44$$38, _47$$39, _54$$44, _55$$44, _56$$46, _58$$46, _59$$46, _57$$47, _61$$49, _62$$49, _63$$55, _64$$55;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&columnValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&rowModel);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&sqlAlias);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$22);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_34$$25);
	ZVAL_UNDEF(&_36$$31);
	ZVAL_UNDEF(&_37$$31);
	ZVAL_UNDEF(&_40$$36);
	ZVAL_UNDEF(&_42$$37);
	ZVAL_UNDEF(&_45$$37);
	ZVAL_UNDEF(&_49$$37);
	ZVAL_UNDEF(&_52$$37);
	ZVAL_UNDEF(&_53$$37);
	ZVAL_UNDEF(&_44$$38);
	ZVAL_UNDEF(&_47$$39);
	ZVAL_UNDEF(&_54$$44);
	ZVAL_UNDEF(&_55$$44);
	ZVAL_UNDEF(&_56$$46);
	ZVAL_UNDEF(&_58$$46);
	ZVAL_UNDEF(&_59$$46);
	ZVAL_UNDEF(&_57$$47);
	ZVAL_UNDEF(&_61$$49);
	ZVAL_UNDEF(&_62$$49);
	ZVAL_UNDEF(&_63$$55);
	ZVAL_UNDEF(&_64$$55);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("activeRow", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("row", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("disableHydration", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("hydrateMode", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("resultsetRowClass", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("columnTypes", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1112, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeRow, &_0);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1113, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&row, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1109, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1112, &row);
		RETURN_CCTOR(&row);
	}
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1112, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1112, &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_3, 1108, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&hydrateMode, &_1);
	if (ZEPHIR_IS_LONG(&hydrateMode, 0)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&hydrateMode, 1)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&hydrateMode, 2)) { goto zephir_switch_0_clause_2; }
	goto zephir_switch_0_clause_3;
	zephir_switch_0_clause_0: ;
		zephir_read_property_cached(&_2$$6, this_ptr, _zephir_prop_4, 1106, PH_NOISY_CC | PH_READONLY);
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_2$$6, "")) {
			zephir_read_property_cached(&_3$$7, this_ptr, _zephir_prop_4, 1106, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&activeRow);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&activeRow, &_3$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&activeRow);
			object_init_ex(&activeRow, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(&activeRow)) {
				ZEPHIR_CALL_METHOD(NULL, &activeRow, "__construct", NULL, 0);
				zephir_check_call_status();
			}

		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_INIT_NVAR(&activeRow);
		array_init(&activeRow);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
		ZEPHIR_INIT_NVAR(&activeRow);
		object_init(&activeRow);
		goto zephir_switch_0_end;
	zephir_switch_0_end: ;

	dirtyState = 0;
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_5, 1105, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_1);
		_4 = &_5;
	} else {
		_4 = &_1;
	}
	zephir_is_iterable(_4, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 342);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&alias);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&alias, _8);
			} else {
				ZVAL_LONG(&alias, _7);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _6);
			if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_9$$12);
				object_init_ex(&_9$$12, phalcon_mvc_model_exceptions_corruptcolumntype_ce);
				ZEPHIR_CALL_METHOD(NULL, &_9$$12, "__construct", &_10, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$12, "phalcon/Mvc/Model/Resultset/Complex.zep", 199);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 202);
			if (ZEPHIR_IS_STRING(&type, "object")) {
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 208);
				ZEPHIR_OBS_NVAR(&attributes);
				zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 209);
				ZEPHIR_OBS_NVAR(&columnMap);
				zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 210);
				ZEPHIR_INIT_NVAR(&rowModel);
				array_init(&rowModel);
				if (Z_TYPE_P(&attributes) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_12$$13);
					zephir_string_to_char_array(&_12$$13, &attributes);
					_11$$13 = &_12$$13;
				} else {
					_11$$13 = &attributes;
				}
				zephir_is_iterable(_11$$13, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 235);
				if (Z_TYPE_P(_11$$13) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11$$13), _13$$13)
					{
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _13$$13);
						ZEPHIR_OBS_NVAR(&columnValue);
						ZEPHIR_INIT_NVAR(&_14$$14);
						ZEPHIR_CONCAT_SVSV(&_14$$14, "_", &source, "_", &attribute);
						zephir_array_fetch(&columnValue, &row, &_14$$14, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 221);
						zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _11$$13, "rewind", NULL, 0);
					zephir_check_call_status();
					_16$$13 = 1;
					while (1) {
						if (_16$$13) {
							_16$$13 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _11$$13, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_15$$13, _11$$13, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&attribute, _11$$13, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_17$$15);
							ZEPHIR_CONCAT_SVSV(&_17$$15, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_17$$15, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 221);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_INIT_NVAR(&attribute);
				allNull = 1;
				if (Z_TYPE_P(&rowModel) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_19$$13);
					zephir_string_to_char_array(&_19$$13, &rowModel);
					_18$$13 = &_19$$13;
				} else {
					_18$$13 = &rowModel;
				}
				zephir_is_iterable(_18$$13, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 243);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_18$$13), _20$$13)
				{
					ZEPHIR_INIT_NVAR(&columnValue);
					ZVAL_COPY(&columnValue, _20$$13);
					if (Z_TYPE_P(&columnValue) != IS_NULL) {
						allNull = 0;
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&columnValue);
				_21$$13 = allNull;
				if (_21$$13) {
					ZEPHIR_INIT_NVAR(&_24$$13);
					ZVAL_STRING(&_24$$13, "orm.resultset_empty_left_join_model");
					ZEPHIR_CALL_CE_STATIC(&_22$$13, phalcon_support_settings_ce, "get", &_23, 0, &_24$$13);
					zephir_check_call_status();
					_21$$13 = !zephir_is_true(&_22$$13);
				}
				if (_21$$13) {
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_NULL(&value);
				} else {
					if (ZEPHIR_IS_LONG(&hydrateMode, 0)) { goto zephir_switch_1_clause_0; }
					goto zephir_switch_1_clause_1;
					zephir_switch_1_clause_0: ;
						ZEPHIR_OBS_NVAR(&keepSnapshots);
						if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
							ZEPHIR_INIT_NVAR(&keepSnapshots);
							ZVAL_BOOL(&keepSnapshots, 0);
						}
						ZEPHIR_INIT_NVAR(&_26$$20);
						ZVAL_STRING(&_26$$20, "orm.late_state_binding");
						ZEPHIR_CALL_CE_STATIC(&_25$$20, phalcon_support_settings_ce, "get", &_23, 0, &_26$$20);
						zephir_check_call_status();
						if (zephir_is_true(&_25$$20)) {
							ZEPHIR_OBS_NVAR(&_27$$22);
							zephir_array_fetch_string(&_27$$22, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 257);
							if (zephir_instance_of_ev(&_27$$22, phalcon_mvc_model_ce)) {
								zephir_array_fetch_string(&_28$$23, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 258);
								ZEPHIR_INIT_NVAR(&modelName);
								zephir_get_class(&modelName, &_28$$23, 0);
							} else {
								ZEPHIR_INIT_NVAR(&modelName);
								ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
							}
							zephir_array_fetch_string(&_29$$22, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 264);
							ZVAL_LONG(&_30$$22, dirtyState);
							_31$$22 = zephir_fetch_class(&modelName);
							ZEPHIR_CALL_CE_STATIC(&value, _31$$22, "cloneresultmap", NULL, 0, &_29$$22, &rowModel, &columnMap, &_30$$22, &keepSnapshots);
							zephir_check_call_status();
						} else {
							zephir_array_fetch_string(&_33$$25, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 276);
							ZVAL_LONG(&_34$$25, dirtyState);
							ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_32, 0, &_33$$25, &rowModel, &columnMap, &_34$$25, &keepSnapshots);
							zephir_check_call_status();
						}
						goto zephir_switch_1_end;
					zephir_switch_1_clause_1: ;
						ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_35, 0, &rowModel, &columnMap, &hydrateMode);
						zephir_check_call_status();
						goto zephir_switch_1_end;
					zephir_switch_1_end: ;

				}
				ZEPHIR_OBS_NVAR(&attribute);
				zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 301);
			} else {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 307);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_isset_fetch(&value, &row, &alias, 0);
				}
				if (zephir_array_isset_value_string(&column, SL("balias"))) {
					ZEPHIR_CPY_WRT(&attribute, &alias);
				} else {
					ZEPHIR_INIT_NVAR(&_36$$31);
					ZVAL_STRING(&_36$$31, "_");
					ZEPHIR_INIT_NVAR(&_37$$31);
					ZVAL_STRING(&_37$$31, "");
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_fast_str_replace(&attribute, &_36$$31, &_37$$31, &alias);
				}
			}
			if (!(zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 1))) {
				if (ZEPHIR_IS_LONG(&hydrateMode, 1)) { goto zephir_switch_2_clause_0; }
				goto zephir_switch_2_clause_1;
				zephir_switch_2_clause_0: ;
					zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
					goto zephir_switch_2_end;
				zephir_switch_2_clause_1: ;
					zephir_update_property_zval_zval(&activeRow, &attribute, &value);
					goto zephir_switch_2_end;
				zephir_switch_2_end: ;

			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_39 = 1;
		while (1) {
			if (_39) {
				_39 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_38, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_38)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, _4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&column, _4, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_40$$36);
					object_init_ex(&_40$$36, phalcon_mvc_model_exceptions_corruptcolumntype_ce);
					ZEPHIR_CALL_METHOD(NULL, &_40$$36, "__construct", &_10, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_40$$36, "phalcon/Mvc/Model/Resultset/Complex.zep", 199);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 202);
				if (ZEPHIR_IS_STRING(&type, "object")) {
					ZEPHIR_OBS_NVAR(&source);
					zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 208);
					ZEPHIR_OBS_NVAR(&attributes);
					zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 209);
					ZEPHIR_OBS_NVAR(&columnMap);
					zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 210);
					ZEPHIR_INIT_NVAR(&rowModel);
					array_init(&rowModel);
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_42$$37);
						zephir_string_to_char_array(&_42$$37, &attributes);
						_41$$37 = &_42$$37;
					} else {
						_41$$37 = &attributes;
					}
					zephir_is_iterable(_41$$37, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 235);
					if (Z_TYPE_P(_41$$37) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_41$$37), _43$$37)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _43$$37);
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_44$$38);
							ZEPHIR_CONCAT_SVSV(&_44$$38, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_44$$38, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 221);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _41$$37, "rewind", NULL, 0);
						zephir_check_call_status();
						_46$$37 = 1;
						while (1) {
							if (_46$$37) {
								_46$$37 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _41$$37, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_45$$37, _41$$37, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_45$$37)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, _41$$37, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&columnValue);
								ZEPHIR_INIT_NVAR(&_47$$39);
								ZEPHIR_CONCAT_SVSV(&_47$$39, "_", &source, "_", &attribute);
								zephir_array_fetch(&columnValue, &row, &_47$$39, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 221);
								zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					allNull = 1;
					if (Z_TYPE_P(&rowModel) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_49$$37);
						zephir_string_to_char_array(&_49$$37, &rowModel);
						_48$$37 = &_49$$37;
					} else {
						_48$$37 = &rowModel;
					}
					zephir_is_iterable(_48$$37, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 243);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_48$$37), _50$$37)
					{
						ZEPHIR_INIT_NVAR(&columnValue);
						ZVAL_COPY(&columnValue, _50$$37);
						if (Z_TYPE_P(&columnValue) != IS_NULL) {
							allNull = 0;
							break;
						}
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&columnValue);
					_51$$37 = allNull;
					if (_51$$37) {
						ZEPHIR_INIT_NVAR(&_53$$37);
						ZVAL_STRING(&_53$$37, "orm.resultset_empty_left_join_model");
						ZEPHIR_CALL_CE_STATIC(&_52$$37, phalcon_support_settings_ce, "get", &_23, 0, &_53$$37);
						zephir_check_call_status();
						_51$$37 = !zephir_is_true(&_52$$37);
					}
					if (_51$$37) {
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_NULL(&value);
					} else {
						if (ZEPHIR_IS_LONG(&hydrateMode, 0)) { goto zephir_switch_3_clause_0; }
						goto zephir_switch_3_clause_1;
						zephir_switch_3_clause_0: ;
							ZEPHIR_OBS_NVAR(&keepSnapshots);
							if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
								ZEPHIR_INIT_NVAR(&keepSnapshots);
								ZVAL_BOOL(&keepSnapshots, 0);
							}
							ZEPHIR_INIT_NVAR(&_55$$44);
							ZVAL_STRING(&_55$$44, "orm.late_state_binding");
							ZEPHIR_CALL_CE_STATIC(&_54$$44, phalcon_support_settings_ce, "get", &_23, 0, &_55$$44);
							zephir_check_call_status();
							if (zephir_is_true(&_54$$44)) {
								ZEPHIR_OBS_NVAR(&_56$$46);
								zephir_array_fetch_string(&_56$$46, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 257);
								if (zephir_instance_of_ev(&_56$$46, phalcon_mvc_model_ce)) {
									zephir_array_fetch_string(&_57$$47, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 258);
									ZEPHIR_INIT_NVAR(&modelName);
									zephir_get_class(&modelName, &_57$$47, 0);
								} else {
									ZEPHIR_INIT_NVAR(&modelName);
									ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
								}
								zephir_array_fetch_string(&_58$$46, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 264);
								ZVAL_LONG(&_59$$46, dirtyState);
								_60$$46 = zephir_fetch_class(&modelName);
								ZEPHIR_CALL_CE_STATIC(&value, _60$$46, "cloneresultmap", NULL, 0, &_58$$46, &rowModel, &columnMap, &_59$$46, &keepSnapshots);
								zephir_check_call_status();
							} else {
								zephir_array_fetch_string(&_61$$49, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 276);
								ZVAL_LONG(&_62$$49, dirtyState);
								ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_32, 0, &_61$$49, &rowModel, &columnMap, &_62$$49, &keepSnapshots);
								zephir_check_call_status();
							}
							goto zephir_switch_3_end;
						zephir_switch_3_clause_1: ;
							ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_35, 0, &rowModel, &columnMap, &hydrateMode);
							zephir_check_call_status();
							goto zephir_switch_3_end;
						zephir_switch_3_end: ;

					}
					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 301);
				} else {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 307);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_isset_fetch(&value, &row, &alias, 0);
					}
					if (zephir_array_isset_value_string(&column, SL("balias"))) {
						ZEPHIR_CPY_WRT(&attribute, &alias);
					} else {
						ZEPHIR_INIT_NVAR(&_63$$55);
						ZVAL_STRING(&_63$$55, "_");
						ZEPHIR_INIT_NVAR(&_64$$55);
						ZVAL_STRING(&_64$$55, "");
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_fast_str_replace(&attribute, &_63$$55, &_64$$55, &alias);
					}
				}
				ZEPHIR_OBS_NVAR(&eager);
				if (!(zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0))) {
					if (ZEPHIR_IS_LONG(&hydrateMode, 1)) { goto zephir_switch_4_clause_0; }
					goto zephir_switch_4_clause_1;
					zephir_switch_4_clause_0: ;
						zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
						goto zephir_switch_4_end;
					zephir_switch_4_clause_1: ;
						zephir_update_property_zval_zval(&activeRow, &attribute, &value);
						goto zephir_switch_4_end;
					zephir_switch_4_end: ;

				}
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1112, &activeRow);
	RETURN_CCTOR(&activeRow);
}

/**
 * Serializing a resultset will dump all related rows into a big array,
 * serialize it and return the resulting string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize)
{
	zval data;
	zval container, serializer, _1, _2, _3, _0$$3, _4$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&data);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("hydrateMode", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Complex.zep", 358);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0);
	zephir_memory_observe(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1107, PH_NOISY_CC);
	zephir_array_update_string(&data, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1105, PH_NOISY_CC);
	zephir_array_update_string(&data, SL("columnTypes"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_2, 1108, PH_NOISY_CC);
	zephir_array_update_string(&data, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "serializer");
	ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "serializer");
		ZEPHIR_CALL_METHOD(&_4$$4, &container, "getshared", NULL, 0, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_4$$4);
		ZEPHIR_CALL_METHOD(NULL, &serializer, "setdata", NULL, 0, &data);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&serializer, "serialize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 22, &data);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a complete resultset as an array, if the resultset has a big
 * number of rows it could consume more memory than currently it does.
 *
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray)
{
	zval records;
	zval current, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&records);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 218);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Complex.zep", 395);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_3, 0);
		zephir_check_call_status();
	}
	RETURN_CTOR(&records);
}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 *
 * @phpstan-param string $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, __$true, __$false, resultset, container, serializer, _1, _2, _6, _7, _8, _9, _10, _11, _0$$3, _3$$4, _4$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("disableHydration", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("rows", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("count", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("hydrateMode", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1109, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1109, &__$false);
	}
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Complex.zep", 419);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "serializer");
	ZEPHIR_CALL_METHOD(&_1, &container, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "serializer");
		ZEPHIR_CALL_METHOD(&_3$$4, &container, "getshared", NULL, 0, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_3$$4);
		ZEPHIR_CALL_METHOD(NULL, &serializer, "unserialize", NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&resultset, &serializer, "getdata", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 27, data);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&resultset) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_5$$6);
		object_init_ex(&_5$$6, phalcon_mvc_model_exceptions_invalidserializationdata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model/Resultset/Complex.zep", 432);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_6, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 435);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1110, &_6);
	zephir_array_fetch_string(&_7, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 436);
	ZVAL_UNDEF(&_8);
	ZVAL_LONG(&_8, zephir_fast_count_int(&_7));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1111, &_8);
	zephir_array_fetch_string(&_9, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 437);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1107, &_9);
	zephir_array_fetch_string(&_10, &resultset, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 438);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1105, &_10);
	zephir_array_fetch_string(&_11, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 439);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1108, &_11);
	ZEPHIR_MM_RESTORE();
}

