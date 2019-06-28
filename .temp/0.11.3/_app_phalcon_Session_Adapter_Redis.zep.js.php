<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Session/Adapter/Redis.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Session\\Adapter',
    'file' => '/app/phalcon/Session/Adapter/Redis.zep',
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
        'name' => 'Phalcon\\Storage\\AdapterFactory',
        'file' => '/app/phalcon/Session/Adapter/Redis.zep',
        'line' => 13,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Session/Adapter/Redis.zep',
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
        'name' => 'Phalcon\\Session\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Session/Adapter/Redis.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Session/Adapter/Redis.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Session\\Adapter\\Redis
 *',
    'file' => '/app/phalcon/Session/Adapter/Redis.zep',
    'line' => 19,
    'char' => 6,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Redis',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
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
                'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                'line' => 24,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Redis.zep',
              'line' => 24,
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
                'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                'line' => 24,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Redis.zep',
              'line' => 24,
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
                      'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                      'line' => 26,
                      'char' => 27,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'sess-reds-',
                    'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                    'line' => 26,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                  'line' => 26,
                  'char' => 41,
                ),
                1 => 
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
                      'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                      'line' => 27,
                      'char' => 41,
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
                          'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                          'line' => 27,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                        'line' => 27,
                        'char' => 59,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                          'line' => 27,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                        'line' => 27,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                    'line' => 27,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Redis.zep',
                  'line' => 27,
                  'char' => 69,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Redis.zep',
              'line' => 28,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/Adapter/Redis.zep',
            'line' => 25,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Redis.zep',
          'line' => 24,
          'last-line' => 29,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Session/Adapter/Redis.zep',
      'line' => 19,
      'char' => 6,
    ),
    'file' => '/app/phalcon/Session/Adapter/Redis.zep',
    'line' => 19,
    'char' => 6,
  ),
);