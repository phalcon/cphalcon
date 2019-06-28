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
    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations\\Adapter',
    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
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
        'name' => 'Phalcon\\Annotations\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
        'line' => 13,
        'char' => 48,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
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
        'name' => 'Phalcon\\Annotations\\Reflection',
        'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
        'line' => 14,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
    'line' => 19,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Stores the parsed annotations in memory. This adapter is the suitable
 * development/testing
 *',
    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
    'line' => 20,
    'char' => 5,
  ),
  5 => 
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
          'docblock' => '**
     * @var mixed
     *',
          'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
          'line' => 29,
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
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
              'line' => 30,
              'char' => 37,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                  'line' => 32,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
              'line' => 34,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                    'line' => 34,
                    'char' => 53,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                        'line' => 34,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                        'line' => 34,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                      'line' => 34,
                      'char' => 35,
                    ),
                    'right' => 
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
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                            'line' => 34,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                          'line' => 34,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                      'line' => 34,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                    'line' => 34,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                  'line' => 34,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                'line' => 34,
                'char' => 53,
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
                    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                    'line' => 35,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                  'line' => 36,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
              'line' => 38,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                'line' => 38,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
              'line' => 39,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads parsed annotations from memory
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
                  'value' => 'Reflection',
                  'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                  'line' => 30,
                  'char' => 55,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                'line' => 30,
                'char' => 55,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                'line' => 31,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
            'line' => 31,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
          'line' => 30,
          'last-line' => 43,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
              'line' => 44,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Reflection',
                'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                'line' => 44,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
              'line' => 44,
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
                  'variable' => 'lowercasedKey',
                  'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                  'line' => 46,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
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
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'lowercasedKey',
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
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                          'line' => 48,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                        'line' => 48,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                    'line' => 48,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                  'line' => 48,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
              'line' => 49,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'data',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'lowercasedKey',
                      'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                      'line' => 49,
                      'char' => 37,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                    'line' => 49,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
                  'line' => 49,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
              'line' => 50,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes parsed annotations to memory
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
            'line' => 45,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
          'line' => 44,
          'last-line' => 51,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Memory.zep',
    'line' => 20,
    'char' => 5,
  ),
);