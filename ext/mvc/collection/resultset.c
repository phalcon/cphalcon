
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "mvc/collection/resultset.h"
#include "mvc/collection/exception.h"
#include "mvc/collection.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/variables.h"
#include "kernel/exception.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Mvc\Collection\Resultset
 *
 * <code>
 *
 * //Using a standard foreach
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * foreach ($robots as $robot) {
 *  echo $robot->name, "\n";
 * }
 *
 * //Using a while
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * $robots->rewind();
 * while ($robots->valid()) {
 *  $robot = $robots->current();
 *  echo $robot->name, "\n";
 *  $robots->next();
 * }
 * </code>
 *
 */
zend_class_entry *phalcon_mvc_collection_resultset_ce;

PHP_METHOD(Phalcon_Mvc_Collection_Resultset, __construct);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, valid);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, toArray);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, serialize);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, unserialize);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, next);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, key);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, rewind);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, seek);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, count);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, offsetExists);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, offsetGet);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, offsetSet);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, getFirst);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, getLast);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, current);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, getMessages);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, delete);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, filter);
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, update);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_resultset___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, cursor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_resultset_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, renameColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_resultset_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, conditionCallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_resultset_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_resultset_update, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, conditionCallback)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_collection_resultset_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Collection_Resultset, __construct, arginfo_phalcon_mvc_collection_resultset___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, valid, arginfo_iterator_valid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, toArray, arginfo_phalcon_mvc_collection_resultset_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, serialize, arginfo_serializable_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, unserialize, arginfo_serializable_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, next, arginfo_iterator_next, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, key, arginfo_iterator_key, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, rewind, arginfo_iterator_rewind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, seek, arginfo_seekableiterator_seek, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, count, arginfo_countable_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, offsetExists, arginfo_arrayaccess_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, offsetGet, arginfo_arrayaccess_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, offsetSet, arginfo_arrayaccess_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, offsetUnset, arginfo_arrayaccess_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, getFirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, getLast, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, current, arginfo_iterator_current, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, delete, arginfo_phalcon_mvc_collection_resultset_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, filter, arginfo_phalcon_mvc_collection_resultset_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Resultset, update, arginfo_phalcon_mvc_collection_resultset_update, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection\Resultset initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Resultset){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Resultset, mvc_collection_resultset, phalcon_mvc_collection_resultset_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_resultset_ce, SL("_collection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_resultset_ce, SL("_cursor"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_collection_resultset_ce, SL("_pointer"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_resultset_ce, SL("_count"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_resultset_ce, SL("_activeRow"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_resultset_ce, SL("_rows"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_resultset_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_collection_resultset_ce TSRMLS_CC, 5, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable, zend_ce_arrayaccess, zend_ce_serializable);

	return SUCCESS;
}


/**
 * Phalcon\Mvc\Collection\Resultset constructor
 *
 * @param Phalcon\Mvc\CollectionInterface $collection
 * @param MongoCursor $cursor
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, __construct){

	zval *collection, *cursor, *row_count = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &collection, &cursor);

	phalcon_update_property_this(this_ptr, SL("_collection"), collection TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_cursor"), cursor TSRMLS_CC);
	if (Z_TYPE_P(cursor) != IS_OBJECT) {
		RETURN_MM_NULL();
	}

	PHALCON_CALL_METHOD(&row_count, cursor, "count", PHALCON_GLOBAL(z_true));

	phalcon_update_property_this(this_ptr, SL("_count"), row_count TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Check whether the internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, valid){

	zval *rows, *cursor = NULL, *row = NULL, *collection, *active_row = NULL;

	PHALCON_MM_GROW();

	rows = phalcon_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(rows) == IS_NULL) {
		PHALCON_OBS_VAR(cursor);
		phalcon_read_property_this(&cursor, this_ptr, SL("_cursor"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(cursor) == IS_OBJECT) {
			PHALCON_CALL_METHOD(NULL, cursor, "next");
			PHALCON_CALL_METHOD(&row, cursor, "current");
		} else {
			PHALCON_INIT_VAR(row);
			ZVAL_FALSE(row);
		}
	} else {
		if (Z_TYPE_P(rows) == IS_ARRAY) { 
			PHALCON_INIT_NVAR(row);
			phalcon_array_get_current(row, rows);
			if (PHALCON_IS_NOT_FALSE(row)) {
				zend_hash_move_forward(Z_ARRVAL_P(rows));
			}
		} else {
			PHALCON_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	}

	if (Z_TYPE_P(row) != IS_ARRAY) { 
		phalcon_update_property_bool(this_ptr, SL("_activeRow"), 0 TSRMLS_CC);
		RETURN_MM_FALSE;
	}

	PHALCON_OBS_VAR(collection);
	phalcon_read_property_this(&collection, this_ptr, SL("_collection"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_CE_STATIC(&active_row, phalcon_mvc_collection_ce, "cloneresult", collection, row);

	phalcon_update_property_this(this_ptr, SL("_activeRow"), active_row TSRMLS_CC);
	RETURN_MM_TRUE;
}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than it currently does. Exporting the resultset to an array
 * couldn't be faster with a large number of records
 *
 * @param boolean $renameColumns
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, toArray){

	zval *rename_columns = NULL, *records, *valid = NULL, *current = NULL, *arr = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &rename_columns);
	
	if (!rename_columns) {
		rename_columns = PHALCON_GLOBAL(z_true);
	}
	
	PHALCON_INIT_VAR(records);
	array_init(records);

	PHALCON_CALL_METHOD(NULL, this_ptr, "rewind");
	
	while (1) {
		PHALCON_CALL_METHOD(&valid, this_ptr, "valid");
		if (!PHALCON_IS_NOT_FALSE(valid)) {
			break;
		}
	
		PHALCON_CALL_METHOD(&current, this_ptr, "current");
		PHALCON_CALL_METHOD(&arr, current, "toarray", PHALCON_GLOBAL(z_null), rename_columns);
		phalcon_array_append(&records, arr, PH_COPY);
		PHALCON_CALL_METHOD(NULL, this_ptr, "next");
	}

	RETURN_CCTOR(records);
}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, serialize){

	zval *rename_columns, *records = NULL, *collection, *data;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(rename_columns);
	ZVAL_BOOL(rename_columns, 0);
	
	PHALCON_CALL_METHOD(&records, this_ptr, "toarray", rename_columns);
	
	PHALCON_OBS_VAR(collection);
	phalcon_read_property_this(&collection, this_ptr, SL("_collection"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(data);
	array_init_size(data, 3);
	phalcon_array_update_string(&data, SL("collection"), collection, PH_COPY);
	phalcon_array_update_string(&data, SL("rows"), records, PH_COPY);
	phalcon_update_property_bool(this_ptr, SL("_activeRow"), 0 TSRMLS_CC);
	
	/** 
	 * Serialize the cache using the serialize function
	 */
	phalcon_serialize(return_value, &data TSRMLS_CC);
	RETURN_MM();
}

