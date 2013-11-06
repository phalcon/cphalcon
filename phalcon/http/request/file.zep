
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
 * Phalcon\Http\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *<code>
 *	class PostsController extends \Phalcon\Mvc\Controller
 *	{
 *
 *		public function uploadAction()
 *		{
 *			//Check if the user has uploaded files
 *			if ($this->request->hasFiles() == true) {
 *				//Print the real file names and their sizes
 *				foreach ($this->request->getUploadedFiles() as $file){
 *					echo $file->getName(), " ", $file->getSize(), "\n";
 *				}
 *			}
 *		}
 *
 *	}
 *</code>
 */
class File implements Phalcon\Http\Request\FileInterface
{

	protected _name;

	protected _tmp;

	protected _size;

	protected _type;

	protected _realType;

	/**
	 * Phalcon\Http\Request\File constructor
	 *
	 * @param array file
	 */
	public function __construct(var file)
	{
		var name, tempName, size, type;

		if typeof file != "array" {
			throw new Phalcon\Http\Request\Exception("Phalcon\\Http\\Request\\File requires a valid uploaded file");
		}

		if fetch name, file["name"] {
			let this->_name = name;
		}

		if fetch tempName, file["tmp_name"] {
			let this->_tmp = tempName;
		}

		if fetch size, file["size"] {
			let this->_size = size;
		}

		if fetch type, file["type"] {
			let this->_type = type;
		}
	}

	/**
	 * Returns the file size of the uploaded file
	 *
	 * @return int
	 */
	public function getSize() -> int
	{
		return this->_size;
	}

	/**
	 * Returns the real name of the uploaded file
	 *
	 * @return string
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Returns the temporal name of the uploaded file
	 *
	 * @return string
	 */
	public function getTempName() -> string
	{
		return this->_tmp;
	}

	/**
	 * Returns the mime type reported by the browser
	 * This mime type is not completely secure, use getRealType() instead
	 *
	 * @return string
	 */
	public function getType() -> string
	{
		return this->_type;
	}

	/**
	 * Gets the real mime type of the upload file using finfo
	 *
	 * @return string
	 */
	public function getRealType() -> string
	{
		var finfo, mime;

        let finfo = finfo_open(FILEINFO_MIME_TYPE);
        if typeof finfo != "resource" {
        	return "";
        }

        let mime = finfo_file(finfo, this->_tmp);
        fclose(finfo);

        return mime;
	}

	/**
	 * Moves the temporary file to a destination within the application
	 *
	 * @param string destination
	 * @return boolean
	 */
	public function moveTo(string! destination) -> boolean
	{
		return move_uploaded_file(this->_tmp, destination);
	}

}