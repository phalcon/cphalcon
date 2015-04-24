/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
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
use Phalcon\Translate\AdapterInterface;
use Phalcon\Translate\Adapter;


/**
 * Class Gettext
 *
 * @package Phalcon\Translate\Adapter
 */
class Gettext extends Adapter implements AdapterInterface, \ArrayAccess
{
	/**
	 * @var string|array
	 */
	protected _directory;

	/**
	 * @var string
	 */
	protected _defaultDomain;

	/**
	 * @var string
	 */
	protected _locale;

	/**
	 * @var int
	 */
	protected _category;

	/**
	 * Phalcon\Translate\Adapter\Gettext constructor
	 */
	public function __construct(array! options)
	{
		this->prepareOptions(options);
	}

	/**
	 * Returns the translation related to the given key
	 *
	 * @param string  index
	 * @param array   placeholders
	 * @param string  domain
	 * @return string
	 */
	public function query(string! index, placeholders = null) -> string
	{
		var translation, domain;

		if func_num_args() > 2 {
			let domain = func_get_arg(2);
		} else {
			let domain = null;
		}

		if !domain {
			let translation = gettext(index);
		} else {
			let translation = dgettext(domain, index);
		}

		return this->replacePlaceholders(translation, placeholders);
	}

	/**
	 * Check whether is defined a translation key in the internal array
	 */
	public function exists(string! index) -> boolean
	{
		return strlen(this->query(index)) > 0;
	}

	/**
	 * The plural version of gettext().
	 * Some languages have more than one form for plural messages dependent on the count.
	 *
	 * @param  string  msgid1
	 * @param  string  msgid2
	 * @param  int     count
	 * @param  array   placeholders
	 * @param  string  domain
	 *
	 * @return string
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
	 * Changes the current domain (i.e. the translation file). The passed domain must be one
	 * of those passed to the constructor.
	 *
	 * @param  string domain
	 *
	 * @return string Returns the new current domain.
	 * @throws \InvalidArgumentException
	 */
	public function setDomain(string! domain) -> string
	{
		/*if domain != this->_defaultDomain || !in_array(domain, this->_domains) {
			throw new \InvalidArgumentException(domain . " is invalid translation domain");
		}*/

		return textdomain(domain);
	}

	/**
	 * Sets the default domain
	 *
	 * @return string Returns the new current domain.
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
	 * Gets the default domain
	 */
	public function getDefaultDomain() -> string
	{
		return this->_defaultDomain;
	}

	/**
	 * Sets the path for a domain
	 */
	public function setDirectory(var directory) -> void
	{
		var key, value;

		let this->_directory = directory;

		if typeof directory === "array" {
			if count(directory) {
				for key, value in directory {
					bindtextdomain(key, value);
				}
			}
		} else {
			bindtextdomain(this->getDefaultDomain(), directory);
		}
	}
	/**
	 * Gets the path for a domain
	 */
	public function getDirectory(var directory) -> string|array
	{
		return this->_directory;
	}

	/**
	 * Sets locale information
	 */
	public function setLocale(int category, string! locale) -> string|boolean
	{
		let this->_locale   = call_user_func_array("setlocale", func_get_args());
		let this->_category = category;

		putenv("LC_ALL=" . this->_locale);
		return this->_locale;
	}

	/**
	 * Gets locale
	 */
	public function getLocale() -> string
	{
		return this->_locale;
	}

	/**
	 * Gets locale category
	 */
	public function getCategory() -> int
	{
		return this->_category;
	}

	/**
	 * Validator for constructor
	 */
	protected function prepareOptions(array! options) -> void
	{
		if !isset options["locale"] {
			throw new Exception("Parameter \"locale\" is required");
		}

		if !isset options["directory"] {
			throw new Exception("Parameter \"directory\" is required");
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
			"defaultDomain": "message"
		];
	}
}
