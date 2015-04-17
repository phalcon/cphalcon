
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Phalcon\Translate
 *
 * Translate component allows the creation of multi-language applications using
 * different adapters for translation lists.
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Translate, phalcon, translate, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

