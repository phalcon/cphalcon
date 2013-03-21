
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

extern zend_class_entry *phalcon_validation_validator_exclusionin_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator_ExclusionIn);

PHP_METHOD(Phalcon_Validation_Validator_ExclusionIn, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_exclusionin_validate, 0, 0, 2)
	ZEND_ARG_INFO(0, validator)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_validation_validator_exclusionin_method_entry){
	PHP_ME(Phalcon_Validation_Validator_ExclusionIn, validate, arginfo_phalcon_validation_validator_exclusionin_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

