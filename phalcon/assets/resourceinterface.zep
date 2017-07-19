
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Assets;

/**
 * Phalcon\Assets\ResourceInterface
 *
 * Interface for custom Phalcon\Assets reources
 */
interface ResourceInterface
{
	/**
	 * Sets the resource's type.
	 */
	public function setType(string type) -> <ResourceInterface>;

	/**
	 * Gets the resource's type.
	 */
	public function getType() -> string;

	/**
	 * Sets if the resource must be filtered or not.
	 */
	public function setFilter(boolean filter) -> <ResourceInterface>;

	/**
	 * Gets if the resource must be filtered or not.
	 */
	public function getFilter() -> boolean;

	/**
	 * Sets extra HTML attributes.
	 */
	public function setAttributes(array attributes) -> <ResourceInterface>;

	/**
	 * Gets extra HTML attributes.
	 */
	public function getAttributes() -> array | null;

	/**
	 * Gets the resource's key.
	 */
	public function getResourceKey() -> string;
}
