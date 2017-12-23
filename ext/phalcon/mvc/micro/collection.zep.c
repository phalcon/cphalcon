
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
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $collection = new Collection();
 *
 * $collection->setHandler(
 *     new PostsController()
 * );
 *
 * $collection->get("/posts/edit/{id}", "edit");
 *
 * $app->mount($collection);
 *</code>
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

	zval _0;
	zval *method, method_sub, *routePattern, routePattern_sub, *handler, handler_sub, *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&routePattern_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &method, &routePattern, &handler, &name);



	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, method);
	zephir_array_fast_append(&_0, routePattern);
	zephir_array_fast_append(&_0, handler);
	zephir_array_fast_append(&_0, name);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a prefix for all routes added to the collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix) {

	zval *prefix_param = NULL;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}


	zephir_update_property_zval(this_ptr, SL("_prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Returns the collection prefix if any
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_prefix");

}

/**
 * Returns the registered handlers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_handlers");

}

/**
 * Sets the main handler
 *
 * @param mixed handler
 * @param boolean lazy
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler) {

	zend_bool lazy;
	zval *handler, handler_sub, *lazy_param = NULL, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 1, &handler, &lazy_param);

	if (!lazy_param) {
		lazy = 0;
	} else {
		lazy = zephir_get_boolval(lazy_param);
	}


	zephir_update_property_zval(this_ptr, SL("_handler"), handler);
	if (lazy) {
		zephir_update_property_zval(this_ptr, SL("_lazy"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_lazy"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if the main handler must be lazy loaded
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy) {

	zval *lazy_param = NULL, __$true, __$false;
	zend_bool lazy;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &lazy_param);

	if (UNEXPECTED(Z_TYPE_P(lazy_param) != IS_TRUE && Z_TYPE_P(lazy_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'lazy' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	lazy = (Z_TYPE_P(lazy_param) == IS_TRUE);


	if (lazy) {
		zephir_update_property_zval(this_ptr, SL("_lazy"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_lazy"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Returns if the main handler must be lazy loaded
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_lazy");

}

/**
 * Returns the main handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_handler");

}

/**
 * Maps a route to a handler
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name = NULL, name_sub, __$null, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, &_0, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler via methods
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string|array method
 * @param  string name
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, mapVia) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *method, method_sub, *name = NULL, name_sub, __$null;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &routePattern_param, &handler, &method, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, method, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name = NULL, name_sub, __$null, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, &_0, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name = NULL, name_sub, __$null, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, &_0, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name = NULL, name_sub, __$null, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, &_0, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name = NULL, name_sub, __$null, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, &_0, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param  string routePattern
 * @param  callable handler
 * @param  string name
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name = NULL, name_sub, __$null, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, &_0, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param  string   routePattern
 * @param  callable handler
 * @param  string name
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name = NULL, name_sub, __$null, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, &_0, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param string routePattern
 * @param callable handler
 * @return \Phalcon\Mvc\Micro\Collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name = NULL, name_sub, __$null, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addmap", NULL, 0, &_0, &routePattern, handler, name);
	zephir_check_call_status();
	RETURN_THIS();

}

