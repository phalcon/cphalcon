
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_AdapterInterface, exists);