/**
 * Unserializing a resultset only works on the rows present in the saved state
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, unserialize){

	zval *data, *resultset, *collection, *rows;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	PHALCON_INIT_VAR(resultset);
	phalcon_unserialize(resultset, data TSRMLS_CC);
	if (Z_TYPE_P(resultset) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid serialization data");
		return;
	}
	
	PHALCON_OBS_VAR(collection);
	phalcon_array_fetch_string(&collection, resultset, SL("collection"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_collection"), collection TSRMLS_CC);
	
	PHALCON_OBS_VAR(rows);
	phalcon_array_fetch_string(&rows, resultset, SL("rows"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Moves cursor to next row in the resultset
 *
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, next){


	phalcon_property_incr(this_ptr, SL("_pointer") TSRMLS_CC);

}

/**
 * Gets pointer number of active row in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, key){


	RETURN_MEMBER(this_ptr, "_pointer");
}

/**
 * Rewinds resultset to its beginning
 *
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, rewind){

	zval *z_zero, *cursor, *active_row, *rows;

	PHALCON_MM_GROW();

	z_zero = PHALCON_GLOBAL(z_zero);

	rows = phalcon_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(rows) == IS_NULL) {
		cursor = phalcon_fetch_nproperty_this(this_ptr, SL("_cursor"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(cursor) == IS_OBJECT) {
			active_row = phalcon_fetch_nproperty_this(this_ptr, SL("_activeRow"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(active_row) != IS_NULL) {
				
				PHALCON_CALL_METHOD(NULL, cursor, "reset");
			}
		}
	} else if (Z_TYPE_P(rows) == IS_ARRAY) {
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(rows), NULL);
	}

	phalcon_update_property_this(this_ptr, SL("_pointer"), z_zero TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Changes internal pointer to a specific position in the resultset
 *
 * @param int $position
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, seek){

	zval *position, *rows, *cursor, *pointer, *is_different;
	HashTable *ah0;
	long i;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &position) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(NULL, this_ptr, "rewind");

	convert_to_long(position);

	PHALCON_OBS_VAR(pointer);
	phalcon_read_property(&pointer, this_ptr, SL("_pointer"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(is_different);
	is_not_equal_function(is_different, pointer, position TSRMLS_CC);
	if (PHALCON_IS_TRUE(is_different)) {
		phalcon_update_property_zval(this_ptr, SL("_pointer"), position TSRMLS_CC);
		rows = phalcon_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(rows) == IS_NULL) {
			PHALCON_OBS_VAR(cursor);
			phalcon_read_property(&cursor, this_ptr, SL("_cursor"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(cursor) == IS_OBJECT) {
				PHALCON_CALL_METHOD(NULL, cursor, "skip", position);
			}
		} else {
			if (Z_TYPE_P(rows) == IS_ARRAY) { 
				ah0 = Z_ARRVAL_P(rows);
				zend_hash_internal_pointer_reset(ah0);

				i = 0;
				while (1) {
					if (i >= Z_LVAL_P(position)) {
						break;
					}

					zend_hash_move_forward(ah0);
					i++;
				}
			}
		}
	}

	PHALCON_MM_RESTORE();
}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, count){

	zval *count = NULL, *rows, *cursor = NULL, *number_rows = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(count);
	phalcon_read_property_this(&count, this_ptr, SL("_count"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(count) == IS_NULL) {

		PHALCON_INIT_NVAR(count);
		ZVAL_LONG(count, 0);

		rows = phalcon_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(rows) == IS_NULL) {
			PHALCON_OBS_VAR(cursor);
			phalcon_read_property_this(&cursor, this_ptr, SL("_cursor"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(cursor) == IS_OBJECT) {
				PHALCON_CALL_METHOD(&number_rows, cursor, "count", PHALCON_GLOBAL(z_true));

				PHALCON_INIT_NVAR(count);
				ZVAL_LONG(count, phalcon_get_intval(number_rows));
			}
		} else {
			PHALCON_INIT_NVAR(count);
			phalcon_fast_count(count, rows TSRMLS_CC);
		}

		phalcon_update_property_this(this_ptr, SL("_count"), count TSRMLS_CC);
	}

	RETURN_CCTOR(count);
}

/**
 * Checks whether offset exists in the resultset
 *
 * @param int $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, offsetExists){

	zval *index, *count = NULL;

	phalcon_fetch_params(0, 1, 0, &index);

	PHALCON_CALL_METHODW(&count, this_ptr, "count");
	is_smaller_function(return_value, index, count TSRMLS_CC);
	zval_ptr_dtor(&count);
}

/**
 * Gets row in a specific position of the resultset
 *
 * @param int $index
 * @return Phalcon\Mvc\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, offsetGet){

	zval *index, *count = NULL, *pointer, *valid = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);

	PHALCON_CALL_METHOD(&count, this_ptr, "count");
	if (PHALCON_LT(index, count)) {
		/** 
		 * Check if the last record returned is the current requested
		 */
		PHALCON_OBS_VAR(pointer);
		phalcon_read_property_this(&pointer, this_ptr, SL("_pointer"), PH_NOISY TSRMLS_CC);
		if (PHALCON_IS_EQUAL(pointer, index)) {
			PHALCON_RETURN_CALL_METHOD(this_ptr, "current");
			RETURN_MM();
		}

		/** 
		 * Move the cursor to the specific position
		 */
		PHALCON_CALL_METHOD(NULL, this_ptr, "seek", index);

		/** 
		 * Check if the last record returned is the requested
		 */
		PHALCON_CALL_METHOD(&valid, this_ptr, "valid");
		if (PHALCON_IS_NOT_FALSE(valid)) {
			PHALCON_RETURN_CALL_METHOD(this_ptr, "current");
			RETURN_MM();
		}

		RETURN_MM_FALSE;
	}

	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The index does not exist in the cursor");
	return;
}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $index
 * @param Phalcon\Mvc\Collection\Document $value
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, offsetSet){

	zval *index, *value;

	phalcon_fetch_params(0, 2, 0, &index, &value);

	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_collection_exception_ce, "Cursor is an immutable ArrayAccess object");
	return;
}

