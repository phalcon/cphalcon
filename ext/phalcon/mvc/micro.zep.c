
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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


	if (Z_TYPE_P(container) == IS_OBJECT) {
		if (zephir_instance_of_ev(container, phalcon_diinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, container);
			zephir_check_call_status();
		}
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



	zephir_update_property_array_append(this_ptr, SL("afterHandlers"), handler);
	RETURN_THISW();

}

/**
 * Appends a afterBinding middleware to be called after model binding
 *
 * @param callable handler
 * @return \Phalcon\Mvc\Micro
 */
PHP_METHOD(Phalcon_Mvc_Micro, afterBinding) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_array_append(this_ptr, SL("afterBindingHandlers"), handler);
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



	zephir_update_property_array_append(this_ptr, SL("beforeHandlers"), handler);
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
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
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



	zephir_update_property_array_append(this_ptr, SL("finishHandlers"), handler);
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
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
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
	if (Z_TYPE_P(&modelBinder) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(&modelBinder, "getboundmodels", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
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
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 364);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "get", NULL, 365, &serviceName);
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
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 364);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "getshared", NULL, 366, &serviceName);
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

	zval _84$$84;
	zend_class_entry *_30$$26;
	zend_bool _28$$7, _36$$7, _33$$30, _41$$37, _46$$42;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *uri_param = NULL, __$true, __$false, container, eventsManager, status, router, matchedRoute, handler, beforeHandlers, params, returnedValue, e, errorHandler, afterHandlers, notFoundHandler, finishHandlers, finish, before, after, response, modelBinder, bindCacheKey, routeName, realHandler, methodName, lazyReturned, afterBindingHandlers, afterBinding, _0, _81, _1$$3, _2$$3, _4$$3, _5$$4, _8$$4, _9$$4, _6$$5, _7$$5, _10$$7, _11$$7, _16$$7, _12$$8, _13$$8, _14$$9, _15$$9, *_17$$12, _18$$12, _27$$12, _19$$15, _20$$17, _21$$17, _22$$13, _23$$21, _24$$23, _25$$23, _26$$19, _29$$26, _31$$29, _32$$27, _34$$31, _35$$31, _37$$34, _38$$34, *_39$$36, _40$$36, _51$$36, _45$$37, _42$$38, _43$$40, _44$$40, _50$$42, _47$$43, _48$$45, _49$$45, _52$$48, *_53$$49, _54$$49, _55$$52, _56$$54, _57$$54, _58$$50, _59$$58, _60$$60, _61$$60, _62$$56, _63$$62, _64$$63, _65$$63, _66$$65, _67$$65, _68$$66, *_69$$67, _70$$67, _71$$70, _72$$72, _73$$72, _74$$73, _75$$68, _76$$77, _77$$79, _78$$79, _79$$80, _80$$75, _82$$82, _83$$83, _85$$92, _86$$92, _87$$95, _88$$95, _89$$98;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
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
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&realHandler);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&lazyReturned);
	ZVAL_UNDEF(&afterBindingHandlers);
	ZVAL_UNDEF(&afterBinding);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_81);
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
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_29$$26);
	ZVAL_UNDEF(&_31$$29);
	ZVAL_UNDEF(&_32$$27);
	ZVAL_UNDEF(&_34$$31);
	ZVAL_UNDEF(&_35$$31);
	ZVAL_UNDEF(&_37$$34);
	ZVAL_UNDEF(&_38$$34);
	ZVAL_UNDEF(&_40$$36);
	ZVAL_UNDEF(&_51$$36);
	ZVAL_UNDEF(&_45$$37);
	ZVAL_UNDEF(&_42$$38);
	ZVAL_UNDEF(&_43$$40);
	ZVAL_UNDEF(&_44$$40);
	ZVAL_UNDEF(&_50$$42);
	ZVAL_UNDEF(&_47$$43);
	ZVAL_UNDEF(&_48$$45);
	ZVAL_UNDEF(&_49$$45);
	ZVAL_UNDEF(&_52$$48);
	ZVAL_UNDEF(&_54$$49);
	ZVAL_UNDEF(&_55$$52);
	ZVAL_UNDEF(&_56$$54);
	ZVAL_UNDEF(&_57$$54);
	ZVAL_UNDEF(&_58$$50);
	ZVAL_UNDEF(&_59$$58);
	ZVAL_UNDEF(&_60$$60);
	ZVAL_UNDEF(&_61$$60);
	ZVAL_UNDEF(&_62$$56);
	ZVAL_UNDEF(&_63$$62);
	ZVAL_UNDEF(&_64$$63);
	ZVAL_UNDEF(&_65$$63);
	ZVAL_UNDEF(&_66$$65);
	ZVAL_UNDEF(&_67$$65);
	ZVAL_UNDEF(&_68$$66);
	ZVAL_UNDEF(&_70$$67);
	ZVAL_UNDEF(&_71$$70);
	ZVAL_UNDEF(&_72$$72);
	ZVAL_UNDEF(&_73$$72);
	ZVAL_UNDEF(&_74$$73);
	ZVAL_UNDEF(&_75$$68);
	ZVAL_UNDEF(&_76$$77);
	ZVAL_UNDEF(&_77$$79);
	ZVAL_UNDEF(&_78$$79);
	ZVAL_UNDEF(&_79$$80);
	ZVAL_UNDEF(&_80$$75);
	ZVAL_UNDEF(&_82$$82);
	ZVAL_UNDEF(&_83$$83);
	ZVAL_UNDEF(&_85$$92);
	ZVAL_UNDEF(&_86$$92);
	ZVAL_UNDEF(&_87$$95);
	ZVAL_UNDEF(&_88$$95);
	ZVAL_UNDEF(&_89$$98);
	ZVAL_UNDEF(&_84$$84);

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
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_micro_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "micro services");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_mvc_micro_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Micro.zep", 345 TSRMLS_CC);
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
			if (!(zephir_array_isset_fetch(&handler, &_10$$7, &_11$$7, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_12$$8);
				object_init_ex(&_12$$8, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(&_13$$8);
				ZVAL_STRING(&_13$$8, "Matched route doesn't have an associated handler");
				ZEPHIR_CALL_METHOD(NULL, &_12$$8, "__construct", NULL, 1, &_13$$8);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_12$$8, "phalcon/Mvc/Micro.zep", 381 TSRMLS_CC);
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
				zephir_is_iterable(&beforeHandlers, 0, "phalcon/Mvc/Micro.zep", 451);
				if (Z_TYPE_P(&beforeHandlers) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&beforeHandlers), _17$$12)
					{
						ZEPHIR_INIT_NVAR(&before);
						ZVAL_COPY(&before, _17$$12);
						if (Z_TYPE_P(&before) == IS_OBJECT) {
							if (zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
								ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_read_property(&_19$$15, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_19$$15)) {
									break;
								}
								continue;
							}
						}
						if (!(zephir_is_callable(&before TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_20$$17);
							object_init_ex(&_20$$17, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_21$$17);
							ZVAL_STRING(&_21$$17, "'before' handler is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_20$$17, "__construct", NULL, 1, &_21$$17);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_20$$17, "phalcon/Mvc/Micro.zep", 433 TSRMLS_CC);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &before);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_22$$13, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_22$$13)) {
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_18$$12, &beforeHandlers, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_18$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&before, &beforeHandlers, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&before) == IS_OBJECT) {
								if (zephir_instance_of_ev(&before, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
									ZEPHIR_CALL_METHOD(&status, &before, "call", NULL, 0, this_ptr);
									zephir_check_call_status_or_jump(try_end_1);
									zephir_read_property(&_23$$21, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
									if (zephir_is_true(&_23$$21)) {
										break;
									}
									continue;
								}
							}
							if (!(zephir_is_callable(&before TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(&_24$$23);
								object_init_ex(&_24$$23, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_25$$23);
								ZVAL_STRING(&_25$$23, "'before' handler is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_24$$23, "__construct", NULL, 1, &_25$$23);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_24$$23, "phalcon/Mvc/Micro.zep", 433 TSRMLS_CC);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &before);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_26$$19, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_26$$19)) {
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &beforeHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&before);
				zephir_read_property(&_27$$12, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_27$$12)) {
					RETURN_CCTOR(&status);
				}
			}
			ZEPHIR_CALL_METHOD(&params, &router, "getparams", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property(&_16$$7, this_ptr, SL("modelBinder"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&modelBinder, &_16$$7);
			_28$$7 = Z_TYPE_P(&handler) == IS_OBJECT;
			if (_28$$7) {
				_28$$7 = zephir_instance_of_ev(&handler, zend_ce_closure TSRMLS_CC);
			}
			if (_28$$7) {
				_30$$26 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_29$$26, _30$$26, "bind", NULL, 0, &handler, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&handler, &_29$$26);
				if (Z_TYPE_P(&modelBinder) != IS_NULL) {
					ZEPHIR_CALL_METHOD(&routeName, &matchedRoute, "getname", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_INIT_VAR(&bindCacheKey);
					if (Z_TYPE_P(&routeName) != IS_NULL) {
						ZEPHIR_CONCAT_SV(&bindCacheKey, "_PHMB_", &routeName);
					} else {
						ZEPHIR_CALL_METHOD(&_31$$29, &matchedRoute, "getpattern", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CONCAT_SV(&bindCacheKey, "_PHMB_", &_31$$29);
					}
					ZEPHIR_CALL_METHOD(&_32$$27, &modelBinder, "bindtohandler", NULL, 0, &handler, &params, &bindCacheKey);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_32$$27);
				}
			}
			if (Z_TYPE_P(&handler) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&realHandler);
				zephir_array_fetch_long(&realHandler, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 487 TSRMLS_CC);
				_33$$30 = zephir_instance_of_ev(&realHandler, phalcon_mvc_controller_ce TSRMLS_CC);
				if (_33$$30) {
					_33$$30 = Z_TYPE_P(&modelBinder) != IS_NULL;
				}
				if (_33$$30) {
					ZEPHIR_OBS_VAR(&methodName);
					zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 490 TSRMLS_CC);
					ZEPHIR_INIT_VAR(&_34$$31);
					zephir_get_class(&_34$$31, &realHandler, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&bindCacheKey);
					ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &_34$$31, "_", &methodName);
					ZEPHIR_CALL_METHOD(&_35$$31, &modelBinder, "bindtohandler", NULL, 0, &realHandler, &params, &bindCacheKey, &methodName);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CPY_WRT(&params, &_35$$31);
				}
			}
			_36$$7 = Z_TYPE_P(&realHandler) != IS_NULL;
			if (_36$$7) {
				_36$$7 = zephir_instance_of_ev(&realHandler, phalcon_mvc_micro_lazyloader_ce TSRMLS_CC);
			}
			if (_36$$7) {
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 507 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&lazyReturned, &realHandler, "callmethod", NULL, 0, &methodName, &params, &modelBinder);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(&returnedValue, &lazyReturned);
			} else {
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &handler, &params);
				zephir_check_call_status_or_jump(try_end_1);
			}
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_38$$34);
				ZVAL_STRING(&_38$$34, "micro:afterBinding");
				ZEPHIR_CALL_METHOD(&_37$$34, &eventsManager, "fire", NULL, 0, &_38$$34, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_37$$34)) {
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
				zephir_is_iterable(&afterBindingHandlers, 0, "phalcon/Mvc/Micro.zep", 581);
				if (Z_TYPE_P(&afterBindingHandlers) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterBindingHandlers), _39$$36)
					{
						ZEPHIR_INIT_NVAR(&afterBinding);
						ZVAL_COPY(&afterBinding, _39$$36);
						_41$$37 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
						if (_41$$37) {
							_41$$37 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
						}
						if (_41$$37) {
							ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_42$$38, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_42$$38)) {
								break;
							}
							continue;
						}
						if (!(zephir_is_callable(&afterBinding TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_43$$40);
							object_init_ex(&_43$$40, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_44$$40);
							ZVAL_STRING(&_44$$40, "'afterBinding' handler is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_43$$40, "__construct", NULL, 1, &_44$$40);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_43$$40, "phalcon/Mvc/Micro.zep", 563 TSRMLS_CC);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_45$$37, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_45$$37)) {
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_40$$36, &afterBindingHandlers, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_40$$36)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&afterBinding, &afterBindingHandlers, "current", NULL, 0);
						zephir_check_call_status();
							_46$$42 = Z_TYPE_P(&afterBinding) == IS_OBJECT;
							if (_46$$42) {
								_46$$42 = zephir_instance_of_ev(&afterBinding, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC);
							}
							if (_46$$42) {
								ZEPHIR_CALL_METHOD(&status, &afterBinding, "call", NULL, 0, this_ptr);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_read_property(&_47$$43, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_47$$43)) {
									break;
								}
								continue;
							}
							if (!(zephir_is_callable(&afterBinding TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(&_48$$45);
								object_init_ex(&_48$$45, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_49$$45);
								ZVAL_STRING(&_49$$45, "'afterBinding' handler is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_48$$45, "__construct", NULL, 1, &_49$$45);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_48$$45, "phalcon/Mvc/Micro.zep", 563 TSRMLS_CC);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &afterBinding);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_50$$42, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_50$$42)) {
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &afterBindingHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&afterBinding);
				zephir_read_property(&_51$$36, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_51$$36)) {
					RETURN_CCTOR(&status);
				}
			}
			zephir_update_property_zval(this_ptr, SL("returnedValue"), &returnedValue);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_52$$48);
				ZVAL_STRING(&_52$$48, "micro:afterExecuteRoute");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_52$$48, this_ptr);
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
				zephir_is_iterable(&afterHandlers, 0, "phalcon/Mvc/Micro.zep", 642);
				if (Z_TYPE_P(&afterHandlers) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&afterHandlers), _53$$49)
					{
						ZEPHIR_INIT_NVAR(&after);
						ZVAL_COPY(&after, _53$$49);
						if (Z_TYPE_P(&after) == IS_OBJECT) {
							if (zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
								ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_read_property(&_55$$52, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_55$$52)) {
									break;
								}
								continue;
							}
						}
						if (!(zephir_is_callable(&after TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_56$$54);
							object_init_ex(&_56$$54, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_57$$54);
							ZVAL_STRING(&_57$$54, "One of the 'after' handlers is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_56$$54, "__construct", NULL, 1, &_57$$54);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_56$$54, "phalcon/Mvc/Micro.zep", 630 TSRMLS_CC);
							goto try_end_1;

						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &after);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_58$$50, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_58$$50)) {
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_54$$49, &afterHandlers, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_54$$49)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&after, &afterHandlers, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&after) == IS_OBJECT) {
								if (zephir_instance_of_ev(&after, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
									ZEPHIR_CALL_METHOD(&status, &after, "call", NULL, 0, this_ptr);
									zephir_check_call_status_or_jump(try_end_1);
									zephir_read_property(&_59$$58, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
									if (zephir_is_true(&_59$$58)) {
										break;
									}
									continue;
								}
							}
							if (!(zephir_is_callable(&after TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(&_60$$60);
								object_init_ex(&_60$$60, phalcon_mvc_micro_exception_ce);
								ZEPHIR_INIT_NVAR(&_61$$60);
								ZVAL_STRING(&_61$$60, "One of the 'after' handlers is not callable");
								ZEPHIR_CALL_METHOD(NULL, &_60$$60, "__construct", NULL, 1, &_61$$60);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_throw_exception_debug(&_60$$60, "phalcon/Mvc/Micro.zep", 630 TSRMLS_CC);
								goto try_end_1;

							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC(&status, &after);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_62$$56, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_62$$56)) {
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &afterHandlers, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&after);
			}
		} else {
			zephir_read_property(&_63$$62, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&eventsManager, &_63$$62);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_65$$63);
				ZVAL_STRING(&_65$$63, "micro:beforeNotFound");
				ZEPHIR_CALL_METHOD(&_64$$63, &eventsManager, "fire", NULL, 0, &_65$$63, this_ptr);
				zephir_check_call_status_or_jump(try_end_1);
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_64$$63)) {
					RETURN_MM_BOOL(0);
				}
			}
			zephir_read_property(&_63$$62, this_ptr, SL("notFoundHandler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&notFoundHandler, &_63$$62);
			if (!(zephir_is_callable(&notFoundHandler TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_66$$65);
				object_init_ex(&_66$$65, phalcon_mvc_micro_exception_ce);
				ZEPHIR_INIT_VAR(&_67$$65);
				ZVAL_STRING(&_67$$65, "Not-Found handler is not callable or is not defined");
				ZEPHIR_CALL_METHOD(NULL, &_66$$65, "__construct", NULL, 1, &_67$$65);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_66$$65, "phalcon/Mvc/Micro.zep", 663 TSRMLS_CC);
				goto try_end_1;

			}
			ZEPHIR_INIT_NVAR(&returnedValue);
			ZEPHIR_CALL_USER_FUNC(&returnedValue, &notFoundHandler);
			zephir_check_call_status_or_jump(try_end_1);
		}
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_68$$66);
			ZVAL_STRING(&_68$$66, "micro:afterHandleRoute");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_68$$66, this_ptr, &returnedValue);
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
			zephir_is_iterable(&finishHandlers, 0, "phalcon/Mvc/Micro.zep", 736);
			if (Z_TYPE_P(&finishHandlers) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&finishHandlers), _69$$67)
				{
					ZEPHIR_INIT_NVAR(&finish);
					ZVAL_COPY(&finish, _69$$67);
					if (Z_TYPE_P(&finish) == IS_OBJECT) {
						if (zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
							ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_read_property(&_71$$70, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
							if (zephir_is_true(&_71$$70)) {
								break;
							}
							continue;
						}
					}
					if (!(zephir_is_callable(&finish TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_72$$72);
						object_init_ex(&_72$$72, phalcon_mvc_micro_exception_ce);
						ZEPHIR_INIT_NVAR(&_73$$72);
						ZVAL_STRING(&_73$$72, "One of the 'finish' handlers is not callable");
						ZEPHIR_CALL_METHOD(NULL, &_72$$72, "__construct", NULL, 1, &_73$$72);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(&_72$$72, "phalcon/Mvc/Micro.zep", 717 TSRMLS_CC);
						goto try_end_1;

					}
					if (Z_TYPE_P(&params) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&_74$$73);
						zephir_create_array(&_74$$73, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(&_74$$73, this_ptr);
						ZEPHIR_CPY_WRT(&params, &_74$$73);
					}
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &params);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_read_property(&_75$$68, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
					if (zephir_is_true(&_75$$68)) {
						break;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_70$$67, &finishHandlers, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_70$$67)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&finish, &finishHandlers, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&finish) == IS_OBJECT) {
							if (zephir_instance_of_ev(&finish, phalcon_mvc_micro_middlewareinterface_ce TSRMLS_CC)) {
								ZEPHIR_CALL_METHOD(&status, &finish, "call", NULL, 0, this_ptr);
								zephir_check_call_status_or_jump(try_end_1);
								zephir_read_property(&_76$$77, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
								if (zephir_is_true(&_76$$77)) {
									break;
								}
								continue;
							}
						}
						if (!(zephir_is_callable(&finish TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_77$$79);
							object_init_ex(&_77$$79, phalcon_mvc_micro_exception_ce);
							ZEPHIR_INIT_NVAR(&_78$$79);
							ZVAL_STRING(&_78$$79, "One of the 'finish' handlers is not callable");
							ZEPHIR_CALL_METHOD(NULL, &_77$$79, "__construct", NULL, 1, &_78$$79);
							zephir_check_call_status_or_jump(try_end_1);
							zephir_throw_exception_debug(&_77$$79, "phalcon/Mvc/Micro.zep", 717 TSRMLS_CC);
							goto try_end_1;

						}
						if (Z_TYPE_P(&params) == IS_NULL) {
							ZEPHIR_INIT_NVAR(&_79$$80);
							zephir_create_array(&_79$$80, 1, 0 TSRMLS_CC);
							zephir_array_fast_append(&_79$$80, this_ptr);
							ZEPHIR_CPY_WRT(&params, &_79$$80);
						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &finish, &params);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_read_property(&_80$$75, this_ptr, SL("stopped"), PH_NOISY_CC | PH_READONLY);
						if (zephir_is_true(&_80$$75)) {
							break;
						}
					ZEPHIR_CALL_METHOD(NULL, &finishHandlers, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&finish);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_81);
		ZVAL_OBJ(&_81, EG(exception));
		Z_ADDREF_P(&_81);
		if (zephir_is_instance_of(&_81, SL("Throwable") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_81);
			zephir_read_property(&_82$$82, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&eventsManager, &_82$$82);
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_83$$83);
				ZVAL_STRING(&_83$$83, "micro:beforeException");
				ZEPHIR_CALL_METHOD(&returnedValue, &eventsManager, "fire", NULL, 0, &_83$$83, this_ptr, &e);
				zephir_check_call_status();
			}
			zephir_read_property(&_82$$82, this_ptr, SL("errorHandler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&errorHandler, &_82$$82);
			if (zephir_is_true(&errorHandler)) {
				if (!(zephir_is_callable(&errorHandler TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Error handler is not callable", "phalcon/Mvc/Micro.zep", 755);
					return;
				}
				ZEPHIR_INIT_VAR(&_84$$84);
				zephir_create_array(&_84$$84, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&_84$$84, &e);
				ZEPHIR_INIT_NVAR(&returnedValue);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&returnedValue, &errorHandler, &_84$$84);
				zephir_check_call_status();
				if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
					if (!(zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC))) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 764 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
						zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 768 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&returnedValue)) {
					zephir_throw_exception_debug(&e, "phalcon/Mvc/Micro.zep", 774 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	zephir_read_property(&_0, this_ptr, SL("responseHandler"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_85$$92, this_ptr, SL("responseHandler"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_callable(&_85$$92 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Response handler is not callable or is not defined", "phalcon/Mvc/Micro.zep", 789);
			return;
		}
		zephir_read_property(&_86$$92, this_ptr, SL("responseHandler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&returnedValue);
		ZEPHIR_CALL_USER_FUNC(&returnedValue, &_86$$92);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(&returnedValue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_88$$95);
			ZVAL_STRING(&_88$$95, "response");
			ZEPHIR_CALL_METHOD(&_87$$95, &container, "getshared", NULL, 0, &_88$$95);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&response, &_87$$95);
			ZEPHIR_CALL_METHOD(&_87$$95, &response, "issent", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_87$$95))) {
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &returnedValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "send", NULL, 0);
				zephir_check_call_status();
			}
		}
		if (Z_TYPE_P(&returnedValue) == IS_OBJECT) {
			if (zephir_instance_of_ev(&returnedValue, phalcon_http_responseinterface_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_89$$98, &returnedValue, "issent", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_89$$98))) {
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
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 364);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "has", NULL, 367, &serviceName);
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
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
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
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
	RETURN_CCTOR(&route);

}

/**
 * Mounts a collection of handlers
 */
PHP_METHOD(Phalcon_Mvc_Micro, mount) {

	zend_bool _4$$8, _5$$8, _7$$16, _8$$16;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, mainHandler, handlers, lazyHandler, prefix, methods, pattern, subHandler, realHandler, prefixedPattern, route, handler, name, _0$$5, *_1$$5, _2$$5, _6$$16;
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
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_6$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_CALL_METHOD(&mainHandler, collection, "gethandler", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&mainHandler)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "Collection requires a main handler", "phalcon/Mvc/Micro.zep", 912);
		return;
	}
	ZEPHIR_CALL_METHOD(&handlers, collection, "gethandlers", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&handlers TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "There are no handlers to mount", "phalcon/Mvc/Micro.zep", 917);
		return;
	}
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$5, collection, "islazy", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$5)) {
			ZEPHIR_INIT_VAR(&lazyHandler);
			object_init_ex(&lazyHandler, phalcon_mvc_micro_lazyloader_ce);
			ZEPHIR_CALL_METHOD(NULL, &lazyHandler, "__construct", NULL, 368, &mainHandler);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&lazyHandler, &mainHandler);
		}
		ZEPHIR_CALL_METHOD(&prefix, collection, "getprefix", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&handlers, 0, "phalcon/Mvc/Micro.zep", 977);
		if (Z_TYPE_P(&handlers) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&handler);
				ZVAL_COPY(&handler, _1$$5);
				if (Z_TYPE_P(&handler) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/Mvc/Micro.zep", 941);
					return;
				}
				ZEPHIR_OBS_NVAR(&methods);
				zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 944 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&pattern);
				zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 945 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&subHandler);
				zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 946 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 947 TSRMLS_CC);
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
				ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_3, 0, &prefixedPattern, &realHandler);
				zephir_check_call_status();
				_4$$8 = Z_TYPE_P(&methods) == IS_STRING;
				if (_4$$8) {
					_4$$8 = !ZEPHIR_IS_STRING(&methods, "");
				}
				_5$$8 = _4$$8;
				if (!(_5$$8)) {
					_5$$8 = Z_TYPE_P(&methods) == IS_ARRAY;
				}
				if (_5$$8) {
					ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&name) == IS_STRING) {
					ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &name);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &handlers, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$5, &handlers, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&handler, &handlers, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&handler) != IS_ARRAY) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_micro_exception_ce, "One of the registered handlers is invalid", "phalcon/Mvc/Micro.zep", 941);
						return;
					}
					ZEPHIR_OBS_NVAR(&methods);
					zephir_array_fetch_long(&methods, &handler, 0, PH_NOISY, "phalcon/Mvc/Micro.zep", 944 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&pattern);
					zephir_array_fetch_long(&pattern, &handler, 1, PH_NOISY, "phalcon/Mvc/Micro.zep", 945 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&subHandler);
					zephir_array_fetch_long(&subHandler, &handler, 2, PH_NOISY, "phalcon/Mvc/Micro.zep", 946 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&name);
					zephir_array_fetch_long(&name, &handler, 3, PH_NOISY, "phalcon/Mvc/Micro.zep", 947 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_6$$16);
					zephir_create_array(&_6$$16, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_6$$16, &lazyHandler);
					zephir_array_fast_append(&_6$$16, &subHandler);
					ZEPHIR_CPY_WRT(&realHandler, &_6$$16);
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
					ZEPHIR_CALL_METHOD(&route, this_ptr, "map", &_3, 0, &prefixedPattern, &realHandler);
					zephir_check_call_status();
					_7$$16 = Z_TYPE_P(&methods) == IS_STRING;
					if (_7$$16) {
						_7$$16 = !ZEPHIR_IS_STRING(&methods, "");
					}
					_8$$16 = _7$$16;
					if (!(_8$$16)) {
						_8$$16 = Z_TYPE_P(&methods) == IS_ARRAY;
					}
					if (_8$$16) {
						ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
						zephir_check_call_status();
					}
					if (Z_TYPE_P(&name) == IS_STRING) {
						ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &name);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, &handlers, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
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
 *
 * @return mixed
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
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 364);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	ZEPHIR_CALL_METHOD(NULL, &container, "remove", NULL, 369, alias);
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
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
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
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
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
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
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
	zephir_update_property_array(this_ptr, SL("handlers"), &_0, handler);
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
		ZEPHIR_CALL_METHOD(NULL, &container, "__construct", NULL, 364);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("container"), &container);
	}
	if (shared) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&container, "set", NULL, 370, &serviceName, definition, &_0);
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

