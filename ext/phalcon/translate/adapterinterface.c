
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Phalcon\Translate\AdapterInterface
 *
 * Interface for Phalcon\Translate adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Translate, AdapterInterface, phalcon, translate_adapterinterface, phalcon_translate_adapterinterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Translate\Adapter\NativeArray constructor
 *
 * @param array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_AdapterInterface, __construct);

/**
 * Returns the translation string of the given key
 *
 * @param	string translateKey
 * @param	array placeholders
 * @return	string
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_AdapterInterface, t);

/**
 * Returns the translation related to the given key
 *
 * @param	string index
 * @param	array placeholders
 * @return	string
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_AdapterInterface, query);

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param 	string index
 * @return	bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_AdapterInterface, exists);

