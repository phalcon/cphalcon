
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

#include "annotations/reader.h"
#include "annotations/readerinterface.h"
#include "annotations/annot.h"
#include "annotations/exception.h"
#include "annotations/scanner.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/reflection.h"

/**
 * Phalcon\Annotations\Reader
 *
 * Parses docblocks returning an array with the found annotations
 */
zend_class_entry *phalcon_annotations_reader_ce;

PHP_METHOD(Phalcon_Annotations_Reader, parse);
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock);

static const zend_function_entry phalcon_annotations_reader_method_entry[] = {
	PHP_ME(Phalcon_Annotations_Reader, parse, arginfo_phalcon_annotations_readerinterface_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reader, parseDocBlock, arginfo_phalcon_annotations_readerinterface_parsedocblock, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Annotations\Reader initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Reader){

	PHALCON_REGISTER_CLASS(Phalcon\\Annotations, Reader, annotations_reader, phalcon_annotations_reader_method_entry, 0);

	zend_class_implements(phalcon_annotations_reader_ce TSRMLS_CC, 1, phalcon_annotations_readerinterface_ce);

	return SUCCESS;
}

/**
 * Reads annotations from the class dockblocks, its methods and/or properties
 *
 * @param string $className
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Reader, parse){

	zval *class_name, *annotations;
	zval *class_annotations, *annotations_properties, *annotations_methods;
	zend_class_entry *class_ce;
	const char *file;
	zend_uint line;

	phalcon_fetch_params(0, 1, 0, &class_name);

	if (unlikely(Z_TYPE_P(class_name) != IS_STRING)) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_annotations_exception_ce, "The class name must be a string");
		return;
	}

	class_ce = zend_fetch_class(Z_STRVAL_P(class_name), Z_STRLEN_P(class_name), ZEND_FETCH_CLASS_AUTO | ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!class_ce) {
		zend_throw_exception_ex(phalcon_annotations_exception_ce, 0 TSRMLS_CC, "Class %s does not exist", Z_STRVAL_P(class_name));
		return;
	}

	if (class_ce->type != ZEND_USER_CLASS) {
		array_init(return_value);
		return;
	}

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(annotations);
	array_init(annotations);

	file = phalcon_get_class_filename(class_ce);
	if (!file) {
		file = "(unknown)";
	}

	/* Class info */
	{
		const char *cmt;
		zend_uint cmt_len;

		if (phalcon_get_class_doc_comment(class_ce, &cmt, &cmt_len)) {
			line = phalcon_get_class_startline(class_ce);

			PHALCON_INIT_VAR(class_annotations);
			RETURN_MM_ON_FAILURE(phannot_parse_annotations(class_annotations, cmt, cmt_len, file, line TSRMLS_CC));

			if (Z_TYPE_P(class_annotations) == IS_ARRAY) {
				phalcon_array_update_string(&annotations, SL("class"), class_annotations, PH_COPY);
			}
		}
	}

	/* Get class properties */
	{
		HashTable *props = &class_ce->properties_info;
		if (zend_hash_num_elements(props) > 0) {
			HashPosition hp;
			zend_property_info *property;

			PHALCON_INIT_VAR(annotations_properties);
			array_init_size(annotations_properties, zend_hash_num_elements(props));

			for (
				zend_hash_internal_pointer_reset_ex(props, &hp);
				zend_hash_get_current_data_ex(props, (void**)&property, &hp) != FAILURE;
				zend_hash_move_forward_ex(props, &hp)
			) {
				const char *cmt;
				zend_uint cmt_len;

				if (phalcon_get_property_doc_comment(property, &cmt, &cmt_len)) {
					zval *property_annotations;

					MAKE_STD_ZVAL(property_annotations);
					if (FAILURE == phannot_parse_annotations(property_annotations, cmt, cmt_len, file, 0 TSRMLS_CC)) {
						zval_ptr_dtor(&property_annotations);
						RETURN_MM();
					}

					if (Z_TYPE_P(property_annotations) == IS_ARRAY) {
						#if PHP_VERSION_ID >= 50400
						{
							const char *prop_name, *class_name;
							if (zend_unmangle_property_name(property->name, property->name_length - 1, &class_name, &prop_name) == SUCCESS) {
								add_assoc_zval_ex(annotations_properties, prop_name, strlen(prop_name) + 1, property_annotations);
							}
						}
						#else
						{
							char *prop_name, *class_name;
							if (zend_unmangle_property_name(property->name, property->name_length - 1, &class_name, &prop_name) == SUCCESS) {
								add_assoc_zval_ex(annotations_properties, prop_name, strlen(prop_name) + 1, property_annotations);
							}
						}
						#endif
					} else {
						zval_ptr_dtor(&property_annotations);
					}
				}
			}

			if (zend_hash_num_elements(Z_ARRVAL_P(annotations_properties))) {
				phalcon_array_update_string(&annotations, SL("properties"), annotations_properties, PH_COPY);
			}
		}
	}

	/* Get class methods */
	{
		HashTable *methods = &class_ce->function_table;
		if (zend_hash_num_elements(methods) > 0) {
			HashPosition hp;
			zend_function *method;

			PHALCON_INIT_VAR(annotations_methods);
			array_init_size(annotations_methods, zend_hash_num_elements(methods));

			for (
				zend_hash_internal_pointer_reset_ex(methods, &hp);
				zend_hash_get_current_data_ex(methods, (void**)&method, &hp) != FAILURE;
				zend_hash_move_forward_ex(methods, &hp)
			) {
				const char *cmt;
				zend_uint cmt_len;

				if (phalcon_get_function_doc_comment(method, &cmt, &cmt_len)) {
					zval *method_annotations;

					line = phalcon_get_function_startline(method);

					MAKE_STD_ZVAL(method_annotations);
					if (FAILURE == phannot_parse_annotations(method_annotations, cmt, cmt_len, file, line TSRMLS_CC)) {
						zval_ptr_dtor(&method_annotations);
						RETURN_MM();
					}

					if (Z_TYPE_P(method_annotations) == IS_ARRAY) {
						add_assoc_zval_ex(annotations_methods, method->common.function_name, strlen(method->common.function_name) + 1, method_annotations);
					}
					else {
						zval_ptr_dtor(&method_annotations);
					}
				}
			}

			if (zend_hash_num_elements(Z_ARRVAL_P(annotations_methods))) {
				phalcon_array_update_string(&annotations, SL("methods"), annotations_methods, PH_COPY);
			}
		}
	}

	RETURN_CTOR(annotations);
}

/**
 * Parses a raw doc block returning the annotations found
 *
 * @param string $docBlock
 * @param string $file
 * @param int $line
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock)
{
	zval **doc_block, **file = NULL, **line = NULL;

	phalcon_fetch_params_ex(3, 0, &doc_block, &file, &line);

	PHALCON_ENSURE_IS_STRING(doc_block);
	PHALCON_ENSURE_IS_STRING(file);
	PHALCON_ENSURE_IS_LONG(line);

	RETURN_ON_FAILURE(phannot_parse_annotations(return_value, Z_STRVAL_PP(doc_block), Z_STRLEN_PP(doc_block), Z_STRVAL_PP(file), Z_LVAL_PP(line) TSRMLS_CC));
}
