
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
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
 *
 * @phpstan-import-type mvc_micro_handlers from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_Collection)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Micro, Collection, phalcon, mvc_micro_collection, phalcon_mvc_micro_collection_method_entry, 0);

	/**
	 * @var callable
	 */
	zend_declare_property_null(phalcon_mvc_micro_collection_ce, SL("handler"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var mvc_micro_handlers
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_micro_collection_ce, SL("handlers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_micro_collection_ce, SL("isLazy"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_micro_collection_ce, SL("prefix"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	zend_class_implements(phalcon_mvc_micro_collection_ce, 1, phalcon_mvc_micro_collectioninterface_ce);
	return SUCCESS;
}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE.
 *
 * @param mixed $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, name_zv, _0;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern_zv, handler, &name_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET.
 *
 *
 * @param mixed $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, name_zv, _0;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern_zv, handler, &name_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Returns the main handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler)
{

	RETURN_MEMBER(getThis(), "handler");
}

/**
 * Returns the registered handlers
 *
 * @phpstan-return mvc_micro_handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers)
{

	RETURN_MEMBER_TYPED(getThis(), "handlers", IS_ARRAY);
}

/**
 * Returns the collection prefix if any
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix)
{

	RETURN_MEMBER_TYPED(getThis(), "prefix", IS_STRING);
}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD.
 *
 * @param mixed $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, head)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, name_zv, _0;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HEAD");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern_zv, handler, &name_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Returns if the main handler must be lazy loaded
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy)
{

	RETURN_MEMBER(getThis(), "isLazy");
}

/**
 * Maps a route to a handler.
 *
 * @param mixed $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, map)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, name_zv, _0;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern_zv, handler, &name_zv);
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
 * @param callable     $handler
 * @param string|array $method
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, mapVia)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, *method, method_sub, name_zv;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&name_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_ZVAL(method)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	method = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, method, &routePattern_zv, handler, &name_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is
 * OPTIONS.
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, options)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, name_zv, _0;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern_zv, handler, &name_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH.
 *
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, name_zv, _0;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern_zv, handler, &name_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST.
 *
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, post)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, name_zv, _0;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern_zv, handler, &name_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT.
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, put)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval routePattern_zv, *handler, handler_sub, name_zv, _0;
	zend_string *routePattern = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addmap", NULL, 0, &_0, &routePattern_zv, handler, &name_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets the main handler.
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler)
{
	zend_bool isLazy;
	zval *handler, handler_sub, *isLazy_param = NULL, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("handler", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("isLazy", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isLazy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 1, &handler, &isLazy_param);
	if (!isLazy_param) {
		isLazy = 0;
	} else {
		}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 990, handler);
	if (isLazy) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 991, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 991, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets if the main handler must be lazy loaded
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy)
{
	zval *isLazy_param = NULL, __$true, __$false;
	zend_bool isLazy;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isLazy", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(isLazy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &isLazy_param);
	if (isLazy) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 991, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 991, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets a prefix for all routes added to the collection
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix)
{
	zval prefix_zv;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&prefix_zv, prefix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 992, &prefix_zv);
	RETURN_THISW();
}

/**
 * Internal function to add a handler to the group.
 *
 * @param string|array $method
 * @param callable     $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro_Collection, addMap)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *routePattern = NULL, *name = NULL;
	zval *method, method_sub, routePattern_zv, *handler, handler_sub, name_zv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&routePattern_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(method)
		Z_PARAM_STR(routePattern)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	method = ZEND_CALL_ARG(execute_data, 1);
	handler = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&routePattern_zv);
	ZVAL_STR_COPY(&routePattern_zv, routePattern);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_fast_append(&_0, method);
	zephir_array_fast_append(&_0, &routePattern_zv);
	zephir_array_fast_append(&_0, handler);
	zephir_array_fast_append(&_0, &name_zv);
	zephir_update_property_array_append(this_ptr, SL("handlers"), &_0);
	ZEPHIR_MM_RESTORE();
}

