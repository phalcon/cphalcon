
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by lcobucci/clock
 *
 * @link    https://github.com/lcobucci/clock
 * @license https://github.com/lcobucci/clock/blob/3.7.x/LICENSE
 */

namespace Phalcon\Time\Clock;

use DateTimeImmutable;
use DateTimeZone;
use Phalcon\Time\Clock\Exceptions\InvalidModifier;
use Throwable;

final class FrozenClock implements ClockInterface
{
    /**
     * @var DateTimeImmutable
     */
    private now;

    public function __construct(<DateTimeImmutable> now)
    {
        let this->now = now;
    }

    /**
     * Mutates the clock to a new value. All consumers receive the same modification
     *
     * @throws InvalidModifier
     */
    public function adjust(string modifier) -> <static>
    {
        var ex, modified;
        bool failed;

        let failed = false;

        if version_compare(phpversion(), "8.3", ">=") {
            try {
                let modified = this->now->modify(modifier);
            } catch Throwable, ex {
                throw new InvalidModifier(modifier, ex);
            }
        } else {
            globals_set("warning.enable", false);
            set_error_handler(
                function (number, message, file, line) {
                    globals_set("warning.enable", true);
                },
                E_WARNING
            );

            let modified = this->now->modify(modifier);

            restore_error_handler();

            let failed = (bool) globals_get("warning.enable");
        }

        if unlikely failed || false === modified {
            throw new InvalidModifier(modifier);
        }

        let this->now = modified;

        return this;
    }

    /**
     * Return a new object of now with the current timezone
     */
    public static function fromSystemTimezone() -> <FrozenClock>
    {
        return new FrozenClock(
            new DateTimeImmutable(
                "now",
                new DateTimeZone(date_default_timezone_get())
            )
        );
    }

    /**
     * Return a new object of now with UTC
     */
    public static function fromUTC() -> <FrozenClock>
    {
        return new FrozenClock(
            new DateTimeImmutable("now", new DateTimeZone("UTC"))
        );
    }

    /**
     * Return the current clock
     */
    public function now() -> <DateTimeImmutable>
    {
        return this->now;
    }

    /**
     * Sets the clock to a new value. All consumers receive the same modification
     */
    public function set(<DateTimeImmutable> now) -> <static>
    {
        let this->now = now;

        return this;
    }
}
