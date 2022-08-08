
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
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
/**
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using a Phalcon\Mvc\Model resultset as a
 * base.
 *
 * ```php
 * use Phalcon\Paginator\Adapter\Model;
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "limit" => 25,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "parameters" => [
 *              "columns" => "id, name"
 *         ],
 *         "limit" => 12,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "parameters" => [
 *              "type = :type:",
 *              "bind" => [
 *                  "type" => "mechanical"
 *              ],
 *              "order" => "name"
 *         ],
 *         "limit" => 16,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "parameters" => "(id % 2) = 0",
 *         "limit" => 8,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 *
 * $paginator = new Model(
 *     [
 *         "model" => Robots::class,
 *         "parameters" => [ "(id % 2) = 0" ],
 *         "limit" => 8,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 * $paginate = $paginator->paginate();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_Model)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, Model, phalcon, paginator_adapter_model, phalcon_paginator_adapter_abstractadapter_ce, phalcon_paginator_adapter_model_method_entry, 0);

	return SUCCESS;
}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, paginate)
{
	zval _5, _13, _4$$4, _10$$10;
	zval config, modelClass, parameters, rowCountResult, pageItems, _0, _1, _2, _3, _6, _14, _7$$6, _8$$10, _9$$10, _11$$10, _12$$10;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_10$$10);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&pageItems);
	array_init(&pageItems);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	limit = zephir_get_intval(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&config, &_1);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(&_2);
	zephir_array_fetch_string(&_3, &config, SL("model"), PH_NOISY | PH_READONLY, "phalcon/Paginator/Adapter/Model.zep", 100);
	ZEPHIR_CPY_WRT(&modelClass, &_3);
	ZEPHIR_OBS_VAR(&parameters);
	if (!(zephir_array_isset_string_fetch(&parameters, &config, SL("parameters"), 0))) {
		ZEPHIR_INIT_NVAR(&parameters);
		array_init(&parameters);
	}
	if (UNEXPECTED(Z_TYPE_P(&parameters) != IS_ARRAY)) {
		zephir_get_arrval(&_4$$4, &parameters);
		ZEPHIR_CPY_WRT(&parameters, &_4$$4);
	}
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	zephir_array_fast_append(&_5, &modelClass);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "count");
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_CALL_FUNCTION(&rowCountResult, "call_user_func", NULL, 181, &_5, &parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&rowCountResult) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_7$$6, &rowCountResult, "count", NULL, 0);
		zephir_check_call_status();
		rowcount = zephir_get_intval(&_7$$6);
	} else {
		rowcount = zephir_get_intval(&rowCountResult);
	}
	if (zephir_safe_mod_long_long(rowcount, limit) != 0) {
		totalPages = (int) ((zephir_safe_div_long_long(rowcount, limit) + (double) (1)));
	} else {
		totalPages = (int) (zephir_safe_div_long_long(rowcount, limit));
	}
	if (rowcount > 0) {
		ZEPHIR_INIT_VAR(&_8$$10);
		ZVAL_LONG(&_8$$10, limit);
		zephir_array_update_string(&parameters, SL("limit"), &_8$$10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_9$$10);
		ZVAL_LONG(&_9$$10, (limit * ((pageNumber - 1))));
		zephir_array_update_string(&parameters, SL("offset"), &_9$$10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_10$$10);
		zephir_create_array(&_10$$10, 2, 0);
		zephir_array_fast_append(&_10$$10, &modelClass);
		ZEPHIR_INIT_VAR(&_11$$10);
		ZVAL_STRING(&_11$$10, "find");
		zephir_array_fast_append(&_10$$10, &_11$$10);
		ZEPHIR_CALL_FUNCTION(&_12$$10, "call_user_func", NULL, 181, &_10$$10, &parameters);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&pageItems, &_12$$10);
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
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 8, 0);
	zephir_array_update_string(&_13, SL("items"), &pageItems, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_LONG(&_6, rowcount);
	zephir_array_update_string(&_13, SL("total_items"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_14);
	zephir_read_property(&_14, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_13, SL("limit"), &_14, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_13, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_LONG(&_6, previous);
	zephir_array_update_string(&_13, SL("previous"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_LONG(&_6, pageNumber);
	zephir_array_update_string(&_13, SL("current"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_LONG(&_6, next);
	zephir_array_update_string(&_13, SL("next"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_LONG(&_6, totalPages);
	zephir_array_update_string(&_13, SL("last"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_13);
	zephir_check_call_status();
	RETURN_MM();
}

