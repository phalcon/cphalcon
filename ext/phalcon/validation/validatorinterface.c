
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

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
 * @param Phalcon\Validator validator
 * @param string attribute
 * @return Phalcon\Validation\Message\Group
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_ValidatorInterface, validate);

