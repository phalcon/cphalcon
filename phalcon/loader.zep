
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)       |
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

use Phalcon\Events\ManagerInterface;
use Phalcon\Events\EventsAwareInterface;

/**
 * Phalcon\Loader
 *
 * This component helps to load your project classes automatically based on some conventions
 *
 *<code>
 * //Creates the autoloader
 * $loader = new Loader();
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
class Loader implements EventsAwareInterface
{

	protected _eventsManager = null;

	protected _foundPath = null;

	protected _checkedPath = null;

	protected _classes = null;

	protected _extensions = ["php"];

	protected _namespaces = null;

	protected _directories = null;

	protected _registered = false;

	/**
	 * Sets the events manager
	 */
	public function setEventsManager(<ManagerInterface> eventsManager)
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Sets an array of file extensions that the loader must try in each attempt to locate the file
	 */
	public function setExtensions(array! extensions) -> <Loader>
	{
		let this->_extensions = extensions;
		return this;
	}

	/**
	 * Returns the file extensions registered in the loader
	 */
	public function getExtensions() -> array
	{
		return this->_extensions;
	}

	/**
	 * Register namespaces and their related directories
	 */
	public function registerNamespaces(array! namespaces, boolean merge = false) -> <Loader>
	{
		var preparedNamespaces, name, paths;

		let preparedNamespaces = this->prepareNamespace(namespaces);

		if merge && typeof this->_namespaces == "array" {
			for name, paths in preparedNamespaces {
				if !isset this->_namespaces[name] {
					let this->_namespaces[name] = [];
				}

				let this->_namespaces[name] = array_merge(this->_namespaces[name], paths);
			}
		} else {
			let this->_namespaces = preparedNamespaces;
		}

		return this;
	}

	protected function prepareNamespace(array! $namespace) -> array
	{
		var localPaths, name, paths, prepared;

		let prepared = [];
		for name, paths in $namespace {
			if typeof paths != "array" {
				let localPaths = [paths];
			} else {
				let localPaths = paths;
			}

			let prepared[name] = localPaths;
		}

		return prepared;
	}

	/**
	 * Returns the namespaces currently registered in the autoloader
	 */
	public function getNamespaces() -> array
	{
		return this->_namespaces;
	}

	/**
	 * Register directories in which "not found" classes could be found
	 */
	public function registerDirs(array! directories, boolean merge = false) -> <Loader>
	{
		if merge && typeof this->_directories == "array" {
			let this->_directories = array_merge(this->_directories, directories);
		} else {
			let this->_directories = directories;
		}

		return this;
	}

	/**
	 * Returns the directories currently registered in the autoloader
	 */
	public function getDirs() -> array
	{
		return this->_directories;
	}

	/**
	 * Register classes and their locations
	 */
	public function registerClasses(array! classes, boolean merge = false) -> <Loader>
	{
		if merge && typeof this->_classes == "array" {
			let this->_classes = array_merge(this->_classes, classes);
		} else {
			let this->_classes = classes;
		}

		return this;
	}

	/**
	 * Returns the class-map currently registered in the autoloader
	 */
	public function getClasses() -> array
	{
		return this->_classes;
	}

	/**
	 * Register the autoload method
	 */
	public function register() -> <Loader>
	{
		if this->_registered === false {
			spl_autoload_register([this, "autoLoad"]);
			let this->_registered = true;
		}
		return this;
	}

	/**
	 * Unregister the autoload method
	 */
	public function unregister() -> <Loader>
	{
		if this->_registered === true {
			spl_autoload_unregister([this, "autoLoad"]);
			let this->_registered = false;
		}
		return this;
	}

	/**
	 * Autoloads the registered classes
	 */
	public function autoLoad(string! className) -> boolean
	{
		var eventsManager, classes, extensions, filePath, ds, fixedDirectory,
			directories, ns, namespaces, nsPrefix,
			directory, fileName, extension, nsClassName;

		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			eventsManager->fire("loader:beforeCheckClass", this, className);
		}

		/**
		 * First we check for static paths for classes
		 */
		let classes = this->_classes;
		if typeof classes == "array" {
			if fetch filePath, classes[className] {
				if typeof eventsManager == "object" {
					let this->_foundPath = filePath;
					eventsManager->fire("loader:pathFound", this, filePath);
				}
				require filePath;
				return true;
			}
		}

		let extensions = this->_extensions;

		let ds = DIRECTORY_SEPARATOR,
			ns = "\\";

		/**
		 * Checking in namespaces
		 */
		let namespaces = this->_namespaces;
		if typeof namespaces == "array" {

			for nsPrefix, directories in namespaces {

				/**
				 * The class name must start with the current namespace
				 */
				if !starts_with(className, nsPrefix) {
					continue;
				}

				/**
				 * Append the namespace separator to the prefix
				 */
				let fileName = substr(className, strlen(nsPrefix . ns));
				let fileName = str_replace(ns, ds, fileName);

				if !fileName {
					continue;
				}

				for directory in directories {
					/**
					 * Add a trailing directory separator if the user forgot to do that
					 */
					let fixedDirectory = rtrim(directory, ds) . ds;

					for extension in extensions {

						let filePath = fixedDirectory . fileName . "." . extension;

						/**
						 * Check if a events manager is available
						 */
						if typeof eventsManager == "object" {
							let this->_checkedPath = filePath;
							eventsManager->fire("loader:beforeCheckPath", this);
						}

						/**
						 * This is probably a good path, let's check if the file exists
						 */
						if is_file(filePath) {

							if typeof eventsManager == "object" {
								let this->_foundPath = filePath;
								eventsManager->fire("loader:pathFound", this, filePath);
							}

							/**
							 * Simulate a require
							 */
							require filePath;

							/**
							 * Return true mean success
							 */
							return true;
						}
					}
				}
			}
		}

		/**
		 * Change the namespace separator by directory separator too
		 */
		let nsClassName = str_replace("\\", ds, className);

		/**
		 * Checking in directories
		 */
		let directories = this->_directories;
		if typeof directories == "array" {

			for directory in directories {

				/**
				 * Add a trailing directory separator if the user forgot to do that
				 */
				let fixedDirectory = rtrim(directory, ds) . ds;

				for extension in extensions {

					/**
					 * Create a possible path for the file
					 */
					let filePath = fixedDirectory . nsClassName . "." . extension;

					if typeof eventsManager == "object" {
						let this->_checkedPath = filePath;
						eventsManager->fire("loader:beforeCheckPath", this, filePath);
					}

					/**
					 * Check in every directory if the class exists here
					 */
					if is_file(filePath) {

						/**
						 * Call 'pathFound' event
						 */
						if typeof eventsManager == "object" {
							let this->_foundPath = filePath;
							eventsManager->fire("loader:pathFound", this, filePath);
						}

						/**
						 * Simulate a require
						 */
						require filePath;

						/**
						 * Return true meaning success
						 */
						return true;
					}
				}
			}
		}

		/**
		 * Call 'afterCheckClass' event
		 */
		if typeof eventsManager == "object" {
			eventsManager->fire("loader:afterCheckClass", this, className);
		}

		/**
		 * Cannot find the class, return false
		 */
		return false;
	}

	/**
	 * Get the path when a class was found
	 */
	public function getFoundPath() -> string
	{
		return this->_foundPath;
	}

	/**
	 * Get the path the loader is checking for a path
	 */
	public function getCheckedPath() -> string
	{
		return this->_checkedPath;
	}
}
