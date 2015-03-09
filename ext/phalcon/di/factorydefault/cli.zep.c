
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
#include "kernel/array.h"
#include "kernel/object.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Di\FactoryDefault\CLI
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault_Cli) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Di\\FactoryDefault, Cli, phalcon, di_factorydefault_cli, phalcon_di_factorydefault_ce, phalcon_di_factorydefault_cli_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Di\FactoryDefault\CLI constructor
 */
PHP_METHOD(Phalcon_Di_FactoryDefault_Cli, __construct) {

	zval *_2 = NULL, *_3 = NULL, *_4 = NULL, _6 = zval_used_for_init;
	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factorydefault_cli_ce, this_ptr, "__construct", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 13);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Phalcon\\CLI\\Router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("router"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\CLI\\Dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("dispatcher"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\Manager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\Metadata\\Memory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsMetadata"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "filter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Filter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4, &_6);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("filter"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "escaper", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Escaper", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4, &_6);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("escaper"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "annotations", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Annotations\\Adapter\\Memory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4, &_6);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("annotations"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "security", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Security", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4, &_6);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("security"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "eventsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Events\\Manage", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4, &_6);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("eventsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "transactionManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\Transaction\\Manager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_5, _3, _4, &_6);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("transactionManager"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_services"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

