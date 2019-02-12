
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Phalcon\Http\Message\ServerRequest;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\ServerRequestFactoryInterface;
use Psr\Http\Message\UriInterface;

class ServerRequestFactory implements ServerRequestFactoryInterface
{
	/**
	 * Create a new server request.
	 *
	 * Note that server parameters are taken precisely as given - no parsing/processing
	 * of the given values is performed. In particular, no attempt is made to
	 * determine the HTTP method or URI, which must be provided explicitly.
	 */
	public function createServerRequest(string method, var uri, array serverParams = []) -> <ServerRequestInterface>
	{
		var factory;

		let factory = new ServerRequest(method, uri, serverParams);

		return factory;
	}
}
