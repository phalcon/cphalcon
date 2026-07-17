
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Exceptions;

use Phalcon\Auth\Exception;

/**
 * Config requires non-empty value
 */
class ConfigRequiresNonEmptyValue extends Exception
{
    public function __construct(
        string configName,
        string configKey,
        string suffix = ""
    ) {
        parent::__construct(
            configName . " requires a non-empty '"
            . configKey . "'" . suffix
        );
    }

    /**
     * Throws when the value is an empty string. A null value is treated as
     * "not provided" and passes, so optional settings can reuse the same
     * guard; callers that require presence reject null earlier. Keeps the
     * empty-value check shared by every config class in one place.
     *
     * @throws self
     */
    public static function assert(
        var value,
        string configName,
        string configKey,
        string suffix = ""
    ) -> void {
        if (value === "") {
            throw new self(configName, configKey, suffix);
        }
    }
}
