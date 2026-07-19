
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

use Phalcon\ADR\Exceptions\MethodNotAllowed;
use Phalcon\ADR\Exceptions\RouteNotFound;
use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Payload\Status;
use Phalcon\Contracts\ADR\Payload\Payload as PayloadContract;
use Phalcon\Contracts\ADR\Responder\Responder;
use Phalcon\Contracts\Logger\Logger;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\ResponseInterface;
use Throwable;

/**
 * Turns a thrown exception into a response through the responder chain.
 *
 * The full diagnostic (class, message, file:line and the exception itself) goes
 * to the log with a correlation reference; the client receives only a generic
 * message plus that same reference, unless debug mode is on. Exceptions are
 * mapped to statuses deterministically: an exact class match first, then the
 * ancestor chain, so map ordering never matters.
 */
final class ErrorResponder
{
    /**
     * @var Responder
     */
    protected chain;

    /**
     * @var bool
     */
    protected debug;

    /**
     * @var array
     */
    protected exceptionMap;

    /**
     * @var Logger
     */
    protected logger;

    public function __construct(
        <Responder> chain, 
        <Logger> logger, 
        bool debug = false, 
        array exceptionMap = []
    ) {
        let this->chain        = chain,
            this->logger       = logger,
            this->debug        = debug,
            this->exceptionMap = exceptionMap + this->defaultMap();
    }

    public function handle(
        <RequestInterface> request, 
        <ResponseInterface> response, 
        <Throwable> exception
    ) -> <ResponseInterface> {
        var status, ref, payload;

        let ref = this->correlationId(request);

        this->logger->error(
            sprintf(
                "%s: %s in %s:%d",
                get_class(exception),
                exception->getMessage(),
                exception->getFile(),
                exception->getLine()
            ),
            ["exception": exception, "ref": ref]
        );

        let status = this->resolveStatus(exception);

        let payload = (new Payload())
            ->withStatus(status)
            ->withResult(this->details(exception, ref));

        return this->chain->__invoke(request, response, payload);
    }

    protected function correlationId(<RequestInterface> request) -> string
    {
        var id;

        let id = request->getHeader("X-Request-Id");
        if empty id {
            let id = bin2hex(random_bytes(8));
        }

        return (string) id;
    }

    protected function defaultMap() -> array
    {
        return [
            RouteNotFound::class    : Status::NOT_FOUND,
            MethodNotAllowed::class : Status::METHOD_NOT_ALLOWED
        ];
    }

    protected function details(<Throwable> exception, string ref) -> array
    {
        if this->debug {
            return [
                "message": exception->getMessage(),
                "trace":   exception->getTraceAsString(),
                "ref":     ref
            ];
        }

        return [
            "message": "Internal Server Error",
            "ref":     ref
        ];
    }

    private function resolveStatus(<Throwable> exception) -> string
    {
        var className, ancestor, ancestors;

        let className = get_class(exception);

        if isset this->exceptionMap[className] {
            return this->exceptionMap[className];
        }

        let ancestors = array_merge(
            array_values(class_parents(exception)),
            array_values(class_implements(exception))
        );

        for ancestor in ancestors {
            if isset this->exceptionMap[ancestor] {
                return this->exceptionMap[ancestor];
            }
        }

        return Status::ERROR;
    }
}
