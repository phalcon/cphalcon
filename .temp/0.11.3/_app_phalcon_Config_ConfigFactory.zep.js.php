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
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Config',
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
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
        'name' => 'Phalcon\\Config\\Adapter\\Grouped',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 13,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
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
        'name' => 'Phalcon\\Config\\Adapter\\Ini',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
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
        'name' => 'Phalcon\\Config\\Adapter\\Json',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 15,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
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
        'name' => 'Phalcon\\Config\\Adapter\\Php',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 16,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Config\\Adapter\\Yaml',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Config\\Exception',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 18,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Factory\\AbstractFactory',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 19,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 20,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Factory\\Exception',
        'alias' => 'FactoryException',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 20,
        'char' => 50,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 21,
    'char' => 3,
  ),
  10 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Config/ConfigFactory.zep',
        'line' => 21,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 37,
    'char' => 2,
  ),
  11 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Loads Config Adapter class using \'adapter\' option, if no extension is
 * provided it will be added to filePath
 *
 *```php
 * use Phalcon\\Config\\ConfigFactory;
 *
 * $options = [
 *     "filePath" => "path/config",
 *     "adapter"  => "php",
 * ];
 *
 * $config = (new ConfigFactory())->load($options);
 *```
 *',
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 38,
    'char' => 5,
  ),
  12 => 
  array (
    'type' => 'class',
    'name' => 'ConfigFactory',
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
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 43,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 43,
              'char' => 52,
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
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 45,
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
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 45,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 45,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 45,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 46,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * ConfigFactory constructor.
     *',
          'file' => '/app/phalcon/Config/ConfigFactory.zep',
          'line' => 43,
          'last-line' => 50,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'load',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'config',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 51,
              'char' => 32,
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
                  'variable' => 'adapter',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 53,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'extension',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 53,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'first',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 53,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'oldConfig',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 53,
                  'char' => 49,
                ),
                4 => 
                array (
                  'variable' => 'second',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 53,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 55,
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
                    'value' => 'config',
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 55,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 55,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 55,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 55,
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
                      'variable' => 'oldConfig',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'config',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 56,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 56,
                      'char' => 35,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'extension',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'pathinfo',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'config',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 57,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 57,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PATHINFO_EXTENSION',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 57,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 57,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 57,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 57,
                      'char' => 65,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 59,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'unlikely',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'list',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'extension',
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 59,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 59,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 59,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 59,
                    'char' => 42,
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
                              'value' => 'You need to provide the extension in the file path',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 62,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 62,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 62,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 63,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 65,
                  'char' => 15,
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
                      'variable' => 'config',
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
                              'value' => 'adapter',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 66,
                              'char' => 26,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'extension',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 66,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 66,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'string',
                              'value' => 'filePath',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 67,
                              'char' => 26,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'oldConfig',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 68,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 68,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 68,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 68,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 69,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 71,
              'char' => 10,
            ),
            2 => 
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
                      'value' => 'config',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 71,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 71,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 71,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 71,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'instanceof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'config',
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 71,
                    'char' => 56,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'Config',
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 71,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 71,
                  'char' => 65,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 71,
                'char' => 65,
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
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'config',
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 72,
                          'char' => 33,
                        ),
                        'name' => 'toArray',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 72,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 72,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 73,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 75,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 75,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 75,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 75,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 75,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 75,
                'char' => 45,
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
                          'value' => 'Config must be array or Phalcon\\\\Config\\\\Config object',
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 78,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 78,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 78,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 79,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 81,
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
                        'value' => 'config',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 81,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'filePath',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 81,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 81,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 81,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 81,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 81,
                'char' => 45,
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
                          'value' => 'You must provide \'filePath\' option in factory config parameter.',
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 84,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 84,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 84,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 85,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 87,
              'char' => 10,
            ),
            5 => 
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
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'config',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 87,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'adapter',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 87,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 87,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 87,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 87,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 87,
                'char' => 44,
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
                          'value' => 'You must provide \'adapter\' option in factory config parameter.',
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 90,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 90,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 90,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 91,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 93,
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
                  'variable' => 'adapter',
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
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'config',
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 93,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'adapter',
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 93,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 93,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 93,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 93,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 93,
                  'char' => 50,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'first',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'config',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 94,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'filePath',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 94,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 94,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 94,
                  'char' => 39,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'second',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 95,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 95,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 97,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
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
                        'value' => 'first',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 97,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 97,
                      'char' => 25,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '.',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 97,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 97,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 97,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 97,
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
                      'variable' => 'first',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'first',
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 98,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '.',
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 98,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 98,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'lcfirst',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'adapter',
                                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                'line' => 98,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 98,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 98,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 98,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 98,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 99,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 101,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => 'ini',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 101,
                  'char' => 18,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'adapter',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 101,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 101,
                'char' => 28,
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
                      'variable' => 'second',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Arr',
                        'dynamic' => 0,
                        'name' => 'get',
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'config',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 102,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 102,
                            'char' => 41,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'mode',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 102,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 102,
                            'char' => 47,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 102,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 102,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 102,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 102,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 103,
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
                      'type' => 'string',
                      'value' => 'yaml',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 103,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapter',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 103,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 103,
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
                          'variable' => 'second',
                          'expr' => 
                          array (
                            'type' => 'scall',
                            'dynamic-class' => 0,
                            'class' => 'Arr',
                            'dynamic' => 0,
                            'name' => 'get',
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'config',
                                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                  'line' => 104,
                                  'char' => 41,
                                ),
                                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                'line' => 104,
                                'char' => 41,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'callbacks',
                                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                  'line' => 104,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                'line' => 104,
                                'char' => 52,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'empty-array',
                                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                  'line' => 104,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                'line' => 104,
                                'char' => 56,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 104,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 104,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 105,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 107,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 107,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 107,
                  'char' => 21,
                ),
                'name' => 'newInstance',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapter',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 107,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 107,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'first',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 107,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 107,
                    'char' => 48,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'second',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 107,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 107,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 107,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 108,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Load a config to create a new instance
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 52,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/ConfigFactory.zep',
            'line' => 52,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/ConfigFactory.zep',
          'line' => 51,
          'last-line' => 112,
          'char' => 19,
        ),
        2 => 
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
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 113,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'fileName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 113,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 113,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 113,
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
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 115,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 117,
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
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 117,
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
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 117,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 117,
                    'char' => 32,
                  ),
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 117,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 119,
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
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 119,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'services',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 119,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 119,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 119,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 119,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 119,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 119,
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
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 120,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mapper',
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 120,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 120,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 120,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 120,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 120,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 122,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'json',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 122,
                        'char' => 23,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 122,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 122,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => 'php',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 122,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Config/ConfigFactory.zep',
                        'line' => 122,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 122,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 122,
                    'char' => 46,
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
                          'property' => 'services',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 123,
                              'char' => 40,
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
                                  'type' => 'variable',
                                  'value' => 'fileName',
                                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                  'line' => 123,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                'line' => 123,
                                'char' => 69,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 123,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 123,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 124,
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
                              'file' => '/app/phalcon/Config/ConfigFactory.zep',
                              'line' => 125,
                              'char' => 40,
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
                                  'type' => 'variable',
                                  'value' => 'fileName',
                                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                  'line' => 125,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                'line' => 125,
                                'char' => 69,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'params',
                                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                  'line' => 125,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                                'line' => 125,
                                'char' => 77,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/ConfigFactory.zep',
                            'line' => 125,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Config/ConfigFactory.zep',
                          'line' => 125,
                          'char' => 78,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 126,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 127,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 129,
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
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 129,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'services',
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 129,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 129,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Config/ConfigFactory.zep',
                  'line' => 129,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 129,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 130,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a new Config instance
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 114,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/ConfigFactory.zep',
            'line' => 114,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/ConfigFactory.zep',
          'line' => 113,
          'last-line' => 134,
          'char' => 19,
        ),
        3 => 
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
                      'value' => 'grouped',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 138,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Config\\\\Adapter\\\\Grouped',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 138,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 138,
                    'char' => 58,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'ini',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 139,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Config\\\\Adapter\\\\Ini',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 139,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 139,
                    'char' => 54,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'json',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 140,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Config\\\\Adapter\\\\Json',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 140,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 140,
                    'char' => 55,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'php',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 141,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Config\\\\Adapter\\\\Php',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 141,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 141,
                    'char' => 54,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'string',
                      'value' => 'yaml',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 142,
                      'char' => 21,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Phalcon\\\\Config\\\\Adapter\\\\Yaml',
                      'file' => '/app/phalcon/Config/ConfigFactory.zep',
                      'line' => 143,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Config/ConfigFactory.zep',
                    'line' => 143,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 143,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Config/ConfigFactory.zep',
              'line' => 144,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the adapters for the factory
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
                'file' => '/app/phalcon/Config/ConfigFactory.zep',
                'line' => 136,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Config/ConfigFactory.zep',
            'line' => 136,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/ConfigFactory.zep',
          'line' => 135,
          'last-line' => 145,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Config/ConfigFactory.zep',
      'line' => 38,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Config/ConfigFactory.zep',
    'line' => 38,
    'char' => 5,
  ),
);