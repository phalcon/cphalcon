
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

#include "translate/adapterinterface.h"

#include "kernel/main.h"

zend_class_entry *phalcon_translate_adapterinterface_ce;

static const zend_function_entry phalcon_translate_adapterinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, query, arginfo_phalcon_translate_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, exists, arginfo_phalcon_translate_adapterinterface_exists)
	PHP_FE_END
};

/**
 * Phalcon\Translate\AdapterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Translate_AdapterInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Translate, AdapterInterface, translate_adapterinterface, phalcon_translate_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the translation string of the given key
 *
 * @param string $translateKey
 * @param array $placeholders
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Translate_AdapterInterface, _);

/**
 * Returns the translation related to the given key
 *
 * @param string $index
 * @param array $placeholders
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Translate_AdapterInterface, query);

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param 	string $index
 * @return bool
 */
PHALCON_DOC_METHOD(Phalcon_Translate_AdapterInterface, exists);
