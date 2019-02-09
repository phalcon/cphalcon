
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Describes a data stream.
 *
 * Typically, an instance will wrap a PHP stream; this interface provides
 * a wrapper around the most common operations, including serialization of
 * the entire stream to a string.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Stream) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, Stream, phalcon, http_message_stream, phalcon_http_message_stream_method_entry, 0);

	/**
	 * @var resource
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("handle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var resource | string
	 */
	zend_declare_property_null(phalcon_http_message_stream_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_message_stream_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\message\\streaminterface")));
	return SUCCESS;

}

/**
 * Reads all data from the stream into a string, from the beginning to end.
 *
 * This method MUST attempt to seek to the beginning of the stream before
 * reading data and read the stream until the end is reached.
 *
 * Warning: This could attempt to load a large amount of data into memory.
 *
 * This method MUST NOT raise an exception in order to conform with PHP's
 * string casting operations.
 *
 * @see http://php.net/manual/en/language.oop5.magic.php#object.tostring
 * @return string
 */
PHP_METHOD(Phalcon_Http_Message_Stream, __toString) {

	zval *this_ptr = getThis();



}

/**
 * Closes the stream and any underlying resources.
 *
 * @return void
 */
PHP_METHOD(Phalcon_Http_Message_Stream, close) {

	zval *this_ptr = getThis();



}

/**
 * Separates any underlying resources from the stream.
 *
 * After the stream has been detached, the stream is in an unusable state.
 *
 * @return resource|null Underlying PHP stream, if any
 */
PHP_METHOD(Phalcon_Http_Message_Stream, detach) {

	zval *this_ptr = getThis();



}

/**
 * Returns true if the stream is at the end of the stream.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Message_Stream, eof) {

	zval *this_ptr = getThis();



}

/**
 * Returns the remaining contents in a string
 *
 * @return string
 * @throws \RuntimeException if unable to read.
 * @throws \RuntimeException if error occurs while reading.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getContents) {

	zval *this_ptr = getThis();



}

/**
 * Get stream metadata as an associative array or retrieve a specific key.
 *
 * The keys returned are identical to the keys returned from PHP's
 * stream_get_meta_data() function.
 *
 * @see http://php.net/manual/en/function.stream-get-meta-data.php
 * @param string $key Specific metadata to retrieve.
 * @return array|mixed|null Returns an associative array if no key is
 *     provided. Returns a specific key value if a key is provided and the
 *     value is found, or null if the key is not found.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getMetadata) {

	zval *key = NULL, key_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &key);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}



}

/**
 * Get the size of the stream if known.
 *
 * @return int|null Returns the size in bytes if known, or null if unknown.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, getSize) {

	zval *this_ptr = getThis();



}

/**
 * Returns whether or not the stream is readable.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isReadable) {

	zval *this_ptr = getThis();



}

/**
 * Returns whether or not the stream is seekable.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isSeekable) {

	zval *this_ptr = getThis();



}

/**
 * Returns whether or not the stream is writable.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Message_Stream, isWritable) {

	zval *this_ptr = getThis();



}

/**
 * Read data from the stream.
 *
 * @param int $length Read up to $length bytes from the object and return
 *     them. Fewer than $length bytes may be returned if underlying stream
 *     call returns fewer bytes.
 * @return string Returns the data read from the stream, or an empty string
 *     if no bytes are available.
 * @throws \RuntimeException if an error occurs.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, read) {

	zval *length, length_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);

	zephir_fetch_params(0, 1, 0, &length);




}

/**
 * Seek to the beginning of the stream.
 *
 * If the stream is not seekable, this method will raise an exception;
 * otherwise, it will perform a seek(0).
 *
 * @see seek()
 * @see http://www.php.net/manual/en/function.fseek.php
 * @throws \RuntimeException on failure.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, rewind) {

	zval *this_ptr = getThis();



}

/**
 * Seek to a position in the stream.
 *
 * @see http://www.php.net/manual/en/function.fseek.php
 * @param int $offset Stream offset
 * @param int $whence Specifies how the cursor position will be calculated
 *     based on the seek offset. Valid values are identical to the built-in
 *     PHP $whence values for `fseek()`.  SEEK_SET: Set position equal to
 *     offset bytes SEEK_CUR: Set position to current location plus offset
 *     SEEK_END: Set position to end-of-stream plus offset.
 * @throws \RuntimeException on failure.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, seek) {

	zval *offset, offset_sub, *whence = NULL, whence_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&whence_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset, &whence);

	if (!whence) {
		whence = &whence_sub;
		ZEPHIR_INIT_VAR(whence);
		ZVAL_LONG(whence, 0);
	}



}

/**
 * Returns the current position of the file read/write pointer
 *
 * @return int Position of the file pointer
 * @throws \RuntimeException on error.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, tell) {

	zval *this_ptr = getThis();



}

/**
 * Write data to the stream.
 *
 * @param string $string The string that is to be written.
 * @return int Returns the number of bytes written to the stream.
 * @throws \RuntimeException on failure.
 */
PHP_METHOD(Phalcon_Http_Message_Stream, write) {

	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params(0, 1, 0, &data);




}

