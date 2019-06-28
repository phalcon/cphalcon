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
    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage',
    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
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
        'file' => '/app/phalcon/Storage/AdapterFactory.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
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
        'name' => 'Phalcon\\Storage\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Storage/AdapterFactory.zep',
        'line' => 14,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
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
        'name' => 'Phalcon\\Storage\\SerializerFactory',
        'file' => '/app/phalcon/Storage/AdapterFactory.zep',
        'line' => 15,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
    'line' => 17,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'AdapterFactory',
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
          'name' => 'serializerFactory',
          'docblock' => '**
     * @var <SerializerFactory>
     *',
          'file' => '/app/phalcon/Storage/AdapterFactory.zep',
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
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 27,
                'char' => 59,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 27,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 27,
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
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 27,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 27,
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
                  'property' => 'serializerFactory',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'factory',
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 29,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 29,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 31,
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
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 31,
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
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 31,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 31,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 31,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 32,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * AdapterFactory constructor.
     *',
          'file' => '/app/phalcon/Storage/AdapterFactory.zep',
          'line' => 27,
          'last-line' => 36,
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
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 37,
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
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 37,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 37,
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
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 39,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 41,
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
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 41,
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
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 41,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 41,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 41,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 43,
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
                        'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                        'line' => 43,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'services',
                        'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                        'line' => 43,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 43,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 43,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 43,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 43,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 43,
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
                            'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                            'line' => 44,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                            'line' => 44,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                          'line' => 44,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                          'line' => 44,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                        'line' => 44,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 44,
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
                          'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                          'line' => 45,
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
                                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                                'line' => 45,
                                'char' => 62,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'serializerFactory',
                                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                                'line' => 45,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                              'line' => 45,
                              'char' => 80,
                            ),
                            'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                            'line' => 45,
                            'char' => 80,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                              'line' => 45,
                              'char' => 89,
                            ),
                            'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                            'line' => 45,
                            'char' => 89,
                          ),
                        ),
                        'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                        'line' => 45,
                        'char' => 90,
                      ),
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 45,
                      'char' => 90,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 46,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 48,
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
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 48,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 48,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 48,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 48,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 48,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 49,
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
                  'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                  'line' => 38,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 38,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/AdapterFactory.zep',
            'line' => 38,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/AdapterFactory.zep',
          'line' => 37,
          'last-line' => 51,
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
                      'value' => 'apcu',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 54,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Adapter\\\\Apcu',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 54,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 54,
                    'char' => 61,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'libmemcached',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 55,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Adapter\\\\Libmemcached',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 55,
                      'char' => 69,
                    ),
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 55,
                    'char' => 69,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'memory',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 56,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Adapter\\\\Memory',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 56,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 56,
                    'char' => 63,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'redis',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 57,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Adapter\\\\Redis',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 57,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 57,
                    'char' => 62,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'stream',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 58,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Adapter\\\\Stream',
                      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                      'line' => 59,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                    'line' => 59,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 59,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Storage/AdapterFactory.zep',
              'line' => 60,
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
                'file' => '/app/phalcon/Storage/AdapterFactory.zep',
                'line' => 52,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/AdapterFactory.zep',
            'line' => 52,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/AdapterFactory.zep',
          'line' => 51,
          'last-line' => 61,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Storage/AdapterFactory.zep',
      'line' => 17,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/AdapterFactory.zep',
    'line' => 17,
    'char' => 5,
  ),
);