
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Session\Adapter\Exceptions\AdapterRuntimeError;
use Phalcon\Session\Adapter\Exceptions\InvalidSavePath;
use Phalcon\Session\Adapter\Exceptions\SavePathUnavailable;
use Phalcon\Traits\Php\FileTrait;
use Phalcon\Traits\Support\Helper\Arr\GetTrait;

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
    use FileTrait;
    use GetTrait;

    /**
     * Session options
     *
     * @var array
     */
    protected options = [];

    /**
     * Session prefix
     *
     * @var string
     */
    protected prefix = "";

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
    public function __construct( array options = [])
    {
        var path;

        let this->prefix  = this->getArrVal(options, "prefix", ""),
            this->options = options;

        /**
         * Get the save_path from the passed options. If not defined
         * get it from php.ini
         */
        let path = this->getArrVal(options, "savePath", this->phpIniGet("session.save_path"));

        if unlikely true === empty(path) {
            throw new InvalidSavePath();
        }

        if unlikely true !== this->phpIsWritable(path) {
            throw new SavePathUnavailable(path);
        }

        let this->path = this->getDirSeparator(path);
    }

    public function destroy(var id) -> bool
    {
        var file;

        let file = this->path . this->getPrefixedName(id);

        if this->phpFileExists(file) && is_file(file) {
            this->phpUnlink(file);
        }

        return true;
    }

    /**
     * Garbage Collector
     *
     * @param int $max_lifetime
     * @return false|int
     */
    public function gc(int max_lifetime) -> int|false
    {
        var file, glob, last, pattern, time;

        let pattern = this->path . this->prefix . "*",
            time    = time() - max_lifetime,
            glob    = this->getGlobFiles(pattern);

        if (false === glob) {
            let last = error_get_last();
            if (isset(last["message"])) {
                let last = last["message"];
            } else {
                let last = "Unexpected gc error";
            }
            throw new AdapterRuntimeError(last);
        }

        if (!empty(glob)) {
            for file in glob {
                if true === this->phpFileExists(file) &&
                   true === is_file(file)     &&
                   (filemtime(file) < time) {
                    this->phpUnlink(file);
                }
            }
        }

        return 1;
    }

    /**
    * Ignore the savePath and use local defined path
    *
    * @return bool
    */
    public function open(var path, var name) -> bool
    {
        return true;
    }

    /**
     * Reads data from the adapter
     */
    public function read(var id) -> string
    {
        var data, name, pointer;

        let name = this->path . this->getPrefixedName(id),
            data = "";

        if true === this->phpFileExists(name) {
            let pointer = this->phpFopen(name, "r");

            if (flock(pointer, LOCK_SH)) {
                let data = this->phpFileGetContents(name);
            }

            this->phpFclose(pointer);

            if false === data {
                return "";
            }
        }

        return data;
    }

    /**
     * Refresh the session file modification time without changing its data
     */
    public function updateTimestamp(var id, var data) -> bool
    {
        var name;

        let name = this->path . this->getPrefixedName(id);

        return touch(name);
    }

    /**
     * Validate the session id (used when strict mode is enabled)
     */
    public function validateId(var id) -> bool
    {
        return this->phpFileExists(this->path . this->getPrefixedName(id));
    }

    public function write(var id, var data) -> bool
    {
        var name;

        let name = this->path . this->getPrefixedName(id);

        return false !== this->phpFilePutContents(name, data, LOCK_EX);
    }

    private function getDirSeparator( string directory) -> string
    {
        return rtrim(directory, DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;
    }


    /**
     * Gets the glob array or returns false on failure
     *
     * @param string $pattern
     *
     * @return array|false
     */
    protected function getGlobFiles(string pattern) -> array | false
    {
        var errorLevel, glob;

        let errorLevel = error_reporting(0);
        error_clear_last();
        let glob = glob(pattern);
        error_reporting(errorLevel);

        return glob;
    }

    /**
     * Helper method to get the name prefixed
     */
    protected function getPrefixedName(var name) -> string
    {
        let name = (string) name;

        return this->prefix . name;
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
}
