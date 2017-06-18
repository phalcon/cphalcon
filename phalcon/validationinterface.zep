
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

namespace Phalcon;

use Phalcon\Di\Injectable;
use Phalcon\Validation\Exception;
use Phalcon\Validation\MessageInterface;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\ValidatorInterface;

/**
 * Phalcon\ValidationInterface
 *
 * Interface for the Phalcon\Validation component
 */
interface ValidationInterface
{
	/**
	 * Validate a set of data according to a set of rules
	 *
	 * @param array|object data
	 * @param object entity
	 * @return \Phalcon\Validation\Message\Group
	 */
	public function validate(var data = null, var entity = null) -> <Group>;

	/**
	 * Adds a validator to a field
	 */
	public function add(string field, <ValidatorInterface> validator) -> <Validation>;

	/**
	 * Alias of `add` method
	 */
	public function rule(string field, <ValidatorInterface> validator) -> <Validation>;

	/**
	 * Adds the validators to a field
	 */
	public function rules(string! field, array! validators) -> <Validation>;

	/**
	 * Adds filters to the field
	 *
	 * @param string field
	 * @param array|string filters
	 * @return \Phalcon\Validation
	 */
	public function setFilters(string field, filters) -> <Validation>;

	/**
	 * Returns all the filters or a specific one
	 *
	 * @param string field
	 * @return mixed
	 */
	public function getFilters(string field = null);

	/**
	 * Returns the validators added to the validation
	 */
	public function getValidators();

	/**
	 * Returns the bound entity
	 *
	 * @return object
	 */
	public function getEntity();

	/**
	 * Adds default messages to validators
	 */
	public function setDefaultMessages(array messages = []);

	/**
	 * Get default message for validator type
	 *
	 * @param string type
	 */
	public function getDefaultMessage(string! type);

	/**
	 * Returns the registered validators
	 */
	public function getMessages() -> <Group>;

	/**
	 * Adds labels for fields
	 */
	public function setLabels(array! labels);

	/**
	 * Get label for field
	 *
	 * @param string field
	 * @return string
	 */
	public function getLabel(string! field);

	/**
	 * Appends a message to the messages list
	 */
	public function appendMessage(<MessageInterface> message);

	/**
	 * Assigns the data to an entity
	 * The entity is used to obtain the validation values
	 *
	 * @param object entity
	 * @param array|object data
	 * @return \Phalcon\Validation
	 */
	public function bind(entity, data) -> <Validation>;

	/**
	 * Gets the a value to validate in the array/object data source
	 *
	 * @param string field
	 * @return mixed
	 */
	public function getValue(string field);
}
