
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"

/**
 * Phalcon\Assets\Resource\Css
 *
 * Represents CSS resources
 */


/**
 * Phalcon\Assets\Resource\Css initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Resource_Css){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Assets\\Resource, Css, assets_resource_css, "phalcon\\assets\\resource", phalcon_assets_resource_css_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Assets\Resource\Css
 *
 * @param string $path
 * @param boolean $local
 */
PHP_METHOD(Phalcon_Assets_Resource_Css, __construct){

	zval *path, *local = NULL, *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &path, &local);
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	}
	
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "css", 1);
	PHALCON_CALL_PARENT_PARAMS_3_NORETURN(this_ptr, "Phalcon\\Assets\\Resource\\Css", "__construct", type, path, local);
	
	PHALCON_MM_RESTORE();
}

