
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

namespace Phalcon\ADR;

use Phalcon\ADR\Events\Event;
use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\Events\Manager;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\ResponseInterface;

/**
 * The terminal handler of the pipeline: fires the `adr:*` events around the
 * Action's execution.
 */
final class EventfulHandler implements Handler
{
    /**
     * @var Action
     */
    protected action;

    /**
     * @var Manager
     */
    protected events;

    public function __construct(<Action> action, <Manager> events)
    {
        let this->action = action,
            this->events = events;
    }

    public function __invoke(<AttributeRequest> request) -> <ResponseInterface>
    {
        var response;

        this->events->fire(Event::ADR_BEFORE_EXECUTE_ACTION, this->action, request);

        let response = this->action->__invoke(request);

        this->events->fire(Event::ADR_AFTER_EXECUTE_ACTION, this->action, response);

        return response;
    }
}
