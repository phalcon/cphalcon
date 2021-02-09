
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Micro\Collection
 *
 * Groups Micro-Mvc handlers as controllers
 *
 *```php
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
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Micro, Collection, phalcon, mvc_micro_collection, phalcon_mvc_micro_collection_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("handler"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("handlers"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("lazy"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("prefix"), ZEND_ACC_PROTECTED);

	phalcon_mvc_micro_collection_ce->create_object = zephir_init_properties_Phalcon_Mvc_Micro_Collection;

	zend_class_implements(phalcon_mvc_micro_collection_ce, 1, phalcon_mvc_micro_collectioninterface_ce);
	return SUCCESS;

}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL, _0;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL, _0;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns the main handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

/**
 * Returns the registered handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handlers");

}

/**
 * Returns the collection prefix if any
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "prefix");

}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL, _0;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns if the main handler must be lazy loaded
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "lazy");

}

/**
 * Maps a route to a handler.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL, _0;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler via methods.
 *
 * ```php
 * $collection->mapVia(
 *     "/test",
 *     "indexAction",
 *     ["POST", "GET"],
 *     "test"
 * );
 * ```
 *
 * @param callable handler
 * @param string|array method
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, mapVia) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *method, method_sub, *name_param = NULL;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&method_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &routePattern_param, &handler, &method, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, method, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is
 * OPTIONS.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL, _0;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL, _0;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL, _0;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL, _0;
	zval routePattern, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern, handler, &name);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the main handler.
 *
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler) {

	zend_bool lazy;
	zval *handler, handler_sub, *lazy_param = NULL, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 1, &handler, &lazy_param);

	if (!lazy_param) {
		lazy = 0;
	} else {
		lazy = zephir_get_boolval(lazy_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	if (lazy) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("lazy"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("lazy"), &__$false);
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

	zephir_fetch_params_without_memory_grow(1, 0, &lazy_param);

	if (UNEXPECTED(Z_TYPE_P(lazy_param) != IS_TRUE && Z_TYPE_P(lazy_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'lazy' must be of the type bool"));
		RETURN_NULL();
	}
	lazy = (Z_TYPE_P(lazy_param) == IS_TRUE);


	if (lazy) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("lazy"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("lazy"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets a prefix for all routes added to the collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prefix_param = NULL;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Internal function to add a handler to the group.
 *
 * @param string|array    method
 * @param callable|string handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, addMap) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval routePattern, name;
	zval *method, method_sub, *routePattern_param = NULL, *handler, handler_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &method, &routePattern_param, &handler, &name_param);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}
	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, method);
	zephir_array_fast_append(&_0, &routePattern);
	zephir_array_fast_append(&_0, handler);
	zephir_array_fast_append(&_0, &name);
	zephir_update_property_array_append(this_ptr, SL("handlers"), &_0);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Micro_Collection(zend_class_entry *class_type) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("handlers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

