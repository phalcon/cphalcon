
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

namespace Phalcon\Http\Request;

/**
 * Phalcon\Http\Request\FileInterface
 *
 * Interface for Phalcon\Http\Request\File
 *
 */
interface FileInterface {

	/**
	 * Phalcon\Http\Request\FileInterface constructor
	 *
	 * @param array file
	 */
	public function __construct(file);

	/**
	 * Returns the file size of the uploaded file
	 *
	 * @return int
	 */
	public function getSize();

	/**
	 * Returns the real name of the uploaded file
	 *
	 * @return string
	 */
	public function getName();

	/**
	 * Returns the temporal name of the uploaded file
	 *
	 * @return string
	 */
	public function getTempName();

	/**
	 * Returns the mime type reported by the browser
	 * This mime type is not completely secure, use getRealType() instead
	 *
	 * @return string
	 */
	public function getType();

	/**
	 * Gets the real mime type of the upload file using finfo
	 *
	 * @return string
	 */
	public function getRealType();

	/**
	 * Move the temporary file to a destination
	 *
	 * @param string destination
	 * @return boolean
	 */
	public function moveTo(destination);

}