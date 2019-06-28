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
    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Annotations\\Adapter',
    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
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
        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
        'line' => 13,
        'char' => 48,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
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
        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
        'line' => 14,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
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
        'name' => 'Phalcon\\Annotations\\Exception',
        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
        'line' => 15,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
    'line' => 29,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Stores the parsed annotations in files. This adapter is suitable for production
 *
 *```php
 * use Phalcon\\Annotations\\Adapter\\Stream;
 *
 * $annotations = new Stream(
 *     [
 *         "annotationsDir" => "app/cache/annotations/",
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
    'line' => 30,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Stream',
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
          'name' => 'annotationsDir',
          'default' => 
          array (
            'type' => 'string',
            'value' => './',
            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
            'line' => 35,
            'char' => 34,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
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
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 40,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
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
                  'variable' => 'annotationsDir',
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 42,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
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
                  'value' => 'annotationsDir',
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 44,
                  'char' => 58,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 44,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'annotationsDir',
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 44,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 44,
                  'char' => 58,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 44,
                'char' => 58,
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
                      'property' => 'annotationsDir',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'annotationsDir',
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 45,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                      'line' => 45,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 46,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 47,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Annotations\\Adapter\\Stream constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
            'line' => 41,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
          'line' => 40,
          'last-line' => 51,
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 52,
              'char' => 36,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 54,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 59,
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
                  'variable' => 'path',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                          'line' => 59,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'annotationsDir',
                          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                          'line' => 59,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 59,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'prepare_virtual_path',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                              'line' => 59,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                            'line' => 59,
                            'char' => 67,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '_',
                              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                              'line' => 59,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                            'line' => 59,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 59,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                      'line' => 59,
                      'char' => 72,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '.php',
                      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                      'line' => 59,
                      'char' => 78,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 59,
                    'char' => 78,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 59,
                  'char' => 78,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 61,
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
                  'type' => 'fcall',
                  'name' => 'file_exists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'path',
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 61,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                      'line' => 61,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 61,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 61,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 62,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 63,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 65,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'require',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'path',
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 65,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 65,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 66,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads parsed annotations from files
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
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 52,
                  'char' => 54,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 52,
                'char' => 54,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 52,
                'char' => 61,
              ),
              2 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 53,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
            'line' => 53,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
          'line' => 52,
          'last-line' => 70,
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
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 71,
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
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 71,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 71,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 73,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 73,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 78,
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
                  'variable' => 'path',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                          'line' => 78,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'annotationsDir',
                          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                          'line' => 78,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 78,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'prepare_virtual_path',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                              'line' => 78,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                            'line' => 78,
                            'char' => 67,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '_',
                              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                              'line' => 78,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                            'line' => 78,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 78,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                      'line' => 78,
                      'char' => 72,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '.php',
                      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                      'line' => 78,
                      'char' => 78,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 78,
                    'char' => 78,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 78,
                  'char' => 78,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 80,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'code',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '<?php return ',
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 80,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'var_export',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                              'line' => 80,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                            'line' => 80,
                            'char' => 51,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'bool',
                              'value' => 'true',
                              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                              'line' => 80,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                            'line' => 80,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 80,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                      'line' => 80,
                      'char' => 59,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '; ',
                      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                      'line' => 80,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 80,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 80,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 82,
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'file_put_contents',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                          'line' => 82,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 82,
                        'char' => 43,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'code',
                          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                          'line' => 82,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 82,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 82,
                    'char' => 53,
                  ),
                  'right' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 82,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 82,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                'line' => 82,
                'char' => 61,
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
                          'value' => 'Annotations directory cannot be written',
                          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                          'line' => 83,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                        'line' => 83,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                    'line' => 83,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
                  'line' => 84,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
              'line' => 85,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes parsed annotations to files
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
            'line' => 72,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
          'line' => 71,
          'last-line' => 86,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
      'line' => 30,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Annotations/Adapter/Stream.zep',
    'line' => 30,
    'char' => 5,
  ),
);