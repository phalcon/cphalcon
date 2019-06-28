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
    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Storage',
    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
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
        'file' => '/app/phalcon/Storage/SerializerFactory.zep',
        'line' => 13,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
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
        'name' => 'Phalcon\\Storage\\Serializer\\SerializerInterface',
        'file' => '/app/phalcon/Storage/SerializerFactory.zep',
        'line' => 14,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
    'line' => 16,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'SerializerFactory',
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
                'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                'line' => 23,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Storage/SerializerFactory.zep',
              'line' => 23,
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
                  'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                  'line' => 25,
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
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 25,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 25,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                'line' => 25,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Storage/SerializerFactory.zep',
              'line' => 26,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * SerializerFactory constructor.
     *
     * @param array services
     *',
          'file' => '/app/phalcon/Storage/SerializerFactory.zep',
          'line' => 23,
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
              'file' => '/app/phalcon/Storage/SerializerFactory.zep',
              'line' => 34,
              'char' => 45,
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
                  'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                  'line' => 36,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Storage/SerializerFactory.zep',
              'line' => 38,
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
                  'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                  'line' => 38,
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
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 38,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 38,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                'line' => 38,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Storage/SerializerFactory.zep',
              'line' => 40,
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
                        'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                        'line' => 40,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'services',
                        'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                        'line' => 40,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 40,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 40,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 40,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                  'line' => 40,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                'line' => 40,
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
                            'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                            'line' => 41,
                            'char' => 45,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                            'line' => 41,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                          'line' => 41,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                          'line' => 41,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                        'line' => 41,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 41,
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
                          'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                          'line' => 42,
                          'char' => 36,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'definition',
                        'dynamic' => 1,
                        'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                        'line' => 42,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 42,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                  'line' => 43,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Storage/SerializerFactory.zep',
              'line' => 45,
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
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 45,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 45,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                  'line' => 45,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                  'line' => 45,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                'line' => 45,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Storage/SerializerFactory.zep',
              'line' => 46,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * @param string name
     *
     * @return mixed
     * @throws Exception
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
                  'value' => 'SerializerInterface',
                  'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                  'line' => 35,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                'line' => 35,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/SerializerFactory.zep',
            'line' => 35,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/SerializerFactory.zep',
          'line' => 34,
          'last-line' => 48,
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
                      'value' => 'base64',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 51,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Serializer\\\\Base64',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 51,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 51,
                    'char' => 62,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'igbinary',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 52,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Serializer\\\\Igbinary',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 52,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 52,
                    'char' => 64,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'json',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 53,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Serializer\\\\Json',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 53,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 53,
                    'char' => 60,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'msgpack',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 54,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Serializer\\\\Msgpack',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 54,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 54,
                    'char' => 63,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'none',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 55,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Serializer\\\\None',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 55,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 55,
                    'char' => 60,
                  ),
                  5 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'php',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 56,
                      'char' => 22,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Storage\\\\Serializer\\\\Php',
                      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                      'line' => 57,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                    'line' => 57,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                'line' => 57,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Storage/SerializerFactory.zep',
              'line' => 58,
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
                'file' => '/app/phalcon/Storage/SerializerFactory.zep',
                'line' => 49,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Storage/SerializerFactory.zep',
            'line' => 49,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Storage/SerializerFactory.zep',
          'line' => 48,
          'last-line' => 59,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Storage/SerializerFactory.zep',
      'line' => 16,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Storage/SerializerFactory.zep',
    'line' => 16,
    'char' => 5,
  ),
);