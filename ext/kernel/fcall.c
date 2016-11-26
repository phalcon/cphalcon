
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Zephir Team (http://www.zephir-lang.com)       |
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include <php.h>
#include "php_ext.h"

#include <Zend/zend_API.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_execute.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/extended/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

static const unsigned char tolower_map[256] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
	0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
	0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
	0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
	0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
	0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
	0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};

int zephir_has_constructor_ce(const zend_class_entry *ce)
{
	while (ce) {
		if (ce->constructor != NULL) {
			return 1;
		}
		ce = ce->parent;
	}
	return 0;
}

/**
 * Creates a unique key to cache the current method/function call address for the current scope
 */
static ulong zephir_make_fcall_info_key(char **result, size_t *length, const zend_class_entry *obj_ce, zephir_call_type type, zephir_fcall_info *info)
{
	const zend_class_entry *calling_scope;
	char *buf = NULL, *c;
	size_t l = 0, len = 0;
	const size_t ppzce_size = sizeof(zend_class_entry**);
	ulong hash = 5381;

#if PHP_VERSION_ID >= 70100
	calling_scope = zend_get_executed_scope();
#else
	calling_scope = EG(scope);
#endif
	*result = NULL;
	*length = 0;

	if (calling_scope && type == zephir_fcall_parent) {
		calling_scope = calling_scope->parent;
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}
	else if (type == zephir_fcall_static) {
#if PHP_VERSION_ID >= 70100
		calling_scope = zend_get_called_scope(EG(current_execute_data));
#else
		calling_scope = EG(current_execute_data)->called_scope;
#endif
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}

	if (
		    calling_scope
		 && obj_ce
		 && calling_scope != obj_ce
		 && !instanceof_function(obj_ce, calling_scope)
		 && !instanceof_function(calling_scope, obj_ce)
	) {
		calling_scope = NULL;
	}

	switch (info->type) {

		case ZEPHIR_FCALL_TYPE_FUNC:

			l   = (size_t)(info->func_length) + 1;
			c   = (char*) info->func_name;
			len = 2 * ppzce_size + l + 1;
			buf = emalloc(len);

			memcpy(buf,                  c,               l);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
			buf[len - 1] = '\0';
			break;

		case ZEPHIR_FCALL_TYPE_CLASS_SELF_METHOD:
		case ZEPHIR_FCALL_TYPE_CLASS_STATIC_METHOD:
		case ZEPHIR_FCALL_TYPE_CLASS_PARENT_METHOD:
			l   = (size_t)(info->func_length) + 2; /* reserve 1 char for fcall-type */
			c   = (char*) info->func_name;
			len = 2 * ppzce_size + l + 1;
			buf = emalloc(len);

			buf[0] = info->type;
			memcpy(buf + 1,              c,               l - 1);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
			buf[len - 1] = '\0';
			break;

		case ZEPHIR_FCALL_TYPE_CE_METHOD:
		case ZEPHIR_FCALL_TYPE_ZVAL_METHOD:
			l   = (size_t)(info->func_length) + 1;
			c   = (char*) info->func_name;
			len = 2 * ppzce_size + l + 1;
			buf = emalloc(len);

			memcpy(buf,                  c,               l);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
			buf[len - 1] = '\0';
			break;
	}

	if (EXPECTED(buf != NULL)) {
		size_t i;

		for (i = 0; i < l; ++i) {
			char c = buf[i];
			c = tolower_map[(unsigned char)c];
			buf[i] = c;
			hash   = (hash << 5) + hash + c;
		}

		for (i = l; i < len; ++i) {
			char c = buf[i];
			hash = (hash << 5) + hash + c;
		}
	}

	*result = buf;
	*length = len;
	return hash;
}

/**
 * Creates a unique key to cache the current method/function call address for the current scope
 */
