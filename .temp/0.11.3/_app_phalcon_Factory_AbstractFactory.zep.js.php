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
    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Factory',
    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
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
        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
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
        'name' => 'Phalcon\\Factory\\Exception',
        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
        'line' => 14,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
    'line' => 16,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'AbstractFactory',
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
          'name' => 'mapper',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Factory/AbstractFactory.zep',
            'line' => 21,
            'char' => 26,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
          'line' => 25,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'services',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Factory/AbstractFactory.zep',
            'line' => 26,
            'char' => 28,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
          'line' => 30,
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
          'name' => 'checkService',
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
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 31,
              'char' => 49,
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
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 33,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mapper',
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 33,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 33,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 33,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                      'line' => 33,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 33,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 33,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 33,
                'char' => 47,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Service ',
                              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                              'line' => 34,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                              'line' => 34,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                            'line' => 34,
                            'char' => 49,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' is not registered',
                            'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                            'line' => 34,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 34,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 34,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 34,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 35,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 36,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a service exists and throws an exception
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Factory/AbstractFactory.zep',
            'line' => 32,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
          'line' => 31,
          'last-line' => 40,
          'char' => 22,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'checkConfig',
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
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 41,
              'char' => 46,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                      'line' => 43,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 43,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 43,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 43,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'instanceof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'config',
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 43,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'Config',
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 43,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 43,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 43,
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
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 44,
                          'char' => 33,
                        ),
                        'name' => 'toArray',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 44,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                      'line' => 44,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 45,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 47,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                      'line' => 47,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 47,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 47,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 47,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 47,
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
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 50,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 50,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 50,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 51,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 53,
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
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 53,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'adapter',
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 53,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                      'line' => 53,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 53,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 53,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 53,
                'char' => 44,
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
                          'value' => 'You must provide \'adapter\' option in factory config parameter.',
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 56,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 56,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 56,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 57,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 59,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'config',
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 59,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 60,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks the config if it is a valid object
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
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 42,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Factory/AbstractFactory.zep',
            'line' => 42,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
          'line' => 41,
          'last-line' => 64,
          'char' => 22,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'abstract',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getAdapters',
          'docblock' => '**
     * Returns the adapters for the factory
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
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 65,
                'char' => 55,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Factory/AbstractFactory.zep',
            'line' => 65,
            'char' => 55,
          ),
          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
          'line' => 65,
          'last-line' => 69,
          'char' => 31,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'init',
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
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 70,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 70,
              'char' => 49,
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
                  'variable' => 'adapters',
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 72,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 72,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'service',
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 72,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 74,
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
                  'variable' => 'adapters',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                      'line' => 74,
                      'char' => 29,
                    ),
                    'name' => 'getAdapters',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 74,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 74,
                  'char' => 43,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'adapters',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_merge',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'adapters',
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 75,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 75,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'services',
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 75,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 75,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 75,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 75,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 77,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'adapters',
                'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                'line' => 77,
                'char' => 39,
              ),
              'key' => 'name',
              'value' => 'service',
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
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'mapper',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 78,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'service',
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 78,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                      'line' => 78,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 79,
                  'char' => 17,
                ),
                1 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'list',
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
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 79,
                          'char' => 24,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'services',
                          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                          'line' => 79,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 79,
                        'char' => 33,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                        'line' => 79,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                      'line' => 79,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                    'line' => 79,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Factory/AbstractFactory.zep',
                  'line' => 80,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Factory/AbstractFactory.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * AdapterFactory constructor.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Factory/AbstractFactory.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Factory/AbstractFactory.zep',
          'line' => 70,
          'last-line' => 82,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Factory/AbstractFactory.zep',
      'line' => 16,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Factory/AbstractFactory.zep',
    'line' => 16,
    'char' => 5,
  ),
);