
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


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

	/**
	 * Configuration of paginator by model
	 */
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\Model constructor
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct) {

	zval *config_param = NULL, *page = NULL, *limit = NULL;
	zval *config = NULL;

	zephir_fetch_params(0, 1, 0, &config_param);

	config = config_param;


	zephir_update_property_this(getThis(), SL("_config"), config TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&limit, config, SS("limit"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_limitRows"), limit TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&page, config, SS("page"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_page"), page TSRMLS_CC);
	}

}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @deprecated will be removed after 4.0
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "paginate", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, paginate) {

	zval *config = NULL, *items = NULL, *pageItems = NULL, *page = NULL, *_0, *_1, *_8, *_2$$9, *_3$$10, *_4$$8 = NULL, *_5$$11 = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pageNumber = 0, show = 0, n = 0, start = 0, lastShowPage = 0, i = 0, next = 0, totalPages = 0, previous = 0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(_0);
	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(items);
	zephir_array_fetch_string(&items, config, SL("data"), PH_NOISY, "phalcon/paginator/adapter/model.zep", 92 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(_1);
	if (Z_TYPE_P(items) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/paginator/adapter/model.zep", 96);
		return;
	}
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	if (show <= 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "The start page number is zero or less", "phalcon/paginator/adapter/model.zep", 106);
		return;
	}
	n = zephir_fast_count_int(items TSRMLS_CC);
	lastShowPage = (pageNumber - 1);
	start = (show * lastShowPage);
	ZEPHIR_INIT_VAR(pageItems);
	array_init(pageItems);
	if (zephir_safe_mod_long_long(n, show TSRMLS_CC) != 0) {
		totalPages = (int) ((zephir_safe_div_long_long(n, show TSRMLS_CC) + (double) (1)));
	} else {
		totalPages = (int) (zephir_safe_div_long_long(n, show TSRMLS_CC));
	}
	if (n > 0) {
		if (start <= n) {
			ZEPHIR_INIT_VAR(_2$$9);
			ZVAL_LONG(_2$$9, start);
			ZEPHIR_CALL_METHOD(NULL, items, "seek", NULL, 0, _2$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_3$$10);
			ZVAL_LONG(_3$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, items, "seek", NULL, 0, _3$$10);
			zephir_check_call_status();
			pageNumber = 1;
		}
		i = 1;
		while (1) {
			ZEPHIR_CALL_METHOD(&_4$$8, items, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_4$$8))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_5$$11, items, "current", &_6, 0);
			zephir_check_call_status();
			zephir_array_append(&pageItems, _5$$11, PH_SEPARATE, "phalcon/paginator/adapter/model.zep", 133);
			if (i >= show) {
				break;
			}
			i++;
			ZEPHIR_CALL_METHOD(NULL, items, "next", &_7, 0);
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
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	zephir_update_property_zval(page, SL("items"), pageItems TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, 1);
	zephir_update_property_zval(page, SL("first"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, previous);
	zephir_update_property_zval(page, SL("before"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, previous);
	zephir_update_property_zval(page, SL("previous"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, pageNumber);
	zephir_update_property_zval(page, SL("current"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, totalPages);
	zephir_update_property_zval(page, SL("last"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, next);
	zephir_update_property_zval(page, SL("next"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, totalPages);
	zephir_update_property_zval(page, SL("total_pages"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, n);
	zephir_update_property_zval(page, SL("total_items"), _8 TSRMLS_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY_CC);
	zephir_update_property_zval(page, SL("limit"), _8 TSRMLS_CC);
	RETURN_CCTOR(page);

}

