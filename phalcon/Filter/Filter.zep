
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Contracts\Filter\FilterTypes;
use Phalcon\Contracts\Filter\Sanitizer;
use Phalcon\Filter\Exceptions\FilterNotRegistered;
use Phalcon\Filter\Sanitize\AbsInt;
use Phalcon\Filter\Sanitize\Alnum;
use Phalcon\Filter\Sanitize\Alpha;
use Phalcon\Filter\Sanitize\BoolVal;
use Phalcon\Filter\Sanitize\Email;
use Phalcon\Filter\Sanitize\FloatVal;
use Phalcon\Filter\Sanitize\IntVal;
use Phalcon\Filter\Sanitize\Ip;
use Phalcon\Filter\Sanitize\Lower;
use Phalcon\Filter\Sanitize\LowerFirst;
use Phalcon\Filter\Sanitize\Regex;
use Phalcon\Filter\Sanitize\Remove;
use Phalcon\Filter\Sanitize\Replace;
use Phalcon\Filter\Sanitize\Special;
use Phalcon\Filter\Sanitize\SpecialFull;
use Phalcon\Filter\Sanitize\StringVal;
use Phalcon\Filter\Sanitize\StringValLegacy;
use Phalcon\Filter\Sanitize\Striptags;
use Phalcon\Filter\Sanitize\Trim;
use Phalcon\Filter\Sanitize\Upper;
use Phalcon\Filter\Sanitize\UpperFirst;
use Phalcon\Filter\Sanitize\UpperWords;
use Phalcon\Filter\Sanitize\Url;

/**
 * Lazy loads, stores and exposes sanitizer objects
 *
 * @method int          absint(mixed $input)
 * @method string       alnum(mixed $input)
 * @method string       alpha(mixed $input)
 * @method bool         bool(mixed $input)
 * @method string       email(string $input)
 * @method float        float(mixed $input)
 * @method int          int(string $input)
 * @method false|string ip(string $input, int $filter = 0)
 * @method string       lower(string $input)
 * @method string       lowerfirst(string $input)
 * @method mixed        regex(mixed $input, mixed $pattern, mixed $replace)
 * @method mixed        remove(mixed $input, mixed $replace)
 * @method mixed        replace(mixed $input, mixed $from, mixed $to)
 * @method string       special(string $input)
 * @method string       specialfull(string $input)
 * @method string       string(string $input)
 * @method string       stringlegacy(mixed $input)
 * @method string       striptags(string $input)
 * @method string       trim(string $input)
 * @method string       upper(string $input)
 * @method string       upperFirst(string $input)
 * @method string|null  upperWords(string $input)
 * @method string|null  url(string $input)
 *
 * @property array $mapper
 * @property array $services
 *
 * @phpstan-import-type filter_mapper from FilterTypes
 * @phpstan-import-type filter_sanitizer_params from FilterTypes
 * @phpstan-import-type filter_sanitizer_split from FilterTypes
 * @phpstan-import-type filter_sanitizers from FilterTypes
 * @phpstan-import-type filter_services from FilterTypes
 * @phpstan-import-type filter_values from FilterTypes
 */
class Filter implements FilterInterface
{
    /**
     * @var string
     */
    const FILTER_ABSINT        = "absint";
    /**
     * @var string
     */
    const FILTER_ALNUM         = "alnum";
    /**
     * @var string
     */
    const FILTER_ALPHA         = "alpha";
    /**
     * @var string
     */
    const FILTER_BOOL          = "bool";
    /**
     * @var string
     */
    const FILTER_EMAIL         = "email";
    /**
     * @var string
     */
    const FILTER_FLOAT         = "float";
    /**
     * @var string
     */
    const FILTER_INT           = "int";
    /**
     * @var string
     */
    const FILTER_IP            = "ip";
    /**
     * @var string
     */
    const FILTER_LOWER         = "lower";
    /**
     * @var string
     */
    const FILTER_LOWERFIRST    = "lowerfirst";
    /**
     * @var string
     */
    const FILTER_REGEX         = "regex";
    /**
     * @var string
     */
    const FILTER_REMOVE        = "remove";
    /**
     * @var string
     */
    const FILTER_REPLACE       = "replace";
    /**
     * @var string
     */
    const FILTER_SPECIAL       = "special";
    /**
     * @var string
     */
    const FILTER_SPECIALFULL   = "specialfull";
    /**
     * @var string
     */
    const FILTER_STRING        = "string";
    /**
     * @var string
     */
    const FILTER_STRING_LEGACY = "stringlegacy";
    /**
     * @var string
     */
    const FILTER_STRIPTAGS     = "striptags";
    /**
     * @var string
     */
    const FILTER_TRIM          = "trim";
    /**
     * @var string
     */
    const FILTER_UPPER         = "upper";
    /**
     * @var string
     */
    const FILTER_UPPERFIRST    = "upperfirst";
    /**
     * @var string
     */
    const FILTER_UPPERWORDS    = "upperwords";
    /**
     * @var string
     */
    const FILTER_URL           = "url";

