
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Phalcon\Helper\Number;
use Phalcon\Http\Message\Exception;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UploadedFileInterface;

/**
 * Value object representing a file uploaded through an HTTP request.
 *
 * Instances of this interface are considered immutable; all methods that
 * might change state MUST be implemented such that they retain the internal
 * state of the current instance and return an instance that contains the
 * changed state.
 */
class UploadedFile implements UploadedFileInterface
{
	/**
	 * If the file has already been moved, we hold that status here
	 *
	 * @var bool
	 */
	private alreadyMoved = false;

	/**
	 * Retrieve the filename sent by the client.
	 *
	 * Do not trust the value returned by this method. A client could send
	 * a malicious filename with the intention to corrupt or hack your
	 * application.
	 *
	 * Implementations SHOULD return the value stored in the "name" key of
	 * the file in the $_FILES array.
	 *
	 * @var string | null
	 */
	private clientFilename = null { get };

	/**
	 * Retrieve the media type sent by the client.
	 *
	 * Do not trust the value returned by this method. A client could send
	 * a malicious media type with the intention to corrupt or hack your
	 * application.
	 *
	 * Implementations SHOULD return the value stored in the "type" key of
	 * the file in the $_FILES array.
	 *
	 * @var string | null
	 */
	private clientMediaType = null { get };

	/**
	 * Retrieve the error associated with the uploaded file.
	 *
	 * The return value MUST be one of PHP's UPLOAD_ERR_XXX constants.
	 *
	 * If the file was uploaded successfully, this method MUST return
	 * UPLOAD_ERR_OK.
	 *
	 * Implementations SHOULD return the value stored in the "error" key of
	 * the file in the $_FILES array.
	 *
	 * @see http://php.net/manual/en/features.file-upload.errors.php
	 *
	 * @var int
	 */
	private error = 0 { get };

	/**
	 * If the stream is a string (file name) we store it here
	 *
	 * @var string
	 */
	private fileName = "";

	/**
	 * Retrieve the file size.
	 *
	 * Implementations SHOULD return the value stored in the "size" key of
	 * the file in the $_FILES array if available, as PHP calculates this based
	 * on the actual size transmitted.
	 *
	 * @var int | null
	 */
	private size = null { get };

	/**
	 * Holds the stream/string for the uploaded file
	 *
	 * @var <StreamInterface> | string | null
	 */
	private stream;

	/**
	 * Constructor
	 */
	public function __construct(
        var stream,
        int size,
        int error = 0,
        string clientFilename = null,
        string clientMediaType = null
	) {
		/**
		 * Check the stream passed. It can be a string representing a file or
		 * a StreamInterface
		 */
		this->checkStream(stream, error);

		/**
		 * Check the error
		 */
		this->checkError(error);

		let this->size            = size,
			this->clientFilename  = clientFilename,
			this->clientMediaType = clientMediaType;
	}

	/**
	 * Retrieve a stream representing the uploaded file.
	 *
	 * This method MUST return a StreamInterface instance, representing the
	 * uploaded file. The purpose of this method is to allow utilizing native PHP
	 * stream functionality to manipulate the file upload, such as
	 * stream_copy_to_stream() (though the result will need to be decorated in a
	 * native PHP stream wrapper to work with such functions).
	 *
	 * If the moveTo() method has been called previously, this method MUST raise
	 * an exception.
	 *
	 * @return StreamInterface Stream representation of the uploaded file.
	 * @throws \RuntimeException in cases when no stream is available.
	 * @throws \RuntimeException in cases when no stream can be created.
	 */
	public function getStream() -> <StreamInterface>
	{
		if this->error !== constant("UPLOAD_ERR_OK") {
			throw new Exception(
				this->getErrorDescription(this->error)
			);
		}

		if true === this->alreadyMoved {
			throw new Exception(
				"The file has already been moved to the target location"
			);
		}

		if !(this->stream instanceof StreamInterface) {
			let this->stream = new Stream(this->fileName);
		}

		return this->stream;
	}