/**
 * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 *
 * @param int $offset
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, offsetUnset){

	zval *offset;

	phalcon_fetch_params(0, 1, 0, &offset);

	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_collection_exception_ce, "Cursor is an immutable ArrayAccess object");
	return;
}

/**
 * Get first row in the resultset
 *
 * @return Phalcon\Mvc\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, getFirst){

	zval *pointer, *valid = NULL;

	PHALCON_MM_GROW();

	/** 
	 * Check if the last record returned is the current requested
	 */
	PHALCON_OBS_VAR(pointer);
	phalcon_read_property_this(&pointer, this_ptr, SL("_pointer"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_LONG(pointer, 0)) {
		PHALCON_RETURN_CALL_METHOD(this_ptr, "current");
		RETURN_MM();
	}

	/** 
	 * Otherwise re-execute the statement
	 */
	PHALCON_CALL_METHOD(NULL, this_ptr, "rewind");

	PHALCON_CALL_METHOD(&valid, this_ptr, "valid");
	if (PHALCON_IS_NOT_FALSE(valid)) {
		PHALCON_RETURN_CALL_METHOD(this_ptr, "current");
		RETURN_MM();
	}

	RETURN_MM_FALSE;
}

/**
 * Get last row in the resultset
 *
 * @return Phalcon\Mvc\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, getLast){

	zval *z_one, *count = NULL, *pre_count, *valid = NULL;

	PHALCON_MM_GROW();

	z_one = PHALCON_GLOBAL(z_one);

	PHALCON_CALL_METHOD(&count, this_ptr, "count");

	PHALCON_INIT_VAR(pre_count);
	phalcon_sub_function(pre_count, count, z_one);
	PHALCON_CALL_METHOD(NULL, this_ptr, "seek", pre_count);

	PHALCON_CALL_METHOD(&valid, this_ptr, "valid");
	if (PHALCON_IS_NOT_FALSE(valid)) {
		PHALCON_RETURN_CALL_METHOD(this_ptr, "current");
		RETURN_MM();
	}

	RETURN_MM_FALSE;
}

/**
 * Returns current row in the resultset
 *
 * @return Phalcon\Mvc\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, current){


	RETURN_MEMBER(this_ptr, "_activeRow");
}

/**
 * Returns the error messages produced by a batch operation
 *
 * @return Phalcon\Mvc\Collection\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, getMessages){


	RETURN_MEMBER(this_ptr, "_errorMessages");
}

/**
 * Deletes every record in the resultset
 *
 * @param Closure $conditionCallback
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, delete){

	zval *condition_callback = NULL, *transaction = NULL, *record = NULL;
	zval *connection = NULL, *parameters = NULL, *status = NULL, *messages = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &condition_callback);

	if (!condition_callback) {
		condition_callback = PHALCON_GLOBAL(z_null);
	}

	PHALCON_INIT_VAR(transaction);
	ZVAL_FALSE(transaction);
	PHALCON_CALL_METHOD(NULL, this_ptr, "rewind");

	while (1) {
		PHALCON_CALL_METHOD(&r0, this_ptr, "valid");
		if (zend_is_true(r0)) {
		} else {
			break;
		}

		PHALCON_CALL_METHOD(&record, this_ptr, "current");
		if (PHALCON_IS_FALSE(transaction)) {

			/** 
			 * We only can delete resultsets whose every element is a complete object
			 */
			if (phalcon_method_exists_ex(record, SS("getwriteconnection") TSRMLS_CC) == FAILURE) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The returned record is not valid");
				return;
			}

			PHALCON_CALL_METHOD(&connection, record, "getwriteconnection");
			PHALCON_CALL_METHOD(NULL, connection, "begin");

			PHALCON_INIT_NVAR(transaction);
			ZVAL_TRUE(transaction);
		}

		/** 
		 * Perform additional validations
		 */
		if (Z_TYPE_P(condition_callback) == IS_OBJECT) {

			PHALCON_INIT_NVAR(parameters);
			array_init_size(parameters, 1);
			phalcon_array_append(&parameters, record, PH_COPY);

			PHALCON_INIT_NVAR(status);/**/
			PHALCON_CALL_USER_FUNC_ARRAY(status, condition_callback, parameters);
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}
		}

		/** 
		 * Try to delete the record
		 */
		PHALCON_CALL_METHOD(&status, record, "delete");
		if (!zend_is_true(status)) {
			/** 
			 * Get the messages from the record that produce the error
			 */
			PHALCON_CALL_METHOD(&messages, record, "getmessages");
			phalcon_update_property_this(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);

			/** 
			 * Rollback the transaction
			 */
			PHALCON_CALL_METHOD(NULL, connection, "rollback");

			PHALCON_INIT_NVAR(transaction);
			ZVAL_BOOL(transaction, 0);
			break;
		}

		PHALCON_CALL_METHOD(NULL, this_ptr, "next");
	}

	/** 
	 * Commit the transaction
	 */
	if (PHALCON_IS_TRUE(transaction)) {
		PHALCON_CALL_METHOD(NULL, connection, "commit");
	}

	RETURN_MM_TRUE;
}

