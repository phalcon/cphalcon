
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

namespace Phalcon\Auth\Internal;

use Phalcon\Auth\Exception;
use Phalcon\Auth\Exceptions\OptionRequiresArray;
use Phalcon\Auth\Exceptions\OptionRequiresString;
use Phalcon\Contracts\Auth\AuthTypes;

/**
 * Internal option-parsing helpers shared by adapter / guard fromOptions()
 * implementations. Not part of the public API.
 *
 * @phpstan-import-type auth_user_row from AuthTypes
 */
final class Options
{
    /**
     * @phpstan-param array<string, mixed> $options
     * @phpstan-param list<auth_user_row>  $defaultValue
     *
     * @phpstan-return list<auth_user_row>
     */
    public static function arrayOption(array options, string key, array defaultValue) -> array
    {
        var value;

        let value = isset(options[key]) ? options[key] : defaultValue;

        if (!is_array(value)) {
            return defaultValue;
        }

        /** @var list<auth_user_row> */
        return array_values(value);
    }

    /**
     * @phpstan-param array<string, mixed> $options
     *
     * @phpstan-return array<string, mixed>
     * @throws Exception
     */
    public static function requireArray(array options, string key, string context) -> array
    {
        var value;

        fetch value, options[key];

        if (typeof value !== "array" || empty(value)) {
            throw new OptionRequiresArray(context, key);
        }

        return value;
    }

    /**
     * @phpstan-param array<string, mixed> $options
     *
     * @throws Exception
     */
    public static function requireString(array options, string key, string context) -> string
    {
        var value;

        fetch value, options[key];

        if (typeof value !== "string" || value === "") {
            throw new OptionRequiresString(context, key);
        }

        return value;
    }

    /**
     * @param array<string, mixed> $options
     */
    public static function stringOrNull(array options, string key) -> string | null
    {
        var value;

        fetch value, options[key];

        return typeof value === "string" ? value : null;
    }
}
