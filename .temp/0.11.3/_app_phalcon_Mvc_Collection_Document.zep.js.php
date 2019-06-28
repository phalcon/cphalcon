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
    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Collection',
    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
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
        'file' => '/app/phalcon/Mvc/Collection/Document.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
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
        'name' => 'Phalcon\\Mvc\\EntityInterface',
        'file' => '/app/phalcon/Mvc/Collection/Document.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
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
        'name' => 'Phalcon\\Mvc\\Collection\\Exception',
        'file' => '/app/phalcon/Mvc/Collection/Document.zep',
        'line' => 15,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
    'line' => 22,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Collection\\Document
 *
 * This component allows Phalcon\\Mvc\\Collection to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 *',
    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
    'line' => 23,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Document',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'EntityInterface',
        'file' => '/app/phalcon/Mvc/Collection/Document.zep',
        'line' => 23,
        'char' => 42,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'ArrayAccess',
        'file' => '/app/phalcon/Mvc/Collection/Document.zep',
        'line' => 24,
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
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 28,
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
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 30,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 32,
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
                      'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                      'line' => 32,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-dynamic-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                        'line' => 32,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'index',
                        'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                        'line' => 32,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                      'line' => 32,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 32,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 32,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 32,
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
                          'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                          'line' => 33,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                        'line' => 33,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 33,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 34,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 36,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 36,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 37,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the value of a field using the ArrayAccess interfase
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
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 29,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/Document.zep',
            'line' => 29,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Collection/Document.zep',
          'line' => 28,
          'last-line' => 41,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 42,
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
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 44,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 44,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 44,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 44,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 45,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether an offset exists in the document
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
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 43,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/Document.zep',
            'line' => 43,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Collection/Document.zep',
          'line' => 42,
          'last-line' => 49,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 50,
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
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 50,
              'char' => 47,
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
                  'property' => 'index',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 52,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 52,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 53,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Change a value using the ArrayAccess interface
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Collection/Document.zep',
            'line' => 51,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Collection/Document.zep',
          'line' => 50,
          'last-line' => 57,
          'char' => 19,
        ),
        3 => 
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
              'name' => 'index',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 58,
              'char' => 42,
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
                      'value' => 'The index does not exist in the row',
                      'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                      'line' => 60,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 60,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 60,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Collection/Document.zep',
            'line' => 59,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Collection/Document.zep',
          'line' => 58,
          'last-line' => 69,
          'char' => 19,
        ),
        4 => 
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
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 70,
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
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 72,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 74,
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
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 74,
                    'char' => 44,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-dynamic-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                      'line' => 74,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'attribute',
                      'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                      'line' => 74,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 74,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 74,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 74,
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
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 75,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 78,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 78,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 79,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads an attribute value by its name
     *
     *```php
     *  echo $robot->readAttribute("name");
     *```
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
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 70,
                'char' => 61,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 71,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/Document.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Collection/Document.zep',
          'line' => 70,
          'last-line' => 83,
          'char' => 19,
        ),
        5 => 
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
                      'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                      'line' => 86,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 86,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 86,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 87,
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
                'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                'line' => 85,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Collection/Document.zep',
            'line' => 85,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Collection/Document.zep',
          'line' => 84,
          'last-line' => 95,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 96,
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
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 96,
              'char' => 64,
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
                    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                    'line' => 98,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Collection/Document.zep',
                  'line' => 98,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Collection/Document.zep',
              'line' => 99,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes an attribute value by its name
     *
     *```php
     *  $robot->writeAttribute("name", "Rosey");
     *```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Collection/Document.zep',
            'line' => 97,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Collection/Document.zep',
          'line' => 96,
          'last-line' => 100,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Collection/Document.zep',
      'line' => 23,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Collection/Document.zep',
    'line' => 23,
    'char' => 5,
  ),
);