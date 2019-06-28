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
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
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
        'name' => 'ArrayAccess',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
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
        'name' => 'JsonSerializable',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 14,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 15,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
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
        'name' => 'Phalcon\\Mvc\\EntityInterface',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 16,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\ResultInterface',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 18,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
    'line' => 25,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Row
 *
 * This component allows Phalcon\\Mvc\\Model to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 *',
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
    'line' => 26,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Row',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'EntityInterface',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 26,
        'char' => 37,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'ResultInterface',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 26,
        'char' => 54,
      ),
      2 => 
      array (
        'type' => 'variable',
        'value' => 'ArrayAccess',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 26,
        'char' => 67,
      ),
      3 => 
      array (
        'type' => 'variable',
        'value' => 'JsonSerializable',
        'file' => '/app/phalcon/Mvc/Model/Row.zep',
        'line' => 27,
        'char' => 1,
      ),
    ),
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
          'name' => 'jsonSerialize',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 33,
                  'char' => 21,
                ),
                'name' => 'toArray',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 33,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 34,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Serializes the object for json_encode
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
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 32,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Row.zep',
            'line' => 32,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 31,
          'last-line' => 42,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetGet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 43,
              'char' => 40,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 45,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 47,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Mvc/Model/Row.zep',
                      'line' => 47,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-dynamic-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Row.zep',
                        'line' => 47,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'index',
                        'file' => '/app/phalcon/Mvc/Model/Row.zep',
                        'line' => 47,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Row.zep',
                      'line' => 47,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 47,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 47,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 47,
                'char' => 49,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'The index does not exist in the row',
                          'file' => '/app/phalcon/Mvc/Model/Row.zep',
                          'line' => 48,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Row.zep',
                        'line' => 48,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 48,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 49,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 51,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 51,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 52,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets a record in a specific position of the row
     *
     * @param string|int index
     *
     * @return string|Phalcon\\Mvc\\ModelInterface
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
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 44,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Row.zep',
            'line' => 44,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 43,
          'last-line' => 58,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetExists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 59,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'property-dynamic-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 61,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 61,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 61,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 61,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 62,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether offset exists in the row
     *
     * @param string|int $index
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
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 60,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Row.zep',
            'line' => 60,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 59,
          'last-line' => 69,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetSet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 70,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 70,
              'char' => 51,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'throw',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Exception',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Row is an immutable ArrayAccess object',
                      'file' => '/app/phalcon/Mvc/Model/Row.zep',
                      'line' => 72,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 72,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 72,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     *
     * @param string|int index
     * @param \\Phalcon\\Mvc\\ModelInterface value
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Row.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 70,
          'last-line' => 79,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'offsetUnset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'offset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 80,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'throw',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Exception',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'Row is an immutable ArrayAccess object',
                      'file' => '/app/phalcon/Mvc/Model/Row.zep',
                      'line' => 82,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 82,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 82,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 83,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     *
     * @param string|int offset
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Row.zep',
            'line' => 81,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 80,
          'last-line' => 93,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'readAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attribute',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 94,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 96,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 98,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 98,
                    'char' => 44,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-dynamic-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Row.zep',
                      'line' => 98,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attribute',
                      'file' => '/app/phalcon/Mvc/Model/Row.zep',
                      'line' => 98,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 98,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 98,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 98,
                'char' => 44,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 99,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 100,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 102,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 102,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads an attribute value by its name
     *
     *```php
     * echo $robot->readAttribute("name");
     *```
     *
     * @return mixed
     *',
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 94,
          'last-line' => 107,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 108,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 110,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 111,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the current object\'s state
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
                  'value' => 'ModelInterface',
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 108,
                  'char' => 71,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 108,
                'char' => 71,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Row.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 108,
          'last-line' => 115,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'toArray',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'get_object_vars',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Row.zep',
                      'line' => 118,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 118,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 118,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 119,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the instance as an array representation
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
                'file' => '/app/phalcon/Mvc/Model/Row.zep',
                'line' => 117,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Row.zep',
            'line' => 117,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 116,
          'last-line' => 129,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'writeAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attribute',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 130,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 130,
              'char' => 60,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable-dynamic-object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'attribute',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/Model/Row.zep',
                    'line' => 132,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Row.zep',
                  'line' => 132,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Row.zep',
              'line' => 133,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes an attribute value by its name
     *
     *```php
     * $robot->writeAttribute("name", "Rosey");
     *```
     *
     * @param mixed value
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Row.zep',
            'line' => 131,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Row.zep',
          'line' => 130,
          'last-line' => 134,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Row.zep',
      'line' => 26,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Row.zep',
    'line' => 26,
    'char' => 5,
  ),
);