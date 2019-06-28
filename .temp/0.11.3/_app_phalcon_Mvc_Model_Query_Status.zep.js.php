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
    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Query',
    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
        'line' => 13,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Query\\StatusInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
        'line' => 15,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
    'line' => 43,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Query\\Status
 *
 * This class represents the status returned by a PHQL
 * statement like INSERT, UPDATE or DELETE. It offers context
 * information and the related messages produced by the
 * model which finally executes the operations when it fails
 *
 *```php
 * $phql = "UPDATE Robots SET name = :name:, type = :type:, year = :year: WHERE id = :id:";
 *
 * $status = $app->modelsManager->executeQuery(
 *     $phql,
 *     [
 *         "id"   => 100,
 *         "name" => "Astroy Boy",
 *         "type" => "mechanical",
 *         "year" => 1959,
 *     ]
 * );
 *
 * // Check if the update was successful
 * if ($status->success()) {
 *     echo "OK";
 * }
 *```
 *',
    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
    'line' => 44,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Status',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'StatusInterface',
        'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
        'line' => 45,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'model',
          'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
          'line' => 48,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'success',
          'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
          'line' => 52,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'success',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 53,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 53,
                'char' => 68,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 53,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 53,
              'char' => 76,
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'success',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'success',
                    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                    'line' => 55,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 55,
                  'char' => 36,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'model',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'model',
                    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                    'line' => 56,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 56,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 57,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Query\\Status
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
            'line' => 54,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
          'line' => 53,
          'last-line' => 61,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
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
                  'variable' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 64,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 66,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'model',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                      'line' => 66,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'model',
                      'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                      'line' => 66,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                    'line' => 66,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 66,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 68,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'model',
                    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                    'line' => 68,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 68,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 68,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 68,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                    'line' => 69,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 70,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 72,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 72,
                  'char' => 22,
                ),
                'name' => 'getMessages',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 72,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the messages produced because of a failed operation
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 63,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
          'line' => 62,
          'last-line' => 77,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getModel',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 80,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 80,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 80,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the model that executed the action
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
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 79,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 79,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
          'line' => 78,
          'last-line' => 85,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'success',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 88,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'success',
                  'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                  'line' => 88,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 88,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
              'line' => 89,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Allows to check if the executed operation was successful
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
                'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
                'line' => 87,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
            'line' => 87,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
          'line' => 86,
          'last-line' => 90,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
      'line' => 44,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/Status.zep',
    'line' => 44,
    'char' => 5,
  ),
);