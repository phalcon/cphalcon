
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use DateTimeImmutable;
use Phalcon\Contracts\Logger\LoggerTypes;
use Phalcon\Logger\Item;
use Phalcon\Traits\Support\Helper\Str\InterpolateTrait;
use Stringable;

/**
 * Class AbstractFormatter
 *
 * @phpstan-import-type logger_context from LoggerTypes
 */
abstract class AbstractFormatter implements FormatterInterface
{
    use InterpolateTrait;

    /**
     * Default date format
     */
    protected string dateFormat = "c";
    protected string interpolatorLeft = "%";
    protected string interpolatorRight = "%";

    public function getDateFormat() -> string
    {
        return this->dateFormat;
    }

    public function setDateFormat(string format) -> void
    {
        let this->dateFormat = format;
    }

    /**
     * Returns the date formatted for the logger.
     *
     * @param Item $item
     *
     * @return string
     */
    protected function getFormattedDate(<Item> item) -> string
    {
        return item->getDateTime()->format(this->dateFormat);
    }

    /**
     * Returns the interpolated message, replacing context placeholders.
     *
     * @param Item   $item
     * @param string $message
     *
     * @return string
     */
    protected function getInterpolatedMessage(
        <Item> item,
        string message
    ) -> string {
        return this->toInterpolate(
            message,
            this->stringifyContext(item->getContext()),
            this->interpolatorLeft,
            this->interpolatorRight
        );
    }

    /**
     * Reduces the log context to the string map interpolation requires.
     *
     * Log context is PSR-3 shaped, so its values are arbitrary, while
     * interpolation replaces a placeholder with a string. Anything that
     * cannot be expressed as one - an array, an object without
     * `__toString()` - substitutes as an empty string, so a placeholder is
     * never left dangling and a non-stringable value can never abort the
     * formatter mid-log.
     *
     * @phpstan-param logger_context $context
     *
     * @return array<string, string>
     */
    protected function stringifyContext(array context) -> array
    {
        var key, value;
        array result;

        let result = [];

        for key, value in context {
            if is_scalar(value) || (typeof value === "object" && value instanceof Stringable) {
                let result[key] = (string) value;
            } else {
                let result[key] = "";
            }
        }

        return result;
    }
}
