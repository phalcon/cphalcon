¡
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"

#include "Zend/zend_API.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_execute.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"

#include "kernel/experimental/object.h"

/*zval *zephir_std_read_property(zval *object, zval *member, int type TSRMLS_DC)
{
	zend_object *zobj;
	zval *tmp_member = NULL;
	zval **retval;
	zval *rv = NULL;
	zend_property_info *property_info;
	int silent;

	silent = (type == BP_VAR_IS);
	zobj = Z_OBJ_P(object);

 	if (Z_TYPE_P(member) != IS_STRING) {
 		ALLOC_ZVAL(tmp_member);
		*tmp_member = *member;
		INIT_PZVAL(tmp_member);
		zval_copy_ctor(tmp_member);
		convert_to_string(tmp_member);
		member = tmp_member;
	}

	property_info = zend_get_property_info(zobj->ce, member, (zobj->ce->__get != NULL) TSRMLS_CC);

	if (!property_info || zend_hash_quick_find(zobj->properties, property_info->name, property_info->name_length+1, property_info->h, (void **) &retval) == FAILURE) {
		zend_guard *guard = NULL;

		if (zobj->ce->__get &&
		    zend_get_property_guard(zobj, property_info, member, &guard) == SUCCESS &&
		    !guard->in_get) {
			Z_ADDREF_P(object);
			if (PZVAL_IS_REF(object)) {
				SEPARATE_ZVAL(&object);
			}
			guard->in_get = 1;
			rv = zend_std_call_getter(object, member TSRMLS_CC);
			guard->in_get = 0;

			if (rv) {
				retval = &rv;
				if (!Z_ISREF_P(rv) &&
				    (type == BP_VAR_W || type == BP_VAR_RW  || type == BP_VAR_UNSET)) {
					if (Z_REFCOUNT_P(rv) > 0) {
						zval *tmp = rv;

						ALLOC_ZVAL(rv);
						*rv = *tmp;
						zval_copy_ctor(rv);
						Z_UNSET_ISREF_P(rv);
						Z_SET_REFCOUNT_P(rv, 0);
					}
					if (Z_TYPE_P(rv) != IS_OBJECT) {
						zend_error(E_NOTICE, "Indirect modification of overloaded property %s::$%s has no effect", zobj->ce->name, Z_STRVAL_P(member));
					}
				}
			} else {
				retval = &EG(uninitialized_zval_ptr);
			}
			if (EXPECTED(*retval != object)) {
				zval_ptr_dtor(&object);
			} else {
				Z_DELREF_P(object);
			}
		} else {
			if (zobj->ce->__get && guard && guard->in_get == 1) {
				if (Z_STRVAL_P(member)[0] == '\0') {
					if (Z_STRLEN_P(member) == 0) {
						zend_error(E_ERROR, "Cannot access empty property");
					} else {
						zend_error(E_ERROR, "Cannot access property started with '\\0'");
					}
				}
			}
			if (!silent) {
				zend_error(E_NOTICE,"Undefined property: %s::$%s", zobj->ce->name, Z_STRVAL_P(member));
			}
			retval = &EG(uninitialized_zval_ptr);
		}
	}
	if (tmp_member) {
		Z_ADDREF_PP(retval);
		zval_ptr_dtor(&tmp_member);
		Z_DELREF_PP(retval);
	}
	return *retval;
}*/
