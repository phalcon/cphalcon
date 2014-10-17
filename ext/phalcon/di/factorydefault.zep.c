
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
 * Phalcon\Di\FactoryDefault
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Di, FactoryDefault, phalcon, di_factorydefault, phalcon_di_ce, phalcon_di_factorydefault_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Di\FactoryDefault constructor
 */
PHP_METHOD(Phalcon_Di_FactoryDefault, __construct) {

	zval *_2 = NULL, *_3, *_4, _5 = zval_used_for_init;
	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factorydefault_ce, this_ptr, "__construct", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 29);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "router", 0);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Router", 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("router"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "dispatcher", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Dispatcher", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("dispatcher"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "url", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Url", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("url"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "modelsManager", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\Manager", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "modelsMetadata", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\MetaData\\Memory", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsMetadata"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "response", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Http\\Response", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("response"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "cookies", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Http\\Response\\Cookies", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("cookies"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "request", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Http\\Request", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("request"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "filter", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Filter", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("filter"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "escaper", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Escaper", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("escaper"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "security", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Security", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("security"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "crypt", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Crypt", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("crypt"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "annotations", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Annotations\\Adapter\\Memory", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("annotations"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "flash", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Flash\\Direct", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("flash"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "flashSession", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Flash\\Session", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("flashSession"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "tag", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Tag", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("tag"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "session", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Session\\Adapter\\Files", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("session"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "sessionBag", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Session\\Bag", 0);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("sessionBag"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "eventsManager", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Events\\Manager", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("eventsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "transactions", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\Transaction\\Manager", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("transactionManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "assets", 0);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Assets\\Manager", 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("assets"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_services"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

