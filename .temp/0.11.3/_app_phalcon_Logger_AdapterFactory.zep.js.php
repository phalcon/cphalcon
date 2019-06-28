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
    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger',
    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
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
        'name' => 'Phalcon\\Factory\\AbstractFactory',
        'file' => '/app/phalcon/Logger/AdapterFactory.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
    'line' => 15,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'AdapterFactory',
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
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 20,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 20,
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
                  'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                  'line' => 22,
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
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 22,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                    'line' => 22,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 22,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 23,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * AdapterFactory constructor.
     *',
          'file' => '/app/phalcon/Logger/AdapterFactory.zep',
          'line' => 20,
          'last-line' => 27,
          'char' => 19,
        ),
        1 => 
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
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 29,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fileName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 30,
              'char' => 25,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 32,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 32,
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
                  'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                  'line' => 34,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 36,
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
                  'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                  'line' => 36,
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
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 36,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                    'line' => 36,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 36,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 38,
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
                        'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                        'line' => 38,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'services',
                        'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                        'line' => 38,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 38,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 38,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                    'line' => 38,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                  'line' => 38,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 38,
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
                            'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                            'line' => 39,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                            'line' => 39,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                          'line' => 39,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                          'line' => 39,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                        'line' => 39,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 39,
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
                          'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                          'line' => 40,
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
                              'value' => 'fileName',
                              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                              'line' => 40,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                            'line' => 40,
                            'char' => 65,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                              'line' => 40,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                            'line' => 40,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                        'line' => 40,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 40,
                      'char' => 75,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                  'line' => 41,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 43,
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
                    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                    'line' => 43,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                    'line' => 43,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                  'line' => 43,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                  'line' => 43,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 43,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 44,
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                  'line' => 33,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 33,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/AdapterFactory.zep',
            'line' => 33,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/AdapterFactory.zep',
          'line' => 28,
          'last-line' => 46,
          'char' => 19,
        ),
        2 => 
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
                      'value' => 'noop',
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 49,
                      'char' => 20,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Logger\\\\Adapter\\\\Noop',
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 49,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                    'line' => 49,
                    'char' => 54,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'stream',
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 50,
                      'char' => 20,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Logger\\\\Adapter\\\\Stream',
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 50,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                    'line' => 50,
                    'char' => 56,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'syslog',
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 51,
                      'char' => 20,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Logger\\\\Adapter\\\\Syslog',
                      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                      'line' => 52,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                    'line' => 52,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 52,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Logger/AdapterFactory.zep',
              'line' => 53,
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
                'file' => '/app/phalcon/Logger/AdapterFactory.zep',
                'line' => 47,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/AdapterFactory.zep',
            'line' => 47,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/AdapterFactory.zep',
          'line' => 46,
          'last-line' => 54,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Logger/AdapterFactory.zep',
      'line' => 15,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/AdapterFactory.zep',
    'line' => 15,
    'char' => 5,
  ),
);