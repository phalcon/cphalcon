
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request;

/**
 * Phalcon\Http\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *```php
 * use Phalcon\Mvc\Controller;
 *
 * class PostsController extends Controller
 * {
 *     public function uploadAction()
 *     {
 *         // Check if the user has uploaded files
 *         if ($this->request->hasFiles() == true) {
 *             // Print the real file names and their sizes
 *             foreach ($this->request->getUploadedFiles() as $file) {
 *                 echo $file->getName(), " ", $file->getSize(), "\n";
 *             }
 *         }
 *     }
 * }
 *```
 */
class File implements FileInterface
{
    /**
     * @var string|null
     */
    protected error = null { get };

    /**
     * @var string
     */
    protected extension { get };

    /**
     * @var string|null
     */
    protected key = null { get };

    /**
     * @var string
     */
    protected name;

    /**
     * @var string
     */
    protected realType;

    /**
     * @var int
     */
    protected size = 0;

    /**
     * @var string|null
     */
    protected tmp = null;

    /**
     * @var string
     */
    protected type;

    /**
     * Phalcon\Http\Request\File constructor
     */
    public function __construct(array! file, key = null)
    {
        var name;

        if fetch name, file["name"] {
            let this->name = name;

            if defined("PATHINFO_EXTENSION") {
                let this->extension = pathinfo(name, PATHINFO_EXTENSION);
            }
        }

        let this->tmp   = this->getArrVal(file, "tmp_name"),
            this->size  = this->getArrVal(file, "size"),
            this->type  = this->getArrVal(file, "type"),
            this->error = this->getArrVal(file, "error");

        if key {
            let this->key = key;
        }
    }

    /**
     * Returns the real name of the uploaded file
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Gets the real mime type of the upload file using finfo
     */
    public function getRealType() -> string
    {
        var finfo, mime;

        let finfo = finfo_open(FILEINFO_MIME_TYPE);

        if typeof finfo != "resource" {
            return "";
        }

        let mime = finfo_file(finfo, this->tmp);

        finfo_close(finfo);

        return mime;
    }

    /**
     * Returns the file size of the uploaded file
     */
    public function getSize() -> int
    {
        return this->size;
    }

    /**
     * Returns the temporary name of the uploaded file
     */
    public function getTempName() -> string
    {
        return this->tmp;
    }

    /**
     * Returns the mime type reported by the browser
     * This mime type is not completely secure, use getRealType() instead
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Checks whether the file has been uploaded via Post.
     */
    public function isUploadedFile() -> bool
    {
        var tmp;

        let tmp = this->getTempName();

        return typeof tmp == "string" && is_uploaded_file(tmp);
    }

    /**
     * Moves the temporary file to a destination within the application
     */
    public function moveTo(string! destination) -> bool
    {
        return move_uploaded_file(this->tmp, destination);
    }

    /**
     * @todo Remove this when we get traits
     */
    private function getArrVal(
        array! collection,
        var index,
        var defaultValue = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        return value;
    }
}
