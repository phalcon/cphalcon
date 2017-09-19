
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://www.phalconphp.com)      |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Stanislav Kiryukhin <korsar.zn@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Translate\Exception;
use Phalcon\Translate\Adapter;

/**
 * Phalcon\Translate\Adapter\Gettext
 *
 * <code>
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
 * </code>
 *
 * Allows translate using gettext
 */
class Gettext extends Adapter implements \ArrayAccess
{
	/**
	 * @var string|array
	 */
	protected _directory { get };

	/**
	 * @var string
	 */
	protected _defaultDomain { get };

	/**
	 * @var string
	 */
	protected _locale { get };

	/**
	 * @var int
	 */
	protected _category { get };

	/**
	 * Phalcon\Translate\Adapter\Gettext constructor
	 */
	public function __construct(array! options)
	{
		if (!function_exists("gettext")) {
			throw new Exception("This class requires the gettext extension for PHP");
		}

		parent::__construct(options);
		this->prepareOptions(options);
	}

	/**
	 * Returns the translation related to the given key.
	 *
	 * <code>
	 * $translator->query("你好 %name%！", ["name" => "Phalcon"]);
	 * </code>
	 */
	public function query(string! index, placeholders = null) -> string
	{
		var translation;

		let translation = gettext(index);

		return this->replacePlaceholders(translation, placeholders);
	}

	/**
	 * Check whether is defined a translation key in the internal array
	 */
	public function exists(string! index) -> boolean
	{
		var result;

		let result = this->query(index);

		return result !== index;
	}

	/**
	 * The plural version of gettext().
	 * Some languages have more than one form for plural messages dependent on the count.
	 */
	public function nquery(string! msgid1, string! msgid2, int! count, placeholders = null, string! domain = null) -> string
	{
		var translation;

		if !domain {
			let translation = ngettext(msgid1, msgid2, count);
		} else {
			let translation = dngettext(domain, msgid1, msgid2, count);
		}

		return this->replacePlaceholders(translation, placeholders);
	}

	/**
	 * Changes the current domain (i.e. the translation file)
	 */
	public function setDomain(var domain) -> string
	{
		return textdomain(domain);
	}

	/**
	 * Sets the default domain
	 */
	public function resetDomain() -> string
	{
		return textdomain(this->getDefaultDomain());
	}

	/**
	 * Sets the domain default to search within when calls are made to gettext()
	 */
	public function setDefaultDomain(string! domain) -> void
	{
		let this->_defaultDomain = domain;
	}

	/**
	 * Sets the path for a domain
	 *
	 * <code>
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
	 * </code>
	 *
	 * @param string|array directory The directory path or an array of directories and domains
	 */
	public function setDirectory(var directory) -> void
	{
		var key, value;

		if (empty(directory)) {
			return;
		}

		let this->_directory = directory;

		if typeof directory === "array" {
			for key, value in directory {
				bindtextdomain(key, value);
			}
		} else {
			bindtextdomain(this->getDefaultDomain(), directory);
		}
	}

	/**
	 * Sets locale information
	 *
	 * <code>
	 * // Set locale to Dutch
	 * $gettext->setLocale(LC_ALL, "nl_NL");
	 *
	 * // Try different possible locale names for german
	 * $gettext->setLocale(LC_ALL, "de_DE@euro", "de_DE", "de", "ge");
	 * </code>
	 */
	public function setLocale(int! category, string! locale) -> string | boolean
	{
		let this->_locale   = call_user_func_array("setlocale", func_get_args());
		let this->_category = category;

		putenv("LC_ALL=" . this->_locale);
		putenv("LANG=" . this->_locale);
		putenv("LANGUAGE=" . this->_locale);
		setlocale(LC_ALL, this->_locale);

		return this->_locale;
	}

	/**
	 * Validator for constructor
	 */
	protected function prepareOptions(array! options) -> void
	{
		if !isset options["locale"] {
			throw new Exception("Parameter 'locale' is required");
		}

		if !isset options["directory"] {
			throw new Exception("Parameter 'directory' is required");
		}

		let options = array_merge(this->getOptionsDefault(), options);

		this->setLocale(options["category"], options["locale"]);
		this->setDefaultDomain(options["defaultDomain"]);
		this->setDirectory(options["directory"]);
		this->setDomain(options["defaultDomain"]);
	}

	/**
	 * Gets default options
	 */
	protected function getOptionsDefault() -> array
	{
		return [
			"category": LC_ALL,
			"defaultDomain": "messages"
		];
	}
}
