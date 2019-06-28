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
    'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\MetaData',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
    'line' => 21,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\MetaData\\Memory
 *
 * Stores model meta-data in memory. Data will be erased when the request finishes
 *
 *',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
    'line' => 22,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Memory',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'MetaData',
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
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
                'line' => 29,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
              'line' => 29,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\MetaData\\Memory constructor
     *
     * @param array options
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
            'line' => 30,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
          'line' => 29,
          'last-line' => 35,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'read',
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
              'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
              'line' => 36,
              'char' => 37,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
                'line' => 38,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
              'line' => 39,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads the meta-data from temporal memory
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
                'line' => 36,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
                'line' => 37,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
            'line' => 37,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
          'line' => 36,
          'last-line' => 43,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'write',
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
              'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
              'line' => 44,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
              'line' => 44,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
              'line' => 47,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes the meta-data to temporal memory
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
            'line' => 45,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
          'line' => 44,
          'last-line' => 48,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
      'line' => 22,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Memory.zep',
    'line' => 22,
    'char' => 5,
  ),
);