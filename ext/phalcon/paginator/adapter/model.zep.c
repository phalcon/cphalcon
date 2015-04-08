
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
#include "kernel/operators.h"
#include "kernel/fcall.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using a Phalcon\Mvc\Model resultset as base
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_Model) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, Model, phalcon, paginator_adapter_model, phalcon_paginator_adapter_model_method_entry, 0);

	/**
	 * Number of rows to show in the paginator. By default is null
	 */
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Configuration of paginator by model
	 */
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Current page in paginate
	 */
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_model_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\Model constructor
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct) {

	zval *config_param = NULL, *page, *limit;
	zval *config = NULL;

	zephir_fetch_params(0, 1, 0, &config_param);

	config = config_param;



	zephir_update_property_this(this_ptr, SL("_config"), config TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&limit, config, SS("limit"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&page, config, SS("page"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	}

}

/**
 * Set the current page number
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setCurrentPage) {

	zval *page_param = NULL, *_0;
	int page;

	zephir_fetch_params(0, 1, 0, &page_param);

	page = zephir_get_intval(page_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, page);
	zephir_update_property_this(this_ptr, SL("_page"), _0 TSRMLS_CC);

}

/**
 * Set current rows limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setLimit) {

	zval *limitRows_param = NULL, *_0;
	int limitRows;

	zephir_fetch_params(0, 1, 0, &limitRows_param);

	limitRows = zephir_get_intval(limitRows_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limitRows);
	zephir_update_property_this(this_ptr, SL("_limitRows"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get current rows limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getLimit) {


	RETURN_MEMBER(this_ptr, "_limitRows");

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate) {

	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	int pageNumber, show, n, start, lastPage, totalPages, lastShowPage, i, maximumPages, next, pagesTotal, before, ZEPHIR_LAST_CALL_STATUS;
	zval *config, *items, *pageItems, *page, *valid = NULL, *_0, *_1, *_2, _3, *_4 = NULL, *_6 = NULL, *_8;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(_0);
	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(items);
	zephir_array_fetch_string(&items, config, SL("data"), PH_NOISY, "phalcon/paginator/adapter/model.zep", 102 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(_1);
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	if (show <= 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "The start page number is zero or less", "phalcon/paginator/adapter/model.zep", 110);
		return;
	}
	n = zephir_fast_count_int(items TSRMLS_CC);
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	lastShowPage = (pageNumber - 1);
	start = (show * lastShowPage);
	lastPage = (n - 1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_DOUBLE(&_3, zephir_safe_div_long_long(lastPage, show TSRMLS_CC));
	zephir_ceil(_2, &_3 TSRMLS_CC);
	totalPages = zephir_get_intval(_2);
	if (Z_TYPE_P(items) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/paginator/adapter/model.zep", 121);
		return;
	}
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	ZEPHIR_INIT_VAR(pageItems);
	array_init(pageItems);
	if (n > 0) {
		if (start <= n) {
			ZEPHIR_INIT_VAR(_4);
			ZVAL_LONG(_4, start);
			ZEPHIR_CALL_METHOD(NULL, items, "seek", NULL, _4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_LONG(_4, 1);
			ZEPHIR_CALL_METHOD(NULL, items, "seek", NULL, _4);
			zephir_check_call_status();
			pageNumber = 1;
		}
		i = 1;
		while (1) {
			ZEPHIR_CALL_METHOD(&valid, items, "valid", &_5);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(valid)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_6, items, "current", &_7);
			zephir_check_call_status();
			zephir_array_append(&pageItems, _6, PH_SEPARATE, "phalcon/paginator/adapter/model.zep", 153);
			if (i >= show) {
				break;
			}
			i++;
		}
	}
	zephir_update_property_zval(page, SL("items"), pageItems TSRMLS_CC);
	maximumPages = (start + show);
	if (maximumPages < n) {
		next = (pageNumber + 1);
	} else {
		if (maximumPages == n) {
			next = n;
		} else {
			next = (int) ((zephir_safe_div_long_long(n, show TSRMLS_CC) + (double) (1)));
		}
	}
	if (next > totalPages) {
		next = totalPages;
	}
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, next);
	zephir_update_property_zval(page, SL("next"), _8 TSRMLS_CC);
	if (pageNumber > 1) {
		before = (pageNumber - 1);
	} else {
		before = 1;
	}
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, 1);
	zephir_update_property_zval(page, SL("first"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, before);
	zephir_update_property_zval(page, SL("before"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, pageNumber);
	zephir_update_property_zval(page, SL("current"), _8 TSRMLS_CC);
	if (zephir_safe_mod_long_long(n, show TSRMLS_CC) != 0) {
		pagesTotal = (int) ((zephir_safe_div_long_long(n, show TSRMLS_CC) + (double) (1)));
	} else {
		pagesTotal = (int) (zephir_safe_div_long_long(n, show TSRMLS_CC));
	}
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, pagesTotal);
	zephir_update_property_zval(page, SL("last"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, pagesTotal);
	zephir_update_property_zval(page, SL("total_pages"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, n);
	zephir_update_property_zval(page, SL("total_items"), _8 TSRMLS_CC);
	RETURN_CCTOR(page);

}

