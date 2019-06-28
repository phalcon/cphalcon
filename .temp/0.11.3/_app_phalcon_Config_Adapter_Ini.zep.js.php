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
    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Config\\Adapter',
    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
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
        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
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
        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
    'line' => 57,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Reads ini files and converts them to Phalcon\\Config objects.
 *
 * Given the next configuration file:
 *
 *```ini
 * [database]
 * adapter = Mysql
 * host = localhost
 * username = scott
 * password = cheetah
 * dbname = test_db
 *
 * [phalcon]
 * controllersDir = "../app/controllers/"
 * modelsDir = "../app/models/"
 * viewsDir = "../app/views/"
 * ```
 *
 * You can read it as follows:
 *
 *```php
 * use Phalcon\\Config\\Adapter\\Ini;
 *
 * $config = new Ini("path/config.ini");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *```
 *
 * PHP constants may also be parsed in the ini file, so if you define a constant
 * as an ini value before calling the constructor, the constant\'s value will be
 * integrated into the results. To use it this way you must specify the optional
 * second parameter as `INI_SCANNER_NORMAL` when calling the constructor:
 *
 * ```php
 * $config = new \\Phalcon\\Config\\Adapter\\Ini(
 *     "path/config-with-constants.ini",
 *     INI_SCANNER_NORMAL
 * );
 * ```
 *',
    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
    'line' => 58,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Ini',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Config',
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
              'name' => 'filePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 63,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'mode',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 63,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 63,
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
                  'variable' => 'directives',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 65,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'iniConfig',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 65,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'lastValue',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 65,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 65,
                  'char' => 51,
                ),
                4 => 
                array (
                  'variable' => 'section',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 65,
                  'char' => 60,
                ),
                5 => 
                array (
                  'variable' => 'sections',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 65,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 66,
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
                  'variable' => 'config',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 66,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 69,
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
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 69,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'mode',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 69,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 69,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 69,
                'char' => 33,
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
                      'variable' => 'mode',
                      'expr' => 
                      array (
                        'type' => 'constant',
                        'value' => 'INI_SCANNER_RAW',
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 70,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 70,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 71,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 73,
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
                  'variable' => 'iniConfig',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'parse_ini_file',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filePath',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 73,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 73,
                        'char' => 48,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 73,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 73,
                        'char' => 54,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mode',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 73,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 73,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 73,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 73,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 75,
              'char' => 10,
            ),
            4 => 
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
                    'type' => 'variable',
                    'value' => 'iniConfig',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 75,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 75,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 75,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 75,
                'char' => 41,
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
                              'value' => 'Configuration file ',
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 77,
                              'char' => 37,
                            ),
                            'right' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'basename',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'filePath',
                                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                    'line' => 77,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                  'line' => 77,
                                  'char' => 56,
                                ),
                              ),
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 77,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 77,
                            'char' => 58,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' cannot be loaded',
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 78,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 78,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 78,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 78,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 79,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 81,
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
                  'variable' => 'config',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 81,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 81,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 83,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'iniConfig',
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 83,
                'char' => 46,
              ),
              'key' => 'section',
              'value' => 'directives',
              'reverse' => 0,
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
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'directives',
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 84,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 84,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 84,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 84,
                    'char' => 44,
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
                          'variable' => 'sections',
                          'expr' => 
                          array (
                            'type' => 'empty-array',
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 85,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 85,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 87,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'directives',
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 87,
                        'char' => 51,
                      ),
                      'key' => 'path',
                      'value' => 'lastValue',
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
                              'assign-type' => 'variable-append',
                              'operator' => 'assign',
                              'variable' => 'sections',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                  'line' => 88,
                                  'char' => 43,
                                ),
                                'name' => 'parseIniString',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'cast',
                                      'left' => 'string',
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'path',
                                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                        'line' => 89,
                                        'char' => 38,
                                      ),
                                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                      'line' => 89,
                                      'char' => 38,
                                    ),
                                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                    'line' => 89,
                                    'char' => 38,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'lastValue',
                                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                      'line' => 91,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                    'line' => 91,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                'line' => 91,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 91,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 92,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 94,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'count',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sections',
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 94,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 94,
                            'char' => 34,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 94,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'config',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'section',
                                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                  'line' => 95,
                                  'char' => 39,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'call_user_func_array',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'array_replace_recursive',
                                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                      'line' => 96,
                                      'char' => 48,
                                    ),
                                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                    'line' => 96,
                                    'char' => 48,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'sections',
                                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                      'line' => 98,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                    'line' => 98,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                'line' => 98,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 98,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 99,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 100,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'config',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'section',
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 101,
                              'char' => 35,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 101,
                              'char' => 44,
                            ),
                            'name' => 'cast',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'directives',
                                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                  'line' => 101,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                'line' => 101,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 101,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 101,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 102,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 103,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 105,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 105,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 105,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 105,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 106,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Ini constructor.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
            'line' => 64,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
          'line' => 63,
          'last-line' => 111,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'cast',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'ini',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 112,
              'char' => 36,
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
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 114,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'lowerIni',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 114,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 114,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 116,
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
                    'value' => 'ini',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 116,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 116,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 116,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 116,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'ini',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 117,
                    'char' => 35,
                  ),
                  'key' => 'key',
                  'value' => 'value',
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'ini',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'key',
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 118,
                              'char' => 28,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                              'line' => 118,
                              'char' => 37,
                            ),
                            'name' => 'cast',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                  'line' => 118,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                                'line' => 118,
                                'char' => 48,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 118,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 118,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 119,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 121,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'ini',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 121,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 122,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 125,
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
                  'variable' => 'ini',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ini',
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 125,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 125,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 125,
                  'char' => 36,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'lowerIni',
                  'expr' => 
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
                          'type' => 'variable',
                          'value' => 'ini',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 126,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 126,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 126,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 126,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 128,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'list',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'lowerIni',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 128,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 128,
                'char' => 27,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'true',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 129,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 130,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'yes',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 130,
                    'char' => 21,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 131,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'on',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 131,
                    'char' => 20,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 132,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 133,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 133,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'false',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 133,
                    'char' => 23,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 134,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'no',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 134,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 135,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'off',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 135,
                    'char' => 21,
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
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 136,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 137,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 137,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'null',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 137,
                    'char' => 22,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 138,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 139,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 139,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 142,
              'char' => 10,
            ),
            4 => 
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
                      'value' => 'ini',
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 142,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 142,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 142,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 142,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_numeric',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ini',
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 142,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 142,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 142,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 142,
                'char' => 53,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_match',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/[.]+/',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 143,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 143,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ini',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 143,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 143,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 143,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'double',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ini',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 144,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 144,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 145,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'int',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ini',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 146,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 146,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 147,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 148,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 150,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'ini',
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 150,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 151,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * We have to cast values manually because parse_ini_file() has a poor
     * implementation.
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
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 112,
                'char' => 46,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 112,
                'char' => 53,
              ),
              2 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'double',
                'mandatory' => 0,
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 112,
                'char' => 62,
              ),
              3 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 112,
                'char' => 68,
              ),
              4 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 113,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
            'line' => 113,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
          'line' => 112,
          'last-line' => 155,
          'char' => 22,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'parseIniString',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 156,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 156,
              'char' => 62,
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
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 158,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'position',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 158,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 160,
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
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 160,
                      'char' => 29,
                    ),
                    'name' => 'cast',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 160,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 160,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 160,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 160,
                  'char' => 41,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'position',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strpos',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 161,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 161,
                        'char' => 35,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '.',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 161,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 161,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 161,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 161,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 163,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 163,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'position',
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 163,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 163,
                'char' => 31,
              ),
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
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 165,
                          'char' => 22,
                        ),
                        'value' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 166,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 166,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 166,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 167,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 169,
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
                  'variable' => 'key',
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
                          'value' => 'path',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 169,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 169,
                        'char' => 31,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 169,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 169,
                        'char' => 34,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'position',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 169,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 169,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 169,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 169,
                  'char' => 45,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'path',
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
                          'value' => 'path',
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 170,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 170,
                        'char' => 31,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'add',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'position',
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 170,
                            'char' => 42,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 170,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 170,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 170,
                        'char' => 45,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 170,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                  'line' => 170,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 172,
              'char' => 14,
            ),
            4 => 
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
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 173,
                      'char' => 17,
                    ),
                    'value' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                        'line' => 173,
                        'char' => 24,
                      ),
                      'name' => 'parseIniString',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'path',
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 173,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 173,
                          'char' => 44,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                            'line' => 173,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                          'line' => 173,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                      'line' => 174,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                    'line' => 174,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 174,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Config/Adapter/Ini.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Build multidimensional array from string
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
                'file' => '/app/phalcon/Config/Adapter/Ini.zep',
                'line' => 157,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/Adapter/Ini.zep',
            'line' => 157,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Adapter/Ini.zep',
          'line' => 156,
          'last-line' => 176,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Config/Adapter/Ini.zep',
      'line' => 58,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Config/Adapter/Ini.zep',
    'line' => 58,
    'char' => 5,
  ),
);