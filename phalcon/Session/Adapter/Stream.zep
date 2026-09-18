
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Contracts\Session\SessionTypes;
use Phalcon\Session\Adapter\Exceptions\AdapterRuntimeError;
use Phalcon\Session\Adapter\Exceptions\InvalidSavePath;
use Phalcon\Session\Adapter\Exceptions\SavePathUnavailable;
use Phalcon\Traits\Php\FileTrait;
use Phalcon\Traits\Php\IniTrait;
use Phalcon\Traits\Support\Helper\Arr\GetTrait;
use Phalcon\Traits\Support\Helper\Str\DirSeparatorTrait;

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
 *
 * @phpstan-import-type session_files from SessionTypes
 * @phpstan-import-type session_stream_options from SessionTypes
 *
 * @phpstan-property session_stream_options $options
 */
class Stream extends Noop
{
    use DirSeparatorTrait;
    use FileTrait;
    use GetTrait;
    use IniTrait;

    /**
     * Session options
     *
     * @phpstan-var session_stream_options
     */
    protected array options = [];

    /**
     * Session prefix
     */
    protected string prefix = "";

    /**
     * The path of the session files
     */
    private string path = "";

    /**
     * Constructor
     *
     * @phpstan-param session_stream_options $options
     *
     * @throws InvalidSavePath
     * @throws SavePathUnavailable
     */
    public function __construct(array options = [])
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

        let this->path = this->toDirSeparator(path);
    }

    public function destroy(string id) -> bool
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
     *
     * @return false|int
     * @throws AdapterRuntimeError
     */
    public function gc(int max_lifetime) -> false | int
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
    */
    public function open(string path, string name) -> bool
    {
        return true;
    }

    /**
     * Reads data from the adapter
     */
    public function read(string id) -> string
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
    public function updateTimestamp(string id, string data) -> bool
    {
        var name;

        let name = this->path . this->getPrefixedName(id);

        return touch(name);
    }

    /**
     * Validate the session id (used when strict mode is enabled)
     */
    public function validateId(string id) -> bool
    {
        return this->phpFileExists(this->path . this->getPrefixedName(id));
    }

    public function write(string id, string data) -> bool
    {
        var name;

        let name = this->path . this->getPrefixedName(id);

        return false !== this->phpFilePutContents(name, data, LOCK_EX);
    }

    /**
     * Gets the glob array or returns false on failure
     *
     * @param string $pattern
     *
     * @return array|false
     *
     * @phpstan-return session_files|false
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
     *
     * @param float|int|string $name
     */
    protected function getPrefixedName(var name) -> string
    {
        let name = (string) name;

        /**
         * Remove path separators from the id so a crafted id cannot climb out
         * of the session directory (CWE-22) when a handler method is called
         * directly, bypassing the Manager id validation. Mirrors the sibling
         * Storage\Adapter\Stream hardening.
         */
        return this->prefix . str_replace(["/", "\\", ":"], "_", name);
    }
}
