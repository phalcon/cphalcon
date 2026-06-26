
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_CloneResultMap)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Hydration, CloneResultMap, phalcon, mvc_model_hydration_cloneresultmap, phalcon_mvc_model_hydration_cloneresultmap_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_Hydration_CloneResultMap, cloneResultMap)
{
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_17 = NULL, *_29 = NULL, *_31 = NULL;
	zend_bool keepSnapshots, callSetters = 0, _40, _6$$5, _26$$5, _8$$9, _11$$13, _23$$21, _36$$36, _41$$40, _59$$40, _43$$44, _46$$48, _56$$56, _67$$71;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data, localMethods;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, metaData, reverseMap, notNullAttributes, setter, _0, _1, _2, *_3, _39, _7$$9, _9$$10, _10$$10, _12$$16, _14$$16, _15$$17, _16$$17, _18$$18, _19$$18, _20$$19, _21$$19, _22$$21, _24$$22, _25$$22, _27$$25, _28$$26, _30$$30, _32$$29, _33$$29, _34$$33, _35$$36, _37$$37, _38$$37, _42$$44, _44$$45, _45$$45, _47$$51, _48$$51, _49$$52, _50$$52, _51$$53, _52$$53, _53$$54, _54$$54, _55$$56, _57$$57, _58$$57, _60$$60, _61$$61, _62$$65, _63$$64, _64$$64, _65$$68, _66$$71, _68$$72, _69$$72, _70$$75, _71$$76;

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&castValue);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&reverseMap);
	ZVAL_UNDEF(&notNullAttributes);
	ZVAL_UNDEF(&setter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_24$$22);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_30$$30);
	ZVAL_UNDEF(&_32$$29);
	ZVAL_UNDEF(&_33$$29);
	ZVAL_UNDEF(&_34$$33);
	ZVAL_UNDEF(&_35$$36);
	ZVAL_UNDEF(&_37$$37);
	ZVAL_UNDEF(&_38$$37);
	ZVAL_UNDEF(&_42$$44);
	ZVAL_UNDEF(&_44$$45);
	ZVAL_UNDEF(&_45$$45);
	ZVAL_UNDEF(&_47$$51);
	ZVAL_UNDEF(&_48$$51);
	ZVAL_UNDEF(&_49$$52);
	ZVAL_UNDEF(&_50$$52);
	ZVAL_UNDEF(&_51$$53);
	ZVAL_UNDEF(&_52$$53);
	ZVAL_UNDEF(&_53$$54);
	ZVAL_UNDEF(&_54$$54);
	ZVAL_UNDEF(&_55$$56);
	ZVAL_UNDEF(&_57$$57);
	ZVAL_UNDEF(&_58$$57);
	ZVAL_UNDEF(&_60$$60);
	ZVAL_UNDEF(&_61$$61);
	ZVAL_UNDEF(&_62$$65);
	ZVAL_UNDEF(&_63$$64);
	ZVAL_UNDEF(&_64$$64);
	ZVAL_UNDEF(&_65$$68);
	ZVAL_UNDEF(&_66$$71);
	ZVAL_UNDEF(&_68$$72);
	ZVAL_UNDEF(&_69$$72);
	ZVAL_UNDEF(&_70$$75);
	ZVAL_UNDEF(&_71$$76);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&localMethods);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_ZVAL(base)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(dirtyState)
		Z_PARAM_BOOL_OR_NULL(keepSnapshots, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 2, &base, &data_param, &columnMap, &dirtyState_param, &keepSnapshots_param);
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base) == FAILURE) {
		RETURN_MM();
	}
	if (zephir_instance_of_ev(&instance, phalcon_mvc_model_ce)) {
		ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&notNullAttributes, &metaData, "getnotnullattributes", NULL, 0, &instance);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&metaData);
		ZVAL_NULL(&metaData);
		ZEPHIR_INIT_NVAR(&notNullAttributes);
		array_init(&notNullAttributes);
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "orm.call_setters_on_hydration");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_support_settings_ce, "get", NULL, 0, &_2);
	zephir_check_call_status();
	callSetters = zephir_get_boolval(&_1);
	ZEPHIR_INIT_VAR(&localMethods);
	zephir_create_array(&localMethods, 10, 0);
	add_assoc_long_ex(&localMethods, SL("setConnectionService"), 1);
	add_assoc_long_ex(&localMethods, SL("setDirtyState"), 1);
	add_assoc_long_ex(&localMethods, SL("setEventsManager"), 1);
	add_assoc_long_ex(&localMethods, SL("setReadConnectionService"), 1);
	add_assoc_long_ex(&localMethods, SL("setOldSnapshotData"), 1);
	add_assoc_long_ex(&localMethods, SL("setSchema"), 1);
	add_assoc_long_ex(&localMethods, SL("setSnapshotData"), 1);
	add_assoc_long_ex(&localMethods, SL("setSource"), 1);
	add_assoc_long_ex(&localMethods, SL("setTransaction"), 1);
	add_assoc_long_ex(&localMethods, SL("setWriteConnectionService"), 1);
	zephir_is_iterable(&data, 1, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 218);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			_6$$5 = Z_TYPE_P(&value) == IS_NULL;
			if (_6$$5) {
				_6$$5 = zephir_fast_in_array(&key, &notNullAttributes);
			}
			if (_6$$5) {
				continue;
			}
			if (Z_TYPE_P(columnMap) != IS_ARRAY) {
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_7$$9);
					zephir_camelize(&_7$$9, &key, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_7$$9);
					_8$$9 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_8$$9) {
						_8$$9 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_8$$9) {

						/* try_start_1: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_1);

						try_end_1:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_9$$10);
							ZVAL_OBJ(&_9$$10, EG(exception));
							Z_ADDREF_P(&_9$$10);
							ZEPHIR_INIT_NVAR(&_10$$10);
							if (zephir_is_instance_of(&_9$$10, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_10$$10, &_9$$10);
								zephir_update_property_zval_zval(&instance, &key, &value);
							}
						}
						continue;
					}
				}
				zephir_update_property_zval_zval(&instance, &key, &value);
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
				_11$$13 = Z_TYPE_P(columnMap) == IS_ARRAY;
				if (_11$$13) {
					_11$$13 = !(ZEPHIR_IS_EMPTY(columnMap));
				}
				if (_11$$13) {
					if (Z_TYPE_P(&metaData) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&attribute);
					if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
						ZEPHIR_INIT_NVAR(&_14$$16);
						ZVAL_STRING(&_14$$16, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_12$$16, phalcon_support_settings_ce, "get", &_13, 0, &_14$$16);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_12$$16))) {
							ZEPHIR_INIT_NVAR(&_15$$17);
							object_init_ex(&_15$$17, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_16$$17);
							zephir_get_class(&_16$$17, base, 0);
							ZEPHIR_CALL_METHOD(NULL, &_15$$17, "__construct", &_17, 0, &key, &_16$$17);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_15$$17, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 101);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_19$$18);
					ZVAL_STRING(&_19$$18, "orm.ignore_unknown_columns");
					ZEPHIR_CALL_CE_STATIC(&_18$$18, phalcon_support_settings_ce, "get", &_13, 0, &_19$$18);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_18$$18))) {
						ZEPHIR_INIT_NVAR(&_20$$19);
						object_init_ex(&_20$$19, phalcon_mvc_model_exceptions_columnnotinmap_ce);
						ZEPHIR_INIT_NVAR(&_21$$19);
						zephir_get_class(&_21$$19, base, 0);
						ZEPHIR_CALL_METHOD(NULL, &_20$$19, "__construct", &_17, 0, &key, &_21$$19);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$19, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 108);
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			if (Z_TYPE_P(&attribute) != IS_ARRAY) {
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_22$$21);
					zephir_camelize(&_22$$21, &attribute, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_22$$21);
					_23$$21 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_23$$21) {
						_23$$21 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_23$$21) {

						/* try_start_2: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
							zephir_check_call_status_or_jump(try_end_2);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_24$$22);
							ZVAL_OBJ(&_24$$22, EG(exception));
							Z_ADDREF_P(&_24$$22);
							ZEPHIR_INIT_NVAR(&_25$$22);
							if (zephir_is_instance_of(&_24$$22, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_25$$22, &_24$$22);
								zephir_update_property_zval_zval(&instance, &attribute, &value);
							}
						}
						continue;
					}
				}
				zephir_update_property_zval_zval(&instance, &attribute, &value);
				continue;
			}
			_26$$5 = !ZEPHIR_IS_STRING(&value, "");
			if (_26$$5) {
				_26$$5 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_26$$5) {
				zephir_array_fetch_long(&_27$$25, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 134);
				do {
					if (ZEPHIR_IS_LONG(&_27$$25, 0) || ZEPHIR_IS_LONG(&_27$$25, 21) || ZEPHIR_IS_LONG(&_27$$25, 22) || ZEPHIR_IS_LONG(&_27$$25, 26)) {
						ZVAL_LONG(&_28$$26, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_29, 95, &value, &_28$$26);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_27$$25, 3) || ZEPHIR_IS_LONG(&_27$$25, 9) || ZEPHIR_IS_LONG(&_27$$25, 7)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
						break;
					}
					if (ZEPHIR_IS_LONG(&_27$$25, 8)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
						break;
					}
					if (ZEPHIR_IS_LONG(&_27$$25, 40) || ZEPHIR_IS_LONG(&_27$$25, 41) || ZEPHIR_IS_LONG(&_27$$25, 42) || ZEPHIR_IS_LONG(&_27$$25, 43) || ZEPHIR_IS_LONG(&_27$$25, 44) || ZEPHIR_IS_LONG(&_27$$25, 45) || ZEPHIR_IS_LONG(&_27$$25, 46) || ZEPHIR_IS_LONG(&_27$$25, 47)) {

						/* try_start_3: */

							ZEPHIR_INIT_NVAR(&_30$$30);
							object_init_ex(&_30$$30, phalcon_db_geometry_wkbparser_ce);
							if (zephir_has_constructor(&_30$$30)) {
								ZEPHIR_CALL_METHOD(NULL, &_30$$30, "__construct", NULL, 0);
								zephir_check_call_status_or_jump(try_end_3);
							}

							ZEPHIR_CALL_METHOD(&castValue, &_30$$30, "parse", &_31, 0, &value);
							zephir_check_call_status_or_jump(try_end_3);

						try_end_3:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_32$$29);
							ZVAL_OBJ(&_32$$29, EG(exception));
							Z_ADDREF_P(&_32$$29);
							ZEPHIR_INIT_NVAR(&_33$$29);
							if (zephir_instance_of_ev(&_32$$29, phalcon_db_exceptions_invalidwkb_ce)) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_33$$29, &_32$$29);
								ZEPHIR_CPY_WRT(&castValue, &value);
							}
						}
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			} else {
				zephir_array_fetch_long(&_34$$33, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 173);
				do {
					if (ZEPHIR_IS_LONG(&_34$$33, 14) || ZEPHIR_IS_LONG(&_34$$33, 8) || ZEPHIR_IS_LONG(&_34$$33, 3) || ZEPHIR_IS_LONG(&_34$$33, 9) || ZEPHIR_IS_LONG(&_34$$33, 7) || ZEPHIR_IS_LONG(&_34$$33, 0) || ZEPHIR_IS_LONG(&_34$$33, 21) || ZEPHIR_IS_LONG(&_34$$33, 22) || ZEPHIR_IS_LONG(&_34$$33, 26)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_NULL(&castValue);
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			}
			ZEPHIR_OBS_NVAR(&attributeName);
			zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 192);
			zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
			if (callSetters) {
				ZEPHIR_INIT_NVAR(&_35$$36);
				zephir_camelize(&_35$$36, &attributeName, NULL );
				ZEPHIR_INIT_NVAR(&setter);
				ZEPHIR_CONCAT_SV(&setter, "set", &_35$$36);
				_36$$36 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
				if (_36$$36) {
					_36$$36 = !(zephir_array_isset_value(&localMethods, &setter));
				}
				if (_36$$36) {

					/* try_start_4: */

						ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
						zephir_check_call_status_or_jump(try_end_4);

					try_end_4:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_37$$37);
						ZVAL_OBJ(&_37$$37, EG(exception));
						Z_ADDREF_P(&_37$$37);
						ZEPHIR_INIT_NVAR(&_38$$37);
						if (zephir_is_instance_of(&_37$$37, SL("TypeError"))) {
							zend_clear_exception();
							ZEPHIR_CPY_WRT(&_38$$37, &_37$$37);
							zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
						}
					}
					continue;
				}
			}
			zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		_40 = 1;
		while (1) {
			if (_40) {
				_40 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_39, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_39)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) != IS_STRING) {
					continue;
				}
				_41$$40 = Z_TYPE_P(&value) == IS_NULL;
				if (_41$$40) {
					_41$$40 = zephir_fast_in_array(&key, &notNullAttributes);
				}
				if (_41$$40) {
					continue;
				}
				if (Z_TYPE_P(columnMap) != IS_ARRAY) {
					if (callSetters) {
						ZEPHIR_INIT_NVAR(&_42$$44);
						zephir_camelize(&_42$$44, &key, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_42$$44);
						_43$$44 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_43$$44) {
							_43$$44 = !(zephir_array_isset_value(&localMethods, &setter));
						}
						if (_43$$44) {

							/* try_start_5: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_5);

							try_end_5:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_44$$45);
								ZVAL_OBJ(&_44$$45, EG(exception));
								Z_ADDREF_P(&_44$$45);
								ZEPHIR_INIT_NVAR(&_45$$45);
								if (zephir_is_instance_of(&_44$$45, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_45$$45, &_44$$45);
									zephir_update_property_zval_zval(&instance, &key, &value);
								}
							}
							continue;
						}
					}
					zephir_update_property_zval_zval(&instance, &key, &value);
					continue;
				}
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0))) {
					_46$$48 = Z_TYPE_P(columnMap) == IS_ARRAY;
					if (_46$$48) {
						_46$$48 = !(ZEPHIR_IS_EMPTY(columnMap));
					}
					if (_46$$48) {
						if (Z_TYPE_P(&metaData) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&metaData, &instance, "getmodelsmetadata", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&reverseMap, &metaData, "getreversecolumnmap", NULL, 0, &instance);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&attribute);
						if (!(zephir_array_isset_fetch(&attribute, &reverseMap, &key, 0))) {
							ZEPHIR_INIT_NVAR(&_48$$51);
							ZVAL_STRING(&_48$$51, "orm.ignore_unknown_columns");
							ZEPHIR_CALL_CE_STATIC(&_47$$51, phalcon_support_settings_ce, "get", &_13, 0, &_48$$51);
							zephir_check_call_status();
							if (UNEXPECTED(!zephir_is_true(&_47$$51))) {
								ZEPHIR_INIT_NVAR(&_49$$52);
								object_init_ex(&_49$$52, phalcon_mvc_model_exceptions_columnnotinmap_ce);
								ZEPHIR_INIT_NVAR(&_50$$52);
								zephir_get_class(&_50$$52, base, 0);
								ZEPHIR_CALL_METHOD(NULL, &_49$$52, "__construct", &_17, 0, &key, &_50$$52);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_49$$52, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 101);
								ZEPHIR_MM_RESTORE();
								return;
							}
							continue;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_52$$53);
						ZVAL_STRING(&_52$$53, "orm.ignore_unknown_columns");
						ZEPHIR_CALL_CE_STATIC(&_51$$53, phalcon_support_settings_ce, "get", &_13, 0, &_52$$53);
						zephir_check_call_status();
						if (UNEXPECTED(!zephir_is_true(&_51$$53))) {
							ZEPHIR_INIT_NVAR(&_53$$54);
							object_init_ex(&_53$$54, phalcon_mvc_model_exceptions_columnnotinmap_ce);
							ZEPHIR_INIT_NVAR(&_54$$54);
							zephir_get_class(&_54$$54, base, 0);
							ZEPHIR_CALL_METHOD(NULL, &_53$$54, "__construct", &_17, 0, &key, &_54$$54);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_53$$54, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 108);
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				if (Z_TYPE_P(&attribute) != IS_ARRAY) {
					if (callSetters) {
						ZEPHIR_INIT_NVAR(&_55$$56);
						zephir_camelize(&_55$$56, &attribute, NULL );
						ZEPHIR_INIT_NVAR(&setter);
						ZEPHIR_CONCAT_SV(&setter, "set", &_55$$56);
						_56$$56 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
						if (_56$$56) {
							_56$$56 = !(zephir_array_isset_value(&localMethods, &setter));
						}
						if (_56$$56) {

							/* try_start_6: */

								ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &value);
								zephir_check_call_status_or_jump(try_end_6);

							try_end_6:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_57$$57);
								ZVAL_OBJ(&_57$$57, EG(exception));
								Z_ADDREF_P(&_57$$57);
								ZEPHIR_INIT_NVAR(&_58$$57);
								if (zephir_is_instance_of(&_57$$57, SL("TypeError"))) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_58$$57, &_57$$57);
									zephir_update_property_zval_zval(&instance, &attribute, &value);
								}
							}
							continue;
						}
					}
					zephir_update_property_zval_zval(&instance, &attribute, &value);
					continue;
				}
				_59$$40 = !ZEPHIR_IS_STRING(&value, "");
				if (_59$$40) {
					_59$$40 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_59$$40) {
					zephir_array_fetch_long(&_60$$60, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 134);
					do {
						if (ZEPHIR_IS_LONG(&_60$$60, 0) || ZEPHIR_IS_LONG(&_60$$60, 21) || ZEPHIR_IS_LONG(&_60$$60, 22) || ZEPHIR_IS_LONG(&_60$$60, 26)) {
							ZVAL_LONG(&_61$$61, 10);
							ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_29, 95, &value, &_61$$61);
							zephir_check_call_status();
							break;
						}
						if (ZEPHIR_IS_LONG(&_60$$60, 3) || ZEPHIR_IS_LONG(&_60$$60, 9) || ZEPHIR_IS_LONG(&_60$$60, 7)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
							break;
						}
						if (ZEPHIR_IS_LONG(&_60$$60, 8)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
							break;
						}
						if (ZEPHIR_IS_LONG(&_60$$60, 40) || ZEPHIR_IS_LONG(&_60$$60, 41) || ZEPHIR_IS_LONG(&_60$$60, 42) || ZEPHIR_IS_LONG(&_60$$60, 43) || ZEPHIR_IS_LONG(&_60$$60, 44) || ZEPHIR_IS_LONG(&_60$$60, 45) || ZEPHIR_IS_LONG(&_60$$60, 46) || ZEPHIR_IS_LONG(&_60$$60, 47)) {

							/* try_start_7: */

								ZEPHIR_INIT_NVAR(&_62$$65);
								object_init_ex(&_62$$65, phalcon_db_geometry_wkbparser_ce);
								if (zephir_has_constructor(&_62$$65)) {
									ZEPHIR_CALL_METHOD(NULL, &_62$$65, "__construct", NULL, 0);
									zephir_check_call_status_or_jump(try_end_7);
								}

								ZEPHIR_CALL_METHOD(&castValue, &_62$$65, "parse", &_31, 0, &value);
								zephir_check_call_status_or_jump(try_end_7);

							try_end_7:

							if (EG(exception)) {
								ZEPHIR_INIT_NVAR(&_63$$64);
								ZVAL_OBJ(&_63$$64, EG(exception));
								Z_ADDREF_P(&_63$$64);
								ZEPHIR_INIT_NVAR(&_64$$64);
								if (zephir_instance_of_ev(&_63$$64, phalcon_db_exceptions_invalidwkb_ce)) {
									zend_clear_exception();
									ZEPHIR_CPY_WRT(&_64$$64, &_63$$64);
									ZEPHIR_CPY_WRT(&castValue, &value);
								}
							}
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				} else {
					zephir_array_fetch_long(&_65$$68, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 173);
					do {
						if (ZEPHIR_IS_LONG(&_65$$68, 14) || ZEPHIR_IS_LONG(&_65$$68, 8) || ZEPHIR_IS_LONG(&_65$$68, 3) || ZEPHIR_IS_LONG(&_65$$68, 9) || ZEPHIR_IS_LONG(&_65$$68, 7) || ZEPHIR_IS_LONG(&_65$$68, 0) || ZEPHIR_IS_LONG(&_65$$68, 21) || ZEPHIR_IS_LONG(&_65$$68, 22) || ZEPHIR_IS_LONG(&_65$$68, 26)) {
							ZEPHIR_INIT_NVAR(&castValue);
							ZVAL_NULL(&castValue);
							break;
						}
						ZEPHIR_CPY_WRT(&castValue, &value);
						break;
					} while(0);

				}
				ZEPHIR_OBS_NVAR(&attributeName);
				zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/Mvc/Model/Hydration/CloneResultMap.zep", 192);
				zephir_array_update_zval(&data, &key, &castValue, PH_COPY | PH_SEPARATE);
				if (callSetters) {
					ZEPHIR_INIT_NVAR(&_66$$71);
					zephir_camelize(&_66$$71, &attributeName, NULL );
					ZEPHIR_INIT_NVAR(&setter);
					ZEPHIR_CONCAT_SV(&setter, "set", &_66$$71);
					_67$$71 = (zephir_method_exists(&instance, &setter)  == SUCCESS);
					if (_67$$71) {
						_67$$71 = !(zephir_array_isset_value(&localMethods, &setter));
					}
					if (_67$$71) {

						/* try_start_8: */

							ZEPHIR_CALL_METHOD_ZVAL(NULL, &instance, &setter, NULL, 0, &castValue);
							zephir_check_call_status_or_jump(try_end_8);

						try_end_8:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_68$$72);
							ZVAL_OBJ(&_68$$72, EG(exception));
							Z_ADDREF_P(&_68$$72);
							ZEPHIR_INIT_NVAR(&_69$$72);
							if (zephir_is_instance_of(&_68$$72, SL("TypeError"))) {
								zend_clear_exception();
								ZEPHIR_CPY_WRT(&_69$$72, &_68$$72);
								zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
							}
						}
						continue;
					}
				}
				zephir_update_property_zval_zval(&instance, &attributeName, &castValue);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "setsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_70$$75, &instance, "getsnapshotdata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &instance, "setoldsnapshotdata", NULL, 0, &_70$$75);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&instance, ZEND_STRL("fireevent")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_71$$76);
		ZVAL_STRING(&_71$$76, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_71$$76);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&instance);
}

