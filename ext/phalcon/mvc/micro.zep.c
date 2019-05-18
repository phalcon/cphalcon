
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Micro
 *
 * With Phalcon you can create "Micro-Framework like" applications. By doing
 * this, you only need to write a minimal amount of code to create a PHP
 * application. Micro applications are suitable to small applications, APIs and
 * prototypes in a practical way.
 *
 *<code>
 * $app = new \Phalcon\Mvc\Micro();
 *
 * $app->get(
 *     "/say/welcome/{name}",
 *     function ($name) {
 *         echo "<h1>Welcome $name!</h1>";
 *     }
 * );
 *
 * $app->handle("/say/welcome/Phalcon");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Micro, phalcon, mvc_micro, phalcon_di_injectable_ce, phalcon_mvc_micro_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("activeHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("afterBindingHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("afterHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("beforeHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("errorHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("finishHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("handlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("modelBinder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("notFoundHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("responseHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("returnedValue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_micro_ce, SL("stopped"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_micro_ce->create_object = zephir_init_properties_Phalcon_Mvc_Micro;

	zend_class_implements(phalcon_mvc_micro_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Micro constructor
 */
PHP_METHOD(Phalcon_Mvc_Micro, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container = NULL, container_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &container);

	if (!container) {
		container = &container_sub;
		container = &__$null;
	}


	if (Z_TYPE_P(container) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, container);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends an 'after' middleware to be called after execute the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, after) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("afterHandlers"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Appends a afterBinding middleware to be called after model binding
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, afterBinding) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("afterBindingHandlers"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Appends a before middleware to be called before execute the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, before) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("beforeHandlers"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is DELETE
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "adddelete", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Sets a handler that will be called when an exception is thrown handling
 * the route
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, error) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("errorHandler"), handler);
	RETURN_THISW();

}

/**
 * Appends a 'finish' middleware to be called when the request is finished
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, finish) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("finishHandlers"), handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is GET
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addget", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Return the handler that will be called for the matched route
 *
 * @return callable
 */
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeHandler");

}

/**
 * Returns bound models from binder instance
 */
PHP_METHOD(Phalcon_Mvc_Micro, getBoundModels) {

	zval modelBinder, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("modelBinder"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&modelBinder, &_0);
	if (Z_TYPE_P(&modelBinder) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(&modelBinder, "getboundmodels", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the internal handlers attached to the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getHandlers) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handlers");

}

/**
 * Gets model binder
 */
PHP_METHOD(Phalcon_Mvc_Micro, getModelBinder) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "modelBinder");

}

/**
 * Returns the value returned by the executed handler
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "returnedValue");

}

/**
 * Returns the internal router used by the application
 */
PHP_METHOD(Phalcon_Mvc_Micro, getRouter) {

	zval router, _0, _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&router, &_0);
	if (Z_TYPE_P(&router) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "router");
		ZEPHIR_CALL_METHOD(&router, this_ptr, "getsharedservice", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &router, "clear", NULL, 0);
		zephir_check_call_status();
		ZVAL_BOOL(&_2$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &router, "removeextraslashes", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("router"), &router);
	}
	RETURN_CCTOR(&router);

}

/**
 * Obtains a service from the DI
 *
 * @return object
 */
