
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */

namespace Phalcon\ADR\Responder;

use Phalcon\Contracts\ADR\Payload\Payload;
use Phalcon\Contracts\ADR\Responder\Responder;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\ResponseInterface;

/**
 * Sets the response HTTP status code from the payload status, via StatusMapper.
 */
class StatusResponder implements Responder
{
    protected <StatusMapper> mapper;

    public function __construct(<StatusMapper> mapper = null)
    {
        if null === mapper {
            let this->mapper = new StatusMapper();
        } else {
            let this->mapper = mapper;
        }
    }

    public function __invoke(
        <RequestInterface> request, 
        <ResponseInterface> response, 
        <Payload> payload
    ) -> <ResponseInterface> {
        var status;

        let status = payload->getStatus();
        if null !== status {
            response->setStatusCode(this->mapper->toHttpCode((string) status));
        }

        return response;
    }
}
