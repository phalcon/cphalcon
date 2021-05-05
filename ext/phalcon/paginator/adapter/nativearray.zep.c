
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
#include "kernel/operators.h"
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
	zval _6;
	double roundedTotal = 0;
	zval config, items, _0, _1, _2, _3, _4, _5, _7, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, show = 0, pageNumber = 0, totalPages = 0, number = 0, previous = 0, next = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&config, &_0);
	ZEPHIR_OBS_VAR(&items);
	zephir_array_fetch_string(&items, &config, SL("data"), PH_NOISY, "phalcon/Paginator/Adapter/NativeArray.zep", 54);
	if (UNEXPECTED(Z_TYPE_P(&items) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/Paginator/Adapter/NativeArray.zep", 57);
		return;
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(&_1);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(&_2);
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	number = zephir_fast_count_int(&items);
	ZVAL_LONG(&_0, show);
	ZEPHIR_CALL_FUNCTION(&_3, "floatval", NULL, 18, &_0);
	zephir_check_call_status();
	roundedTotal = zephir_safe_div_long_zval(number, &_3);
	totalPages = (int) (roundedTotal);
	if (totalPages != roundedTotal) {
		totalPages++;
	}
	ZVAL_LONG(&_0, (show * ((pageNumber - 1))));
	ZVAL_LONG(&_4, show);
	ZEPHIR_CALL_FUNCTION(&_5, "array_slice", NULL, 260, &items, &_0, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&items, &_5);
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
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 8, 0);
	zephir_array_update_string(&_6, SL("items"), &items, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_LONG(&_7, number);
	zephir_array_update_string(&_6, SL("total_items"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_6, SL("limit"), &_8, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_6, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, previous);
	zephir_array_update_string(&_6, SL("previous"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, pageNumber);
	zephir_array_update_string(&_6, SL("current"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, next);
	zephir_array_update_string(&_6, SL("next"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_LONG(&_7, totalPages);
	zephir_array_update_string(&_6, SL("last"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

