
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Cache\Backend\Redis as CacheRedis;
use Phalcon\Cache\Frontend\None as FrontendNone;

/**
 * Phalcon\Session\Adapter\Noop
 *
 * This is an "empty" or null adapter. It can be used for testing or any
 * other purpose that no session needs to be invoked
 *
 * <code>
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Redis
 *
 * $session = new Manager();
 * $adapter = new Redis(
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "index"      => 0,
 *     ]
 * );
 *
 * $session->setAdapter($adapter);
 * </code>
 */class Redis extends Noop
{
	public function __construct(array options = [])
	{
		var options, params;

	    parent::__construct(options);

	    let options              = this->options,
	        params["host"]       = this->arrayGetDefault(options, "host", "127.0.0.1"),
		    params["port"]       = this->arrayGetDefault(options, "port", 6379),
		    params["index"]      = this->arrayGetDefault(options, "index", 0),
		    params["persistent"] = this->arrayGetDefault(options, "persistent", false),
		    this->ttl            = this->arrayGetDefault(options, "ttl", this->ttl);

		let this->connection = new CacheRedis(
			new FrontendNone(
				[
					"lifetime" : this->ttl
				]
			),
			params
		);
	}

	public function destroy(var id) -> bool
	{
		var name = this->getPrefixedName(id);

		if (true !== empty(name) && this->connection->exists(name)) {
			return (bool) this->connection->delete(name);
		}

		return true;
	}

	public function read(var id) -> string
	{
		var name = this->getPrefixedName(id),
		    data = this->connection->get(name, this->ttl);

		return data;
	}

	public function write(var id, var data) -> void
	{
		var name = this->getPrefixedName(id);

		this->connection->save(name, data, this->ttl);
	}
}
