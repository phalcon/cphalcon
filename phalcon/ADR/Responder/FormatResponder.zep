
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
 * Negotiates a formatter against the request `Accept` header and renders the
 * payload as the response body + content type.
 *
 * If no formatter accepts the header it falls back to the first (default)
 * formatter, so the content type and body are never left unset.
 */
class FormatResponder implements Responder
{
    /**
     * @var array
     */
    protected array formatters;

    public function __construct(array formatters = [])
    {
        let this->formatters = formatters;
    }

    public function __invoke(
        <RequestInterface> request, 
        <ResponseInterface> response, 
        <Payload> payload
    ) -> <ResponseInterface> {
        var accept, chosen = null, formatter;

        if empty this->formatters {
            return response;
        }

        let accept = (string) request->getHeader("Accept");

        for formatter in this->formatters {
            if formatter->accepts(accept) {
                let chosen = formatter;
                break;
            }
        }

        if null === chosen {
            let chosen = this->formatters[0];
        }

        response
            ->setContentType(chosen->contentType())
            ->setContent(chosen->format(payload));

        return response;
    }
}
