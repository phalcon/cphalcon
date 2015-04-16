
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
 * @param string key
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, isSetOption);

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't been set
 *
 * @param string key
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, getOption);

/**
 * Executes the validation
 *
 * @param Phalcon\Validation validator
 * @param string attribute
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, validate);

