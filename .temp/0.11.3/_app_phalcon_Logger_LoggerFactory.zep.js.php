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
    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger',
    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
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
        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
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
        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
        'line' => 14,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
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
        'name' => 'Phalcon\\Logger\\Logger',
        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
        'line' => 15,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
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
        'name' => 'Phalcon\\Logger\\AdapterFactory',
        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
        'line' => 16,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
    'line' => 22,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PhalconNG\\Logger\\LoggerFactory
 *
 * Logger factory
 *',
    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
    'line' => 23,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'LoggerFactory',
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
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'adapterFactory',
          'docblock' => '**
     * @var AdapterFactory
     *',
          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
          'line' => 30,
          'char' => 10,
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
                'value' => 'AdapterFactory',
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 30,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 30,
              'char' => 57,
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
                  'property' => 'adapterFactory',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'factory',
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 32,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 32,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 33,
              'char' => 5,
            ),
          ),
          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
          'line' => 30,
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
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
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
                  'variable' => 'adapter',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 40,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'adapterClass',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 40,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'adapterFileName',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 40,
                  'char' => 51,
                ),
                3 => 
                array (
                  'variable' => 'adapterOptions',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 40,
                  'char' => 67,
                ),
                4 => 
                array (
                  'variable' => 'adapters',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 41,
                  'char' => 21,
                ),
                5 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 41,
                  'char' => 27,
                ),
                6 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 41,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 42,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 42,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 44,
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
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 44,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 44,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 44,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 44,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'instanceof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'config',
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 44,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'Config',
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 44,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 44,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 44,
                'char' => 64,
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
                      'variable' => 'config',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'config',
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 45,
                          'char' => 33,
                        ),
                        'name' => 'toArray',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 45,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 45,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 46,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 48,
              'char' => 10,
            ),
            3 => 
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
                      'value' => 'config',
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 48,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 48,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 48,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 48,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 48,
                'char' => 45,
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
                          'value' => 'Config must be array or Phalcon\\\\Config object',
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 51,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 51,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 51,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 52,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 54,
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
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 54,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'name',
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 54,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 54,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 54,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 54,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 54,
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
                          'value' => 'You must provide \'name\' option in factory config parameter.',
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 57,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 57,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 57,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 58,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 60,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 60,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 60,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 60,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 60,
                  'char' => 36,
                ),
                1 => 
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
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 61,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 61,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'options',
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 61,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 61,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 61,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 61,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 61,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 61,
                  'char' => 53,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'adapters',
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
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 62,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 62,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'adapters',
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 62,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 62,
                        'char' => 49,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 62,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 62,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 62,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 62,
                  'char' => 54,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 63,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 63,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 65,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'adapters',
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 65,
                'char' => 33,
              ),
              'value' => 'adapter',
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'adapterClass',
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
                              'value' => 'adapter',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 66,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 66,
                            'char' => 51,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'adapter',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 66,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 66,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 66,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 66,
                      'char' => 61,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'adapterFileName',
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
                              'value' => 'adapter',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 67,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 67,
                            'char' => 51,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'name',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 67,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 67,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 67,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 67,
                      'char' => 58,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'adapterOptions',
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
                              'value' => 'adapter',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 68,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 68,
                            'char' => 51,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'options',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 68,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 68,
                            'char' => 60,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'empty-array',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 68,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 68,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 68,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 68,
                      'char' => 65,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 70,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'data',
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
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 70,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'adapterFactory',
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 70,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                          'line' => 70,
                          'char' => 47,
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
                              'value' => 'adapterClass',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 71,
                              'char' => 29,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 71,
                            'char' => 29,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'adapterFileName',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 72,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 72,
                            'char' => 32,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'adapterOptions',
                              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                              'line' => 74,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                            'line' => 74,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                        'line' => 74,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 74,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 75,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 77,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 77,
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
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 77,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 77,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 77,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 77,
                    'char' => 44,
                  ),
                ),
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 77,
                'char' => 45,
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 78,
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
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 39,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
            'line' => 39,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
          'line' => 38,
          'last-line' => 87,
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
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 88,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'adapters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 88,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 88,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'Logger',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 90,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 90,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapters',
                      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                      'line' => 90,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                    'line' => 90,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 90,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Logger/LoggerFactory.zep',
              'line' => 91,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a Logger object
     *
     * @param string $name
     * @param array  $adapters
     *
     * @return Logger
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
                  'value' => 'Logger',
                  'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                  'line' => 89,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/LoggerFactory.zep',
                'line' => 89,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/LoggerFactory.zep',
            'line' => 89,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/LoggerFactory.zep',
          'line' => 88,
          'last-line' => 92,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/LoggerFactory.zep',
      'line' => 23,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/LoggerFactory.zep',
    'line' => 23,
    'char' => 5,
  ),
);