static ulong zephir_make_fcall_key(char **result, size_t *length, const zend_class_entry *obj_ce, zephir_call_type type, zval *function_name TSRMLS_DC)
{
	const zend_class_entry *calling_scope;
	char *buf = NULL, *c;
	size_t l = 0, len = 0;
	const size_t ppzce_size = sizeof(zend_class_entry**);
	ulong hash = 5381;

#if PHP_VERSION_ID >= 70100
	calling_scope = EG(fake_scope);
#else
	calling_scope = EG(scope);
#endif
	*result = NULL;
	*length = 0;

	if (calling_scope && type == zephir_fcall_parent) {
		calling_scope = calling_scope->parent;
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}
	else if (type == zephir_fcall_static) {
#if PHP_VERSION_ID >= 70100
		calling_scope = zend_get_called_scope(EG(current_execute_data));
#else
		calling_scope = EG(current_execute_data)->called_scope;
#endif
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}

	if (
		    calling_scope
		 && obj_ce
		 && calling_scope != obj_ce
		 && !instanceof_function(obj_ce, calling_scope)
		 && !instanceof_function(calling_scope, obj_ce)
	) {
		calling_scope = NULL;
	}

	if (Z_TYPE_P(function_name) == IS_STRING) {
		l   = (size_t)(Z_STRLEN_P(function_name)) + 1;
		c   = Z_STRVAL_P(function_name);
		len = 2 * ppzce_size + l + 1;
		buf = emalloc(len);

		memcpy(buf,                  c,               l);
		memcpy(buf + l,              &calling_scope,  ppzce_size);
		memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
		buf[len - 1] = '\0';
	}
	else if (Z_TYPE_P(function_name) == IS_ARRAY) {
		zval *method;
		HashTable *function_hash = Z_ARRVAL_P(function_name);
		if (
			    function_hash->nNumOfElements == 2
			 && ((method = zend_hash_index_find(function_hash, 1)) != NULL)
			 && Z_TYPE_P(method) == IS_STRING
		) {
			l   = (size_t)(Z_STRLEN_P(method)) + 1;
			c   = Z_STRVAL_P(method);
			len = 2 * ppzce_size + l + 1;
			buf = emalloc(len);

			memcpy(buf,                  c,               l);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
			buf[len - 1] = '\0';
		}
	}

	if (EXPECTED(buf != NULL)) {
		size_t i;

		for (i = 0; i < l; ++i) {
			char c = buf[i];
			c = tolower_map[(unsigned char)c];
			buf[i] = c;
			hash   = (hash << 5) + hash + c;
		}

		for (i = l; i < len; ++i) {
			char c = buf[i];
			hash = (hash << 5) + hash + c;
		}
	}

	*result = buf;
	*length = len;
	return hash;
}

