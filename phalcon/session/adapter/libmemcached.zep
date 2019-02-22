
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Cache\Backend\Libmemcached as CacheLibmemcached;
use Phalcon\Cache\Frontend\Data as FrontendData;
use Phalcon\Helper\Arr;
use Phalcon\Session\Exception;

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
 * use Phalcon\Session\Adapter\Libmemcached;
 *
 * $session = new Manager();
 * $adapter = new Libmemcached(
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "localhost",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *              Memcached::OPT_HASH       => Memcached::HASH_MD5,
 *              Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
 *         "ttl"    => 3600,
 *         "prefix" => "my_",
 *     ]
 * );
 *
 * $session->setHandler($adapter);
 * </code>
 */
class Libmemcached extends Noop
{
	public function __construct(array! options = [])
	{
		var client, options, persistentId, prefix, servers, statsKey, ttl;

		parent::__construct(options);

		let options = this->options;

		if !fetch servers, options["servers"] {
			throw new Exception("No 'servers' specified in the options");
		}

		let client       = Arr::get(options, "client", []),
			ttl          = Arr::get(options, "ttl", this->ttl),
			statsKey     = Arr::get(options, "statsKey", ""),
			persistentId = Arr::get(options, "persistent_id", "phalcon-session");


		// Memcached has an internal max lifetime of 30 days
		let this->ttl = min(ttl, 2592000);

		let this->connection = new CacheLibmemcached(
			new FrontendData(
				[
					"lifetime" : this->ttl
				]
			),
			[
				"servers"       : servers,
				"client"     	: client,
				"prefix"        : prefix,
				"statsKey"      : statsKey,
				"persistent_id" : persistentId
			]
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

	public function write(var id, var data) -> bool
	{
		var name = this->getPrefixedName(id);

		return this->connection->save(name, data, this->ttl);
	}
}
