
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Http\Request;

/**
 * Phalcon\Http\Request\FileInterface
 *
 * Interface for Phalcon\Http\Request\File
 *
 */
interface FileInterface
{

	/**
	 * Phalcon\Http\Request\FileInterface constructor
	 */
	public function __construct(array! file, key = null);

	/**
	 * Returns the file size of the uploaded file
	 */
	public function getSize() -> int;

	/**
	 * Returns the real name of the uploaded file
	 */
	public function getName() -> string;

	/**
	 * Returns the temporal name of the uploaded file
	 */
	public function getTempName() -> string;

	/**
	 * Returns the mime type reported by the browser
	 * This mime type is not completely secure, use getRealType() instead
	 */
	public function getType() -> string;

	/**
	 * Gets the real mime type of the upload file using finfo
	 */
	public function getRealType() -> string;

	/**
	 * Move the temporary file to a destination
	 */
	public function moveTo(string! destination) -> boolean;

}