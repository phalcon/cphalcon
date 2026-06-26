
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */

namespace Phalcon\Queue\Adapter;

use Phalcon\Contracts\Queue\Message as MessageInterface;

/**
 * Shared implementation of every Message getter/setter, plus the
 * correlation-id / message-id / timestamp / reply-to header conveniences.
 * Concrete adapter messages extend this base.
 *
 * The convenience accessors are stored as transport headers under fixed keys
 * for binary compatibility with the wider interop ecosystem.
 */
abstract class AbstractMessage implements MessageInterface
{
    /**
     * @var string
     */
    protected body = "";

    /**
     * @var array
     */
    protected headers = [];

    /**
     * @var array
     */
    protected properties = [];

    /**
     * @var bool
     */
    protected redelivered = false;

    /**
     * AbstractMessage constructor.
     */
    public function __construct(string body = "", array properties = [], array headers = [])
    {
        let this->body       = body,
            this->properties = properties,
            this->headers    = headers;
    }

    /**
     * Returns the message body.
     */
    public function getBody() -> string
    {
        return this->body;
    }

    /**
     * Returns the correlation id used to correlate request/reply messages.
     */
    public function getCorrelationId() -> string | null
    {
        return this->getHeader("correlation_id");
    }

    /**
     * Returns a single header value, or the default when it is not set.
     */
    public function getHeader(string name, var defaultValue = null) -> var
    {
        if array_key_exists(name, this->headers) {
            return this->headers[name];
        }

        return defaultValue;
    }

    /**
     * Returns all transport headers.
     */
    public function getHeaders() -> array
    {
        return this->headers;
    }

    /**
     * Returns the message id.
     */
    public function getMessageId() -> string | null
    {
        return this->getHeader("message_id");
    }

    /**
     * Returns all application properties.
     */
    public function getProperties() -> array
    {
        return this->properties;
    }

    /**
     * Returns a single property value, or the default when it is not set.
     */
    public function getProperty(string name, var defaultValue = null) -> var
    {
        if array_key_exists(name, this->properties) {
            return this->properties[name];
        }

        return defaultValue;
    }

    /**
     * Returns the reply-to destination name.
     */
    public function getReplyTo() -> string | null
    {
        return this->getHeader("reply_to");
    }

    /**
     * Returns the timestamp (in milliseconds) or null when it is not set.
     */
    public function getTimestamp() -> int | null
    {
        var value;

        let value = this->getHeader("timestamp");

        if value === null {
            return null;
        }

        return (int) value;
    }

    /**
     * Whether the message has been redelivered.
     */
    public function isRedelivered() -> bool
    {
        return this->redelivered;
    }

    /**
     * Sets the message body.
     */
    public function setBody(string body) -> void
    {
        let this->body = body;
    }

    /**
     * Sets the correlation id.
     */
    public function setCorrelationId(string correlationId) -> void
    {
        this->setHeader("correlation_id", correlationId);
    }

    /**
     * Sets a single transport header.
     */
    public function setHeader(string name, var value) -> void
    {
        let this->headers[name] = value;
    }

    /**
     * Replaces all transport headers.
     */
    public function setHeaders(array headers) -> void
    {
        let this->headers = headers;
    }

    /**
     * Sets the message id.
     */
    public function setMessageId(string messageId) -> void
    {
        this->setHeader("message_id", messageId);
    }

    /**
     * Replaces all application properties.
     */
    public function setProperties(array properties) -> void
    {
        let this->properties = properties;
    }

    /**
     * Sets a single application property.
     */
    public function setProperty(string name, var value) -> void
    {
        let this->properties[name] = value;
    }

    /**
     * Marks the message as redelivered.
     */
    public function setRedelivered(bool redelivered) -> void
    {
        let this->redelivered = redelivered;
    }

    /**
     * Sets the reply-to destination name.
     */
    public function setReplyTo(string replyTo) -> void
    {
        this->setHeader("reply_to", replyTo);
    }

    /**
     * Sets the timestamp (in milliseconds).
     */
    public function setTimestamp(int timestamp) -> void
    {
        this->setHeader("timestamp", timestamp);
    }
}
