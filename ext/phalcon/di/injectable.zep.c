
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Di\Injectable
 *
 * This class allows to access services in the services container by just only accessing a public property
 * with the same name of a registered service
 *
 * @property \Phalcon\Mvc\Dispatcher|\Phalcon\Mvc\DispatcherInterface $dispatcher;
 * @property \Phalcon\Mvc\Router|\Phalcon\Mvc\RouterInterface $router
 * @property \Phalcon\Mvc\Url|\Phalcon\Mvc\UrlInterface $url
 * @property \Phalcon\Http\Request|\Phalcon\HTTP\RequestInterface $request
 * @property \Phalcon\Http\Response|\Phalcon\HTTP\ResponseInterface $response
 * @property \Phalcon\Http\Response\Cookies|\Phalcon\Http\Response\CookiesInterface $cookies
 * @property \Phalcon\Filter|\Phalcon\FilterInterface $filter
 * @property \Phalcon\Flash\Direct $flash
 * @property \Phalcon\Flash\Session $flashSession
 * @property \Phalcon\Session\Adapter\Files|\Phalcon\Session\Adapter|\Phalcon\Session\AdapterInterface $session
 * @property \Phalcon\Events\Manager $eventsManager
 * @property \Phalcon\Db\AdapterInterface $db
 * @property \Phalcon\Security $security
 * @property \Phalcon\Crypt $crypt
 * @property \Phalcon\Tag $tag
 * @property \Phalcon\Escaper|\Phalcon\EscaperInterface $escaper
 * @property \Phalcon\Annotations\Adapter\Memory|\Phalcon\Annotations\Adapter $annotations
 * @property \Phalcon\Mvc\Model\Manager|\Phalcon\Mvc\Model\ManagerInterface $modelsManager
 * @property \Phalcon\Mvc\Model\MetaData\Memory|\Phalcon\Mvc\Model\MetadataInterface $modelsMetadata
 * @property \Phalcon\Mvc\Model\Transaction\Manager $transactionManager
 * @property \Phalcon\Assets\Manager $assets
 * @property \Phalcon\DI|\Phalcon\DiInterface $di
 * @property \Phalcon\Session\Bag $persistent
 * @property \Phalcon\Mvc\View|\Phalcon\Mvc\ViewInterface $view
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Injectable) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Injectable, phalcon, di_injectable, phalcon_di_injectable_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Dependency Injector
	 *
	 * @var \Phalcon\DiInterface
	 */
	zend_declare_property_null(phalcon_di_injectable_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Events Manager
	 *
	 * @var \Phalcon\Events\ManagerInterface
	 */
	zend_declare_property_null(phalcon_di_injectable_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_di_injectable_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_di_injectable_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Di_Injectable, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Di_Injectable, getDI) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
		zephir_check_call_status();
	}
	RETURN_CCTOR(dependencyInjector);

}

/**
 * Sets the event manager
 */
PHP_METHOD(Phalcon_Di_Injectable, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Di_Injectable, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Magic method __get
 */
PHP_METHOD(Phalcon_Di_Injectable, __get) {

	zval *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *propertyName_param = NULL, *dependencyInjector = NULL, *service = NULL, *persistent = NULL, *_0, *_2 = NULL, *_3 = NULL, *_5 = NULL;
	zval *propertyName = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &propertyName_param);

	if (unlikely(Z_TYPE_P(propertyName_param) != IS_STRING && Z_TYPE_P(propertyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'propertyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(propertyName_param) == IS_STRING)) {
		zephir_get_strval(propertyName, propertyName_param);
	} else {
		ZEPHIR_INIT_VAR(propertyName);
		ZVAL_EMPTY_STRING(propertyName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1, 147);
		zephir_check_call_status();
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "A dependency injection object is required to access the application services", "phalcon/di/injectable.zep", 127);
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&_2, dependencyInjector, "has", NULL, 0, propertyName);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_CALL_METHOD(&service, dependencyInjector, "getshared", NULL, 0, propertyName);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, propertyName, service TSRMLS_CC);
		RETURN_CCTOR(service);
	}
	if (ZEPHIR_IS_STRING(propertyName, "di")) {
		zephir_update_property_zval(this_ptr, SL("di"), dependencyInjector TSRMLS_CC);
		RETURN_CCTOR(dependencyInjector);
	}
	if (ZEPHIR_IS_STRING(propertyName, "persistent")) {
		ZEPHIR_INIT_VAR(_4);
		zephir_create_array(_4, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		zephir_get_class(_5, this_ptr, 0 TSRMLS_CC);
		zephir_array_fast_append(_4, _5);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "sessionBag", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, dependencyInjector, "get", NULL, 0, _5, _4);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(persistent, _3);
		zephir_update_property_zval(this_ptr, SL("persistent"), persistent TSRMLS_CC);
		RETURN_CCTOR(persistent);
	}
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "Access to undefined property ", propertyName);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 148, _6);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

