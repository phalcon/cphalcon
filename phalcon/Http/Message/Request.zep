
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */

namespace Phalcon\Http\Message;

use Phalcon\Http\Message\Stream\Input;
use Phalcon\Http\Message\AbstractRequest;
use Psr\Http\Message\RequestInterface;
use Psr\Http\Message\StreamInterface;
use Psr\Http\Message\UriInterface;

/**
 * PSR-7 Request
 */
final class Request extends AbstractRequest implements RequestInterface
{
    /**
     * Request constructor.
     *
     * @param string                          $method
     * @param UriInterface|string|null        $uri
     * @param StreamInterface|resource|string $body
     * @param array                           $headers
     */
    public function __construct(
        string method = self::METHOD_GET,
        var uri = null,
        var body = "php://memory",
        var headers = []
    ) {
        if unlikely "php://input" === body {
            let body = new Input();
        }

        let this->uri     = this->processUri(uri),
            this->headers = this->processHeaders(headers),
            this->method  = this->processMethod(method),
            this->body    = this->processBody(body, "w+b");
    }
}
