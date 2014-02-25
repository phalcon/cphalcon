
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

	zval *_1 = NULL, *_2, *_3;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factorydefault_ce, this_ptr, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 29);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "router", 0);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Router", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("router"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "dispatcher", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Dispatcher", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("dispatcher"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "url", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Url", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("url"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "modelsManager", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\Manager", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("modelsManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "modelsMetadata", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\MetaData\\Memory", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("modelsMetadata"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "response", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Http\\Response", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("response"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "cookies", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Http\\Response\\Cookies", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("cookies"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "request", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Http\\Request", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("request"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "filter", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Filter", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("filter"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "escaper", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Escaper", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("escaper"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "security", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Security", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("security"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "crypt", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Crypt", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("crypt"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "annotations", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Annotations\\Adapter\\Memory", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("annotations"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "flash", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Flash\\Direct", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("flash"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "flashSession", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Flash\\Session", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("flashSession"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "tag", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Tag", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("tag"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "session", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Session\\Adapter\\Files", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("session"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "sessionBag", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Session\\Bag", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("sessionBag"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "eventsManager", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Events\\Manager", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("eventsManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "transactions", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\Transaction\\Manager", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("transactionManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "assets", 0);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Assets\\Manager", 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("assets"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_services"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

