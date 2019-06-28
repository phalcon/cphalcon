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
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation',
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
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
        'name' => 'Phalcon\\Di\\Injectable',
        'file' => '/app/phalcon/Validation/ValidationInterface.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
    'line' => 14,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Messages\\MessageInterface',
        'file' => '/app/phalcon/Validation/ValidationInterface.zep',
        'line' => 14,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Messages\\Messages',
        'file' => '/app/phalcon/Validation/ValidationInterface.zep',
        'line' => 15,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Validation\\Exception',
        'file' => '/app/phalcon/Validation/ValidationInterface.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Validation\\ValidatorInterface',
        'file' => '/app/phalcon/Validation/ValidationInterface.zep',
        'line' => 17,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
    'line' => 21,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for the Phalcon\\Validation component
 *',
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
    'line' => 22,
    'char' => 9,
  ),
  8 => 
  array (
    'type' => 'interface',
    'name' => 'ValidationInterface',
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
          'name' => 'add',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 27,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'validator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ValidatorInterface',
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 27,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 27,
              'char' => 69,
            ),
          ),
          'docblock' => '**
     * Adds a validator to a field
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
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                  'line' => 27,
                  'char' => 95,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 27,
                'char' => 95,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 27,
            'char' => 95,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 27,
          'last-line' => 31,
          'char' => 19,
        ),
        1 => 
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
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 32,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 32,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Appends a message to the messages list
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
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                  'line' => 32,
                  'char' => 87,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 32,
                'char' => 87,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 32,
            'char' => 87,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 32,
          'last-line' => 40,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'bind',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'entity',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 41,
              'char' => 32,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 41,
              'char' => 38,
            ),
          ),
          'docblock' => '**
     * Assigns the data to an entity
     * The entity is used to obtain the validation values
     *
     * @param object entity
     * @param array|object data
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
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                  'line' => 41,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 41,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 41,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 41,
          'last-line' => 45,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEntity',
          'docblock' => '**
     * Returns the bound entity
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 46,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 46,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 46,
          'last-line' => 50,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFilters',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 51,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 51,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Returns all the filters or a specific one
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 51,
                'char' => 60,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 51,
                'char' => 66,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 51,
            'char' => 66,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 51,
          'last-line' => 55,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getLabel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 56,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Get label for field
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
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 56,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 56,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 56,
          'last-line' => 60,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'docblock' => '**
     * Returns the registered validators
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
                  'value' => 'Messages',
                  'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                  'line' => 61,
                  'char' => 48,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 61,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 61,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 61,
          'last-line' => 65,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValidators',
          'docblock' => '**
     * Returns the validators added to the validation
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
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 66,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 66,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 66,
          'last-line' => 70,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 71,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Gets the a value to validate in the array/object data source
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 71,
                'char' => 51,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 71,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 71,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 71,
          'last-line' => 75,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rule',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 76,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'validator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ValidatorInterface',
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 76,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 76,
              'char' => 70,
            ),
          ),
          'docblock' => '**
     * Alias of `add` method
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
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                  'line' => 76,
                  'char' => 96,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 76,
                'char' => 96,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 76,
            'char' => 96,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rules',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 81,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'validators',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 81,
              'char' => 59,
            ),
          ),
          'docblock' => '**
     * Adds the validators to a field
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
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                  'line' => 81,
                  'char' => 85,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 81,
                'char' => 85,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 81,
            'char' => 85,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 81,
          'last-line' => 87,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setFilters',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 88,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 88,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Adds filters to the field
     *
     * @param array|string filters
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
                  'value' => 'ValidationInterface',
                  'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                  'line' => 88,
                  'char' => 79,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 88,
                'char' => 79,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 88,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 88,
          'last-line' => 92,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setLabels',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'labels',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 93,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Adds labels for fields
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 93,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 93,
          'last-line' => 100,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'validate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 101,
                'char' => 45,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 101,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'entity',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 101,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidationInterface.zep',
              'line' => 101,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Validate a set of data according to a set of rules
     *
     * @param array|object data
     * @param object entity
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
                  'value' => 'Messages',
                  'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                  'line' => 101,
                  'char' => 79,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidationInterface.zep',
                'line' => 101,
                'char' => 79,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidationInterface.zep',
            'line' => 101,
            'char' => 79,
          ),
          'file' => '/app/phalcon/Validation/ValidationInterface.zep',
          'line' => 101,
          'last-line' => 102,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/ValidationInterface.zep',
      'line' => 102,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Validation/ValidationInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);