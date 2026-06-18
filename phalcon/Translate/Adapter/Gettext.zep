
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Translate\Exception;
use Phalcon\Translate\Exceptions\MissingGettextExtension;
use Phalcon\Translate\Exceptions\MissingRequiredParameter;
use Phalcon\Translate\InterpolatorFactory;

/**
 * Phalcon\Translate\Adapter\Gettext
 *
 * ```php
 * use Phalcon\Translate\Adapter\Gettext;
 *
 * $adapter = new Gettext(
 *     [
 *         "locale"        => "de_DE.UTF-8",
 *         "defaultDomain" => "translations",
 *         "directory"     => "/path/to/application/locales",
 *         "category"      => LC_MESSAGES,
 *     ]
 * );
 * ```
 *
 * Allows translations using gettext
 *
 * @phpstan-type TOptions array{
 *      locale?: string,
 *      defaultDomain?: string,
 *      directory?: string,
 *      category?: string
 * }
 */
class Gettext extends AbstractAdapter
{
    /**
     * @var int
     */
    protected category;

    /**
     * @var string
     */
    protected defaultDomain;

    /**
     * @var string|array
     */
    protected directory;

    /**
     * @var string | false
     */
    protected locale;

    /**
     * Gettext constructor.
     *
     * @param InterpolatorFactory $interpolator
     * @param TOptions            $options
     *
     * @throws Exception
     * @throws MissingGettextExtension
     * @throws MissingRequiredParameter
     */
    public function __construct(<InterpolatorFactory> interpolator, array! options)
    {
        if unlikely !this->phpFunctionExists("gettext") {
            throw new MissingGettextExtension();
        }

        parent::__construct(interpolator, options);

        this->prepareOptions(options);
    }

    /**
     * Check whether is defined a translation key in the internal array
     *
     * @param string $index
     *
     * @return bool
     * @deprecated
     */
    public function exists(string! index) -> bool
    {
        return this->has(index);
    }

    /**
     * @return int
     */
    public function getCategory() -> int
    {
        return this->category;
    }

    /**
     * @return string
     */
    public function getDefaultDomain() -> string
    {
        return this->defaultDomain;
    }

    /**
     * @phpstan-return array<string, string>|string
     */
    public function getDirectory() -> array | string
    {
        return this->directory;
    }

    /**
     * @return string
     */
    public function getLocale() -> string | false
    {
        return this->locale;
    }

    /**
     * Check whether is defined a translation key in the internal array
     *
     * @param string $index
     *
     * @return bool
     */
    public function has(string! index) -> bool
    {
        return gettext(index) !== index;
    }

    /**
     * The plural version of gettext().
     * Some languages have more than one form for plural messages dependent on
     * the count.
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     */
    public function nquery(
        string! msgid1,
        string! msgid2,
        int! count,
        array placeholders = [],
        string! domain = null
    ) -> string {
        var translation;

        if !domain {
            let translation = ngettext(msgid1, msgid2, count);
        } else {
            let translation = dngettext(domain, msgid1, msgid2, count);
        }

        return this->replacePlaceholders(translation, placeholders);
    }

    /**
     * Returns the translation related to the given key.
     *
     * ```php
     * $translator->query("你好 %name%！", ["name" => "Phalcon"]);
     * ```
     *
     * @phpstan-param array<string, string> $placeholders
     *
     * @return string
     * @throws Exception
     */
    public function query(string! translateKey, array placeholders = []) -> string
    {
        var translation;

        let translation = gettext(translateKey);

        if translation === translateKey {
            let translation = this->notFound(translateKey);
        }

        return this->replacePlaceholders(translation, placeholders);
    }

    /**
     * Sets the default domain
     *
     * @return string
     */
    public function resetDomain() -> string
    {
        return textdomain(this->getDefaultDomain());
    }

    /**
     * Sets the domain default to search within when calls are made to gettext()
     *
     * @param string $domain
     */
    public function setDefaultDomain(string! domain) -> void
    {
        let this->defaultDomain = domain;
    }

    /**
     * Sets the path for a domain
     *
     * ```php
     * // Set the directory path
     * $gettext->setDirectory("/path/to/the/messages");
     *
     * // Set the domains and directories path
     * $gettext->setDirectory(
     *     [
     *         "messages" => "/path/to/the/messages",
     *         "another"  => "/path/to/the/another",
     *     ]
     * );
     * ```
     *
     * @param string|array $directory
     */
    public function setDirectory(var directory) -> void
    {
        var key, value;

        if empty(directory) {
            return;
        }

        let this->directory = directory;

        if typeof directory === "array" {
            for key, value in directory {
                bindtextdomain(key, value);
            }
        } else {
            bindtextdomain(
                this->getDefaultDomain(),
                directory
            );
        }
    }

    /**
     * Changes the current domain (i.e. the translation file)
     *
     * @param string|null $domain
     *
     * @return string
     */
    public function setDomain(string domain = null) -> string
    {
        return textdomain(domain);
    }

    /**
     * Sets locale information
     *
     * Note: this method has process-global side effects. Besides calling
     * `setlocale()`, it exports the `LC_ALL`, `LANG` and `LANGUAGE`
     * environment variables via `putenv()`. `LC_ALL` affects every
     * locale-sensitive operation in the process - `(string)` casts of floats,
     * `strtoupper()`/`strtolower()` tables, date formatting and more - not
     * just translations.
     *
     * ```php
     * // Set locale to Dutch
     * $gettext->setLocale(LC_ALL, ["nl_NL"]);
     *
     * // Try different possible locale names for German
     * $gettext->setLocale(LC_ALL, ["de_DE@euro", "de_DE", "de", "ge"]);
     * ```
     *
     * @phpstan-param array<string, mixed> $localeArray
     *
     * @return false|string
     */
    public function setLocale(int! category, array localeArray = []) -> string | bool
    {
        let this->locale   = setlocale(category, localeArray),
            this->category = category;

        if (false !== this->locale) {
            putenv("LC_ALL=" . this->locale);
            putenv("LANG=" . this->locale);
            putenv("LANGUAGE=" . this->locale);
            setlocale(LC_ALL, this->locale);
        }

        return this->locale;
    }

    /**
     * Gets default options
     *
     * @phpstan-return array<string, mixed>
     */
    protected function getOptionsDefault() -> array
    {
        return [
            "category":      LC_ALL,
            "defaultDomain": "messages"
        ];
    }

    /**
     * Validator for constructor
     *
     * @phpstan-param TOptions $options
     *
     * @return void
     * @throws MissingRequiredParameter
     */
    protected function prepareOptions(array! options) -> void
    {
        if unlikely !isset options["locale"] {
            throw new MissingRequiredParameter("locale");
        }

        if unlikely !isset options["directory"] {
            throw new MissingRequiredParameter("directory");
        }

        let options = array_merge(
            this->getOptionsDefault(),
            options
        );

        this->setLocale(options["category"], options["locale"]);
        this->setDefaultDomain(options["defaultDomain"]);
        this->setDirectory(options["directory"]);
        this->setDomain(options["defaultDomain"]);
    }

    /**
     * @todo to be removed when we get traits
     */
    protected function phpFunctionExists(string name) -> bool
    {
        return function_exists(name);
    }
}
