
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Wojciech Ślawski <jurigag@gmail.com>                          |
 |          Nathan Daly <justlikephp@gmail.com>                           |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\Controller\BindModelInterface;
use Phalcon\Mvc\Model\Binder\BindableInterface;
use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Mvc\Model\Binding
 *
 * This is an class for binding models into params for handler
 */
class Binder implements BinderInterface
{
	/**
	 * Array for storing active bound models
	 *
	 * @var array
	 */
	protected boundModels = [] { get };

	/**
	 * Cache object used for caching parameters for model binding
	 */
	protected cache ;

	/**
	 * Internal cache for caching parameters for model binding during request
	 */
	protected internalCache = [];

	/**
	 * Array for original values
	 */
	protected originalValues = [] { get };

	/**
	 * Phalcon\Mvc\Model\Binder constructor
	 */
	public function __construct(<BackendInterface> cache = null)
	{
		let this->cache = cache;
	}

	/**
	 * Gets cache instance
	 */
	public function setCache(<BackendInterface> cache) -> <BinderInterface>
	{
		let this->cache = cache;

		return this;
	}

	/**
	 * Sets cache instance
	 */
	public function getCache() -> <BackendInterface>
	{
		return this->cache;
	}

	/**
	 * Bind models into params in proper handler
	 */
	public function bindToHandler(object handler, array params, string cacheKey, var methodName = null) -> array
	{
		var paramKey, className, boundModel, paramsCache, paramValue;

		let this->originalValues = [];
		if handler instanceof \Closure || methodName != null {
			let this->boundModels = [];
			let paramsCache = this->getParamsFromCache(cacheKey);
			if typeof paramsCache == "array" {
				for paramKey, className in paramsCache {
					let paramValue = params[paramKey];
					let boundModel = this->findBoundModel(paramValue, className);
					let this->originalValues[paramKey] = paramValue;
					let params[paramKey] = boundModel;
					let this->boundModels[paramKey] = boundModel;
				}

				return params;
			}

			return this->getParamsFromReflection(handler, params, cacheKey, methodName);
		}
		throw new Exception("You must specify methodName for handler or pass Closure as handler");
	}

    /**
    * Find the model by param value.
    */
    protected function findBoundModel(var paramValue, string className) -> object | boolean
    {
        return {className}::findFirst(paramValue);
    }

	/**
	 * Get params classes from cache by key
	 */
	protected function getParamsFromCache(string cacheKey) -> array | null
	{
		var cache, internalParams;

		if fetch internalParams, this->internalCache[cacheKey] {
			return internalParams;
		}

		let cache = this->cache;

		if cache != null && cache->exists(cacheKey) {
			let internalParams = cache->get(cacheKey);
			let this->internalCache[cacheKey] = internalParams;

			return internalParams;
		}

		return null;
	}

	/**
	 * Get modified params for handler using reflection
	 */
	protected function getParamsFromReflection(object handler, array params, string cacheKey, var methodName) -> array
	{
		var methodParams, reflection, paramKey, methodParam, paramsCache, className, realClasses = null,
			boundModel, cache, handlerClass, reflectionClass, paramsKeys, paramValue;
		let paramsCache = [];
		if methodName != null {
			let reflection = new \ReflectionMethod(handler, methodName);
		} else {
			let reflection = new \ReflectionFunction(handler);
		}

		let cache = this->cache;

		let methodParams = reflection->getParameters();
		let paramsKeys = array_keys(params);
		for paramKey, methodParam in methodParams {
			let reflectionClass = methodParam->getClass();

			if !reflectionClass {
				continue;
			}

			let className = reflectionClass->getName();
			if !isset params[paramKey] {
				let paramKey = paramsKeys[paramKey];
			}
			let boundModel = null;
			let paramValue = params[paramKey];

			if className == "Phalcon\\Mvc\\Model" {
				if realClasses == null {
					if handler instanceof BindModelInterface {
						let handlerClass = get_class(handler);
						let realClasses = {handlerClass}::getModelName();
					} elseif handler instanceof BindableInterface {
						let realClasses = handler->getModelName();
					} else {
						throw new Exception("Handler must implement Phalcon\\Mvc\\Model\\Binder\\BindableInterface in order to use Phalcon\\Mvc\\Model as parameter");
					}
				}
				if typeof realClasses == "array" {
					if fetch className, realClasses[paramKey] {
						let boundModel = this->findBoundModel(paramValue, className);
					} else {
						throw new Exception("You should provide model class name for ".paramKey." parameter");
					}
				} elseif typeof realClasses == "string" {					
					let className = realClasses;
					let boundModel = this->findBoundModel(paramValue, className);
				} else {
					throw new Exception("getModelName should return array or string");
				}
			} elseif is_subclass_of(className, "Phalcon\\Mvc\\Model") {
				let boundModel = this->findBoundModel(paramValue, className);
			}

			if boundModel != null {
				let this->originalValues[paramKey] = paramValue;
				let params[paramKey] = boundModel;
				let this->boundModels[paramKey] = boundModel;
				let paramsCache[paramKey] = className;
			}
		}

		if cache != null {
			cache->save(cacheKey, paramsCache);
		}

		let this->internalCache[cacheKey] = paramsCache;

		return params;
	}
}
