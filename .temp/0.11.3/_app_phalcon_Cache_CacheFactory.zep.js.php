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
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cache',
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Cache/CacheFactory.zep',
        'line' => 13,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
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
        'file' => '/app/phalcon/Cache/CacheFactory.zep',
        'line' => 14,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
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
        'name' => 'Phalcon\\Cache\\Cache',
        'file' => '/app/phalcon/Cache/CacheFactory.zep',
        'line' => 15,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
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
        'name' => 'Phalcon\\Cache\\CacheInterface',
        'file' => '/app/phalcon/Cache/CacheFactory.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
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
        'name' => 'Phalcon\\Cache\\Exception\\Exception',
        'file' => '/app/phalcon/Cache/CacheFactory.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
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
        'name' => 'Phalcon\\Config\\Config',
        'file' => '/app/phalcon/Cache/CacheFactory.zep',
        'line' => 18,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Factory\\AbstractFactory',
        'file' => '/app/phalcon/Cache/CacheFactory.zep',
        'line' => 19,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
    'line' => 20,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Cache/CacheFactory.zep',
        'line' => 20,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
    'line' => 24,
    'char' => 2,
  ),
  10 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Creates a new Cache class
 *',
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
    'line' => 25,
    'char' => 5,
  ),
  11 => 
  array (
    'type' => 'class',
    'name' => 'CacheFactory',
    'abstract' => 0,
    'final' => 0,
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
          'name' => 'adapterFactory',
          'docblock' => '**
     * @var AdapterFactory
     *',
          'file' => '/app/phalcon/Cache/CacheFactory.zep',
          'line' => 34,
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
              'name' => 'factory',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterFactory',
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 35,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 35,
              'char' => 57,
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
                  'property' => 'adapterFactory',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'factory',
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 37,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 37,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 38,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'file' => '/app/phalcon/Cache/CacheFactory.zep',
          'line' => 35,
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
          'name' => 'load',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'config',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 43,
              'char' => 36,
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 45,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 45,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 47,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 47,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 47,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 47,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 47,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'instanceof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'config',
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 47,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'Config',
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 47,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 47,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 47,
                'char' => 64,
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
                      'variable' => 'config',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'config',
                          'file' => '/app/phalcon/Cache/CacheFactory.zep',
                          'line' => 48,
                          'char' => 33,
                        ),
                        'name' => 'toArray',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 48,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 48,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 49,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 51,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 51,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 51,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 51,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 51,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 51,
                'char' => 45,
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
                          'value' => 'Config must be array or Phalcon\\\\Config object',
                          'file' => '/app/phalcon/Cache/CacheFactory.zep',
                          'line' => 54,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 54,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 54,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 55,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 57,
              'char' => 10,
            ),
            3 => 
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
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'config',
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 57,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'adapter',
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 57,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 57,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 57,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 57,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 57,
                'char' => 44,
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
                          'value' => 'You must provide \'adapter\' option in factory config parameter.',
                          'file' => '/app/phalcon/Cache/CacheFactory.zep',
                          'line' => 60,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 60,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 60,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 61,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 63,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 63,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'adapter',
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 63,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 63,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 63,
                  'char' => 38,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Arr',
                    'dynamic' => 0,
                    'name' => 'get',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'config',
                          'file' => '/app/phalcon/Cache/CacheFactory.zep',
                          'line' => 64,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 64,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'options',
                          'file' => '/app/phalcon/Cache/CacheFactory.zep',
                          'line' => 64,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 64,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Cache/CacheFactory.zep',
                          'line' => 64,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 64,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 64,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 64,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 66,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 66,
                  'char' => 21,
                ),
                'name' => 'newInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 66,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 66,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 66,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 66,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 66,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 67,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Factory to create an instace from a Config object
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
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 44,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/CacheFactory.zep',
            'line' => 44,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/CacheFactory.zep',
          'line' => 43,
          'last-line' => 71,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'newInstance',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 72,
              'char' => 45,
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
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 72,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 72,
              'char' => 66,
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
                  'variable' => 'adapter',
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 74,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 76,
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
                  'variable' => 'adapter',
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
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 76,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'adapterFactory',
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 76,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 76,
                      'char' => 44,
                    ),
                    'name' => 'newInstance',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Cache/CacheFactory.zep',
                          'line' => 76,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 76,
                        'char' => 61,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Cache/CacheFactory.zep',
                          'line' => 76,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Cache/CacheFactory.zep',
                        'line' => 76,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 76,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 76,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 78,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Cache',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapter',
                      'file' => '/app/phalcon/Cache/CacheFactory.zep',
                      'line' => 78,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Cache/CacheFactory.zep',
                    'line' => 78,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 78,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Cache/CacheFactory.zep',
              'line' => 79,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructs a new Cache instance.
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
                  'value' => 'CacheInterface',
                  'file' => '/app/phalcon/Cache/CacheFactory.zep',
                  'line' => 73,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cache/CacheFactory.zep',
                'line' => 73,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/CacheFactory.zep',
            'line' => 73,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/CacheFactory.zep',
          'line' => 72,
          'last-line' => 80,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Cache/CacheFactory.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Cache/CacheFactory.zep',
    'line' => 25,
    'char' => 5,
  ),
);