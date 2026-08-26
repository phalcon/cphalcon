
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
 * For the full copyright and license information, please view the LICENSE.txt
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL;
	zval config;

	ZVAL_UNDEF(&config);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);
	if (UNEXPECTED(!(zephir_array_isset_value_string(&config, SL("model"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "model", "phalcon/Paginator/Adapter/Model.zep", 98);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_paginator_adapter_model_ce, getThis(), "__construct", NULL, 0, &config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, paginate)
{
	zval _6, _14, _5$$4, _11$$10;
	zval config, modelClass, parameters, rowCountResult, pageItems, _0, _1, _2, _3, _7, _15, _4$$4, _8$$6, _9$$10, _10$$10, _12$$10, _13$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pageNumber = 0, limit = 0, rowcount = 0, next = 0, totalPages = 0, previous = 0;
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
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_11$$10);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1230, PH_NOISY_CC);
	limit = zephir_get_intval(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1231, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&config, &_1);
	zephir_memory_observe(&_2);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 1232, PH_NOISY_CC);
	pageNumber = zephir_get_intval(&_2);
	zephir_array_fetch_string(&_3, &config, SL("model"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/Model.zep", 117);
	ZEPHIR_CPY_WRT(&modelClass, &_3);
	zephir_memory_observe(&parameters);
	if (!(zephir_array_isset_string_fetch(&parameters, &config, SL("parameters"), 0))) {
		ZEPHIR_INIT_NVAR(&parameters);
		array_init(&parameters);
	}
	if (UNEXPECTED(Z_TYPE_P(&parameters) != IS_ARRAY)) {
		ZEPHIR_CPY_WRT(&_4$$4, &parameters);
		zephir_get_arrval(&_5$$4, &_4$$4);
		ZEPHIR_CPY_WRT(&parameters, &_5$$4);
	}
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	zephir_array_fast_append(&_6, &modelClass);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "count");
	zephir_array_fast_append(&_6, &_7);
	ZEPHIR_CALL_FUNCTION(&rowCountResult, "call_user_func", NULL, 82, &_6, &parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&rowCountResult) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_8$$6, &rowCountResult, "count", NULL, 0);
		zephir_check_call_status();
		rowcount = zephir_get_intval(&_8$$6);
	} else {
		rowcount = zephir_get_intval(&rowCountResult);
	}
	if (zephir_safe_mod_long_long(rowcount, limit) != 0) {
		totalPages = (int) ((zephir_safe_div_long_long(rowcount, limit) + (double) (1)));
	} else {
		totalPages = (int) (zephir_safe_div_long_long(rowcount, limit));
	}
	if (rowcount > 0) {
		ZEPHIR_INIT_VAR(&_9$$10);
		ZVAL_LONG(&_9$$10, limit);
		zephir_array_update_string(&parameters, SL("limit"), &_9$$10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_10$$10);
		ZVAL_LONG(&_10$$10, (limit * ((pageNumber - 1))));
		zephir_array_update_string(&parameters, SL("offset"), &_10$$10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_11$$10);
		zephir_create_array(&_11$$10, 2, 0);
		zephir_array_fast_append(&_11$$10, &modelClass);
		ZEPHIR_INIT_VAR(&_12$$10);
		ZVAL_STRING(&_12$$10, "find");
		zephir_array_fast_append(&_11$$10, &_12$$10);
		ZEPHIR_CALL_FUNCTION(&_13$$10, "call_user_func", NULL, 82, &_11$$10, &parameters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&pageItems, &_13$$10);
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
	ZEPHIR_INIT_VAR(&_14);
	zephir_create_array(&_14, 8, 0);
	zephir_array_update_string(&_14, SL("items"), &pageItems, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, rowcount);
	zephir_array_update_string(&_14, SL("total_items"), &_7, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_15);
	zephir_read_property_cached(&_15, this_ptr, _zephir_prop_0, 1230, PH_NOISY_CC);
	zephir_array_update_string(&_14, SL("limit"), &_15, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_14, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, previous);
	zephir_array_update_string(&_14, SL("previous"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, pageNumber);
	zephir_array_update_string(&_14, SL("current"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, next);
	zephir_array_update_string(&_14, SL("next"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, totalPages);
	zephir_array_update_string(&_14, SL("last"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_14);
	zephir_check_call_status();
	RETURN_MM();
}

