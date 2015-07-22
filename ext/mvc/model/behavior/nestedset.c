
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

#include "mvc/model/behavior/nestedset.h"
#include "mvc/model/behavior.h"
#include "mvc/model/behaviorinterface.h"
#include "mvc/model/exception.h"
#include "mvc/modelinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\Behavior\NestedSet
 *
 */
zend_class_entry *phalcon_mvc_model_behavior_nestedset_ce;

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, notify);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, missingMethod);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, setOwner);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getOwner);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getLeftAttribute);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getRightAttribute);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getLevelAttribute);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getRootAttribute);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getPrimaryKey);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, setHasManyRoots);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, hasManyRoots);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isNewRecord);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isDeletedRecord);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isLeaf);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isRoot);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isDescendantOf);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, descendants);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, children);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, ancestors);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, roots);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, parent);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, prev);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, next);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, prependTo);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, prepend);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, appendTo);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, append);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, insertBefore);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, insertAfter);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveBefore);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveAfter);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsFirst);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsLast);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsRoot);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, saveNode);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, deleteNode);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveNode);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, shiftLeftRight);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, addNode);
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, makeRoot);


ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_missingmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, owner)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_setowner, 0, 0, 1)
	ZEND_ARG_INFO(0, owner)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_getleftattribute, 0, 0, 0)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_getrightattribute, 0, 0, 0)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_getlevelattribute, 0, 0, 0)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_getrootattribute, 0, 0, 0)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_getprimarykey, 0, 0, 0)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_sethasmanyroots, 0, 0, 1)
	ZEND_ARG_INFO(0, manyroots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_isdescendantof, 0, 0, 1)
	ZEND_ARG_INFO(0, subj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_descendants, 0, 0, 0)
	ZEND_ARG_INFO(0, depth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_ancestors, 0, 0, 0)
	ZEND_ARG_INFO(0, depth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_prependto, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_prepend, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_appendto, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_append, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_insertbefore, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_insertafter, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_movebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_moveafter, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_moveasfirst, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_moveaslast, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_savenode, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, white_list)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_movenode, 0, 0, 3)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, level_up)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_shiftleftright, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, delta)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_addnode, 0, 0, 4)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, level_up)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_nestedset_makeroot, 0, 0, 2)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, white_list)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_behavior_nestedset_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, __construct, arginfo_phalcon_mvc_model_behavior_nestedset___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, notify, arginfo_phalcon_mvc_model_behaviorinterface_notify, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, missingMethod, arginfo_phalcon_mvc_model_behavior_nestedset_missingmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, setOwner, arginfo_phalcon_mvc_model_behavior_nestedset_setowner, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, getOwner, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, getLeftAttribute, arginfo_phalcon_mvc_model_behavior_nestedset_getleftattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, getRightAttribute, arginfo_phalcon_mvc_model_behavior_nestedset_getrightattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, getLevelAttribute, arginfo_phalcon_mvc_model_behavior_nestedset_getlevelattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, getRootAttribute, arginfo_phalcon_mvc_model_behavior_nestedset_getrootattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, getPrimaryKey, arginfo_phalcon_mvc_model_behavior_nestedset_getprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, setHasManyRoots, arginfo_phalcon_mvc_model_behavior_nestedset_sethasmanyroots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, hasManyRoots, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, isNewRecord, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, isDeletedRecord, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, isLeaf, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, isRoot, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, isDescendantOf, arginfo_phalcon_mvc_model_behavior_nestedset_isdescendantof, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, descendants, arginfo_phalcon_mvc_model_behavior_nestedset_descendants, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, children, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, ancestors, arginfo_phalcon_mvc_model_behavior_nestedset_ancestors, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, roots, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, parent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, prev, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, prependTo, arginfo_phalcon_mvc_model_behavior_nestedset_prependto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, prepend, arginfo_phalcon_mvc_model_behavior_nestedset_prepend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, appendTo, arginfo_phalcon_mvc_model_behavior_nestedset_appendto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, append, arginfo_phalcon_mvc_model_behavior_nestedset_append, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, insertBefore, arginfo_phalcon_mvc_model_behavior_nestedset_insertbefore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, insertAfter, arginfo_phalcon_mvc_model_behavior_nestedset_insertafter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, moveBefore, arginfo_phalcon_mvc_model_behavior_nestedset_movebefore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, moveAfter, arginfo_phalcon_mvc_model_behavior_nestedset_moveafter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsFirst, arginfo_phalcon_mvc_model_behavior_nestedset_moveasfirst, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsLast, arginfo_phalcon_mvc_model_behavior_nestedset_moveaslast, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsRoot, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, saveNode, arginfo_phalcon_mvc_model_behavior_nestedset_savenode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, deleteNode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, moveNode, arginfo_phalcon_mvc_model_behavior_nestedset_shiftleftright, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, shiftLeftRight, arginfo_phalcon_mvc_model_behavior_nestedset_shiftleftright, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, addNode, arginfo_phalcon_mvc_model_behavior_nestedset_addnode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior_NestedSet, makeRoot, arginfo_phalcon_mvc_model_behavior_nestedset_makeroot, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Behavior\NestedSet initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior_NestedSet){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, NestedSet, mvc_model_behavior_nestedset, phalcon_mvc_model_behavior_ce, phalcon_mvc_model_behavior_nestedset_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_behavior_nestedset_ce, SL("_owner"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_behavior_nestedset_ce, SL("_hasManyRoots"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_behavior_nestedset_ce, SL("_rootAttribute"), "root", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_behavior_nestedset_ce, SL("_leftAttribute"), "lft", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_behavior_nestedset_ce, SL("_rightAttribute"), "rgt", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_behavior_nestedset_ce, SL("_levelAttribute"), "lvl", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_behavior_nestedset_ce, SL("_primaryKey"), "id", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_behavior_nestedset_ce, SL("_ignoreEvent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_behavior_nestedset_ce TSRMLS_CC, 1, phalcon_mvc_model_behaviorinterface_ce);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, __construct){

	zval *options = NULL, *option = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);

	if (options && Z_TYPE_P(options) == IS_ARRAY) {
		if (phalcon_array_isset_string(options, SS("hasManyRoots"))) {
			PHALCON_OBS_NVAR(option);
			phalcon_array_fetch_string(&option, options, SL("hasManyRoots"), PH_NOISY);

			phalcon_update_property_this(this_ptr, SL("_hasManyRoots"), option TSRMLS_CC);
		}

		if (phalcon_array_isset_string(options, SS("rootAttribute"))) {
			PHALCON_OBS_NVAR(option);
			phalcon_array_fetch_string(&option, options, SL("rootAttribute"), PH_NOISY);

			phalcon_update_property_this(this_ptr, SL("_rootAttribute"), option TSRMLS_CC);
		}

		if (phalcon_array_isset_string(options, SS("leftAttribute"))) {
			PHALCON_OBS_NVAR(option);
			phalcon_array_fetch_string(&option, options, SL("leftAttribute"), PH_NOISY);

			phalcon_update_property_this(this_ptr, SL("_leftAttribute"), option TSRMLS_CC);
		}

		if (phalcon_array_isset_string(options, SS("rightAttribute"))) {
			PHALCON_OBS_NVAR(option);
			phalcon_array_fetch_string(&option, options, SL("rightAttribute"), PH_NOISY);

			phalcon_update_property_this(this_ptr, SL("_rightAttribute"), option TSRMLS_CC);
		}

		if (phalcon_array_isset_string(options, SS("levelAttribute"))) {
			PHALCON_OBS_NVAR(option);
			phalcon_array_fetch_string(&option, options, SL("levelAttribute"), PH_NOISY);

			phalcon_update_property_this(this_ptr, SL("_levelAttribute"), option TSRMLS_CC);
		}

		if (phalcon_array_isset_string(options, SS("primaryKey"))) {
			PHALCON_OBS_NVAR(option);
			phalcon_array_fetch_string(&option, options, SL("primaryKey"), PH_NOISY);

			phalcon_update_property_this(this_ptr, SL("_primaryKey"), option TSRMLS_CC);
		}
	}

	PHALCON_MM_RESTORE();
}

/**
 * Listens for notifications from the models manager
 *
 * @param string $type
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, notify){

	zval *type, *model, *ignore_event, *message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &model);

	ignore_event = phalcon_fetch_nproperty_this(this_ptr, SL("_ignoreEvent"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(ignore_event)) {
		PHALCON_INIT_VAR(message);
		ZVAL_STRING(message, "You should not use this method when NestedSetBehavior attached. Use the methods of behavior", 1);

		if (PHALCON_IS_STRING(type, "beforeCreate") || PHALCON_IS_STRING(type, "beforeUpdate") || PHALCON_IS_STRING(type, "beforeDelete")) {
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, message);
			return;
		}
	}

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, missingMethod){

	zval *owner, *method, *arguments = NULL, *call_object = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &owner, &method, &arguments);

	if (Z_TYPE_P(method) != IS_STRING) {
		PHALCON_SEPARATE_PARAM(method);
		convert_to_string(method);
	}

	if (phalcon_method_exists(this_ptr, method TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_CALL_SELF(NULL, "setowner", owner);

	PHALCON_INIT_VAR(call_object);
	array_init_size(call_object, 2);
	phalcon_array_append(&call_object, this_ptr, PH_COPY);
	phalcon_array_append(&call_object, method, PH_COPY);

	PHALCON_CALL_USER_FUNC_ARRAY(return_value, call_object, arguments);

	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, setOwner){

	zval *owner;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &owner);

	PHALCON_VERIFY_INTERFACE(owner, phalcon_mvc_modelinterface_ce);

	phalcon_update_property_this(this_ptr, SL("_owner"), owner TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getOwner){

	RETURN_MEMBER(this_ptr, "_owner");
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getLeftAttribute){

	zval *model = NULL, *left_attribute, *left;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &model);

	if (!model) {
		model = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);
	}

	PHALCON_VERIFY_INTERFACE(model, phalcon_mvc_modelinterface_ce);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(left);
	phalcon_read_property_zval(&left, model, left_attribute, PH_NOISY TSRMLS_CC);

	RETURN_CTOR(left);
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getRightAttribute){

	zval *model = NULL, *right_attribute, *right;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &model);

	if (!model) {
		model = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);
	}

	PHALCON_VERIFY_INTERFACE(model, phalcon_mvc_modelinterface_ce);

	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(right);
	phalcon_read_property_zval(&right, model, right_attribute, PH_NOISY TSRMLS_CC);

	RETURN_CTOR(right);
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getLevelAttribute){

	zval *model = NULL, *level_attribute, *level;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &model);

	if (!model) {
		model = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);
	}

	PHALCON_VERIFY_INTERFACE(model, phalcon_mvc_modelinterface_ce);

	level_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_levelAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(level);
	phalcon_read_property_zval(&level, model, level_attribute, PH_NOISY TSRMLS_CC);

	RETURN_CTOR(level);
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getRootAttribute){

	zval *model = NULL, *root_attribute, *root;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &model);

	if (!model) {
		model = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);
	}

	PHALCON_VERIFY_INTERFACE(model, phalcon_mvc_modelinterface_ce);

	root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(root);
	phalcon_read_property_zval(&root, model, root_attribute, PH_NOISY TSRMLS_CC);

	RETURN_CTOR(root);
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, getPrimaryKey){

	zval *model = NULL, *primary_key, *primary_key_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &model);

	if (!model) {
		model = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);
	}

	PHALCON_VERIFY_INTERFACE(model, phalcon_mvc_modelinterface_ce);

	primary_key = phalcon_fetch_nproperty_this(this_ptr, SL("_primaryKey"), PH_NOISY TSRMLS_CC);

	PHALCON_OBS_VAR(primary_key_value);
	phalcon_read_property_zval(&primary_key_value, model, primary_key, PH_NOISY TSRMLS_CC);

	RETURN_CTOR(primary_key_value);
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, setHasManyRoots){

	zval *manyroots;

	phalcon_fetch_params(0, 1, 0, &manyroots);

	if (zend_is_true(manyroots)) {
		phalcon_update_property_bool(this_ptr, SL("_hasManyRoots"), 1 TSRMLS_CC);
	} else {
		phalcon_update_property_bool(this_ptr, SL("_hasManyRoots"), 0 TSRMLS_CC);
	}
}

PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, hasManyRoots){

	RETURN_MEMBER(this_ptr, "_hasManyRoots");
}

/**
 * Returns if the current node is new
 *
 * @return boolean whether the node is new
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isNewRecord){

	zval *owner;

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	PHALCON_VERIFY_INTERFACEW(owner, phalcon_mvc_modelinterface_ce);

	PHALCON_RETURN_CALL_METHODW(owner, "isnewrecord");
}

/**
 * Returns if the current node is deleted
 *
 * @return boolean whether the node is deleted
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isDeletedRecord){

	zval *owner;

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	PHALCON_VERIFY_INTERFACEW(owner, phalcon_mvc_modelinterface_ce);

	PHALCON_RETURN_CALL_METHODW(owner, "isdeletedrecord");
}

/**
 * Determines if node is leaf.
 *
 * @return boolean whether the node is leaf.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isLeaf){

	zval *left = NULL, *right = NULL;

	PHALCON_CALL_SELFW(&left, "getleftattribute");
	PHALCON_CALL_SELFW(&right, "getrightattribute");

	if ((phalcon_get_intval(right) - phalcon_get_intval(left)) == 1) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

/**
 * Determines if node is root.
 *
 * @return boolean whether the node is root.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isRoot){

	zval *left = NULL;

	PHALCON_CALL_SELFW(&left, "getleftattribute");

	if (phalcon_is_equal_long(left, 1 TSRMLS_CC)) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

/**
 * Determines if node is descendant of subject node.
 *
 * @param Phalcon\Mvc\ModelInterface $subj the subject node.
 *
 * @return boolean whether the node is descendant of subject node.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, isDescendantOf){

	zval *subj, *left = NULL, *right = NULL, *left2 = NULL, *right2 = NULL;
	zval *has_many_roots, *root = NULL, *root2 = NULL;
	int result;

	phalcon_fetch_params(0, 1, 0, &subj);

	PHALCON_VERIFY_INTERFACEW(subj, phalcon_mvc_modelinterface_ce);

	PHALCON_CALL_SELFW(&left, "getleftattribute");
	PHALCON_CALL_SELFW(&right, "getrightattribute");

	PHALCON_CALL_SELFW(&left2, "getleftattribute", subj);
	PHALCON_CALL_SELFW(&right2, "getrightattribute", subj);

	result = (phalcon_get_intval(left) > phalcon_get_intval(left2)) && (phalcon_get_intval(right) < phalcon_get_intval(right2));

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	if (zend_is_true(has_many_roots)) {
		PHALCON_CALL_SELFW(&root, "getrootattribute");
		PHALCON_CALL_SELFW(&root2, "getrootattribute", subj);

		result = result && (PHALCON_IS_EQUAL(root, root2));
	}

	if (result) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

/**
 * Named scope. Gets descendants for node.
 *
 * @param int $depth the depth.
 *
 * @return \Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, descendants){

	zval *depth, *owner, *left_attribute, *left = NULL, *right_attribute, *right = NULL, *has_many_roots;
	zval *query = NULL, *statement, *level_attribute, *level = NULL, *root_attribute, *root = NULL, *tmp = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &depth);

	if (!depth) {
		depth = PHALCON_GLOBAL(z_null);
	} else if (Z_TYPE_P(depth) != IS_NULL && Z_TYPE_P(depth) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(depth);
		convert_to_long(depth);
	}

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_SELF(&left, "getleftattribute");
	PHALCON_CALL_SELF(&right, "getrightattribute");

	PHALCON_CALL_METHOD(&query, owner, "query");

	PHALCON_INIT_VAR(statement);
	PHALCON_CONCAT_VSV(statement, left_attribute, ">", left);
	PHALCON_CALL_METHOD(NULL, query, "where", statement);

	PHALCON_INIT_NVAR(statement);
	PHALCON_CONCAT_VSV(statement, right_attribute, "<", right);
	PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);

	if (Z_TYPE_P(depth) != IS_NULL) {
		level_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_levelAttribute"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_SELF(&level, "getlevelattribute");

		PHALCON_INIT_NVAR(tmp);
		phalcon_add_function(tmp, level, depth);

		PHALCON_INIT_NVAR(statement);
		PHALCON_CONCAT_VSV(statement, level_attribute, "<=", tmp);
		PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);
	}

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);
	root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);

	if (zend_is_true(has_many_roots)) {
		PHALCON_CALL_SELF(&root, "getrootattribute");

		PHALCON_INIT_NVAR(statement);
		PHALCON_CONCAT_VSV(statement, root_attribute, "=", root);
		PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);
	}

	PHALCON_INIT_NVAR(tmp);
	PHALCON_CONCAT_VSV(tmp, root_attribute, ",", left_attribute);

	PHALCON_CALL_METHOD(NULL, query, "orderby", tmp);

	PHALCON_RETURN_CALL_METHOD(query, "execute");

	RETURN_MM();
}

/**
 * Named scope. Gets children for node (direct descendants only).
 *
 * @return \Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, children){


	PHALCON_RETURN_CALL_SELFW("descendants", PHALCON_GLOBAL(z_one));
}

/**
 * Named scope. Gets ancestors for node.
 *
 * @param int $depth the depth.
 *
 * @return \Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, ancestors){

	zval *depth, *owner, *left_attribute, *left = NULL, *right_attribute, *right = NULL, *has_many_roots;
	zval *query = NULL, *statement, *level_attribute, *level = NULL, *root_attribute, *root = NULL, *tmp = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &depth);

	if (!depth) {
		depth = PHALCON_GLOBAL(z_null);
	} else if (Z_TYPE_P(depth) != IS_NULL && Z_TYPE_P(depth) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(depth);
		convert_to_long(depth);
	}

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_SELF(&left, "getleftattribute");
	PHALCON_CALL_SELF(&right, "getrightattribute");

	PHALCON_CALL_METHOD(&query, owner, "query");

	PHALCON_INIT_VAR(statement);
	PHALCON_CONCAT_VSV(statement, left_attribute, "<", left);
	PHALCON_CALL_METHOD(NULL, query, "where", statement);

	PHALCON_INIT_NVAR(statement);
	PHALCON_CONCAT_VSV(statement, right_attribute, ">", right);
	PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);

	if (Z_TYPE_P(depth) != IS_NULL) {
		level_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_levelAttribute"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_SELF(&level, "getlevelattribute");

		PHALCON_INIT_NVAR(tmp);
		phalcon_sub_function(tmp, level, depth);

		PHALCON_INIT_NVAR(statement);
		PHALCON_CONCAT_VSV(statement, level_attribute, ">=", tmp);
		PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);
	}

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	if (zend_is_true(has_many_roots)) {
		root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_SELF(&root, "getrootattribute");

		PHALCON_INIT_NVAR(statement);
		PHALCON_CONCAT_VSV(statement, root_attribute, "=", root);
		PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);
	}

	PHALCON_CALL_METHOD(NULL, query, "orderby", left_attribute);

	PHALCON_RETURN_CALL_METHOD(query, "execute");

	RETURN_MM();
}

/**
 * Named scope. Gets root node(s).
 *
 * @return \Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, roots){

	zval *owner, *left_attribute, *statement;

	PHALCON_MM_GROW();

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(statement);
	PHALCON_CONCAT_VSV(statement, left_attribute, "=", PHALCON_GLOBAL(z_one));
	PHALCON_RETURN_CALL_METHOD(owner, "find", statement);

	RETURN_MM();
}

/**
 * Named scope. Gets parent of node.
 *
 * @return \Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, parent){

	zval *owner, *left_attribute, *left = NULL, *right_attribute, *right = NULL;
	zval *query = NULL, *statement, *has_many_roots = NULL, *root_attribute, *root = NULL;

	PHALCON_MM_GROW();

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_SELF(&left, "getleftattribute");
	PHALCON_CALL_SELF(&right, "getrightattribute");

	PHALCON_CALL_METHOD(&query, owner, "query");

	PHALCON_INIT_VAR(statement);
	PHALCON_CONCAT_VSV(statement, left_attribute, "<", left);
	PHALCON_CALL_METHOD(NULL, query, "where", statement);

	PHALCON_INIT_NVAR(statement);
	PHALCON_CONCAT_VSV(statement, right_attribute, ">", right);
	PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	if (zend_is_true(has_many_roots)) {
		root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_SELF(&root, "getrootattribute");

		PHALCON_INIT_NVAR(statement);
		PHALCON_CONCAT_VSV(statement, root_attribute, "=", root);
		PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);
	}

	PHALCON_CALL_METHOD(NULL, query, "orderby", right_attribute);
	PHALCON_CALL_METHOD(NULL, query, "limit", PHALCON_GLOBAL(z_one));

	PHALCON_CALL_METHOD(&return_value, query, "execute");
	PHALCON_RETURN_CALL_METHOD(return_value, "getfirst");

	RETURN_MM();
}

/**
 * Named scope. Gets previous sibling of node.
 *
 * @return \Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, prev){

	zval *owner, *left = NULL, *right_attribute;
	zval *query = NULL, *statement, *has_many_roots, *root_attribute, *root = NULL, *tmp = NULL;

	PHALCON_MM_GROW();

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_SELF(&left, "getleftattribute");

	PHALCON_CALL_METHOD(&query, owner, "query");

	PHALCON_INIT_NVAR(tmp);
	phalcon_sub_function(tmp, left, PHALCON_GLOBAL(z_one));

	PHALCON_INIT_VAR(statement);
	PHALCON_CONCAT_VSV(statement, right_attribute, "=", tmp);
	PHALCON_CALL_METHOD(NULL, query, "where", statement);

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	if (zend_is_true(has_many_roots)) {
		root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_SELF(&root, "getrootattribute");

		PHALCON_INIT_NVAR(statement);
		PHALCON_CONCAT_VSV(statement, root_attribute, "=", root);
		PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);
	}

	PHALCON_CALL_METHOD(&return_value, query, "execute");
	PHALCON_RETURN_CALL_METHOD(return_value, "getfirst");

	RETURN_MM();
}

/**
 * Named scope. Gets next sibling of node.
 *
 * @return \Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, next){

	zval *owner, *left_attribute, *right = NULL;
	zval *query = NULL, *statement, *has_many_roots, *root_attribute, *root = NULL, *tmp = NULL;

	PHALCON_MM_GROW();

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_SELF(&right, "getrightattribute");

	PHALCON_CALL_METHOD(&query, owner, "query");

	PHALCON_INIT_NVAR(tmp);
	phalcon_add_function(tmp, right, PHALCON_GLOBAL(z_one));

	PHALCON_INIT_VAR(statement);
	PHALCON_CONCAT_VSV(statement, left_attribute, "=", tmp);
	PHALCON_CALL_METHOD(NULL, query, "where", statement);

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	if (zend_is_true(has_many_roots)) {
		root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_SELF(&root, "getrootattribute");

		PHALCON_INIT_NVAR(statement);
		PHALCON_CONCAT_VSV(statement, root_attribute, "=", root);
		PHALCON_CALL_METHOD(NULL, query, "andwhere", statement);
	}

	PHALCON_CALL_METHOD(&return_value, query, "execute");
	PHALCON_RETURN_CALL_METHOD(return_value, "getfirst");

	RETURN_MM();
}

/**
 * Prepends node to target as first child.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target
 * @param array $attributes list of attributes.
 *
 * @return boolean whether the prepending succeeds.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, prependTo){

	zval *target, *attributes = NULL, *left = NULL, *tmp = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &target, &attributes);

	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_SELF(&left, "getleftattribute", target);

	PHALCON_INIT_NVAR(tmp);
	phalcon_add_function(tmp, left, PHALCON_GLOBAL(z_one));

	PHALCON_RETURN_CALL_SELF("addnode", target, tmp, PHALCON_GLOBAL(z_one), attributes);

	RETURN_MM();
}

/**
 * Prepends target to node as first child.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 * @param array $attributes list of attributes.
 *
 * @return boolean whether the prepending succeeds.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, prepend){

	zval *target, *attributes = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &target, &attributes);

	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_SELF("prependto", target, attributes);

	RETURN_MM();
}

/**
 * Appends node to target as last child.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 * @param array $attributes list of attributes.
 *
 * @return boolean whether the appending succeeds.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, appendTo){

	zval *target, *attributes = NULL, *right = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &target, &attributes);

	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_SELF(&right, "getrightattribute", target);

	PHALCON_RETURN_CALL_SELF("addnode", target, right, PHALCON_GLOBAL(z_one), attributes);

	RETURN_MM();
}

/**
 * Appends node to target as last child.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 * @param array $attributes list of attributes.
 *
 * @return boolean whether the appending succeeds.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, append){

	zval *target, *attributes = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &target, &attributes);

	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}

	PHALCON_RETURN_CALL_SELF("appendto", target, attributes);

	RETURN_MM();
}

/**
 * Inserts node as previous sibling of target.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 * @param array $attributes list of attributes.
 *
 * @return boolean whether the inserting succeeds.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, insertBefore){

	zval *target, *attributes = NULL, *left = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &target, &attributes);

	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_SELF(&left, "getleftattribute", target);

	PHALCON_RETURN_CALL_SELF("addnode", target, left, PHALCON_GLOBAL(z_zero), attributes);

	RETURN_MM();
}

/**
 * Inserts node as next sibling of target.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 * @param array $attributes list of attributes.
 *
 * @return boolean whether the inserting succeeds.
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, insertAfter){

	zval *target, *attributes = NULL, *right = NULL, *tmp = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &target, &attributes);

	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_SELF(&right, "getrightattribute", target);

	PHALCON_INIT_NVAR(tmp);
	phalcon_add_function(tmp, right, PHALCON_GLOBAL(z_one));

	PHALCON_RETURN_CALL_SELF("addnode", target, tmp, PHALCON_GLOBAL(z_zero), attributes);

	RETURN_MM();
}

/**
 * Move node as previous sibling of target.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveBefore){

	zval *target, *left = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &target);

	PHALCON_CALL_SELF(&left, "getleftattribute", target);

	PHALCON_RETURN_CALL_SELF("movenode", target, left, PHALCON_GLOBAL(z_zero));

	RETURN_MM();
}

/**
 * Move node as next sibling of target.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveAfter){

	zval *target, *left = NULL, *tmp = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &target);

	PHALCON_CALL_SELF(&left, "getleftattribute", target);

	PHALCON_INIT_NVAR(tmp);
	phalcon_add_function(tmp, left, PHALCON_GLOBAL(z_one));

	PHALCON_RETURN_CALL_SELF("movenode", target, tmp, PHALCON_GLOBAL(z_zero));

	RETURN_MM();
}

/**
 * Move node as first child of target.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsFirst){

	zval *target, *left = NULL, *tmp = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &target);

	PHALCON_CALL_SELF(&left, "getleftattribute", target);

	PHALCON_INIT_NVAR(tmp);
	phalcon_add_function(tmp, left, PHALCON_GLOBAL(z_one));

	PHALCON_RETURN_CALL_SELF("movenode", target, tmp, PHALCON_GLOBAL(z_one));

	RETURN_MM();
}

/**
 * Move node as first child of target.
 *
 * @param Phalcon\Mvc\ModelInterface $target the target.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsLast){

	zval *target, *right = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &target);

	PHALCON_CALL_SELF(&right, "getrightattribute", target);

	PHALCON_RETURN_CALL_SELF("movenode", target, right, PHALCON_GLOBAL(z_one));

	RETURN_MM();
}

/**
 * Move node as new root.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveAsRoot){

	zval *has_many_roots, *owner, *is_new = NULL, *is_deleted = NULL, *is_root = NULL;
	zval *connection = NULL, *left = NULL, *right = NULL, *level = NULL, *root = NULL, *primary_key = NULL, *delta, *level_delta;
	zval *left_attribute, *right_attribute, *level_attribute, *root_attribute, *condition, *childs = NULL, *child = NULL;
	zval *child_left = NULL, *child_right = NULL, *child_level = NULL, *values = NULL, *ret = NULL;
	zval *tmp1, *tmp2;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	if (!zend_is_true(has_many_roots)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Many roots mode is off");
		return;
	}

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&is_new, owner, "isnewrecord");

	if (zend_is_true(is_new)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The node should not be new record");
		return;
	}

	PHALCON_CALL_METHOD(&is_deleted, owner, "isdeletedrecord");

	if (zend_is_true(is_deleted)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The node should not be deleted");
		return;
	}

	PHALCON_CALL_METHOD(&is_root, owner, "isroot");

	if (zend_is_true(is_root)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The node already is root node");
		return;
	}

	PHALCON_CALL_METHOD(&connection, owner, "getwriteconnection");

	PHALCON_CALL_METHOD(NULL, connection, "begin");

	PHALCON_CALL_SELF(&left, "getleftattribute");
	PHALCON_CALL_SELF(&right, "getrightattribute");
	PHALCON_CALL_SELF(&level, "getlevelattribute");
	PHALCON_CALL_SELF(&root, "getrootattribute");
	PHALCON_CALL_SELF(&primary_key, "getprimarykey");

	PHALCON_INIT_VAR(delta);
	phalcon_sub_function(delta, PHALCON_GLOBAL(z_one), left);

	PHALCON_INIT_VAR(level_delta);
	phalcon_sub_function(level_delta, PHALCON_GLOBAL(z_one), level);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);
	level_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_levelAttribute"), PH_NOISY TSRMLS_CC);
	root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(condition);
	PHALCON_CONCAT_VSVS(condition, left_attribute, ">=", left, " AND ");
	PHALCON_SCONCAT_VSVS(condition, right_attribute, "<=", right, " AND ");
	PHALCON_SCONCAT_VSV(condition, root_attribute, "=", root);

	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

	PHALCON_CALL_METHOD(&childs, owner, "find", condition);

	phalcon_is_iterable(childs, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

		PHALCON_GET_HVALUE(child);

		PHALCON_CALL_SELF(&child_left, "getleftattribute", child);
		PHALCON_CALL_SELF(&child_right, "getrightattribute", right);
		PHALCON_CALL_SELF(&child_level, "getlevelattribute", right);

		PHALCON_INIT_NVAR(values);
		array_init(values);

		phalcon_array_update_zval_long(&values, left_attribute, (phalcon_get_intval(child_left) + phalcon_get_intval(delta)), PH_COPY);
		phalcon_array_update_zval_long(&values, right_attribute, (phalcon_get_intval(child_right) + phalcon_get_intval(delta)), PH_COPY);
		phalcon_array_update_zval_long(&values, level_attribute, (phalcon_get_intval(child_level) + phalcon_get_intval(level_delta)), PH_COPY);
		phalcon_array_update_zval(&values, root_attribute, primary_key, PH_COPY);

		PHALCON_CALL_METHOD(&ret, child, "update", values);
		if (!zend_is_true(ret)) {
			PHALCON_CALL_METHOD(NULL, connection, "rollback");
			phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
			RETURN_MM_FALSE;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
	}

	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);

	PHALCON_INIT_VAR(tmp1);
	ZVAL_LONG(tmp1, phalcon_get_intval(right) + 1);

	PHALCON_INIT_VAR(tmp2);
	ZVAL_LONG(tmp2, phalcon_get_intval(left) - phalcon_get_intval(right) - 1);

	PHALCON_CALL_SELF(NULL, "shiftleftright", tmp1, tmp2);

	PHALCON_CALL_METHOD(NULL, connection, "commit");

	RETURN_MM();
}

/**
 * Create root node if multiple-root tree mode. Update node if it's not new.
 *
 * @param array $attributes list of attributes.
 * @param array $whiteList  whether to perform validation.
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, saveNode){

	zval *attributes = NULL, *white_list = NULL, *primary_key = NULL, *owner;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &attributes, &white_list);

	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}

	if (!white_list) {
		white_list = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_SELF(&primary_key, "getprimarykey");

	if (!zend_is_true(primary_key)) {
		PHALCON_RETURN_CALL_SELF("makeroot", attributes, white_list);
		RETURN_MM();
	}

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

	PHALCON_RETURN_CALL_METHOD(owner, "update", attributes, white_list);

	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);

	RETURN_MM();
}

/**
 * Deletes node and it's descendants.
 *
 * @return boolean
 * @throws Phalcon\Mvc\Model\Exception
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, deleteNode){

	zval *owner, *is_new = NULL, *is_deleted = NULL, *connection = NULL, *is_leaf = NULL, *ret = NULL;
	zval *left_attribute, *right_attribute, *root_attribute, *has_many_roots, *left = NULL, *right = NULL, *root = NULL, *condition;
	zval *childs = NULL, *valid = NULL, *child = NULL, *tmp1 = NULL, *tmp2 = NULL;

	PHALCON_MM_GROW();

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&is_new, owner, "isnewrecord");

	if (zend_is_true(is_new)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The node cannot be deleted because it is new");
		return;
	}

	PHALCON_CALL_METHOD(&is_deleted, owner, "isdeletedrecord");

	if (zend_is_true(is_deleted)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The node cannot be deleted because it is already deleted");
		return;
	}

	PHALCON_CALL_METHOD(&connection, owner, "getwriteconnection");

	PHALCON_CALL_METHOD(NULL, connection, "begin");

	PHALCON_CALL_SELF(&is_leaf, "isleaf");

	if (zend_is_true(is_leaf)) {
		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);
		PHALCON_CALL_METHOD(&ret, owner, "delete");
		if (!zend_is_true(is_leaf)) {
			PHALCON_CALL_METHOD(NULL, connection, "rollback");
			phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
			RETURN_MM_FALSE;
		}
		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
	} else {
		left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
		right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);

		PHALCON_CALL_SELF(&left, "getleftattribute");
		PHALCON_CALL_SELF(&right, "getrightattribute");

		has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(condition);
		PHALCON_CONCAT_VSVS(condition, left_attribute, ">=", left, " AND ");
		PHALCON_SCONCAT_VSV(condition, right_attribute, "<=", right);

		if (zend_is_true(has_many_roots)) {
			root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);
			PHALCON_CALL_SELF(&root, "getrootattribute");
			PHALCON_SCONCAT_VSV(condition, root_attribute, "=", root);
		}

		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

		PHALCON_CALL_METHOD(&childs, owner, "find", condition);
		
		PHALCON_CALL_METHOD(NULL, childs, "rewind");

		while (1) {
			PHALCON_CALL_METHOD(&valid, childs, "valid");
			if (!PHALCON_IS_NOT_FALSE(valid)) {
				break;
			}

			PHALCON_CALL_METHOD(&child, childs, "current");

			PHALCON_CALL_METHOD(&ret, child, "delete");
			if (!zend_is_true(ret)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback");
				phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
				RETURN_MM_FALSE;
			}

			PHALCON_CALL_METHOD(NULL, childs, "next");
		}

		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
	}

	if (!left || !right) {
		PHALCON_CALL_SELF(&left, "getleftattribute");
		PHALCON_CALL_SELF(&right, "getrightattribute");
	}

	PHALCON_INIT_VAR(tmp1);
	ZVAL_LONG(tmp1, phalcon_get_intval(right) + 1);

	PHALCON_INIT_VAR(tmp2);
	ZVAL_LONG(tmp2, phalcon_get_intval(left) - phalcon_get_intval(right) - 1);

	PHALCON_CALL_SELF(NULL, "shiftleftright", tmp1, tmp2);

	PHALCON_CALL_METHOD(NULL, connection, "commit");

	RETURN_MM_TRUE;
}

/**
 * @param Phalcon\Mvc\ModelInterface $target
 * @param int $key
 * @param int $levelUp
 *
 * @return boolean
 * @throws Phalcon\Mvc\Model\Exception
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, moveNode){

	zval *target, *key, *level_up, *owner, *is_new = NULL, *is_deleted = NULL, *is_descendantof = NULL, *is_root = NULL;
	zval *left_attribute, *right_attribute, *level_attribute, *root_attribute;
	zval *connection = NULL, *left = NULL,  *right = NULL, *level = NULL, *level2 = NULL;
	zval *root = NULL, *root2 = NULL, *level_delta, *has_many_roots, *condition = NULL, *childs = NULL, *valid = NULL, *child = NULL, *ret = NULL;
	zval *values = NULL, *child_left = NULL, *child_right = NULL, *child_level = NULL, *delta = NULL, *tmp = NULL, *tmp1 = NULL, *tmp2 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &target, &key, &level_up);

	PHALCON_VERIFY_INTERFACE(target, phalcon_mvc_modelinterface_ce);

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	if (PHALCON_IS_EQUAL(owner, target)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target node should not be self");
		return;
	}

	PHALCON_CALL_METHOD(NULL, owner, "refresh");
	PHALCON_CALL_METHOD(NULL, target, "refresh");

	PHALCON_CALL_METHOD(&is_new, owner, "isnewrecord");

	if (zend_is_true(is_new)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The node should not be new record");
		return;
	}

	PHALCON_CALL_METHOD(&is_deleted, owner, "isdeletedrecord");

	if (zend_is_true(is_deleted)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The node should not be deleted");
		return;
	}

	PHALCON_CALL_METHOD(&is_new, target, "isnewrecord");

	if (zend_is_true(is_new)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target should not be new record");
		return;
	}

	PHALCON_CALL_METHOD(&is_deleted, target, "isdeletedrecord");

	if (zend_is_true(is_deleted)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target should not be deleted");
		return;
	}

	PHALCON_CALL_SELF(&is_descendantof, "isdescendantof", target);

	if (zend_is_true(is_deleted)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target node should not be descendant");
		return;
	}

	PHALCON_CALL_SELF(&is_root, "isroot", target);

	if (!zend_is_true(level_up) && zend_is_true(is_root)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target node should not be root");
		return;
	}

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);
	level_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_levelAttribute"), PH_NOISY TSRMLS_CC);
	root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_METHOD(&connection, owner, "getwriteconnection");

	PHALCON_CALL_METHOD(NULL, connection, "begin");

	PHALCON_CALL_SELF(&left, "getleftattribute");
	PHALCON_CALL_SELF(&right, "getrightattribute");
	PHALCON_CALL_SELF(&level, "getlevelattribute");
	PHALCON_CALL_SELF(&root, "getrootattribute");

	PHALCON_CALL_SELF(&level2, "getlevelattribute", target);
	PHALCON_CALL_SELF(&root2, "getrootattribute", target);

	PHALCON_INIT_VAR(level_delta);
	ZVAL_LONG(level_delta, phalcon_get_intval(level2) - phalcon_get_intval(level) + phalcon_get_intval(level_up));

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	if (zend_is_true(has_many_roots) && !PHALCON_IS_EQUAL(root, root2)) {
		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

		PHALCON_INIT_NVAR(condition);
		PHALCON_CONCAT_VSVS(condition, left_attribute, ">=", key, " AND ");
		PHALCON_SCONCAT_VSV(condition, root_attribute, "=", root2);

		PHALCON_CALL_METHOD(&childs, owner, "find", condition);

		PHALCON_CALL_METHOD(NULL, childs, "rewind");

		while (1) {
			PHALCON_CALL_METHOD(&valid, childs, "valid");
			if (!PHALCON_IS_NOT_FALSE(valid)) {
				break;
			}

			PHALCON_CALL_METHOD(&child, childs, "current");

			PHALCON_CALL_SELF(&child_left, "getleftattribute", child);

			PHALCON_INIT_NVAR(tmp);
			ZVAL_LONG(tmp, phalcon_get_intval(child_left) + phalcon_get_intval(right) - phalcon_get_intval(left) + 1);

			PHALCON_INIT_NVAR(values);
			array_init(values);

			phalcon_array_update_zval(&values, left_attribute, tmp, PH_COPY);

			PHALCON_CALL_METHOD(&ret, child, "update", values);
			if (!zend_is_true(ret)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback");
				phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
				RETURN_MM_FALSE;
			}

			PHALCON_CALL_METHOD(NULL, childs, "next");
		}

		PHALCON_INIT_NVAR(condition);
		PHALCON_CONCAT_VSVS(condition, right_attribute, ">=", key, " AND ");
		PHALCON_SCONCAT_VSV(condition, root_attribute, "=", root2);

		PHALCON_CALL_METHOD(&childs, owner, "find", condition);

		PHALCON_CALL_METHOD(NULL, childs, "rewind");

		while (1) {
			PHALCON_CALL_METHOD(&valid, childs, "valid");
			if (!PHALCON_IS_NOT_FALSE(valid)) {
				break;
			}

			PHALCON_CALL_METHOD(&child, childs, "current");

			PHALCON_CALL_SELF(&child_right, "getrightattribute", child);

			PHALCON_INIT_NVAR(tmp);
			ZVAL_LONG(tmp, phalcon_get_intval(child_right) + phalcon_get_intval(right) - phalcon_get_intval(left) + 1);

			PHALCON_INIT_NVAR(values);
			array_init(values);

			phalcon_array_update_zval(&values, right_attribute, tmp, PH_COPY);

			PHALCON_CALL_METHOD(&ret, child, "update", values);
			if (!zend_is_true(ret)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback");
				phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
				RETURN_MM_FALSE;
			}

			PHALCON_CALL_METHOD(NULL, childs, "next");
		}

		PHALCON_INIT_NVAR(delta);
		ZVAL_LONG(delta, phalcon_get_intval(key) - phalcon_get_intval(left));

		PHALCON_INIT_NVAR(condition);
		PHALCON_CONCAT_VSVS(condition, left_attribute, ">=", left, " AND ");
		PHALCON_SCONCAT_VSVS(condition, right_attribute, "<=", right, " AND ");
		PHALCON_SCONCAT_VSV(condition, root_attribute, "=", root);

		PHALCON_CALL_METHOD(&childs, owner, "find", condition);

		PHALCON_CALL_METHOD(NULL, childs, "rewind");

		while (1) {
			PHALCON_CALL_METHOD(&valid, childs, "valid");
			if (!PHALCON_IS_NOT_FALSE(valid)) {
				break;
			}

			PHALCON_CALL_METHOD(&child, childs, "current");

			PHALCON_CALL_SELF(&child_left, "getleftattribute", child);
			PHALCON_CALL_SELF(&child_right, "getrightattribute", child);
			PHALCON_CALL_SELF(&child_level, "getlevelattribute", child);

			PHALCON_INIT_NVAR(values);
			array_init(values);

			phalcon_array_update_zval_long(&values, left_attribute, (phalcon_get_intval(child_left) + phalcon_get_intval(delta)), PH_COPY);
			phalcon_array_update_zval_long(&values, right_attribute, (phalcon_get_intval(child_right) + phalcon_get_intval(delta)), PH_COPY);
			phalcon_array_update_zval_long(&values, level_attribute, (phalcon_get_intval(child_level) + phalcon_get_intval(level_delta)), PH_COPY);
			phalcon_array_update_zval(&values, root_attribute, root2, PH_COPY);

			PHALCON_CALL_METHOD(&ret, child, "update", values);
			if (!zend_is_true(ret)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback");
				phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
				RETURN_MM_FALSE;
			}

			PHALCON_CALL_METHOD(NULL, childs, "next");
		}

		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);

		PHALCON_INIT_NVAR(tmp1);
		ZVAL_LONG(tmp1, phalcon_get_intval(right) + 1);

		PHALCON_INIT_NVAR(tmp2);
		ZVAL_LONG(tmp2, phalcon_get_intval(left) - phalcon_get_intval(right) - 1);

		PHALCON_CALL_SELF(NULL, "shiftleftright", tmp1, tmp2);

		PHALCON_CALL_METHOD(NULL, connection, "commit");
	} else {
		PHALCON_INIT_NVAR(delta);
		ZVAL_LONG(delta, phalcon_get_intval(right) - phalcon_get_intval(left) + 1);

		PHALCON_CALL_SELF(NULL, "shiftleftright", key, delta);

		PHALCON_INIT_NVAR(condition);
		PHALCON_CONCAT_VSVS(condition, left_attribute, ">=", left, " AND ");
		PHALCON_SCONCAT_VSV(condition, right_attribute, "<=", right);

		if (zend_is_true(has_many_roots)) {
			PHALCON_SCONCAT_SVSV(condition, " AND ", root_attribute, "=", root);
		}
		
		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

		PHALCON_CALL_METHOD(&childs, owner, "find", condition);

		PHALCON_CALL_METHOD(NULL, childs, "rewind");

		while (1) {
			PHALCON_CALL_METHOD(&valid, childs, "valid");
			if (!PHALCON_IS_NOT_FALSE(valid)) {
				break;
			}

			PHALCON_CALL_METHOD(&child, childs, "current");

			PHALCON_CALL_SELF(&child_level, "getlevelattribute", child);

			PHALCON_INIT_NVAR(values);
			array_init(values);

			phalcon_array_update_zval_long(&values, level_attribute, (phalcon_get_intval(level) + phalcon_get_intval(level_delta)), PH_COPY);

			PHALCON_CALL_METHOD(&ret, child, "update", values);
			if (!zend_is_true(ret)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback");
				phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
				RETURN_MM_FALSE;
			}

			PHALCON_CALL_METHOD(NULL, childs, "next");
		}
		
		PHALCON_INIT_NVAR(condition);
		PHALCON_CONCAT_VSVS(condition, left_attribute, ">=", left, " AND ");
		PHALCON_SCONCAT_VSV(condition, left_attribute, "<=", right);

		if (zend_is_true(has_many_roots)) {
			PHALCON_SCONCAT_SVSV(condition, " AND ", root_attribute, "=", root);
		}

		PHALCON_CALL_METHOD(&childs, owner, "find", condition);

		PHALCON_CALL_METHOD(NULL, childs, "rewind");

		while (1) {
			PHALCON_CALL_METHOD(&valid, childs, "valid");
			if (!PHALCON_IS_NOT_FALSE(valid)) {
				break;
			}

			PHALCON_CALL_METHOD(&child, childs, "current");

			PHALCON_CALL_SELF(&child_left, "getleftattribute", child);

			PHALCON_INIT_NVAR(tmp);
			ZVAL_LONG(tmp, phalcon_get_intval(child_left) + phalcon_get_intval(key) - phalcon_get_intval(left));

			PHALCON_INIT_NVAR(values);
			array_init(values);

			phalcon_array_update_zval(&values, left_attribute, tmp, PH_COPY);

			PHALCON_CALL_METHOD(&ret, child, "update", values);
			if (!zend_is_true(ret)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback");
				phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
				RETURN_MM_FALSE;
			}

			PHALCON_CALL_METHOD(NULL, childs, "next");
		}
		
		PHALCON_INIT_NVAR(condition);
		PHALCON_CONCAT_VSVS(condition, right_attribute, ">=", left, " AND ");
		PHALCON_SCONCAT_VSV(condition, right_attribute, "<=", right);

		if (zend_is_true(has_many_roots)) {
			PHALCON_SCONCAT_SVSV(condition, " AND ", root_attribute, "=", root);
		}

		PHALCON_CALL_METHOD(&childs, owner, "find", condition);

		PHALCON_CALL_METHOD(NULL, childs, "rewind");

		while (1) {
			PHALCON_CALL_METHOD(&valid, childs, "valid");
			if (!PHALCON_IS_NOT_FALSE(valid)) {
				break;
			}

			PHALCON_CALL_METHOD(&child, childs, "current");

			PHALCON_CALL_SELF(&child_right, "getrightattribute", child);

			PHALCON_INIT_NVAR(tmp);
			ZVAL_LONG(tmp, phalcon_get_intval(child_right) + phalcon_get_intval(key) - phalcon_get_intval(left));

			PHALCON_INIT_NVAR(values);
			array_init(values);

			phalcon_array_update_zval(&values, right_attribute, tmp, PH_COPY);

			PHALCON_CALL_METHOD(&ret, child, "update", values);
			if (!zend_is_true(ret)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback");
				phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
				RETURN_MM_FALSE;
			}

			PHALCON_CALL_METHOD(NULL, childs, "next");
		}

		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);

		PHALCON_INIT_NVAR(tmp1);
		ZVAL_LONG(tmp1, phalcon_get_intval(right) + 1);

		PHALCON_INIT_NVAR(tmp2);
		ZVAL_LONG(tmp2, 0 - phalcon_get_intval(delta));

		PHALCON_CALL_SELF(NULL, "shiftleftright", tmp1, tmp2);

		PHALCON_CALL_METHOD(NULL, connection, "commit");
	}

	PHALCON_CALL_METHOD(NULL, owner, "refresh");
	PHALCON_CALL_METHOD(NULL, target, "refresh");

	RETURN_MM_TRUE;
}

/**
 * @param int $key
 * @param int $delta
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, shiftLeftRight){

	zval *key, *delta, *left_attribute, *right_attribute, *root_attribute, *has_many_roots;
	zval *owner, *childs = NULL, *valid = NULL, *child = NULL, *child_left = NULL, *child_right = NULL;
	zval *root = NULL, *connection = NULL, *condition = NULL;
	zval *values = NULL, *tmp = NULL, *ret = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &delta);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);
	root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);

	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_SELF(&root, "getrootattribute");

	PHALCON_CALL_METHOD(&connection, owner, "getwriteconnection");

	PHALCON_CALL_METHOD(NULL, connection, "begin");
		
	PHALCON_INIT_NVAR(condition);
	PHALCON_CONCAT_VSV(condition, left_attribute, ">=", key);

	if (zend_is_true(has_many_roots)) {
		PHALCON_SCONCAT_SVSV(condition, " AND ", root_attribute, "=", root);
	}

	PHALCON_CALL_METHOD(&childs, owner, "find", condition);

	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, childs, "rewind");

	while (1) {
		PHALCON_CALL_METHOD(&valid, childs, "valid");
		if (!PHALCON_IS_NOT_FALSE(valid)) {
			break;
		}

		PHALCON_CALL_METHOD(&child, childs, "current");

		PHALCON_CALL_SELF(&child_left, "getleftattribute", child);

		PHALCON_INIT_NVAR(tmp);
		ZVAL_LONG(tmp, phalcon_get_intval(child_left) + phalcon_get_intval(delta));

		PHALCON_INIT_NVAR(values);
		array_init(values);

		phalcon_array_update_zval(&values, left_attribute, tmp, PH_COPY);

		PHALCON_CALL_METHOD(&ret, child, "update", values);
		if (!zend_is_true(ret)) {
			PHALCON_CALL_METHOD(NULL, connection, "rollback");
			phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
			RETURN_MM_FALSE;
		}

		PHALCON_CALL_METHOD(NULL, childs, "next");
	}
	
	PHALCON_INIT_NVAR(condition);
	PHALCON_CONCAT_VSV(condition, right_attribute, ">=", key);

	if (zend_is_true(has_many_roots)) {
		PHALCON_SCONCAT_SVSV(condition, " AND ", root_attribute, "=", root);
	}

	PHALCON_CALL_METHOD(&childs, owner, "find", condition);

	PHALCON_CALL_METHOD(NULL, childs, "rewind");

	while (1) {
		PHALCON_CALL_METHOD(&valid, childs, "valid");
		if (!PHALCON_IS_NOT_FALSE(valid)) {
			break;
		}

		PHALCON_CALL_METHOD(&child, childs, "current");

		PHALCON_CALL_SELF(&child_right, "getrightattribute", child);

		PHALCON_INIT_NVAR(tmp);
		ZVAL_LONG(tmp, phalcon_get_intval(child_right) + phalcon_get_intval(delta));

		PHALCON_INIT_NVAR(values);
		array_init(values);

		phalcon_array_update_zval(&values, right_attribute, tmp, PH_COPY);

		PHALCON_CALL_METHOD(&ret, child, "update", values);
		if (!zend_is_true(ret)) {
			PHALCON_CALL_METHOD(NULL, connection, "rollback");
			phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
			RETURN_MM_FALSE;
		}

		PHALCON_CALL_METHOD(NULL, childs, "next");
	}

	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, connection, "commit");

	RETURN_MM_TRUE;
}

/**
 * @param Phalcon\Mvc\ModelInterface $target
 * @param int $key
 * @param int $levelUp
 * @param array $attributes
 *
 * @return boolean
 * @throws Phalcon\Mvc\Model\Exception
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, addNode){

	zval *target, *key, *level_up, *attributes, *owner, *is_new = NULL, *is_deleted = NULL, *is_root = NULL;
	zval *left_attribute, *right_attribute, *level_attribute, *root_attribute;
	zval *level2 = NULL, *root2 = NULL, *tmp = NULL, *ret = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &target, &key, &level_up, &attributes);

	PHALCON_VERIFY_INTERFACE(target, phalcon_mvc_modelinterface_ce);

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	if (PHALCON_IS_EQUAL(owner, target)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target node should not be self");
		return;
	}

	PHALCON_CALL_METHOD(&is_new, owner, "isnewrecord");

	if (!zend_is_true(is_new)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The node cannot be inserted because it is not new");
		return;
	}

	PHALCON_CALL_METHOD(&is_new, target, "isnewrecord");

	if (zend_is_true(is_new)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target should not be new record");
		return;
	}

	PHALCON_CALL_METHOD(&is_deleted, target, "isdeletedrecord");

	if (zend_is_true(is_deleted)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target should not be deleted");
		return;
	}

	PHALCON_CALL_SELF(&is_root, "isroot", target);

	if (!zend_is_true(level_up) && zend_is_true(is_root)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The target node should not be root");
		return;
	}

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);
	root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);
	level_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_levelAttribute"), PH_NOISY TSRMLS_CC);

	PHALCON_CALL_SELF(&root2, "getrootattribute", target);
	phalcon_update_property_zval_zval(owner, root_attribute, root2 TSRMLS_CC);

	PHALCON_CALL_SELF(&ret, "shiftleftright", key, PHALCON_GLOBAL(z_two));
	if (!zend_is_true(ret)) {
		RETURN_MM_FALSE;
	}

	phalcon_update_property_zval_zval(owner, left_attribute, key TSRMLS_CC);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, phalcon_get_intval(key) + 1);

	phalcon_update_property_zval_zval(owner, right_attribute, tmp TSRMLS_CC);

	PHALCON_CALL_SELF(&level2, "getlevelattribute", target);

	PHALCON_INIT_NVAR(tmp);
	ZVAL_LONG(tmp, phalcon_get_intval(level2) + phalcon_get_intval(level_up));

	phalcon_update_property_zval_zval(owner, level_attribute, tmp TSRMLS_CC);
	
	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

	PHALCON_CALL_METHOD(&ret, owner, "create", attributes);
	
	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);

	RETURN_CTOR(ret);
}

/**
 * @param array $attributes
 * @param array $whiteList
 *
 * @return boolean
 * @throws Phalcon\Mvc\Model\Exception
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_NestedSet, makeRoot){

	zval *attributes, *white_list, *owner, *connection = NULL;
	zval *left_attribute, *right_attribute, *level_attribute, *root_attribute, *has_many_roots, *primary_key = NULL;
	zval *ret = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &attributes, &white_list);

	owner = phalcon_fetch_nproperty_this(this_ptr, SL("_owner"), PH_NOISY TSRMLS_CC);

	left_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_leftAttribute"), PH_NOISY TSRMLS_CC);
	right_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rightAttribute"), PH_NOISY TSRMLS_CC);
	level_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_levelAttribute"), PH_NOISY TSRMLS_CC);
	root_attribute = phalcon_fetch_nproperty_this(this_ptr, SL("_rootAttribute"), PH_NOISY TSRMLS_CC);
	has_many_roots = phalcon_fetch_nproperty_this(this_ptr, SL("_hasManyRoots"), PH_NOISY TSRMLS_CC);

	phalcon_update_property_zval_long(owner, left_attribute, 1 TSRMLS_CC);
	phalcon_update_property_zval_long(owner, right_attribute, 2 TSRMLS_CC);
	phalcon_update_property_zval_long(owner, level_attribute, 1 TSRMLS_CC);

	PHALCON_CALL_METHOD(&connection, owner, "getwriteconnection");

	if (!zend_is_true(has_many_roots)) {
		PHALCON_CALL_SELF(&ret, "roots");
		if (phalcon_fast_count_ev(ret TSRMLS_CC)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot create more than one root in single root mode");
			return;
		}
	}

	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 1 TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, connection, "begin");

	PHALCON_CALL_METHOD(&ret, owner, "create", attributes, white_list);
	if (!zend_is_true(ret)) {
		PHALCON_CALL_METHOD(NULL, connection, "rollback");
		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
		RETURN_MM_FALSE;
	}

	PHALCON_CALL_SELF(&primary_key, "getprimarykey", owner);

	phalcon_update_property_zval_zval(owner, root_attribute, primary_key TSRMLS_CC);

	PHALCON_CALL_METHOD(&ret, owner, "save");
	if (!zend_is_true(ret)) {
		PHALCON_CALL_METHOD(NULL, connection, "rollback");
		phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);
		RETURN_MM_FALSE;
	}

	phalcon_update_property_bool(this_ptr, SL("_ignoreEvent"), 0 TSRMLS_CC);

	PHALCON_CALL_METHOD(NULL, connection, "commit");

	RETURN_MM_TRUE;
}