/**
 * Filters a resultset returning only those the developer requires
 *
 *<code>
 * $filtered = $robots->filter(function($robot){
 *		if ($robot->id < 3) {
 *			return $robot;
 *		}
 *	});
 *</code>
 *
 * @param callback $filter
 * @return Phalcon\Mvc\Collection[]
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, filter){

	zval *filter, *records, *parameters, *record = NULL, *processed_record = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &filter);

	PHALCON_INIT_VAR(records);
	array_init(records);
	PHALCON_CALL_METHOD(NULL, this_ptr, "rewind");

	PHALCON_INIT_VAR(parameters);
	array_init(parameters);

	while (1) {

		PHALCON_CALL_METHOD(&r0, this_ptr, "valid");
		if (zend_is_true(r0)) {
		} else {
			break;
		}

		PHALCON_CALL_METHOD(&record, this_ptr, "current");
		phalcon_array_update_long(&parameters, 0, record, PH_COPY);

		PHALCON_INIT_NVAR(processed_record);/**/
		PHALCON_CALL_USER_FUNC_ARRAY(processed_record, filter, parameters);

		/** 
		 * Only add processed records to 'records' if the returned value is an array/object
		 */
		if (Z_TYPE_P(processed_record) != IS_OBJECT) {
			if (Z_TYPE_P(processed_record) != IS_ARRAY) { 
				continue;
			}
		}

		phalcon_array_append(&records, processed_record, PH_COPY);
		PHALCON_CALL_METHOD(NULL, this_ptr, "next");
	}

	RETURN_CTOR(records);
}

