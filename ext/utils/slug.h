#ifndef PHALCON_UTILS_SLUG_H
#define PHALCON_UTILS_SLUG_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_utils_slug_ce;

PHALCON_INIT_CLASS(Phalcon_Utils_Slug);

PHP_METHOD(Phalcon_Utils_Slug, generate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_slug_generate, 0, 0, 1)
	ZEND_ARG_INFO(0, string)
	ZEND_ARG_INFO(0, replace)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_utils_slug_method_entry) {
	PHP_ME(Phalcon_Utils_Slug, generate, arginfo_phalcon_utils_slug_generate, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_FE_END
};

#endif /* PHALCON_UTILS_SLUG_H */
