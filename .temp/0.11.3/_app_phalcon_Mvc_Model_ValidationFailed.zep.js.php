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
    'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
    'line' => 20,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\ValidationFailed
 *
 * This exception is generated when a model fails to save a record
 * Phalcon\\Mvc\\Model must be set up to have this behavior
 *',
    'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
    'line' => 21,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'ValidationFailed',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Exception',
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
          'name' => 'messages',
          'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
          'line' => 25,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'model',
          'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
          'line' => 31,
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
              'name' => 'model',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                'line' => 32,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 32,
              'char' => 55,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'validationMessages',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 32,
              'char' => 82,
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
                  'variable' => 'messageStr',
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 34,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'message',
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 34,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 36,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'count',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'validationMessages',
                        'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                        'line' => 36,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                      'line' => 36,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 36,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 36,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                'line' => 36,
                'char' => 42,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'message',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'validationMessages',
                          'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                          'line' => 40,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                          'line' => 40,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                        'line' => 40,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                      'line' => 40,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 45,
                  'char' => 15,
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
                      'variable' => 'messageStr',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                          'line' => 45,
                          'char' => 38,
                        ),
                        'name' => 'getMessage',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                        'line' => 45,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                      'line' => 45,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 46,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'messageStr',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'Validation failed',
                        'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                        'line' => 47,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                      'line' => 47,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 48,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 50,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'model',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'model',
                    'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                    'line' => 50,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 50,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 51,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'validationMessages',
                    'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                    'line' => 51,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 51,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 53,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'messageStr',
                      'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                      'line' => 53,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                    'line' => 53,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                'line' => 53,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 54,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\ValidationFailed constructor
     *
     * @param Message[] validationMessages
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
          'line' => 32,
          'last-line' => 58,
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
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 61,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'messages',
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 61,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                'line' => 61,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 62,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the complete group of messages produced in the validation
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
                  'value' => 'Message',
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 60,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                'line' => 60,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
            'line' => 60,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
          'line' => 59,
          'last-line' => 66,
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
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 69,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'model',
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 69,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                'line' => 69,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
              'line' => 70,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the model that generated the messages
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
                  'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                  'line' => 68,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
                'line' => 68,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
            'line' => 68,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
          'line' => 67,
          'last-line' => 71,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/ValidationFailed.zep',
    'line' => 21,
    'char' => 5,
  ),
);