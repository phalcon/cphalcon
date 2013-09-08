
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\DI\FactoryDefault
 *
 * This is a variant of the standard Phalcon\DI. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
ZEPHIR_INIT_CLASS(Phalcon_DI_FactoryDefault) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DI, phalcon, FactoryDefault, di_factorydefault, phalcon_di_ce, phalcon_di_factorydefault_method_entry, 0);


	return SUCCESS;

}

/**
 * Phalcon\DI\FactoryDefault constructor
 */
PHP_METHOD(Phalcon_DI_FactoryDefault, __construct) {

	zval *_0, *_1, *_2, *_3, *_4;
	zend_bool shared;

	ZEPHIR_MM_GROW();

	zephir_call_parent_noret(this_ptr, phalcon_di_factorydefault_ce, "__construct");
	shared = 1;
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "router", 1);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Router", 1);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("router"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "dispatcher", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Dispatcher", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("dispatcher"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "url", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Url", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("url"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "modelsManager", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\Manager", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("modelsManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "modelsMetadata", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\MetaData\\Memory", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("modelsMetadata"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "response", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Http\\Response", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("response"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "cookies", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Http\\Response\\Cookies", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("cookies"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "request", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Http\\Request", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("request"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "filter", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Filter", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("filter"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "escaper", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Escaper", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("escaper"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "security", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Security", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("security"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "crypt", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Crypt", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("crypt"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "annotations", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Annotations\\Adapter\\Memory", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("annotations"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "flash", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Flash\\Direct", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("flash"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "flashSession", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Flash\\Session", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("flashSession"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "tag", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Tag", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("tag"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "session", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Session\\Adapter\\Files", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("session"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "sessionBag", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Session\\Bag", 1);
	zephir_call_method_p2_noret(_1, "__construct", _2, _3);
	zephir_array_update_string(&_0, SS("sessionBag"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "eventsManager", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Events\\Manager", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("eventsManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "transactions", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Mvc\\Model\\Transaction\\Manager", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("transactionManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	object_init_ex(_1, phalcon_di_service_ce);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "assets", 1);
	ZEPHIR_INIT_BNVAR(_3);
	ZVAL_STRING(_3, "Phalcon\\Assets\\Manager", 1);
	ZEPHIR_INIT_BNVAR(_4);
	ZVAL_BOOL(_4, shared);
	zephir_call_method_p3_noret(_1, "__construct", _2, _3, _4);
	zephir_array_update_string(&_0, SS("assets"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_services"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

