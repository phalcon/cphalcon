
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

#include "paginator/adapter/nativearray.h"
#include "paginator/adapterinterface.h"
#include "paginator/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Paginator\Adapter\NativeArray
 *
 * Pagination using a PHP array as source of data
 *
 *<code>
 *	$paginator = new \Phalcon\Paginator\Adapter\Model(
 *		array(
 *			"data"  => array(
 *				array('id' => 1, 'name' => 'Artichoke'),
 *				array('id' => 2, 'name' => 'Carrots'),
 *				array('id' => 3, 'name' => 'Beet'),
 *				array('id' => 4, 'name' => 'Lettuce'),
 *				array('id' => 5, 'name' => '')
 *			),
 *			"limit" => 2,
 *			"page"  => $currentPage
 *		)
 *	);
 *</code>
 *
 */
zend_class_entry *phalcon_paginator_adapter_nativearray_ce;

PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_nativearray___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_paginator_adapter_nativearray_method_entry[] = {
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, __construct, arginfo_phalcon_paginator_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, getPaginate, arginfo_phalcon_paginator_adapterinterface_getpaginate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Paginator\Adapter\NativeArray initializer
 */
PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray){

	PHALCON_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, NativeArray, paginator_adapter_nativearray, phalcon_paginator_adapter_nativearray_method_entry, 0);

	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_nativearray_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\NativeArray constructor
 *
 * @param array $config
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct){

	zval *config, *limit, *page, *data;

	phalcon_fetch_params(0, 1, 0, &config);
	
	if (phalcon_array_isset_string_fetch(&limit, config, SS("limit"))) {
		phalcon_update_property_this(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string_fetch(&page, config, SS("page"))) {
		phalcon_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	}

	if (!phalcon_array_isset_string_fetch(&data, config, SS("data"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "Parameter 'data' is required");
		return;
	}

	if (Z_TYPE_P(data) != IS_ARRAY) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "'data' should be an array");
		return;
	}

	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
}

/**
 * Set the current page number
 *
 * @param int $page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, setCurrentPage){

	zval **current_page;

	phalcon_fetch_params_ex(1, 0, &current_page);
	PHALCON_ENSURE_IS_LONG(current_page);
	
	phalcon_update_property_this(this_ptr, SL("_page"), *current_page TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate){

	zval *items, *limit, *number_page, *lim;
	zval *start, *slice = NULL;
	zval *params[3];
	long int i_limit, i_number_page, i_number, i_before, i_rowcount;
	long int i_total_pages, i_next;
	ldiv_t tp;

	items = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY TSRMLS_CC);
	if (UNEXPECTED(Z_TYPE_P(items) != IS_ARRAY)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_paginator_exception_ce, "Invalid data for paginator");
		return;
	}

	limit         = phalcon_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY TSRMLS_CC);
	number_page   = phalcon_fetch_nproperty_this(this_ptr, SL("_page"), PH_NOISY TSRMLS_CC);
	i_limit       = phalcon_get_intval(limit);
	i_number_page = phalcon_get_intval(number_page);

	if (i_limit < 1) {
		/* This should never happen unless someone deliberately modified the properties of the object */
		i_limit = 10;
	}

	if (!i_number_page) {
		i_number_page = 1;
	}

	i_number      = (i_number_page - 1) * i_limit;
	i_before      = (i_number_page == 1) ? 1 : (i_number_page - 1);
	i_rowcount    = zend_hash_num_elements(Z_ARRVAL_P(items));
	tp            = ldiv(i_rowcount, i_limit);
	i_total_pages = tp.quot + (tp.rem ? 1 : 0);
	i_next        = (i_number_page < i_total_pages) ? (i_number_page + 1) : i_total_pages;

	PHALCON_ALLOC_GHOST_ZVAL(start);
	PHALCON_ALLOC_GHOST_ZVAL(lim);
	ZVAL_LONG(start, i_number);
	ZVAL_LONG(lim, i_limit);

	params[0] = items;
	params[1] = start;
	params[2] = lim;
	RETURN_ON_FAILURE(phalcon_call_func_aparams(&slice, SL("array_slice"), 3, params TSRMLS_CC));

	Z_DELREF_P(slice);
	
	object_init(return_value);
	phalcon_update_property_zval(return_value, SL("items"),       slice TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("before"),      i_before TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("first"),       1 TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("next"),        i_next TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("last"),        i_total_pages TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("current"),     i_number_page TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("total_pages"), i_total_pages TSRMLS_CC);
	phalcon_update_property_long(return_value, SL("total_items"), i_rowcount TSRMLS_CC);
}
