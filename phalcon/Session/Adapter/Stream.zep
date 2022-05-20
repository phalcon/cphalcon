
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Session\Exception;

/**
 * Phalcon\Session\Adapter\Stream
 *
 * This is the file based adapter. It stores sessions in a file based system
 *
 * ```php
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Stream;
 *
 * $session = new Manager();
 * $files = new Stream(
 *     [
 *         'savePath' => '/tmp',
 *     ]
 * );
 * $session->setAdapter($files);
 * ```
 *
 * @property array  $options
 * @property string $prefix
 * @property string $path
 */
class Stream extends Noop
{
    /**
     * @var string
     */
    private path = "";

    /**
     * Constructor
     *
     * @param array $options = [
     *     'prefix' => '',
     *     'savePath' => ''
     * ]
     */
    public function __construct(array! options = [])
    {
        var path;

        parent::__construct(options);

        /**
         * Get the save_path from the passed options. If not defined
         * get it from php.ini
         */
        let path = this->getArrVal(options, "savePath", this->phpIniGet("session.save_path"));

        if unlikely true === empty(path) {
            throw new Exception("The session save path cannot be empty");
        }

        if unlikely true !== this->phpIsWritable(path) {
            throw new Exception("The session save path [" . path . "] is not writable");
        }

        let this->path = this->getDirSeparator(path);
    }

    public function destroy(var sessionId) -> bool
    {
        var file;

        let file = this->path . this->getPrefixedName(sessionId);

        if file_exists(file) && is_file(file) {
            unlink(file);
        }

        return true;
    }

    /**
     * Garbage Collector
     */
    public function gc(var maxlifetime)
    {
        var file, pattern, time;

        let pattern = this->path . this->prefix . "*",
            time    = time() - maxlifetime;

        for file in glob(pattern) {
            if true === file_exists(file) &&
               true === is_file(file)     &&
               (filemtime(file) < time) {
                unlink(file);
            }
        }

        return true;
    }

    /**
    * Ignore the savePath and use local defined path
    *
    * @return bool
    */
    public function open(var savePath, var sessionName) -> bool
    {
        return true;
    }

    /**
     * Reads data from the adapter
     */
    public function read(var sessionId) -> string
    {
        var data, name, pointer;

        let name = this->path . this->getPrefixedName(sessionId),
            data = "";

        if true === this->phpFileExists(name) {
            let pointer = this->phpFopen(name, "r");

            if (flock(pointer, LOCK_SH)) {
                let data = this->phpFileGetContents(name);
            }

            fclose(pointer);

            if false === data {
                return "";
            }
        }

        return data;
    }

    public function write(var sessionId, var data) -> bool
    {
        var name;

        let name = this->path . this->getPrefixedName(sessionId);

        return false !== this->phpFilePutContents(name, data, LOCK_EX);
    }

    /**
     * @todo Remove this when we get traits
     */
    protected function getArrVal(
        array! collection,
        var index,
        var defaultValue = null,
        string! cast = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        if unlikely cast {
            settype(value, cast);
        }

        return value;
    }

    private function getDirSeparator(string! directory) -> string
    {
        return rtrim(directory, DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;
    }

    /**
     * @param string $filename
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.file-exists.php
     */
    protected function phpFileExists(string filename)
    {
        return file_exists(filename);
    }

    /**
     * @param string $filename
     *
     * @return string|false
     *
     * @link https://php.net/manual/en/function.file-get-contents.php
     */
    protected function phpFileGetContents(string filename)
    {
        return file_get_contents(filename);
    }

    /**
     * @param string   $filename
     * @param mixed    $data
     * @param int      $flags
     * @param resource $context
     *
     * @return int|false
     *
     * @link https://php.net/manual/en/function.file-put-contents.php
     */
    protected function phpFilePutContents(
        string filename,
        var data,
        int flags = 0,
        var context = null
    ) {
        return file_put_contents(filename, data, flags, context);
    }

    /**
     * @param string $filename
     * @param string $mode
     *
     * @return resource|false
     *
     * @link https://php.net/manual/en/function.fopen.php
     */
    protected function phpFopen(string filename, string mode)
    {
        return fopen(filename, mode);
    }

    /**
     * Gets the value of a configuration option
     *
     * @param string $varname
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.ini-get.php
     * @link https://php.net/manual/en/ini.list.php
     */
    protected function phpIniGet(string varname) -> string
    {
        return ini_get(varname);
    }

    /**
     * Tells whether the filename is writable
     *
     * @param string $filename
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.is-writable.php
     */
    protected function phpIsWritable(string filename) -> bool
    {
        return is_writable(filename);
    }
}
