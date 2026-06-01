
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use ArrayAccess;
use Phalcon\Translate\Exceptions\ImmutableObject;
use Phalcon\Translate\InterpolatorFactory;

/**
 * @psalm-type TOptions array{
 *     defaultInterpolator?: string
 * }
 *
 * @template TKey of string
 * @template TValue of string
 * @implements ArrayAccess<TKey, TValue>
 */
abstract class AbstractAdapter implements AdapterInterface, ArrayAccess
{
    /**
     * @var string
     */
    protected defaultInterpolator = "";

    /**
    * @var InterpolatorFactory
    */
    protected interpolatorFactory;

    /**
     * AbstractAdapter constructor.
     *
     * @param TOptions            $options
     */
    public function __construct(
        <InterpolatorFactory> interpolator,
        array options = []
    ) {
        var value;

        if !fetch value, options["defaultInterpolator"] {
            let value = "associativeArray";
        }
        let this->defaultInterpolator = value,
            this->interpolatorFactory = interpolator;
    }

    /**
     * Returns the translation string of the given key (alias of method 't')
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     */
    public function _(string! translateKey, array placeholders = []) -> string
    {
        return this->query(translateKey, placeholders);
    }

    /**
     * Check whether a translation key exists
     *
     * @param mixed $translateKey
     *
     * @return bool
     */
    public function offsetExists(var translateKey) -> bool
    {
        return this->has(translateKey);
    }

    /**
     * Returns the translation related to the given key
     *
     * @param TKey $translateKey
     *
     * @return TValue|null
     */
    public function offsetGet(mixed translateKey) -> string | null
    {
        return this->query(translateKey);
    }

    /**
     * Sets a translation value
     *
     * @param mixed $offset
     * @param mixed $value
     *
     * @return void
     * @throws ImmutableObject
     */
    public function offsetSet(var offset, var value) -> void
    {
        throw new ImmutableObject();
    }

    /**
     * Unsets a translation from the dictionary
     *
     * @param mixed $offset
     *
     * @return void
     * @throws ImmutableObject
     */
    public function offsetUnset(var offset) -> void
    {
        throw new ImmutableObject();
    }

    /**
     * Returns the translation string of the given key
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     */
    public function t(string! translateKey, array placeholders = []) -> string
    {
        return this->query(translateKey, placeholders);
    }

    /**
     * Replaces placeholders by the values passed
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     */
    protected function replacePlaceholders(
        string! translation,
        array placeholders = []
    ) -> string {
        var interpolator;

        let interpolator = this->interpolatorFactory->newInstance(this->defaultInterpolator);

        return interpolator->replacePlaceholders(
            translation,
            placeholders
        );
    }
}
