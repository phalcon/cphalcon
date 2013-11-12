
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *<code>
 *
 * $app = new Phalcon\Mvc\Micro();
 *
 * $collection = new Phalcon\Mvc\Micro\Collection();
 *
 * $collection->setHandler(new PostsController());
 *
 * $collection->get('/posts/edit/{id}', 'edit');
 *
 * $app->mount($collection);
 *
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Micro, Collection, phalcon, mvc_micro_collection, phalcon_mvc_micro_collection_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_lazy"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("_handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_micro_collection_ce TSRMLS_CC, 1, phalcon_mvc_micro_collectioninterface_ce);

	return SUCCESS;

}

/**
 * Internal function to add a handler to the group
 *
 * @param string|array method
 * @param string routePattern
 * @param mixed handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, _addMap) {

	zval *method_param = NULL, *routePattern, *handler, *_0;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &method_param, &routePattern, &handler);

		if (Z_TYPE_P(method_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		method = method_param;



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_fast_append(_0, method);
	zephir_array_fast_append(_0, routePattern);
	zephir_array_fast_append(_0, handler);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a prefix for all routes added to the collection
 *
 * @param string prefix
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix) {

	zval *prefix_param = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

		if (Z_TYPE_P(prefix_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		prefix = prefix_param;



	zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the collection prefix if any
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix) {


	RETURN_MEMBER(this_ptr, "_prefix");

}

/**
 * Returns the registered handlers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers) {


	RETURN_MEMBER(this_ptr, "_handlers");

}

/**
 * Sets the main handler
 *
 * @param mixed handler
 * @param boolean lazy
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler) {

	zend_bool lazy;
	zval *handler, *lazy_param = NULL;

	zephir_fetch_params(0, 1, 1, &handler, &lazy_param);

	if (!lazy_param) {
		lazy = 0;
	} else {
		lazy = zephir_get_boolval(lazy_param);
	}


	zephir_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_lazy"), lazy ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets if the main handler must be lazy loaded
 *
 * @param boolean lazy
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy) {

	zval *lazy;

	zephir_fetch_params(0, 1, 0, &lazy);



	zephir_update_property_this(this_ptr, SL("_lazy"), lazy TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns if the main handler must be lazy loaded
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy) {


	RETURN_MEMBER(this_ptr, "_lazy");

}

/**
 * Returns the main handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler) {


	RETURN_MEMBER(this_ptr, "_handler");

}

/**
 * Maps a route to a handler
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map) {

	zval *routePattern_param = NULL, *handler;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	zephir_call_method_p3(return_value, this_ptr, "_addmap", ZEPHIR_GLOBAL(global_null), routePattern, handler);
	RETURN_MM();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get) {

	zval *routePattern_param = NULL, *handler, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "GET", 1);
	zephir_call_method_p3_noret(this_ptr, "_addmap", _0, routePattern, handler);
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post) {

	zval *routePattern_param = NULL, *handler, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "POST", 1);
	zephir_call_method_p3_noret(this_ptr, "_addmap", _0, routePattern, handler);
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put) {

	zval *routePattern_param = NULL, *handler, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PUT", 1);
	zephir_call_method_p3_noret(this_ptr, "_addmap", _0, routePattern, handler);
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch) {

	zval *routePattern_param = NULL, *handler, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PATCH", 1);
	zephir_call_method_p3_noret(this_ptr, "_addmap", _0, routePattern, handler);
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param  string routePattern
 * @param  callable handler
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head) {

	zval *routePattern_param = NULL, *handler, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HEAD", 1);
	zephir_call_method_p3_noret(this_ptr, "_addmap", _0, routePattern, handler);
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param string   routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete) {

	zval *routePattern_param = NULL, *handler, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DELETE", 1);
	zephir_call_method_p3_noret(this_ptr, "_addmap", _0, routePattern, handler);
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string routePattern
 * @param callable handler
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options) {

	zval *routePattern_param = NULL, *handler, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

		if (Z_TYPE_P(routePattern_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		routePattern = routePattern_param;



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "OPTIONS", 1);
	zephir_call_method_p3_noret(this_ptr, "_addmap", _0, routePattern, handler);
	RETURN_THIS();

}