/**
 * Updates every record in the resultset
 *
 * @param array $data
 * @param Closure $conditionCallback
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Resultset, update){

	zval *data, *condition_callback = NULL, *transaction = NULL, *record = NULL;
	zval *connection = NULL, *parameters = NULL, *status = NULL, *messages = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &data, &condition_callback);

	if (!condition_callback) {
		condition_callback = PHALCON_GLOBAL(z_null);
	}

	PHALCON_INIT_VAR(transaction);
	ZVAL_FALSE(transaction);
	PHALCON_CALL_METHOD(NULL, this_ptr, "rewind");

	while (1) {
		PHALCON_CALL_METHOD(&r0, this_ptr, "valid");
		if (zend_is_true(r0)) {
		} else {
			break;
		}

		PHALCON_CALL_METHOD(&record, this_ptr, "current");
		if (PHALCON_IS_FALSE(transaction)) {

			/** 
			 * We only can update resultsets whose every element is a complete object
			 */
			if (phalcon_method_exists_ex(record, SS("getwriteconnection") TSRMLS_CC) == FAILURE) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "The returned record is not valid");
				return;
			}

			PHALCON_CALL_METHOD(&connection, record, "getwriteconnection");
			PHALCON_CALL_METHOD(NULL, connection, "begin");

			PHALCON_INIT_NVAR(transaction);
			ZVAL_TRUE(transaction);
		}

		/** 
		 * Perform additional validations
		 */
		if (Z_TYPE_P(condition_callback) == IS_OBJECT) {

			PHALCON_INIT_NVAR(parameters);
			array_init_size(parameters, 1);
			phalcon_array_append(&parameters, record, PH_COPY);

			PHALCON_INIT_NVAR(status);/**/
			PHALCON_CALL_USER_FUNC_ARRAY(status, condition_callback, parameters);
			if (PHALCON_IS_FALSE(status)) {
				continue;
			}
		}

		/** 
		 * Try to update the record
		 */
		PHALCON_CALL_METHOD(&status, record, "save", data);
		if (!zend_is_true(status)) {
			/** 
			 * Get the messages from the record that produce the error
			 */
			PHALCON_CALL_METHOD(&messages, record, "getmessages");
			phalcon_update_property_this(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);

			/** 
			 * Rollback the transaction
			 */
			PHALCON_CALL_METHOD(NULL, connection, "rollback");

			PHALCON_INIT_NVAR(transaction);
			ZVAL_BOOL(transaction, 0);
			break;
		}

		PHALCON_CALL_METHOD(NULL, this_ptr, "next");
	}

	/** 
	 * Commit the transaction
	 */
	if (PHALCON_IS_TRUE(transaction)) {
		PHALCON_CALL_METHOD(NULL, connection, "commit");
	}

	RETURN_MM_TRUE;
}