ZEPHIR_ATTR_NONNULL static void zephir_fcall_populate_fci_cache(zend_fcall_info_cache *fcic, zend_fcall_info *fci, zephir_call_type type)
{
	zend_class_entry *scope, *called_scope;
#if PHP_VERSION_ID >= 70100
	scope = EG(fake_scope);
	called_scope = zend_get_called_scope(EG(current_execute_data));
#else
	scope = EG(scope);
	called_scope = EG(current_execute_data)->called_scope;
#endif

	switch (type) {
		case zephir_fcall_parent:
			if (scope && scope->parent) {
				fcic->calling_scope = scope->parent;
				fcic->called_scope  = called_scope;
				fcic->object        = fci->object ? fci->object : Z_OBJ(EG(current_execute_data)->This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_self:
			if (scope) {
				fcic->calling_scope = scope;
				fcic->called_scope  = called_scope;
				fcic->object        = fci->object ? fci->object : Z_OBJ(EG(current_execute_data)->This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_static:
			if (called_scope) {
				fcic->called_scope  = called_scope;
				fcic->calling_scope = called_scope;
				fcic->object        = fci->object ? fci->object : Z_OBJ(EG(current_execute_data)->This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_function:
			fcic->calling_scope = NULL;
			fcic->called_scope  = NULL;
			fcic->object        = NULL;
			fcic->initialized   = 1;
			break;

		case zephir_fcall_ce: {
			fcic->initialized      = 1;
			fcic->calling_scope    = scope;
			/* called_scope: Instead of the checks below, which seem unnecessary/broken? */
			fcic->called_scope     = fcic->calling_scope;
			fcic->object       	   = NULL;
			/*
			zend_class_entry *scope = EG(current_execute_data)->func ? EG(current_execute_data)->func->op_array.scope : NULL;
			if (scope && EG(current_execute_data) && Z_OBJ(EG(current_execute_data)->This) &&
				instanceof_function(Z_OBJCE(EG(current_execute_data)->This), scope) &&
				instanceof_function(scope, fcic->calling_scope)) {
				fcic->object = Z_OBJ(EG(current_execute_data)->This);
				fcic->called_scope = fcic->object->ce;
			}
			else {
				fcic->called_scope = fcic->calling_scope;
			}
			*/

			break;
		}

		case zephir_fcall_method:
			fcic->initialized      = 1;
			fcic->calling_scope    = scope;
			fcic->object           = fci->object;
			if (fci->object) {
				fcic->called_scope = fci->object->ce;
			}
			else if (scope && !(called_scope && instanceof_function(called_scope, scope))) {
				fcic->called_scope = scope;
			}
			else {
				fcic->called_scope = called_scope;
			}

			break;

		default:
#ifndef ZEPHIR_RELEASE
			fprintf(stderr, "%s: unknown call type (%d)\n", __func__, (int) type);
			abort();
#endif
			fcic->initialized = 0; /* not strictly necessary but just to be safe */
			break;
	}

}

/**
 * Calls a function/method in the PHP userland
 */
int zephir_call_user_function(zval *object_pp, zend_class_entry *obj_ce, zephir_call_type type,
	zval *function_name, zval *retval_ptr, zephir_fcall_cache_entry **cache_entry, int cache_slot, zend_uint param_count,
	zval *params[], zephir_fcall_info *info)
{
	zval local_retval_ptr;
	int status;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	char *fcall_key = NULL;
	ulong fcall_key_hash;
	size_t fcall_key_len;
	zephir_fcall_cache_entry *temp_cache_entry = NULL;
	zend_class_entry *old_scope;
	int reload_cache = 1;

#if PHP_VERSION_ID >= 70100
	old_scope = EG(fake_scope);
#else
	old_scope = EG(scope);
#endif
	assert(obj_ce || !object_pp);
	ZVAL_UNDEF(&local_retval_ptr);

	if (retval_ptr) {
		zval_ptr_dtor(retval_ptr);
		ZVAL_UNDEF(retval_ptr);
	}

	++zephir_globals_ptr->recursive_lock;

	if (UNEXPECTED(zephir_globals_ptr->recursive_lock > 2048)) {
		zend_error(E_ERROR, "Maximum recursion depth exceeded");
		return FAILURE;
	}

	if (type != zephir_fcall_function && !object_pp) {
		object_pp = EG(current_execute_data) && Z_OBJ(EG(current_execute_data)->This) ? &EG(current_execute_data)->This : NULL;
		if (!obj_ce && object_pp) {
			obj_ce = Z_OBJCE_P(object_pp);
		}
	}

	if (obj_ce) {
#if PHP_VERSION_ID >= 70100
		EG(fake_scope) = obj_ce;
#else
		EG(scope) = obj_ce;
#endif
	}

	if (!cache_entry || !*cache_entry) {
		if (zephir_globals_ptr->cache_enabled) {

			if (cache_slot > 0) {
				if (zephir_globals_ptr->scache[cache_slot]) {
					reload_cache = 0;
					temp_cache_entry = zephir_globals_ptr->scache[cache_slot];
					if (cache_entry) {
						*cache_entry = temp_cache_entry;
					}
				}
			}

			if (reload_cache) {
				if (info) {
					fcall_key_hash = zephir_make_fcall_info_key(&fcall_key, &fcall_key_len, (object_pp && type != zephir_fcall_ce ? Z_OBJCE_P(object_pp) : obj_ce), type, info);
				} else {
					fcall_key_hash = zephir_make_fcall_key(&fcall_key, &fcall_key_len, (object_pp && type != zephir_fcall_ce ? Z_OBJCE_P(object_pp) : obj_ce), type, function_name);
				}
			}
		}
	}

	fci.size           = sizeof(fci);
#if PHP_VERSION_ID < 70100
	fci.function_table = obj_ce ? &obj_ce->function_table : EG(function_table);
#endif
	fci.object         = object_pp ? Z_OBJ_P(object_pp) : NULL;
	if (function_name) ZVAL_COPY_VALUE(&fci.function_name, function_name);
	fci.retval         = retval_ptr ? retval_ptr : &local_retval_ptr;
	fci.param_count    = param_count;
	fci.params         = NULL;
	//fci.params: Passed as separate parameter to prevent the need to convert zval ** to zval *
	fci.no_separation  = 1;
#if PHP_VERSION_ID < 70100
	fci.symbol_table   = NULL;
#endif

	fcic.initialized = 0;
	fcic.function_handler = NULL;
	fcic.calling_scope = NULL;
	fcic.called_scope = NULL;
	if (!cache_entry || !*cache_entry) {
		if (fcall_key && (temp_cache_entry = zend_hash_str_find_ptr(zephir_globals_ptr->fcache, fcall_key, fcall_key_len)) != NULL) {
			zephir_fcall_populate_fci_cache(&fcic, &fci, type);

#ifndef ZEPHIR_RELEASE
			fcic.function_handler = temp_cache_entry->f;
			++(temp_cache_entry->times);
#else
			fcic.function_handler = temp_cache_entry;
#endif
			/*memcpy(&clone, &fcic, sizeof(clone));*/
		}
	} else {
		zephir_fcall_populate_fci_cache(&fcic, &fci, type);
#ifndef ZEPHIR_RELEASE
		fcic.function_handler = (*cache_entry)->f;
		++(*cache_entry)->times;
#else
		fcic.function_handler = *cache_entry;
#endif
	}

	/* fcic.initialized = 0; */
	//status = ZEPHIR_ZEND_CALL_FUNCTION_WRAPPER(&fci, &fcic, info);
	status = zephir_call_function_opt(&fci, &fcic, info, params);

#if PHP_VERSION_ID >= 70100
		EG(fake_scope) = old_scope;
#else
		EG(scope) = old_scope;
#endif

	if (!cache_entry || !*cache_entry) {
		if (EXPECTED(status != FAILURE) && fcall_key && !temp_cache_entry && fcic.initialized) {
#ifndef ZEPHIR_RELEASE
			zephir_fcall_cache_entry *cache_entry_temp = malloc(sizeof(zephir_fcall_cache_entry));
			cache_entry_temp->f     = fcic.function_handler;
			cache_entry_temp->times = 0;
#else
			zephir_fcall_cache_entry *cache_entry_temp = fcic.function_handler;
#endif
			if (NULL == zend_hash_str_add_ptr(zephir_globals_ptr->fcache, fcall_key, fcall_key_len, cache_entry_temp)) {
#ifndef ZEPHIR_RELEASE
				free(cache_entry_temp);
				free(temp_cache_entry);
#endif
			} else {
				if (cache_entry) {
					*cache_entry = cache_entry_temp;
					if (cache_slot > 0) {
						zephir_globals_ptr->scache[cache_slot] = *cache_entry;
					}
				}
			}
		}
	}

	if (fcall_key) {
		efree(fcall_key);
	}

	if (!retval_ptr) {
		zval_ptr_dtor(&local_retval_ptr);
	}

	--zephir_globals_ptr->recursive_lock;
	return status;
}

int zephir_call_func_aparams(zval *return_value_ptr, const char *func_name, uint func_length,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params)
{
	int status;
	zval rv, *rvp = return_value_ptr ? return_value_ptr : &rv;
	zval *func = NULL;
	zephir_fcall_info info;

	ZVAL_UNDEF(&rv);

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr != NULL && Z_TYPE_P(return_value_ptr) > IS_NULL) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	info.type = ZEPHIR_FCALL_TYPE_FUNC;
	info.class_name = NULL;
	info.func_name = func_name;
	info.func_length = func_length;

	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func, rvp, cache_entry, cache_slot, param_count, params, &info);

	if (status == FAILURE && !EG(exception)) {
		zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined function %s()", func_name);
		if (return_value_ptr) {
			zval_ptr_dtor(return_value_ptr);
			ZVAL_UNDEF(return_value_ptr);
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				zval_ptr_dtor(return_value_ptr);
				ZVAL_UNDEF(return_value_ptr);
			}
		}
	}

	if (!return_value_ptr) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int zephir_call_zval_func_aparams(zval *return_value_ptr, zval *func_name,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params)
{
	int status;
	zval rv, *rvp = return_value_ptr ? return_value_ptr : &rv;

	ZVAL_UNDEF(&rv);

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr != NULL && Z_TYPE_P(return_value_ptr) > IS_NULL) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func_name, rvp, cache_entry, cache_slot, param_count, params, NULL);

	if (status == FAILURE && !EG(exception)) {
		zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined function %s()", Z_TYPE_P(func_name) ? Z_STRVAL_P(func_name) : "undefined");
		if (return_value_ptr) {
			zval_ptr_dtor(return_value_ptr);
			ZVAL_NULL(return_value_ptr);
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				zval_ptr_dtor(return_value_ptr);
				ZVAL_NULL(return_value_ptr);
			}
		}
	}

	if (!return_value_ptr) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int zephir_call_class_method_aparams(zval *return_value_ptr, zend_class_entry *ce, zephir_call_type type, zval *object,
	const char *method_name, uint method_len,
	zephir_fcall_cache_entry **cache_entry, int cache_slot,
	uint param_count, zval **params)
{
	char *possible_method;
	zval rv, *rvp = return_value_ptr ? return_value_ptr : &rv;
	zval *fn = NULL;
	int status;
	zephir_fcall_info info;

	ZVAL_UNDEF(&rv);

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr != NULL && Z_TYPE_P(return_value_ptr) > IS_NULL) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	if (object) {
		if (Z_TYPE_P(object) != IS_OBJECT) {
			zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Trying to call method %s on a non-object", method_name);
			if (return_value_ptr) {
				zval_ptr_dtor(return_value_ptr);
				ZVAL_UNDEF(return_value_ptr);
			}
			return FAILURE;
		}
	}

	if (!cache_entry || !*cache_entry) {

		switch (type) {

			case zephir_fcall_parent:
				info.type = ZEPHIR_FCALL_TYPE_CLASS_PARENT_METHOD;
				break;

			case zephir_fcall_self:
				assert(!ce);
				info.type = ZEPHIR_FCALL_TYPE_CLASS_SELF_METHOD;
				break;

			case zephir_fcall_static:
				assert(!ce);
				info.type = ZEPHIR_FCALL_TYPE_CLASS_STATIC_METHOD;
				break;

			case zephir_fcall_ce:
				assert(ce != NULL);
				info.type = ZEPHIR_FCALL_TYPE_CE_METHOD;
				info.ce = ce;
				break;

			case zephir_fcall_method:
			default:
				assert(object != NULL);
				info.type = ZEPHIR_FCALL_TYPE_ZVAL_METHOD;
				info.object_ptr = object;
				info.ce = ce;
				break;
		}

		info.func_name = method_name;
		info.func_length = method_len;
	}

	status = zephir_call_user_function(object ? object : NULL, ce, type, fn, rvp, cache_entry, cache_slot, param_count, params, &info);

	if (status == FAILURE && !EG(exception)) {

		if (ce) {
			//possible_method = zephir_fcall_possible_method(ce, method_name);
			possible_method = NULL; // todo
		} else {
			possible_method = "undefined";
		}

		switch (type) {

			case zephir_fcall_parent:
				if (possible_method) {
					zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method parent::%s(), did you mean '%s'?", method_name, possible_method);
				} else {
					zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method parent::%s()", method_name);
				}
				break;

			case zephir_fcall_self:
				if (possible_method) {
					zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method self::%s(), did you mean '%s'?", method_name, possible_method);
				} else {
					zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method self::%s()", method_name);
				}
				break;

			case zephir_fcall_static:
				zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method static::%s()", method_name);
				break;

			case zephir_fcall_ce:
				zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method %s::%s()", ce->name, method_name);
				break;

			case zephir_fcall_method:
				if (possible_method) {
					zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method %s::%s(), did you mean '%s'?", ce->name, method_name, possible_method);
				} else {
					zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method %s::%s()", ce->name, method_name);
				}
				break;

			default:
				zephir_throw_exception_format(spl_ce_RuntimeException, "Call to undefined method ?::%s()", method_name);
		}

		if (return_value_ptr) {
			zval_ptr_dtor(return_value_ptr);
			ZVAL_UNDEF(return_value_ptr);
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				zval_ptr_dtor(return_value_ptr);
				ZVAL_UNDEF(return_value_ptr);
			}
		}
	}

	if (!return_value_ptr) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

/**
 * Replaces call_user_func_array avoiding function lookup
 * This function does not return FAILURE if an exception has ocurred
 */
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params)
{
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	int status = FAILURE;

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL, E_WARNING, "Invalid arguments supplied for zephir_call_user_func_array_noex()");
		return FAILURE;
	}

	zend_fcall_info_init(handler, 0, &fci, &fci_cache, NULL, &is_callable_error);

	if (is_callable_error) {
		zend_error(E_WARNING, "%s", is_callable_error);
		efree(is_callable_error);
	} else {
		status = SUCCESS;
	}

	if (status == SUCCESS) {
		zend_fcall_info_args(&fci, params);

		fci.retval = return_value;
		zend_call_function(&fci, &fci_cache);

		zend_fcall_info_args_clear(&fci, 1);
	}

	if (EG(exception)) {
		status = SUCCESS;
	}

	return status;
}

