
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1124, &resultsetRowClass_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_mvc_model_resultset_complex_ce, getThis(), "__construct", &_zephir_call_cache[0], result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __serialize)
{
	zval records, columnTypes, hydrateMode, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&columnTypes);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("hydrateMode", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD_CACHED(&records, this_ptr, "toArray", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1123, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&columnTypes, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1125, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&hydrateMode, &_0);
	zephir_create_array(return_value, 3, 0);
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
	zval *data_param = NULL, __$true, __$false, _0, _1, _2, _3, _4;
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
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
		_zephir_prop_3 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("hydrateMode", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1126, &__$true);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1126, &__$false);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_array_fetch_string(&_0, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 114);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1127, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_1, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 115);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, zephir_fast_count_int(&_1));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1128, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_3, &data, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 116);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1123, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_4, &data, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 117);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1125, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns current row in the resultset
 *
 * @phpstan-return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current)
{
	zend_class_entry *_29$$23, *_60$$48;
	zend_string *_10;
	zend_ulong _9;
	zend_bool allNull = 0, _41, _17$$13, _22$$13, _25$$20, _34$$28, _36$$28, _35$$30, _39$$11, _48$$38, _53$$38, _56$$45, _65$$53, _67$$53, _66$$55, _70$$36;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;
	zval __$true, __$false, row, hydrateMode, eager, alias, activeRow, type, column, columnValue, value, attribute, source, attributes, columnMap, rowModel, keepSnapshots, sqlAlias, modelName, lateStateBinding, _0, _1, *_6, _7, *_8, _40, _2$$6, _3$$7, _4$$8, _5$$10, _11$$12, *_12$$13, _13$$13, *_14$$13, _16$$13, *_19$$13, _20$$13, *_21$$13, _23$$13, _24$$13, _15$$14, _18$$15, _26$$22, _27$$23, _30$$23, _31$$23, _28$$24, _32$$26, _33$$26, _37$$32, _38$$32, _42$$37, *_43$$38, _44$$38, *_45$$38, _47$$38, *_50$$38, _51$$38, *_52$$38, _54$$38, _55$$38, _46$$39, _49$$40, _57$$47, _58$$48, _61$$48, _62$$48, _59$$49, _63$$51, _64$$51, _68$$57, _69$$57;
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
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_28$$24);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_33$$26);
	ZVAL_UNDEF(&_37$$32);
	ZVAL_UNDEF(&_38$$32);
	ZVAL_UNDEF(&_42$$37);
	ZVAL_UNDEF(&_44$$38);
	ZVAL_UNDEF(&_47$$38);
	ZVAL_UNDEF(&_51$$38);
	ZVAL_UNDEF(&_54$$38);
	ZVAL_UNDEF(&_55$$38);
	ZVAL_UNDEF(&_46$$39);
	ZVAL_UNDEF(&_49$$40);
	ZVAL_UNDEF(&_57$$47);
	ZVAL_UNDEF(&_58$$48);
	ZVAL_UNDEF(&_61$$48);
	ZVAL_UNDEF(&_62$$48);
	ZVAL_UNDEF(&_59$$49);
	ZVAL_UNDEF(&_63$$51);
	ZVAL_UNDEF(&_64$$51);
	ZVAL_UNDEF(&_68$$57);
	ZVAL_UNDEF(&_69$$57);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1129, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&activeRow, &_0);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1130, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&row, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1126, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1129, &row);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&row);
	}
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1129, &__$true);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1129, &__$false);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_3, 1125, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_INIT_VAR(&_4$$8);
			object_init_ex(&_4$$8, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(&_4$$8)) {
				zephir_constructor_start(&_4$$8);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$8, "__construct", &_zephir_call_cache[0]);
				zephir_check_call_status();
				zephir_constructor_finish(&_4$$8);
			}

			ZEPHIR_CPY_WRT(&activeRow, &_4$$8);
			ZEPHIR_INIT_NVAR(&_4$$8);
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_INIT_NVAR(&activeRow);
		array_init(&activeRow);
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
	zephir_switch_0_clause_3: ;
		ZEPHIR_INIT_VAR(&_5$$10);
		object_init(&_5$$10);
		ZEPHIR_CPY_WRT(&activeRow, &_5$$10);
		ZEPHIR_INIT_NVAR(&_5$$10);
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
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, &_1);
		_6 = &_7;
	} else {
		_6 = &_1;
	}
	zephir_is_iterable(_6, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 352);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_6), _9, _10, _8)
		{
			ZEPHIR_INIT_NVAR(&alias);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&alias, _10);
			} else {
				ZVAL_LONG(&alias, _9);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _8);
			if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_11$$12);
				object_init_ex(&_11$$12, phalcon_mvc_model_exceptions_corruptcolumntype_ce);
				zephir_constructor_start(&_11$$12);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$12, "__construct", &_zephir_call_cache[1]);
				zephir_check_call_status();
				zephir_constructor_finish(&_11$$12);
				zephir_throw_exception_debug(&_11$$12, "phalcon/Mvc/Model/Resultset/Complex.zep", 204);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 207);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&type, "object")) {
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 213);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&attributes);
				zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 214);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&columnMap);
				zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 215);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&rowModel);
				array_init(&rowModel);
				if (Z_TYPE_P(&attributes) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_13$$13);
					zephir_string_to_char_array(&_13$$13, &attributes);
					_12$$13 = &_13$$13;
				} else {
					_12$$13 = &attributes;
				}
				zephir_is_iterable(_12$$13, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 241);
				if (Z_TYPE_P(_12$$13) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_12$$13), _14$$13)
					{
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _14$$13);
						ZEPHIR_OBS_NVAR(&columnValue);
						ZEPHIR_INIT_NVAR(&_15$$14);
						ZEPHIR_CONCAT_SVSV(&_15$$14, "_", &source, "_", &attribute);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_fetch(&columnValue, &row, &_15$$14, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 226);
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
					ZEPHIR_CALL_METHOD_CACHED(NULL, _12$$13, "rewind", &_zephir_call_cache[2]);
					zephir_check_call_status();
					_17$$13 = 1;
					while (1) {
						if (_17$$13) {
							_17$$13 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _12$$13, "next", &_zephir_call_cache[3]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_16$$13, _12$$13, "valid", &_zephir_call_cache[4]);
						zephir_check_call_status();
						if (!zend_is_true(&_16$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&attribute, _12$$13, "current", &_zephir_call_cache[5]);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_18$$15);
							ZEPHIR_CONCAT_SVSV(&_18$$15, "_", &source, "_", &attribute);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fetch(&columnValue, &row, &_18$$15, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 226);
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
				allNull = 1;
				if (Z_TYPE_P(&rowModel) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_20$$13);
					zephir_string_to_char_array(&_20$$13, &rowModel);
					_19$$13 = &_20$$13;
				} else {
					_19$$13 = &rowModel;
				}
				zephir_is_iterable(_19$$13, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 249);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_19$$13), _21$$13)
				{
					ZEPHIR_INIT_NVAR(&columnValue);
					ZVAL_COPY(&columnValue, _21$$13);
					if (Z_TYPE_P(&columnValue) != IS_NULL) {
						allNull = 0;
						break;
					}
				} ZEND_HASH_FOREACH_END();
				_22$$13 = allNull;
				if (_22$$13) {
					ZEPHIR_INIT_NVAR(&_24$$13);
					ZVAL_STRING(&_24$$13, "orm.resultset_empty_left_join_model");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_23$$13, phalcon_support_settings_ce, "get", &_zephir_call_cache[6], &_24$$13);
					zephir_check_call_status();
					_22$$13 = !zephir_is_true(&_23$$13);
				}
				if (_22$$13) {
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_NULL(&value);
				} else {
					if (ZEPHIR_IS_LONG(&hydrateMode, 0)) { goto zephir_switch_1_clause_0; }
					goto zephir_switch_1_clause_1;
					zephir_switch_1_clause_0: ;
						ZEPHIR_OBS_NVAR(&keepSnapshots);
						_25$$20 = zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (!(_25$$20)) {
							ZEPHIR_INIT_NVAR(&keepSnapshots);
							ZVAL_BOOL(&keepSnapshots, 0);
						}
						if (Z_TYPE_P(&lateStateBinding) == IS_NULL) {
							ZEPHIR_INIT_NVAR(&_26$$22);
							ZVAL_STRING(&_26$$22, "orm.late_state_binding");
							ZEPHIR_CALL_CE_STATIC_CACHED(&lateStateBinding, phalcon_support_settings_ce, "get", &_zephir_call_cache[7], &_26$$22);
							zephir_check_call_status();
						}
						if (zephir_is_true(&lateStateBinding)) {
							ZEPHIR_OBS_NVAR(&_27$$23);
							zephir_array_fetch_string(&_27$$23, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 267);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (zephir_instance_of_ev(&_27$$23, phalcon_mvc_model_ce)) {
								ZEPHIR_OBS_NVAR(&_28$$24);
								zephir_array_fetch_string(&_28$$24, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 268);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&modelName);
								zephir_get_class(&modelName, &_28$$24, 0);
							} else {
								ZEPHIR_INIT_NVAR(&modelName);
								ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
							}
							_29$$23 = zephir_fetch_class(&modelName);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_30$$23);
							zephir_array_fetch_string(&_30$$23, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 274);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZVAL_LONG(&_31$$23, dirtyState);
							ZEPHIR_CALL_CE_STATIC_THIS_CACHED(&value, _29$$23, getThis(), "cloneResultMap", &_zephir_call_cache[8], &_30$$23, &rowModel, &columnMap, &_31$$23, &keepSnapshots);
							zephir_check_call_status();
						} else {
							ZEPHIR_OBS_NVAR(&_32$$26);
							zephir_array_fetch_string(&_32$$26, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 286);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZVAL_LONG(&_33$$26, dirtyState);
							ZEPHIR_CALL_CE_STATIC_CACHED(&value, phalcon_mvc_model_ce, "cloneResultMap", &_zephir_call_cache[9], &_32$$26, &rowModel, &columnMap, &_33$$26, &keepSnapshots);
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
				zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 311);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				_34$$28 = zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_34$$28) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 317);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&value);
					_35$$30 = zephir_array_isset_fetch(&value, &row, &alias, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_36$$28 = zephir_array_isset_value_string(&column, SL("balias"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_36$$28) {
					ZEPHIR_CPY_WRT(&attribute, &alias);
				} else {
					ZEPHIR_INIT_NVAR(&_37$$32);
					ZVAL_STRING(&_37$$32, "_");
					ZEPHIR_INIT_NVAR(&_38$$32);
					ZVAL_STRING(&_38$$32, "");
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_fast_str_replace(&attribute, &_37$$32, &_38$$32, &alias);
				}
			}
			ZEPHIR_OBS_NVAR(&eager);
			_39$$11 = zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_39$$11)) {
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
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_2_end;
				zephir_switch_2_end: ;

			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _6, "rewind", &_zephir_call_cache[11]);
		zephir_check_call_status();
		_41 = 1;
		while (1) {
			if (_41) {
				_41 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _6, "next", &_zephir_call_cache[12]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_40, _6, "valid", &_zephir_call_cache[13]);
			zephir_check_call_status();
			if (!zend_is_true(&_40)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&alias, _6, "key", &_zephir_call_cache[14]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&column, _6, "current", &_zephir_call_cache[15]);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_42$$37);
					object_init_ex(&_42$$37, phalcon_mvc_model_exceptions_corruptcolumntype_ce);
					zephir_constructor_start(&_42$$37);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_42$$37, "__construct", &_zephir_call_cache[16]);
					zephir_check_call_status();
					zephir_constructor_finish(&_42$$37);
					zephir_throw_exception_debug(&_42$$37, "phalcon/Mvc/Model/Resultset/Complex.zep", 204);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 207);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&type, "object")) {
					ZEPHIR_OBS_NVAR(&source);
					zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 213);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&attributes);
					zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 214);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&columnMap);
					zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 215);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&rowModel);
					array_init(&rowModel);
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_44$$38);
						zephir_string_to_char_array(&_44$$38, &attributes);
						_43$$38 = &_44$$38;
					} else {
						_43$$38 = &attributes;
					}
					zephir_is_iterable(_43$$38, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 241);
					if (Z_TYPE_P(_43$$38) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_43$$38), _45$$38)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _45$$38);
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_46$$39);
							ZEPHIR_CONCAT_SVSV(&_46$$39, "_", &source, "_", &attribute);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fetch(&columnValue, &row, &_46$$39, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 226);
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
						ZEPHIR_CALL_METHOD_CACHED(NULL, _43$$38, "rewind", &_zephir_call_cache[17]);
						zephir_check_call_status();
						_48$$38 = 1;
						while (1) {
							if (_48$$38) {
								_48$$38 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _43$$38, "next", &_zephir_call_cache[18]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_47$$38, _43$$38, "valid", &_zephir_call_cache[19]);
							zephir_check_call_status();
							if (!zend_is_true(&_47$$38)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&attribute, _43$$38, "current", &_zephir_call_cache[20]);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&columnValue);
								ZEPHIR_INIT_NVAR(&_49$$40);
								ZEPHIR_CONCAT_SVSV(&_49$$40, "_", &source, "_", &attribute);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fetch(&columnValue, &row, &_49$$40, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 226);
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
					allNull = 1;
					if (Z_TYPE_P(&rowModel) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_51$$38);
						zephir_string_to_char_array(&_51$$38, &rowModel);
						_50$$38 = &_51$$38;
					} else {
						_50$$38 = &rowModel;
					}
					zephir_is_iterable(_50$$38, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 249);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_50$$38), _52$$38)
					{
						ZEPHIR_INIT_NVAR(&columnValue);
						ZVAL_COPY(&columnValue, _52$$38);
						if (Z_TYPE_P(&columnValue) != IS_NULL) {
							allNull = 0;
							break;
						}
					} ZEND_HASH_FOREACH_END();
					_53$$38 = allNull;
					if (_53$$38) {
						ZEPHIR_INIT_NVAR(&_55$$38);
						ZVAL_STRING(&_55$$38, "orm.resultset_empty_left_join_model");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_54$$38, phalcon_support_settings_ce, "get", &_zephir_call_cache[21], &_55$$38);
						zephir_check_call_status();
						_53$$38 = !zephir_is_true(&_54$$38);
					}
					if (_53$$38) {
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_NULL(&value);
					} else {
						if (ZEPHIR_IS_LONG(&hydrateMode, 0)) { goto zephir_switch_3_clause_0; }
						goto zephir_switch_3_clause_1;
						zephir_switch_3_clause_0: ;
							ZEPHIR_OBS_NVAR(&keepSnapshots);
							_56$$45 = zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (!(_56$$45)) {
								ZEPHIR_INIT_NVAR(&keepSnapshots);
								ZVAL_BOOL(&keepSnapshots, 0);
							}
							if (Z_TYPE_P(&lateStateBinding) == IS_NULL) {
								ZEPHIR_INIT_NVAR(&_57$$47);
								ZVAL_STRING(&_57$$47, "orm.late_state_binding");
								ZEPHIR_CALL_CE_STATIC_CACHED(&lateStateBinding, phalcon_support_settings_ce, "get", &_zephir_call_cache[22], &_57$$47);
								zephir_check_call_status();
							}
							if (zephir_is_true(&lateStateBinding)) {
								ZEPHIR_OBS_NVAR(&_58$$48);
								zephir_array_fetch_string(&_58$$48, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 267);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (zephir_instance_of_ev(&_58$$48, phalcon_mvc_model_ce)) {
									ZEPHIR_OBS_NVAR(&_59$$49);
									zephir_array_fetch_string(&_59$$49, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 268);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&modelName);
									zephir_get_class(&modelName, &_59$$49, 0);
								} else {
									ZEPHIR_INIT_NVAR(&modelName);
									ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
								}
								_60$$48 = zephir_fetch_class(&modelName);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&_61$$48);
								zephir_array_fetch_string(&_61$$48, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 274);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZVAL_LONG(&_62$$48, dirtyState);
								ZEPHIR_CALL_CE_STATIC_THIS_CACHED(&value, _60$$48, getThis(), "cloneResultMap", &_zephir_call_cache[23], &_61$$48, &rowModel, &columnMap, &_62$$48, &keepSnapshots);
								zephir_check_call_status();
							} else {
								ZEPHIR_OBS_NVAR(&_63$$51);
								zephir_array_fetch_string(&_63$$51, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 286);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZVAL_LONG(&_64$$51, dirtyState);
								ZEPHIR_CALL_CE_STATIC_CACHED(&value, phalcon_mvc_model_ce, "cloneResultMap", &_zephir_call_cache[24], &_63$$51, &rowModel, &columnMap, &_64$$51, &keepSnapshots);
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
					zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 311);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					_65$$53 = zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_65$$53) {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 317);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_OBS_NVAR(&value);
						_66$$55 = zephir_array_isset_fetch(&value, &row, &alias, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					_67$$53 = zephir_array_isset_value_string(&column, SL("balias"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_67$$53) {
						ZEPHIR_CPY_WRT(&attribute, &alias);
					} else {
						ZEPHIR_INIT_NVAR(&_68$$57);
						ZVAL_STRING(&_68$$57, "_");
						ZEPHIR_INIT_NVAR(&_69$$57);
						ZVAL_STRING(&_69$$57, "");
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_fast_str_replace(&attribute, &_68$$57, &_69$$57, &alias);
					}
				}
				ZEPHIR_OBS_NVAR(&eager);
				_70$$36 = zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_70$$36)) {
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
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						goto zephir_switch_4_end;
					zephir_switch_4_end: ;

				}
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1129, &activeRow);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("hydrateMode", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		zephir_constructor_start(&_0$$3);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_constructor_finish(&_0$$3);
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Complex.zep", 368);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 3, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "toArray", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("rows"), &_1, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_2);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1123, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&data, SL("columnTypes"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_2);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 1125, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&data, SL("hydrateMode"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "serializer");
	ZEPHIR_CALL_METHOD_CACHED(&_1, &container, "has", &_zephir_call_cache[3], &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
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
		zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Complex.zep", 408);
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
	zval *data, data_sub, __$true, __$false, resultset, container, serializer, _1, _2, _6, _7, _8, _9, _10, _0$$3, _3$$4, _4$$4, _5$$6;
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
		_zephir_prop_3 = zend_string_init("columnTypes", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("hydrateMode", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1126, &__$true);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1126, &__$false);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_CE_STATIC_CACHED(&container, phalcon_di_di_ce, "getDefault", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		zephir_constructor_start(&_0$$3);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_constructor_finish(&_0$$3);
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Complex.zep", 433);
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
		zephir_constructor_start(&_5$$6);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$6, "__construct", &_zephir_call_cache[6]);
		zephir_check_call_status();
		zephir_constructor_finish(&_5$$6);
		zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model/Resultset/Complex.zep", 446);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_6);
	zephir_array_fetch_string(&_6, &resultset, SL("rows"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 449);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1127, &_6);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_7);
	zephir_array_fetch_string(&_7, &resultset, SL("rows"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 450);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_UNDEF(&_8);
	ZVAL_LONG(&_8, zephir_fast_count_int(&_7));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1128, &_8);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_9);
	zephir_array_fetch_string(&_9, &resultset, SL("columnTypes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 451);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1123, &_9);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_10);
	zephir_array_fetch_string(&_10, &resultset, SL("hydrateMode"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 452);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1125, &_10);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

