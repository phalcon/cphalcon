
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "annotations/scanner.h"
#include "annotations/annot.h"
#include "kernel/array.h"
#include "kernel/file.h"

/**
 * Phalcon\Annotations\Reader
 *
 * Parses docblocks returning an array with the found annotations
 */


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

	zval *class_name, *annotations, *reflection;
	zval *comment = NULL, *file = NULL, *line = NULL, *class_annotations;
	zval *properties, *annotations_properties;
	zval *property = NULL, *property_annotations = NULL, *name = NULL;
	zval *methods, *annotations_methods, *method = NULL;
	zval *method_annotations = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &class_name);
	
	if (unlikely(Z_TYPE_P(class_name) != IS_STRING)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "The class name must be an object");
		return;
	}
	
	PHALCON_INIT_VAR(annotations);
	array_init(annotations);
	
	/** 
	 * A ReflectionClass is used to obtain the class dockblock
	 */
	ce0 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_INIT_VAR(reflection);
	object_init_ex(reflection, ce0);
	if (phalcon_has_constructor(reflection TSRMLS_CC)) {
		phalcon_call_method_p1_noret(reflection, "__construct", class_name);
	}
	
	PHALCON_INIT_VAR(comment);
	phalcon_call_method(comment, reflection, "getdoccomment");
	if (Z_TYPE_P(comment) == IS_STRING) {
	
		/** 
		 * Get the file where the class was declared
		 */
		PHALCON_INIT_VAR(file);
		phalcon_call_method(file, reflection, "getfilename");
	
		/** 
		 * Get the line where the class was declared
		 */
		PHALCON_INIT_VAR(line);
		phalcon_call_method(line, reflection, "getstartline");
	
		/** 
		 * Read annotations from class
		 */
		PHALCON_INIT_VAR(class_annotations);
		if (phannot_parse_annotations(class_annotations, comment, file, line TSRMLS_CC) == FAILURE) {
			return;
		}
	
		/** 
		 * Append the class annotations to the annotations var
		 */
		if (Z_TYPE_P(class_annotations) == IS_ARRAY) { 
			phalcon_array_update_string(&annotations, SL("class"), &class_annotations, PH_COPY | PH_SEPARATE);
		}
	}
	
	/** 
	 * Get the class properties
	 */
	PHALCON_INIT_VAR(properties);
	phalcon_call_method(properties, reflection, "getproperties");
	if (phalcon_fast_count_ev(properties TSRMLS_CC)) {
	
		/** 
		 * Line declaration for properties isn't available
		 */
		PHALCON_INIT_NVAR(line);
		ZVAL_LONG(line, 1);
	
		PHALCON_INIT_VAR(annotations_properties);
		array_init(annotations_properties);
	
		phalcon_is_iterable(properties, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(property);
	
			/** 
			 * Read comment from method
			 */
			PHALCON_INIT_NVAR(comment);
			phalcon_call_method(comment, property, "getdoccomment");
			if (Z_TYPE_P(comment) == IS_STRING) {
	
				/** 
				 * Get the file where the property was declared
				 */
				PHALCON_INIT_NVAR(file);
				phalcon_call_method(file, reflection, "getfilename");
	
				/** 
				 * Read annotations from the docblock
				 */
				PHALCON_INIT_NVAR(property_annotations);
				if (phannot_parse_annotations(property_annotations, comment, file, line TSRMLS_CC) == FAILURE) {
					return;
				}
				if (Z_TYPE_P(property_annotations) == IS_ARRAY) { 
					PHALCON_OBS_NVAR(name);
					phalcon_read_property(&name, property, SL("name"), PH_NOISY_CC);
					phalcon_array_update_zval(&annotations_properties, name, &property_annotations, PH_COPY | PH_SEPARATE);
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		if (phalcon_fast_count_ev(annotations_properties TSRMLS_CC)) {
			phalcon_array_update_string(&annotations, SL("properties"), &annotations_properties, PH_COPY | PH_SEPARATE);
		}
	}
	
	/** 
	 * Get the class methods
	 */
	PHALCON_INIT_VAR(methods);
	phalcon_call_method(methods, reflection, "getmethods");
	if (phalcon_fast_count_ev(methods TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(annotations_methods);
		array_init(annotations_methods);
	
		phalcon_is_iterable(methods, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(method);
	
			/** 
			 * Read comment from method
			 */
			PHALCON_INIT_NVAR(comment);
			phalcon_call_method(comment, method, "getdoccomment");
			if (Z_TYPE_P(comment) == IS_STRING) {
	
				/** 
				 * Get the file where the method was declared
				 */
				PHALCON_INIT_NVAR(file);
				phalcon_call_method(file, method, "getfilename");
	
				/** 
				 * Get the line where the method was declared
				 */
				PHALCON_INIT_NVAR(line);
				phalcon_call_method(line, method, "getstartline");
	
				/** 
				 * Read annotations from class
				 */
				PHALCON_INIT_NVAR(method_annotations);
				if (phannot_parse_annotations(method_annotations, comment, file, line TSRMLS_CC) == FAILURE) {
					return;
				}
				if (Z_TYPE_P(method_annotations) == IS_ARRAY) { 
					PHALCON_OBS_NVAR(name);
					phalcon_read_property(&name, method, SL("name"), PH_NOISY_CC);
					phalcon_array_update_zval(&annotations_methods, name, &method_annotations, PH_COPY | PH_SEPARATE);
				}
			}
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
		if (phalcon_fast_count_ev(annotations_methods TSRMLS_CC)) {
			phalcon_array_update_string(&annotations, SL("methods"), &annotations_methods, PH_COPY | PH_SEPARATE);
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
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock){

	zval *doc_block, *file = NULL, *line = NULL, *annotations;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &doc_block, &file, &line);
	
	if (!file) {
		PHALCON_INIT_VAR(file);
	} else {
		PHALCON_SEPARATE_PARAM(file);
	}
	
	if (!line) {
		PHALCON_INIT_VAR(line);
	}
	
	if (Z_TYPE_P(file) != IS_STRING) {
		PHALCON_INIT_NVAR(file);
		ZVAL_STRING(file, "eval code", 1);
	}
	
	PHALCON_INIT_VAR(annotations);
	if (phannot_parse_annotations(annotations, doc_block, file, line TSRMLS_CC) == FAILURE) {
		return;
	}
	
	RETURN_CTOR(annotations);
}

