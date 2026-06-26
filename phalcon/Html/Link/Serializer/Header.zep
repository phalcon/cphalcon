
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Link\Serializer;

/**
 * Class Phalcon\Http\Link\Serializer\Header
 */
class Header implements SerializerInterface
{
    /**
     * Serializes all the passed links to a HTTP link header
     */
    public function serialize(array links) -> string | null
    {
        var attributes, key, link, rels, result = null, subValue, value;
        array elements, parts;

        let elements = [];
        for link in links {
            /**
             * Leave templated links alone
             */
            if true === link->isTemplated() {
                continue;
            }

            /**
             * Split the parts of the attributes so that we can parse them
             */
            let attributes = link->getAttributes(),
                rels       = link->getRels(),
                parts      = [
                    "",
                    "rel=\"" . implode(" ", rels) . "\""
                ];

            for key, value in attributes {
                if typeof value === "array" {
                    for subValue in value {
                        let parts[] = key . "=\"" . this->quote((string) subValue) . "\"";
                    }
                    continue;
                }

                if typeof value !== "boolean" {
                    let parts[] = key . "=\"" . this->quote((string) value) . "\"";
                    continue;
                }

                if true === value {
                    let parts[] = key;
                    continue;
                }
            }

            let elements[] = "<"
                           . link->getHref()
                           . ">"
                           . implode("; ", parts);
        }

        if count(elements) > 0 {
            let result = implode(",", elements);
        }

        return result;
    }

    /**
     * Escapes a quoted-string attribute value per RFC 8288 section 3: a
     * backslash and a double quote are each prefixed with a backslash so the
     * value cannot terminate or corrupt the header field.
     *
     * @param string $value
     *
     * @return string
     */
    private function quote(string value) -> string
    {
        return str_replace(["\\", "\""], ["\\\\", "\\\""], value);
    }
}
