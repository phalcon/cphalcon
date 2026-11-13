
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
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
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
	 * Unserialized result-set hydrated all rows already. unserialize() sets
	 * disableHydration to true
	 */
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_model_resultset_complex_ce, SL("disableHydration"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_model_resultset_complex_ce, SL("resultsetRowClass"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1123, columnTypes);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1124, &resultsetRowClass_zv);
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_mvc_model_resultset_complex_ce, getThis(), "__construct", &_zephir_call_cache[0], result, cache);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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

	ZEPHIR_CALL_METHOD_CACHED(&records, this_ptr, "toArray", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1125, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&cache, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1123, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&columnTypes, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1126, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&hydrateMode, &_0);
	zephir_create_array(return_value, 4, 0);
	zephir_array_update_string(return_value, SL("cache"), &cache, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("rows"), &records, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("columnTypes"), &columnTypes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("hydrateMode"), &hydrateMode, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * @phpstan-param mvc_resultset_complex_state $data
 */
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1127, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1127, &__$false);
	}
	zephir_array_fetch_string(&_0, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 112);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1128, &_0);
	zephir_array_fetch_string(&_1, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 113);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, zephir_fast_count_int(&_1));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1129, &_2);
	zephir_array_fetch_string(&_3, &data, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 114);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1125, &_3);
	zephir_array_fetch_string(&_4, &data, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 115);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1123, &_4);
	zephir_array_fetch_string(&_5, &data, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 116);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1126, &_5);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns current row in the resultset
 *
 * @phpstan-return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current)
{
	zend_class_entry *_27$$23, *_58$$48;
	zend_string *_8;
	zend_ulong _7;
	zend_bool allNull = 0, _39, _15$$13, _20$$13, _23$$20, _32$$28, _34$$28, _33$$30, _37$$11, _46$$38, _51$$38, _54$$45, _63$$53, _65$$53, _64$$55, _68$$36;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;
	zval __$true, __$false, row, hydrateMode, eager, alias, activeRow, type, column, columnValue, value, attribute, source, attributes, columnMap, rowModel, keepSnapshots, sqlAlias, modelName, lateStateBinding, _0, _1, *_4, _5, *_6, _38, _2$$6, _3$$7, _9$$12, *_10$$13, _11$$13, *_12$$13, _14$$13, *_17$$13, _18$$13, *_19$$13, _21$$13, _22$$13, _13$$14, _16$$15, _24$$22, _25$$23, _28$$23, _29$$23, _26$$24, _30$$26, _31$$26, _35$$32, _36$$32, _40$$37, *_41$$38, _42$$38, *_43$$38, _45$$38, *_48$$38, _49$$38, *_50$$38, _52$$38, _53$$38, _44$$39, _47$$40, _55$$47, _56$$48, _59$$48, _60$$48, _57$$49, _61$$51, _62$$51, _66$$57, _67$$57;
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
	ZVAL_UNDEF(&lateStateBinding);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_24$$22);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_26$$24);
	ZVAL_UNDEF(&_30$$26);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_35$$32);
	ZVAL_UNDEF(&_36$$32);
	ZVAL_UNDEF(&_40$$37);
	ZVAL_UNDEF(&_42$$38);
	ZVAL_UNDEF(&_45$$38);
	ZVAL_UNDEF(&_49$$38);
	ZVAL_UNDEF(&_52$$38);
	ZVAL_UNDEF(&_53$$38);
	ZVAL_UNDEF(&_44$$39);
	ZVAL_UNDEF(&_47$$40);
	ZVAL_UNDEF(&_55$$47);
	ZVAL_UNDEF(&_56$$48);
	ZVAL_UNDEF(&_59$$48);
	ZVAL_UNDEF(&_60$$48);
	ZVAL_UNDEF(&_57$$49);
	ZVAL_UNDEF(&_61$$51);
	ZVAL_UNDEF(&_62$$51);
	ZVAL_UNDEF(&_66$$57);
	ZVAL_UNDEF(&_67$$57);
	ZEND_TLS zephir_method_cache _zephir_call_cache[26];
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1130, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&activeRow, &_0);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1131, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&row, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1127, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1130, &row);
		RETURN_CCTOR(&row);
	}
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1130, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1130, &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_3, 1126, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&hydrateMode, &_1);
	if (ZEPHIR_IS_LONG(&hydrateMode, 0)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&hydrateMode, 1)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&hydrateMode, 2)) { goto zephir_switch_0_clause_2; }
	goto zephir_switch_0_clause_3;
	zephir_switch_0_clause_0: ;
		zephir_read_property_cached(&_2$$6, this_ptr, _zephir_prop_4, 1124, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!ZEPHIR_IS_STRING_IDENTICAL(&_2$$6, "")) {
			zephir_read_property_cached(&_3$$7, this_ptr, _zephir_prop_4, 1124, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&activeRow);
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&activeRow, &_3$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&activeRow);
			object_init_ex(&activeRow, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(&activeRow)) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &activeRow, "__construct", &_zephir_call_cache[0]);
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
	ZEPHIR_INIT_VAR(&lateStateBinding);
	ZVAL_NULL(&lateStateBinding);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_5, 1123, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_1) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_1);
		_4 = &_5;
	} else {
		_4 = &_1;
	}
	zephir_is_iterable(_4, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 351);
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
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_9$$12, "__construct", &_zephir_call_cache[1]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$12, "phalcon/Mvc/Model/Resultset/Complex.zep", 203);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 206);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&type, "object")) {
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 212);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&attributes);
				zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 213);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&columnMap);
				zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 214);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&rowModel);
				array_init(&rowModel);
				if (Z_TYPE_P(&attributes) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_11$$13);
					zephir_string_to_char_array(&_11$$13, &attributes);
					_10$$13 = &_11$$13;
				} else {
					_10$$13 = &attributes;
				}
				zephir_is_iterable(_10$$13, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 240);
				if (Z_TYPE_P(_10$$13) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$13), _12$$13)
					{
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _12$$13);
						ZEPHIR_OBS_NVAR(&columnValue);
						ZEPHIR_INIT_NVAR(&_13$$14);
						ZEPHIR_CONCAT_SVSV(&_13$$14, "_", &source, "_", &attribute);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_fetch(&columnValue, &row, &_13$$14, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 225);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$13, "rewind", &_zephir_call_cache[2]);
					zephir_check_call_status();
					_15$$13 = 1;
					while (1) {
						if (_15$$13) {
							_15$$13 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$13, "next", &_zephir_call_cache[3]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_14$$13, _10$$13, "valid", &_zephir_call_cache[4]);
						zephir_check_call_status();
						if (!zend_is_true(&_14$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&attribute, _10$$13, "current", &_zephir_call_cache[5]);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_16$$15);
							ZEPHIR_CONCAT_SVSV(&_16$$15, "_", &source, "_", &attribute);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fetch(&columnValue, &row, &_16$$15, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 225);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&attribute);
				allNull = 1;
				if (Z_TYPE_P(&rowModel) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_18$$13);
					zephir_string_to_char_array(&_18$$13, &rowModel);
					_17$$13 = &_18$$13;
				} else {
					_17$$13 = &rowModel;
				}
				zephir_is_iterable(_17$$13, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 248);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_17$$13), _19$$13)
				{
					ZEPHIR_INIT_NVAR(&columnValue);
					ZVAL_COPY(&columnValue, _19$$13);
					if (Z_TYPE_P(&columnValue) != IS_NULL) {
						allNull = 0;
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&columnValue);
				_20$$13 = allNull;
				if (_20$$13) {
					ZEPHIR_INIT_NVAR(&_22$$13);
					ZVAL_STRING(&_22$$13, "orm.resultset_empty_left_join_model");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_21$$13, phalcon_support_settings_ce, "get", &_zephir_call_cache[6], &_22$$13);
					zephir_check_call_status();
					_20$$13 = !zephir_is_true(&_21$$13);
				}
				if (_20$$13) {
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_NULL(&value);
				} else {
					if (ZEPHIR_IS_LONG(&hydrateMode, 0)) { goto zephir_switch_1_clause_0; }
					goto zephir_switch_1_clause_1;
					zephir_switch_1_clause_0: ;
						ZEPHIR_OBS_NVAR(&keepSnapshots);
						_23$$20 = zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(_23$$20)) {
							ZEPHIR_INIT_NVAR(&keepSnapshots);
							ZVAL_BOOL(&keepSnapshots, 0);
						}
						if (Z_TYPE_P(&lateStateBinding) == IS_NULL) {
							ZEPHIR_INIT_NVAR(&_24$$22);
							ZVAL_STRING(&_24$$22, "orm.late_state_binding");
							ZEPHIR_CALL_CE_STATIC_CACHED(&lateStateBinding, phalcon_support_settings_ce, "get", &_zephir_call_cache[7], &_24$$22);
							zephir_check_call_status();
						}
						if (zephir_is_true(&lateStateBinding)) {
							ZEPHIR_OBS_NVAR(&_25$$23);
							zephir_array_fetch_string(&_25$$23, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 266);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (zephir_instance_of_ev(&_25$$23, phalcon_mvc_model_ce)) {
								ZEPHIR_OBS_NVAR(&_26$$24);
								zephir_array_fetch_string(&_26$$24, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 267);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&modelName);
								zephir_get_class(&modelName, &_26$$24, 0);
							} else {
								ZEPHIR_INIT_NVAR(&modelName);
								ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
							}
							_27$$23 = zephir_fetch_class(&modelName);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_28$$23);
							zephir_array_fetch_string(&_28$$23, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 273);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZVAL_LONG(&_29$$23, dirtyState);
							ZEPHIR_CALL_CE_STATIC_CACHED(&value, _27$$23, "cloneResultMap", &_zephir_call_cache[8], &_28$$23, &rowModel, &columnMap, &_29$$23, &keepSnapshots);
							zephir_check_call_status();
						} else {
							ZEPHIR_OBS_NVAR(&_30$$26);
							zephir_array_fetch_string(&_30$$26, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 285);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZVAL_LONG(&_31$$26, dirtyState);
							ZEPHIR_CALL_CE_STATIC_CACHED(&value, phalcon_mvc_model_ce, "cloneResultMap", &_zephir_call_cache[9], &_30$$26, &rowModel, &columnMap, &_31$$26, &keepSnapshots);
							zephir_check_call_status();
						}
						goto zephir_switch_1_end;
					zephir_switch_1_clause_1: ;
						ZEPHIR_CALL_CE_STATIC_CACHED(&value, phalcon_mvc_model_ce, "cloneResultMapHydrate", &_zephir_call_cache[10], &rowModel, &columnMap, &hydrateMode);
						zephir_check_call_status();
						goto zephir_switch_1_end;
					zephir_switch_1_end: ;

				}
				ZEPHIR_OBS_NVAR(&attribute);
				zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 310);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				_32$$28 = zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_32$$28) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 316);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&value);
					_33$$30 = zephir_array_isset_fetch(&value, &row, &alias, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_33$$30;
				}
				_34$$28 = zephir_array_isset_value_string(&column, SL("balias"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_34$$28) {
					ZEPHIR_CPY_WRT(&attribute, &alias);
				} else {
					ZEPHIR_INIT_NVAR(&_35$$32);
					ZVAL_STRING(&_35$$32, "_");
					ZEPHIR_INIT_NVAR(&_36$$32);
					ZVAL_STRING(&_36$$32, "");
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_fast_str_replace(&attribute, &_35$$32, &_36$$32, &alias);
				}
			}
			ZEPHIR_OBS_NVAR(&eager);
			_37$$11 = zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_37$$11)) {
				if (ZEPHIR_IS_LONG(&hydrateMode, 1)) { goto zephir_switch_2_clause_0; }
				goto zephir_switch_2_clause_1;
				zephir_switch_2_clause_0: ;
					zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_2_end;
				zephir_switch_2_clause_1: ;
					zephir_update_property_zval_zval(&activeRow, &attribute, &value);
					goto zephir_switch_2_end;
				zephir_switch_2_end: ;

			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "rewind", &_zephir_call_cache[11]);
		zephir_check_call_status();
		_39 = 1;
		while (1) {
			if (_39) {
				_39 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "next", &_zephir_call_cache[12]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_38, _4, "valid", &_zephir_call_cache[13]);
			zephir_check_call_status();
			if (!zend_is_true(&_38)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&alias, _4, "key", &_zephir_call_cache[14]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&column, _4, "current", &_zephir_call_cache[15]);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_40$$37);
					object_init_ex(&_40$$37, phalcon_mvc_model_exceptions_corruptcolumntype_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_40$$37, "__construct", &_zephir_call_cache[16]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_40$$37, "phalcon/Mvc/Model/Resultset/Complex.zep", 203);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 206);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&type, "object")) {
					ZEPHIR_OBS_NVAR(&source);
					zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 212);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&attributes);
					zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 213);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&columnMap);
					zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 214);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&rowModel);
					array_init(&rowModel);
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_42$$38);
						zephir_string_to_char_array(&_42$$38, &attributes);
						_41$$38 = &_42$$38;
					} else {
						_41$$38 = &attributes;
					}
					zephir_is_iterable(_41$$38, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 240);
					if (Z_TYPE_P(_41$$38) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_41$$38), _43$$38)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _43$$38);
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_44$$39);
							ZEPHIR_CONCAT_SVSV(&_44$$39, "_", &source, "_", &attribute);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fetch(&columnValue, &row, &_44$$39, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 225);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _41$$38, "rewind", &_zephir_call_cache[17]);
						zephir_check_call_status();
						_46$$38 = 1;
						while (1) {
							if (_46$$38) {
								_46$$38 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _41$$38, "next", &_zephir_call_cache[18]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_45$$38, _41$$38, "valid", &_zephir_call_cache[19]);
							zephir_check_call_status();
							if (!zend_is_true(&_45$$38)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&attribute, _41$$38, "current", &_zephir_call_cache[20]);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&columnValue);
								ZEPHIR_INIT_NVAR(&_47$$40);
								ZEPHIR_CONCAT_SVSV(&_47$$40, "_", &source, "_", &attribute);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fetch(&columnValue, &row, &_47$$40, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 225);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					allNull = 1;
					if (Z_TYPE_P(&rowModel) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_49$$38);
						zephir_string_to_char_array(&_49$$38, &rowModel);
						_48$$38 = &_49$$38;
					} else {
						_48$$38 = &rowModel;
					}
					zephir_is_iterable(_48$$38, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 248);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_48$$38), _50$$38)
					{
						ZEPHIR_INIT_NVAR(&columnValue);
						ZVAL_COPY(&columnValue, _50$$38);
						if (Z_TYPE_P(&columnValue) != IS_NULL) {
							allNull = 0;
							break;
						}
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&columnValue);
					_51$$38 = allNull;
					if (_51$$38) {
						ZEPHIR_INIT_NVAR(&_53$$38);
						ZVAL_STRING(&_53$$38, "orm.resultset_empty_left_join_model");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_52$$38, phalcon_support_settings_ce, "get", &_zephir_call_cache[21], &_53$$38);
						zephir_check_call_status();
						_51$$38 = !zephir_is_true(&_52$$38);
					}
					if (_51$$38) {
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_NULL(&value);
					} else {
						if (ZEPHIR_IS_LONG(&hydrateMode, 0)) { goto zephir_switch_3_clause_0; }
						goto zephir_switch_3_clause_1;
						zephir_switch_3_clause_0: ;
							ZEPHIR_OBS_NVAR(&keepSnapshots);
							_54$$45 = zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (!(_54$$45)) {
								ZEPHIR_INIT_NVAR(&keepSnapshots);
								ZVAL_BOOL(&keepSnapshots, 0);
							}
							if (Z_TYPE_P(&lateStateBinding) == IS_NULL) {
								ZEPHIR_INIT_NVAR(&_55$$47);
								ZVAL_STRING(&_55$$47, "orm.late_state_binding");
								ZEPHIR_CALL_CE_STATIC_CACHED(&lateStateBinding, phalcon_support_settings_ce, "get", &_zephir_call_cache[22], &_55$$47);
								zephir_check_call_status();
							}
							if (zephir_is_true(&lateStateBinding)) {
								ZEPHIR_OBS_NVAR(&_56$$48);
								zephir_array_fetch_string(&_56$$48, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 266);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (zephir_instance_of_ev(&_56$$48, phalcon_mvc_model_ce)) {
									ZEPHIR_OBS_NVAR(&_57$$49);
									zephir_array_fetch_string(&_57$$49, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 267);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&modelName);
									zephir_get_class(&modelName, &_57$$49, 0);
								} else {
									ZEPHIR_INIT_NVAR(&modelName);
									ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
								}
								_58$$48 = zephir_fetch_class(&modelName);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_59$$48);
								zephir_array_fetch_string(&_59$$48, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 273);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZVAL_LONG(&_60$$48, dirtyState);
								ZEPHIR_CALL_CE_STATIC_CACHED(&value, _58$$48, "cloneResultMap", &_zephir_call_cache[23], &_59$$48, &rowModel, &columnMap, &_60$$48, &keepSnapshots);
								zephir_check_call_status();
							} else {
								ZEPHIR_OBS_NVAR(&_61$$51);
								zephir_array_fetch_string(&_61$$51, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 285);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZVAL_LONG(&_62$$51, dirtyState);
								ZEPHIR_CALL_CE_STATIC_CACHED(&value, phalcon_mvc_model_ce, "cloneResultMap", &_zephir_call_cache[24], &_61$$51, &rowModel, &columnMap, &_62$$51, &keepSnapshots);
								zephir_check_call_status();
							}
							goto zephir_switch_3_end;
						zephir_switch_3_clause_1: ;
							ZEPHIR_CALL_CE_STATIC_CACHED(&value, phalcon_mvc_model_ce, "cloneResultMapHydrate", &_zephir_call_cache[25], &rowModel, &columnMap, &hydrateMode);
							zephir_check_call_status();
							goto zephir_switch_3_end;
						zephir_switch_3_end: ;

					}
					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 310);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					_63$$53 = zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_63$$53) {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 316);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_OBS_NVAR(&value);
						_64$$55 = zephir_array_isset_fetch(&value, &row, &alias, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_64$$55;
					}
					_65$$53 = zephir_array_isset_value_string(&column, SL("balias"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_65$$53) {
						ZEPHIR_CPY_WRT(&attribute, &alias);
					} else {
						ZEPHIR_INIT_NVAR(&_66$$57);
						ZVAL_STRING(&_66$$57, "_");
						ZEPHIR_INIT_NVAR(&_67$$57);
						ZVAL_STRING(&_67$$57, "");
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_fast_str_replace(&attribute, &_66$$57, &_67$$57, &alias);
					}
				}
				ZEPHIR_OBS_NVAR(&eager);
				_68$$36 = zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_68$$36)) {
					if (ZEPHIR_IS_LONG(&hydrateMode, 1)) { goto zephir_switch_4_clause_0; }
					goto zephir_switch_4_clause_1;
					zephir_switch_4_clause_0: ;
						zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1130, &activeRow);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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

	ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Complex.zep", 367);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0);
	zephir_memory_observe(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1125, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&data, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "toArray", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1123, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&data, SL("columnTypes"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_2, 1126, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&data, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "serializer");
	ZEPHIR_CALL_METHOD_CACHED(&_2, &container, "has", &_zephir_call_cache[3], &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "serializer");
		ZEPHIR_CALL_METHOD_CACHED(&_4$$4, &container, "getShared", &_zephir_call_cache[4], &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_4$$4);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &serializer, "setData", &_zephir_call_cache[5], &data);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&serializer, "serialize", &_zephir_call_cache[6]);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 13, &data);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&records);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "rewind", &_zephir_call_cache[0]);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "valid", &_zephir_call_cache[1]);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD_CACHED(&current, this_ptr, "current", &_zephir_call_cache[2]);
		zephir_check_call_status();
		zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Complex.zep", 404);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "next", &_zephir_call_cache[3]);
		zephir_check_call_status();
	}
	RETURN_CTOR(&records);
}

