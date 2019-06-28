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
    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Micro',
    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\BinderInterface',
        'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
        'line' => 13,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
    'line' => 19,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Micro\\LazyLoader
 *
 * Lazy-Load of handlers for Mvc\\Micro using auto-loading
 *',
    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
    'line' => 20,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'LazyLoader',
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
          'name' => 'handler',
          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
          'line' => 24,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'definition',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 24,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
          'line' => 28,
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
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 29,
              'char' => 51,
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
                  'property' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                    'line' => 31,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 31,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 32,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Micro\\LazyLoader constructor
     *',
          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
          'line' => 29,
          'last-line' => 39,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'callMethod',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'method',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 40,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'arguments',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 40,
              'char' => 57,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'modelBinder',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'BinderInterface',
                'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                'line' => 40,
                'char' => 87,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                'line' => 40,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 40,
              'char' => 95,
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
                  'variable' => 'handler',
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 42,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 42,
                  'char' => 33,
                ),
                2 => 
                array (
                  'variable' => 'bindCacheKey',
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 42,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 44,
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
                  'variable' => 'handler',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 44,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 44,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                    'line' => 44,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 44,
                  'char' => 39,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 45,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 45,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                    'line' => 45,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 45,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 47,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'handler',
                    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                    'line' => 47,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 47,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 47,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                'line' => 47,
                'char' => 37,
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
                      'variable' => 'handler',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'definition',
                        'dynamic' => 1,
                        'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                        'line' => 48,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 48,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 50,
                  'char' => 15,
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
                      'property' => 'handler',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'handler',
                        'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                        'line' => 50,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 50,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 51,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 53,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'modelBinder',
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 53,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 53,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                'line' => 53,
                'char' => 32,
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
                      'variable' => 'bindCacheKey',
                      'expr' => 
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
                              'value' => '_PHMB_',
                              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                              'line' => 54,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'definition',
                              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                              'line' => 54,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                            'line' => 54,
                            'char' => 52,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '_',
                            'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                            'line' => 54,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                          'line' => 54,
                          'char' => 56,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'method',
                          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                          'line' => 54,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                        'line' => 54,
                        'char' => 64,
                      ),
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 54,
                      'char' => 64,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 56,
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
                      'variable' => 'arguments',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'modelBinder',
                          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                          'line' => 56,
                          'char' => 41,
                        ),
                        'name' => 'bindToHandler',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'handler',
                              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                              'line' => 57,
                              'char' => 24,
                            ),
                            'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                            'line' => 57,
                            'char' => 24,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'arguments',
                              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                              'line' => 58,
                              'char' => 26,
                            ),
                            'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                            'line' => 58,
                            'char' => 26,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'bindCacheKey',
                              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                              'line' => 59,
                              'char' => 29,
                            ),
                            'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                            'line' => 59,
                            'char' => 29,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'method',
                              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                              'line' => 61,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                            'line' => 61,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                        'line' => 61,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 61,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                  'line' => 62,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 67,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'call_user_func_array',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array',
                      'left' => 
                      array (
                        0 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handler',
                            'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                            'line' => 68,
                            'char' => 21,
                          ),
                          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                          'line' => 68,
                          'char' => 21,
                        ),
                        1 => 
                        array (
                          'value' => 
                          array (
                            'type' => 'variable',
                            'value' => 'method',
                            'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                            'line' => 68,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                          'line' => 68,
                          'char' => 29,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 68,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                    'line' => 68,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'arguments',
                      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                      'line' => 70,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                    'line' => 70,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
                'line' => 70,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
              'line' => 71,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Calling __call method
     *
     * @param  array arguments
     * @return mixed
     *',
          'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
          'line' => 40,
          'last-line' => 72,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Micro/LazyLoader.zep',
    'line' => 20,
    'char' => 5,
  ),
);