    /**
     * @phpstan-var filter_mapper
     */
    protected array mapper = [];

    /**
     * @phpstan-var filter_services
     */
    protected array services = [];

    /**
     * Filter constructor.
     *
     * @phpstan-param filter_mapper $mapper
     */
    public function __construct(array mapper = [])
    {
        this->init(mapper);
    }

    /**
     * Magic call to make the helper objects available as methods.
     *
     * @param string               $name
     * @param array<string, mixed> $args
     *
     * @return mixed
     * @throws Exception
     */
    public function __call(string name, array args)
    {
        var sanitizer;

        let sanitizer = this->get(name);

        return call_user_func_array([sanitizer, "__invoke"], args);
    }

    /**
     * Returns the default sanitizer name to class map. This is the single
     * source for the built-in sanitizer registry: when adding a sanitizer,
     * add its `FILTER_*` constant and its entry here.
     *
     * @return string[]
     *
     * @phpstan-return filter_mapper
     */
    public static function getDefaultMapper() -> array
    {
        return [
            self::FILTER_ABSINT        : AbsInt::class,
            self::FILTER_ALNUM         : Alnum::class,
            self::FILTER_ALPHA         : Alpha::class,
            self::FILTER_BOOL          : BoolVal::class,
            self::FILTER_EMAIL         : Email::class,
            self::FILTER_FLOAT         : FloatVal::class,
            self::FILTER_INT           : IntVal::class,
            self::FILTER_IP            : Ip::class,
            self::FILTER_LOWER         : Lower::class,
            self::FILTER_LOWERFIRST    : LowerFirst::class,
            self::FILTER_REGEX         : Regex::class,
            self::FILTER_REMOVE        : Remove::class,
            self::FILTER_REPLACE       : Replace::class,
            self::FILTER_SPECIAL       : Special::class,
            self::FILTER_SPECIALFULL   : SpecialFull::class,
            self::FILTER_STRING        : StringVal::class,
            self::FILTER_STRING_LEGACY : StringValLegacy::class,
            self::FILTER_STRIPTAGS     : Striptags::class,
            self::FILTER_TRIM          : Trim::class,
            self::FILTER_UPPER         : Upper::class,
            self::FILTER_UPPERFIRST    : UpperFirst::class,
            self::FILTER_UPPERWORDS    : UpperWords::class,
            self::FILTER_URL           : Url::class
        ];
    }

    /**
     * Get a service. If it is not in the mapper array, create a new object,
     * set it and then return it.
     *
     * @param string $name
     *
     * @return mixed
     *
     * @phpstan-return Sanitizer
     *
     * @throws Exception
     */
    public function get(string name) -> var
    {
        var definition;

        if (true !== isset(this->mapper[name])) {
            throw new FilterNotRegistered(name);
        }

        if (true !== isset(this->services[name])) {
            let definition           = this->mapper[name],
                this->services[name] = this->createInstance(definition);
        }

        return this->services[name];
    }

    /**
     * Checks if a service exists in the map array
     *
     * @param string $name
     *
     * @return bool
     */
    public function has(string name) -> bool
    {
        return isset(this->mapper[name]);
    }

    /**
     * Sanitizes a value with a specified single or set of sanitizers
     *
     * Array policy: when `$value` is an array and `$noRecursive` is `false`
     * (the default), each element is passed to the sanitizer individually
     * and an array is returned - recursion is one level deep only. Elements
     * that are themselves arrays are passed to the sanitizer as-is, which
     * raises a `TypeError` for sanitizers that type their value parameter
     * (e.g. `trim`). When `$noRecursive` is `true`, the whole array is
     * passed to the sanitizer as a single value.
     *
     * @phpstan-param filter_sanitizers|string $sanitizers
     *
     * @return array|false|mixed|null
     * @throws Exception
     */
    public function sanitize(var value, var sanitizers, bool noRecursive = false) -> var
    {
        /**
         * First we need to figure out whether this is one sanitizer (string) or
         * an array with different sanitizers in it.
         *
         * All is well if the sanitizer accepts only one parameter, but certain
         * sanitizers require more than one parameter. To figure this out we
         * need to of course call call_user_func_array() but with the correct
         * parameters.
         *
         * If the array is passed with just values then those are just the
         * sanitizer names i.e.
         *
         * $locator->sanitize( 'abcde', ['trim', 'upper'])
         *
         * If the sanitizer requires more than one parameter then we need to
         * inject those parameters in the sanitize also:
         *
         * $locator->sanitize(
         *     '  mary had a little lamb ',
         *     [
         *         'trim',
         *         'replace' => [' ', '-'],
         *         'remove'  => ['mary'],
         *     ]
         * );
         *
         * The above should produce "-had-a-little-lamb"
         */

        /**
         * Filter is an array
         */
        if typeof sanitizers === "array" {
            return this->processArraySanitizers(sanitizers, value, noRecursive);
        }

        /**
         * Apply a single sanitizer to the values. Check if the values are an
         * array
         */
        if typeof value === "array" && !noRecursive {
            return this->processArrayValues(value, sanitizers);
        }

        /**
         * One value one sanitizer
         */
        return this->sanitizer(value, sanitizers);
    }

