
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
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
 * Phalcon\Paginator\Adapter\AbstractAdapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_AbstractAdapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, AbstractAdapter, phalcon, paginator_adapter_abstractadapter, phalcon_paginator_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Configuration of paginator
	 */
	zend_declare_property_null(phalcon_paginator_adapter_abstractadapter_ce, SL("config"), ZEND_ACC_PROTECTED);

	/**
	 * Number of rows to show in the paginator. By default is null
	 */
	zend_declare_property_null(phalcon_paginator_adapter_abstractadapter_ce, SL("limitRows"), ZEND_ACC_PROTECTED);

	/**
	 * Current page in paginate
	 */
	zend_declare_property_null(phalcon_paginator_adapter_abstractadapter_ce, SL("page"), ZEND_ACC_PROTECTED);

	/**
	 * Repository for pagination
	 *
	 * @var RepositoryInterface
	 */
	zend_declare_property_null(phalcon_paginator_adapter_abstractadapter_ce, SL("repository"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_paginator_adapter_abstractadapter_ce, 1, phalcon_paginator_adapter_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\AbstractAdapter constructor
 */
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, _0$$3, _1$$4, _2$$5;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	ZEPHIR_OBS_COPY_OR_DUP(&config, config_param);


	zephir_update_property_zval(this_ptr, SL("config"), &config);
	if (zephir_array_isset_string(&config, SL("limit"))) {
		zephir_array_fetch_string(&_0$$3, &config, SL("limit"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Paginator/Adapter/AbstractAdapter.zep", 54);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlimit", NULL, 0, &_0$$3);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&config, SL("page"))) {
		zephir_array_fetch_string(&_1$$4, &config, SL("page"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Paginator/Adapter/AbstractAdapter.zep", 60);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcurrentpage", NULL, 0, &_1$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&config, SL("repository"))) {
		zephir_array_fetch_string(&_2$$5, &config, SL("repository"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Paginator/Adapter/AbstractAdapter.zep", 66);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrepository", NULL, 0, &_2$$5);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get current rows limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, getLimit) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "limitRows");

}

/**
 * Set the current page number
 */
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, setCurrentPage) {

	zval *page_param = NULL, _0;
	zend_long page;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &page_param);

	page = zephir_get_intval(page_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, page);
	zephir_update_property_zval(this_ptr, SL("page"), &_0);
	RETURN_THISW();

}

/**
 * Set current rows limit
 */
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, setLimit) {

	zval *limitRows_param = NULL, _0;
	zend_long limitRows;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &limitRows_param);

	limitRows = zephir_get_intval(limitRows_param);


	if (limitRows <= 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_paginator_exception_ce, "Limit must be greater then zero", "/home/nikos/Work/niden/cphalcon/phalcon/Paginator/Adapter/AbstractAdapter.zep", 94);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, limitRows);
	zephir_update_property_zval(this_ptr, SL("limitRows"), &_0);
	RETURN_THISW();

}

/**
 * Sets current repository for pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, setRepository) {

	zval *repository, repository_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&repository_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &repository);



	zephir_update_property_zval(this_ptr, SL("repository"), repository);
	RETURN_THISW();

}

/**
 * Gets current repository for pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_AbstractAdapter, getRepository) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *properties_param = NULL, _0, _1$$3, _2$$4;
	zval properties;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &properties_param);

	if (!properties_param) {
		ZEPHIR_INIT_VAR(&properties);
		array_init(&properties);
	} else {
		zephir_get_arrval(&properties, properties_param);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("repository"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_paginator_repository_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("repository"), &_1$$3);
	}
	if (!ZEPHIR_IS_STRING_IDENTICAL(&properties, "")) {
		zephir_read_property(&_2$$4, this_ptr, SL("repository"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "setproperties", NULL, 0, &properties);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "repository");

}

