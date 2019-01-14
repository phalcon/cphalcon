
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Session\Exception;

/**
 * Phalcon\Session\Adapter\Noop
 *
 * This is the file based adapter. It stores sessions in a file based system
 *
 * <code>
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Files;
 *
 * $session = new Manager();
 * $files = new Files(
 *     [
 *         'savePath' => '/tmp',
 *     ]
 * );
 * $session->setHandler(new Files());
 * </code>
 */
class Files extends Noop
{
    /**
     * @var string
     */
	private path = "";

	public function __construct(array! options = [])
	{
		var path, options;

		parent::__construct(options);

		let options = this->options;

        /**
         * Get the save_path from the passed options. If not defined
         * get it from php.ini
         */
		if !fetch path, options["save_path"] {
            let path = ini_get("session.save_path");
		}

        if true !== is_writable(path) {
            throw new Exception("The save_path [" . path . "]is not writeable");
        }

		let this->path = path;
	}

	public function destroy(var id) -> bool
	{
		var name;

		let name = this->path . this->getPrefixedName(id);

		if (true === file_exists(name)) {
			unlink(name);
		}

		return true;
	}

	public function gc(var maxlifetime) -> bool
	{
		var file, pattern;

		let pattern = this->path . this->prefix . "*";

		for file in glob(pattern) {
			if (true === file_exists(file) && filemtime(file) + maxlifetime < time()) {
				unlink(file);
			}
		}

		return true;
	}

	public function open(var savePath, var sessionName) -> bool
	{
		var path;

		if true !== ends_with(savePath, "/") {
			let path = savePath . "/";
		}

		let this->path = path;

		return true;
	}

	public function read(var id) -> string
	{
		var data, name;

		let name = this->path . this->getPrefixedName(id),
			data = "";

		if true === file_exists(name) {
			let data = file_get_contents(name);

			if (false === data) {
				return "";
			}
		}

		return data;
	}

	public function write(var id, var data) -> bool
	{
		var name;

		let name = this->path . this->getPrefixedName(id);

		return false !== file_put_contents(name, data);
	}
}
