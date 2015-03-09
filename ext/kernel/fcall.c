
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
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
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

#if PHP_VERSION_ID >= 50500
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
#endif

int zephir_has_constructor_ce(const zend_class_entry *ce)
{
	while (ce) {
		if (ce->constructor) {
			return 1;
		}
		ce = ce->parent;
	}
	return 0;
}

#if 0
static inline ulong zephir_update_hash(const char *arKey, uint nKeyLength, ulong hash)
{
	for (; nKeyLength >= 8; nKeyLength -= 8) {
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
		hash = ((hash << 5) + hash) + *arKey++;
	}

	switch (nKeyLength) {
		case 7:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 6:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 5:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 4:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 3:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 2:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		case 1:  hash = ((hash << 5) + hash) + *arKey++;
		/* no break */
		default: break;
	}

	return hash;
}
#endif

static char *zephir_fcall_possible_method(zend_class_entry *ce, const char *wrong_name TSRMLS_DC)
{
	HashTable *methods;
	HashPosition   pos;
	zend_function *method;
	char *possible_method = NULL;
	zval *left = NULL, *right = NULL, method_name;
	zval *params[1];
	int count;

	count = zend_hash_num_elements(&ce->function_table);
	if (count > 0) {

		ZEPHIR_SINIT_VAR(method_name);
		ZVAL_STRING(&method_name, wrong_name, 0);

		params[0] = &method_name;
		zephir_call_func_aparams(&right, SL("metaphone"), NULL, 1, params TSRMLS_CC);

		methods = &ce->function_table;
		zend_hash_internal_pointer_reset_ex(methods, &pos);

		while (zend_hash_get_current_data_ex(methods, (void **) &method, &pos) == SUCCESS) {

			ZEPHIR_SINIT_VAR(method_name);
			ZVAL_STRING(&method_name, method->common.function_name, 0);

			if (left) {
				zephir_ptr_dtor(&left);
			}
			left = NULL;

			params[0] = &method_name;
			zephir_call_func_aparams(&left, SL("metaphone"), NULL, 1, params TSRMLS_CC);

			if (zephir_is_equal(left, right TSRMLS_CC)) {
				possible_method = (char *) method->common.function_name;
				break;
			}

			zend_hash_move_forward_ex(methods, &pos);
		}

		if (left) {
			zephir_ptr_dtor(&left);
		}

		if (right) {
			zephir_ptr_dtor(&right);
		}
	}

	return possible_method;
}

/**
 * Creates a unique key to cache the current method/function call address for the current scope
 */
