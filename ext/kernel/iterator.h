
/*
	+------------------------------------------------------------------------+
	| Zephir Language                                                        |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2014 Zephir Team  (http://www.zephir-lang.com)      |
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

#ifndef ZEPHIR_KERNEL_ITERATOR_H
#define ZEPHIR_KERNEL_ITERATOR_H	

zend_object_iterator *zephir_get_iterator(zval *iterator TSRMLS_DC);

#endif