/**
 * Unserializing a resultset will allow to only works on the rows present
 * in the saved state
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1127, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1127, &__$false);
	}
	ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Complex.zep", 429);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "serializer");
	ZEPHIR_CALL_METHOD_CACHED(&_1, &container, "has", &_zephir_call_cache[2], &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "serializer");
		ZEPHIR_CALL_METHOD_CACHED(&_3$$4, &container, "getShared", &_zephir_call_cache[3], &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_3$$4);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &serializer, "unserialize", &_zephir_call_cache[4], data);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&resultset, &serializer, "getData", &_zephir_call_cache[5]);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 17, data);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&resultset) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_5$$6);
		object_init_ex(&_5$$6, phalcon_mvc_model_exceptions_invalidserializationdata_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$6, "__construct", &_zephir_call_cache[6]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model/Resultset/Complex.zep", 442);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_6);
	zephir_array_fetch_string(&_6, &resultset, SL("rows"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 445);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1128, &_6);
	zephir_memory_observe(&_7);
	zephir_array_fetch_string(&_7, &resultset, SL("rows"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 446);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_UNDEF(&_8);
	ZVAL_LONG(&_8, zephir_fast_count_int(&_7));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1129, &_8);
	zephir_memory_observe(&_9);
	zephir_array_fetch_string(&_9, &resultset, SL("cache"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 447);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1125, &_9);
	zephir_memory_observe(&_10);
	zephir_array_fetch_string(&_10, &resultset, SL("columnTypes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 448);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1123, &_10);
	zephir_memory_observe(&_11);
	zephir_array_fetch_string(&_11, &resultset, SL("hydrateMode"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 449);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1126, &_11);
	ZEPHIR_MM_RESTORE();
}

