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
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Adapter',
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
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
        'name' => 'DateInterval',
        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
        'line' => 13,
        'char' => 17,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
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
        'name' => 'DateTime',
        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
        'line' => 14,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
        'line' => 15,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Storage\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
        'line' => 16,
        'char' => 45,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Storage\\Exception',
        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
        'line' => 17,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Storage\\SerializerFactory',
        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
        'line' => 18,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
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
        'name' => 'Phalcon\\Storage\\Serializer\\SerializerInterface',
        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
        'line' => 19,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
    'line' => 21,
    'char' => 8,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'AbstractAdapter',
    'abstract' => 1,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'AdapterInterface',
        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
        'line' => 22,
        'char' => 1,
      ),
    ),
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
          'name' => 'adapter',
          'docblock' => '**
     * @var mixed
     *',
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 32,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultSerializer',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Php',
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 33,
            'char' => 39,
          ),
          'docblock' => '**
     * Name of the default serializer class
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 33,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 33,
              'char' => 50,
            ),
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 39,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'lifetime',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3600',
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 40,
            'char' => 30,
          ),
          'docblock' => '**
     * Name of the default TTL (time to live)
     *
     * @var int
     *',
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 44,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'prefix',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 45,
            'char' => 25,
          ),
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 45,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 51,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'serializer',
          'docblock' => '**
     * Serializer
     *
     * @var <SerializerInterface>
     *',
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 58,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'serializerFactory',
          'docblock' => '**
     * Serializer Factory
     *
     * @var <SerializerFactory>
     *',
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 63,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 64,
                'char' => 62,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 64,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 64,
              'char' => 70,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 64,
              'char' => 86,
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
                  'property' => 'defaultSerializer',
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
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 69,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 69,
                        'char' => 55,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'defaultSerializer',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 69,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 69,
                        'char' => 74,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Php',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 69,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 69,
                        'char' => 79,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 69,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 69,
                  'char' => 80,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'lifetime',
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
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 70,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 70,
                        'char' => 55,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'lifetime',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 70,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 70,
                        'char' => 65,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '3600',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 70,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 70,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 70,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 70,
                  'char' => 72,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'serializer',
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
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 71,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 71,
                        'char' => 55,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'serializer',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 71,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 71,
                        'char' => 67,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 71,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 71,
                        'char' => 73,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 71,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 71,
                  'char' => 74,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'serializerFactory',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'factory',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 72,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 72,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 74,
              'char' => 10,
            ),
            1 => 
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
                    'value' => 'options',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 74,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 74,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 74,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 74,
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
                      'property' => 'prefix',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 75,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 75,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 75,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 75,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 76,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 77,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets parameters based on options
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 65,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 64,
          'last-line' => 81,
          'char' => 22,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
          'docblock' => '**
     * Flushes/clears the cache
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 82,
                'char' => 45,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 82,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 82,
          'last-line' => 86,
          'char' => 28,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
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
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 87,
              'char' => 51,
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 87,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 87,
              'char' => 66,
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 87,
                'char' => 75,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 87,
                'char' => 81,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 87,
            'char' => 81,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 87,
          'last-line' => 91,
          'char' => 28,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
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
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 92,
              'char' => 48,
            ),
          ),
          'docblock' => '**
     * Deletes data from the adapter
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 92,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 92,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 92,
          'last-line' => 96,
          'char' => 28,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
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
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 97,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Reads data from the adapter
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 97,
                'char' => 53,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 97,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 97,
          'last-line' => 101,
          'char' => 28,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAdapter',
          'docblock' => '**
     * Returns the adapter - connects to the storage if not connected
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 102,
                'char' => 49,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 102,
            'char' => 49,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 102,
          'last-line' => 106,
          'char' => 28,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => 'getKeys',
          'docblock' => '**
     * Returns all the keys stored
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 107,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 107,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 107,
          'last-line' => 111,
          'char' => 28,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
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
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 112,
              'char' => 45,
            ),
          ),
          'docblock' => '**
     * Checks if an element exists in the cache
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 112,
                'char' => 54,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 112,
            'char' => 54,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 112,
          'last-line' => 116,
          'char' => 28,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
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
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 117,
              'char' => 51,
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 117,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 117,
              'char' => 66,
            ),
          ),
          'docblock' => '**
     * Increments a stored number
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 117,
                'char' => 75,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 117,
                'char' => 81,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 117,
            'char' => 81,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 117,
          'last-line' => 121,
          'char' => 28,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'public',
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
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 122,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 122,
              'char' => 56,
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 122,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 122,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Stores data in the adapter
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 122,
                'char' => 81,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 122,
            'char' => 81,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 122,
          'last-line' => 126,
          'char' => 28,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getPrefixedKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 127,
              'char' => 46,
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
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'key',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 129,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 129,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 129,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 131,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 131,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 131,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 131,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'key',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 131,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 131,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 132,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the key requested, prefixed
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 128,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 128,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 127,
          'last-line' => 136,
          'char' => 22,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getSerializedData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 137,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 139,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultSerializer',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 139,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 139,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 139,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 139,
                'char' => 41,
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 140,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'serializer',
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 140,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 140,
                      'char' => 30,
                    ),
                    'name' => 'setData',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'content',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 140,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 140,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 140,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 141,
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
                      'variable' => 'content',
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
                            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                            'line' => 141,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'serializer',
                            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                            'line' => 141,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 141,
                          'char' => 44,
                        ),
                        'name' => 'serialize',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 141,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 141,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 142,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 144,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'content',
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 144,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 145,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns serialized data
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 138,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 138,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 137,
          'last-line' => 154,
          'char' => 22,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getTtl',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'ttl',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 155,
              'char' => 38,
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
                  'variable' => 'dateTime',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 157,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 159,
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
                  'type' => 'variable',
                  'value' => 'ttl',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 159,
                  'char' => 18,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 159,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 159,
                'char' => 25,
              ),
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
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 160,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'lifetime',
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 160,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 160,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 161,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 163,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ttl',
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 163,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 163,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 163,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 163,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'instanceof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'ttl',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 163,
                    'char' => 50,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'DateInterval',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 163,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 163,
                  'char' => 65,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 163,
                'char' => 65,
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
                      'variable' => 'dateTime',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'DateTime',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '@0',
                              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                              'line' => 164,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                            'line' => 164,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 164,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 164,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 165,
                  'char' => 18,
                ),
                1 => 
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
                        'value' => 'dateTime',
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 165,
                        'char' => 29,
                      ),
                      'name' => 'add',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ttl',
                            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                            'line' => 165,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 165,
                          'char' => 37,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 165,
                      'char' => 39,
                    ),
                    'name' => 'getTimestamp',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 165,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 166,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 168,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'cast',
                'left' => 'int',
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'ttl',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 168,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 168,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 169,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Calculates the TTL for a cache item
     *
     * @param DateInterval|int|null $ttl
     *
     * @return int
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 156,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 156,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 155,
          'last-line' => 173,
          'char' => 22,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getUnserializedData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 174,
              'char' => 55,
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 174,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 174,
              'char' => 80,
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
                  'type' => 'variable',
                  'value' => 'content',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 176,
                  'char' => 21,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 176,
                'char' => 21,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultValue',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 177,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 178,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 180,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 180,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultSerializer',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 180,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 180,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 180,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 180,
                'char' => 41,
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 181,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'serializer',
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 181,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 181,
                      'char' => 30,
                    ),
                    'name' => 'unserialize',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'content',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 181,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 181,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 181,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 182,
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
                      'variable' => 'content',
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
                            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                            'line' => 182,
                            'char' => 32,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'serializer',
                            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                            'line' => 182,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 182,
                          'char' => 44,
                        ),
                        'name' => 'getData',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 182,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 182,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 183,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 185,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'content',
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 185,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 186,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns unserialized data
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
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 175,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 175,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 174,
          'last-line' => 190,
          'char' => 22,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'initSerializer',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 193,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 195,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 195,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 195,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'serializerFactory',
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 195,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 195,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 195,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                'line' => 195,
                'char' => 54,
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
                          'value' => 'A valid serializer is required',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 196,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 196,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 196,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 197,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 199,
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
                  'variable' => 'className',
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
                            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                            'line' => 199,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'defaultSerializer',
                            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                            'line' => 199,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 199,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 199,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 199,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 199,
                  'char' => 67,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'serializer',
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
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 200,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'serializerFactory',
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 200,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                      'line' => 200,
                      'char' => 56,
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
                          'value' => 'className',
                          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                          'line' => 200,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                        'line' => 200,
                        'char' => 78,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                    'line' => 200,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
                  'line' => 200,
                  'char' => 79,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
              'line' => 201,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Initializes the serializer
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
            'line' => 192,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
          'line' => 191,
          'last-line' => 202,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
      'line' => 21,
      'char' => 14,
    ),
    'file' => '/app/phalcon/Storage/Adapter/AbstractAdapter.zep',
    'line' => 21,
    'char' => 14,
  ),
);