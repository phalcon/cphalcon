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
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Adapter',
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
        'line' => 15,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
        'line' => 16,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
        'line' => 17,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
    'line' => 23,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Storage\\Adapter\\Libmemcached
 *
 * Libmemcached adapter
 *',
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
    'line' => 24,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Libmemcached',
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
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 29,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 35,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 36,
                'char' => 59,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 36,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 36,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 36,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 36,
              'char' => 88,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
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
                      'value' => 'options',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 38,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'servers',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 38,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 38,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 38,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 38,
                'char' => 36,
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
                          'value' => 'servers',
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 39,
                          'char' => 32,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'array',
                        'left' => 
                        array (
                          0 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 40,
                              'char' => 18,
                            ),
                            'value' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'host',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 41,
                                    'char' => 28,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '127.0.0.1',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 41,
                                    'char' => 39,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 41,
                                  'char' => 39,
                                ),
                                1 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'port',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 42,
                                    'char' => 28,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '11211',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 42,
                                    'char' => 35,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 42,
                                  'char' => 35,
                                ),
                                2 => 
                                array (
                                  'key' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'weight',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 43,
                                    'char' => 28,
                                  ),
                                  'value' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 44,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 44,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 45,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 45,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 45,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 45,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 46,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 48,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'ph-memc-',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 48,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 48,
                  'char' => 37,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 49,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 49,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 51,
              'char' => 14,
            ),
            2 => 
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
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 51,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 51,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 51,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 51,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 51,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 52,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Libmemcached constructor.
     *
     * @param array $options
     *',
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 36,
          'last-line' => 59,
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
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 62,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 62,
                  'char' => 35,
                ),
                'name' => 'flush',
                'call-type' => 1,
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 62,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 63,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 61,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 61,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 60,
          'last-line' => 67,
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
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 68,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 68,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 68,
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
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 70,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 70,
                  'char' => 35,
                ),
                'name' => 'decrement',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 70,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 70,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 70,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 70,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 70,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 71,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Decrements a stored number
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 68,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 69,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 69,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 68,
          'last-line' => 80,
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
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 81,
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
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 83,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 83,
                  'char' => 35,
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
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 83,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 83,
                    'char' => 46,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 83,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 83,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 83,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 84,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 82,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 82,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 81,
          'last-line' => 94,
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
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 95,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 95,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 95,
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
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 97,
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
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 98,
                          'char' => 18,
                        ),
                        'name' => 'getAdapter',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 98,
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
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 98,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 98,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 98,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 98,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 100,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 100,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 100,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 101,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 96,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 96,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 95,
          'last-line' => 109,
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
                  'variable' => 'client',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 112,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 112,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'failover',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 112,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 112,
                  'char' => 50,
                ),
                4 => 
                array (
                  'variable' => 'persistentId',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 112,
                  'char' => 64,
                ),
                5 => 
                array (
                  'variable' => 'sasl',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 113,
                  'char' => 17,
                ),
                6 => 
                array (
                  'variable' => 'saslPass',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 113,
                  'char' => 27,
                ),
                7 => 
                array (
                  'variable' => 'saslUser',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 113,
                  'char' => 37,
                ),
                8 => 
                array (
                  'variable' => 'servers',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 113,
                  'char' => 46,
                ),
                9 => 
                array (
                  'variable' => 'serverList',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 113,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 115,
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
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 115,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 115,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 115,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 115,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 115,
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
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 116,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 116,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 116,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 116,
                      'char' => 45,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'persistentId',
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
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 117,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 117,
                            'char' => 48,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'persistentId',
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 117,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 117,
                            'char' => 62,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'ph-mcid-',
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 117,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 117,
                            'char' => 72,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 117,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 117,
                      'char' => 73,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'sasl',
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
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 118,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 118,
                            'char' => 48,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'saslAuthData',
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 118,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 118,
                            'char' => 62,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'empty-array',
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 118,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 118,
                            'char' => 66,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 118,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 118,
                      'char' => 67,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'connection',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => '\\Memcached',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'persistentId',
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 119,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 119,
                            'char' => 59,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 119,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 119,
                      'char' => 60,
                    ),
                    4 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'serverList',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'connection',
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 120,
                          'char' => 43,
                        ),
                        'name' => 'getServerList',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 120,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 120,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 122,
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
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 122,
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
                            'value' => '\\Memcached',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 122,
                            'char' => 61,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'OPT_PREFIX_KEY',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 122,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 122,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 122,
                        'char' => 61,
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
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 122,
                            'char' => 68,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'prefix',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 122,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 122,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 122,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 122,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 124,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'less',
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
                            'value' => 'serverList',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 124,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 124,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 124,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 124,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 124,
                    'char' => 38,
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
                          'variable' => 'servers',
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
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 125,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 125,
                                'char' => 48,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'servers',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 125,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 125,
                                'char' => 57,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'empty-array',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 125,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 125,
                                'char' => 61,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 125,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 125,
                          'char' => 62,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'client',
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
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 126,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 126,
                                'char' => 48,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'client',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 126,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 126,
                                'char' => 56,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'empty-array',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 126,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 126,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 126,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 126,
                          'char' => 61,
                        ),
                        2 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'saslUser',
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
                                  'value' => 'sasl',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 127,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 127,
                                'char' => 45,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'user',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 127,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 127,
                                'char' => 51,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 127,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 127,
                                'char' => 53,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 127,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 127,
                          'char' => 54,
                        ),
                        3 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'saslPass',
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
                                  'value' => 'sasl',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 128,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 128,
                                'char' => 45,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'pass',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 128,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 128,
                                'char' => 51,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 128,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 128,
                                'char' => 53,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 128,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 128,
                          'char' => 54,
                        ),
                        4 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'failover',
                          'expr' => 
                          array (
                            'type' => 'array',
                            'left' => 
                            array (
                              0 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'static-constant-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '\\Memcached',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 130,
                                    'char' => 63,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'OPT_CONNECT_TIMEOUT',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 130,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 130,
                                  'char' => 63,
                                ),
                                'value' => 
                                array (
                                  'type' => 'int',
                                  'value' => '10',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 130,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 130,
                                'char' => 67,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'static-constant-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '\\Memcached',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 131,
                                    'char' => 63,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'OPT_DISTRIBUTION',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 131,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 131,
                                  'char' => 63,
                                ),
                                'value' => 
                                array (
                                  'type' => 'static-constant-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '\\Memcached',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 131,
                                    'char' => 100,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'DISTRIBUTION_CONSISTENT',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 131,
                                    'char' => 100,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 131,
                                  'char' => 100,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 131,
                                'char' => 100,
                              ),
                              2 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'static-constant-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '\\Memcached',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 132,
                                    'char' => 63,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'OPT_SERVER_FAILURE_LIMIT',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 132,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 132,
                                  'char' => 63,
                                ),
                                'value' => 
                                array (
                                  'type' => 'int',
                                  'value' => '2',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 132,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 132,
                                'char' => 66,
                              ),
                              3 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'static-constant-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '\\Memcached',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 133,
                                    'char' => 63,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'OPT_REMOVE_FAILED_SERVERS',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 133,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 133,
                                  'char' => 63,
                                ),
                                'value' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 133,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 133,
                                'char' => 69,
                              ),
                              4 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'static-constant-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => '\\Memcached',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 134,
                                    'char' => 63,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'OPT_RETRY_TIMEOUT',
                                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                    'line' => 134,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 134,
                                  'char' => 63,
                                ),
                                'value' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 135,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 135,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 135,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 135,
                          'char' => 22,
                        ),
                        5 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'client',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'array_merge',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'failover',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 136,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 136,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'client',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 136,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 136,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 136,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 136,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 138,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'connection',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 138,
                            'char' => 32,
                          ),
                          'name' => 'setOptions',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'client',
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 138,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 138,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 138,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 138,
                        'char' => 52,
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
                                  'value' => 'Cannot set Memcached client options',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 139,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 139,
                                'char' => 76,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 139,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 140,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 142,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'connection',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 142,
                            'char' => 32,
                          ),
                          'name' => 'addServers',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'servers',
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 142,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 142,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 142,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 142,
                        'char' => 53,
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
                                  'value' => 'Cannot connect to the Memcached server(s)',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 143,
                                  'char' => 82,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 143,
                                'char' => 82,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 143,
                            'char' => 83,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 144,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 146,
                      'char' => 18,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'empty',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'saslUser',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 146,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 146,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 146,
                        'char' => 36,
                      ),
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
                              'type' => 'variable',
                              'value' => 'connection',
                              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                              'line' => 147,
                              'char' => 32,
                            ),
                            'name' => 'setSaslAuthData',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'saslUser',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 147,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 147,
                                'char' => 57,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'saslPass',
                                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                  'line' => 147,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                                'line' => 147,
                                'char' => 67,
                              ),
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 147,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 148,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 149,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 151,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 151,
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
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 151,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 151,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 151,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 153,
                  'char' => 15,
                ),
                4 => 
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
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 153,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 153,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 154,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 156,
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
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 156,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'adapter',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 156,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 156,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 157,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     *
     * @return Memcached
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 110,
          'last-line' => 164,
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'keys',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 167,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 169,
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
                  'variable' => 'keys',
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
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 169,
                        'char' => 25,
                      ),
                      'name' => 'getAdapter',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 169,
                      'char' => 39,
                    ),
                    'name' => 'getAllKeys',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 169,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 169,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 171,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'ternary',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'keys',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 171,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 171,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'empty-array',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 171,
                  'char' => 27,
                ),
                'extra' => 
                array (
                  'type' => 'variable',
                  'value' => 'keys',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 171,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 171,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 172,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 166,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 166,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 165,
          'last-line' => 181,
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
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 182,
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
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 184,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 184,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 186,
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
                  'variable' => 'connection',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 186,
                      'char' => 31,
                    ),
                    'name' => 'getAdapter',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 186,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 186,
                  'char' => 44,
                ),
                1 => 
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
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 187,
                      'char' => 37,
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
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 187,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 187,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 187,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 187,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 189,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => '\\Memcached',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 189,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'RES_NOTFOUND',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 189,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 189,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'connection',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 189,
                    'char' => 56,
                  ),
                  'name' => 'getResultCode',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 189,
                  'char' => 72,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 189,
                'char' => 72,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 190,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 183,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 183,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 182,
          'last-line' => 200,
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
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 201,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 201,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 201,
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
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 203,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 203,
                  'char' => 35,
                ),
                'name' => 'increment',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 203,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 203,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 203,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 203,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 203,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 204,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 201,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 202,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 202,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 201,
          'last-line' => 215,
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
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 216,
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
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 216,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 216,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 216,
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
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 218,
                    'char' => 21,
                  ),
                  'name' => 'getAdapter',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 218,
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
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 219,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 219,
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
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 220,
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
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 220,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 220,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 220,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 220,
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
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 221,
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
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 221,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 221,
                          'char' => 29,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 222,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 222,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 222,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 223,
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
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 217,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
            'line' => 217,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 216,
          'last-line' => 230,
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
                'value' => '\\Memcached',
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 231,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 231,
              'char' => 59,
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
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 233,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 234,
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
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 234,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 236,
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
                          'value' => 'php',
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 237,
                          'char' => 22,
                        ),
                        'value' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Memcached',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 237,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'SERIALIZER_PHP',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 237,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 237,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 237,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'json',
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 238,
                          'char' => 22,
                        ),
                        'value' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Memcached',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 238,
                            'char' => 51,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'SERIALIZER_JSON',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 238,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 238,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 238,
                        'char' => 51,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'igbinary',
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 239,
                          'char' => 22,
                        ),
                        'value' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => '\\Memcached',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 240,
                            'char' => 9,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'SERIALIZER_IGBINARY',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 240,
                            'char' => 9,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 240,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 240,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 240,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 240,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 242,
              'char' => 11,
            ),
            3 => 
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
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 242,
                            'char' => 42,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultSerializer',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 242,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 242,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 242,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 242,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 242,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 244,
              'char' => 10,
            ),
            4 => 
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
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 244,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'serializer',
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 244,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 244,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                'line' => 244,
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
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 245,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 245,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 246,
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
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 246,
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
                            'value' => '\\Memcached',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 246,
                            'char' => 61,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'OPT_SERIALIZER',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 246,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 246,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 246,
                        'char' => 61,
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
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 246,
                            'char' => 66,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'serializer',
                            'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                            'line' => 246,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                          'line' => 246,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                        'line' => 246,
                        'char' => 78,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 246,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 247,
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
                      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                      'line' => 248,
                      'char' => 18,
                    ),
                    'name' => 'initSerializer',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                    'line' => 248,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
                  'line' => 249,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
              'line' => 250,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the serializer. If it is a supported one it is set, otherwise
     * the custom one is set.
     *
     * @param Memcached $connection
     *',
          'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
          'line' => 231,
          'last-line' => 251,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
      'line' => 24,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/Adapter/Libmemcached.zep',
    'line' => 24,
    'char' => 5,
  ),
);