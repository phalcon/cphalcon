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
    'file' => '/app/phalcon/Image/ImageFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Image',
    'file' => '/app/phalcon/Image/ImageFactory.zep',
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
        'file' => '/app/phalcon/Image/ImageFactory.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Image/ImageFactory.zep',
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
        'file' => '/app/phalcon/Image/ImageFactory.zep',
        'line' => 14,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Image/ImageFactory.zep',
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
        'file' => '/app/phalcon/Image/ImageFactory.zep',
        'line' => 15,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Image/ImageFactory.zep',
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
        'name' => 'Phalcon\\Image\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Image/ImageFactory.zep',
        'line' => 16,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Image/ImageFactory.zep',
    'line' => 20,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Image/ImageFactory
 *',
    'file' => '/app/phalcon/Image/ImageFactory.zep',
    'line' => 21,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'ImageFactory',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractFactory',
    'definition' => 
    array (
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
              'name' => 'services',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 26,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 26,
              'char' => 53,
            ),
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 28,
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
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 28,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 28,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 28,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 29,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * TagFactory constructor.
     *',
          'file' => '/app/phalcon/Image/ImageFactory.zep',
          'line' => 26,
          'last-line' => 33,
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
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 34,
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
                  'variable' => 'height',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 36,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'file',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 36,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 36,
                  'char' => 31,
                ),
                3 => 
                array (
                  'variable' => 'width',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 36,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 38,
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
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 38,
                      'char' => 27,
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
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 38,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 38,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 38,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 38,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 40,
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
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'config',
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 40,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'file',
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 40,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 40,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 40,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 40,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 40,
                'char' => 41,
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
                          'value' => 'You must provide \'file\' option in factory config parameter.',
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 43,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 43,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 43,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 44,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 46,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 46,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'adapter',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 46,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 46,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 46,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 48,
              'char' => 13,
            ),
            4 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'config',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 48,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'adapter',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 48,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 48,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 50,
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
                  'variable' => 'file',
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
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 50,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 50,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'file',
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 50,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 50,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 50,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 50,
                  'char' => 44,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'height',
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
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 51,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 51,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'height',
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 51,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 51,
                        'char' => 45,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 51,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 51,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 51,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 51,
                  'char' => 52,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'width',
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
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 52,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 52,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'width',
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 52,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 52,
                        'char' => 44,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 52,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 52,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 52,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 52,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 54,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 54,
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
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 54,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 54,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'file',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 54,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 54,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'width',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 54,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 54,
                    'char' => 51,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'height',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 54,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 54,
                    'char' => 59,
                  ),
                ),
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 54,
                'char' => 60,
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 55,
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 35,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 35,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Image/ImageFactory.zep',
            'line' => 35,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Image/ImageFactory.zep',
          'line' => 34,
          'last-line' => 59,
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
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 61,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 62,
              'char' => 21,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'width',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 63,
                'char' => 25,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 63,
              'char' => 25,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'height',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 65,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 65,
              'char' => 5,
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
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 67,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 69,
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
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 69,
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
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 69,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 69,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 69,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 71,
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
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 71,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'services',
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 71,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 71,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 71,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 71,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 71,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 71,
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
                            'file' => '/app/phalcon/Image/ImageFactory.zep',
                            'line' => 72,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Image/ImageFactory.zep',
                            'line' => 72,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 72,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 72,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 72,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 72,
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
                          'file' => '/app/phalcon/Image/ImageFactory.zep',
                          'line' => 73,
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
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Image/ImageFactory.zep',
                              'line' => 73,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Image/ImageFactory.zep',
                            'line' => 73,
                            'char' => 61,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'width',
                              'file' => '/app/phalcon/Image/ImageFactory.zep',
                              'line' => 73,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Image/ImageFactory.zep',
                            'line' => 73,
                            'char' => 68,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'height',
                              'file' => '/app/phalcon/Image/ImageFactory.zep',
                              'line' => 73,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Image/ImageFactory.zep',
                            'line' => 73,
                            'char' => 76,
                          ),
                        ),
                        'file' => '/app/phalcon/Image/ImageFactory.zep',
                        'line' => 73,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 73,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 74,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 76,
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
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 76,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 76,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 76,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 76,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 76,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 77,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Creates a new instance
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Image/ImageFactory.zep',
                  'line' => 66,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 66,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Image/ImageFactory.zep',
            'line' => 66,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Image/ImageFactory.zep',
          'line' => 60,
          'last-line' => 79,
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
                      'value' => 'gd',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 82,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Image\\\\Adapter\\\\Gd',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 82,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 82,
                    'char' => 52,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'imagick',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 83,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Image\\\\Adapter\\\\Imagick',
                      'file' => '/app/phalcon/Image/ImageFactory.zep',
                      'line' => 84,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Image/ImageFactory.zep',
                    'line' => 84,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 84,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Image/ImageFactory.zep',
              'line' => 85,
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
                'file' => '/app/phalcon/Image/ImageFactory.zep',
                'line' => 80,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Image/ImageFactory.zep',
            'line' => 80,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Image/ImageFactory.zep',
          'line' => 79,
          'last-line' => 86,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Image/ImageFactory.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Image/ImageFactory.zep',
    'line' => 21,
    'char' => 5,
  ),
);