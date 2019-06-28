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
    'file' => '/app/phalcon/Config/Adapter/Json.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Config\\Adapter',
    'file' => '/app/phalcon/Config/Adapter/Json.zep',
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
        'file' => '/app/phalcon/Config/Adapter/Json.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Config/Adapter/Json.zep',
    'line' => 34,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Reads JSON files and converts them to Phalcon\\Config objects.
 *
 * Given the following configuration file:
 *
 *```json
 * {"phalcon":{"baseuri":"\\/phalcon\\/"},"models":{"metadata":"memory"}}
 *```
 *
 * You can read it as follows:
 *
 *```php
 * use Phalcon\\Config\\Adapter\\Json;
 *
 * $config = new Json("path/config.json");
 *
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *```
 *',
    'file' => '/app/phalcon/Config/Adapter/Json.zep',
    'line' => 35,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Json',
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
              'file' => '/app/phalcon/Config/Adapter/Json.zep',
              'line' => 40,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
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
                      'type' => 'fcall',
                      'name' => 'json_decode',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'file_get_contents',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filePath',
                                  'file' => '/app/phalcon/Config/Adapter/Json.zep',
                                  'line' => 44,
                                  'char' => 43,
                                ),
                                'file' => '/app/phalcon/Config/Adapter/Json.zep',
                                'line' => 44,
                                'char' => 43,
                              ),
                            ),
                            'file' => '/app/phalcon/Config/Adapter/Json.zep',
                            'line' => 44,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Json.zep',
                          'line' => 44,
                          'char' => 44,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Config/Adapter/Json.zep',
                            'line' => 46,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Config/Adapter/Json.zep',
                          'line' => 46,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Config/Adapter/Json.zep',
                      'line' => 47,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Config/Adapter/Json.zep',
                    'line' => 47,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Config/Adapter/Json.zep',
                'line' => 47,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Config/Adapter/Json.zep',
              'line' => 48,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Config\\Adapter\\Json constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Config/Adapter/Json.zep',
            'line' => 41,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Config/Adapter/Json.zep',
          'line' => 40,
          'last-line' => 49,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Config/Adapter/Json.zep',
      'line' => 35,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Config/Adapter/Json.zep',
    'line' => 35,
    'char' => 5,
  ),
);