PHP_METHOD(Phalcon_Mvc_Micro, getService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, container, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
		ZVAL_EMPTY_STRING(&serviceName);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 407);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "get", NULL, 408, &serviceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Obtains a shared service from the DI
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, container, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
		ZVAL_EMPTY_STRING(&serviceName);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 407);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "getshared", NULL, 409, &serviceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Handle the whole request
 *
 * @param string uri
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro, handle) {

	zval _64$$60;
	zend_class_entry *_25$$20;
	zend_bool _23$$7, _34$$7, _30$$24, _38$$31;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *uri_param = NULL, __$true, __$false, container, eventsManager, status, router, matchedRoute, handler, beforeHandlers, params, returnedValue, e, errorHandler, afterHandlers, notFoundHandler, finishHandlers, finish, before, after, response, modelBinder, routeName, realHandler, methodName, lazyReturned, afterBindingHandlers, afterBinding, _0, _61, _1$$3, _2$$3, _4$$3, _5$$4, _8$$4, _9$$4, _6$$5, _7$$5, _10$$7, _11$$7, _16$$7, _12$$8, _13$$8, _14$$9, _15$$9, *_17$$12, _22$$12, _18$$15, _19$$17, _20$$17, _21$$13, _24$$20, _26$$22, _27$$23, _28$$23, _29$$21, _31$$25, _32$$25, _33$$25, _35$$28, _36$$28, *_37$$30, _43$$30, _42$$31, _39$$32, _40$$34, _41$$34, _44$$37, *_45$$38, _46$$41, _47$$43, _48$$43, _49$$39, _50$$45, _51$$46, _52$$46, _53$$48, _54$$48, _55$$49, *_56$$50, _57$$53, _58$$55, _59$$55, _60$$51, _62$$58, _63$$59, _65$$68, _66$$68, _67$$71, _68$$71, _69$$74;
	zval uri, bindCacheKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&matchedRoute);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&beforeHandlers);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&returnedValue);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&errorHandler);
	ZVAL_UNDEF(&afterHandlers);
	ZVAL_UNDEF(&notFoundHandler);
	ZVAL_UNDEF(&finishHandlers);
	ZVAL_UNDEF(&finish);
	ZVAL_UNDEF(&before);
	ZVAL_UNDEF(&after);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&realHandler);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&lazyReturned);
	ZVAL_UNDEF(&afterBindingHandlers);
	ZVAL_UNDEF(&afterBinding);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_61);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_35$$28);
	ZVAL_UNDEF(&_36$$28);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_42$$31);
	ZVAL_UNDEF(&_39$$32);
	ZVAL_UNDEF(&_40$$34);
	ZVAL_UNDEF(&_41$$34);
	ZVAL_UNDEF(&_44$$37);
	ZVAL_UNDEF(&_46$$41);
	ZVAL_UNDEF(&_47$$43);
	ZVAL_UNDEF(&_48$$43);
	ZVAL_UNDEF(&_49$$39);
	ZVAL_UNDEF(&_50$$45);
	ZVAL_UNDEF(&_51$$46);
	ZVAL_UNDEF(&_52$$46);
	ZVAL_UNDEF(&_53$$48);
	ZVAL_UNDEF(&_54$$48);
	ZVAL_UNDEF(&_55$$49);
	ZVAL_UNDEF(&_57$$53);
	ZVAL_UNDEF(&_58$$55);
	ZVAL_UNDEF(&_59$$55);
	ZVAL_UNDEF(&_60$$51);
	ZVAL_UNDEF(&_62$$58);
	ZVAL_UNDEF(&_63$$59);
	ZVAL_UNDEF(&_65$$68);
	ZVAL_UNDEF(&_66$$68);
	ZVAL_UNDEF(&_67$$71);
	ZVAL_UNDEF(&_68$$71);
	ZVAL_UNDEF(&_69$$74);
	ZVAL_UNDEF(&_64$$60);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_INIT_VAR(&realHandler);
	ZVAL_NULL(&realHandler);
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_micro_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "micro services");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_mvc_micro_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Micro.zep", 352 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&returnedValue);
		ZVAL_NULL(&returnedValue);
		zephir_read_property(&_5$$4, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&eventsManager, &_5$$4);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "micro:beforeHandleRoute");
			ZEPHIR_CALL_METHOD(&_6$$5, &eventsManager, "fire", NULL, 0, &_7$$5, this_ptr);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$5)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "router");
		ZEPHIR_CALL_METHOD(&_8$$4, &container, "getshared", NULL, 0, &_9$$4);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&router, &_8$$4);
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&matchedRoute, &router, "getmatchedroute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&matchedRoute) == IS_OBJECT) {
			ZEPHIR_OBS_VAR(&handler);
			zephir_read_property(&_10$$7, this_ptr, SL("handlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_11$$7, &matchedRoute, "getrouteid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&handler, &_10$$7, &_11$$7, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_VAR(&_12$$8);
				object_init_ex(&_12$$8, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(&_13$$8);
				ZVAL_STRING(&_13$$8, "Matched route doesn't have an associated handler");
				ZEPHIR_CALL_METHOD(NULL, &_12$$8, "__construct", NULL, 1, &_13$$8);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_12$$8, "phalcon/Mvc/Micro.zep", 388 TSRMLS_CC);
				goto try_end_1;

			}
			zephir_update_property_zval(this_ptr, SL("activeHandler"), &handler);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_15$$9);
				ZVAL_STRING(&_15$$9, "micro:beforeExecuteRoute");
				ZEPHIR_CALL_METHOD(&_14$$9, &eventsManager, "fire", NULL, 0, &_15$$9, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$9)) {
					RETURN_MM_BOOL(0);
				} else {
					ZEPHIR_OBS_NVAR(&handler);
					zephir_read_property(&handler, this_ptr, SL("activeHandler"), PH_NOISY_CC);
				}
			}
			zephir_read_property(&_16$$7, this_ptr, SL("beforeHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&beforeHandlers, &_16$$7);
			if (Z_TYPE_P(&beforeHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_zval(this_ptr, SL("stopped"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, SL("stopped"), &__$false);
				}
				zephir_is_iterable(&beforeHandlers, 0, "phalcon/Mvc/Micro.zep", 456);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&beforeHandlers), _17$$12)
				{
					ZEPHIR_INIT_NVAR(&before);
					ZVAL_COPY(&before, _17$$12);
					if (Z_TYPE_P(&before) == IS_OBJECT) {
						if (zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_18$$15, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_18$$15)) {
								break;
							}
							continue;
						}
					}
					if (UNEXPECTED(!(zephir_is_callable(&before TSRMLS_CC)))) {
						ZEPHIR_INIT_NVAR(&_19$$17);
						object_init_ex(&_19$$17, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(&_20$$17);
						ZVAL_STRING(&_20$$17, "'before' handler is not callable");
						ZEPHIR_CALL_METHOD(NULL, &_19$$17, "__construct", NULL, 1, &_20$$17);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_19$$17, "phalcon/Mvc/Micro.zep", 438 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC(&status, &before);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_read_property(&_21$$13, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_21$$13)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&before);
				zephir_read_property(&_22$$12, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_22$$12)) {
					RETURN_CCTOR(&status);
				}
			}
			ZEPHIR_CALL_METHOD(&params, &router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property(&_16$$7, this_ptr, SL("modelBinder"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_16$$7);
			_23$$7 = Z_TYPE_P(&handler) == IS_OBJECT;
			if (_23$$7) {
				_23$$7 = zephir_instance_of_ev(&handler, zend_ce_closure TSRMLS_CC);
			}
			if (_23$$7) {
				_25$$20 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_24$$20, _25$$20, "bind", NULL, 0, &handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&handler, &_24$$20);
				if (Z_TYPE_P(&modelBinder) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&routeName, &matchedRoute, "getname", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					if (Z_TYPE_P(&routeName) != IS_NULL) {
						ZEPHIR_INIT_VAR(&_26$$22);
						ZEPHIR_CONCAT_SV(&_26$$22, "_PHMB_", &routeName);
						zephir_get_strval(&bindCacheKey, &_26$$22);
					} else {
						ZEPHIR_CALL_METHOD(&_27$$23, &matchedRoute, "getpattern", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_INIT_VAR(&_28$$23);
						ZEPHIR_CONCAT_SV(&_28$$23, "_PHMB_", &_27$$23);
						zephir_get_strval(&bindCacheKey, &_28$$23);
					}
					ZEPHIR_CALL_METHOD(&_29$$21, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_29$$21);
				}
			}
			if (Z_TYPE_P(&handler) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&realHandler);
				zephir_array_fetch_long(&realHandler, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 492 TSRMLS_CC);
				_30$$24 = zephir_instance_of_ev(&realHandler, phalcon_mvc_controller_ce TSRMLS_CC);
				if (_30$$24) {
					_30$$24 = Z_TYPE_P(&modelBinder) != IS_NULL;
				}
				if (_30$$24) {
					ZEPHIR_OBS_VAR(&methodName);
					zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 495 TSRMLS_CC);
					ZEPHIR_INIT_VAR(&_31$$25);
					zephir_get_class(&_31$$25, &realHandler, 0 TSRMLS_CC);
					ZEPHIR_INIT_VAR(&_32$$25);
					ZEPHIR_CONCAT_SVSV(&_32$$25, "_PHMB_", &_31$$25, "_", &methodName);
					zephir_get_strval(&bindCacheKey, &_32$$25);
					ZEPHIR_CALL_METHOD(&_33$$25, &modelBinder, "bindtohandler", NULL, 0, &realHandler, &params, &bindCacheKey, &methodName);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_33$$25);
				}
			}
			_34$$7 = Z_TYPE_P(&realHandler) != IS_NULL;
			if (_34$$7) {
				_34$$7 = zephir_instance_of_ev(&realHandler, phalcon_mvc_micro_lazyloader_ce TSRMLS_CC);
			}
			if (_34$$7) {
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 512 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&lazyReturned, &realHandler, "callmethod", NULL, 0, &methodName, &params, &modelBinder);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				ZEPHIR_INIT_NVAR(&lazyReturned);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&lazyReturned, &handler, &params);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_CPY_WRT(&returnedValue, &lazyReturned);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_36$$28);
				ZVAL_STRING(&_36$$28, "micro:afterBinding");
				ZEPHIR_CALL_METHOD(&_35$$28, &eventsManager, "fire", NULL, 0, &_36$$28, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_35$$28)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property(&_16$$7, this_ptr, SL("afterBindingHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterBindingHandlers, &_16$$7);
			if (Z_TYPE_P(&afterBindingHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_zval(this_ptr, SL("stopped"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, SL("stopped"), &__$false);
				}
				zephir_is_iterable(&afterBindingHandlers, 0, "phalcon/Mvc/Micro.zep", 586);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterBindingHandlers), _37$$30)
				{
					ZEPHIR_INIT_NVAR(&afterBinding);
					ZVAL_COPY(&afterBinding, _37$$30);
					_38$$31 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
					if (_38$$31) {
						_38$$31 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
					}
					if (_38$$31) {
						ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_39$$32, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_39$$32)) {
							break;
						}
						continue;
					}
					if (UNEXPECTED(!(zephir_is_callable(&afterBinding TSRMLS_CC)))) {
						ZEPHIR_INIT_NVAR(&_40$$34);
						object_init_ex(&_40$$34, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(&_41$$34);
						ZVAL_STRING(&_41$$34, "'afterBinding' handler is not callable");
						ZEPHIR_CALL_METHOD(NULL, &_40$$34, "__construct", NULL, 1, &_41$$34);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_40$$34, "phalcon/Mvc/Micro.zep", 567 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_read_property(&_42$$31, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_42$$31)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&afterBinding);
				zephir_read_property(&_43$$30, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_43$$30)) {
					RETURN_CCTOR(&status);
				}
			}
			zephir_update_property_zval(this_ptr, SL("returnedValue"), &returnedValue);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_44$$37);
				ZVAL_STRING(&_44$$37, "micro:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_44$$37, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
			}
			zephir_read_property(&_16$$7, this_ptr, SL("afterHandlers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&afterHandlers, &_16$$7);
			if (Z_TYPE_P(&afterHandlers) == IS_ARRAY) {
				if (0) {
					zephir_update_property_zval(this_ptr, SL("stopped"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, SL("stopped"), &__$false);
				}
				zephir_is_iterable(&afterHandlers, 0, "phalcon/Mvc/Micro.zep", 645);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterHandlers), _45$$38)
				{
					ZEPHIR_INIT_NVAR(&after);
					ZVAL_COPY(&after, _45$$38);
					if (Z_TYPE_P(&after) == IS_OBJECT) {
						if (zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_46$$41, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_46$$41)) {
								break;
							}
							continue;
						}
					}
					if (UNEXPECTED(!(zephir_is_callable(&after TSRMLS_CC)))) {
						ZEPHIR_INIT_NVAR(&_47$$43);
						object_init_ex(&_47$$43, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(&_48$$43);
						ZVAL_STRING(&_48$$43, "One of the 'after' handlers is not callable");
						ZEPHIR_CALL_METHOD(NULL, &_47$$43, "__construct", NULL, 1, &_48$$43);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_47$$43, "phalcon/Mvc/Micro.zep", 633 TSRMLS_CC);
						goto try_end_1;

					}
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC(&status, &after);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_read_property(&_49$$39, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_49$$39)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&after);
			}
		} else {
			zephir_read_property(&_50$$45, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&eventsManager, &_50$$45);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_52$$46);
				ZVAL_STRING(&_52$$46, "micro:beforeNotFound");
				ZEPHIR_CALL_METHOD(&_51$$46, &eventsManager, "fire", NULL, 0, &_52$$46, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_51$$46)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property(&_50$$45, this_ptr, SL("notFoundHandler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&notFoundHandler, &_50$$45);
			if (UNEXPECTED(!(zephir_is_callable(&notFoundHandler TSRMLS_CC)))) {
				ZEPHIR_INIT_VAR(&_53$$48);
				object_init_ex(&_53$$48, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(&_54$$48);
				ZVAL_STRING(&_54$$48, "Not-Found handler is not callable or is not defined");
				ZEPHIR_CALL_METHOD(NULL, &_53$$48, "__construct", NULL, 1, &_54$$48);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_53$$48, "phalcon/Mvc/Micro.zep", 667 TSRMLS_CC);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(&returnedValue);
			ZEPHIR_CALL_USER_FUNC(&returnedValue, &notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_55$$49);
			ZVAL_STRING(&_55$$49, "micro:afterHandleRoute");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_55$$49, this_ptr, &returnedValue);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_read_property(&_5$$4, this_ptr, SL("finishHandlers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&finishHandlers, &_5$$4);
		if (Z_TYPE_P(&finishHandlers) == IS_ARRAY) {
			if (0) {
				zephir_update_property_zval(this_ptr, SL("stopped"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("stopped"), &__$false);
			}
			ZEPHIR_INIT_NVAR(&params);
			ZVAL_NULL(&params);
			zephir_is_iterable(&finishHandlers, 0, "phalcon/Mvc/Micro.zep", 737);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&finishHandlers), _56$$50)
			{
				ZEPHIR_INIT_NVAR(&finish);
				ZVAL_COPY(&finish, _56$$50);
				if (Z_TYPE_P(&finish) == IS_OBJECT) {
					if (zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
						ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_57$$53, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_57$$53)) {
							break;
						}
						continue;
					}
				}
				if (UNEXPECTED(!(zephir_is_callable(&finish TSRMLS_CC)))) {
					ZEPHIR_INIT_NVAR(&_58$$55);
					object_init_ex(&_58$$55, phalcon_mvc_micro_exception_ce);
					ZEPHIR_INIT_NVAR(&_59$$55);
					ZVAL_STRING(&_59$$55, "One of the 'finish' handlers is not callable");
					ZEPHIR_CALL_METHOD(NULL, &_58$$55, "__construct", NULL, 1, &_59$$55);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_throw_exception_debug(&_58$$55, "phalcon/Mvc/Micro.zep", 718 TSRMLS_CC);
					goto try_end_1;

				}
				if (Z_TYPE_P(&params) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&params);
					zephir_create_array(&params, 1, 0 TSRMLS_CC);
					zephir_array_fast_append(&params, this_ptr);
				}
				ZEPHIR_INIT_NVAR(&status);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &params);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_read_property(&_60$$51, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_60$$51)) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&finish);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_61);
		ZVAL_OBJ(&_61, EG(exception));
		Z_ADDREF_P(&_61);
		if (zephir_is_instance_of(&_61, SL("Throwable") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_61);
			zephir_read_property(&_62$$58, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&eventsManager, &_62$$58);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_63$$59);
				ZVAL_STRING(&_63$$59, "micro:beforeException");
				ZEPHIR_CALL_METHOD(&returnedValue, &eventsManager, "fire", NULL, 0, &_63$$59, this_ptr, &e);
				zephir_check_call_status();
			}
			zephir_read_property(&_62$$58, this_ptr, SL("errorHandler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&errorHandler, &_62$$58);
			if (zephir_is_true(&errorHandler)) {
				if (UNEXPECTED(!(zephir_is_callable(&errorHandler TSRMLS_CC)))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Error handler is not callable", "phalcon/Mvc/Micro.zep", 759);
					return;
				}
				ZEPHIR_INIT_VAR(&_64$$60);
				zephir_create_array(&_64$$60, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_64$$60, &e);
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &errorHandler, &_64$$60);
				zephir_check_call_status();
				if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC))) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 772 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 776 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
					zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 781 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	zephir_read_property(&_0, this_ptr, SL("responseHandler"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_65$$68, this_ptr, SL("responseHandler"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(!(zephir_is_callable(&_65$$68 TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Response handler is not callable or is not defined", "phalcon/Mvc/Micro.zep", 794);
			return;
		}
		zephir_read_property(&_66$$68, this_ptr, SL("responseHandler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&returnedValue);
		ZEPHIR_CALL_USER_FUNC(&returnedValue, &_66$$68);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(&returnedValue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_68$$71);
			ZVAL_STRING(&_68$$71, "response");
			ZEPHIR_CALL_METHOD(&_67$$71, &container, "getshared", NULL, 0, &_68$$71);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_67$$71);
			ZEPHIR_CALL_METHOD(&_67$$71, &response, "issent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_67$$71))) {
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &returnedValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
		if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
			if (zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_69$$74, &returnedValue, "issent", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_69$$74))) {
					ZEPHIR_CALL_METHOD(NULL, &returnedValue, "send", NULL, 0);
					zephir_check_call_status();
				}
			}
		}
	}
	RETURN_CCTOR(&returnedValue);

}

/**
 * Checks if a service is registered in the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, hasService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, container, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
		ZVAL_EMPTY_STRING(&serviceName);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 407);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "has", NULL, 410, &serviceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is HEAD
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, head) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addhead", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler without any HTTP method constraint
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, map) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "add", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Mounts a collection of handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount) {

	zend_bool _3$$8, _4$$8;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, mainHandler, handlers, lazyHandler, prefix, methods, pattern, subHandler, realHandler, prefixedPattern, route, handler, name, _0$$5, *_1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&mainHandler);
	ZVAL_UNDEF(&handlers);
	ZVAL_UNDEF(&lazyHandler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&subHandler);
	ZVAL_UNDEF(&realHandler);
	ZVAL_UNDEF(&prefixedPattern);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_CALL_METHOD(&mainHandler, collection, "gethandler", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&mainHandler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Collection requires a main handler", "phalcon/Mvc/Micro.zep", 919);
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "gethandlers", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_count_int(&handlers TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "There are no handlers to mount", "phalcon/Mvc/Micro.zep", 925);
		return;
	}
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$5, collection, "islazy", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$5)) {
			ZEPHIR_INIT_VAR(&lazyHandler);
			object_init_ex(&lazyHandler, phalcon_mvc_micro_lazyloader_ce);
			ZEPHIR_CALL_METHOD(NULL, &lazyHandler, "__construct", NULL, 411, &mainHandler);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&lazyHandler, &mainHandler);
		}
		ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&handlers, 0, "phalcon/Mvc/Micro.zep", 983);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _1$$5)
		{
			ZEPHIR_INIT_NVAR(&handler);
			ZVAL_COPY(&handler, _1$$5);
			if (UNEXPECTED(Z_TYPE_P(&handler) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/Mvc/Micro.zep", 947);
				return;
			}
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 950 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&pattern);
			zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 951 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&subHandler);
			zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 952 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&name);
			zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 953 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&realHandler);
			zephir_create_array(&realHandler, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&realHandler, &lazyHandler);
			zephir_array_fast_append(&realHandler, &subHandler);
			if (!(ZEPHIR_IS_EMPTY(&prefix))) {
				if (ZEPHIR_IS_STRING(&pattern, "/")) {
					ZEPHIR_CPY_WRT(&prefixedPattern, &prefix);
				} else {
					ZEPHIR_INIT_NVAR(&prefixedPattern);
					ZEPHIR_CONCAT_VV(&prefixedPattern, &prefix, &pattern);
				}
			} else {
				ZEPHIR_CPY_WRT(&prefixedPattern, &pattern);
			}
			ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_2, 0, &prefixedPattern, &realHandler);
			zephir_check_call_status();
			_3$$8 = Z_TYPE_P(&methods) == IS_STRING;
			if (_3$$8) {
				_3$$8 = !ZEPHIR_IS_STRING(&methods, "");
			}
			_4$$8 = _3$$8;
			if (!(_4$$8)) {
				_4$$8 = Z_TYPE_P(&methods) == IS_ARRAY;
			}
			if (_4$$8) {
				ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&name) == IS_STRING) {
				ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &name);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&handler);
	}
	RETURN_THIS();

}

/**
 * Sets a handler that will be called when the router doesn't match any of
 * the defined routes
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, notFound) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("notFoundHandler"), handler);
	RETURN_THISW();

}

/**
 * Check if a service is registered in the internal services container using
 * the array syntax
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasservice", NULL, 0, alias);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to obtain a shared service in the internal services container
 * using the array syntax
 *
 *<code>
 * var_dump(
 *     $app["request"]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getservice", NULL, 0, alias);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to register a shared service in the internal services container
 * using the array syntax
 *
 *<code>
 *    $app["request"] = new \Phalcon\Http\Request();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, *definition, definition_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&definition_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias, &definition);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setservice", NULL, 0, alias, definition);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a service from the internal services container using the array
 * syntax
 */
PHP_METHOD(Phalcon_Mvc_Micro, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, container, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias);



	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 407);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	ZEPHIR_CALL_METHOD(NULL, &container, "remove", NULL, 412, alias);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Maps a route to a handler that only matches if the HTTP method is OPTIONS
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, options) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addoptions", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PATCH
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, patch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addpatch", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is POST
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, post) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addpost", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Maps a route to a handler that only matches if the HTTP method is PUT
 *
 * @param callable $handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, put) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routePattern_param = NULL, *handler, handler_sub, router, route, _0;
	zval routePattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routePattern);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &routePattern_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(routePattern_param) != IS_STRING && Z_TYPE_P(routePattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'routePattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(routePattern_param) == IS_STRING)) {
		zephir_get_strval(&routePattern, routePattern_param);
	} else {
		ZEPHIR_INIT_VAR(&routePattern);
		ZVAL_EMPTY_STRING(&routePattern);
	}


	ZEPHIR_CALL_METHOD(&router, this_ptr, "getrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, &router, "addput", NULL, 0, &routePattern);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &route, "getrouteid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Sets externally the handler that must be called by the matched route
 *
 * @param callable activeHandler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler) {

	zval *activeHandler, activeHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&activeHandler_sub);

	zephir_fetch_params(0, 1, 0, &activeHandler);



	zephir_update_property_zval(this_ptr, SL("activeHandler"), activeHandler);

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Micro, setDI) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "application");
	ZEPHIR_CALL_METHOD(&_0, container, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "application");
		ZEPHIR_CALL_METHOD(NULL, container, "set", NULL, 0, &_2$$3, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("container"), container);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets model binder
 *
 * <code>
 * $micro = new Micro($di);
 * $micro->setModelBinder(new Binder(), 'cache');
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Micro, setModelBinder) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelBinder, modelBinder_sub, *cache = NULL, cache_sub, __$null, container, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modelBinder, &cache);

	if (!cache) {
		cache = &cache_sub;
		ZEPHIR_CPY_WRT(cache, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cache);
	}


	if (Z_TYPE_P(cache) == IS_STRING) {
		zephir_read_property(&_0$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_0$$3);
		ZEPHIR_CALL_METHOD(&_1$$3, &container, "get", NULL, 0, cache);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cache, &_1$$3);
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, modelBinder, "setcache", NULL, 0, cache);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("modelBinder"), modelBinder);
	RETURN_THIS();

}

