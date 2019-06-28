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
    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Transaction',
    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
        'line' => 13,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Transaction\\Exception',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
        'line' => 15,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
    'line' => 21,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Transaction\\Failed
 *
 * This class will be thrown to exit a try/catch block for isolated transactions
 *',
    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
    'line' => 22,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Failed',
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
          'name' => 'record',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
            'line' => 24,
            'char' => 28,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
          'line' => 28,
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
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 29,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                'line' => 29,
                'char' => 72,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                'line' => 29,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 29,
              'char' => 80,
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
                  'property' => 'record',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'record',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                    'line' => 31,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 31,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 33,
              'char' => 14,
            ),
            1 => 
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
                      'value' => 'message',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                      'line' => 33,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                    'line' => 33,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                'line' => 33,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 34,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Transaction\\Failed constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
            'line' => 30,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
          'line' => 29,
          'last-line' => 38,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRecord',
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 41,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'record',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 41,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                'line' => 41,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 42,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns validation record messages which stop the transaction
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 40,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                'line' => 40,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
            'line' => 40,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
          'line' => 39,
          'last-line' => 46,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRecordMessages',
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
                  'variable' => 'record',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 49,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 51,
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
                  'variable' => 'record',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                      'line' => 51,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'record',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                      'line' => 51,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                    'line' => 51,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 51,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 53,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'record',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 53,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 53,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                'line' => 53,
                'char' => 28,
              ),
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
                      'value' => 'record',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                      'line' => 54,
                      'char' => 27,
                    ),
                    'name' => 'getMessages',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                    'line' => 54,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 55,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 57,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 57,
                  'char' => 21,
                ),
                'name' => 'getMessage',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                'line' => 57,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
              'line' => 58,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns validation record messages which stop the transaction
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                  'line' => 48,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
                'line' => 48,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
            'line' => 48,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
          'line' => 47,
          'last-line' => 59,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
      'line' => 22,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Failed.zep',
    'line' => 22,
    'char' => 5,
  ),
);