
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

/** Class Retrieving/Checking */
extern int phalcon_class_exists(zval *class_name TSRMLS_DC);
extern void phalcon_get_class(zval *result, zval *object TSRMLS_DC);
extern zend_class_entry *phalcon_fetch_class(zval *class_name TSRMLS_DC);

/** Class constants */
extern int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, int constant_length TSRMLS_DC);

/** Cloning/Instance of*/
extern int phalcon_clone(zval *destiny, zval *obj TSRMLS_DC);
extern int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC);
extern int phalcon_is_instance_of(zval *object, char *class_name, unsigned int class_length TSRMLS_DC);

/** Method exists */
extern int phalcon_method_exists(zval *object, zval *method_name TSRMLS_DC);
extern int phalcon_method_exists_ex(zval *object, char *method_name, int method_len TSRMLS_DC);

/** Isset properties */
extern int phalcon_isset_property(zval *object, char *property_name, int property_length TSRMLS_DC);
extern int phalcon_isset_property_zval(zval *object, zval *property TSRMLS_DC);

/** Reading properties */
extern int phalcon_read_property(zval **result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC);
extern int phalcon_read_property_zval(zval **result, zval *object, zval *property, int silent TSRMLS_DC);
extern int phalcon_return_property(zval *return_value, zval *object, char *property_name, int property_length TSRMLS_DC);

/** Updating properties */
extern int phalcon_update_property_long(zval *obj, char *property_name, int property_length, long value TSRMLS_DC);
extern int phalcon_update_property_string(zval *obj, char *property_name, int property_length, char *value TSRMLS_DC);
extern int phalcon_update_property_bool(zval *obj, char *property_name, int property_length, int value TSRMLS_DC);
extern int phalcon_update_property_null(zval *obj, char *property_name, int property_length TSRMLS_DC);
extern int phalcon_update_property_zval(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC);
extern int phalcon_update_property_zval_zval(zval *obj, zval *property, zval *value TSRMLS_DC);
extern int phalcon_update_property_empty_array(zend_class_entry *ce, zval *object, char *property, unsigned int property_length TSRMLS_DC);

/** Static properties */
extern int phalcon_read_static_property(zval **result, char *class_name, int class_length, char *property_name, int property_length TSRMLS_DC);
extern int phalcon_update_static_property(char *class_name, int class_length, char *name, int name_length, zval *value TSRMLS_DC);

/** Create instances */
extern int phalcon_create_instance(zval *return_value, zval *class_name TSRMLS_DC);
extern int phalcon_create_instance_params(zval *return_value, zval *class_name, zval *params TSRMLS_DC);