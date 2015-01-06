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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_INTERNAL_ARGINFO_H
#define PHALCON_INTERNAL_ARGINFO_H

#include <Zend/zend.h>
#include <Zend/zend_API.h>


ZEND_BEGIN_ARG_INFO_EX(arginfo_empty, 0, 0, 0)
ZEND_END_ARG_INFO()


/** @brief & __get($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo___getref, 0, 1, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

/** @brief __get($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

/** @brief __set($property, $value) */
ZEND_BEGIN_ARG_INFO_EX(arginfo___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

/** @brief __isset($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

/** @brief __unset($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

/** @brief __call($method, array $arguments) */
ZEND_BEGIN_ARG_INFO_EX(arginfo___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

/** @brief __callStatic($method, array $arguments) */
ZEND_BEGIN_ARG_INFO_EX(arginfo___callstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

/** @brief __toString() */
ZEND_BEGIN_ARG_INFO_EX(arginfo___tostring, 0, 0, 0)
ZEND_END_ARG_INFO()

/** @brief __destruct() */
ZEND_BEGIN_ARG_INFO_EX(arginfo___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

/** @brief __set_state(array $properties) */
ZEND_BEGIN_ARG_INFO_EX(arginfo___set_state, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

/** @brief IteratorAggregate::getIterator() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_iteratoraggregate_getiterator, 0, 0, 0)
ZEND_END_ARG_INFO()


/** @brief Countable::count() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_countable_count, 0, 0, 0)
ZEND_END_ARG_INFO()


/** @brief ArrayAccess::offsetGet($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo_arrayaccess_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 50304

/** @brief & ArrayAccess::offsetGet($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo_arrayaccess_offsetgetref, 0, 1, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

#else

/** @brief ArrayAccess::offsetGet($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo_arrayaccess_offsetgetref, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

#endif

/** @brief ArrayAccess::offsetSet($property, $value) */
ZEND_BEGIN_ARG_INFO_EX(arginfo_arrayaccess_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

/** @brief ArrayAccess::offsetExists($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo_arrayaccess_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

/** @brief ArrayAccess::offsetUnset($property) */
ZEND_BEGIN_ARG_INFO_EX(arginfo_arrayaccess_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()


/** @brief Iterator::current() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_iterator_current, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 50304
/** @brief & Iterator::current() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_iterator_currentref, 0, 1, 0)
ZEND_END_ARG_INFO()
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_iterator_currentref, 0, 0, 0)
ZEND_END_ARG_INFO()
#endif

/** @brief Iterator::key() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_iterator_key, 0, 0, 0)
ZEND_END_ARG_INFO()

/** @brief Iterator::next() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_iterator_next, 0, 0, 0)
ZEND_END_ARG_INFO()

/** @brief Iterator::rewind() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_iterator_rewind, 0, 0, 0)
ZEND_END_ARG_INFO()

/** @brief Iterator::valid() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_iterator_valid, 0, 0, 0)
ZEND_END_ARG_INFO()


/** @brief SeekableIterator::seek($position) */
ZEND_BEGIN_ARG_INFO_EX(arginfo_seekableiterator_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()


/** @brief JsonSerializable::jsonSerialize() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsonserializable_jsonserialize, 0, 0, 0)
ZEND_END_ARG_INFO()


/** @brief Serializable::serialize() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_serializable_serialize, 0, 0, 0)
ZEND_END_ARG_INFO()

/** @brief Serializable::unserialize() */
ZEND_BEGIN_ARG_INFO_EX(arginfo_serializable_unserialize, 0, 0, 0)
	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

#endif /* PHALCON_INTERNAL_ARGINFO_H */
