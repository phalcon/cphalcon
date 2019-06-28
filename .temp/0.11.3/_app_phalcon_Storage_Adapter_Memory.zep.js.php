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
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Adapter',
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
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
        'name' => 'Phalcon\\Collection\\Collection',
        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
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
        'name' => 'Phalcon\\Storage\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
        'line' => 15,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
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
        'name' => 'Phalcon\\Storage\\Exception',
        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
        'line' => 16,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
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
        'name' => 'Phalcon\\Storage\\SerializerFactory',
        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
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
        'name' => 'Phalcon\\Storage\\Serializer\\SerializerInterface',
        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
        'line' => 18,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
    'line' => 24,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Storage\\Adapter\\Memory
 *
 * Memory adapter
 *',
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
    'line' => 25,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Memory',
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
          'name' => 'data',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 30,
            'char' => 24,
          ),
          'docblock' => '**
     * @var Collection
     *',
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 34,
          'char' => 6,
        ),
        1 => 
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
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 35,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 39,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 40,
                'char' => 59,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 40,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 40,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 40,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 40,
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'ph-memo-',
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 45,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 45,
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
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 46,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 46,
                  'char' => 36,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'data',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 47,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 47,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 49,
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
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 49,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 49,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 49,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 49,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 49,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 51,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 51,
                  'char' => 14,
                ),
                'name' => 'initSerializer',
                'call-type' => 1,
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 51,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 52,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 40,
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
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 59,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 59,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 59,
                  'char' => 20,
                ),
                'name' => 'clear',
                'call-type' => 1,
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 59,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 61,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 61,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 62,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 58,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 58,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 57,
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
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 72,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 72,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 72,
              'char' => 57,
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
                  'variable' => 'current',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 74,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'newValue',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 74,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'prefixedKey',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 74,
                  'char' => 43,
                ),
                3 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 74,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
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
                  'variable' => 'prefixedKey',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 76,
                      'char' => 32,
                    ),
                    'name' => 'getPrefixedKey',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 76,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 76,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 76,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 76,
                  'char' => 52,
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 77,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 77,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 77,
                      'char' => 38,
                    ),
                    'name' => 'has',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefixedKey',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 77,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 77,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 77,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 77,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 79,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 79,
                'char' => 19,
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
                      'variable' => 'current',
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
                            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                            'line' => 80,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                            'line' => 80,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 80,
                          'char' => 39,
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
                              'value' => 'prefixedKey',
                              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                              'line' => 80,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                            'line' => 80,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 80,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 80,
                      'char' => 56,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'newValue',
                      'expr' => 
                      array (
                        'type' => 'sub',
                        'left' => 
                        array (
                          'type' => 'cast',
                          'left' => 'int',
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'current',
                            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                            'line' => 81,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 81,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 81,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 81,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 81,
                      'char' => 49,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'newValue',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 82,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 82,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 84,
                  'char' => 16,
                ),
                1 => 
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
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 84,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 84,
                        'char' => 24,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 84,
                      'char' => 24,
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
                          'value' => 'prefixedKey',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 84,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 84,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'newValue',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 84,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 84,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 84,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 85,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 87,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 87,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 88,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 72,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 73,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 73,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 72,
          'last-line' => 96,
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
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 97,
              'char' => 39,
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
                  'variable' => 'exists',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 99,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'prefixedKey',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 99,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 101,
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
                  'variable' => 'prefixedKey',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 101,
                      'char' => 32,
                    ),
                    'name' => 'getPrefixedKey',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 101,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 101,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 101,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 101,
                  'char' => 52,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'exists',
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
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 102,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 102,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 102,
                      'char' => 38,
                    ),
                    'name' => 'has',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefixedKey',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 102,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 102,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 102,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 102,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 104,
              'char' => 12,
            ),
            2 => 
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
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 104,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 104,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 104,
                  'char' => 20,
                ),
                'name' => 'remove',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'prefixedKey',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 104,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 104,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 104,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 106,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'exists',
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 106,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 107,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads data from the adapter
     *
     * @param string $key
     *
     * @return bool
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 98,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 98,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 97,
          'last-line' => 116,
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
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 117,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 117,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 117,
              'char' => 61,
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
                  'variable' => 'content',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 119,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'prefixedKey',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 119,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 121,
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
                  'variable' => 'prefixedKey',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 121,
                      'char' => 32,
                    ),
                    'name' => 'getPrefixedKey',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 121,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 121,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 121,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 121,
                  'char' => 52,
                ),
                1 => 
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
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 122,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 122,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 122,
                      'char' => 38,
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
                          'value' => 'prefixedKey',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 122,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 122,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 122,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 122,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 124,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 124,
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
                      'type' => 'variable',
                      'value' => 'content',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 124,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 124,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 124,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 124,
                    'char' => 63,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 124,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 125,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads data from the adapter
     *
     * @param string     $key
     * @param mixed|null $defaultValue
     *
     * @return mixed
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 118,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 118,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 117,
          'last-line' => 132,
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
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 135,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'adapter',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 135,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 135,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 136,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     *
     * @return mixed
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 134,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 134,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 133,
          'last-line' => 142,
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
                'type' => 'fcall',
                'name' => 'array_keys',
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
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 145,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 145,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 145,
                        'char' => 38,
                      ),
                      'name' => 'toArray',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 145,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 145,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 145,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 146,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stores data in the adapter
     *
     * @return array
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 144,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 144,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 143,
          'last-line' => 154,
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
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 155,
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
                  'variable' => 'prefixedKey',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 157,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 159,
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
                  'variable' => 'prefixedKey',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 159,
                      'char' => 32,
                    ),
                    'name' => 'getPrefixedKey',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 159,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 159,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 159,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 159,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 161,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
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
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 161,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 161,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 161,
                  'char' => 27,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'prefixedKey',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 161,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 161,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 161,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 162,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if an element exists in the cache
     *
     * @param string $key
     *
     * @return bool
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 156,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 156,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 155,
          'last-line' => 171,
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
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 172,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 172,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 172,
              'char' => 57,
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
                  'variable' => 'current',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 174,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'newValue',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 174,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'prefixedKey',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 174,
                  'char' => 43,
                ),
                3 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 174,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 176,
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
                  'variable' => 'prefixedKey',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 176,
                      'char' => 32,
                    ),
                    'name' => 'getPrefixedKey',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 176,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 176,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 176,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 176,
                  'char' => 52,
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 177,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 177,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 177,
                      'char' => 38,
                    ),
                    'name' => 'has',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefixedKey',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 177,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 177,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 177,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 177,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 179,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 179,
                'char' => 19,
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
                      'variable' => 'current',
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
                            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                            'line' => 180,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'data',
                            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                            'line' => 180,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 180,
                          'char' => 39,
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
                              'value' => 'prefixedKey',
                              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                              'line' => 180,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                            'line' => 180,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 180,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 180,
                      'char' => 56,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'newValue',
                      'expr' => 
                      array (
                        'type' => 'add',
                        'left' => 
                        array (
                          'type' => 'cast',
                          'left' => 'int',
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'current',
                            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                            'line' => 181,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 181,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 181,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 181,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 181,
                      'char' => 49,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'newValue',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 182,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 182,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 184,
                  'char' => 16,
                ),
                1 => 
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
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 184,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 184,
                        'char' => 24,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 184,
                      'char' => 24,
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
                          'value' => 'prefixedKey',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 184,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 184,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'newValue',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 184,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 184,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 184,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 185,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 187,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 187,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 188,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 172,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 173,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 173,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 172,
          'last-line' => 198,
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
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 199,
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
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 199,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 199,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 199,
              'char' => 63,
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
                  'variable' => 'content',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 201,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'lifetime',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 201,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'prefixedKey',
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 201,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 203,
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
                  'variable' => 'content',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 203,
                      'char' => 32,
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
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 203,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 203,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 203,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 203,
                  'char' => 57,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'lifetime',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 204,
                      'char' => 32,
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
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 204,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 204,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 204,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 204,
                  'char' => 44,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'prefixedKey',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 205,
                      'char' => 32,
                    ),
                    'name' => 'getPrefixedKey',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                          'line' => 205,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                        'line' => 205,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 205,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 205,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 207,
              'char' => 12,
            ),
            2 => 
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
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 207,
                    'char' => 14,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 207,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                  'line' => 207,
                  'char' => 20,
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
                      'value' => 'prefixedKey',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 207,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 207,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'content',
                      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                      'line' => 207,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                    'line' => 207,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 207,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 209,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 209,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
              'line' => 210,
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
                'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
                'line' => 200,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
            'line' => 200,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
          'line' => 199,
          'last-line' => 211,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/Adapter/Memory.zep',
    'line' => 25,
    'char' => 5,
  ),
);