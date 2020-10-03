/*
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_KERNEL_OBJECT_H
#define ZEPHIR_KERNEL_OBJECT_H

#include <php.h>
#include <Zend/zend.h>

#include "kernel/globals.h"
#include "kernel/main.h"

/* Working with scopes */
#if PHP_VERSION_ID >= 70100
# define zephir_get_scope(e) ((e) ? zend_get_executed_scope() : EG(fake_scope))
# define zephir_set_scope(s) EG(fake_scope) = (s)
#else
# define zephir_get_scope(e) EG(scope)
# define zephir_set_scope(s) EG(scope) = (s)
#endif

/** Class Retrieving/Checking */
int zephir_class_exists(zval *class_name, int autoload);
int zephir_interface_exists(zval *interface_name, int autoload);
void zephir_get_called_class(zval *return_value);
zend_class_entry *zephir_fetch_class(zval *class_name);
zend_class_entry *zephir_fetch_class_str_ex(const char *class_name, size_t length, int fetch_type);
void zephir_get_class(zval *result, zval *object, int lower);
void zephir_get_class_ns(zval *result, zval *object, int lower);
void zephir_get_ns_class(zval *result, zval *object, int lower);

/** Cloning/Instance of */
int zephir_clone(zval *destination, zval *obj);
int zephir_is_instance_of(zval *object, const char *class_name, unsigned int class_length);
int zephir_instance_of_ev(zval *object, const zend_class_entry *ce);
int zephir_zval_is_traversable(zval *object);

/** Method exists */
int zephir_method_exists(zval *object, const zval *method_name);

/** Isset properties */
int zephir_isset_property(zval *object, const char *property_name, unsigned int property_length);
int zephir_isset_property_zval(zval *object, const zval *property);

/** Reading properties */
int zephir_read_property_ex(zval *result, zval *object, const char *property_name, uint32_t property_length, int silent);
int zephir_read_property(zval *result, zval *object, const char *property_name, uint32_t property_length, int silent);
int zephir_read_property_zval(zval *result, zval *object, zval *property, int silent);
int zephir_return_property(zval *return_value, zval *object, char *property_name, unsigned int property_length);
int zephir_fetch_property(zval *result, zval *object, const char *property_name, uint32_t property_length, int silent);
int zephir_fetch_property_zval(zval *result, zval *object, zval *property, int silent);

/** Updating properties */
int zephir_update_property_zval_ex(zval *obj, const char *property_name, unsigned int property_length, zval *value);
int zephir_update_property_zval(zval *obj, const char *property_name, unsigned int property_length, zval *value);
int zephir_update_property_zval_zval(zval *obj, zval *property, zval *value);

/** Updating array properties */
int zephir_update_property_array(zval *object, const char *property, uint32_t property_length, const zval *index, zval *value);
int zephir_update_property_array_string(zval *object, char *property, unsigned int property_length, char *index, unsigned int index_length, zval *value);
int zephir_update_property_array_append(zval *object, char *property, unsigned int property_length, zval *value);
int zephir_update_property_array_multi(zval *object, const char *property, uint32_t property_length, zval *value, const char *types, int types_length, int types_count, ...);

/** Unset properties */
int zephir_unset_property(zval* object, const char* name);
int zephir_unset_property_array(zval *object, char *property, unsigned int property_length, zval *index);

/** Static properties */
int zephir_read_static_property_ce(zval *result, zend_class_entry *ce, const char *property, int len, int flags);
int zephir_update_static_property_ce(zend_class_entry *ce, const char *property, uint32_t len, zval *value);
int zephir_add_static_property_ce(zend_class_entry *ce, const char *property, uint32_t len, zval *value);
int zephir_sub_static_property_ce(zend_class_entry *ce, const char *property, uint32_t len, zval *value);
int zephir_update_static_property_array_multi_ce(zend_class_entry *ce, const char *property, uint32_t property_length, zval *value, const char *types, int types_length, int types_count, ...);

/** Create closures */
int zephir_create_closure_ex(zval *return_value, zval *this_ptr, zend_class_entry *ce, const char *method_name, uint32_t method_length);

/** Create instances */
int zephir_create_instance(zval *return_value, const zval *class_name);
int zephir_create_instance_params(zval *return_value, const zval *class_name, zval *params);

/** Increment/Decrement properties */
#define zephir_property_incr(object, property) zephir_property_incr_decr(object, property, 1)
#define zephir_property_decr(object, property) zephir_property_incr_decr(object, property, 0)
int zephir_property_incr_decr(zval *object, char *property_name, unsigned int property_length, unsigned int increment);

#define zephir_fetch_safe_class(destination, var) { \
		if (Z_TYPE_P(var) == IS_STRING) { \
			ZEPHIR_CPY_WRT(destination, var); \
		} else { \
			ZEPHIR_INIT_NVAR(destination); \
			ZVAL_STRING(destination, "<undefined class>"); \
		} \
	}

/** Methods */
int zephir_method_exists_ex(zval *object, const char *method_name, unsigned int method_len);

#endif
