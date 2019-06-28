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
    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Translate',
    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
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
        'name' => 'Phalcon\\Config\\Config',
        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
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
        'name' => 'Phalcon\\Factory\\AbstractFactory',
        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
        'line' => 14,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
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
        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
        'line' => 15,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
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
        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
        'line' => 16,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
    'line' => 18,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'TranslateFactory',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractFactory',
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
          'name' => 'interpolator',
          'docblock' => '**
     * @var InterpolatorFactory
     *',
          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
          'line' => 27,
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
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 28,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 28,
              'char' => 67,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'services',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 28,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 28,
              'char' => 89,
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
                  'property' => 'interpolator',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'interpolator',
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 30,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 30,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 32,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 32,
                  'char' => 14,
                ),
                'name' => 'init',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'services',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 32,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 32,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 32,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 33,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * AdapterFactory constructor.
     *',
          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
          'line' => 28,
          'last-line' => 37,
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
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 38,
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
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 40,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 40,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 42,
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
                  'variable' => 'config',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 42,
                      'char' => 28,
                    ),
                    'name' => 'checkConfig',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'config',
                          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                          'line' => 42,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                        'line' => 42,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 42,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 42,
                  'char' => 48,
                ),
                1 => 
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
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 43,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'adapter',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 43,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 43,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 43,
                  'char' => 38,
                ),
                2 => 
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
                          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                          'line' => 44,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                        'line' => 44,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'options',
                          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                          'line' => 44,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                        'line' => 44,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                          'line' => 44,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                        'line' => 44,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 44,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 44,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 46,
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
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 46,
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
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 46,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 46,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 46,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 46,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 46,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 47,
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
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 39,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/TranslateFactory.zep',
            'line' => 39,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
          'line' => 38,
          'last-line' => 51,
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
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 52,
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
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 52,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 52,
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
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 54,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 56,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 56,
                  'char' => 14,
                ),
                'name' => 'checkService',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 56,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 56,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 56,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 58,
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
                        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                        'line' => 58,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'services',
                        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                        'line' => 58,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 58,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 58,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 58,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 58,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 58,
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
                      'variable' => 'definition',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                            'line' => 59,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                            'line' => 59,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                          'line' => 59,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                          'line' => 59,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                        'line' => 59,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 59,
                      'char' => 58,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'services',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                          'line' => 60,
                          'char' => 36,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'definition',
                        'dynamic' => 1,
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
                                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                                'line' => 60,
                                'char' => 62,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'interpolator',
                                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                                'line' => 60,
                                'char' => 75,
                              ),
                              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                              'line' => 60,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                            'line' => 60,
                            'char' => 75,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                              'line' => 60,
                              'char' => 84,
                            ),
                            'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                            'line' => 60,
                            'char' => 84,
                          ),
                        ),
                        'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                        'line' => 60,
                        'char' => 85,
                      ),
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 60,
                      'char' => 85,
                    ),
                  ),
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 61,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 63,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 63,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 63,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 63,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 63,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 63,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create a new instance of the adapter
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
                  'value' => 'AbstractAdapter',
                  'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                  'line' => 53,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 53,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/TranslateFactory.zep',
            'line' => 53,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
          'line' => 52,
          'last-line' => 66,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getAdapters',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
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
                      'value' => 'csv',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 69,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Translate\\\\Adapter\\\\Csv',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 69,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 69,
                    'char' => 57,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'gettext',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 70,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Translate\\\\Adapter\\\\Gettext',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 70,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 70,
                    'char' => 61,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 71,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Translate\\\\Adapter\\\\NativeArray',
                      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                      'line' => 72,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                    'line' => 72,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 72,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Translate/TranslateFactory.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Translate/TranslateFactory.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Translate/TranslateFactory.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Translate/TranslateFactory.zep',
          'line' => 66,
          'last-line' => 74,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Translate/TranslateFactory.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Translate/TranslateFactory.zep',
    'line' => 18,
    'char' => 5,
  ),
);