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
    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\MetaData',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
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
        'name' => 'Phalcon\\Cache\\AdapterFactory',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
        'line' => 15,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
    'line' => 34,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\MetaData\\Apcu
 *
 * Stores model meta-data in the APCu cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apcu_fetch(\'$PMM$\') or apcu_fetch(\'$PMM$my-app-id\')
 *
 *```php
 * $metaData = new \\Phalcon\\Mvc\\Model\\MetaData\\Apcu(
 *     [
 *         "prefix"   => "my-app-id",
 *         "lifetime" => 86400,
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
    'line' => 35,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Apcu',
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
              'name' => 'factory',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterFactory',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                'line' => 42,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
              'line' => 42,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                'line' => 42,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
              'line' => 42,
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
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'prefix',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                      'line' => 44,
                      'char' => 27,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'ph-mm-apcu-',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                    'line' => 44,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                  'line' => 44,
                  'char' => 44,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'lifetime',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                      'line' => 45,
                      'char' => 29,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '172800',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                    'line' => 45,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                  'line' => 45,
                  'char' => 39,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'adapter',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'factory',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                      'line' => 46,
                      'char' => 43,
                    ),
                    'name' => 'newInstance',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'apcu',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                          'line' => 46,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                        'line' => 46,
                        'char' => 60,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                          'line' => 46,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                        'line' => 46,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                    'line' => 46,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
                  'line' => 46,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
              'line' => 47,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\MetaData\\Apcu constructor
     *
     * @param array options
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
            'line' => 43,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
          'line' => 42,
          'last-line' => 48,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
      'line' => 35,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Apcu.zep',
    'line' => 35,
    'char' => 5,
  ),
);