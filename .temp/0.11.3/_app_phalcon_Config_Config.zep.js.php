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
    'file' => '/app/phalcon/Config/Config.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Config',
    'file' => '/app/phalcon/Config/Config.zep',
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
        'name' => 'Phalcon\\Collection\\Collection',
        'file' => '/app/phalcon/Config/Config.zep',
        'line' => 13,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Config/Config.zep',
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
        'name' => 'Phalcon\\Config\\Exception',
        'file' => '/app/phalcon/Config/Config.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Config/Config.zep',
    'line' => 40,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * `Phalcon\\Config` is designed to simplify the access to, and the use of,
 * configuration data within applications. It provides a nested object property
 * based user interface for accessing this configuration data within application
 * code.
 *
 *```php
 * $config = new \\Phalcon\\Config(
 *     [
 *         "database" => [
 *             "adapter"  => "Mysql",
 *             "host"     => "localhost",
 *             "username" => "scott",
 *             "password" => "cheetah",
 *             "dbname"   => "test_db",
 *         ],
 *         "phalcon" => [
 *             "controllersDir" => "../app/controllers/",
 *             "modelsDir"      => "../app/models/",
 *             "viewsDir"       => "../app/views/",
 *         ],
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Config/Config.zep',
    'line' => 41,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Config',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Collection',
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
          'name' => 'pathDelimiter',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Config/Config.zep',
            'line' => 48,
            'char' => 35,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 54,
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
          'name' => 'getPathDelimiter',
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 57,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pathDelimiter',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 57,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 57,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 57,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 57,
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
                      'property' => 'pathDelimiter',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 58,
                          'char' => 67,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'DEFAULT_PATH_DELIMITER',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 58,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 58,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 58,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 59,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 61,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 61,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'pathDelimiter',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 61,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 61,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 62,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the default path delimiter
     *
     * @return string
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 56,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/Config.zep',
            'line' => 56,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 55,
          'last-line' => 78,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'merge',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'toMerge',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 79,
              'char' => 38,
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
                  'variable' => 'config',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 81,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 81,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'source',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 81,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'target',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 81,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 83,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'toMerge',
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 83,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 83,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 83,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 83,
                'char' => 37,
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
                        'type' => 'new',
                        'class' => 'Config',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'toMerge',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 84,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 84,
                            'char' => 44,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 84,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 84,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 85,
                  'char' => 9,
                ),
              ),
              'elseif_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'toMerge',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 85,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 85,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 85,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 85,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'instanceof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'toMerge',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 85,
                        'char' => 64,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'Config',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 85,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 85,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 85,
                    'char' => 73,
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
                            'type' => 'variable',
                            'value' => 'toMerge',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 86,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 86,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 87,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 87,
                  'char' => 14,
                ),
              ),
              'else_statements' => 
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
                          'value' => 'Invalid data type for merge.',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 88,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 88,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 88,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 89,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 91,
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
                  'variable' => 'source',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 91,
                      'char' => 27,
                    ),
                    'name' => 'toArray',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 91,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 91,
                  'char' => 37,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'target',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 92,
                      'char' => 29,
                    ),
                    'name' => 'toArray',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 92,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 92,
                  'char' => 39,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 93,
                      'char' => 27,
                    ),
                    'name' => 'internalMerge',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'source',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 93,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 93,
                        'char' => 48,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'target',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 93,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 93,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 93,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 93,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 95,
              'char' => 12,
            ),
            3 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 95,
                  'char' => 14,
                ),
                'name' => 'clear',
                'call-type' => 1,
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 95,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 96,
              'char' => 12,
            ),
            4 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 96,
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
                      'value' => 'result',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 96,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 96,
                    'char' => 26,
                  ),
                ),
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 96,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 98,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 98,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 99,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Merges a configuration into the current one
     *
     *```php
     * $appConfig = new \\Phalcon\\Config(
     *     [
     *         "database" => [
     *             "host" => "localhost",
     *         ],
     *     ]
     * );
     *
     * $globalConfig->merge($appConfig);
     *```
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
                  'value' => 'Config',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 80,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 80,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/Config.zep',
            'line' => 80,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 79,
          'last-line' => 107,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'path',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 108,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 108,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 108,
              'char' => 58,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'delimiter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 108,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 108,
              'char' => 80,
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
                  'variable' => 'config',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 110,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 110,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'keys',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 110,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 112,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 112,
                  'char' => 17,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 112,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 112,
                    'char' => 26,
                  ),
                ),
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 112,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 113,
                      'char' => 25,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 113,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 113,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 113,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 114,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 116,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'delimiter',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 116,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 116,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 116,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 116,
                'char' => 36,
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
                      'variable' => 'delimiter',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 117,
                          'char' => 34,
                        ),
                        'name' => 'getPathDelimiter',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 117,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 117,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 118,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 120,
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
                  'variable' => 'config',
                  'expr' => 
                  array (
                    'type' => 'clone',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 120,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 120,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 120,
                  'char' => 32,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'keys',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'explode',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'delimiter',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 121,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 121,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 121,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 121,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 121,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 121,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 123,
              'char' => 13,
            ),
            4 => 
            array (
              'type' => 'while',
              'expr' => 
              array (
                'type' => 'list',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'keys',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 123,
                        'char' => 27,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 123,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 123,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 123,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 123,
                'char' => 30,
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
                      'variable' => 'key',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'array_shift',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'keys',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 124,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 124,
                            'char' => 39,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 124,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 124,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 126,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'config',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 126,
                        'char' => 24,
                      ),
                      'name' => 'has',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 126,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 126,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 126,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 126,
                    'char' => 34,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 128,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 130,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'keys',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 130,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 130,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 130,
                    'char' => 28,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'config',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 131,
                          'char' => 31,
                        ),
                        'name' => 'get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 131,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 131,
                            'char' => 39,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 131,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 132,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 134,
                  'char' => 15,
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
                      'variable' => 'config',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'config',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 134,
                          'char' => 33,
                        ),
                        'name' => 'get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 134,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 134,
                            'char' => 41,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 134,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 134,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 135,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'config',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 135,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 135,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 135,
                    'char' => 30,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 137,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 138,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 140,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'defaultValue',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 140,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 141,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a value from current config using a dot separated path.
     *
     *```php
     * echo $config->path("unknown.path", "default", ".");
     *```
     *',
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 108,
          'last-line' => 145,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPathDelimiter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'delimiter',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 146,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 146,
              'char' => 61,
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
                  'property' => 'pathDelimiter',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'delimiter',
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 148,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 148,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 150,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 150,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 151,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the default path delimiter
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
                  'value' => 'Config',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 147,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 147,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/Config.zep',
            'line' => 147,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 146,
          'last-line' => 161,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'toArray',
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 164,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 164,
                  'char' => 22,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 164,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 165,
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
                  'variable' => 'results',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 165,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 167,
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
                  'variable' => 'results',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 167,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 167,
                  'char' => 25,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'parent',
                    'dynamic' => 0,
                    'name' => 'toArray',
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 168,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 168,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 170,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 170,
                'char' => 32,
              ),
              'key' => 'key',
              'value' => 'value',
              'reverse' => 0,
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
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 171,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 171,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 171,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 171,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'method_exists',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 171,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 171,
                          'char' => 62,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'toArray',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 171,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 171,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 171,
                      'char' => 73,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 171,
                    'char' => 73,
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
                          'variable' => 'value',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 172,
                              'char' => 35,
                            ),
                            'name' => 'toArray',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 172,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 172,
                          'char' => 45,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 173,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 175,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'results',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 175,
                          'char' => 28,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 175,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 175,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 176,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 178,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'results',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 178,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 179,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Converts recursively the object to an array
     *
     *```php
     * print_r(
     *     $config->toArray()
     * );
     *```
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
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 163,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/Config.zep',
            'line' => 163,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 162,
          'last-line' => 183,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'internalMerge',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'source',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 184,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'target',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 184,
              'char' => 70,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 186,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 186,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 188,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'target',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 188,
                'char' => 34,
              ),
              'key' => 'key',
              'value' => 'value',
              'reverse' => 0,
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
                      'type' => 'and',
                      'left' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 189,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 189,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 189,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 189,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'isset',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'source',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 189,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 189,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 189,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 189,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 189,
                      'char' => 62,
                    ),
                    'right' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'source',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 189,
                            'char' => 77,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 189,
                            'char' => 81,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 189,
                          'char' => 85,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 189,
                        'char' => 85,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 189,
                        'char' => 93,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 189,
                      'char' => 93,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 189,
                    'char' => 93,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'source',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 190,
                              'char' => 31,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 190,
                              'char' => 40,
                            ),
                            'name' => 'internalMerge',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'source',
                                    'file' => '/app/phalcon/Config/Config.zep',
                                    'line' => 190,
                                    'char' => 61,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'key',
                                    'file' => '/app/phalcon/Config/Config.zep',
                                    'line' => 190,
                                    'char' => 65,
                                  ),
                                  'file' => '/app/phalcon/Config/Config.zep',
                                  'line' => 190,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Config/Config.zep',
                                'line' => 190,
                                'char' => 66,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Config/Config.zep',
                                  'line' => 190,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Config/Config.zep',
                                'line' => 190,
                                'char' => 73,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 190,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 190,
                          'char' => 74,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 191,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 191,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 191,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'int',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 191,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 191,
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
                              'assign-type' => 'variable-append',
                              'operator' => 'assign',
                              'variable' => 'source',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Config/Config.zep',
                                'line' => 192,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 192,
                              'char' => 37,
                            ),
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 193,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 193,
                      'char' => 18,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'source',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 194,
                              'char' => 31,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 194,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 194,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 195,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 196,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 198,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'source',
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 198,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 199,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Performs a merge recursively
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
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 185,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/Config.zep',
            'line' => 185,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 184,
          'last-line' => 203,
          'char' => 28,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'setData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'element',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 204,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 204,
              'char' => 54,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 206,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 206,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 208,
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
                  'variable' => 'element',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 208,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 208,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 208,
                  'char' => 39,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'key',
                  'expr' => 
                  array (
                    'type' => 'ternary',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 209,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'insensitive',
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 209,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 209,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 209,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'mb_strtolower',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'element',
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 209,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Config/Config.zep',
                          'line' => 209,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 209,
                      'char' => 68,
                    ),
                    'extra' => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 209,
                      'char' => 77,
                    ),
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 209,
                    'char' => 77,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 209,
                  'char' => 77,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 211,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'lowerKeys',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 211,
                      'char' => 32,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'element',
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 211,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 211,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 213,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 213,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 213,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 213,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Config/Config.zep',
                'line' => 213,
                'char' => 35,
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
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Config',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Config/Config.zep',
                              'line' => 214,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Config/Config.zep',
                            'line' => 214,
                            'char' => 40,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 214,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 214,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 215,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
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
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Config/Config.zep',
                        'line' => 216,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 216,
                      'char' => 29,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 217,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 219,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'data',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'element',
                      'file' => '/app/phalcon/Config/Config.zep',
                      'line' => 219,
                      'char' => 31,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Config/Config.zep',
                    'line' => 219,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Config/Config.zep',
                  'line' => 219,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Config/Config.zep',
              'line' => 220,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the collection data
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Config/Config.zep',
            'line' => 205,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 204,
          'last-line' => 221,
          'char' => 22,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'DEFAULT_PATH_DELIMITER',
          'default' => 
          array (
            'type' => 'string',
            'value' => '.',
            'file' => '/app/phalcon/Config/Config.zep',
            'line' => 43,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Config/Config.zep',
          'line' => 47,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Config/Config.zep',
      'line' => 41,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Config/Config.zep',
    'line' => 41,
    'char' => 5,
  ),
);