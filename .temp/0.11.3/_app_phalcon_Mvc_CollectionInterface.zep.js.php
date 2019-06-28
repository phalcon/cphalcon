<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc',
    'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
    'line' => 13,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Messages\\MessageInterface',
        'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
        'line' => 13,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Mvc\\Collection
 *',
    'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
    'line' => 18,
    'char' => 9,
  ),
  4 => 
  array (
    'type' => 'interface',
    'name' => 'CollectionInterface',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'appendMessage',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'MessageInterface',
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 23,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 23,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Appends a customized message on the validation process
     *',
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 23,
          'last-line' => 27,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'cloneResult',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'CollectionInterface',
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 28,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 28,
              'char' => 72,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'document',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 28,
              'char' => 89,
            ),
          ),
          'docblock' => '**
     * Returns a cloned collection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                  'line' => 28,
                  'char' => 115,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 28,
                'char' => 115,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 28,
            'char' => 115,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 28,
          'last-line' => 32,
          'char' => 26,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'count',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 33,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 33,
              'char' => 57,
            ),
          ),
          'docblock' => '**
     * Perform a count over a collection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 33,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 33,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 33,
          'last-line' => 37,
          'char' => 26,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'delete',
          'docblock' => '**
     * Deletes a model instance. Returning true on success or false otherwise
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 38,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 38,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'find',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 43,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 43,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Allows to query a set of records that match the specified conditions
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 43,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 43,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 43,
          'last-line' => 49,
          'char' => 26,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'findById',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 50,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Find a document by its id
     *
     * @param string id
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                  'line' => 50,
                  'char' => 70,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 50,
                'char' => 70,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 50,
                'char' => 76,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 50,
            'char' => 76,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 50,
          'last-line' => 54,
          'char' => 26,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => 'findFirst',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 55,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 55,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Allows to query the first record that match the specified conditions
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 55,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 55,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 55,
          'last-line' => 60,
          'char' => 26,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fireEvent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 61,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Fires an event, implicitly calls behaviors and listeners in the events
     * manager are notified
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 61,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 61,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 61,
          'last-line' => 66,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'fireEventCancel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 67,
              'char' => 54,
            ),
          ),
          'docblock' => '**
     * Fires an event, implicitly listeners in the events manager are notified
     * This method stops if one of the callbacks/listeners returns bool false
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 67,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 67,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 67,
          'last-line' => 73,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getConnection',
          'docblock' => '**
     * Retrieves a database connection
     *
     * @return MongoDb
     *',
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 74,
          'last-line' => 79,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDirtyState',
          'docblock' => '**
     * Returns one of the DIRTY_STATE_* constants telling if the record exists
     * in the database or not
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 80,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 80,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 80,
          'last-line' => 86,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getId',
          'docblock' => '**
     * Returns the value of the _id property
     *
     * @return MongoId
     *',
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 87,
          'last-line' => 91,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'docblock' => '**
     * Returns all the validation messages
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'MessageInterface',
                  'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                  'line' => 92,
                  'char' => 58,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 92,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 92,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 92,
          'last-line' => 97,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getReservedAttributes',
          'docblock' => '**
     * Returns an array with reserved properties that cannot be part of the
     * insert/update
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 98,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 98,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 98,
          'last-line' => 102,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSource',
          'docblock' => '**
     * Returns collection name mapped in the model
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 103,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 103,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 103,
          'last-line' => 107,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'save',
          'docblock' => '**
     * Creates/Updates a collection based on the values in the attributes
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 108,
                'char' => 35,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 108,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 108,
          'last-line' => 112,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setConnectionService',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'connectionService',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 113,
              'char' => 67,
            ),
          ),
          'docblock' => '**
     * Sets a service in the services container that returns the Mongo database
     *',
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 113,
          'last-line' => 118,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDirtyState',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'dirtyState',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 119,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets the dirty state of the object using one of the DIRTY_STATE_*
     * constants
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'CollectionInterface',
                  'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                  'line' => 119,
                  'char' => 75,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 119,
                'char' => 75,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 119,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 119,
          'last-line' => 125,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setId',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
              'line' => 126,
              'char' => 29,
            ),
          ),
          'docblock' => '**
     * Sets a value for the _id property, creates a MongoId object if needed
     *
     * @param mixed id
     *',
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 126,
          'last-line' => 130,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'validationHasFailed',
          'docblock' => '**
     * Check whether validation process has generated any messages
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
                'line' => 131,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
            'line' => 131,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
          'line' => 131,
          'last-line' => 132,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
      'line' => 132,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/CollectionInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);