/**
 * Appends a custom 'reponse' handler to be called insted of the default
 * response handler
 *
 * @param callable handler
 */
PHP_METHOD(Phalcon_Mvc_Micro, setResponseHandler) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, SL("responseHandler"), handler);
	RETURN_THISW();

}

/**
 * Sets a service from the DI
 */
PHP_METHOD(Phalcon_Mvc_Micro, setService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared;
	zval *serviceName_param = NULL, *definition, definition_sub, *shared_param = NULL, container, _0;
	zval serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &serviceName_param, &definition, &shared_param);

	if (UNEXPECTED(Z_TYPE_P(serviceName_param) != IS_STRING && Z_TYPE_P(serviceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serviceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(serviceName_param) == IS_STRING)) {
		zephir_get_strval(&serviceName, serviceName_param);
	} else {
		ZEPHIR_INIT_VAR(&serviceName);
		ZVAL_EMPTY_STRING(&serviceName);
	}
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_NVAR(&container);
		object_init_ex(&container, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 407);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	if (shared) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "set", NULL, 413, &serviceName, definition, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stops the middleware execution avoiding than other middlewares be
 * executed
 */
PHP_METHOD(Phalcon_Mvc_Micro, stop) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (1) {
		zephir_update_property_zval(this_ptr, SL("stopped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("stopped"), &__$false);
	}

}

zend_object *zephir_init_properties_Phalcon_Mvc_Micro(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("handlers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

