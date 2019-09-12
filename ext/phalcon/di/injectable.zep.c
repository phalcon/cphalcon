
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This class allows to access services in the services container by just only
 * accessing a public property with the same name of a registered service
 *
 * @property \Phalcon\Mvc\Dispatcher|\Phalcon\Mvc\DispatcherInterface $dispatcher
 * @property \Phalcon\Mvc\Router|\Phalcon\Mvc\RouterInterface $router
 * @property \Phalcon\Url|\Phalcon\Url\UrlInterface $url
 * @property \Phalcon\Http\Request|\Phalcon\Http\RequestInterface $request
 * @property \Phalcon\Http\Response|\Phalcon\Http\ResponseInterface $response
 * @property \Phalcon\Http\Response\Cookies|\Phalcon\Http\Response\CookiesInterface $cookies
 * @property \Phalcon\Filter $filter
 * @property \Phalcon\Flash\Direct $flash
 * @property \Phalcon\Flash\Session $flashSession
 * @property \Phalcon\Session\ManagerInterface $session
 * @property \Phalcon\Events\Manager|\Phalcon\Events\ManagerInterface $eventsManager
 * @property \Phalcon\Db\Adapter\AdapterInterface $db
 * @property \Phalcon\Security $security
 * @property \Phalcon\Crypt|\Phalcon\CryptInterface $crypt
 * @property \Phalcon\Tag $tag
 * @property \Phalcon\Escaper|\Phalcon\Escaper\EscaperInterface $escaper
 * @property \Phalcon\Annotations\Adapter\Memory|\Phalcon\Annotations\Adapter $annotations
 * @property \Phalcon\Mvc\Model\Manager|\Phalcon\Mvc\Model\ManagerInterface $modelsManager
 * @property \Phalcon\Mvc\Model\MetaData\Memory|\Phalcon\Mvc\Model\MetadataInterface $modelsMetadata
 * @property \Phalcon\Mvc\Model\Transaction\Manager|\Phalcon\Mvc\Model\Transaction\ManagerInterface $transactionManager
 * @property \Phalcon\Assets\Manager $assets
 * @property \Phalcon\Di|\Phalcon\Di\DiInterface $di
 * @property \Phalcon\Session\Bag|\Phalcon\Session\BagInterface $persistent
 * @property \Phalcon\Mvc\View|\Phalcon\Mvc\ViewInterface $view
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Injectable) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Injectable, phalcon, di_injectable, phalcon_di_injectable_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Dependency Injector
	 *
	 * @var DiInterface
	 */
	zend_declare_property_null(phalcon_di_injectable_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Events Manager
	 *
	 * @var \Phalcon\Events\ManagerInterface
	 */
	zend_declare_property_null(phalcon_di_injectable_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_di_injectable_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_di_injectable_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Magic method __get
 */
PHP_METHOD(Phalcon_Di_Injectable, __get) {

	zval _8$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *propertyName_param = NULL, container, service, _0, _6, _2$$4, _3$$4, _5$$4, _7$$7, _9$$7, _10$$7;
	zval propertyName, _11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&propertyName);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_8$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &propertyName_param);

	if (UNEXPECTED(Z_TYPE_P(propertyName_param) != IS_STRING && Z_TYPE_P(propertyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'propertyName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(propertyName_param) == IS_STRING)) {
		zephir_get_strval(&propertyName, propertyName_param);
	} else {
		ZEPHIR_INIT_VAR(&propertyName);
		ZVAL_EMPTY_STRING(&propertyName);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_1, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_di_exception_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "internal services");
			ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_di_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 5, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "phalcon/Di/Injectable.zep", 81 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&_6, &container, "has", NULL, 0, &propertyName);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZEPHIR_CALL_METHOD(&service, &container, "getshared", NULL, 0, &propertyName);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, &propertyName, &service TSRMLS_CC);
		RETURN_CCTOR(&service);
	}
	if (ZEPHIR_IS_STRING(&propertyName, "di")) {
		zephir_update_property_zval(this_ptr, SL("di"), &container);
		RETURN_CCTOR(&container);
	}
	if (ZEPHIR_IS_STRING(&propertyName, "persistent")) {
		ZEPHIR_INIT_VAR(&_8$$7);
		zephir_create_array(&_8$$7, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$7);
		zephir_get_class(&_9$$7, this_ptr, 0 TSRMLS_CC);
		zephir_array_fast_append(&_8$$7, &_9$$7);
		ZEPHIR_INIT_NVAR(&_9$$7);
		ZVAL_STRING(&_9$$7, "sessionBag");
		ZEPHIR_CALL_METHOD(&_7$$7, &container, "get", NULL, 0, &_9$$7, &_8$$7);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("persistent"), &_7$$7);
		ZEPHIR_OBS_VAR(&_10$$7);
		zephir_read_property(&_10$$7, this_ptr, SL("persistent"), PH_NOISY_CC);
		RETURN_CCTOR(&_10$$7);
	}
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_SV(&_11, "Access to undefined property ", &propertyName);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 6, &_11);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Di_Injectable, getDI) {

	zval container, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_1, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&container);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Di_Injectable, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "eventsManager");

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Di_Injectable, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Sets the event manager
 */
PHP_METHOD(Phalcon_Di_Injectable, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("eventsManager"), eventsManager);

}

