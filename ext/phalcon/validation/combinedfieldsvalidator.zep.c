
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


/**
 * Phalcon\Validation\CombinedFieldsValidator
 *
 * This is a base class for combined fields validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_CombinedFieldsValidator) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation, CombinedFieldsValidator, phalcon, validation_combinedfieldsvalidator, phalcon_validation_validator_ce, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

