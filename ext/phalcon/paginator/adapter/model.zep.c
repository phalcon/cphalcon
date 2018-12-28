
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using a Phalcon\Mvc\Model resultset as a base.
 *
 * <code>
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
 * $paginate = $paginator->getPaginate();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_Model) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, Model, phalcon, paginator_adapter_model, phalcon_paginator_adapter_ce, phalcon_paginator_adapter_model_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, paginate) {

	zval _8;
	zval config, items, pageItems, _0, _1, _9, _10, _2$$9, _3$$10, _4$$8, _5$$11;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pageNumber = 0, show = 0, n = 0, start = 0, lastShowPage = 0, i = 0, next = 0, totalPages = 0, previous = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&pageItems);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(&_0);
	ZEPHIR_OBS_VAR(&config);
	zephir_read_property(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&items);
	zephir_array_fetch_string(&items, &config, SL("data"), PH_NOISY, "phalcon/paginator/adapter/model.zep", 49 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(&_1);
	if (Z_TYPE_P(&items) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/paginator/adapter/model.zep", 53);
		return;
	}
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	if (show <= 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "The start page number is zero or less", "phalcon/paginator/adapter/model.zep", 63);
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
			ZVAL_LONG(&_2$$9, start);
			ZEPHIR_CALL_METHOD(NULL, &items, "seek", NULL, 0, &_2$$9);
			zephir_check_call_status();
		} else {
			ZVAL_LONG(&_3$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &items, "seek", NULL, 0, &_3$$10);
			zephir_check_call_status();
			pageNumber = 1;
		}
		i = 1;
		while (1) {
			ZEPHIR_CALL_METHOD(&_4$$8, &items, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_4$$8))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_5$$11, &items, "current", &_6, 0);
			zephir_check_call_status();
			zephir_array_append(&pageItems, &_5$$11, PH_SEPARATE, "phalcon/paginator/adapter/model.zep", 90);
			if (i >= show) {
				break;
			}
			i++;
			ZEPHIR_CALL_METHOD(NULL, &items, "next", &_7, 0);
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
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 8, 0 TSRMLS_CC);
	zephir_array_update_string(&_8, SL("items"), &pageItems, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_LONG(&_9, n);
	zephir_array_update_string(&_8, SL("total_items"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_10);
	zephir_read_property(&_10, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_8, SL("limit"), &_10, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_8, SL("first"), 1);
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_LONG(&_9, previous);
	zephir_array_update_string(&_8, SL("previous"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_LONG(&_9, pageNumber);
	zephir_array_update_string(&_8, SL("current"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_LONG(&_9, next);
	zephir_array_update_string(&_8, SL("next"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_LONG(&_9, totalPages);
	zephir_array_update_string(&_8, SL("last"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_8);
	zephir_check_call_status();
	RETURN_MM();

}