	/**
	 * Move the uploaded file to a new location.
	 *
	 * Use this method as an alternative to move_uploaded_file(). This method is
	 * guaranteed to work in both SAPI and non-SAPI environments.
	 * Implementations must determine which environment they are in, and use the
	 * appropriate method (move_uploaded_file(), rename(), or a stream
	 * operation) to perform the operation.
	 *
	 * $targetPath may be an absolute path, or a relative path. If it is a
	 * relative path, resolution should be the same as used by PHP's rename()
	 * function.
	 *
	 * The original file or stream MUST be removed on completion.
	 *
	 * If this method is called more than once, any subsequent calls MUST raise
	 * an exception.
	 *
	 * When used in an SAPI environment where $_FILES is populated, when writing
	 * files via moveTo(), is_uploaded_file() and move_uploaded_file() SHOULD be
	 * used to ensure permissions and upload status are verified correctly.
	 *
	 * If you wish to move to a stream, use getStream(), as SAPI operations
	 * cannot guarantee writing to stream destinations.
	 *
	 * @see http://php.net/is_uploaded_file
	 * @see http://php.net/move_uploaded_file
	 *
	 * @throws \InvalidArgumentException if the $targetPath specified is invalid.
	 * @throws \RuntimeException on any error during the move operation.
	 * @throws \RuntimeException on the second or subsequent call to the method.
	 */
	public function moveTo(var targetPath) -> void
	{
		var sapi, dirname;

		if true === this->alreadyMoved {
			throw new Exception("File has already been moved");
		}

		if constant("UPLOAD_ERR_OK") !== this->error {
			throw new Exception(this->getErrorDescription(this->error));
		}

		let dirname = dirname(targetPath);

		/**
		 * All together for early failure
		 */
		if !(typeof targetPath === "string" && !empty(targetPath) && is_dir(dirname) && is_writable(dirname)) {
			throw new Exception("Target folder is empty string, not a folder or not writable");
		}

		/**
		 * Figure out the SAPI path
		 */
		let sapi = constant("PHP_SAPI");

		if empty(sapi) || empty(this->fileName) || starts_with(sapi, "cli") {
			this->storeFile(targetPath);
		} else {
			if !move_uploaded_file(this->fileName, targetPath) {
				throw new Exception("The file cannot be moved to the target folder");
			}
		}

		let this->alreadyMoved = true;
	}

	/**
	 * Checks the passed error code and if not in the range throws an exception
	 */
	private function checkError(int error) -> void
	{
		if true !== Number::between(error, constant("UPLOAD_ERR_OK"), constant("UPLOAD_ERR_EXTENSION")) {
			throw new Exception(
				"Invalid 'error'. Must be one of the UPLOAD_ERR_* constants"
			);
		}

		let this->error = error;
	}

	/**
	 * Checks the passed error code and if not in the range throws an exception
	 */
	private function checkStream(var stream, int error) -> void
	{
		if error === constant("UPLOAD_ERR_OK") {
			switch (true) {
				case (typeof stream === "string"):
					let this->fileName = stream;
					break;
				case (true === is_resource(stream)):
					let this->stream = new Stream(stream);
					break;
				case (stream instanceof StreamInterface):
					let this->stream = stream;
					break;
				default:
					throw new Exception("Invalid stream or file passed");
			}
		}
	}

	/**
	 * Returns a description string depending on the upload error code passed
	 */
	private function getErrorDescription(int error) -> string
	{
		switch error {
			case constant("UPLOAD_ERR_OK"):
				return  "There is no error, the file uploaded with success.";
			case constant("UPLOAD_ERR_INI_SIZE"):
				return  "The uploaded file exceeds the upload_max_filesize directive in php.ini.";
			case constant("UPLOAD_ERR_FORM_SIZE"):
				return  "The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form.";
			case constant("UPLOAD_ERR_PARTIAL"):
				return  "The uploaded file was only partially uploaded.";
			case constant("UPLOAD_ERR_NO_FILE"):
				return  "No file was uploaded.";
			case constant("UPLOAD_ERR_NO_TMP_DIR"):
				return  "Missing a temporary folder.";
			case constant("UPLOAD_ERR_CANT_WRITE"):
				return  "Failed to write file to disk.";
			case constant("UPLOAD_ERR_EXTENSION"):
				return  "A PHP extension stopped the file upload.";
		}

		return "Unknown upload error";
	}

	/**
	 * Store a file in the new location (stream)
	 */
	private function storeFile(string targetPath) -> void
	{
		var data, handle, stream;

		let handle = fopen(targetPath, "w+b"),
			stream = this->getStream();

		stream->rewind();
		while (true !== stream->eof()) {
			let data = stream->read(2048);
			fwrite(handle, data);
		}

		fclose(handle);
	}
}
