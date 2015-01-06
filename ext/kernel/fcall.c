
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/fcall.h"

#include <Zend/zend_API.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_execute.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/backtrace.h"

#include "interned-strings.h"

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

#ifndef PHALCON_RELEASE
void phalcon_fcall_cache_dtor(void *pData)
{
	phalcon_fcall_cache_entry **entry = (phalcon_fcall_cache_entry**)pData;
	free(*entry);
}
#endif

int phalcon_cleanup_fcache(void *pDest TSRMLS_DC, int num_args, va_list args, zend_hash_key *hash_key)
{
	phalcon_fcall_cache_entry **entry = (phalcon_fcall_cache_entry**)pDest;
	zend_class_entry *scope;
	uint len = hash_key->nKeyLength;

	assert(hash_key->arKey != NULL);
	assert(hash_key->nKeyLength > 2 * sizeof(zend_class_entry**));

	memcpy(&scope, &hash_key->arKey[len - 2 * sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

/*
#ifndef PHALCON_RELEASE
	{
		zend_class_entry *cls;
		memcpy(&cls, &hash_key->arKey[len - sizeof(zend_class_entry**)], sizeof(zend_class_entry*));

		fprintf(stderr, "func: %s, cls: %s, scope: %s [%u]\n", (*entry)->f->common.function_name, (cls ? cls->name : "N/A"), (scope ? scope->name : "N/A"), (uint)(*entry)->times);
	}
#endif
*/

#ifndef PHALCON_RELEASE
	if ((*entry)->f->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if ((*entry)->type != ZEND_INTERNAL_FUNCTION || (scope && scope->type != ZEND_INTERNAL_CLASS)) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

#if PHP_VERSION_ID >= 50400
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->info.internal.module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#else
	if (scope && scope->type == ZEND_INTERNAL_CLASS && scope->module->type != MODULE_PERSISTENT) {
		return ZEND_HASH_APPLY_REMOVE;
	}
#endif

	return ZEND_HASH_APPLY_KEEP;
}

int phalcon_has_constructor_ce(const zend_class_entry *ce)
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
static inline ulong phalcon_update_hash(const char *arKey, uint nKeyLength, ulong hash)
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

static ulong phalcon_make_fcall_key(char **result, size_t *length, const zend_class_entry *obj_ce, phalcon_call_type type, zval *function_name TSRMLS_DC)
{
	const zend_class_entry *calling_scope = EG(scope);
	char *buf = NULL, *c;
	size_t l = 0, len = 0;
	const size_t ppzce_size = sizeof(zend_class_entry**);
	ulong hash = 5381;

	*result = NULL;
	*length = 0;

	if (calling_scope && type == phalcon_fcall_parent) {
		calling_scope = calling_scope->parent;
		if (UNEXPECTED(!calling_scope)) {
			return 0;
		}
	}
	else if (type == phalcon_fcall_static) {
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
		buf = emalloc(len);

		memcpy(buf,                  c,               l);
		memcpy(buf + l,              &calling_scope,  ppzce_size);
		memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
	}
	else if (Z_TYPE_P(function_name) == IS_ARRAY) {
		zval **method;
		if (
			    zend_hash_num_elements(Z_ARRVAL_P(function_name)) == 2
			 && zend_hash_index_find(Z_ARRVAL_P(function_name), 1, (void**)&method) == SUCCESS
			 && Z_TYPE_PP(method) == IS_STRING
		) {
			l   = (size_t)(Z_STRLEN_PP(method)) + 1;
			c   = Z_STRVAL_PP(method);
			len = 2 * ppzce_size + l;
			buf = emalloc(len);

			memcpy(buf,                  c,               l);
			memcpy(buf + l,              &calling_scope,  ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,         ppzce_size);
		}
	}
	else if (Z_TYPE_P(function_name) == IS_OBJECT) {
		if (Z_OBJ_HANDLER_P(function_name, get_closure)) {
			l   = sizeof("__invoke");
			len = 2 * ppzce_size + l;
			buf = emalloc(len);

			memcpy(buf,                  "__invoke",     l);
			memcpy(buf + l,              &calling_scope, ppzce_size);
			memcpy(buf + l + ppzce_size, &obj_ce,        ppzce_size);
		}
	}

	if (EXPECTED(buf != NULL)) {
		size_t i;

		for (i=0; i<l; ++i) {
			char c = buf[i];
#if PHP_VERSION_ID >= 50500
			c = tolower_map[(unsigned char)c];
#else
			c = tolower(c);
#endif
			buf[i] = c;
			hash   = (hash << 5) + hash + c;
		}

		for (i=l; i<len; ++i) {
			char c = buf[i];
			hash = (hash << 5) + hash + c;
		}
	}

	*result = buf;
	*length = len;
	return hash;
}

PHALCON_ATTR_NONNULL static void phalcon_fcall_populate_fci_cache(zend_fcall_info_cache *fcic, zend_fcall_info *fci, phalcon_call_type type TSRMLS_DC)
{
	switch (type) {
		case phalcon_fcall_parent:
			if (EG(scope) && EG(scope)->parent) {
				fcic->calling_scope = EG(scope)->parent;
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case phalcon_fcall_self:
			if (EG(scope)) {
				fcic->calling_scope = EG(scope);
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case phalcon_fcall_static:
			if (EG(called_scope)) {
				fcic->calling_scope = EG(called_scope);
				fcic->called_scope  = EG(called_scope);
				fcic->object_ptr    = fci->object_ptr ? fci->object_ptr : EG(This);
				fcic->initialized   = 1;
			}

			break;

		case phalcon_fcall_function:
			fcic->calling_scope = NULL;
			fcic->called_scope  = NULL;
			fcic->object_ptr    = NULL;
			fcic->initialized   = 1;
			break;

		case phalcon_fcall_ce: {
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

		case phalcon_fcall_method:
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
#ifndef PHALCON_RELEASE
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
int phalcon_call_user_function(zval **object_pp, zend_class_entry *obj_ce, phalcon_call_type type, zval *function_name, zval **retval_ptr_ptr, zend_uint param_count, zval *params[] TSRMLS_DC)
{
	zval ***params_ptr, ***params_array = NULL;
	zval **static_params_array[10];
	zval *local_retval_ptr = NULL;
	int status;
	zend_fcall_info fci;
	zend_fcall_info_cache fcic /* , clone */;
	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;
	char *fcall_key;
	size_t fcall_key_len;
	ulong fcall_key_hash;
	phalcon_fcall_cache_entry **cache_entry = NULL;
	zend_class_entry *old_scope = EG(scope);

	assert(obj_ce || !object_pp);

	if (retval_ptr_ptr && *retval_ptr_ptr) {
		zval_ptr_dtor(retval_ptr_ptr);
		*retval_ptr_ptr = NULL;
	}

	++phalcon_globals_ptr->recursive_lock;

	if (UNEXPECTED(phalcon_globals_ptr->recursive_lock > 2048)) {
		zend_error(E_ERROR, "Maximum recursion depth exceeded");
		return FAILURE;
	}

	if (param_count) {
		zend_uint i;

		if (UNEXPECTED(param_count > 10)) {
			params_array = (zval***)emalloc(param_count * sizeof(zval**));
			params_ptr   = params_array;
			for (i=0; i<param_count; ++i) {
				params_array[i] = &params[i];
			}
		} else {
			params_ptr = static_params_array;
			for (i=0; i<param_count; ++i) {
				static_params_array[i] = &params[i];
			}
		}
	}
	else {
		params_ptr = NULL;
	}

	if (type != phalcon_fcall_function && !object_pp) {
		object_pp = EG(This) ? &EG(This) : NULL;
		if (!obj_ce && object_pp) {
			obj_ce = Z_OBJCE_PP(object_pp);
		}
	}

	if (obj_ce) {
		EG(scope) = obj_ce;
	}

	fcall_key_hash = phalcon_make_fcall_key(&fcall_key, &fcall_key_len, (object_pp ? Z_OBJCE_PP(object_pp) : obj_ce), type, function_name TSRMLS_CC);

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
	if (fcall_key && zend_hash_quick_find(phalcon_globals_ptr->fcache, fcall_key, fcall_key_len, fcall_key_hash, (void**)&cache_entry) != FAILURE) {
		phalcon_fcall_populate_fci_cache(&fcic, &fci, type TSRMLS_CC);

#ifndef PHALCON_RELEASE
		fcic.function_handler = (*cache_entry)->f;
		++(*cache_entry)->times;
#else
		fcic.function_handler = *cache_entry;
#endif
		/*memcpy(&clone, &fcic, sizeof(clone));*/
	}

	fcic.initialized = 0;
	status = PHALCON_ZEND_CALL_FUNCTION_WRAPPER(&fci, /*&fcic*/NULL TSRMLS_CC);

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

	if (EXPECTED(status != FAILURE) && fcall_key && !cache_entry && fcic.initialized) {
#ifndef PHALCON_RELEASE
		phalcon_fcall_cache_entry *cache_entry = malloc(sizeof(phalcon_fcall_cache_entry));
		cache_entry->f     = fcic.function_handler;
		cache_entry->times = 0;
#else
		phalcon_fcall_cache_entry *cache_entry = fcic.function_handler;
#endif
		if (FAILURE == zend_hash_quick_add(phalcon_globals_ptr->fcache, fcall_key, fcall_key_len, fcall_key_hash, &cache_entry, sizeof(phalcon_fcall_cache_entry*), NULL)) {
#ifndef PHALCON_RELEASE
			free(cache_entry);
#endif
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

	--phalcon_globals_ptr->recursive_lock;
	return status;
}

int phalcon_call_func_aparams(zval **return_value_ptr, const char *func_name, uint func_length, uint param_count, zval **params TSRMLS_DC)
{
	int status;
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	zval func = zval_used_for_init;

#ifndef PHALCON_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		phalcon_print_backtrace();
		abort();
	}
#endif

	ZVAL_STRINGL(&func, func_name, func_length, 0);
	status = phalcon_call_user_function(NULL, NULL, phalcon_fcall_function, &func, rvp, param_count, params TSRMLS_CC);

	if (status == FAILURE && !EG(exception)) {
		zend_error(E_ERROR, "Call to undefined function %s()", func_name);
	}
	else if (EG(exception)) {
		status = FAILURE;
		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	return status;
}

int phalcon_call_class_method_aparams(zval **return_value_ptr, zend_class_entry *ce, phalcon_call_type type, zval *object, const char *method_name, uint method_len, uint param_count, zval **params TSRMLS_DC)
{
	zval *rv = NULL, **rvp = return_value_ptr ? return_value_ptr : &rv;
	zval fn = zval_used_for_init;
	int status;

#ifndef PHALCON_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr must be NULL\n", __func__);
		phalcon_print_backtrace();
		abort();
	}
#endif

	array_init_size(&fn, 2);
	switch (type) {
		case phalcon_fcall_parent: add_next_index_stringl(&fn, ISL(parent), !IS_INTERNED(phalcon_interned_parent)); break;
		case phalcon_fcall_self:   assert(!ce); add_next_index_stringl(&fn, ISL(self), !IS_INTERNED(phalcon_interned_self)); break;
		case phalcon_fcall_static: assert(!ce); add_next_index_stringl(&fn, ISL(static), !IS_INTERNED(phalcon_interned_static)); break;

		case phalcon_fcall_ce:
			assert(ce != NULL);
			add_next_index_stringl(&fn, ce->name, ce->name_length, !IS_INTERNED(ce->name));
			break;

		case phalcon_fcall_method:
		default:
			assert(object != NULL);
			Z_ADDREF_P(object);
			add_next_index_zval(&fn, object);
			break;
	}

	add_next_index_stringl(&fn, method_name, method_len, 1);

	status = phalcon_call_user_function(object ? &object : NULL, ce, type, &fn, rvp, param_count, params TSRMLS_CC);

	if (status == FAILURE && !EG(exception)) {
		switch (type) {
			case phalcon_fcall_parent: zend_error(E_ERROR, "Call to undefined function parent::%s()", method_name); break;
			case phalcon_fcall_self:   zend_error(E_ERROR, "Call to undefined function self::%s()", method_name); break;
			case phalcon_fcall_static: zend_error(E_ERROR, "Call to undefined function static::%s()", method_name); break;
			case phalcon_fcall_ce:     zend_error(E_ERROR, "Call to undefined function %s::%s()", ce->name, method_name); break;
			case phalcon_fcall_method: zend_error(E_ERROR, "Call to undefined function %s::%s()", Z_OBJCE_P(object)->name, method_name); break;
			default:                   zend_error(E_ERROR, "Call to undefined function ?::%s()", method_name);
		}
	}
	else if (EG(exception)) {
		status = FAILURE;
		if (return_value_ptr) {
			*return_value_ptr = NULL;
		}
	}

	if (rv) {
		zval_ptr_dtor(&rv);
	}

	zval_dtor(&fn);
	return status;
}

/**
 * Replaces call_user_func_array avoiding function lookup
 * This function does not return FAILURE if an exception has ocurred
 */
int phalcon_call_user_func_array_noex(zval *return_value, zval *handler, zval *params TSRMLS_DC){

	zval *retval_ptr = NULL;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache;
	char *is_callable_error = NULL;
	int status = FAILURE;

	if (params && Z_TYPE_P(params) != IS_ARRAY) {
		ZVAL_NULL(return_value);
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments supplied for phalcon_call_user_func_array_noex()");
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
void phalcon_throw_exception_internal(zval *exception TSRMLS_DC)
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

int phalcon_call_function(zend_fcall_info *fci, zend_fcall_info_cache *fci_cache TSRMLS_DC) {

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
			zend_error(E_ERROR, "Corrupted fcall_info provided to phalcon_call_function()");
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
	if (fci->object_ptr && Z_TYPE_P(fci->object_ptr) == IS_OBJECT &&
		(!EG(objects_store).object_buckets || !EG(objects_store).object_buckets[Z_OBJ_HANDLE_P(fci->object_ptr)].valid)) {
		return FAILURE;
	}

	if (EX(function_state).function->common.fn_flags & ZEND_ACC_ABSTRACT) {
		zend_error_noreturn(E_ERROR, "Cannot call abstract method %s::%s()", EX(function_state).function->common.scope->name, EX(function_state).function->common.function_name);
		return FAILURE;
	}

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
		phalcon_throw_exception_internal(NULL TSRMLS_CC);
	}
	return SUCCESS;
}

#endif
