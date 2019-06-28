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
    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations\\Adapter',
    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
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
        'name' => 'Phalcon\\Annotations\\Adapter\\AbstractAdapter',
        'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
        'line' => 13,
        'char' => 48,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
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
        'name' => 'Phalcon\\Annotations\\Reflection',
        'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
        'line' => 14,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
    'line' => 24,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Stores the parsed annotations in APCu. This adapter is suitable for production
 *
 *```php
 * use Phalcon\\Annotations\\Adapter\\Apcu;
 *
 * $annotations = new Apcu();
 *```
 *',
    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
    'line' => 25,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Apcu',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
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
          'name' => 'prefix',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
            'line' => 30,
            'char' => 24,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
          'line' => 34,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'ttl',
          'default' => 
          array (
            'type' => 'int',
            'value' => '172800',
            'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
            'line' => 35,
            'char' => 27,
          ),
          'docblock' => '**
     * @var int
     *',
          'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
          'line' => 39,
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
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 40,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 40,
              'char' => 51,
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
                  'variable' => 'prefix',
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 42,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'ttl',
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 42,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 44,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'prefix',
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 44,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                    'line' => 44,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                    'line' => 44,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 44,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 44,
                'char' => 42,
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
                      'property' => 'prefix',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'prefix',
                        'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                        'line' => 45,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                      'line' => 45,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 46,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 48,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'ttl',
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 48,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                    'line' => 48,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'lifetime',
                    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                    'line' => 48,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 48,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 48,
                'char' => 41,
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
                      'property' => 'ttl',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ttl',
                        'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                        'line' => 49,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                      'line' => 49,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 50,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 51,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Annotations\\Adapter\\Apcu constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
            'line' => 41,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
          'line' => 40,
          'last-line' => 55,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'read',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 56,
              'char' => 37,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'apcu_fetch',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strtolower',
                      'call-type' => 1,
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
                                'value' => '_PHAN',
                                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                                'line' => 60,
                                'char' => 23,
                              ),
                              'right' => 
                              array (
                                'type' => 'property-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                                  'line' => 60,
                                  'char' => 30,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'prefix',
                                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                                  'line' => 60,
                                  'char' => 38,
                                ),
                                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                                'line' => 60,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                              'line' => 60,
                              'char' => 38,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                              'line' => 61,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                            'line' => 61,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                          'line' => 61,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                      'line' => 62,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                    'line' => 62,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 62,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 63,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads parsed annotations from APCu
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
                  'value' => 'Reflection',
                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                  'line' => 56,
                  'char' => 55,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 56,
                'char' => 55,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 57,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
            'line' => 57,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
          'line' => 56,
          'last-line' => 67,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'write',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 68,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Reflection',
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 68,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 68,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'apcu_store',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strtolower',
                      'call-type' => 1,
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
                                'value' => '_PHAN',
                                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                                'line' => 72,
                                'char' => 23,
                              ),
                              'right' => 
                              array (
                                'type' => 'property-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                                  'line' => 72,
                                  'char' => 30,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'prefix',
                                  'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                                  'line' => 72,
                                  'char' => 38,
                                ),
                                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                                'line' => 72,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                              'line' => 72,
                              'char' => 38,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                              'line' => 73,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                            'line' => 73,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                          'line' => 73,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                      'line' => 73,
                      'char' => 14,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                    'line' => 73,
                    'char' => 14,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                      'line' => 74,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                    'line' => 74,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                        'line' => 75,
                        'char' => 18,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ttl',
                        'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                        'line' => 76,
                        'char' => 9,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                      'line' => 76,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                    'line' => 76,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 76,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
              'line' => 77,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes parsed annotations to APCu
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
                'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
                'line' => 69,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
            'line' => 69,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
          'line' => 68,
          'last-line' => 78,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Apcu.zep',
    'line' => 25,
    'char' => 5,
  ),
);