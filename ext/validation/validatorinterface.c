
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

#include "validation/validatorinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_validation_validatorinterface_ce;

static const zend_function_entry phalcon_validation_validatorinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, isSetOption, arginfo_phalcon_validation_validatorinterface_issetoption)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, getOption, arginfo_phalcon_validation_validatorinterface_getoption)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, setOption, arginfo_phalcon_validation_validatorinterface_setoption)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, validate, arginfo_phalcon_validation_validatorinterface_validate)
	PHP_FE_END
};

/**
 * Phalcon\Validation\ValidatorInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_ValidatorInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Validation, ValidatorInterface, validation_validatorinterface, phalcon_validation_validatorinterface_method_entry);

	return SUCCESS;
}

/**
 * Checks if an option is defined
 *
 * @param string $key
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Validation_ValidatorInterface, isSetOption);

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't been set
 *
 * @param string $key
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Validation_ValidatorInterface, getOption);

/**
 * Sets the validator's option
 *
 * @param string $key
 * @param mixed $value
 */
PHALCON_DOC_METHOD(Phalcon_Validation_ValidatorInterface, setOption);

/**
 * Executes the validation
 *
 * @param Phalcon\Validator $validator
 * @param string $attribute
 * @return Phalcon\Validation\Message\Group
 */
PHALCON_DOC_METHOD(Phalcon_Validation_ValidatorInterface, validate);
