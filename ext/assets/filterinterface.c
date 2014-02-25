
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

#include "assets/filterinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_assets_filterinterface_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_filterinterface_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_assets_filterinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Assets_FilterInterface, filter, arginfo_phalcon_assets_filterinterface_filter)
	PHP_FE_END
};

/**
 * Phalcon\Assets\FilterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_FilterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Assets, FilterInterface, assets_filterinterface, phalcon_assets_filterinterface_method_entry);

	return SUCCESS;
}

/**
 * Filters the content returning a string with the filtered content
 *
 * @param string $content
 * @return $content
 */
PHALCON_DOC_METHOD(Phalcon_Assets_FilterInterface, filter);
