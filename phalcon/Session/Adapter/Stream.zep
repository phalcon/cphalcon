
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
 * $session->setAdapter($files);
 * ```
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
     * @param array options = [
     *     'prefix' => '',
     *     'savePath' => ''
     * ]
     */
    public function __construct(array! options = [])
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
        }

        if unlikely !is_writable(path) {
            throw new Exception("The session save path [" . path . "] is not writable");
        }

        let this->path = Str::dirSeparator(path);
    }

    public function destroy(var id) -> bool
    {
        var file;

        let file = this->path . this->getPrefixedName(id);

        if file_exists(file) && is_file(file) {
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
            if file_exists(file) &&
               is_file(file)     &&
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

    public function read(var id) -> string
    {
        var data, name, pointer;

        let name = this->path . this->getPrefixedName(id),
            data = "";

        if file_exists(name) {
            let pointer = fopen(name, 'r');

            if(flock(pointer, LOCK_SH)) {
                let data = file_get_contents(name);
            }

            fclose(pointer);

            if false === data {
                return "";
            }
        }

        return data;
    }

    public function write(var id, var data) -> bool
    {
        var name;

        let name = this->path . this->getPrefixedName(id);

        return false !== file_put_contents(name, data, LOCK_EX);
    }
}
