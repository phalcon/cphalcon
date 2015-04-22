
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Cache\Frontend;

use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Frontend\None
 *
 * Discards any kind of frontend data input. This frontend does not have expiration time or any other options
 *
 *<code>
 *<?php
 *
 *	//Create a None Cache
 *	$frontCache = new \Phalcon\Cache\Frontend\None();
 *
 *	// Create the component that will cache "Data" to a "Memcached" backend
 *	// Memcached connection settings
 *	$cache = new \Phalcon\Cache\Backend\Memcache($frontCache, array(
 *		"host" => "localhost",
 *		"port" => "11211"
 *	));
 *
 *	// This Frontend always return the data as it's returned by the backend
 *	$cacheKey = 'robots_order_id.cache';
 *	$robots    = $cache->get($cacheKey);
 *	if ($robots === null) {
 *
 *		// This cache doesn't perform any expiration checking, so the data is always expired
 *		// Make the database call and populate the variable
 *		$robots = Robots::find(array("order" => "id"));
 *
 *		$cache->save($cacheKey, $robots);
 *	}
 *
 *	// Use $robots :)
 *	foreach ($robots as $robot) {
 *		echo $robot->name, "\n";
 *	}
 *</code>
 */
class None implements FrontendInterface
{

	/**
	 * Returns cache lifetime, always one second expiring content
	 */
	public function getLifetime() -> int
	{
		return 1;
	}

	/**
	 * Check whether if frontend is buffering output, always false
	 */
	public function isBuffering() -> boolean
	{
		return false;
	}

	/**
	 * Starts output frontend
	 */
	public function start()
	{

	}

	/**
	 * Returns output cached content
	 *
	 * @return string
	 */
	public function getContent()
	{

	}

	/**
	 * Stops output frontend
	 */
	public function stop()
	{

	}

	/**
	 * Prepare data to be stored
	 *
	 * @param mixed $data
	 */
	public function beforeStore(var data)
	{
		return data;
	}

	/**
	 * Prepares data to be retrieved to user
	 *
	 * @param mixed $data
	 */
	public function afterRetrieve(var data)
	{
		return data;
	}
}
