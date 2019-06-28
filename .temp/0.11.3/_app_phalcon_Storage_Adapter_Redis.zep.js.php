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
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Adapter',
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
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
        'name' => 'Phalcon\\Storage\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
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
        'name' => 'Phalcon\\Storage\\Exception',
        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
        'line' => 15,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
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
        'name' => 'Phalcon\\Storage\\SerializerFactory',
        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
        'line' => 16,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
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
        'name' => 'Phalcon\\Storage\\Serializer\\SerializerInterface',
        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
        'line' => 17,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
    'line' => 23,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Storage\\Adapter\\Redis
 *
 * Redis adapter
 *',
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
    'line' => 24,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Redis',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
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
          'name' => 'options',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 29,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 33,
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
                'value' => 'SerializerFactory',
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 34,
                'char' => 59,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 34,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 34,
              'char' => 67,
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
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 34,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 34,
              'char' => 88,
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
                      'value' => 'host',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 39,
                      'char' => 25,
                    ),
                  ),
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
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 39,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 39,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'host',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 39,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 39,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '127.0.0.1',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 39,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 39,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 39,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 39,
                  'char' => 69,
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
                      'value' => 'port',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 40,
                      'char' => 25,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
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
                            'value' => 'options',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 40,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 40,
                          'char' => 57,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'port',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 40,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 40,
                          'char' => 63,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'int',
                            'value' => '6379',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 40,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 40,
                          'char' => 69,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 40,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 40,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 40,
                  'char' => 70,
                ),
                2 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'index',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 41,
                      'char' => 26,
                    ),
                  ),
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
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 41,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 41,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'index',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 41,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 41,
                        'char' => 58,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 41,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 41,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 41,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 41,
                  'char' => 62,
                ),
                3 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'persistent',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 42,
                      'char' => 31,
                    ),
                  ),
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
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 42,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 42,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'persistent',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 42,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 42,
                        'char' => 63,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 42,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 42,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 42,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 42,
                  'char' => 71,
                ),
                4 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'auth',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 43,
                      'char' => 25,
                    ),
                  ),
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
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 43,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 43,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'auth',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 43,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 43,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 43,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 43,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 43,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 43,
                  'char' => 60,
                ),
                5 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'socket',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 44,
                      'char' => 27,
                    ),
                  ),
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
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 44,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 44,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'socket',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 44,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 44,
                        'char' => 59,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 44,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 44,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 44,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 44,
                  'char' => 62,
                ),
                6 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'ph-reds-',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 45,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 45,
                  'char' => 45,
                ),
                7 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 46,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 46,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 48,
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
                      'value' => 'factory',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 48,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 48,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 48,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 48,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 48,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 49,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 34,
          'last-line' => 56,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 59,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 59,
                  'char' => 35,
                ),
                'name' => 'flushDB',
                'call-type' => 1,
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 59,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 60,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Flushes/clears the cache
     *
     * @return bool
     * @throws Exception
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
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 58,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 58,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 57,
          'last-line' => 70,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'decrement',
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
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 71,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 71,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 71,
              'char' => 57,
            ),
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 73,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 73,
                  'char' => 35,
                ),
                'name' => 'decrBy',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 73,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 73,
                    'char' => 46,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 73,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 73,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 73,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 74,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Decrements a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     * @throws Exception
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 71,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 72,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 72,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 71,
          'last-line' => 83,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'delete',
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
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 84,
              'char' => 39,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'cast',
                'left' => 'bool',
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 86,
                      'char' => 28,
                    ),
                    'name' => 'getAdapter',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 86,
                    'char' => 42,
                  ),
                  'name' => 'delete',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 86,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 86,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 86,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 86,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 87,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads data from the adapter
     *
     * @param string $key
     *
     * @return bool
     * @throws Exception
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
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 85,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 85,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 84,
          'last-line' => 97,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'get',
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
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 98,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 98,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 98,
              'char' => 61,
            ),
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 100,
                  'char' => 21,
                ),
                'name' => 'getUnserializedData',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 101,
                          'char' => 18,
                        ),
                        'name' => 'getAdapter',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 101,
                        'char' => 32,
                      ),
                      'name' => 'get',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 101,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 101,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 101,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 101,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 103,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 103,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 103,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 104,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads data from the adapter
     *
     * @param string $key
     * @param null   $defaultValue
     *
     * @return mixed
     * @throws Exception
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
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 99,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 99,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 98,
          'last-line' => 112,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAdapter',
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
                  'variable' => 'auth',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 115,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 115,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'host',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 115,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'index',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 115,
                  'char' => 42,
                ),
                4 => 
                array (
                  'variable' => 'method',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 115,
                  'char' => 50,
                ),
                5 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 115,
                  'char' => 59,
                ),
                6 => 
                array (
                  'variable' => 'persistent',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 116,
                  'char' => 23,
                ),
                7 => 
                array (
                  'variable' => 'port',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 116,
                  'char' => 29,
                ),
                8 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 116,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 118,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 118,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 118,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 118,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 118,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 118,
                'char' => 35,
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
                      'variable' => 'options',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 119,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 119,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 119,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 119,
                      'char' => 43,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'connection',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => '\\Redis',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 120,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 120,
                      'char' => 42,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'auth',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 121,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'auth',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 121,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 121,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 121,
                      'char' => 43,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'host',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 122,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'host',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 122,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 122,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 122,
                      'char' => 43,
                    ),
                    4 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'index',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 123,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'index',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 123,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 123,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 123,
                      'char' => 44,
                    ),
                    5 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'persistent',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 124,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'persistent',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 124,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 124,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 124,
                      'char' => 49,
                    ),
                    6 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'port',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 125,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'port',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 125,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 125,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 125,
                      'char' => 43,
                    ),
                    7 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'method',
                      'expr' => 
                      array (
                        'type' => 'ternary',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'persistent',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 126,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'pconnect',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 126,
                          'char' => 52,
                        ),
                        'extra' => 
                        array (
                          'type' => 'string',
                          'value' => 'connect',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 126,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 126,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 126,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 128,
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
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'connection',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 128,
                          'char' => 37,
                        ),
                        'name' => 'method',
                        'call-type' => 2,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'host',
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 128,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 128,
                            'char' => 51,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'port',
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 128,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 128,
                            'char' => 57,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                'line' => 128,
                                'char' => 64,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'lifetime',
                                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                'line' => 128,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 128,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 128,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 128,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 128,
                      'char' => 74,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 130,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'result',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 130,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 130,
                    'char' => 24,
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
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'Could not connect to the Redisd server [',
                                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                      'line' => 132,
                                      'char' => 62,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'host',
                                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                      'line' => 132,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                    'line' => 132,
                                    'char' => 69,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ':',
                                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                    'line' => 132,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                  'line' => 132,
                                  'char' => 73,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'port',
                                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                  'line' => 132,
                                  'char' => 80,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                'line' => 132,
                                'char' => 80,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => ']',
                                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                                'line' => 133,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 133,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 133,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 133,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 134,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 136,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'auth',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 136,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 136,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 136,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'connection',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 136,
                          'char' => 43,
                        ),
                        'name' => 'auth',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'auth',
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 136,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 136,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 136,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 136,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 136,
                    'char' => 55,
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
                              'value' => 'Failed to authenticate with the Redis server',
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 137,
                              'char' => 81,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 137,
                            'char' => 81,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 137,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 138,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 140,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'greater',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'index',
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 140,
                        'char' => 22,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 140,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 140,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'connection',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 140,
                          'char' => 41,
                        ),
                        'name' => 'select',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'index',
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 140,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 140,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 140,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 140,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 140,
                    'char' => 56,
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
                              'value' => 'Redis server selected database failed',
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 141,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 141,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 141,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 142,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 144,
                  'char' => 22,
                ),
                5 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'connection',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 144,
                      'char' => 24,
                    ),
                    'name' => 'setOption',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Redis',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 144,
                            'char' => 53,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'OPT_PREFIX',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 144,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 144,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 144,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 144,
                            'char' => 60,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'prefix',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 144,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 144,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 144,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 144,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 146,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 146,
                      'char' => 18,
                    ),
                    'name' => 'setSerializer',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'connection',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 146,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 146,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 146,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 147,
                  'char' => 15,
                ),
                7 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'adapter',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'connection',
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 147,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 147,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 148,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 150,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 150,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'adapter',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 150,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 150,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 151,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     *
     * @return mixed|\\Redis
     * @throws Exception
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
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 113,
          'last-line' => 158,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getKeys',
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 161,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 161,
                  'char' => 35,
                ),
                'name' => 'getKeys',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '*',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 161,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 161,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 161,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 162,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stores data in the adapter
     *
     * @return array
     * @throws Exception
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
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 160,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 160,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 159,
          'last-line' => 171,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
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
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 172,
              'char' => 36,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'cast',
                'left' => 'bool',
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 174,
                      'char' => 28,
                    ),
                    'name' => 'getAdapter',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 174,
                    'char' => 42,
                  ),
                  'name' => 'exists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 174,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 174,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 174,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 174,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if an element exists in the cache
     *
     * @param string $key
     *
     * @return bool
     * @throws Exception
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
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 173,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 173,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 172,
          'last-line' => 185,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'increment',
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
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 186,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '1',
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 186,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 186,
              'char' => 57,
            ),
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 188,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 188,
                  'char' => 35,
                ),
                'name' => 'incrBy',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 188,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 188,
                    'char' => 46,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 188,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 188,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 188,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 189,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Increments a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     * @throws Exception
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 186,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 187,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 187,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 186,
          'last-line' => 200,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'set',
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
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 201,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 201,
              'char' => 47,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'ttl',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 201,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 201,
              'char' => 63,
            ),
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 203,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 203,
                  'char' => 35,
                ),
                'name' => 'set',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 204,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 204,
                    'char' => 16,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 205,
                        'char' => 18,
                      ),
                      'name' => 'getSerializedData',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 205,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 205,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 205,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 205,
                    'char' => 43,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 206,
                        'char' => 18,
                      ),
                      'name' => 'getTtl',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ttl',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 206,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 206,
                          'char' => 29,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 207,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 207,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 207,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 208,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stores data in the adapter
     *
     * @param string $key
     * @param mixed  $value
     * @param null   $ttl
     *
     * @return bool
     * @throws Exception
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
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 202,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
            'line' => 202,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 201,
          'last-line' => 215,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'setSerializer',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'connection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => '\\Redis',
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 216,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 216,
              'char' => 55,
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
                  'variable' => 'serializer',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 218,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 219,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'map',
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 219,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 221,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'map',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'none',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 222,
                          'char' => 18,
                        ),
                        'value' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Redis',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 222,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'SERIALIZER_NONE',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 222,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 222,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 222,
                        'char' => 43,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'php',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 223,
                          'char' => 18,
                        ),
                        'value' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Redis',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 224,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'SERIALIZER_PHP',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 224,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 224,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 224,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 224,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 224,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 230,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'defined',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Redis::SERIALIZER_IGBINARY',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 230,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 230,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 230,
                'char' => 50,
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
                      'variable' => 'map',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'igbinary',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 231,
                          'char' => 29,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'constant',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '\\\\Redis::SERIALIZER_IGBINARY',
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 231,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 231,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 231,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 231,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 232,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 234,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'defined',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Redis::SERIALIZER_MSGPACK',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 234,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 234,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 234,
                'char' => 49,
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
                      'variable' => 'map',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'msgpack',
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 235,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'constant',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '\\\\Redis::SERIALIZER_MSGPACK',
                              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                              'line' => 235,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 235,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 235,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 235,
                      'char' => 70,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 236,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 238,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'serializer',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtolower',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 238,
                            'char' => 42,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultSerializer',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 238,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 238,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 238,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 238,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 238,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 240,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'map',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 240,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'serializer',
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 240,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 240,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                'line' => 240,
                'char' => 34,
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
                      'property' => 'defaultSerializer',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 241,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 241,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 242,
                  'char' => 22,
                ),
                1 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'connection',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 242,
                      'char' => 24,
                    ),
                    'name' => 'setOption',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Redis',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 242,
                            'char' => 57,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'OPT_SERIALIZER',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 242,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 242,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 242,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'map',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 242,
                            'char' => 62,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'serializer',
                            'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                            'line' => 242,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                          'line' => 242,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                        'line' => 242,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 242,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 243,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                      'line' => 244,
                      'char' => 18,
                    ),
                    'name' => 'initSerializer',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                    'line' => 244,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
                  'line' => 245,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
              'line' => 246,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the serializer. If it is a supported one it is set, otherwise
     * the custom one is set.
     *
     * @param \\Redis $connection
     *',
          'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
          'line' => 216,
          'last-line' => 247,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/Adapter/Redis.zep',
    'line' => 24,
    'char' => 5,
  ),
);