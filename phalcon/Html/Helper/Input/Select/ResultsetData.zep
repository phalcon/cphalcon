
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html\Helper\Input\Select;

use InvalidArgumentException;
use Phalcon\Contracts\Html\Helper\Input\SelectData;
use Phalcon\Html\Exceptions\InvalidResultsetValue;
use Phalcon\Html\Exceptions\UsingRequiresTwoValues;
use Phalcon\Mvc\Model\ResultsetInterface;

class ResultsetData implements SelectData
{
    /**
     * @var array
     */
    protected attributesMap = [];

    /**
     * @var array|null
     */
    protected resolvedAttributes = null;

    /**
     * @var array|null
     */
    protected resolvedOptions = null;

    /**
     * @var ResultsetInterface
     */
    protected resultset;

    /**
     * @var array
     */
    protected using = [];

    /**
     * @param ResultsetInterface resultset
     * @param array              using
     * @param array              attributesMap
     */
    public function __construct(
        <ResultsetInterface> resultset,
        array using,
        array attributesMap = []
    ) {
        if unlikely count(using) !== 2 {
            throw new UsingRequiresTwoValues();
        }

        let this->resultset     = resultset;
        let this->using         = using;
        let this->attributesMap = attributesMap;
    }

    /**
     * @return array
     */
    public function getAttributes() -> array
    {
        if null === this->resolvedAttributes {
            this->resolve();
        }

        return this->resolvedAttributes;
    }

    /**
     * @return array
     */
    public function getOptions() -> array
    {
        if null === this->resolvedOptions {
            this->resolve();
        }

        return this->resolvedOptions;
    }

    /**
     * Reads a property from the row, supporting both objects (via
     * `readAttribute` when present) and plain arrays.
     */
    protected function readField(var option, string field)
    {
        if typeof option == "object" {
            if method_exists(option, "readAttribute") {
                return option->readAttribute(field);
            }

            return option->{field};
        }

        return option[field];
    }

    /**
     * Walks the resultset once, building both the option map and the
     * per-option resolved attribute map. Closures in `attributesMap`
     * receive the current row; string values are passed through.
     */
    protected function resolve() -> void
    {
        var attrName, attrSpec, attrValue, attrs, option, optionAttrs,
            optionText, optionValue, options, usingZero, usingOne;

        let usingZero   = this->using[0],
            usingOne    = this->using[1],
            options     = [],
            attrs       = [];

        for option in this->resultset {
            if typeof option != "object" && typeof option != "array" {
                throw new InvalidResultsetValue();
            }

            let optionValue = this->readField(option, usingZero),
                optionText  = this->readField(option, usingOne);

            let options[optionValue] = optionText;

            if !empty(this->attributesMap) {
                let optionAttrs = [];

                for attrName, attrSpec in this->attributesMap {
                    if is_callable(attrSpec) {
                        let attrValue = call_user_func(attrSpec, option);
                    } else {
                        let attrValue = attrSpec;
                    }

                    if false !== attrValue && null !== attrValue {
                        let optionAttrs[attrName] = (string) attrValue;
                    }
                }

                if !empty(optionAttrs) {
                    let attrs[optionValue] = optionAttrs;
                }
            }
        }

        let this->resolvedOptions    = options,
            this->resolvedAttributes = attrs;
    }
}