static ulong zephir_make_fcall_key(char **result, size_t *length, const zend_class_entry *obj_ce, zephir_call_type type, zval *function_name TSRMLS_DC)
{
	const zend_class_entry *calling_scope = EG(scope);
	char *buf = NULL, *c;
	size_t l = 0, len = 0;
	const size_t ppzce_size = sizeof(zend_class_entry**);
	ulong hash = 5381;

	*result = NULL;
	*length = 0;

	if (calling_scope && type == zephir_fcall_parent) {
		calling_scope = calling_scope->parent;
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}
	else if (type == zephir_fcall_static) {
		calling_scope = EG(called_scope);
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}

	if (
		    calling_scope
		 && obj_ce
		 && calling_scope != obj_ce
		 && !instanceof_function(obj_ce, calling_scope TSRMLS_CC)
		 && !instanceof_function(calling_scope, obj_ce TSRMLS_CC)
	) {
		calling_scope = NULL;
	}

	if (Z_TYPE_P(function_name) == IS_STRING) {
		l   = (size_t)(Z_STRLEN_P(function_name)) + 1;
		c   = Z_STRVAL_P(function_name);
		len = 2 * ppzce_size + l;
		buf = ecalloc(1, len);

		memcpy(buf,                  c,               l);
		memcpy(buf + l,              &calling_scope,  ppzce_size);
		memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
	}
	else if (Z_TYPE_P(function_name) == IS_ARRAY) {
		zval **method;
		HashTable *function_hash = Z_ARRVAL_P(function_name);
		if (
			    function_hash->nNumOfElements == 2
			 && zend_hash_index_find(function_hash, 1, (void**)&method) == SUCCESS
			 && Z_TYPE_PP(method) == IS_STRING
		) {
			l   = (size_t)(Z_STRLEN_PP(method)) + 1;
			c   = Z_STRVAL_PP(method);
			len = 2 * ppzce_size + l;
			buf = ecalloc(1, len);

			memcpy(buf,                  c,               l);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
		}
	}
	else if (Z_TYPE_P(function_name) == IS_OBJECT) {
		/*if (Z_OBJ_HANDLER_P(function_name, get_closure)) {
			l   = sizeof("__invoke");
			len = 2 * ppzce_size + l;
			buf = ecalloc(1, len);

			memcpy(buf,                  "__invoke",     l);
			memcpy(buf + l,              &calling_scope, ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,        ppzce_size);
		}*/
	}

	if (EXPECTED(buf != NULL)) {
		size_t i;

		for (i = 0; i < l; ++i) {
			char c = buf[i];
#if PHP_VERSION_ID >= 50500
			c = tolower_map[(unsigned char)c];
#else
			c = tolower(c);
#endif
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

ZEPHIR_ATTR_NONNULL static void zephir_fcall_populate_fci_cache(zend_fcall_info_cache *fcic, zend_fcall_info *fci, zephir_call_type type TSRMLS_DC)
{
	switch (type) {
		case zephir_fcall_parent:
			if (EG(scope) && EG(scope)->parent) {
				fcic->calling_scope = EG(scope)->parent;
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_self:
			if (EG(scope)) {
				fcic->calling_scope = EG(scope);
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_static:
			if (EG(called_scope)) {
				fcic->calling_scope = EG(called_scope);
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case zephir_fcall_function:
			fcic->calling_scope = NULL;
			fcic->called_scope  = NULL;
			fcic->object_ptr    = NULL;
			fcic->initialized   = 1;
			break;

		case zephir_fcall_ce: {
			zend_class_entry *scope = EG(active_op_array) ? EG(active_op_array)->scope : NULL;

			fcic->initialized      = 1;
			fcic->calling_scope    = EG(scope);
			fcic->object_ptr       = NULL;

			if (scope && EG(This) && instanceof_function(Z_OBJCE_P(EG(This)), scope TSRMLS_CC) && instanceof_function(scope, fcic->calling_scope TSRMLS_CC)) {
				fcic->object_ptr   = EG(This);
				fcic->called_scope = Z_OBJCE_P(fcic->object_ptr);
			}
			else {
				fcic->called_scope = fcic->calling_scope;
			}

			break;
		}

		case zephir_fcall_method:
			fcic->initialized      = 1;
			fcic->calling_scope    = EG(scope);
			fcic->object_ptr       = fci->object_ptr;
			if (fci->object_ptr) {
				fcic->called_scope = Z_OBJCE_P(fci->object_ptr);
			}
			else if (EG(scope) && !(EG(called_scope) && instanceof_function(EG(called_scope), EG(scope) TSRMLS_CC))) {
				fcic->called_scope = EG(scope);
			}
			else {
				fcic->called_scope = EG(called_scope);
			}

			break;

		default:
#ifndef ZEPHIR_RELEASE
			fprintf(stderr, "%s: unknown call type (%d)\n", __func__, (int)type);
			abort();
#endif
			fcic->initialized = 0; /* not strictly necessary but just to be safe */
			break;
	}

}

/**
 * Calls a function/method in the PHP userland
 */
int zephir_call_user_function(zval **object_pp, zend_class_entry *obj_ce, zephir_call_type type,
	zval *function_name, zval **retval_ptr_ptr, zephir_fcall_cache_entry **cache_entry, zend_uint param_count,
	zval *params[] TSRMLS_DC)
{
	zval ***params_ptr, ***params_array = NULL;
	zval **static_params_array[10];
	zval *local_retval_ptr = NULL;
	int status;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic /* , clone */;
	zend_zephir_globals_def *zephir_globals_ptr = ZEPHIR_VGLOBAL;
	char *fcall_key = NULL;
	size_t fcall_key_len;
	ulong fcall_key_hash;
	zephir_fcall_cache_entry **temp_cache_entry = NULL;
	zend_class_entry *old_scope = EG(scope);

	assert(obj_ce || !object_pp);

	if (retval_ptr_ptr && *retval_ptr_ptr) {
		zval_ptr_dtor(retval_ptr_ptr);
		*retval_ptr_ptr = NULL;
	}

	++zephir_globals_ptr->recursive_lock;

	if (UNEXPECTED(zephir_globals_ptr->recursive_lock > 2048)) {
		zend_error(E_ERROR, "Maximum recursion depth exceeded");
		return FAILURE;
	}

	if (param_count) {
		zend_uint i;

		if (UNEXPECTED(param_count > 10)) {
			params_array = (zval***)emalloc(param_count * sizeof(zval**));
			params_ptr   = params_array;
			for (i = 0; i < param_count; ++i) {
				params_array[i] = &params[i];
			}
		} else {
			params_ptr = static_params_array;
			for (i = 0; i < param_count; ++i) {
				static_params_array[i] = &params[i];
			}
		}
	}
	else {
		params_ptr = NULL;
	}

	if (type != zephir_fcall_function && !object_pp) {
		object_pp = EG(This) ? &EG(This) : NULL;
		if (!obj_ce && object_pp) {
			obj_ce = Z_OBJCE_PP(object_pp);
		}
	}

	if (obj_ce) {
		EG(scope) = obj_ce;
	}

	if (!cache_entry || !*cache_entry) {
		if (zephir_globals_ptr->cache_enabled) {
			fcall_key_hash = zephir_make_fcall_key(&fcall_key, &fcall_key_len, (object_pp ? Z_OBJCE_PP(object_pp) : obj_ce), type, function_name TSRMLS_CC);
		}
	}

	fci.size           = sizeof(fci);
	fci.function_table = obj_ce ? &obj_ce->function_table : EG(function_table);
	fci.object_ptr     = object_pp ? *object_pp : NULL;
	fci.function_name  = function_name;
	fci.retval_ptr_ptr = retval_ptr_ptr ? retval_ptr_ptr : &local_retval_ptr;
	fci.param_count    = param_count;
	fci.params         = params_ptr;
	fci.no_separation  = 1;
	fci.symbol_table   = NULL;

	fcic.initialized = 0;
	fcic.function_handler = NULL;
	if (!cache_entry || !*cache_entry) {
		if (fcall_key && zend_hash_quick_find(zephir_globals_ptr->fcache, fcall_key, fcall_key_len, fcall_key_hash, (void**)&temp_cache_entry) != FAILURE) {
			zephir_fcall_populate_fci_cache(&fcic, &fci, type TSRMLS_CC);

#ifndef ZEPHIR_RELEASE
			fcic.function_handler = (*temp_cache_entry)->f;
			++(*temp_cache_entry)->times;
#else
			fcic.function_handler = *temp_cache_entry;
#endif
			/*memcpy(&clone, &fcic, sizeof(clone));*/
		}
	} else {
		zephir_fcall_populate_fci_cache(&fcic, &fci, type TSRMLS_CC);
#ifndef ZEPHIR_RELEASE
		fcic.function_handler = (*cache_entry)->f;
		++(*temp_cache_entry)->times;
#else
		fcic.function_handler = *cache_entry;
#endif
	}

	/* Xdebug fix */
	//if (fcic.function_handler && fcic.function_handler->type == ZEND_INTERNAL_FUNCTION && fcic.function_handler->op_array) {
	//	fcic.function_handler->op_array.filename = "?";
	//	fcic.function_handler->op_array.line_start = 0;
	//	fcic.function_handler->op_array.line_end = 0;
	//}

	/* fcic.initialized = 0; */
	status = ZEPHIR_ZEND_CALL_FUNCTION_WRAPPER(&fci, &fcic TSRMLS_CC);

/*
	if (fcic.initialized && cache_entry) {
		if (fcic.called_scope != clone.called_scope) {
			fprintf(stderr, "real called_scope: %s (%p)\n", fcic.called_scope->name, fcic.called_scope);
			fprintf(stderr, "my   called_scope: %s (%p)\n", clone.called_scope->name, clone.called_scope);
			fprintf(stderr, "type: %d\n", (int)type);
		}

		if (fcic.calling_scope != clone.calling_scope) {
			fprintf(stderr, "real calling_scope: %s (%p)\n", fcic.calling_scope->name, fcic.calling_scope);
			fprintf(stderr, "my   calling_scope: %s (%p)\n", clone.calling_scope->name, clone.calling_scope);
			fprintf(stderr, "type: %d\n", (int)type);
		}

		if (fcic.object_ptr != clone.object_ptr) {
			fprintf(stderr, "real object_ptr: %s (%p)\n", (fcic.object_ptr ? Z_OBJCE_P(fcic.object_ptr)->name : ""), fcic.object_ptr);
			fprintf(stderr, "my   object_ptr: %s (%p)\n", (clone.object_ptr ? Z_OBJCE_P(clone.object_ptr)->name : ""), clone.object_ptr);
			fprintf(stderr, "type: %d\n", (int)type);
		}

		if (fcic.function_handler != clone.function_handler) {
			fprintf(stderr, "real handler: %p (%s::%s)\n", fcic.function_handler, (fcic.function_handler->common.scope ? fcic.function_handler->common.scope->name : ""), fcic.function_handler->common.function_name);
			fprintf(stderr, "my   handler: %p (%s::%s)\n", clone.function_handler, (clone.function_handler->common.scope ? clone.function_handler->common.scope->name : ""), clone.function_handler->common.function_name);
			fprintf(stderr, "type: %d\n", (int)type);
		}
	}
*/
	EG(scope) = old_scope;

	if (!cache_entry || !*cache_entry) {
		if (EXPECTED(status != FAILURE) && fcall_key && !temp_cache_entry) {
#ifndef ZEPHIR_RELEASE
			zephir_fcall_cache_entry *temp_cache_entry = malloc(sizeof(zephir_fcall_cache_entry));
			temp_cache_entry->f     = fcic.function_handler;
			temp_cache_entry->times = 0;
#else
			zephir_fcall_cache_entry *temp_cache_entry = fcic.function_handler;
#endif
			if (FAILURE == zend_hash_quick_add(zephir_globals_ptr->fcache, fcall_key, fcall_key_len, fcall_key_hash, &temp_cache_entry, sizeof(zephir_fcall_cache_entry*), NULL)) {
#ifndef ZEPHIR_RELEASE
				free(temp_cache_entry);
#endif
			} else {
#ifdef ZEPHIR_RELEASE
				if (cache_entry) {
					*cache_entry = temp_cache_entry;
				}
#endif
			}
		}
	}

	if (fcall_key) {
		efree(fcall_key);
	}

	if (UNEXPECTED(params_array != NULL)) {
		efree(params_array);
	}

	if (!retval_ptr_ptr) {
		if (local_retval_ptr) {
			zval_ptr_dtor(&local_retval_ptr);
		}
	}

	--zephir_globals_ptr->recursive_lock;
	return status;
}

int zephir_call_func_aparams(zval **return_value_ptr, const char *func_name, uint func_length,
	zephir_fcall_cache_entry **cache_entry,
	uint param_count, zval **params TSRMLS_DC)
{
	int status;
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	zval *func;

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	ALLOC_INIT_ZVAL(func);
	ZVAL_STRINGL(func, func_name, func_length, 0);
	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func, rvp, cache_entry, param_count, params TSRMLS_CC);

	if (status == FAILURE && !EG(exception)) {
		zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined function %s()", func_name);
		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				*return_value_ptr = NULL;
			}
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	if (Z_REFCOUNT_P(func) > 1) {
		zval_copy_ctor(func);
	} else {
		ZVAL_NULL(func);
	}
	zval_ptr_dtor(&func);

	return status;
}

int zephir_call_zval_func_aparams(zval **return_value_ptr, zval *func_name,
	zephir_fcall_cache_entry **cache_entry,
	uint param_count, zval **params TSRMLS_DC)
{
	int status;
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	status = zephir_call_user_function(NULL, NULL, zephir_fcall_function, func_name, rvp, cache_entry, param_count, params TSRMLS_CC);

	if (status == FAILURE && !EG(exception)) {
		zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined function %s()", Z_TYPE_P(func_name) ? Z_STRVAL_P(func_name) : "undefined");
		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				*return_value_ptr = NULL;
			}
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int zephir_call_class_method_aparams(zval **return_value_ptr, zend_class_entry *ce, zephir_call_type type, zval *object,
	const char *method_name, uint method_len,
	zephir_fcall_cache_entry **cache_entry,
	uint param_count, zval **params TSRMLS_DC)
{
	char *possible_method;
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	zval *fn;
	zval *mn;
	int status;

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	if (object) {
		if (Z_TYPE_P(object) != IS_OBJECT) {
			zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Trying to call method %s on a non-object", method_name);
			if (return_value_ptr) {
				*return_value_ptr = NULL;
			}
			return FAILURE;
		}
	}

	ALLOC_INIT_ZVAL(fn);
	if (!cache_entry || !*cache_entry) {

		array_init_size(fn, 2);
		switch (type) {
			case zephir_fcall_parent: add_next_index_stringl(fn, ZEND_STRL("parent"), 1); break;
			case zephir_fcall_self:   assert(!ce); add_next_index_stringl(fn, ZEND_STRL("self"), 1); break;
			case zephir_fcall_static: assert(!ce); add_next_index_stringl(fn, ZEND_STRL("static"), 1); break;

			case zephir_fcall_ce:
				assert(ce != NULL);
				add_next_index_stringl(fn, ce->name, ce->name_length, 1);
				break;

			case zephir_fcall_method:
			default:
				assert(object != NULL);
				Z_ADDREF_P(object);
				add_next_index_zval(fn, object);
				break;
		}

		ALLOC_INIT_ZVAL(mn);
		ZVAL_STRINGL(mn, method_name, method_len, 1);
		add_next_index_zval(fn, mn);

	} else {
		ZVAL_STRINGL(fn, "undefined", sizeof("undefined")-1, 1);
	}

	status = zephir_call_user_function(object ? &object : NULL, ce, type, fn, rvp, cache_entry, param_count, params TSRMLS_CC);
	if (status == FAILURE && !EG(exception)) {

		if (ce) {
			possible_method = zephir_fcall_possible_method(ce, method_name TSRMLS_CC);
		}

		switch (type) {

			case zephir_fcall_parent:
				if (possible_method) {
					zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method parent::%s(), did you mean '%s'?", method_name, possible_method);
				} else {
					zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method parent::%s()", method_name);
				}
				break;

			case zephir_fcall_self:
				if (possible_method) {
					zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method self::%s(), did you mean '%s'?", method_name, possible_method);
				} else {
					zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method self::%s()", method_name);
				}
				break;

			case zephir_fcall_static:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method static::%s()", method_name);
				break;

			case zephir_fcall_ce:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method %s::%s()", ce->name, method_name);
				break;

			case zephir_fcall_method:
				if (possible_method) {
					zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method %s::%s(), did you mean '%s'?", ce->name, method_name, possible_method);
				} else {
					zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method %s::%s()", ce->name, method_name);
				}
				break;

			default:
				zephir_throw_exception_format(spl_ce_RuntimeException TSRMLS_CC, "Call to undefined method ?::%s()", method_name);
		}

		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	} else {
		if (EG(exception)) {
			status = FAILURE;
			if (return_value_ptr) {
				*return_value_ptr = NULL;
			}
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	zval_ptr_dtor(&fn);

	return status;
}

/**
 * Replaces call_user_func_array avoiding function lookup
 * This function does not return FAILURE if an exception has ocurred
 */
int zephir_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC){

	zval *retval_ptr = NULL;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	int status = FAILURE;

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for zephir_call_user_func_array_noex()");
		return FAILURE;
	}

	if (zend_fcall_info_init(handler, 0, &fci, &fci_cache, NULL, &is_callable_error TSRMLS_CC) == SUCCESS) {
		if (is_callable_error) {
			zend_error(E_STRICT, "%s", is_callable_error);
			efree(is_callable_error);
		}
		status = SUCCESS;
	} else {
		if (is_callable_error) {
			zend_error(E_WARNING, "%s", is_callable_error);
			efree(is_callable_error);
		} else {
			status = SUCCESS;
		}
	}

	if (status == SUCCESS) {

		zend_fcall_info_args(&fci, params TSRMLS_CC);
		fci.retval_ptr_ptr = &retval_ptr;

		if (zend_call_function(&fci, &fci_cache TSRMLS_CC) == SUCCESS && fci.retval_ptr_ptr && *fci.retval_ptr_ptr) {
			COPY_PZVAL_TO_ZVAL(*return_value, *fci.retval_ptr_ptr);
		}

		if (fci.params) {
			efree(fci.params);
		}
	}

	if (EG(exception)) {
		status = SUCCESS;
	}

	return status;
}

#if PHP_VERSION_ID <= 50309

/**
 * Latest version of zend_throw_exception_internal
 */
void zephir_throw_exception_internal(zval *exception TSRMLS_DC)
{
	if (exception != NULL) {
		zval *previous = EG(exception);
		zend_exception_set_previous(exception, EG(exception) TSRMLS_CC);
		EG(exception) = exception;
		if (previous) {
			return;
		}
	}

	if (!EG(current_execute_data)) {
		if (EG(exception)) {
			zend_exception_error(EG(exception), E_ERROR TSRMLS_CC);
		}
		zend_error(E_ERROR, "Exception thrown without a stack frame");
	}

	if (zend_throw_exception_hook) {
		zend_throw_exception_hook(exception TSRMLS_CC);
	}

	if (EG(current_execute_data)->opline == NULL ||
		(EG(current_execute_data)->opline + 1)->opcode == ZEND_HANDLE_EXCEPTION) {
		/* no need to rethrow the exception */
		return;
	}

	EG(opline_before_exception) = EG(current_execute_data)->opline;
	EG(current_execute_data)->opline = EG(exception_op);
}

int zephir_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC) {

	zend_uint i;
	zval **original_return_value;
	HashTable *calling_symbol_table;
	zend_op_array *original_op_array;
	zend_op **original_opline_ptr;
	zend_class_entry *current_scope;
	zend_class_entry *current_called_scope;
	zend_class_entry *calling_scope = NULL;
	zend_class_entry *called_scope = NULL;
	zval *current_this;
	zend_execute_data execute_data;

	*fci->retval_ptr_ptr = NULL;

	if (!EG(active)) {
		return FAILURE; /* executor is already inactive */
	}

	if (EG(exception)) {
		return FAILURE; /* we would result in an instable executor otherwise */
	}

	switch (fci->size) {
		case sizeof(zend_fcall_info):
			break; /* nothing to do currently */
		default:
			zend_error(E_ERROR, "Corrupted fcall_info provided to zephir_call_function()");
			break;
	}

	/* Initialize execute_data */
	if (EG(current_execute_data)) {
		execute_data = *EG(current_execute_data);
		EX(op_array) = NULL;
		EX(opline) = NULL;
		EX(object) = NULL;
	} else {
		/* This only happens when we're called outside any execute()'s
		 * It shouldn't be strictly necessary to NULL execute_data out,
		 * but it may make bugs easier to spot
		 */
		memset(&execute_data, 0, sizeof(zend_execute_data));
	}

	if (!fci_cache || !fci_cache->initialized) {

		zend_fcall_info_cache fci_cache_local;
		char *callable_name;
		char *error = NULL;

		if (!fci_cache) {
			fci_cache = &fci_cache_local;
		}

		if (!zend_is_callable_ex(fci->function_name, fci->object_ptr, IS_CALLABLE_CHECK_SILENT, &callable_name, NULL, fci_cache, &error TSRMLS_CC)) {
			if (error) {
				zend_error(E_WARNING, "Invalid callback %s, %s", callable_name, error);
				efree(error);
			}
			if (callable_name) {
				efree(callable_name);
			}
			return FAILURE;
		} else {
			if (error) {
				/* Capitalize the first latter of the error message */
				if (error[0] >= 'a' && error[0] <= 'z') {
					error[0] += ('A' - 'a');
				}
				zend_error(E_STRICT, "%s", error);
				efree(error);
			}
		}
		efree(callable_name);
	}

	EX(function_state).function = fci_cache->function_handler;
	calling_scope = fci_cache->calling_scope;
	called_scope = fci_cache->called_scope;
	fci->object_ptr = fci_cache->object_ptr;
	EX(object) = fci->object_ptr;
	if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT && (!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
		return FAILURE;
	}

	#ifndef ZEPHIR_RELEASE
	if (EX(function_state).function->common.fn_flags & ZEND_ACC_ABSTRACT) {
		zend_error_noreturn(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
		return FAILURE;
	}
	#endif

	ZEND_VM_STACK_GROW_IF_NEEDED(fci->param_count + 1);

	for (i = 0; i < fci->param_count; i++) {
		zval *param;

		if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION
			&& (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) == 0
			&& !ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& PZVAL_IS_REF(*fci->params[i])) {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
			zval_copy_ctor(param);
		} else if (ARG_SHOULD_BE_SENT_BY_REF(EX(function_state).function, i + 1)
			&& !PZVAL_IS_REF(*fci->params[i])) {

			if (Z_REFCOUNT_PP(fci->params[i]) > 1) {
				zval *new_zval;

				if (fci->no_separation &&
					!ARG_MAY_BE_SENT_BY_REF(EX(function_state).function, i + 1)) {
					if (i || UNEXPECTED(ZEND_VM_STACK_ELEMETS(EG(argument_stack)) == EG(argument_stack)->top)) {
						/* hack to clean up the stack */
						zend_vm_stack_push_nocheck((void *) (zend_uintptr_t)i TSRMLS_CC);
						#if PHP_VERSION_ID <= 50500
						zend_vm_stack_clear_multiple(TSRMLS_C);
						#else
						zend_vm_stack_clear_multiple(0 TSRMLS_C);
						#endif
					}

					zend_error(E_WARNING, "Parameter %d to %s%s%s() expected to be a reference, value given",
						i+1,
						EX(function_state).function->common.scope ? EX(function_state).function->common.scope->name : "",
						EX(function_state).function->common.scope ? "::" : "",
						EX(function_state).function->common.function_name);
					return FAILURE;
				}

				ALLOC_ZVAL(new_zval);
				*new_zval = **fci->params[i];
				zval_copy_ctor(new_zval);
				Z_SET_REFCOUNT_P(new_zval, 1);
				Z_DELREF_PP(fci->params[i]);
				*fci->params[i] = new_zval;
			}
			Z_ADDREF_PP(fci->params[i]);
			Z_SET_ISREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else if (*fci->params[i] != &EG(uninitialized_zval)) {
			Z_ADDREF_PP(fci->params[i]);
			param = *fci->params[i];
		} else {
			ALLOC_ZVAL(param);
			*param = **(fci->params[i]);
			INIT_PZVAL(param);
		}
		zend_vm_stack_push_nocheck(param TSRMLS_CC);
	}

	EX(function_state).arguments = zend_vm_stack_top(TSRMLS_C);
	zend_vm_stack_push_nocheck((void*)(zend_uintptr_t)fci->param_count TSRMLS_CC);

	current_scope = EG(scope);
	EG(scope) = calling_scope;

	current_this = EG(This);

	current_called_scope = EG(called_scope);
	if (called_scope) {
		EG(called_scope) = called_scope;
	} else {
		if (EX(function_state).function->type != ZEND_INTERNAL_FUNCTION) {
			EG(called_scope) = NULL;
		}
	}

	if (fci->object_ptr) {
		if ((EX(function_state).function->common.fn_flags & ZEND_ACC_STATIC)) {
			EG(This) = NULL;
		} else {
			EG(This) = fci->object_ptr;

			if (!PZVAL_IS_REF(EG(This))) {
				Z_ADDREF_P(EG(This)); /* For $this pointer */
			} else {
				zval *this_ptr;

				ALLOC_ZVAL(this_ptr);
				*this_ptr = *EG(This);
				INIT_PZVAL(this_ptr);
				zval_copy_ctor(this_ptr);
				EG(This) = this_ptr;
			}
		}
	} else {
		EG(This) = NULL;
	}

	EX(prev_execute_data) = EG(current_execute_data);
	EG(current_execute_data) = &execute_data;

	if (EX(function_state).function->type == ZEND_USER_FUNCTION) {

		calling_symbol_table = EG(active_symbol_table);
		EG(scope) = EX(function_state).function->common.scope;
		if (fci->symbol_table) {
			EG(active_symbol_table) = fci->symbol_table;
		} else {
			EG(active_symbol_table) = NULL;
		}

		original_return_value = EG(return_value_ptr_ptr);
		original_op_array = EG(active_op_array);
		EG(return_value_ptr_ptr) = fci->retval_ptr_ptr;
		EG(active_op_array) = (zend_op_array *) EX(function_state).function;
		original_opline_ptr = EG(opline_ptr);
		zend_execute(EG(active_op_array) TSRMLS_CC);
		if (!fci->symbol_table && EG(active_symbol_table)) {
			if (EG(symtable_cache_ptr)>=EG(symtable_cache_limit)) {
				zend_hash_destroy(EG(active_symbol_table));
				FREE_HASHTABLE(EG(active_symbol_table));
			} else {
				/* clean before putting into the cache, since clean
				   could call dtors, which could use cached hash */
				zend_hash_clean(EG(active_symbol_table));
				*(++EG(symtable_cache_ptr)) = EG(active_symbol_table);
			}
		}
		EG(active_symbol_table) = calling_symbol_table;
		EG(active_op_array) = original_op_array;
		EG(return_value_ptr_ptr)=original_return_value;
		EG(opline_ptr) = original_opline_ptr;
	} else if (EX(function_state).function->type == ZEND_INTERNAL_FUNCTION) {
		int call_via_handler = (EX(function_state).function->common.fn_flags & ZEND_ACC_CALL_VIA_HANDLER) != 0;
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);
		if (EX(function_state).function->common.scope) {
			EG(scope) = EX(function_state).function->common.scope;
		}

		((zend_internal_function *) EX(function_state).function)->handler(fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		/*  We shouldn't fix bad extensions here,
			because it can break proper ones (Bug #34045)
		if (!EX(function_state).function->common.return_reference)
		{
			INIT_PZVAL(*fci->retval_ptr_ptr);
		}*/
		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}

		if (call_via_handler) {
			/* We must re-initialize function again */
			fci_cache->initialized = 0;
		}
	} else {
		ALLOC_INIT_ZVAL(*fci->retval_ptr_ptr);

		if (fci->object_ptr) {
			Z_OBJ_HT_P(fci->object_ptr)->call_method(EX(function_state).function->common.function_name, fci->param_count, *fci->retval_ptr_ptr, fci->retval_ptr_ptr, fci->object_ptr, 1 TSRMLS_CC);
		} else {
			zend_error_noreturn(E_ERROR, "Cannot call overloaded function for non-object");
			return FAILURE;
		}

		if (EX(function_state).function->type == ZEND_OVERLOADED_FUNCTION_TEMPORARY) {
			efree(EX(function_state).function->common.function_name);
		}
		efree(EX(function_state).function);

		if (EG(exception) && fci->retval_ptr_ptr) {
			zval_ptr_dtor(fci->retval_ptr_ptr);
			*fci->retval_ptr_ptr = NULL;
		}
	}

	#if PHP_VERSION_ID <= 50500
	zend_vm_stack_clear_multiple(TSRMLS_C);
	#else
	zend_vm_stack_clear_multiple(0 TSRMLS_C);
	#endif

	if (EG(This)) {
		zval_ptr_dtor(&EG(This));
	}
	EG(called_scope) = current_called_scope;
	EG(scope) = current_scope;
	EG(This) = current_this;
	EG(current_execute_data) = EX(prev_execute_data);

	if (EG(exception)) {
		zephir_throw_exception_internal(NULL TSRMLS_CC);
	}
	return SUCCESS;
}

#endif

void zephir_eval_php(zval *str, zval *retval_ptr, char *context TSRMLS_DC)
{
    zend_eval_string_ex(Z_STRVAL_P(str), retval_ptr, context, 1 TSRMLS_CC);
}
