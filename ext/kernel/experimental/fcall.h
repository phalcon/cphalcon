
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

extern int phalcon_exp_call_user_method(zend_class_entry *ce, zval **object_pp, zval *function_name, zval *retval_ptr, zend_uint param_count, zval *params[], unsigned long method_key TSRMLS_DC);
int phalcon_exp_call_user_method_ex(zend_class_entry *ce, zval **object_pp, zval *method_name, zval **retval_ptr_ptr, zend_uint param_count, zval **params[], unsigned long method_key TSRMLS_DC);
int phalcon_exp_call_method(zend_fcall_info *fci, zend_class_entry *ce, char *key, unsigned int key_length, unsigned long hash_key, unsigned long method_key TSRMLS_DC);