
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

use Phalcon\Contracts\Http\AttributeRequestInterface;
use Phalcon\Http\Request\Bag\AttributeBag;

/**
 * Generic, string-keyed input bag for an Action.
 *
 * Ships as a convenience; applications typically write their own typed input
 * value objects. `fromRequest()` merges the request query, parsed body and
 * route attributes into a single bag (later sources win).
 */
class Input
{
    /**
     * @var array
     */
    protected data = [];

    public function __construct(array data = [])
    {
        let this->data = data;
    }

    public static function fromArray(array data) -> <Input>
    {
        return new self(data);
    }

    public static function fromRequest(<AttributeRequestInterface> request) -> <Input>
    {
        var json;

        let json = request->getJsonRawBody(true);
        if typeof json !== "array" {
            let json = [];
        }

        return new self(
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

    public function toArray() -> array
    {
        return this->data;
    }
}
