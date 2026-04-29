
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
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Controller
 *
 * Every application controller should extend this class that encapsulates all
 * the controller functionality
 *
 * The controllers provide the “flow” between models and views. Controllers are
 * responsible for processing the incoming requests from the web browser,
 * interrogating the models for data, and passing that data on to the views for
 * presentation.
 *
 *```php
 * <?php
 *
 * class PeopleController extends \Phalcon\Mvc\Controller
 * {
 *     // This action will be executed by default
 *     public function indexAction()
 *     {
 *
 *     }
 *
 *     public function findAction()
 *     {
 *
 *     }
 *
 *     public function saveAction()
 *     {
 *         // Forwards flow to the index action
 *         return $this->dispatcher->forward(
 *             [
 *                 "controller" => "people",
 *                 "action"     => "index",
 *             ]
 *         );
 *     }
 * }
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Controller)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Controller, phalcon, mvc_controller, phalcon_di_injectable_ce, phalcon_mvc_controller_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_controller_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_mvc_controller_ce, 1, phalcon_mvc_controllerinterface_ce);
	zend_class_implements(phalcon_mvc_controller_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Controller constructor
 */
PHP_METHOD(Phalcon_Mvc_Controller, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the internal event manager
 *
 * @return ManagerInterface|null
 */
PHP_METHOD(Phalcon_Mvc_Controller, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 *
 * @param ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Controller, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
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
PHP_METHOD(Phalcon_Mvc_Controller, fireManagerEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancellable;
	zval eventName_zv, *data = NULL, data_sub, *cancellable_param = NULL, __$null, _0, _1$$3, _2$$3;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cancellable_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancellable_param) {
		cancellable = 1;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		if (cancellable) {
			ZVAL_BOOL(&_2$$3, 1);
		} else {
			ZVAL_BOOL(&_2$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "fire", NULL, 0, &eventName_zv, this_ptr, data, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

