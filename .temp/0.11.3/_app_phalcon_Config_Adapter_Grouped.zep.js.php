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
    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Config\\Adapter',
    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
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
        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
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
        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
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
        'name' => 'Phalcon\\Factory\\Exception',
        'alias' => 'FactoryException',
        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
        'line' => 15,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
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
        'name' => 'Phalcon\\Config\\ConfigFactory',
        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
        'line' => 16,
        'char' => 33,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
    'line' => 68,
    'char' => 2,
  ),
  6 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Reads multiple files (or arrays) and merges them all together.
 *
 * See `Phalcon\\Config\\Factory::load` To load Config Adapter class using \'adapter\' option.
 *
 * ```php
 * use Phalcon\\Config\\Adapter\\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.php",
 *         "path/to/config.dist.php",
 *     ]
 * );
 * ```
 *
 * ```php
 * use Phalcon\\Config\\Adapter\\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.json",
 *         "path/to/config.dist.json",
 *     ],
 *     "json"
 * );
 * ```
 *
 * ```php
 * use Phalcon\\Config\\Adapter\\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         [
 *             "filePath" => "path/to/config.php",
 *             "adapter"  => "php",
 *         ],
 *         [
 *             "filePath" => "path/to/config.json",
 *             "adapter"  => "json",
 *         ],
 *         [
 *             "adapter"  => "array",
 *             "config"   => [
 *                 "property" => "value",
 *             ],
 *         ],
 *     ],
 * );
 * ```
 *',
    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
    'line' => 69,
    'char' => 5,
  ),
  7 => 
  array (
    'type' => 'class',
    'name' => 'Grouped',
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
              'name' => 'arrayConfig',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
              'line' => 74,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultAdapter',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'php',
                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                'line' => 74,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
              'line' => 74,
              'char' => 81,
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
                  'variable' => 'configArray',
                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                  'line' => 76,
                  'char' => 24,
                ),
                1 => 
                array (
                  'variable' => 'configInstance',
                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                  'line' => 76,
                  'char' => 40,
                ),
                2 => 
                array (
                  'variable' => 'configName',
                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                  'line' => 76,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
              'line' => 78,
              'char' => 14,
            ),
            1 => 
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
                      'type' => 'empty-array',
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 78,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                    'line' => 78,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                'line' => 78,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
              'line' => 80,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'arrayConfig',
                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                'line' => 80,
                'char' => 39,
              ),
              'value' => 'configName',
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
                      'variable' => 'configInstance',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'configName',
                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                        'line' => 81,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 81,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                  'line' => 84,
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
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'configName',
                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                        'line' => 84,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 84,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 84,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                    'line' => 84,
                    'char' => 45,
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
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 85,
                          'char' => 23,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'defaultAdapter',
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 85,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                        'line' => 85,
                        'char' => 40,
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
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 86,
                              'char' => 26,
                            ),
                            'name' => 'merge',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'list',
                                    'left' => 
                                    array (
                                      'type' => 'new',
                                      'class' => 'ConfigFactory',
                                      'dynamic' => 0,
                                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                      'line' => 87,
                                      'char' => 45,
                                    ),
                                    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                    'line' => 87,
                                    'char' => 47,
                                  ),
                                  'name' => 'load',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'configName',
                                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                        'line' => 87,
                                        'char' => 63,
                                      ),
                                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                      'line' => 87,
                                      'char' => 63,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 88,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                'line' => 88,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                            'line' => 88,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 90,
                          'char' => 28,
                        ),
                        1 => 
                        array (
                          'type' => 'continue',
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 91,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 93,
                      'char' => 19,
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
                          'variable' => 'configInstance',
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
                                  'value' => 'filePath',
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 94,
                                  'char' => 30,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'configName',
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 94,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                'line' => 94,
                                'char' => 42,
                              ),
                              1 => 
                              array (
                                'key' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'adapter',
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 95,
                                  'char' => 30,
                                ),
                                'value' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'defaultAdapter',
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 96,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                'line' => 96,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                            'line' => 96,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 96,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 97,
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
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'isset',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'configInstance',
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 97,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'adapter',
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 97,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                            'line' => 97,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 97,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                        'line' => 97,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'configInstance',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'string',
                                  'value' => 'adapter',
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 98,
                                  'char' => 43,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'defaultAdapter',
                                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                'line' => 98,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 98,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 99,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 101,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                  'line' => 101,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 101,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'configInstance',
                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                        'line' => 101,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'adapter',
                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                        'line' => 101,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 101,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                    'line' => 101,
                    'char' => 50,
                  ),
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
                              'type' => 'variable',
                              'value' => 'configInstance',
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 102,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'config',
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 102,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                            'line' => 102,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 102,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                        'line' => 102,
                        'char' => 50,
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
                                    'type' => 'string',
                                    'value' => 'To use \'array\' adapter you have to specify ',
                                    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                    'line' => 104,
                                    'char' => 69,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'the \'config\' as an array.',
                                    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                    'line' => 106,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 106,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                'line' => 106,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                            'line' => 106,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 107,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 109,
                      'char' => 19,
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
                          'variable' => 'configArray',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'configInstance',
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 109,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'config',
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 109,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                            'line' => 109,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 109,
                          'char' => 60,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'configInstance',
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
                                  'value' => 'configArray',
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 110,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                'line' => 110,
                                'char' => 60,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                            'line' => 110,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 110,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 111,
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
                          'variable' => 'configInstance',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'list',
                              'left' => 
                              array (
                                'type' => 'new',
                                'class' => 'ConfigFactory',
                                'dynamic' => 0,
                                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                'line' => 112,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                              'line' => 112,
                              'char' => 60,
                            ),
                            'name' => 'load',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'configInstance',
                                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                  'line' => 112,
                                  'char' => 80,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                                'line' => 112,
                                'char' => 80,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                            'line' => 112,
                            'char' => 81,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 112,
                          'char' => 81,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 113,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                  'line' => 115,
                  'char' => 16,
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
                      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                      'line' => 115,
                      'char' => 18,
                    ),
                    'name' => 'merge',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'configInstance',
                          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                          'line' => 115,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                        'line' => 115,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                    'line' => 115,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
                  'line' => 116,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
              'line' => 117,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Config\\Adapter\\Grouped constructor
     *',
          'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
          'line' => 74,
          'last-line' => 118,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
      'line' => 69,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Config/Adapter/Grouped.zep',
    'line' => 69,
    'char' => 5,
  ),
);