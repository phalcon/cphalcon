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
    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\MetaData',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
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
        'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
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
        'name' => 'Phalcon\\Cache\\AdapterFactory',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
        'line' => 14,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
    'line' => 36,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\MetaData\\Redis
 *
 * Stores model meta-data in the Redis.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 *```php
 * use Phalcon\\Mvc\\Model\\MetaData\\Redis;
 *
 * $metaData = new Redis(
 *     [
 *         "host"       => "127.0.0.1",
 *         "port"       => 6379,
 *         "persistent" => 0,
 *         "lifetime"   => 172800,
 *         "index"      => 2,
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
    'line' => 37,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Redis',
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                'line' => 44,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
              'line' => 44,
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
                'type' => 'empty-array',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                'line' => 44,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
              'line' => 44,
              'char' => 78,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                      'line' => 46,
                      'char' => 27,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'ph-mm-reds-',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                    'line' => 46,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                  'line' => 46,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                      'line' => 47,
                      'char' => 29,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '172800',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                    'line' => 47,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                  'line' => 47,
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
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                      'line' => 48,
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
                          'value' => 'redis',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                          'line' => 48,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                        'line' => 48,
                        'char' => 61,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                          'line' => 48,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                        'line' => 48,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                    'line' => 48,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                  'line' => 48,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
              'line' => 49,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\MetaData\\Redis constructor
     *
     * @param array options
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
            'line' => 45,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
          'line' => 44,
          'last-line' => 53,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                    'line' => 56,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                    'line' => 56,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                  'line' => 56,
                  'char' => 23,
                ),
                'name' => 'clear',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                'line' => 56,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
              'line' => 58,
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
                'name' => 'reset',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
                'line' => 58,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
              'line' => 59,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Flush Redis data and resets internal meta-data in order to regenerate it
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
            'line' => 55,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
          'line' => 54,
          'last-line' => 60,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
      'line' => 37,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Redis.zep',
    'line' => 37,
    'char' => 5,
  ),
);