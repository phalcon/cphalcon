
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

/** Class Retrieving/Checking */
extern int phalcon_class_exists(const zval *class_name, int autoload TSRMLS_DC);
extern void phalcon_get_class(zval *result, zval *object, int lower TSRMLS_DC);
extern void phalcon_get_class_ns(zval *result, zval *object, int lower TSRMLS_DC);
extern void phalcon_get_ns_class(zval *result, zval *object, int lower TSRMLS_DC);
extern void phalcon_get_called_class(zval *return_value TSRMLS_DC);
extern zend_class_entry *phalcon_fetch_class(const zval *class_name TSRMLS_DC);
zend_class_entry* phalcon_fetch_self_class(TSRMLS_D);
zend_class_entry* phalcon_fetch_parent_class(TSRMLS_D);
zend_class_entry* phalcon_fetch_static_class(TSRMLS_D);

#define PHALCON_GET_CLASS_CONSTANT(return_value, ce, const_name) \
	do { \
		if (FAILURE == phalcon_get_class_constant(return_value, ce, const_name, strlen(const_name)+1 TSRMLS_CC)) { \
			PHALCON_MM_RESTORE(); \
			return; \
		} \
	} while (0)

/** Class constants */
extern int phalcon_get_class_constant(zval *return_value, zend_class_entry *ce, char *constant_name, unsigned int constant_length TSRMLS_DC);

/** Cloning/Instance of*/
extern int phalcon_clone(zval *destiny, zval *obj TSRMLS_DC);
extern int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC);
extern int phalcon_is_instance_of(zval *object, const char *class_name, unsigned int class_length TSRMLS_DC);

/** Method exists */
extern int phalcon_method_exists(const zval *object, const zval *method_name TSRMLS_DC);
extern int phalcon_method_exists_ex(const zval *object, const char *method_name, unsigned int method_len TSRMLS_DC);
extern int phalcon_method_quick_exists_ex(const zval *object, const char *method_name, unsigned int method_len, unsigned long hash TSRMLS_DC);

/** Isset properties */
extern int phalcon_isset_property(zval *object, const char *property_name, unsigned int property_length TSRMLS_DC);
extern int phalcon_isset_property_quick(zval *object, const char *property_name, unsigned int property_length, unsigned long hash TSRMLS_DC);
extern int phalcon_isset_property_zval(zval *object, const zval *property TSRMLS_DC);

/** Reading properties */
int phalcon_read_property_this(zval **result, zval *object, char *property_name, unsigned int property_length, int silent TSRMLS_DC);
int phalcon_read_property_this_quick(zval **result, zval *object, char *property_name, unsigned int property_length, unsigned long key, int silent TSRMLS_DC);
zval** phalcon_fetch_nproperty_this(zval *object, char *property_name, unsigned int property_length, int silent TSRMLS_DC);
zval** phalcon_fetch_nproperty_this_quick(zval *object, char *property_name, unsigned int property_length, unsigned long key, int silent TSRMLS_DC);
zval** phalcon_fetch_property_this(zval *object, char *property_name, unsigned int property_length, int silent TSRMLS_DC);
zval** phalcon_fetch_property_this_quick(zval *object, char *property_name, unsigned int property_length, unsigned long key, int silent TSRMLS_DC);
int phalcon_read_property(zval **result, zval *object, char *property_name, unsigned int property_length, int silent TSRMLS_DC);
int phalcon_read_property_zval(zval **result, zval *object, zval *property, int silent TSRMLS_DC);
int phalcon_return_property(zval *return_value, zval *object, char *property_name, unsigned int property_length TSRMLS_DC);
int phalcon_return_property_quick(zval *return_value, zval *object, char *property_name, unsigned int property_length, unsigned long key TSRMLS_DC);

/** Updating properties */
extern int phalcon_update_property_this(zval *object, char *property_name, unsigned int property_length, zval *value TSRMLS_DC);
extern int phalcon_update_property_long(zval *obj, char *property_name, unsigned int property_length, long value TSRMLS_DC);
extern int phalcon_update_property_string(zval *object, char *property_name, unsigned int property_length, char *str, unsigned int str_length TSRMLS_DC);
extern int phalcon_update_property_bool(zval *obj, char *property_name, unsigned int property_length, int value TSRMLS_DC);
extern int phalcon_update_property_null(zval *obj, char *property_name, unsigned int property_length TSRMLS_DC);
extern int phalcon_update_property_zval(zval *obj, char *property_name, unsigned int property_length, zval *value TSRMLS_DC);
extern int phalcon_update_property_zval_zval(zval *obj, zval *property, zval *value TSRMLS_DC);
extern int phalcon_update_property_empty_array(zend_class_entry *ce, zval *object, char *property, unsigned int property_length TSRMLS_DC);

/** Updating array properties */
extern int phalcon_update_property_array(zval *object, char *property, unsigned int property_length, zval *index, zval *value TSRMLS_DC);
extern int phalcon_update_property_array_string(zval *object, char *property, unsigned int property_length, char *index, unsigned int index_length, zval *value TSRMLS_DC);
extern int phalcon_update_property_array_append(zval *object, char *property, unsigned int property_length, zval *value TSRMLS_DC);

/** Increment/Decrement properties */
extern int phalcon_property_incr(zval *object, char *property_name, unsigned int property_length TSRMLS_DC);
extern int phalcon_property_decr(zval *object, char *property_name, unsigned int property_length TSRMLS_DC);

/** Unset Array properties */
extern int phalcon_unset_property_array(zval *object, char *property, unsigned int property_length, zval *index TSRMLS_DC);

/** Static properties */
int phalcon_read_static_property(zval **result, const char *class_name, unsigned int class_length, char *property_name, unsigned int property_length TSRMLS_DC);
int phalcon_update_static_property_ce(zend_class_entry *ce, char *name, int len, zval *value TSRMLS_DC);
int phalcon_update_static_property(const char *class_name, unsigned int class_length, char *name, unsigned int name_length, zval *value TSRMLS_DC);
int phalcon_read_static_property_ce(zval **result, zend_class_entry *ce, char *property, int len TSRMLS_DC);
int phalcon_read_class_property(zval **result, int type, char *property, int len TSRMLS_DC);
zval* phalcon_fetch_static_property_ce(zend_class_entry *ce, char *property, int len TSRMLS_DC);

/** Create instances */
extern int phalcon_create_instance(zval *return_value, const zval *class_name TSRMLS_DC);
extern int phalcon_create_instance_params(zval *return_value, const zval *class_name, zval *params TSRMLS_DC);

