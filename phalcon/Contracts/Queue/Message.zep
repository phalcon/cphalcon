
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Queue;

/**
 * A message exchanged through the transport. Carries a body, application
 * properties, transport headers and the standard messaging metadata.
 */
interface Message
{
    /**
     * Returns the message body.
     */
    public function getBody() -> string;

    /**
     * Returns the correlation id used to correlate request/reply messages.
     */
    public function getCorrelationId() -> string | null;

    /**
     * Returns a single header value, or the default when it is not set.
     */
    public function getHeader(string name, var defaultValue = null) -> var;

    /**
     * Returns all transport headers.
     */
    public function getHeaders() -> array;

    /**
     * Returns the message id.
     */
    public function getMessageId() -> string | null;

    /**
     * Returns all application properties.
     */
    public function getProperties() -> array;

    /**
     * Returns a single property value, or the default when it is not set.
     */
    public function getProperty(string name, var defaultValue = null) -> var;

    /**
     * Returns the reply-to destination name.
     */
    public function getReplyTo() -> string | null;

    /**
     * Returns the timestamp (in milliseconds) or null when it is not set.
     */
    public function getTimestamp() -> int | null;

    /**
     * Whether the message has been redelivered.
     */
    public function isRedelivered() -> bool;

    /**
     * Sets the message body.
     */
    public function setBody(string body) -> void;

    /**
     * Sets the correlation id.
     */
    public function setCorrelationId(string correlationId) -> void;

    /**
     * Sets a single transport header.
     */
    public function setHeader(string name, var value) -> void;

    /**
     * Replaces all transport headers.
     */
    public function setHeaders(array headers) -> void;

    /**
     * Sets the message id.
     */
    public function setMessageId(string messageId) -> void;

    /**
     * Replaces all application properties.
     */
    public function setProperties(array properties) -> void;

    /**
     * Sets a single application property.
     */
    public function setProperty(string name, var value) -> void;

    /**
     * Marks the message as redelivered.
     */
    public function setRedelivered(bool redelivered) -> void;

    /**
     * Sets the reply-to destination name.
     */
    public function setReplyTo(string replyTo) -> void;

    /**
     * Sets the timestamp (in milliseconds).
     */
    public function setTimestamp(int timestamp) -> void;
}
