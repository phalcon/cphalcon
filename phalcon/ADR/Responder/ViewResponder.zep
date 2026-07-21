
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
use Phalcon\Contracts\View\Renderer;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\ResponseInterface;

/**
 * Renders a template from the payload and returns it as an HTML response.
 *
 * The HTML sibling of `JsonResponder`: serialization is swapped for rendering,
 * the status mapping and the `Responder` contract stay the same. It depends on
 * the neutral `Renderer` contract only, so the ADR component never imports the
 * MVC view.
 */
final class ViewResponder implements Responder
{
    /**
     * @var Renderer
     */
    protected renderer;

    /**
     * @var StatusMapper
     */
    protected statusMapper;

    /**
     * @var string
     */
    protected template = "";

    public function __construct(
        <Renderer> renderer,
        <StatusMapper> statusMapper,
        string template = ""
    ) {
        let this->renderer     = renderer,
            this->statusMapper = statusMapper,
            this->template     = template;
    }

    public function __invoke(
        <RequestInterface> request,
        <ResponseInterface> response,
        <Payload> payload
    ) -> <ResponseInterface> {
        var html;

        let html = this->renderer->render(
            this->template,
            this->viewData(payload)
        );

        response
            ->setStatusCode(
                this->statusMapper->toHttpCode((string) payload->getStatus())
            )
            ->setContentType("text/html")
            ->setContent(html);

        return response;
    }

    /**
     * Returns a copy of the responder bound to the given template. The action
     * names the view; the payload stays free of presentation concerns.
     */
    public function withTemplate(string template) -> <static>
    {
        var cloned;

        let cloned           = clone this,
            cloned->template = template;

        return cloned;
    }

    /**
     * Flattens the payload into the variables handed to the template.
     */
    protected function viewData(<Payload> payload) -> array
    {
        return [
            "result"   : payload->getResult(),
            "messages" : payload->getMessages(),
            "status"   : payload->getStatus()
        ];
    }
}
