
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Validation\ValidatorInterface
 *
 * Interface for Phalcon\Validation\Validator
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_ValidatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Validation, ValidatorInterface, phalcon, validation_validatorinterface, phalcon_validation_validatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Checks if an option is defined
 *
 * @deprecated since 2.1.0
 * @see \Phalcon\Validation\Validator::hasOption()
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, isSetOption);

/**
 * Checks if an option is defined
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, hasOption);

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't set
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, getOption);

/**
 * Executes the validation
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, validate);

