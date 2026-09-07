
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
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */
/**
 * Holds the payload
 */
ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_Payload)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Domain\\Payload, Payload, phalcon, domain_payload_payload, phalcon_domain_payload_payload_method_entry, 0);

	/**
	 * Exception if any
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_domain_payload_payload_ce, SL("exception"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Throwable"));
	}

	/**
	 * Extra information
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("extras"), ZEND_ACC_PROTECTED);
	/**
	 * Input
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("input"), ZEND_ACC_PROTECTED);
	/**
	 * Messages
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("messages"), ZEND_ACC_PROTECTED);
	/**
	 * Output
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("output"), ZEND_ACC_PROTECTED);
	/**
	 * Status
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_domain_payload_payload_ce, SL("status"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_domain_payload_payload_ce, 1, phalcon_domain_payload_payloadinterface_ce);
	return SUCCESS;
}

/**
 * Gets the potential exception thrown in the domain layer
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getException)
{

	RETURN_MEMBER(getThis(), "exception");
}

/**
 * Extra information
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getExtras)
{

	RETURN_MEMBER(getThis(), "extras");
}

/**
 * Input
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getInput)
{

	RETURN_MEMBER(getThis(), "input");
}

/**
 * Messages
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getMessages)
{

	RETURN_MEMBER(getThis(), "messages");
}

/**
 * Output
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getOutput)
{

	RETURN_MEMBER(getThis(), "output");
}

/**
 * Status
 *
 * Status values are drawn from the `Status` vocabulary.
 *
 * @see Status
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, getStatus)
{

	RETURN_MEMBER(getThis(), "status");
}

/**
 * Sets an exception thrown in the domain
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setException)
{
	zval *exception, exception_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("exception", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &exception);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 676, exception);
	RETURN_THISW();
}

/**
 * Sets arbitrary extra domain information.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setExtras)
{
	zval *extras, extras_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extras_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extras", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(extras)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &extras);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 677, extras);
	RETURN_THISW();
}

/**
 * Sets the domain input.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setInput)
{
	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("input", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &input);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 678, input);
	RETURN_THISW();
}

/**
 * Sets the domain messages.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setMessages)
{
	zval *messages, messages_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(messages)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &messages);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 679, messages);
	RETURN_THISW();
}

/**
 * Sets the domain output.
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setOutput)
{
	zval *output, output_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&output_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("output", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(output)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &output);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 680, output);
	RETURN_THISW();
}

/**
 * Sets the payload status.
 *
 * Status values are drawn from the `Status` vocabulary.
 *
 * @see Status
 */
PHP_METHOD(Phalcon_Domain_Payload_Payload, setStatus)
{
	zval *status, status_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("status", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(status)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &status);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 681, status);
	RETURN_THISW();
}

