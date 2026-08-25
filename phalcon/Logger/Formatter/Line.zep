
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Exception;
use Phalcon\Logger\Item;

/**
 * Class Line
 */
class Line extends AbstractFormatter
{
    /**
     * Format applied to each message
     */
    protected string format;

    /**
     * Line constructor.
     *
     * @param string $format
     * @param string $dateFormat
     * @param string $interpolatorLeft
     * @param string $interpolatorRight
     */
    public function __construct(
        string format = "[%date%][%level%] %message%",
        string dateFormat = "c",
        string interpolatorLeft = "%",
        string interpolatorRight = "%"
    ) {
        let this->format            = format;
        let this->dateFormat        = dateFormat;
        let this->interpolatorLeft  = interpolatorLeft;
        let this->interpolatorRight = interpolatorRight;
    }

    /**
     * Applies a format to a message before sent it to the internal log
     *
     * @throws Exception
     */
    public function format(<Item> item) -> string
    {
        var message;

        let message = strtr(
            this->format,
            [
                this->interpolatorLeft . "date"    . this->interpolatorRight : this->getFormattedDate(item),
                this->interpolatorLeft . "level"   . this->interpolatorRight : item->getLevelName(),
                this->interpolatorLeft . "message" . this->interpolatorRight : item->getMessage()
            ]
        );

        let message = this->getInterpolatedMessage(item, message);

        /**
         * Escape C0 control characters (except tab) and DEL so an untrusted
         * message or context value carrying CR/LF cannot forge extra log lines
         * (CWE-117) or inject terminal control sequences. The record separator
         * the adapter appends is added after formatting, so it is not touched.
         */
        return preg_replace_callback(
            "/[\\x00-\\x08\\x0A-\\x1F\\x7F]/",
            function(matches) {
                return sprintf("\\x%02X", ord(matches[0]));
            },
            message
        );
    }

    /**
     * Return the format applied to each message
     */
    public function getFormat() -> string
    {
        return this->format;
    }

    /**
     * Set the format applied to each message
     */
    public function setFormat(string format) -> <static>
    {
        let this->format = format;

        return this;
    }
}
