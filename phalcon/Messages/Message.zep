
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Messages;

use JsonSerializable;

/**
 * Phalcon\Messages\Message
 *
 * Stores a message from various components
 */
class Message implements MessageInterface, JsonSerializable
{
    /**
     * @var int
     */
    protected code { get };

    /**
     * @var string
     */
    protected field { get };

    /**
     * @var string
     */
    protected message { get };

    /**
     * @var string
     */
    protected type { get };

    /**
     * @var array
     */
    protected metaData = [] { get };

    /**
     * Phalcon\Messages\Message constructor
     */
    public function __construct(string! message, var field = "", string type = "", int code = 0, array metaData = [])
    {
        let this->message  = message,
            this->field    = field,
            this->type     = type,
            this->code     = code,
            this->metaData = metaData;
    }

    /**
     * Magic __toString method returns verbose message
     */
    public function __toString() -> string
    {
        return this->message;
    }

    /**
     * Serializes the object for json_encode
     */
    public function jsonSerialize() -> array
    {
        return [
            "field"    : this->field,
            "message"  : this->message,
            "type"     : this->type,
            "code"     : this->code,
            "metaData" : this->metaData
        ];
    }

    /**
     * Sets code for the message
     */
    public function setCode(int code) -> <MessageInterface>
    {
        let this->code = code;

        return this;
    }

    /**
     * Sets field name related to message
     */
    public function setField(var field) -> <MessageInterface>
    {
        let this->field = field;

        return this;
    }

    /**
     * Sets verbose message
     */
    public function setMessage(string! message) -> <MessageInterface>
    {
        let this->message = message;

        return this;
    }

    /**
     * Sets message metadata
     */
    public function setMetaData(array! metaData) -> <MessageInterface>
    {
        let this->metaData = metaData;

        return this;
    }

    /**
     * Sets message type
     */
    public function setType(string! type) -> <MessageInterface>
    {
        let this->type = type;

        return this;
    }
}
