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
    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Translate\\Adapter',
    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
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
        'name' => 'ArrayAccess',
        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
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
        'name' => 'Phalcon\\Translate\\Exception',
        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
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
        'name' => 'Phalcon\\Translate\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
        'line' => 15,
        'char' => 46,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
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
        'name' => 'Phalcon\\Translate\\InterpolatorFactory',
        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
        'line' => 16,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
    'line' => 22,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Translate\\Adapter\\NativeArray
 *
 * Allows to define translation lists using PHP arrays
 *',
    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
    'line' => 23,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'NativeArray',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ArrayAccess',
        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
        'line' => 24,
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
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'translate',
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
          'line' => 32,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'triggerError',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
            'line' => 33,
            'char' => 33,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
          'line' => 37,
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
              'name' => 'interpolator',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'InterpolatorFactory',
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 38,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 38,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 38,
              'char' => 83,
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
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 40,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'error',
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 40,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 42,
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
                      'value' => 'interpolator',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 42,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 42,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 42,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 42,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 42,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 44,
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 44,
                      'char' => 51,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'options',
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 44,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'content',
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 44,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 44,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 44,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 44,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 44,
                'char' => 51,
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
                          'value' => 'Translation content was not provided',
                          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                          'line' => 45,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 45,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 45,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 46,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 48,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'error',
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 48,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 48,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'triggerError',
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 48,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 48,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 48,
                'char' => 47,
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
                      'property' => 'triggerError',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'bool',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'error',
                          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                          'line' => 49,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 49,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 49,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 50,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 52,
              'char' => 10,
            ),
            4 => 
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
                      'value' => 'data',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 52,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 52,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 52,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 52,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 52,
                'char' => 43,
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
                          'value' => 'Translation data must be an array',
                          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                          'line' => 53,
                          'char' => 66,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 53,
                        'char' => 66,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 53,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 54,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 56,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'translate',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 56,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 56,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 57,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Translate\\Adapter\\NativeArray constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
            'line' => 39,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
          'line' => 38,
          'last-line' => 61,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'exists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 62,
              'char' => 41,
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
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 64,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translate',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 64,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 64,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'index',
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 64,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 64,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 64,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 65,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether is defined a translation key in the internal array
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
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 63,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
            'line' => 63,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
          'line' => 62,
          'last-line' => 69,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notFound',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 70,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 72,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 72,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'triggerError',
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 72,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 72,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 72,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 72,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 72,
                'char' => 51,
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
                            'type' => 'string',
                            'value' => 'Cannot find translation key: ',
                            'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                            'line' => 73,
                            'char' => 63,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'index',
                            'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                            'line' => 73,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                          'line' => 73,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 73,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 73,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 74,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 76,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'index',
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 76,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 77,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Whenever a key is not found this medhod will be called
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
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 71,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
          'line' => 70,
          'last-line' => 81,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'query',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'index',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 82,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'placeholders',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 82,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 82,
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
                  'variable' => 'translation',
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 84,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 86,
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
                    'value' => 'translation',
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 86,
                    'char' => 55,
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
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 86,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'translate',
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 86,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 86,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'index',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 86,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 86,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 86,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 86,
                'char' => 55,
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
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 87,
                      'char' => 25,
                    ),
                    'name' => 'notFound',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'index',
                          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                          'line' => 87,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                        'line' => 87,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 87,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 88,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 90,
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
                  'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                  'line' => 90,
                  'char' => 21,
                ),
                'name' => 'replacePlaceholders',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'translation',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 90,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 90,
                    'char' => 53,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'placeholders',
                      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                      'line' => 90,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                    'line' => 90,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 90,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
              'line' => 91,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the translation related to the given key
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
                'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
                'line' => 83,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
            'line' => 83,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
          'line' => 82,
          'last-line' => 92,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
      'line' => 23,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Translate/Adapter/NativeArray.zep',
    'line' => 23,
    'char' => 5,
  ),
);