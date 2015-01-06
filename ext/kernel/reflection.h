#ifndef PHALCON_KERNEL_REFLECTION_H
#define PHALCON_KERNEL_REFLECTION_H

#include "php_phalcon.h"

PHALCON_ATTR_NONNULL static inline const char* phalcon_get_class_doc_comment(const zend_class_entry *ce, const char **comment, zend_uint *len)
{
	if (ce->type == ZEND_USER_CLASS) {
#if PHP_VERSION_ID >= 50400
		*comment = ce->info.user.doc_comment;
		*len     = ce->info.user.doc_comment_len;
		return ce->info.user.doc_comment;
#else
		*comment = ce->doc_comment;
		*len     = ce->doc_comment_len;
		return ce->doc_comment;
#endif
	}

	*comment = NULL;
	*len     = 0;
	return NULL;
}

PHALCON_ATTR_NONNULL static inline const char* phalcon_get_class_filename(const zend_class_entry *ce)
{
	if (ce->type == ZEND_USER_CLASS) {
#if PHP_VERSION_ID >= 50400
		return ce->info.user.filename;
#else
		return ce->filename;
#endif
	}

	return NULL;
}

PHALCON_ATTR_NONNULL static inline zend_uint phalcon_get_class_startline(const zend_class_entry *ce)
{
	if (ce->type == ZEND_USER_CLASS) {
#if PHP_VERSION_ID >= 50400
		return ce->info.user.line_start;
#else
		return ce->line_start;
#endif
	}

	return 0;
}

static inline const char* phalcon_get_property_doc_comment(const zend_property_info *prop, const char **comment, zend_uint *len)
{
	*comment = prop->doc_comment;
	*len     = prop->doc_comment_len;
	return prop->doc_comment;
}

static inline const char* phalcon_get_function_doc_comment(const zend_function *func, const char **comment, zend_uint *len)
{
	if (func->type == ZEND_USER_FUNCTION) {
		*comment = func->op_array.doc_comment;
		*len     = func->op_array.doc_comment_len;
		return func->op_array.doc_comment;
	}

	return NULL;
}

static inline zend_uint phalcon_get_function_startline(const zend_function *func)
{
	if (func->type == ZEND_USER_FUNCTION) {
		return func->op_array.line_start;
	}

	return 0;
}

#endif /* PHALCON_KERNEL_REFLECTION_H */
