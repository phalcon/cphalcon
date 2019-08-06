
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Helper\Str;
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
 * $session->setHandler($files);
 * ```
 */
class Stream extends Noop
{
    /**
     * @var string
     */
    private path = "";

    public function __construct(array! options = []) -> void
    {
        var path, options;

        parent::__construct(options);

        let options = this->options;

        /**
         * Get the save_path from the passed options. If not defined
         * get it from php.ini
         */
        if !fetch path, options["savePath"] {
            let path = ini_get("session.save_path");
            if empty path {
                let path = sys_get_temp_dir();
            }
        }

        if unlikely !is_writable(path) {
            throw new Exception("The session save path [" . path . "] is not writeable");
        }

        let this->path = Str::dirSeparator(path);
    }

    public function destroy(var id) -> bool
    {
        var file;

        let file = this->path . this->getPrefixedName(id);

        if is_file(file) {
             unlink(file);
         }

        return true;
    }

    public function gc(var maxlifetime) -> bool
    {
        var file, pattern, time;

        let pattern = this->path . this->prefix . "*",
            time    = time() - maxlifetime;

        for file in glob(pattern) {
            if is_file(file) && (filemtime(file) < time) {
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
        if unlikely !empty savePath {
            if ends_with(savePath, "/") {
                let this->path = savePath;
            } else {
                let this->path = savePath . "/";
            }
        }
        return true;
    }

    public function read(var id) -> string
    {
        var name;

        let name = this->path . this->getPrefixedName(id);

        if file_exists(name) {
            return (string) file_get_contents(name);
        }

        return "";
    }

    public function write(var id, var data) -> bool
    {
        var name;

        let name = this->path . this->getPrefixedName(id);

        return false !== file_put_contents(name, data);
    }

    /**
     * Returns current session stream path
     *
     * @return string
     */
    public function getPath() -> string
    {
        return this->path;
    }
}
