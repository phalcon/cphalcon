
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

#include "paginator/adapter/model.h"
#include "paginator/adapterinterface.h"
#include "paginator/exception.h"

#include <math.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Paginator\Adapter\Model
 *
 * This adapter allows to paginate data using a Phalcon\Mvc\Model resultset as base
 */
zend_class_entry *phalcon_paginator_adapter_model_ce;

PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_model___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_paginator_adapter_model_method_entry[] = {
	PHP_ME(Phalcon_Paginator_Adapter_Model, __construct, arginfo_phalcon_paginator_adapter_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_Model, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_Model, getPaginate, arginfo_phalcon_paginator_adapterinterface_getpaginate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Paginator\Adapter\Model initializer
 */
PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_Model){

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, Model, paginator_adapter_model, phalcon_paginator_adapter_model_method_entry, 0);

	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_model_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_model_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\Model constructor
 *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct){

	zval *config, *limit, *page;

	phalcon_fetch_params(0, 1, 0, &config);
	
	phalcon_update_property_this(this_ptr, SL("_config"), config TSRMLS_CC);
	if (phalcon_array_isset_string_fetch(&limit, config, SS("limit"))) {
		phalcon_update_property_this(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string_fetch(&page, config, SS("page"))) {
		phalcon_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	}
}

/**
 * Set the current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setCurrentPage){

	zval *page;

	phalcon_fetch_params(0, 1, 0, &page);
	
	phalcon_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate){

	zval *z_one, *z_zero, *show, *config, *items, *page_number = NULL;
	zval *rowcount, *page, *last_show_page, *start;
	zval *possible_pages = NULL, *total_pages, *page_items;
	zval *valid = NULL, *current = NULL, *maximum_pages, *next = NULL, *additional_page;
	zval *before = NULL, *remainder, *pages_total = NULL;
	long int i, i_show;

	PHALCON_MM_GROW();

	z_one  = PHALCON_GLOBAL(z_one);
	z_zero = PHALCON_GLOBAL(z_zero);
	
	show        = phalcon_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY TSRMLS_CC);
	config      = phalcon_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(page_number);
	phalcon_read_property_this(&page_number, this_ptr, SL("_page"), PH_NOISY TSRMLS_CC);

	i_show = (Z_TYPE_P(show) == IS_LONG) ? Z_LVAL_P(show) : phalcon_get_intval(show);

	PHALCON_OBS_VAR(items);
	phalcon_array_fetch_string(&items, config, SL("data"), PH_NOISY);
	
	if (Z_TYPE_P(page_number) == IS_NULL || PHALCON_LT(show, z_zero)) {
		PHALCON_CPY_WRT_CTOR(page_number, z_one);
	}
	
	PHALCON_INIT_VAR(rowcount);
	phalcon_fast_count(rowcount, items TSRMLS_CC);

	PHALCON_INIT_VAR(page);
	object_init(page);
	
	PHALCON_INIT_VAR(last_show_page);
	sub_function(last_show_page, page_number, z_one TSRMLS_CC);
	
	PHALCON_INIT_VAR(start);
	mul_function(start, show, last_show_page TSRMLS_CC);
	
	PHALCON_INIT_VAR(possible_pages);
	div_function(possible_pages, rowcount, show TSRMLS_CC);
	if (unlikely(Z_TYPE_P(possible_pages)) != IS_DOUBLE) {
		convert_to_double(possible_pages);
	}
	
	PHALCON_INIT_VAR(total_pages);
	ZVAL_LONG(total_pages, (long int)ceil(Z_DVAL_P(possible_pages)));
	if (Z_TYPE_P(items) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Invalid data for paginator");
		return;
	}
	
	PHALCON_INIT_VAR(page_items);
	array_init(page_items);
	if (PHALCON_GT(rowcount, z_zero)) {
	
		/** 
		 * Seek to the desired position
		 */
		if (PHALCON_LT(start, rowcount)) {
			PHALCON_CALL_METHOD(NULL, items, "seek", start);
		} else {
			PHALCON_CALL_METHOD(NULL, items, "rewind");
			PHALCON_CPY_WRT_CTOR(page_number, z_one);
			PHALCON_CPY_WRT_CTOR(start, z_zero);
		}
	
		/** 
		 * The record must be iterable
		 */
		for (i=1; ; ++i) {
			PHALCON_CALL_METHOD(&valid, items, "valid");
			if (!PHALCON_IS_NOT_FALSE(valid)) {
				break;
			}
	
			PHALCON_CALL_METHOD(&current, items, "current");
			phalcon_array_append(&page_items, current, 0);

			if (i >= i_show) {
				break;
			}
		}
	}
	
	phalcon_update_property_zval(page, SL("items"), page_items TSRMLS_CC);
	
	PHALCON_INIT_VAR(maximum_pages);
	phalcon_add_function(maximum_pages, start, show TSRMLS_CC);
	if (PHALCON_LT(maximum_pages, rowcount)) {
		PHALCON_INIT_VAR(next);
		phalcon_add_function(next, page_number, z_one TSRMLS_CC);
	} else if (PHALCON_IS_EQUAL(maximum_pages, rowcount)) {
			PHALCON_CPY_WRT(next, rowcount);
	} else {
		div_function(possible_pages, rowcount, show TSRMLS_CC);

		PHALCON_INIT_VAR(additional_page);
		phalcon_add_function(additional_page, possible_pages, z_one TSRMLS_CC);

		PHALCON_INIT_NVAR(next);
		ZVAL_LONG(next, phalcon_get_intval(additional_page));
	}
	
	if (PHALCON_GT(next, total_pages)) {
		PHALCON_CPY_WRT(next, total_pages);
	}
	
	phalcon_update_property_zval(page, SL("next"), next TSRMLS_CC);
	if (PHALCON_GT(page_number, z_one)) {
		PHALCON_INIT_VAR(before);
		sub_function(before, page_number, z_one TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT_CTOR(before, z_one);
	}
	
	phalcon_update_property_zval(page, SL("first"), z_one TSRMLS_CC);
	phalcon_update_property_zval(page, SL("before"), before TSRMLS_CC);
	phalcon_update_property_zval(page, SL("current"), page_number TSRMLS_CC);
	
	PHALCON_INIT_VAR(remainder);
	mod_function(remainder, rowcount, show TSRMLS_CC);
	
	PHALCON_INIT_NVAR(possible_pages);
	div_function(possible_pages, rowcount, show TSRMLS_CC);
	if (!PHALCON_IS_LONG(remainder, 0)) {
		PHALCON_INIT_NVAR(next);
		phalcon_add_function(next, possible_pages, z_one TSRMLS_CC);
	
		PHALCON_INIT_VAR(pages_total);
		ZVAL_LONG(pages_total, phalcon_get_intval(next));
	} else {
		PHALCON_CPY_WRT(pages_total, possible_pages);
	}
	
	phalcon_update_property_zval(page, SL("last"), pages_total TSRMLS_CC);
	phalcon_update_property_zval(page, SL("total_pages"), pages_total TSRMLS_CC);
	phalcon_update_property_zval(page, SL("total_items"), rowcount TSRMLS_CC);
	
	RETURN_CTOR(page);
}
