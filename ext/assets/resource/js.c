
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

#include "assets/resource/js.h"
#include "assets/resource.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Assets\Resource\Js
 *
 * Represents Javascript resources
 */
zend_class_entry *phalcon_assets_resource_js_ce;

PHP_METHOD(Phalcon_Assets_Resource_Js, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_js___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_assets_resource_js_method_entry[] = {
	PHP_ME(Phalcon_Assets_Resource_Js, __construct, arginfo_phalcon_assets_resource_js___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

/**
 * Phalcon\Assets\Resource\Js initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Resource_Js){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Assets\\Resource, Js, assets_resource_js, phalcon_assets_resource_ce, phalcon_assets_resource_js_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Assets\Resource\Js
 *
 * @param string $path
 * @param boolean $local
 * @param boolean $filter
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Assets_Resource_Js, __construct){

	zval *path, *local = NULL, *filter = NULL, *attributes = NULL, *type;

	phalcon_fetch_params(0, 1, 3, &path, &local, &filter, &attributes);
	
	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_STRING(type, "js", 1);
	
	PHALCON_CALL_PARENTW(NULL,
		phalcon_assets_resource_js_ce, this_ptr, "__construct",
		type, path,
		(local ? local : PHALCON_GLOBAL(z_true)),
		(filter ? filter : PHALCON_GLOBAL(z_true)),
		(attributes ? attributes : PHALCON_GLOBAL(z_null))
	);
}