    /**
     * Set a new service to the mapper array
     *
     * @phpstan-param class-string<Sanitizer>|Sanitizer $service
     */
    public function set(string name, var service) -> void
    {
        let this->mapper[name] = service;

        unset this->services[name];
    }

    /**
     * Loads the objects in the internal mapper array
     *
     * @phpstan-param filter_mapper $mapper
     */
    protected function init(array mapper) -> void
    {
        var name, service;

        for name, service in mapper {
            this->set(name, service);
        }
    }

    /**
     * @phpstan-param class-string<Sanitizer>|Sanitizer $definition
     *
     * @phpstan-return Sanitizer
     */
    private function createInstance(var definition)
    {
        var instance;

        let instance = definition;
        if typeof instance === "string" {
            return create_instance(instance);
        }

        return instance;
    }

    /**
     * @phpstan-param filter_sanitizers $sanitizers
     *
     * @return array|false|mixed|null
     * @throws Exception
     */
    private function processArraySanitizers(
        array sanitizers,
        var value,
        bool noRecursive
    ) {
        var sanitizer, sanitizerKey, sanitizerName, sanitizerParams, split;

        /**
         * Null value - return immediately
         */
        if null === value {
            return value;
        }

        /**
         * `value` is something. Loop through the sanitizers
         */
        for sanitizerKey, sanitizer in sanitizers {
            /**
             * If `sanitizer` is an array, that means that the sanitizerKey
             * is the name of the sanitizer.
             */
            let split           = this->splitSanitizerParameters(sanitizerKey, sanitizer),
                sanitizerName   = split[0],
                sanitizerParams = split[1];

            /**
             * Check if the value is an array of elements. If `noRecursive`
             * has been defined it is a straight up; otherwise recursion is
             * required
             */
             if typeof value === "array" {
                let value = this->processValueIsArray(
                    value,
                    sanitizerName,
                    sanitizerParams,
                    noRecursive
                );
             } else {
                 let value = this->processValueIsNotArray(
                     value,
                     sanitizerName,
                     sanitizerParams
                 );
             }
        }

        return value;
    }

    /**
     * Processes the array values with the relevant sanitizers
     *
     * @phpstan-param filter_values           $values
     * @phpstan-param filter_sanitizer_params $sanitizerParams
     *
     * @phpstan-return filter_values
     * @throws Exception
     */
    private function processArrayValues(
        array values,
        string sanitizerName,
        array sanitizerParams = []
    ) -> array {
        var itemKey, itemValue;
        array arrayValues = [];

        for itemKey, itemValue in values {
            let arrayValues[itemKey] = this->sanitizer(
                itemValue,
                sanitizerName,
                sanitizerParams
            );
        }

        return arrayValues;
    }

    /**
     * @phpstan-param filter_values             $value
     * @phpstan-param filter_sanitizer_params   $sanitizerParams
     *
     * @return array|mixed
     * @throws Exception
     */
    private function processValueIsArray(
        var value,
        string sanitizerName,
        array sanitizerParams,
        bool noRecursive
    ) {
        if noRecursive {
            let value = this->sanitizer(
                value,
                sanitizerName,
                sanitizerParams
            );
        } else {
            let value = this->processArrayValues(
                value,
                sanitizerName,
                sanitizerParams
            );
        }

        return value;
    }

    /**
     * @phpstan-param filter_sanitizer_params $sanitizerParams
     *
     * @return array|false|mixed
     * @throws Exception
     */
    private function processValueIsNotArray(
        var value,
        string sanitizerName,
        array sanitizerParams
    ) {
        if typeof value !== "array" {
            let value = this->sanitizer(
                value,
                sanitizerName,
                sanitizerParams
            );
        }

        return value;
    }

    /**
     * Internal sanitize wrapper for recursion
     *
     * @phpstan-param filter_sanitizer_params $sanitizerParams
     *
     * @return false|mixed
     * @throws Exception
     */
    private function sanitizer(
        var value,
        string sanitizerName,
        array sanitizerParams = []
    ) {
        var params, sanitizerObject;

        if true !== this->has(sanitizerName) {
            if true !== empty(sanitizerName) {
                trigger_error(
                    "Sanitizer '" . sanitizerName . "' is not registered",
                    E_USER_NOTICE
                );
            }

            return value;
        }

        let sanitizerObject = this->get(sanitizerName),
            params          = array_merge([value], sanitizerParams);

        return call_user_func_array([sanitizerObject, "__invoke"], params);
    }

    /**
     * @param mixed $sanitizerKey
     * @param mixed $sanitizer
     *
     * @phpstan-return filter_sanitizer_split
     */
    private function splitSanitizerParameters(var sanitizerKey, var sanitizer) -> array
    {
        /**
         * If `sanitizer` is an array, that means that the sanitizerKey
         * is the name of the sanitizer.
         */
        if typeof sanitizer === "array" {
            return [sanitizerKey, sanitizer];
        }

        return [sanitizer, []];
    }
}
