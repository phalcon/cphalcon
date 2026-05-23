
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Paginator\Adapter\NativeArray
 *
 * Pagination using a PHP array as source of data
 *
 * ```php
 * use Phalcon\Paginator\Adapter\NativeArray;
 *
 * $paginator = new NativeArray(
 *     [
 *         "data"  => [
 *             ["id" => 1, "name" => "Artichoke"],
 *             ["id" => 2, "name" => "Carrots"],
 *             ["id" => 3, "name" => "Beet"],
 *             ["id" => 4, "name" => "Lettuce"],
 *             ["id" => 5, "name" => ""],
 *         ],
 *         "limit" => 2,
 *         "page"  => $currentPage,
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, NativeArray, phalcon, paginator_adapter_nativearray, phalcon_paginator_adapter_abstractadapter_ce, phalcon_paginator_adapter_nativearray_method_entry, 0);

	return SUCCESS;
}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, paginate)
{
	zval _7;
	double roundedTotal = 0;
	zval config, items, _0, _2, _3, _4, _5, _6, _8, _9, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, show = 0, pageNumber = 0, totalPages = 0, number = 0, previous = 0, next = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&config, &_0);
	zephir_memory_observe(&items);
	zephir_array_fetch_string(&items, &config, SL("data"), PH_NOISY, "phalcon/Paginator/Adapter/NativeArray.zep", 55);
	if (UNEXPECTED(Z_TYPE_P(&items) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_paginator_exceptions_paginatordatanotarray_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Paginator/Adapter/NativeArray.zep", 58);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(&_2);
	zephir_memory_observe(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(&_3);
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	number = zephir_fast_count_int(&items);
	ZVAL_LONG(&_0, show);
	ZEPHIR_CALL_FUNCTION(&_4, "floatval", NULL, 32, &_0);
	zephir_check_call_status();
	roundedTotal =  (zephir_safe_div_long_zval(number, &_4));
	totalPages = (int) (roundedTotal);
	if (totalPages != roundedTotal) {
		totalPages++;
	}
	ZVAL_LONG(&_0, (show * ((pageNumber - 1))));
	ZVAL_LONG(&_5, show);
	ZEPHIR_CALL_FUNCTION(&_6, "array_slice", NULL, 189, &items, &_0, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&items, &_6);
	if (pageNumber < totalPages) {
		next = (pageNumber + 1);
	} else {
		next = totalPages;
	}
	if (pageNumber > 1) {
		previous = (pageNumber - 1);
	} else {
		previous = 1;
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 8, 0);
	zephir_array_update_string(&_7, SL("items"), &items, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_LONG(&_8, number);
	zephir_array_update_string(&_7, SL("total_items"), &_8, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_9);
	zephir_read_property(&_9, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_7, SL("limit"), &_9, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_7, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, previous);
	zephir_array_update_string(&_7, SL("previous"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, pageNumber);
	zephir_array_update_string(&_7, SL("current"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, next);
	zephir_array_update_string(&_7, SL("next"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_LONG(&_8, totalPages);
	zephir_array_update_string(&_7, SL("last"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_7);
	zephir_check_call_status();
	RETURN_MM();
}

