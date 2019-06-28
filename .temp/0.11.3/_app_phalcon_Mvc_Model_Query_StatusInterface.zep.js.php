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
    'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Query',
    'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
        'line' => 13,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Query\\StatusInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Query\\Status
 *',
    'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
    'line' => 21,
    'char' => 9,
  ),
  5 => 
  array (
    'type' => 'interface',
    'name' => 'StatusInterface',
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
          'name' => 'getMessages',
          'docblock' => '**
     * Returns the messages produced by an operation failed
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
                  'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
                  'line' => 26,
                  'char' => 58,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
                'line' => 26,
                'char' => 58,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
            'line' => 26,
            'char' => 58,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
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
          'name' => 'getModel',
          'docblock' => '**
     * Returns the model which executed the action
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
                  'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
                  'line' => 31,
                  'char' => 51,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
                'line' => 31,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
            'line' => 31,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'success',
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
                'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
                'line' => 36,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
            'line' => 36,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
          'line' => 36,
          'last-line' => 37,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
      'line' => 37,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/Query/StatusInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);