/**
 * If a retval_ptr is specified, PHP's implementation of zend_eval_stringl
 * simply prepends a "return " which causes only the first statement to be executed
 */
void zephir_eval_php(zval *str, zval *retval_ptr, char *context)
{
	zval local_retval;
	zend_op_array *new_op_array = NULL;
	uint32_t original_compiler_options;

	ZVAL_UNDEF(&local_retval);

	original_compiler_options = CG(compiler_options);
	CG(compiler_options) = ZEND_COMPILE_DEFAULT_FOR_EVAL;
	new_op_array = zend_compile_string(str, context);
	CG(compiler_options) = original_compiler_options;

	if (new_op_array)
	{
		EG(no_extensions) = 1;
		zend_try {
			zend_execute(new_op_array, &local_retval);
		} zend_catch {
			destroy_op_array(new_op_array);
			efree_size(new_op_array, sizeof(zend_op_array));
			zend_bailout();
		} zend_end_try();
		EG(no_extensions) = 0;

		if (Z_TYPE(local_retval) != IS_UNDEF) {
			if (retval_ptr) {
				ZVAL_COPY_VALUE(retval_ptr, &local_retval);
			} else {
				zval_ptr_dtor(&local_retval);
			}
		} else if (retval_ptr) {
			ZVAL_NULL(retval_ptr);
		}

		destroy_op_array(new_op_array);
		efree_size(new_op_array, sizeof(zend_op_array));
	}
}
