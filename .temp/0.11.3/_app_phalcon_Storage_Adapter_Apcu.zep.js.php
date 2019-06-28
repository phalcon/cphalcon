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
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage\\Adapter',
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
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
        'name' => 'APCUIterator',
        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
        'line' => 13,
        'char' => 17,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
        'line' => 15,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
        'line' => 16,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
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
        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
        'line' => 18,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
    'line' => 24,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Storage\\Adapter\\Apcu
 *
 * Apcu adapter
 *',
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
    'line' => 25,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Apcu',
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
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 30,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
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
                'value' => 'SerializerFactory',
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 35,
                'char' => 59,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 35,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 35,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 35,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 35,
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
                    'value' => 'ph-apcu-',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 40,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 40,
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
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 41,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 41,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 43,
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
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 43,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 43,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 43,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 43,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 43,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 45,
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
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 45,
                  'char' => 14,
                ),
                'name' => 'initSerializer',
                'call-type' => 1,
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 45,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 46,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 35,
          'last-line' => 50,
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
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'item',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 53,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'pattern',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 53,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'apc',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 53,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 53,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 54,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 54,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 56,
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
                  'variable' => 'pattern',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '/^',
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 56,
                        'char' => 26,
                      ),
                      'right' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 56,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 56,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 56,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 56,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '/',
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 56,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 56,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 56,
                  'char' => 44,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'apc',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'APCUIterator',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pattern',
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 57,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 57,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 57,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 57,
                  'char' => 48,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 58,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 58,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 60,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'apc',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 60,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 60,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 60,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 60,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 61,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 62,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 64,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'iterator',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'apc',
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 64,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 64,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 64,
                'char' => 35,
              ),
              'value' => 'item',
              'reverse' => 0,
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
                      'type' => 'fcall',
                      'name' => 'apcu_delete',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'item',
                              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                              'line' => 65,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'key',
                              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                              'line' => 65,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 65,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 65,
                          'char' => 38,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 65,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 65,
                    'char' => 40,
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
                          'variable' => 'result',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 66,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 66,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 67,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 68,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 70,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 70,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 71,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 52,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 52,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 51,
          'last-line' => 80,
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
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 81,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 81,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 81,
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
                'type' => 'fcall',
                'name' => 'apcu_dec',
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
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 83,
                        'char' => 30,
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
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 83,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 83,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 83,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 83,
                    'char' => 50,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 83,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 83,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 83,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 84,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 81,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 82,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 82,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 81,
          'last-line' => 92,
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
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 93,
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
                'type' => 'fcall',
                'name' => 'apcu_delete',
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
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 95,
                        'char' => 33,
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
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 95,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 95,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 95,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 95,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 95,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 96,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 94,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 94,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 93,
          'last-line' => 105,
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
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 106,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 106,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 106,
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
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 108,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 110,
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
                    'type' => 'fcall',
                    'name' => 'apcu_fetch',
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
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 110,
                            'char' => 39,
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
                                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                                'line' => 110,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                              'line' => 110,
                              'char' => 58,
                            ),
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 110,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 110,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 110,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 110,
                  'char' => 60,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 112,
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
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 112,
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
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 112,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 112,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'defaultValue',
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 112,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 112,
                    'char' => 63,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 112,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 113,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 107,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 107,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 106,
          'last-line' => 120,
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
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 123,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'adapter',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 123,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 123,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 124,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 121,
          'last-line' => 130,
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
                  'variable' => 'item',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 133,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'pattern',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 133,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'apc',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 133,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 133,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 134,
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
                  'variable' => 'results',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 134,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 136,
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
                  'variable' => 'pattern',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '/^',
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 136,
                        'char' => 26,
                      ),
                      'right' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 136,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 136,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 136,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 136,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '/',
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 136,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 136,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 136,
                  'char' => 44,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'apc',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'APCUIterator',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'pattern',
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 137,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 137,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 137,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 137,
                  'char' => 48,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'results',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 138,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 138,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 140,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'apc',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 140,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 140,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 140,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 140,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'results',
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 141,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 142,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 144,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'iterator',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'apc',
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 144,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 144,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 144,
                'char' => 35,
              ),
              'value' => 'item',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'results',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'item',
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 145,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'key',
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 145,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 145,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 145,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                  'line' => 146,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 148,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'results',
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 148,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 149,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 132,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 132,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 131,
          'last-line' => 157,
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
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 158,
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
                'type' => 'fcall',
                'name' => 'apcu_exists',
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
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 160,
                        'char' => 33,
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
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 160,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 160,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 160,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 160,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 160,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 161,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 159,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 159,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 158,
          'last-line' => 170,
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
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 171,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 171,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 171,
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
                'type' => 'fcall',
                'name' => 'apcu_inc',
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
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 173,
                        'char' => 30,
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
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 173,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 173,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 173,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 173,
                    'char' => 50,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 173,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 173,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 173,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 174,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 171,
                'char' => 66,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 172,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 172,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 171,
          'last-line' => 185,
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
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 186,
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
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 186,
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 186,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 186,
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
                'type' => 'fcall',
                'name' => 'apcu_store',
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
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 189,
                        'char' => 18,
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
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 189,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 189,
                          'char' => 37,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 189,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 189,
                    'char' => 38,
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
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 190,
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
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 190,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 190,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 190,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 190,
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
                        'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                        'line' => 191,
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
                            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                            'line' => 191,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                          'line' => 191,
                          'char' => 29,
                        ),
                      ),
                      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                      'line' => 192,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                    'line' => 192,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 192,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
              'line' => 193,
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
     * @throws \\Exception
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
                'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
                'line' => 187,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
            'line' => 187,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
          'line' => 186,
          'last-line' => 194,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/Adapter/Apcu.zep',
    'line' => 25,
    'char' => 5,
  ),
);