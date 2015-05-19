
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


/**
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *<code>
 *
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $collection = new Collection();
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
 * @param string name
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, _addMap) {

	zval *_0;
	zval *method_param = NULL, *routePattern, *handler, *name;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &method_param, &routePattern, &handler, &name);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, method);
	zephir_array_fast_append(_0, routePattern);
	zephir_array_fast_append(_0, handler);
	zephir_array_fast_append(_0, name);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a prefix for all routes added to the collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix) {

	zval *prefix_param = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the collection prefix if any
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
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy) {

	zval *lazy_param = NULL;
	zend_bool lazy;

	zephir_fetch_params(0, 1, 0, &lazy_param);

	if (unlikely(Z_TYPE_P(lazy_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'lazy' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}

	lazy = Z_BVAL_P(lazy_param);


	zephir_update_property_this(this_ptr, SL("_lazy"), lazy ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns if the main handler must be lazy loaded
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
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *name = NULL, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}
	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_NULL(_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, _0, routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *name = NULL, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}
	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "GET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, _0, routePattern, handler, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *name = NULL, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}
	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "POST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, _0, routePattern, handler, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *name = NULL, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}
	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PUT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, _0, routePattern, handler, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *name = NULL, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}
	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "PATCH", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, _0, routePattern, handler, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *name = NULL, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}
	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "HEAD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, _0, routePattern, handler, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param  string   routePattern
 * @param  callable handler
 * @param  string name
 * @return Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *name = NULL, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}
	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DELETE", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, _0, routePattern, handler, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, *name = NULL, *_0;
	zval *routePattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (unlikely(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(routePattern);
		ZVAL_EMPTY_STRING(routePattern);
	}
	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "OPTIONS", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, _0, routePattern, handler, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

