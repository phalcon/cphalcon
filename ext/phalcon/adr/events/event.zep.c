
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
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * The ADR event vocabulary, fired through the native events manager.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Events_Event)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Events, Event, phalcon, adr_events_event, phalcon_adr_events_event_method_entry, 0);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_adr_events_event_ce, SL("ADR_AFTER_EXECUTE_ACTION"), "adr:afterExecuteAction");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_adr_events_event_ce, SL("ADR_BEFORE_EXECUTE_ACTION"), "adr:beforeExecuteAction");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_adr_events_event_ce, SL("APPLICATION_AFTER_HANDLE"), "application:afterHandle");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_adr_events_event_ce, SL("APPLICATION_BEFORE_HANDLE"), "application:beforeHandle");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_adr_events_event_ce, SL("PIPELINE_AFTER_DISPATCH"), "pipeline:afterDispatch");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_adr_events_event_ce, SL("PIPELINE_BEFORE_DISPATCH"), "pipeline:beforeDispatch");

	return SUCCESS;
}

/**
 * Instantiation not allowed.
 */
PHP_METHOD(Phalcon_ADR_Events_Event, __construct)
{

}

