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
    'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Validation',
    'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
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
        'name' => 'Phalcon\\Collection',
        'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
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
        'name' => 'Phalcon\\Validation\\Validation',
        'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
        'line' => 14,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Validation\\AbstractValidator
 *',
    'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
    'line' => 19,
    'char' => 9,
  ),
  5 => 
  array (
    'type' => 'interface',
    'name' => 'ValidatorInterface',
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
          'name' => 'getOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
              'line' => 27,
              'char' => 42,
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
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 27,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
              'line' => 27,
              'char' => 67,
            ),
          ),
          'docblock' => '**
     * Returns an option in the validator\'s options
     * Returns null if the option hasn\'t set
     *
     * @return mixed
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
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 27,
                'char' => 75,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
            'line' => 27,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
          'line' => 27,
          'last-line' => 33,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasOption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
              'line' => 34,
              'char' => 42,
            ),
          ),
          'docblock' => '**
     * Checks if an option is defined
     *
     * @return boolean
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
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 34,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
            'line' => 34,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
          'line' => 34,
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
          'name' => 'validate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'validation',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Validation',
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 41,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
              'line' => 41,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'field',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
              'line' => 41,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Executes the validation
     *
     * @return boolean
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
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 41,
                'char' => 73,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
            'line' => 41,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
          'line' => 41,
          'last-line' => 48,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTemplate',
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
              'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
              'line' => 49,
              'char' => 46,
            ),
          ),
          'docblock' => '**
    * Get the template message
    *
    * @return string
    * @throw InvalidArgumentException When the field does not exists
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
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 49,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
            'line' => 49,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
          'line' => 49,
          'last-line' => 55,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTemplates',
          'docblock' => '**
    * Get message templates
    *
    * @return array
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
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 56,
                'char' => 44,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
            'line' => 56,
            'char' => 44,
          ),
          'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
          'line' => 56,
          'last-line' => 62,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTemplates',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'templates',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
              'line' => 63,
              'char' => 50,
            ),
          ),
          'docblock' => '**
    * Clear current template and set new from an array,
    *
    * @return ValidatorInterface
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
                  'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                  'line' => 63,
                  'char' => 75,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 63,
                'char' => 75,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
            'line' => 63,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
          'line' => 63,
          'last-line' => 69,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTemplate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'template',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
              'line' => 70,
              'char' => 49,
            ),
          ),
          'docblock' => '**
    * Set a new temlate message
    *
    * @return ValidatorInterface
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
                  'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                  'line' => 70,
                  'char' => 74,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
                'line' => 70,
                'char' => 74,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
            'line' => 70,
            'char' => 74,
          ),
          'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
          'line' => 70,
          'last-line' => 71,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
      'line' => 71,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Validation/ValidatorInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);