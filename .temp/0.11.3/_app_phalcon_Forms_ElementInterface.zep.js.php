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
    'file' => '/app/phalcon/Forms/ElementInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Forms',
    'file' => '/app/phalcon/Forms/ElementInterface.zep',
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
        'name' => 'Phalcon\\Forms\\Form',
        'file' => '/app/phalcon/Forms/ElementInterface.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Forms/ElementInterface.zep',
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
        'file' => '/app/phalcon/Forms/ElementInterface.zep',
        'line' => 14,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Forms/ElementInterface.zep',
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
        'file' => '/app/phalcon/Forms/ElementInterface.zep',
        'line' => 15,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Forms/ElementInterface.zep',
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
        'name' => 'Phalcon\\Validation\\ValidatorInterface',
        'file' => '/app/phalcon/Forms/ElementInterface.zep',
        'line' => 16,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Forms/ElementInterface.zep',
    'line' => 20,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Forms\\Element classes
 *',
    'file' => '/app/phalcon/Forms/ElementInterface.zep',
    'line' => 21,
    'char' => 9,
  ),
  7 => 
  array (
    'type' => 'interface',
    'name' => 'ElementInterface',
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
          'name' => 'addFilter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 26,
              'char' => 44,
            ),
          ),
          'docblock' => '**
     * Adds a filter to current list of filters
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 26,
                  'char' => 67,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 26,
                'char' => 67,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 26,
            'char' => 67,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addValidator',
          'parameters' => 
          array (
            0 => 
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 31,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 31,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Adds a validator to the element
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 31,
                  'char' => 87,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 31,
                'char' => 87,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 31,
            'char' => 87,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 31,
          'last-line' => 37,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addValidators',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'validators',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 38,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 38,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 38,
              'char' => 71,
            ),
          ),
          'docblock' => '**
     * Adds a group of validators
     *
     * @param \\Phalcon\\Validation\\ValidatorInterface[]
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 38,
                  'char' => 94,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 38,
                'char' => 94,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 38,
            'char' => 94,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 38,
          'last-line' => 42,
          'char' => 19,
        ),
        3 => 
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 43,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 43,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Appends a message to the internal message list
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 43,
                  'char' => 84,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 43,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 43,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 43,
          'last-line' => 47,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
          'docblock' => '**
     * Clears every element in the form to its default value
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 48,
                  'char' => 50,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 48,
                'char' => 50,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 48,
            'char' => 50,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 48,
          'last-line' => 52,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attribute',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 53,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 53,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 53,
              'char' => 75,
            ),
          ),
          'docblock' => '**
     * Returns the value of an attribute if present
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 53,
                'char' => 83,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 53,
            'char' => 83,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 53,
          'last-line' => 57,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAttributes',
          'docblock' => '**
     * Returns the default attributes for the element
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 58,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 58,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 58,
          'last-line' => 62,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefault',
          'docblock' => '**
     * Returns the default value assigned to the element
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 63,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 63,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 63,
          'last-line' => 69,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFilters',
          'docblock' => '**
     * Returns the element\'s filters
     *
     * @return mixed
     *',
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 70,
          'last-line' => 74,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getForm',
          'docblock' => '**
     * Returns the parent form to the element
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
                  'value' => 'Form',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 75,
                  'char' => 40,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 75,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 75,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 75,
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
          'name' => 'getLabel',
          'docblock' => '**
     * Returns the element\'s label
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 80,
                'char' => 41,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 80,
            'char' => 41,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 80,
          'last-line' => 85,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'docblock' => '**
     * Returns the messages that belongs to the element
     * The element needs to be attached to a form
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
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 86,
                  'char' => 48,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 86,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 86,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 86,
          'last-line' => 90,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getName',
          'docblock' => '**
     * Returns the element\'s name
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 91,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 91,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 91,
          'last-line' => 95,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getUserOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'option',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 96,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 96,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 96,
              'char' => 73,
            ),
          ),
          'docblock' => '**
     * Returns the value of an option if present
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 96,
                'char' => 81,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 96,
            'char' => 81,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 96,
          'last-line' => 100,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getUserOptions',
          'docblock' => '**
     * Returns the options for the element
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 101,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 101,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 101,
          'last-line' => 105,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValidators',
          'docblock' => '**
     * Returns the validators registered for the element
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
                  'value' => 'ValidatorInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 106,
                  'char' => 62,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 106,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 106,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 106,
          'last-line' => 110,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValue',
          'docblock' => '**
     * Returns the element\'s value
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 111,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 111,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 111,
          'last-line' => 115,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasMessages',
          'docblock' => '**
     * Checks whether there are messages attached to the element
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 116,
                'char' => 42,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 116,
            'char' => 42,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 116,
          'last-line' => 120,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'label',
          'docblock' => '**
     * Generate the HTML to label the element
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 121,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 121,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 121,
          'last-line' => 126,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'prepareAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 127,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 127,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'useChecked',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 127,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 127,
              'char' => 85,
            ),
          ),
          'docblock' => '**
     * Returns an array of prepared attributes for Phalcon\\Tag helpers
     * according to the element\'s parameters
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 127,
                'char' => 95,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 127,
            'char' => 95,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 127,
          'last-line' => 131,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'render',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 132,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 132,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Renders the element widget
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
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 132,
                'char' => 60,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 132,
            'char' => 60,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 132,
          'last-line' => 136,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attribute',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 137,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 137,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Sets a default attribute for the element
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 137,
                  'char' => 84,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 137,
                'char' => 84,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 137,
            'char' => 84,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 137,
          'last-line' => 141,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 142,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Sets default attributes for the element
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 142,
                  'char' => 75,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 142,
                'char' => 75,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 142,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 142,
          'last-line' => 147,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefault',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 148,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets a default value in case the form does not use an entity
     * or there is no value available for the element in _POST
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 148,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 148,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 148,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 148,
          'last-line' => 154,
          'char' => 19,
        ),
        24 => 
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
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 155,
              'char' => 39,
            ),
          ),
          'docblock' => '**
     * Sets the element\'s filters
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 155,
                  'char' => 62,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 155,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 155,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 155,
          'last-line' => 159,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setForm',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'form',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Form',
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 160,
                'char' => 39,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 160,
              'char' => 40,
            ),
          ),
          'docblock' => '**
     * Sets the parent form to the element
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 160,
                  'char' => 63,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 160,
                'char' => 63,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 160,
            'char' => 63,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 160,
          'last-line' => 164,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setLabel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'label',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 165,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Sets the element label
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 165,
                  'char' => 65,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 165,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 165,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 165,
          'last-line' => 169,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setMessages',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'messages',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Messages',
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 170,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 170,
              'char' => 52,
            ),
          ),
          'docblock' => '**
     * Sets the validation messages related to the element
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 170,
                  'char' => 75,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 170,
                'char' => 75,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 170,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 170,
          'last-line' => 174,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setName',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 175,
              'char' => 41,
            ),
          ),
          'docblock' => '**
     * Sets the element\'s name
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 175,
                  'char' => 64,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 175,
                'char' => 64,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 175,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 175,
          'last-line' => 179,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setUserOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'option',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 180,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 180,
              'char' => 59,
            ),
          ),
          'docblock' => '**
     * Sets an option for the element
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 180,
                  'char' => 82,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 180,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 180,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 180,
          'last-line' => 184,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setUserOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Forms/ElementInterface.zep',
              'line' => 185,
              'char' => 49,
            ),
          ),
          'docblock' => '**
     * Sets options for the element
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
                  'value' => 'ElementInterface',
                  'file' => '/app/phalcon/Forms/ElementInterface.zep',
                  'line' => 185,
                  'char' => 72,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Forms/ElementInterface.zep',
                'line' => 185,
                'char' => 72,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Forms/ElementInterface.zep',
            'line' => 185,
            'char' => 72,
          ),
          'file' => '/app/phalcon/Forms/ElementInterface.zep',
          'line' => 185,
          'last-line' => 186,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Forms/ElementInterface.zep',
      'line' => 186,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Forms/ElementInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);