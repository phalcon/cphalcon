
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
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */
ZEPHIR_INIT_CLASS(Phalcon_Container_Provider_Cli)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Container\\Provider, Cli, phalcon, container_provider_cli, phalcon_container_provider_cli_method_entry, 0);

	zend_class_implements(phalcon_container_provider_cli_ce, 1, phalcon_contracts_container_service_provider_ce);
	return SUCCESS;
}

/**
 * Provider for commonly used CLI applications
 *
 * @param Collection $services
 *
 * @return void
 */
PHP_METHOD(Phalcon_Container_Provider_Cli, provide)
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
	ZVAL_STRING(&_0, "Phalcon\\Cli\\DispatcherInterface");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Cli\\Dispatcher");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Cli\\DispatcherInterface");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "dispatcher");
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
	ZVAL_STRING(&_0, "Phalcon\\Events\\ManagerInterface");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Events\\Manager");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Events\\ManagerInterface");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "eventsManager");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_10__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Filter\\FilterInterface");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Filter\\FilterInterface");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "filter");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\ManagerInterface");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Model\\Manager");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\ManagerInterface");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\MetaDataInterface");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Model\\MetaData\\Memory");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\MetaDataInterface");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "modelsMetadata");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Cli\\RouterInterface");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Cli\\Router");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Cli\\RouterInterface");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "router");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Model\\Transaction\\Manager");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface");
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "transactionManager");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, phalcon_11__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Auth\\Access\\AccessLocator");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Annotations\\Adapter\\Memory");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Annotations\\Adapter\\Memory");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Annotations\\Adapter\\Memory");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "annotationsMemory");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Support\\HelperFactory");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Support\\HelperFactory");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Support\\HelperFactory");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "helper");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Contracts\\Encryption\\Security\\Security");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Encryption\\Security");
	ZEPHIR_CALL_METHOD(NULL, services, "bind", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Contracts\\Encryption\\Security\\Security");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "security");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Storage\\SerializerFactory");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Storage\\SerializerFactory");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Storage\\SerializerFactory");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "storageSerializer");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Support\\Settings");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Support\\Settings");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Support\\Settings");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "settings");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Html\\TagFactory");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Html\\TagFactory");
	ZEPHIR_CALL_METHOD(NULL, services, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Html\\TagFactory");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "tag");
	ZEPHIR_CALL_METHOD(NULL, services, "setalias", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

