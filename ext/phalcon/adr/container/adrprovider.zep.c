
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
 * Registers the ADR seams in the container; concretes autowire.
 *
 * Used instead of `Phalcon\Container\Provider\Web` for ADR applications. It
 * shares the short aliases (`request`/`response`/`router`/`eventsManager`) but
 * binds the ADR contracts behind them.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Container_AdrProvider)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Container, AdrProvider, phalcon, adr_container_adrprovider, phalcon_adr_container_adrprovider_method_entry, 0);

	zend_class_implements(phalcon_adr_container_adrprovider_ce, 1, phalcon_contracts_container_service_provider_ce);
	return SUCCESS;
}

/**
 * @param Collection $services
 *
 * @return void
 */
PHP_METHOD(Phalcon_ADR_Container_AdrProvider, provide)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services, services_sub, _0, _1, _2, _3;

	ZVAL_UNDEF(&services_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(services, phalcon_contracts_container_service_collection_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &services);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Contracts\\Events\\Manager");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Events\\Manager");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Contracts\\Events\\Manager");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "eventsManager");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Contracts\\Http\\AttributeRequest");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Http\\Request");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Contracts\\Http\\AttributeRequest");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Http\\ResponseInterface");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Http\\Response");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Http\\ResponseInterface");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "response");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Html\\Escaper\\EscaperInterface");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\Escaper");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Html\\Escaper\\EscaperInterface");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "escaper");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Html\\TagFactory");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Html\\TagFactory");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Html\\TagFactory");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tag");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_4__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\Logger\\Logger");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\ADR\\Responder\\Responder");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\ADR\\Responder\\JsonResponder");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Contracts\\ADR\\Responder\\Responder");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "responder");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, phalcon_5__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Contracts\\ADR\\Dispatcher");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Contracts\\ADR\\Dispatcher");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "dispatcher");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Contracts\\ADR\\Router\\Router");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\ADR\\Router\\Router");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Contracts\\ADR\\Router\\Router");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "router");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Contracts\\ADR\\Emitter\\Emitter");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\ADR\\Emitter\\SapiEmitter");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Contracts\\ADR\\Emitter\\Emitter");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "emitter");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

