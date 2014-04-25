
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
 *
 * @param array config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct) {

	zval *config, *page, *limit;

	zephir_fetch_params(0, 1, 0, &config);



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
 *
 * @param int page
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
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int pageNumber, show, n, start, lastPage, totalPages, lastShowPage, i, maximumPages, next, pagesTotal, before, ZEPHIR_LAST_CALL_STATUS;
	zval *config, *items, *pageItems, *page, *valid = NULL, *_0, *_1, _2, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(_0);
	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(items);
	zephir_array_fetch_string(&items, config, SL("data"), PH_NOISY TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(_1);
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	if (show <= 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "The start page number is zero or less", "phalcon/paginator/adapter/model.zep", 95);
		return;
	}
	n = zephir_fast_count_int(items TSRMLS_CC);
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	lastShowPage = (pageNumber - 1);
	start = (show * lastShowPage);
	lastPage = (n - 1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, (lastPage / show));
	ZEPHIR_CALL_FUNCTION(&_3, "ceil", &_4, &_2);
	zephir_check_call_status();
	totalPages = zephir_get_intval(_3);
	if (Z_TYPE_P(items) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/paginator/adapter/model.zep", 106);
		return;
	}
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	ZEPHIR_INIT_VAR(pageItems);
	array_init(pageItems);
	if (n > 0) {
		if (start <= n) {
			ZEPHIR_INIT_VAR(_5);
			ZVAL_LONG(_5, start);
			ZEPHIR_CALL_METHOD(NULL, items, "seek", NULL, _5);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_LONG(_5, 1);
			ZEPHIR_CALL_METHOD(NULL, items, "seek", NULL, _5);
			zephir_check_call_status();
			pageNumber = 1;
		}
		i = 1;
		while (1) {
			ZEPHIR_CALL_METHOD(&valid, items, "valid",  NULL);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE(valid)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_6, items, "current",  NULL);
			zephir_check_call_status();
			zephir_array_append(&pageItems, _6, PH_SEPARATE);
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
			next = (((n / show) + 1));
		}
	}
	if (next > totalPages) {
		next = totalPages;
	}
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, next);
	zephir_update_property_zval(page, SL("next"), _7 TSRMLS_CC);
	if (pageNumber > 1) {
		before = (pageNumber - 1);
	} else {
		before = 1;
	}
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, 1);
	zephir_update_property_zval(page, SL("first"), _7 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, before);
	zephir_update_property_zval(page, SL("before"), _7 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, pageNumber);
	zephir_update_property_zval(page, SL("current"), _7 TSRMLS_CC);
	if ((n % show) != 0) {
		pagesTotal = (((n / show) + 1));
	} else {
		pagesTotal = ((n / show));
	}
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, pagesTotal);
	zephir_update_property_zval(page, SL("last"), _7 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, pagesTotal);
	zephir_update_property_zval(page, SL("total_pages"), _7 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, n);
	zephir_update_property_zval(page, SL("total_items"), _7 TSRMLS_CC);
	RETURN_CCTOR(page);

}

