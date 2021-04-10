
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
use Phalcon\Translate\Exception;
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
 * Allows translate using gettext
 */
class Gettext extends AbstractAdapter implements ArrayAccess
{
    /**
     * @var int
     */
    protected category { get };

    /**
     * @var string
     */
    protected defaultDomain { get };

    /**
     * @var string|array
     */
    protected directory { get };

    /**
     * @var string
     */
    protected locale { get };

    /**
     * Phalcon\Translate\Adapter\Gettext constructor
     *
     * @param array options = [
     *     'locale' => '',
     *     'defaultDomain' => '',
     *     'directory' => '',
     *     'category' => ''
     * ]
     */
    public function __construct(<InterpolatorFactory> interpolator, array! options)
    {
        if unlikely !function_exists("gettext") {
            throw new Exception(
                "This class requires the gettext extension for PHP"
            );
        }

        parent::__construct(interpolator, options);

        this->prepareOptions(options);
    }

    /**
     * Check whether is defined a translation key in the internal array
     */
    public function exists(string! index) -> bool
    {
        var result;

        let result = this->query(index);

        return result !== index;
    }

    /**
     * The plural version of gettext().
     * Some languages have more than one form for plural messages dependent on
     * the count.
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
     * @param array   placeholders
     */
    public function query(string! index, array placeholders = []) -> string
    {
        var translation;

        let translation = gettext(index);

        return this->replacePlaceholders(translation, placeholders);
    }

    /**
     * Sets the default domain
     */
    public function resetDomain() -> string
    {
        return textdomain(
            this->getDefaultDomain()
        );
    }

    /**
     * Sets the domain default to search within when calls are made to gettext()
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
     * @param string|array directory The directory path or an array of directories and domains
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
     */
    public function setDomain(var domain) -> string
    {
        return textdomain(domain);
    }

    /**
     * Sets locale information
     *
     * ```php
     * // Set locale to Dutch
     * $gettext->setLocale(LC_ALL, "nl_NL");
     *
     * // Try different possible locale names for German
     * $gettext->setLocale(LC_ALL, "de_DE@euro", "de_DE", "de", "ge");
     * ```
     */
    public function setLocale(int! category, array localeArray = []) -> string | bool
    {
        let this->locale   = setlocale(category, localeArray),
            this->category = category;git

        putenv("LC_ALL=" . this->locale);
        putenv("LANG=" . this->locale);
        putenv("LANGUAGE=" . this->locale);
        setlocale(LC_ALL, this->locale);

        return this->locale;
    }

    /**
     * Gets default options
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
     */
    protected function prepareOptions(array! options) -> void
    {
        if unlikely !isset options["locale"] {
            throw new Exception("Parameter 'locale' is required");
        }

        if unlikely !isset options["directory"] {
            throw new Exception("Parameter 'directory' is required");
        }

        let options = array_merge(
            this->getOptionsDefault(),
            options
        );

        this->setLocale(
            options["category"],
            options["locale"]
        );

        this->setDefaultDomain(
            options["defaultDomain"]
        );

        this->setDirectory(
            options["directory"]
        );

        this->setDomain(
            options["defaultDomain"]
        );
    }
}
