
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

namespace Phalcon\ADR\Input;

use Phalcon\Contracts\ADR\ADRTypes;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request\Bag\AttributeBag;

/**
 * Generic, string-keyed input bag for an Action.
 *
 * `fromRequest()` merges the request query, parsed body and route attributes
 * into a single bag (later sources win). Extend it to build a typed, per-domain
 * input value object: the factories use late static binding, so a subclass's
 * `fromRequest()` / `fromArray()` return that subclass.
 *
 * @phpstan-import-type adr_input_data from ADRTypes
 */
class Input
{
    /**
     * @phpstan-var adr_input_data
     */
    protected array data = [];

    /**
     * @phpstan-param adr_input_data $data
     */
    public function __construct(array data = [])
    {
        let this->data = data;
    }

    /**
     * @phpstan-param adr_input_data $data
     */
    public static function fromArray(array data) -> <static>
    {
        return new static(data);
    }

    public static function fromRequest(<AttributeRequest> request) -> <static>
    {
        var json, decoded;

        let json = [];

        /**
         * Only a request that says it carries JSON is decoded as JSON. A form
         * post is not, and decoding its body raises a decode error.
         */
        if str_contains((string) request->getContentType(), "json") {
            let decoded = request->getJsonRawBody(true);

            if typeof decoded === "array" {
                let json = decoded;
            }
        }

        return new static(
            array_merge(
                request->getQuery(),
                request->getPost(),
                json,
                request->getAttributes()->all()
            )
        );
    }

    public function get(string key, var defaultValue = null) -> var
    {
        return isset this->data[key] ? this->data[key] : defaultValue;
    }

    public function has(string key) -> bool
    {
        return isset this->data[key];
    }

    /**
     * @phpstan-return adr_input_data
     */
    public function toArray() -> array
    {
        return this->data;
    }
}
