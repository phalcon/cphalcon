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
    'file' => '/app/phalcon/Loader.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Loader.zep',
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
        'name' => 'Phalcon\\Loader\\Exception',
        'file' => '/app/phalcon/Loader.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Loader.zep',
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
        'name' => 'Phalcon\\Events\\ManagerInterface',
        'file' => '/app/phalcon/Loader.zep',
        'line' => 14,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Loader.zep',
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
        'name' => 'Phalcon\\Events\\EventsAwareInterface',
        'file' => '/app/phalcon/Loader.zep',
        'line' => 15,
        'char' => 40,
      ),
    ),
    'file' => '/app/phalcon/Loader.zep',
    'line' => 42,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This component helps to load your project classes automatically based on some
 * conventions
 *
 *```php
 * use Phalcon\\Loader;
 *
 * // Creates the autoloader
 * $loader = new Loader();
 *
 * // Register some namespaces
 * $loader->registerNamespaces(
 *     [
 *         "Example\\\\Base"    => "vendor/example/base/",
 *         "Example\\\\Adapter" => "vendor/example/adapter/",
 *         "Example"          => "vendor/example/",
 *     ]
 * );
 *
 * // Register autoloader
 * $loader->register();
 *
 * // Requiring this class will automatically include file vendor/example/adapter/Some.php
 * $adapter = new \\Example\\Adapter\\Some();
 *```
 *',
    'file' => '/app/phalcon/Loader.zep',
    'line' => 43,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Loader',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'EventsAwareInterface',
        'file' => '/app/phalcon/Loader.zep',
        'line' => 44,
        'char' => 1,
      ),
    ),
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
          'name' => 'checkedPath',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 45,
            'char' => 33,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 49,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'classes',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 50,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Loader.zep',
          'line' => 54,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'directories',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 55,
            'char' => 31,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Loader.zep',
          'line' => 56,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'eventsManager',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 56,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 60,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'extensions',
          'default' => 
          array (
            'type' => 'array',
            'left' => 
            array (
              0 => 
              array (
                'value' => 
                array (
                  'type' => 'string',
                  'value' => 'php',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 61,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 61,
                'char' => 32,
              ),
            ),
            'file' => '/app/phalcon/Loader.zep',
            'line' => 61,
            'char' => 33,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Loader.zep',
          'line' => 63,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'fileCheckingCallback',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'is_file',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 63,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 67,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'files',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 68,
            'char' => 25,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Loader.zep',
          'line' => 72,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'foundPath',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 73,
            'char' => 31,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Loader.zep',
          'line' => 77,
          'char' => 6,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'namespaces',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 78,
            'char' => 30,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Loader.zep',
          'line' => 82,
          'char' => 6,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'registered',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Loader.zep',
            'line' => 83,
            'char' => 33,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Loader.zep',
          'line' => 87,
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
          'name' => 'autoLoad',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 88,
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
                  'variable' => 'eventsManager',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 90,
                  'char' => 26,
                ),
                1 => 
                array (
                  'variable' => 'classes',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 90,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'extensions',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 90,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'filePath',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 90,
                  'char' => 57,
                ),
                4 => 
                array (
                  'variable' => 'ds',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 90,
                  'char' => 61,
                ),
                5 => 
                array (
                  'variable' => 'fixedDirectory',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 90,
                  'char' => 77,
                ),
                6 => 
                array (
                  'variable' => 'directories',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 91,
                  'char' => 24,
                ),
                7 => 
                array (
                  'variable' => 'ns',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 91,
                  'char' => 28,
                ),
                8 => 
                array (
                  'variable' => 'namespaces',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 91,
                  'char' => 40,
                ),
                9 => 
                array (
                  'variable' => 'nsPrefix',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 91,
                  'char' => 50,
                ),
                10 => 
                array (
                  'variable' => 'directory',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 91,
                  'char' => 61,
                ),
                11 => 
                array (
                  'variable' => 'fileName',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 91,
                  'char' => 71,
                ),
                12 => 
                array (
                  'variable' => 'extension',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 92,
                  'char' => 22,
                ),
                13 => 
                array (
                  'variable' => 'nsClassName',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 92,
                  'char' => 35,
                ),
                14 => 
                array (
                  'variable' => 'fileCheckingCallback',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 92,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 94,
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
                  'variable' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 94,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 94,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 94,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 94,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 96,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 96,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 96,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 96,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 96,
                'char' => 43,
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
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 97,
                      'char' => 27,
                    ),
                    'name' => 'fire',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'loader:beforeCheckClass',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 97,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 97,
                        'char' => 56,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 97,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 97,
                        'char' => 62,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 97,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 97,
                        'char' => 73,
                      ),
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 97,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 98,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 103,
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
                  'variable' => 'classes',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 103,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'classes',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 103,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 103,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 103,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 105,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'filePath',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 105,
                  'char' => 47,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'classes',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 105,
                    'char' => 35,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'className',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 105,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 105,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 105,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'eventsManager',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 106,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 106,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 106,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 106,
                    'char' => 47,
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
                          'property' => 'foundPath',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filePath',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 107,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 107,
                          'char' => 47,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 108,
                      'char' => 29,
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
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 108,
                          'char' => 31,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'loader:pathFound',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 108,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 108,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 108,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 108,
                            'char' => 59,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filePath',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 108,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 108,
                            'char' => 69,
                          ),
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 108,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 109,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 111,
                  'char' => 19,
                ),
                1 => 
                array (
                  'type' => 'require',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filePath',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 111,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 113,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 113,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 114,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 116,
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
                  'variable' => 'extensions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 116,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'extensions',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 116,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 116,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 116,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 118,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'ds',
                  'expr' => 
                  array (
                    'type' => 'constant',
                    'value' => 'DIRECTORY_SEPARATOR',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 118,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 118,
                  'char' => 37,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'ns',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '\\\\',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 119,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 119,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 124,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'namespaces',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 124,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'namespaces',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 124,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 124,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 124,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 126,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'fileCheckingCallback',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 126,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fileCheckingCallback',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 126,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 126,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 126,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 128,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'namespaces',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 128,
                'char' => 49,
              ),
              'key' => 'nsPrefix',
              'value' => 'directories',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'starts_with',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 132,
                            'char' => 38,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 132,
                          'char' => 38,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'nsPrefix',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 132,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 132,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 132,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 132,
                    'char' => 50,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 134,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 139,
                  'char' => 15,
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
                      'variable' => 'fileName',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'substr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'className',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 139,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 139,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'strlen',
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
                                      'type' => 'variable',
                                      'value' => 'nsPrefix',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 139,
                                      'char' => 62,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'ns',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 139,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 139,
                                    'char' => 66,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 139,
                                  'char' => 66,
                                ),
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 139,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 139,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 139,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 139,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 141,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fileName',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 141,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 141,
                    'char' => 26,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 143,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 145,
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
                      'variable' => 'fileName',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'str_replace',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ns',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 145,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 145,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ds',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 145,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 145,
                            'char' => 46,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'fileName',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 145,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 145,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 145,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 145,
                      'char' => 57,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 147,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'directories',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 147,
                    'char' => 42,
                  ),
                  'value' => 'directory',
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
                          'variable' => 'fixedDirectory',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'rtrim',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'directory',
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 152,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 152,
                                  'char' => 53,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'ds',
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 152,
                                    'char' => 57,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 152,
                                  'char' => 57,
                                ),
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 152,
                              'char' => 59,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ds',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 152,
                              'char' => 63,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 152,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 152,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 154,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'extensions',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 154,
                        'char' => 45,
                      ),
                      'value' => 'extension',
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
                              'variable' => 'filePath',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'fixedDirectory',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 155,
                                      'char' => 51,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'fileName',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 155,
                                      'char' => 62,
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 155,
                                    'char' => 62,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '.',
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 155,
                                    'char' => 66,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 155,
                                  'char' => 66,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'extension',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 155,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 155,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 155,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 160,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'eventsManager',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 160,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 160,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'object',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 160,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 160,
                            'char' => 55,
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
                                  'property' => 'checkedPath',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'filePath',
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 161,
                                    'char' => 57,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 161,
                                  'char' => 57,
                                ),
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 163,
                              'char' => 37,
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
                                  'value' => 'eventsManager',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 163,
                                  'char' => 39,
                                ),
                                'name' => 'fire',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'loader:beforeCheckPath',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 163,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 163,
                                    'char' => 67,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 163,
                                      'char' => 73,
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 163,
                                    'char' => 73,
                                  ),
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 163,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 164,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 170,
                          'char' => 22,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'call_user_func',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'fileCheckingCallback',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 170,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 170,
                                'char' => 59,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filePath',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 170,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 170,
                                'char' => 69,
                              ),
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 170,
                            'char' => 71,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'equals',
                                'left' => 
                                array (
                                  'type' => 'typeof',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'eventsManager',
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 171,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 171,
                                  'char' => 50,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'object',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 171,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 171,
                                'char' => 59,
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
                                      'property' => 'foundPath',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'filePath',
                                        'file' => '/app/phalcon/Loader.zep',
                                        'line' => 172,
                                        'char' => 59,
                                      ),
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 172,
                                      'char' => 59,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 174,
                                  'char' => 41,
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
                                      'value' => 'eventsManager',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 174,
                                      'char' => 43,
                                    ),
                                    'name' => 'fire',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'loader:pathFound',
                                          'file' => '/app/phalcon/Loader.zep',
                                          'line' => 175,
                                          'char' => 49,
                                        ),
                                        'file' => '/app/phalcon/Loader.zep',
                                        'line' => 175,
                                        'char' => 49,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Loader.zep',
                                          'line' => 176,
                                          'char' => 37,
                                        ),
                                        'file' => '/app/phalcon/Loader.zep',
                                        'line' => 176,
                                        'char' => 37,
                                      ),
                                      2 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'filePath',
                                          'file' => '/app/phalcon/Loader.zep',
                                          'line' => 178,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Loader.zep',
                                        'line' => 178,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 178,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 179,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 184,
                              'char' => 31,
                            ),
                            1 => 
                            array (
                              'type' => 'require',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'filePath',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 184,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 189,
                              'char' => 30,
                            ),
                            2 => 
                            array (
                              'type' => 'return',
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 189,
                                'char' => 36,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 190,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 191,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 192,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 193,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 198,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'nsClassName',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'str_replace',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ns',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 198,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 198,
                        'char' => 41,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ds',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 198,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 198,
                        'char' => 45,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 198,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 198,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 198,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 198,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 203,
              'char' => 11,
            ),
            11 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'directories',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 203,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'directories',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 203,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 203,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 203,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 205,
              'char' => 11,
            ),
            12 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'directories',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 205,
                'char' => 38,
              ),
              'value' => 'directory',
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
                      'variable' => 'fixedDirectory',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'rtrim',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'directory',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 209,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 209,
                              'char' => 49,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'ds',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 209,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 209,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 209,
                          'char' => 55,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ds',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 209,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 209,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 209,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 211,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'extensions',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 211,
                    'char' => 41,
                  ),
                  'value' => 'extension',
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
                          'variable' => 'filePath',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'fixedDirectory',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 215,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'nsClassName',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 215,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 215,
                                'char' => 61,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '.',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 215,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 215,
                              'char' => 65,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'extension',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 215,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 215,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 215,
                          'char' => 76,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 217,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'eventsManager',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 217,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 217,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 217,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 217,
                        'char' => 51,
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
                              'property' => 'checkedPath',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'filePath',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 218,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 218,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 220,
                          'char' => 33,
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
                              'value' => 'eventsManager',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 220,
                              'char' => 35,
                            ),
                            'name' => 'fire',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'loader:beforeCheckPath',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 221,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 221,
                                'char' => 47,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 222,
                                  'char' => 29,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 222,
                                'char' => 29,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filePath',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 224,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 224,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 224,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 225,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 230,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'call_user_func',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'fileCheckingCallback',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 230,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 230,
                            'char' => 55,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filePath',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 230,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 230,
                            'char' => 65,
                          ),
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 230,
                        'char' => 67,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'eventsManager',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 234,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 234,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'object',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 234,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 234,
                            'char' => 55,
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
                                  'property' => 'foundPath',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'filePath',
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 235,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 235,
                                  'char' => 55,
                                ),
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 237,
                              'char' => 37,
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
                                  'value' => 'eventsManager',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 237,
                                  'char' => 39,
                                ),
                                'name' => 'fire',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'loader:pathFound',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 237,
                                      'char' => 61,
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 237,
                                    'char' => 61,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 237,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 237,
                                    'char' => 67,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'filePath',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 237,
                                      'char' => 77,
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 237,
                                    'char' => 77,
                                  ),
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 237,
                                'char' => 78,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 238,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 243,
                          'char' => 27,
                        ),
                        1 => 
                        array (
                          'type' => 'require',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filePath',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 243,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 248,
                          'char' => 26,
                        ),
                        2 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 248,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 249,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 250,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 251,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 256,
              'char' => 10,
            ),
            13 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 256,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 256,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 256,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 256,
                'char' => 43,
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
                      'value' => 'eventsManager',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 257,
                      'char' => 27,
                    ),
                    'name' => 'fire',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'loader:afterCheckClass',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 257,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 257,
                        'char' => 55,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 257,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 257,
                        'char' => 61,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'className',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 257,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 257,
                        'char' => 72,
                      ),
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 257,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 258,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 263,
              'char' => 14,
            ),
            14 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 263,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 264,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Autoloads the registered classes
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 89,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 89,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 88,
          'last-line' => 268,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCheckedPath',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 271,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'checkedPath',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 271,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 271,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 272,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the path the loader is checking for a path
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 270,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 270,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 269,
          'last-line' => 275,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getClasses',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 278,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'classes',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 278,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 278,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 279,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the class-map currently registered in the autoloader
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 277,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 277,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 276,
          'last-line' => 283,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDirs',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 286,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'directories',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 286,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 286,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 287,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the directories currently registered in the autoloader
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 285,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 285,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 284,
          'last-line' => 291,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getEventsManager',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 294,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'eventsManager',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 294,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 294,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 295,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal event manager
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 293,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 293,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 293,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 292,
          'last-line' => 299,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getExtensions',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 302,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'extensions',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 302,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 302,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 303,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the file extensions registered in the loader
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 301,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 301,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 300,
          'last-line' => 307,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFiles',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 310,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'files',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 310,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 310,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 311,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the files currently registered in the autoloader
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 309,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 309,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 308,
          'last-line' => 315,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getFoundPath',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 318,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'foundPath',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 318,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 318,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 319,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the path when a class was found
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 317,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 317,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 316,
          'last-line' => 323,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNamespaces',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 326,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'namespaces',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 326,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 326,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 327,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the namespaces currently registered in the autoloader
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 325,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 325,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 324,
          'last-line' => 331,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'loadFiles',
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
                  'variable' => 'filePath',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 334,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'fileCheckingCallback',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 334,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 336,
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
                  'variable' => 'fileCheckingCallback',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 336,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'fileCheckingCallback',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 336,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 336,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 336,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 338,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 338,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'files',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 338,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 338,
                'char' => 37,
              ),
              'value' => 'filePath',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 339,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'eventsManager',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 339,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 339,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 339,
                      'char' => 44,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 339,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 339,
                    'char' => 53,
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
                          'property' => 'checkedPath',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filePath',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 340,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 340,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 341,
                      'char' => 24,
                    ),
                    1 => 
                    array (
                      'type' => 'mcall',
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
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 341,
                            'char' => 26,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'eventsManager',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 341,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 341,
                          'char' => 41,
                        ),
                        'name' => 'fire',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'loader:beforeCheckPath',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 342,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 342,
                            'char' => 47,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 343,
                              'char' => 29,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 343,
                            'char' => 29,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filePath',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 345,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 345,
                            'char' => 21,
                          ),
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 345,
                        'char' => 22,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 346,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 351,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'call_user_func',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'fileCheckingCallback',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 351,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 351,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filePath',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 351,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 351,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 351,
                    'char' => 63,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 355,
                              'char' => 32,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'eventsManager',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 355,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 355,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 355,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 355,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 355,
                        'char' => 57,
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
                              'property' => 'foundPath',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'filePath',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 356,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 356,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 358,
                          'char' => 24,
                        ),
                        1 => 
                        array (
                          'type' => 'mcall',
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
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 358,
                                'char' => 26,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'eventsManager',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 358,
                                'char' => 41,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 358,
                              'char' => 41,
                            ),
                            'name' => 'fire',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'loader:pathFound',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 359,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 359,
                                'char' => 41,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 360,
                                  'char' => 29,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 360,
                                'char' => 29,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filePath',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 362,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 362,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 362,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 363,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 368,
                      'char' => 23,
                    ),
                    1 => 
                    array (
                      'type' => 'require',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filePath',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 368,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 369,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 370,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 371,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a file exists and then adds the file by doing virtual require
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 333,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 332,
          'last-line' => 375,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'register',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'prepend',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 376,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 376,
              'char' => 50,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 378,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'registered',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 378,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 378,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 378,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 378,
                'char' => 39,
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
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 382,
                      'char' => 18,
                    ),
                    'name' => 'loadFiles',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 382,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 387,
                  'char' => 33,
                ),
                1 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'spl_autoload_register',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'value' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 388,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 388,
                              'char' => 22,
                            ),
                            1 => 
                            array (
                              'value' => 
                              array (
                                'type' => 'string',
                                'value' => 'autoLoad',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 388,
                                'char' => 32,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 388,
                              'char' => 32,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 388,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 388,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 389,
                          'char' => 21,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 389,
                        'char' => 21,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prepend',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 391,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 391,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 391,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 393,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'registered',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 393,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 393,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 394,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 396,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 396,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 397,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Register the autoload method
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
                  'value' => 'Loader',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 377,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 377,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 377,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 376,
          'last-line' => 401,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'registerClasses',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'classes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 402,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 402,
                'char' => 71,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 402,
              'char' => 71,
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
                'value' => 'merge',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 404,
                'char' => 18,
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
                      'property' => 'classes',
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
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 405,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'classes',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 405,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 405,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 405,
                            'char' => 58,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'classes',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 405,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 405,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 405,
                        'char' => 68,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 405,
                      'char' => 68,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 406,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'classes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'classes',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 407,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 407,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 408,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 410,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 410,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 411,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Register classes and their locations
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
                  'value' => 'Loader',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 403,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 403,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 403,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 402,
          'last-line' => 415,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'registerDirs',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'directories',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 416,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 416,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 416,
              'char' => 72,
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
                'value' => 'merge',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 418,
                'char' => 18,
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
                      'property' => 'directories',
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
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 419,
                                'char' => 54,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'directories',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 419,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 419,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 419,
                            'char' => 66,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'directories',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 419,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 419,
                            'char' => 79,
                          ),
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 419,
                        'char' => 80,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 419,
                      'char' => 80,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 420,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'directories',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'directories',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 421,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 421,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 422,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 424,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 424,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 425,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Register directories in which "not found" classes could be found
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
                  'value' => 'Loader',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 417,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 417,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 417,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 416,
          'last-line' => 430,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'registerFiles',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'files',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 431,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 431,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 431,
              'char' => 67,
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
                'value' => 'merge',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 433,
                'char' => 18,
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
                      'property' => 'files',
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
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 434,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'files',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 434,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 434,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 434,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'files',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 434,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 434,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 434,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 434,
                      'char' => 62,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 435,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'files',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'files',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 436,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 436,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 437,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 439,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 439,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 440,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Registers files that are "non-classes" hence need a "require". This is
     * very useful for including files that only have functions
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
                  'value' => 'Loader',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 432,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 432,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 432,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 431,
          'last-line' => 444,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'registerNamespaces',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'namespaces',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 445,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'merge',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 445,
                'char' => 77,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 445,
              'char' => 77,
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
                  'variable' => 'preparedNamespaces',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 447,
                  'char' => 31,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 447,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'paths',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 447,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 449,
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
                  'variable' => 'preparedNamespaces',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 449,
                      'char' => 39,
                    ),
                    'name' => 'prepareNamespace',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'namespaces',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 449,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 449,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 449,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 449,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 451,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'merge',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 451,
                'char' => 18,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'preparedNamespaces',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 452,
                    'char' => 51,
                  ),
                  'key' => 'name',
                  'value' => 'paths',
                  'reverse' => 0,
                  'statements' => 
                  array (
                    0 => 
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
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 453,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'namespaces',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 453,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 453,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 453,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 453,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 453,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 453,
                        'char' => 50,
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
                              'assign-type' => 'object-property-array-index',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'namespaces',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 454,
                                  'char' => 46,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'empty-array',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 454,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 454,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 455,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 457,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'namespaces',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 457,
                              'char' => 42,
                            ),
                          ),
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
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'property-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 458,
                                      'char' => 26,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'namespaces',
                                      'file' => '/app/phalcon/Loader.zep',
                                      'line' => 458,
                                      'char' => 37,
                                    ),
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 458,
                                    'char' => 37,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'name',
                                    'file' => '/app/phalcon/Loader.zep',
                                    'line' => 458,
                                    'char' => 42,
                                  ),
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 458,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 458,
                                'char' => 43,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'paths',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 460,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 460,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 460,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 460,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 461,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 462,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'namespaces',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'preparedNamespaces',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 463,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 463,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 464,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 466,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 466,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 467,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Register namespaces and their related directories
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
                  'value' => 'Loader',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 446,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 446,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 446,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 445,
          'last-line' => 471,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setEventsManager',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eventsManager',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ManagerInterface',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 472,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 472,
              'char' => 70,
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
                  'property' => 'eventsManager',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'eventsManager',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 474,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 474,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 475,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the events manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 473,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 472,
          'last-line' => 480,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setExtensions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'extensions',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 481,
              'char' => 52,
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
                  'property' => 'extensions',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'extensions',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 483,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 483,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 485,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 485,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 486,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets an array of file extensions that the loader must try in each attempt
     * to locate the file
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
                  'value' => 'Loader',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 482,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 482,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 482,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 481,
          'last-line' => 502,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setFileCheckingCallback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'callback',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 503,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 503,
              'char' => 64,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_callable',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'callback',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 505,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 505,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 505,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 505,
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
                      'property' => 'fileCheckingCallback',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'callback',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 506,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 506,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 507,
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
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'callback',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 507,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 507,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 507,
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
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'fileCheckingCallback',
                          'expr' => 
                          array (
                            'type' => 'closure',
                            'left' => 
                            array (
                              0 => 
                              array (
                                'type' => 'parameter',
                                'name' => 'file',
                                'const' => 0,
                                'data-type' => 'variable',
                                'mandatory' => 0,
                                'reference' => 0,
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 508,
                                'char' => 60,
                              ),
                            ),
                            'right' => 
                            array (
                              0 => 
                              array (
                                'type' => 'return',
                                'expr' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'true',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 509,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 510,
                                'char' => 13,
                              ),
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 510,
                            'char' => 14,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 510,
                          'char' => 14,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 511,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 511,
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
                          'value' => 'The \'callback\' parameter must be either a callable or NULL.',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 514,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 514,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 514,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 515,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 517,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 517,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 518,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the file check callback.
     *
     * ```php
     * // Default behavior.
     * $loader->setFileCheckingCallback("is_file");
     *
     * // Faster than `is_file()`, but implies some issues if
     * // the file is removed from the filesystem.
     * $loader->setFileCheckingCallback("stream_resolve_include_path");
     *
     * // Do not check file existence.
     * $loader->setFileCheckingCallback(null);
     * ```
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
                  'value' => 'Loader',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 504,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 504,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 504,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 508,
          'last-line' => 522,
          'char' => 53,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'unregister',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 525,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'registered',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 525,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 525,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 525,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Loader.zep',
                'line' => 525,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'spl_autoload_unregister',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array',
                          'left' => 
                          array (
                            0 => 
                            array (
                              'value' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 528,
                                'char' => 25,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 528,
                              'char' => 25,
                            ),
                            1 => 
                            array (
                              'value' => 
                              array (
                                'type' => 'string',
                                'value' => 'autoLoad',
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 530,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Loader.zep',
                              'line' => 530,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 531,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 531,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 531,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 533,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'registered',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 533,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 533,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 534,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 536,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 536,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 537,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Unregister the autoload method
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
                  'value' => 'Loader',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 524,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Loader.zep',
                'line' => 524,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 524,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 523,
          'last-line' => 539,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'prepareNamespace',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'namespaceName',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Loader.zep',
              'line' => 539,
              'char' => 61,
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
                  'variable' => 'localPaths',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 541,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 541,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'paths',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 541,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'prepared',
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 541,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 543,
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
                  'variable' => 'prepared',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 543,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 543,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 545,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'namespaceName',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 545,
                'char' => 42,
              ),
              'key' => 'name',
              'value' => 'paths',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paths',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 546,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 546,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 546,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Loader.zep',
                    'line' => 546,
                    'char' => 38,
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
                          'variable' => 'localPaths',
                          'expr' => 
                          array (
                            'type' => 'array',
                            'left' => 
                            array (
                              0 => 
                              array (
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'paths',
                                  'file' => '/app/phalcon/Loader.zep',
                                  'line' => 547,
                                  'char' => 40,
                                ),
                                'file' => '/app/phalcon/Loader.zep',
                                'line' => 547,
                                'char' => 40,
                              ),
                            ),
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 547,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 547,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 548,
                      'char' => 13,
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
                          'variable' => 'localPaths',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'paths',
                            'file' => '/app/phalcon/Loader.zep',
                            'line' => 549,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 549,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 550,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 552,
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
                      'variable' => 'prepared',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Loader.zep',
                          'line' => 552,
                          'char' => 30,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'localPaths',
                        'file' => '/app/phalcon/Loader.zep',
                        'line' => 552,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Loader.zep',
                      'line' => 552,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Loader.zep',
                  'line' => 553,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 555,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'prepared',
                'file' => '/app/phalcon/Loader.zep',
                'line' => 555,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Loader.zep',
              'line' => 556,
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
                'file' => '/app/phalcon/Loader.zep',
                'line' => 540,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Loader.zep',
            'line' => 540,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Loader.zep',
          'line' => 539,
          'last-line' => 557,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Loader.zep',
      'line' => 43,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Loader.zep',
    'line' => 43,
    'char' => 5,
  ),
);