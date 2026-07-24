
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

namespace Phalcon\ADR\Router;

use Phalcon\ADR\Exceptions\RouteNotFound;
use Phalcon\Contracts\ADR\Router\AttributeFilter as AttributeFilterInterface;

/**
 * Reads an Action's optional static `params()` declaration and transforms the
 * router's positional tail segments: regex match (miss => RouteNotFound), cast
 * to a scalar type, then an optional converter closure. Declaration order names
 * the attributes; a declared parameter with no segment is skipped; surplus
 * segments pass through under their positional keys. An Action without
 * `params()` is returned unchanged.
 */
final class AttributeFilter implements AttributeFilterInterface
{
    public function filter(string actionClass, array attributes) -> array
    {
        var convert, index, item, key, name, params, pattern, result, 
            rule, segment, type, value;

        if !method_exists(actionClass, "params") {
            return attributes;
        }

        let params = call_user_func([actionClass, "params"]);
        if typeof params !== "array" {
            return attributes;
        }

        let result = [],
            index  = 0;

        for name, rule in params {
            if isset attributes[index] {
                let segment = attributes[index];

                if isset rule["match"] {
                    let pattern = rule["match"];

                    if !preg_match("#^(?:" . pattern . ")$#", segment) {
                        throw new RouteNotFound();
                    }
                }

                let type  = isset rule["type"] ? rule["type"] : "string",
                    value = this->cast(segment, type);

                if isset rule["convert"] {
                    let convert = rule["convert"],
                        value   = call_user_func(convert, value);
                }

                let result[name] = value;
            }

            let index++;
        }

        for key, item in attributes {
            if key >= index {
                let result[key] = item;
            }
        }

        return result;
    }

    protected function cast(string value, string type)
    {
        switch type {
            case "int":
                return intval(value);
            case "float":
                return floatval(value);
            default:
                return strval(value);
        }
    }
}
