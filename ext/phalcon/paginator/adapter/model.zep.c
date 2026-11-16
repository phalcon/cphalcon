
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This adapter allows to paginate data using a Phalcon\Mvc\Model resultset as a
 * base.
 *
 * ```php
 * use Phalcon\Paginator\Adapter\Model;
 *
 * $paginator = new Model(
 *     [
 *         "model" => Invoices::class,
 *         "limit" => 25,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Invoices::class,
 *         "parameters" => [
 *              "columns" => "inv_id, inv_title"
 *         ],
 *         "limit" => 12,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Invoices::class,
 *         "parameters" => [
 *              "inv_status_flag = :flag:",
 *              "bind" => [
 *                  "flag" => 1
 *              ],
 *              "order" => "inv_title"
 *         ],
 *         "limit" => 16,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 * $paginator = new Model(
 *     [
 *         "model" => Invoices::class,
 *         "parameters" => "(inv_id % 2) = 0",
 *         "limit" => 8,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Invoices::class,
 *         "parameters" => [ "(inv_id % 2) = 0" ],
 *         "limit" => 8,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 * $paginate = $paginator->paginate();
 *```
 *
 * @phpstan-import-type paginator_config from PaginatorTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_Model)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, Model, phalcon, paginator_adapter_model, phalcon_paginator_adapter_abstractadapter_ce, phalcon_paginator_adapter_model_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\Model constructor
 *
 * @param paginator_config $config = [
 *     'model'  => null,
 *     'limit'  => 10,
 *     'page'   => 1
 * ]
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL;
	zval config;

	ZVAL_UNDEF(&config);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);
	_0 = zephir_array_isset_value_string(&config, SL("model"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "model", "phalcon/Paginator/Adapter/Model.zep", 98);
		return;
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_paginator_adapter_model_ce, getThis(), "__construct", &_zephir_call_cache[0], &config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, paginate)
{
	zend_long _11;
	zval _7, _21, _6$$4, _18$$10;
	zend_bool _4;
	zval config, modelClass, parameters, rowCountResult, pageItems, _0, _1, _2, _3, _8, _5$$4, _10$$6, _12$$8, _13$$8, _14$$8, _15$$9, _16$$10, _17$$10, _19$$10, _20$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pageNumber = 0, limit = 0, rowcount = 0, next = 0, totalPages = 0, previous = 0;
	zephir_fcall_cache_entry *_9 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&modelClass);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&rowCountResult);
	ZVAL_UNDEF(&pageItems);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_18$$10);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("limitRows", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("config", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("page", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&pageItems);
	array_init(&pageItems);
	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1248, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	limit = zephir_get_intval(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1249, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&config, &_1);
	zephir_memory_observe(&_2);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 1250, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	pageNumber = zephir_get_intval(&_2);
	zephir_memory_observe(&_3);
	zephir_array_fetch_string(&_3, &config, SL("model"), PH_NOISY, "phalcon/Paginator/Adapter/Model.zep", 117);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&modelClass, &_3);
	zephir_memory_observe(&parameters);
	_4 = zephir_array_isset_string_fetch(&parameters, &config, SL("parameters"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_4)) {
		ZEPHIR_INIT_NVAR(&parameters);
		array_init(&parameters);
	}
	if (UNEXPECTED(Z_TYPE_P(&parameters) != IS_ARRAY)) {
		ZEPHIR_CPY_WRT(&_5$$4, &parameters);
		zephir_get_arrval(&_6$$4, &_5$$4);
		ZEPHIR_CPY_WRT(&parameters, &_6$$4);
	}
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	zephir_array_fast_append(&_7, &modelClass);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "count");
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_CALL_FUNCTION(&rowCountResult, "call_user_func", &_9, 34, &_7, &parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&rowCountResult) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD_CACHED(&_10$$6, &rowCountResult, "count", &_zephir_call_cache[0]);
		zephir_check_call_status();
		rowcount = zephir_get_intval(&_10$$6);
	} else {
		rowcount = zephir_get_intval(&rowCountResult);
	}
	_11 = zephir_safe_mod_long_long(rowcount, limit);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_11 != 0) {
		ZEPHIR_INIT_VAR(&_12$$8);
		zephir_div_long_long(&_12$$8, rowcount, limit);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_13$$8);
		ZVAL_LONG(&_13$$8, 1);
		ZEPHIR_INIT_VAR(&_14$$8);
		zephir_add_function(&_14$$8, &_12$$8, &_13$$8);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		totalPages = zephir_get_intval(&_14$$8);
	} else {
		ZEPHIR_INIT_VAR(&_15$$9);
		zephir_div_long_long(&_15$$9, rowcount, limit);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		totalPages = zephir_get_intval(&_15$$9);
	}
	if (rowcount > 0) {
		ZEPHIR_INIT_VAR(&_16$$10);
		ZVAL_LONG(&_16$$10, limit);
		zephir_array_update_string(&parameters, SL("limit"), &_16$$10, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_17$$10);
		ZVAL_LONG(&_17$$10, (limit * ((pageNumber - 1))));
		zephir_array_update_string(&parameters, SL("offset"), &_17$$10, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_18$$10);
		zephir_create_array(&_18$$10, 2, 0);
		zephir_array_fast_append(&_18$$10, &modelClass);
		ZEPHIR_INIT_VAR(&_19$$10);
		ZVAL_STRING(&_19$$10, "find");
		zephir_array_fast_append(&_18$$10, &_19$$10);
		ZEPHIR_CALL_FUNCTION(&_20$$10, "call_user_func", &_9, 34, &_18$$10, &parameters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&pageItems, &_20$$10);
	}
	next = (pageNumber + 1);
	if (next > totalPages) {
		next = totalPages;
	}
	if (pageNumber > 1) {
		previous = (pageNumber - 1);
	} else {
		previous = 1;
	}
	ZEPHIR_INIT_VAR(&_21);
	zephir_create_array(&_21, 8, 0);
	zephir_array_update_string(&_21, SL("items"), &pageItems, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, rowcount);
	zephir_array_update_string(&_21, SL("total_items"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 1248, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_21, SL("limit"), &_3, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_21, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, previous);
	zephir_array_update_string(&_21, SL("previous"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, pageNumber);
	zephir_array_update_string(&_21, SL("current"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, next);
	zephir_array_update_string(&_21, SL("next"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, totalPages);
	zephir_array_update_string(&_21, SL("last"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getRepository", &_zephir_call_cache[1], &_21);
	zephir_check_call_status();
	RETURN_MM();
}

