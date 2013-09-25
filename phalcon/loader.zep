
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

/**
 * Phalcon\Loader
 *
 * This component helps to load your project classes automatically based on some conventions
 *
 *<code>
 * //Creates the autoloader
 * $loader = new Phalcon\Loader();
 *
 * //Register some namespaces
 * $loader->registerNamespaces(array(
 *   'Example\Base' => 'vendor/example/base/',
 *   'Example\Adapter' => 'vendor/example/adapter/',
 *   'Example' => 'vendor/example/'
 * ));
 *
 * //register autoloader
 * $loader->register();
 *
 * //Requiring this class will automatically include file vendor/example/adapter/Some.php
 * $adapter = Example\Adapter\Some();
 *</code>
 */
class Loader implements Phalcon\Events\EventsAwareInterface
{

	protected _eventsManager;

	protected _foundPath;

	protected _checkedPath;

	protected _prefixes;

	protected _classes;

	protected _extensions;

	protected _namespaces;

	protected _directories;

	protected _registered;

	/**
	 * Phalcon\Loader constructor
	 */
	public function __construct()
	{
		let this->_extensions = ["php"];
	}

	/**
	 * Sets the events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<Phalcon\Events\ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager() -> <Phalcon\Events\ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Sets an array of extensions that the loader must try in each attempt to locate the file
	 *
	 * @param array extensions
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function setExtensions(extensions) -> <Phalcon\Loader>
	{
		if typeof extensions != "array" {
			throw new Phalcon\Loader\Exception("Parameter extensions must be an array");
		}
		let this->_extensions = extensions;
		return this;
	}

	/**
	 * Return file extensions registered in the loader
	 *
	 * @return boolean
	 */
	public function getExtensions()
	{
		return this->_extensions;
	}

	/**
	 * Register namespaces and their related directories
	 *
	 * @param array namespaces
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function registerNamespaces(namespaces, boolean merge=false) -> <Phalcon\Loader>
	{
		var currentNamespaces;

		if typeof namespaces != "array" {
			throw new Phalcon\Loader\Exception("Parameter namespaces must be an array");
		}

		if merge {
			let currentNamespaces = this->_namespaces;
			if typeof currentNamespaces == "array" {
				let this->_namespaces = array_merge(currentNamespaces, namespaces);
			} else {
				let this->_namespaces = namespaces;
			}
		} else {
			let this->_namespaces = namespaces;
		}

		return this;
	}

	/**
	 * Return current namespaces registered in the autoloader
	 *
	 * @param array
	 */
	public function getNamespaces()
	{
		return this->_namespaces;
	}

	/**
	 * Register directories on which "not found" classes could be found
	 *
	 * @param array prefixes
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function registerPrefixes(prefixes, boolean merge=false) -> <Phalcon\Loader>
	{
		var currentPrefixes;

		if typeof prefixes != "array" {
			throw new Phalcon\Loader\Exception("Parameter prefixes must be an array");
		}

		if merge {
			let currentPrefixes = this->_prefixes;
			if typeof currentPrefixes == "array" {
				let this->_prefixes = array_merge(currentPrefixes, prefixes);
			} else {
				let this->_prefixes = prefixes;
			}
		} else {
			let this->_prefixes = prefixes;
		}

		return this;
	}

	/**
	 * Return current prefixes registered in the autoloader
	 *
	 * @param array
	 */
	public function getPrefixes()
	{
		return this->_prefixes;
	}

	/**
	 * Register directories on which "not found" classes could be found
	 *
	 * @param array directories
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function registerDirs(directories, boolean merge=false) -> <Phalcon\Loader>
	{
		var currentDirectories;

		if typeof directories != "array" {
			throw new Phalcon\Loader\Exception("Parameter directories must be an array");
		}

		if merge {
			let currentDirectories = this->_directories;
			if typeof currentDirectories == "array" {
				let this->_directories = array_merge(currentDirectories, directories);
			} else {
				let this->_directories = directories;
			}
		} else {
			let this->_directories = directories;
		}
		return this;
	}

	/**
	 * Return current directories registered in the autoloader
	 *
	 * @param array
	 */
	public function getDirs()
	{
		return this->_directories;
	}

	/**
	 * Register classes and their locations
	 *
	 * @param array classes
	 * @param boolean merge
	 * @return Phalcon\Loader
	 */
	public function registerClasses(classes, boolean merge=false) -> <Phalcon\Loader>
	{
		var currentClasses;

		if typeof classes != "array" {
			throw new Phalcon\Loader\Exception("Parameter directories must be an array");
		}

		if merge {
			let currentClasses = this->_classes;
			if typeof currentClasses == "array" {
				let this->_classes = array_merge(currentClasses, classes);
			} else {
				let this->_classes = classes;
			}
		} else {
			let this->_classes = classes;
		}
		return this;
	}

	/**
	 * Return the current class-map registered in the autoloader
	 *
	 * @param array
	 */
	public function getClasses()
	{
		return this->_classes;
	}

	/**
	 * Register the autoload method
	 *
	 * @return Phalcon\Loader
	 */
	public function register() -> <Phalcon\Loader>
	{
		var registered;
		let registered = this->_registered;
		if registered === false {
			spl_autoload_register([this, "autoLoad"]);
			let this->_registered = true;
		}
		return this;
	}

	/**
	 * Unregister the autoload method
	 *
	 * @return Phalcon\Loader
	 */
	public function unregister() -> <Phalcon\Loader>
	{
		var registered;
		let registered = this->_registered;
		if registered === false {
			spl_autoload_unregister([this, "autoLoad"]);
			let this->_registered = true;
		}
		return this;
	}

	/**
	 * Makes the work of autoload registered classes
	 *
	 * @param string className
	 * @return boolean
	 */
	public function autoLoad(string className) -> boolean
	{
	}

	/**
	 * Get the path when a class was found
	 *
	 * @return string
	 */
	public function getFoundPath() -> string
	{
		return this->_foundPath;
	}

	/**
	 * Get the path the loader is checking for a path
	 *
	 * @return string
	 */
	public function getCheckedPath() -> string
	{
		return this->_checkedPath;
	}

}
