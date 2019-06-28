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
    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\MetaData',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\MetaData',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Exception',
        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
        'line' => 14,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
    'line' => 28,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\MetaData\\Stream
 *
 * Stores model meta-data in PHP files.
 *
 *```php
 * $metaData = new \\Phalcon\\Mvc\\Model\\MetaData\\Files(
 *     [
 *         "metaDataDir" => "app/cache/metadata/",
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
    'line' => 29,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Stream',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'MetaData',
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
          'name' => 'metaDataDir',
          'default' => 
          array (
            'type' => 'string',
            'value' => './',
            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
            'line' => 31,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
          'line' => 37,
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
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                'line' => 38,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 38,
              'char' => 47,
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
                  'variable' => 'metaDataDir',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 40,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 42,
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
                  'value' => 'metaDataDir',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 42,
                  'char' => 52,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                    'line' => 42,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'metaDataDir',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                    'line' => 42,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 42,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                'line' => 42,
                'char' => 52,
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
                      'property' => 'metaDataDir',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'metaDataDir',
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 43,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 43,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 44,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 45,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\MetaData\\Files constructor
     *
     * @param array options
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
            'line' => 39,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
          'line' => 38,
          'last-line' => 49,
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
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 50,
              'char' => 37,
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
                  'variable' => 'path',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 52,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 54,
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 54,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'metaDataDir',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 54,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 54,
                        'char' => 38,
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
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 54,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 54,
                            'char' => 64,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '_',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 54,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 54,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 54,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 54,
                      'char' => 69,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '.php',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 54,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                    'line' => 54,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 54,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 56,
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
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 56,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 56,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 56,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                'line' => 56,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                    'line' => 57,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 58,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 60,
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
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 60,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                'line' => 60,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads meta-data from files
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
                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                'line' => 50,
                'char' => 48,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                'line' => 51,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
            'line' => 51,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
          'line' => 50,
          'last-line' => 65,
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
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 66,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 66,
              'char' => 50,
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
                  'variable' => 'option',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 68,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 68,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 70,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'try-catch',
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
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 71,
                              'char' => 31,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'metaDataDir',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 71,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 71,
                            'char' => 44,
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
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                  'line' => 71,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                'line' => 71,
                                'char' => 70,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => '_',
                                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                  'line' => 71,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                'line' => 71,
                                'char' => 73,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 71,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 71,
                          'char' => 75,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '.php',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 71,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 71,
                        'char' => 81,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 71,
                      'char' => 81,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'option',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'globals_get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'orm.exception_on_failed_metadata_save',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 72,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 72,
                            'char' => 75,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 72,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 72,
                      'char' => 76,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 74,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 74,
                      'char' => 24,
                    ),
                    'right' => 
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
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 74,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 74,
                          'char' => 48,
                        ),
                        1 => 
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
                                'value' => '<?php return ',
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                'line' => 74,
                                'char' => 64,
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
                                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                      'line' => 74,
                                      'char' => 81,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                    'line' => 74,
                                    'char' => 81,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'bool',
                                      'value' => 'true',
                                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                      'line' => 74,
                                      'char' => 87,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                    'line' => 74,
                                    'char' => 87,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                                'line' => 74,
                                'char' => 89,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 74,
                              'char' => 89,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '; ',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 74,
                              'char' => 93,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 74,
                            'char' => 93,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 74,
                          'char' => 93,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 74,
                      'char' => 95,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                    'line' => 74,
                    'char' => 95,
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 75,
                          'char' => 22,
                        ),
                        'name' => 'throwWriteException',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'option',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 75,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 75,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 75,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 76,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 77,
                  'char' => 9,
                ),
              ),
              'catches' => 
              array (
                0 => 
                array (
                  'classes' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => '\\Exception',
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 77,
                      'char' => 28,
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
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 78,
                          'char' => 18,
                        ),
                        'name' => 'throwWriteException',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'option',
                              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                              'line' => 78,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                            'line' => 78,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 78,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                      'line' => 79,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 80,
                  'char' => 5,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 80,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Writes the meta-data to files
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
          'line' => 66,
          'last-line' => 84,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'throwWriteException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'option',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 85,
              'char' => 52,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'option',
                'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                'line' => 87,
                'char' => 19,
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
                          'value' => 'Meta-Data directory cannot be written',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 90,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 90,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                    'line' => 90,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 91,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'trigger_error',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Meta-Data directory cannot be written',
                          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                          'line' => 94,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                        'line' => 94,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                    'line' => 94,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
                  'line' => 95,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
              'line' => 96,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Throws an exception when the metadata cannot be written
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
            'line' => 86,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
          'line' => 85,
          'last-line' => 97,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
      'line' => 29,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/MetaData/Stream.zep',
    'line' => 29,
    'char' => 5,
  ),
);