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
    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Cache',
    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Cache/AdapterFactory.zep',
        'line' => 13,
        'char' => 42,
      ),
    ),
    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
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
        'name' => 'Phalcon\\Cache\\Exception\\Exception',
        'file' => '/app/phalcon/Cache/AdapterFactory.zep',
        'line' => 14,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
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
        'name' => 'Phalcon\\Factory\\AbstractFactory',
        'file' => '/app/phalcon/Cache/AdapterFactory.zep',
        'line' => 15,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
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
        'name' => 'Phalcon\\Storage\\SerializerFactory',
        'file' => '/app/phalcon/Cache/AdapterFactory.zep',
        'line' => 16,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
    'line' => 20,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Factory to create Cache adapters
 *',
    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
    'line' => 21,
    'char' => 5,
  ),
  7 => 
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
     * @var SerializerFactory
     *',
          'file' => '/app/phalcon/Cache/AdapterFactory.zep',
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
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 31,
                'char' => 59,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 31,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 31,
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
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 31,
                'char' => 89,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 31,
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
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 33,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 33,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 35,
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
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 35,
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
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 35,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 35,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 35,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 36,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * AdapterFactory constructor.
     *',
          'file' => '/app/phalcon/Cache/AdapterFactory.zep',
          'line' => 31,
          'last-line' => 40,
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
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 41,
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
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 41,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 41,
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
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 43,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 45,
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
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 45,
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
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 45,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 45,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 45,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 47,
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
                        'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                        'line' => 47,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'services',
                        'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                        'line' => 47,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 47,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 47,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 47,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 47,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 47,
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
                            'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                            'line' => 48,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                            'line' => 48,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                          'line' => 48,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                          'line' => 48,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                        'line' => 48,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 48,
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
                          'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                          'line' => 49,
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
                                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                                'line' => 49,
                                'char' => 62,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'serializerFactory',
                                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                                'line' => 49,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                              'line' => 49,
                              'char' => 80,
                            ),
                            'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                            'line' => 49,
                            'char' => 80,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'options',
                              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                              'line' => 49,
                              'char' => 89,
                            ),
                            'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                            'line' => 49,
                            'char' => 89,
                          ),
                        ),
                        'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                        'line' => 49,
                        'char' => 90,
                      ),
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 49,
                      'char' => 90,
                    ),
                  ),
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 50,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 52,
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
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 52,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 52,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 52,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 52,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 52,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 53,
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
                  'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                  'line' => 42,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 42,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/AdapterFactory.zep',
            'line' => 42,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/AdapterFactory.zep',
          'line' => 41,
          'last-line' => 57,
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
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 61,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Cache\\\\Adapter\\\\Apcu',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 61,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 61,
                    'char' => 59,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'libmemcached',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 62,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Cache\\\\Adapter\\\\Libmemcached',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 62,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 62,
                    'char' => 67,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'memory',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 63,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Cache\\\\Adapter\\\\Memory',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 63,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 63,
                    'char' => 61,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'redis',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 64,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Cache\\\\Adapter\\\\Redis',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 64,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 64,
                    'char' => 60,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'stream',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 65,
                      'char' => 26,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Cache\\\\Adapter\\\\Stream',
                      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                      'line' => 66,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                    'line' => 66,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 66,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Cache/AdapterFactory.zep',
              'line' => 67,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the available adapters
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
                'file' => '/app/phalcon/Cache/AdapterFactory.zep',
                'line' => 59,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Cache/AdapterFactory.zep',
            'line' => 59,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Cache/AdapterFactory.zep',
          'line' => 58,
          'last-line' => 68,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Cache/AdapterFactory.zep',
      'line' => 21,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Cache/AdapterFactory.zep',
    'line' => 21,
    'char' => 5,
  ),
);