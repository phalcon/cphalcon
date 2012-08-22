
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

/** New */
#define PHALCON_NEW_STD(object) PHALCON_ALLOC_ZVAL(object); object_init(object)
#define PHALCON_NEW(object, class) PHALCON_ALLOC_ZVAL(object); object_init_ex(object, class)

/** Class Constants */
#define PHALCON_GET_CLASS_CONSTANT(var, class_entry, name) PHALCON_VAR_INIT(var); phalcon_get_class_constant(var, class_entry, name, strlen(name) TSRMLS_CC)

extern void phalcon_get_class(zval *result, zval *object TSRMLS_DC);

extern zend_class_entry *phalcon_fetch_class(zval *class_name TSRMLS_DC);

extern int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, int constant_length TSRMLS_DC);

extern int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC);
extern int phalcon_is_instance_of(zval *object, char *class_name, int class_length TSRMLS_DC);
extern int phalcon_clone(zval *destiny, zval *obj TSRMLS_DC);

extern int phalcon_method_exists(zval *object, zval *method_name TSRMLS_DC);
extern int phalcon_method_exists_ex(zval *object, char *method_name, int method_len TSRMLS_DC);

extern int phalcon_isset_property(zval *object, char *property_name, int property_length TSRMLS_DC);
extern int phalcon_isset_property_zval(zval *object, zval *property TSRMLS_DC);

extern int phalcon_read_property(zval **result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC);
extern int phalcon_read_property_zval(zval **result, zval *object, zval *property, int silent TSRMLS_DC);

extern int phalcon_update_property_long(zval *obj, char *property_name, int property_length, long value TSRMLS_DC);
extern int phalcon_update_property_string(zval *obj, char *property_name, int property_length, char *value TSRMLS_DC);
extern int phalcon_update_property_bool(zval *obj, char *property_name, int property_length, int value TSRMLS_DC);
extern int phalcon_update_property_null(zval *obj, char *property_name, int property_length TSRMLS_DC);
extern int phalcon_update_property_zval(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC);

extern int phalcon_update_property_zval_zval(zval *obj, zval *property, zval *value TSRMLS_DC);

/** Static properties **/
extern int phalcon_read_static_property(zval **result, char *class_name, int class_length, char *property_name, int property_length TSRMLS_DC);
extern int phalcon_update_static_property(char *class_name, int class_length, char *name, int name_length, zval *value TSRMLS_DC);
