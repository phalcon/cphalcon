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
    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Config\\Adapter',
    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
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
        'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
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
        'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
    'line' => 52,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Reads YAML files and converts them to Phalcon\\Config objects.
 *
 * Given the following configuration file:
 *
 *```yaml
 * phalcon:
 *   baseuri:        /phalcon/
 *   controllersDir: !approot  /app/controllers/
 * models:
 *   metadata: memory
 *```
 *
 * You can read it as follows:
 *
 *```php
 * define(
 *     "APPROOT",
 *     dirname(__DIR__)
 * );
 *
 * use Phalcon\\Config\\Adapter\\Yaml;
 *
 * $config = new Yaml(
 *     "path/config.yaml",
 *     [
 *         "!approot" => function($value) {
 *             return APPROOT . $value;
 *         },
 *     ]
 * );
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *```
 *',
    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
    'line' => 53,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Yaml',
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
              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
              'line' => 58,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'callbacks',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                'line' => 58,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
              'line' => 58,
              'char' => 74,
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
                  'variable' => 'yamlConfig',
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 60,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
              'line' => 61,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'ndocs',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                    'line' => 61,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 61,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
              'line' => 63,
              'char' => 10,
            ),
            2 => 
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
                    'type' => 'fcall',
                    'name' => 'extension_loaded',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'yaml',
                          'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                          'line' => 63,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                        'line' => 63,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                    'line' => 63,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 63,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                'line' => 63,
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
                          'value' => 'Yaml extension not loaded',
                          'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                          'line' => 64,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                        'line' => 64,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                    'line' => 64,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 65,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
              'line' => 67,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'callbacks',
                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                    'line' => 67,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 67,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                'line' => 67,
                'char' => 29,
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
                      'variable' => 'yamlConfig',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'yaml_parse_file',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filePath',
                              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                              'line' => 68,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                            'line' => 68,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                        'line' => 68,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                      'line' => 68,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 69,
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
                      'variable' => 'yamlConfig',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'yaml_parse_file',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filePath',
                              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                              'line' => 70,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                            'line' => 70,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                              'line' => 70,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                            'line' => 70,
                            'char' => 57,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ndocs',
                              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                              'line' => 70,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                            'line' => 70,
                            'char' => 64,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'callbacks',
                              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                              'line' => 70,
                              'char' => 75,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                            'line' => 70,
                            'char' => 75,
                          ),
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                        'line' => 70,
                        'char' => 76,
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                      'line' => 70,
                      'char' => 76,
                    ),
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 71,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
              'line' => 73,
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
                    'value' => 'yamlConfig',
                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                    'line' => 73,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                    'line' => 73,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 73,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                'line' => 73,
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'Configuration file ',
                              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                              'line' => 75,
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
                                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                                    'line' => 75,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                                  'line' => 75,
                                  'char' => 56,
                                ),
                              ),
                              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                              'line' => 75,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                            'line' => 75,
                            'char' => 58,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ' can\'t be loaded',
                            'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                            'line' => 76,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                          'line' => 76,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                        'line' => 76,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                    'line' => 76,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                  'line' => 77,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
              'line' => 79,
              'char' => 14,
            ),
            5 => 
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
                      'value' => 'yamlConfig',
                      'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                      'line' => 79,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                    'line' => 79,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
                'line' => 79,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
              'line' => 80,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Config\\Adapter\\Yaml constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
            'line' => 59,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
          'line' => 58,
          'last-line' => 81,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
      'line' => 53,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Config/Adapter/Yaml.zep',
    'line' => 53,
    'char' => 5,
  ),
);