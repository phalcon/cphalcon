
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

/** Reads properties */
#define PHALCON_READ_PROPERTY_NOISY(result, object, property_name, property_length) PHALCON_VAR_INIT(result); phalcon_read_property(result, object, property_name, property_length, PHALCON_NOISY_FETCH TSRMLS_CC);
#define PHALCON_READ_PROPERTY_SILENT(result, object, property_name, property_length) PHALCON_VAR_INIT(result); phalcon_read_property(result, object, property_name, property_length, PHALCON_SILENT_FETCH TSRMLS_CC);

#define PHALCON_UPDATE_PROPERTY_CPY(object, property_name, value) {\
    zval *copy;\
    ALLOC_ZVAL(copy);\
    ZVAL_ZVAL(copy, value, 1, 0);\
    phalcon_update_property_zval_cpy(object, property_name, strlen(property_name), copy TSRMLS_CC);\
  }

/** New */
#define PHALCON_NEW_STD(object) PHALCON_ALLOC_ZVAL(object); object_init(object)
#define PHALCON_NEW(object, class) PHALCON_ALLOC_ZVAL(object); object_init_ex(object, class)


/** Instance of */
#define PHALCON_INSTANCE_OF(result, var, class) if(Z_TYPE_P(var)!=IS_OBJECT){\
      zend_error(E_ERROR, "instanceof expects an object instance, constant given");\
    } else {\
      PHALCON_RESULT_INIT(result);\
      ZVAL_BOOL(result, instanceof_function(Z_OBJCE_P(var), class TSRMLS_CC));\
    }


extern int phalcon_instance_of(zval *result, const zval *object, const zend_class_entry *ce TSRMLS_DC);
extern int phalcon_class_exists(zval *return_value, zval *class_name_zval, zval *autoload_zval TSRMLS_DC);
extern int phalcon_clone(zval **dst, zval *obj TSRMLS_DC);

extern int phalcon_method_exists(zval *object, zval *method_name TSRMLS_DC);
extern int phalcon_method_exists_ex(zval *object, char *method_name, int method_len TSRMLS_DC);

extern int phalcon_isset_property(zval *object, char *property_name, int property_length TSRMLS_DC);
extern int phalcon_isset_property_zval(zval *object, zval *property TSRMLS_DC);

extern int phalcon_read_property(zval *result, zval *object, char *property_name, int property_length, int silent TSRMLS_DC);
extern int phalcon_read_property_zval(zval *result, zval *object, zval *property, int silent TSRMLS_DC);

extern int phalcon_update_property_long(zval *obj, char *property_name, int property_length, long value TSRMLS_DC);
extern int phalcon_update_property_string(zval *obj, char *property_name, int property_length, char *value TSRMLS_DC);
extern int phalcon_update_property_zval(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC);
extern int phalcon_update_property_zval_cpy(zval *obj, char *property_name, int property_length, zval *value TSRMLS_DC);

