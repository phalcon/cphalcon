
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
#include "kernel/exception.h"
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
 *         "data"  => Robots::find(),
 *         "limit" => 25,
 *         "page"  => $currentPage,
 *     ]
 * );
 *
 * $paginate = $paginator->paginate();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_Model) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, Model, phalcon, paginator_adapter_model, phalcon_paginator_adapter_abstractadapter_ce, phalcon_paginator_adapter_model_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, paginate) {

	zval _9;
	zval config, items, pageItems, _0, _1, _2, _10, _11, _3$$9, _4$$10, _5$$8, _6$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pageNumber = 0, show = 0, n = 0, start = 0, lastShowPage = 0, i = 0, next = 0, totalPages = 0, previous = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&pageItems);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(&_0);
	zephir_read_property(&_1, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&config, &_1);
	ZEPHIR_OBS_VAR(&items);
	zephir_array_fetch_string(&items, &config, SL("data"), PH_NOISY, "phalcon/Paginator/Adapter/Model.zep", 50 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(&_2);
	if (UNEXPECTED(Z_TYPE_P(&items) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/Paginator/Adapter/Model.zep", 54);
		return;
	}
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	if (UNEXPECTED(show <= 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "The start page number is zero or less", "phalcon/Paginator/Adapter/Model.zep", 64);
		return;
	}
	n = zephir_fast_count_int(&items TSRMLS_CC);
	lastShowPage = (pageNumber - 1);
	start = (show * lastShowPage);
	ZEPHIR_INIT_VAR(&pageItems);
	array_init(&pageItems);
	if (zephir_safe_mod_long_long(n, show TSRMLS_CC) != 0) {
		totalPages = (int) ((zephir_safe_div_long_long(n, show TSRMLS_CC) + (double) (1)));
	} else {
		totalPages = (int) (zephir_safe_div_long_long(n, show TSRMLS_CC));
	}
	if (n > 0) {
		if (start <= n) {
			ZVAL_LONG(&_3$$9, start);
			ZEPHIR_CALL_METHOD(NULL, &items, "seek", NULL, 0, &_3$$9);
			zephir_check_call_status();
		} else {
			ZVAL_LONG(&_4$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &items, "seek", NULL, 0, &_4$$10);
			zephir_check_call_status();
			pageNumber = 1;
		}
		i = 1;
		while (1) {
			ZEPHIR_CALL_METHOD(&_5$$8, &items, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_5$$8))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_6$$11, &items, "current", &_7, 0);
			zephir_check_call_status();
			zephir_array_append(&pageItems, &_6$$11, PH_SEPARATE, "phalcon/Paginator/Adapter/Model.zep", 92);
			if (i >= show) {
				break;
			}
			i++;
			ZEPHIR_CALL_METHOD(NULL, &items, "next", &_8, 0);
			zephir_check_call_status();
		}
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
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 8, 0 TSRMLS_CC);
	zephir_array_update_string(&_9, SL("items"), &pageItems, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_LONG(&_10, n);
	zephir_array_update_string(&_9, SL("total_items"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_11);
	zephir_read_property(&_11, this_ptr, SL("limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("limit"), &_11, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_9, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_10);
	ZVAL_LONG(&_10, previous);
	zephir_array_update_string(&_9, SL("previous"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_10);
	ZVAL_LONG(&_10, pageNumber);
	zephir_array_update_string(&_9, SL("current"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_10);
	ZVAL_LONG(&_10, next);
	zephir_array_update_string(&_9, SL("next"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_10);
	ZVAL_LONG(&_10, totalPages);
	zephir_array_update_string(&_9, SL("last"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

