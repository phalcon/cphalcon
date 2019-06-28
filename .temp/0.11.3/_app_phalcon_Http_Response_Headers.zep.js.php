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
    'file' => '/app/phalcon/Http/Response/Headers.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Response',
    'file' => '/app/phalcon/Http/Response/Headers.zep',
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
        'name' => 'Phalcon\\Http\\Response\\HeadersInterface',
        'file' => '/app/phalcon/Http/Response/Headers.zep',
        'line' => 13,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Http/Response/Headers.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Http\\Response\\Headers
 *
 * This class is a bag to manage the response headers
 *',
    'file' => '/app/phalcon/Http/Response/Headers.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Headers',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'HeadersInterface',
        'file' => '/app/phalcon/Http/Response/Headers.zep',
        'line' => 21,
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
          'name' => 'headers',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Http/Response/Headers.zep',
            'line' => 22,
            'char' => 27,
          ),
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 26,
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
            1 => 'static',
          ),
          'type' => 'method',
          'name' => '__set_state',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 27,
              'char' => 51,
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
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 29,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 29,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 29,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'dataHeaders',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 29,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 31,
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
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'self',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 31,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 31,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 33,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'dataHeaders',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 33,
                  'char' => 45,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 33,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'headers',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 33,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 33,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 33,
                'char' => 45,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'dataHeaders',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 34,
                    'char' => 43,
                  ),
                  'key' => 'key',
                  'value' => 'value',
                  'reverse' => 0,
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
                          'value' => 'headers',
                          'file' => '/app/phalcon/Http/Response/Headers.zep',
                          'line' => 35,
                          'char' => 25,
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
                              'file' => '/app/phalcon/Http/Response/Headers.zep',
                              'line' => 35,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Http/Response/Headers.zep',
                            'line' => 35,
                            'char' => 33,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Http/Response/Headers.zep',
                              'line' => 35,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Http/Response/Headers.zep',
                            'line' => 35,
                            'char' => 40,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Response/Headers.zep',
                        'line' => 35,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 36,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 37,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 39,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'headers',
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 39,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 40,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Restore a \\Phalcon\\Http\\Response\\Headers object
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
                  'value' => 'HeadersInterface',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 28,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 28,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Headers.zep',
            'line' => 28,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 27,
          'last-line' => 44,
          'char' => 26,
        ),
        1 => 
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 45,
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
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 47,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'headerValue',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 47,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 49,
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
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 49,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 49,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 49,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 49,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 51,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'headerValue',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 51,
                    'char' => 46,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 51,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 51,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 51,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 51,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 51,
                'char' => 46,
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
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 52,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 53,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 55,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'headerValue',
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 55,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 56,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets a header value from the internal bag
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
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 45,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 46,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Headers.zep',
            'line' => 46,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 45,
          'last-line' => 60,
          'char' => 19,
        ),
        2 => 
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 61,
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
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 63,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 63,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 63,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 63,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 63,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 63,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a header to be sent at the end of the request
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
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 62,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Headers.zep',
            'line' => 62,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 61,
          'last-line' => 68,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'remove',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'header',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 69,
              'char' => 41,
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
                  'variable' => 'headers',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 71,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 73,
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
                  'variable' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 73,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'headers',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 73,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 73,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 73,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 74,
              'char' => 13,
            ),
            2 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'headers',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 74,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'header',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 74,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 74,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 75,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'headers',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 75,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 75,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 76,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes a header to be sent at the end of the request
     *',
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 69,
          'last-line' => 80,
          'char' => 19,
        ),
        4 => 
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
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'headers',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 83,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 83,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reset set headers
     *',
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 81,
          'last-line' => 88,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'send',
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
                  'variable' => 'header',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 91,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 91,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 93,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'headers_sent',
                'call-type' => 1,
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 93,
                'char' => 27,
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
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 94,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 95,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 97,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 97,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'headers',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 97,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 97,
                'char' => 44,
              ),
              'key' => 'header',
              'value' => 'value',
              'reverse' => 0,
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
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 98,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 98,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 98,
                    'char' => 31,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'fcall',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'header',
                        'call-type' => 1,
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
                                  'type' => 'variable',
                                  'value' => 'header',
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 100,
                                  'char' => 28,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => ': ',
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 100,
                                  'char' => 33,
                                ),
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 100,
                                'char' => 33,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 100,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Http/Response/Headers.zep',
                              'line' => 100,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Http/Response/Headers.zep',
                            'line' => 100,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'bool',
                              'value' => 'true',
                              'file' => '/app/phalcon/Http/Response/Headers.zep',
                              'line' => 102,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Response/Headers.zep',
                            'line' => 102,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Response/Headers.zep',
                        'line' => 102,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 103,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'memstr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'header',
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 104,
                                'char' => 33,
                              ),
                              'file' => '/app/phalcon/Http/Response/Headers.zep',
                              'line' => 104,
                              'char' => 33,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => ':',
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 104,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Http/Response/Headers.zep',
                              'line' => 104,
                              'char' => 36,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Response/Headers.zep',
                          'line' => 104,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'substr',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'header',
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 104,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 104,
                                'char' => 54,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 104,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 104,
                                'char' => 57,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '5',
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 104,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 104,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Response/Headers.zep',
                            'line' => 104,
                            'char' => 63,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'HTTP/',
                            'file' => '/app/phalcon/Http/Response/Headers.zep',
                            'line' => 104,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Http/Response/Headers.zep',
                          'line' => 104,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Http/Response/Headers.zep',
                        'line' => 104,
                        'char' => 71,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'fcall',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'header',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'header',
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 106,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 106,
                                'char' => 31,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 108,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 108,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Response/Headers.zep',
                            'line' => 108,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Http/Response/Headers.zep',
                          'line' => 109,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'fcall',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'header',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'header',
                                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                                    'line' => 111,
                                    'char' => 32,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ': ',
                                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                                    'line' => 111,
                                    'char' => 36,
                                  ),
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 111,
                                  'char' => 36,
                                ),
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 111,
                                'char' => 36,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                                  'line' => 113,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Http/Response/Headers.zep',
                                'line' => 113,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Response/Headers.zep',
                            'line' => 113,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Http/Response/Headers.zep',
                          'line' => 114,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 115,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 116,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 118,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 118,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 119,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sends the headers to the client
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
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 90,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Headers.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 89,
          'last-line' => 123,
          'char' => 19,
        ),
        6 => 
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 124,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 124,
              'char' => 50,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'headers',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 126,
                      'char' => 31,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 126,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 126,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 127,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a header to be sent at the end of the request
     *',
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 124,
          'last-line' => 131,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRaw',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'header',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 132,
              'char' => 41,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'headers',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'header',
                      'file' => '/app/phalcon/Http/Response/Headers.zep',
                      'line' => 134,
                      'char' => 33,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Response/Headers.zep',
                    'line' => 134,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 134,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 135,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a raw header to be sent at the end of the request
     *',
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 132,
          'last-line' => 139,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'toArray',
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
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 142,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'headers',
                  'file' => '/app/phalcon/Http/Response/Headers.zep',
                  'line' => 142,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 142,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Http/Response/Headers.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current headers as an array
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
                'file' => '/app/phalcon/Http/Response/Headers.zep',
                'line' => 141,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Response/Headers.zep',
            'line' => 141,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Response/Headers.zep',
          'line' => 140,
          'last-line' => 144,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Response/Headers.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Response/Headers.zep',
    'line' => 20,
    'char' => 5,
  ),
);