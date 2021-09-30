
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
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Trait EventsAwareTrait
 *
 * @package Phalcon\Events\Traits
 *
 * @property ?ManagerInterface $eventsManager
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_AbstractEventsAware)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, AbstractEventsAware, phalcon, events_abstracteventsaware, phalcon_events_abstracteventsaware_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_events_abstracteventsaware_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Returns the internal event manager
 *
 * @return ManagerInterface|null
 */
PHP_METHOD(Phalcon_Events_AbstractEventsAware, getEventsManager)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 *
 * @param ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Events_AbstractEventsAware, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);


	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

/**
 * Helper method to fire an event
 *
 * @param string     $eventName
 * @param mixed|null $data
 * @param bool       $cancellable
 *
 * @return mixed|bool
 */
PHP_METHOD(Phalcon_Events_AbstractEventsAware, fireManagerEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancellable;
	zval *eventName_param = NULL, *data = NULL, data_sub, *cancellable_param = NULL, __$null, _0, _1$$3, _2$$3;
	zval eventName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &eventName_param, &data, &cancellable_param);
	zephir_get_strval(&eventName, eventName_param);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancellable_param) {
		cancellable = 1;
	} else {
		cancellable = zephir_get_boolval(cancellable_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		if (cancellable) {
			ZVAL_BOOL(&_2$$3, 1);
		} else {
			ZVAL_BOOL(&_2$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "fire", NULL, 0, &eventName, this_ptr, data, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

