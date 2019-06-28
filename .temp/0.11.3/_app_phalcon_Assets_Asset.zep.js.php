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
    'file' => '/app/phalcon/Assets/Asset.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets',
    'file' => '/app/phalcon/Assets/Asset.zep',
    'line' => 19,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents an asset asset
 *
 *```php
 * $asset = new \\Phalcon\\Assets\\Asset("js", "javascripts/jquery.js");
 *```
 *',
    'file' => '/app/phalcon/Assets/Asset.zep',
    'line' => 20,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Asset',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'AssetInterface',
        'file' => '/app/phalcon/Assets/Asset.zep',
        'line' => 21,
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
          'name' => 'attributes',
          'docblock' => '**
     * @var array | null
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 25,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 29,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'autoVersion',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 30,
            'char' => 32,
          ),
          'docblock' => '**
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 30,
              'char' => 38,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 33,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'filter',
          'docblock' => '**
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 34,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 38,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'local',
          'docblock' => '**
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 39,
              'char' => 27,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 43,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'path',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 44,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 48,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sourcePath',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 49,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 53,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'targetPath',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 54,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 58,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'targetUri',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 59,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 63,
          'char' => 6,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'type',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 64,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 69,
          'char' => 3,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'version',
          'docblock' => '**
	 * Version of resource
	 * @var string
	 *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 70,
              'char' => 25,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 70,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 74,
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
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 76,
              'char' => 20,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 77,
              'char' => 20,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'local',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 78,
                'char' => 26,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 78,
              'char' => 26,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 79,
                'char' => 27,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 79,
              'char' => 27,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 80,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 80,
              'char' => 30,
            ),
            5 => 
            array (
              'type' => 'parameter',
              'name' => 'version',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 81,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 81,
              'char' => 30,
            ),
            6 => 
            array (
              'type' => 'parameter',
              'name' => 'autoVersion',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 83,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 83,
              'char' => 5,
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
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 85,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 85,
                  'char' => 37,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'path',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 86,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 86,
                  'char' => 37,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'local',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'local',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 87,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 87,
                  'char' => 38,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'filter',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filter',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 88,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 88,
                  'char' => 39,
                ),
                4 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'attributes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 89,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 89,
                  'char' => 43,
                ),
                5 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'version',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'version',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 90,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 90,
                  'char' => 40,
                ),
                6 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'autoVersion',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'autoVersion',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 91,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 91,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 92,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Assets\\Asset constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 84,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 75,
          'last-line' => 96,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAssetKey',
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
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 99,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 101,
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
                  'variable' => 'key',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 101,
                          'char' => 24,
                        ),
                        'name' => 'getType',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 101,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ':',
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 101,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 101,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 101,
                        'char' => 46,
                      ),
                      'name' => 'getPath',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 101,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 101,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 101,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 103,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'md5',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 103,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 103,
                    'char' => 23,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 103,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 104,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the asset\'s key.
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
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 98,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 98,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 97,
          'last-line' => 109,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getContent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'basePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 110,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 110,
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
                  'variable' => 'sourcePath',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 112,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'completePath',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 112,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'content',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 112,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 114,
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
                  'variable' => 'sourcePath',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 114,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sourcePath',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 114,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 114,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 114,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 116,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'sourcePath',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 116,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 116,
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
                      'variable' => 'sourcePath',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 117,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 117,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 117,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 117,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 118,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 123,
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
                  'variable' => 'completePath',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'basePath',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 123,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sourcePath',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 123,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 123,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 123,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 128,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 128,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'local',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 128,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 128,
                'char' => 24,
              ),
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
                              'value' => 'completePath',
                              'file' => '/app/phalcon/Assets/Asset.zep',
                              'line' => 132,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 132,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 132,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 132,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 132,
                    'char' => 52,
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
                                  'value' => 'Asset\'s content for \'',
                                  'file' => '/app/phalcon/Assets/Asset.zep',
                                  'line' => 134,
                                  'char' => 43,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'completePath',
                                  'file' => '/app/phalcon/Assets/Asset.zep',
                                  'line' => 134,
                                  'char' => 58,
                                ),
                                'file' => '/app/phalcon/Assets/Asset.zep',
                                'line' => 134,
                                'char' => 58,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\' cannot be read',
                                'file' => '/app/phalcon/Assets/Asset.zep',
                                'line' => 135,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Assets/Asset.zep',
                              'line' => 135,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 135,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 135,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 136,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 137,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 143,
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
                  'variable' => 'content',
                  'expr' => 
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
                          'value' => 'completePath',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 143,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 143,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 143,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 143,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 145,
              'char' => 10,
            ),
            6 => 
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
                    'value' => 'content',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 145,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 145,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 145,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 145,
                'char' => 39,
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
                              'value' => 'Asset\'s content for \'',
                              'file' => '/app/phalcon/Assets/Asset.zep',
                              'line' => 147,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'completePath',
                              'file' => '/app/phalcon/Assets/Asset.zep',
                              'line' => 147,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 147,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\' cannot be read',
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 148,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 148,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 148,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 148,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 149,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 151,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'content',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 151,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 152,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the content of the asset as an string
     * Optionally a base path where the asset is located can be set
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
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 110,
          'last-line' => 156,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRealSourcePath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'basePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 157,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 157,
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
                  'variable' => 'sourcePath',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 159,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 161,
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
                  'variable' => 'sourcePath',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 161,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sourcePath',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 161,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 161,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 161,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 163,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'sourcePath',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 163,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 163,
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
                      'variable' => 'sourcePath',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 164,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 164,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 164,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 164,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 165,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 167,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 167,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'local',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 167,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 167,
                'char' => 24,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'realpath',
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
                            'value' => 'basePath',
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 171,
                            'char' => 38,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'sourcePath',
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 171,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 171,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 171,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 171,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 172,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 174,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'sourcePath',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 174,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the complete location where the asset is located
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
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 158,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 158,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 157,
          'last-line' => 179,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRealTargetPath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'basePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 180,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 180,
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
                  'variable' => 'targetPath',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 182,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'completePath',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 182,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 184,
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
                  'variable' => 'targetPath',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 184,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'targetPath',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 184,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 184,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 184,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 186,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'targetPath',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 186,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 186,
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
                      'variable' => 'targetPath',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 187,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 187,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 187,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 187,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 188,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 190,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 190,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'local',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 190,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 190,
                'char' => 24,
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
                      'variable' => 'completePath',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'basePath',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 194,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'targetPath',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 194,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 194,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 194,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 200,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
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
                          'value' => 'completePath',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 200,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 200,
                        'char' => 40,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 200,
                    'char' => 42,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'realpath',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'completePath',
                              'file' => '/app/phalcon/Assets/Asset.zep',
                              'line' => 201,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 201,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 201,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 202,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 204,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'completePath',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 204,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 205,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 207,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'targetPath',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 207,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 208,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the complete location where the asset must be written
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
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 181,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 181,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 180,
          'last-line' => 212,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRealTargetUri',
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
                  'variable' => 'modificationTime',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 215,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'targetUri',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 215,
                  'char' => 40,
                ),
                2 => 
                array (
                  'variable' => 'version',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 215,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 217,
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
                  'variable' => 'targetUri',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 217,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'targetUri',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 217,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 217,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 217,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 219,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'targetUri',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 219,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 219,
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
                      'variable' => 'targetUri',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 220,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 220,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 220,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 220,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 221,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 223,
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
                  'variable' => 'version',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 223,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'version',
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 223,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 223,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 223,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 225,
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 225,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'autoVersion',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 225,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 225,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 225,
                    'char' => 38,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'local',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 225,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 225,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 225,
                'char' => 45,
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
                      'variable' => 'modificationTime',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'filemtime',
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
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Assets/Asset.zep',
                                'line' => 226,
                                'char' => 51,
                              ),
                              'name' => 'getRealSourcePath',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Assets/Asset.zep',
                              'line' => 226,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 226,
                            'char' => 71,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 226,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 226,
                      'char' => 72,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'version',
                      'expr' => 
                      array (
                        'type' => 'ternary',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'version',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 227,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'version',
                              'file' => '/app/phalcon/Assets/Asset.zep',
                              'line' => 227,
                              'char' => 54,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '.',
                              'file' => '/app/phalcon/Assets/Asset.zep',
                              'line' => 227,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 227,
                            'char' => 58,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'modificationTime',
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 227,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 227,
                          'char' => 77,
                        ),
                        'extra' => 
                        array (
                          'type' => 'variable',
                          'value' => 'modificationTime',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 227,
                          'char' => 95,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 227,
                        'char' => 95,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 227,
                      'char' => 95,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 228,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 230,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'version',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 230,
                'char' => 20,
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
                      'variable' => 'targetUri',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'targetUri',
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 231,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '?ver=',
                            'file' => '/app/phalcon/Assets/Asset.zep',
                            'line' => 231,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 231,
                          'char' => 47,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'version',
                          'file' => '/app/phalcon/Assets/Asset.zep',
                          'line' => 231,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Assets/Asset.zep',
                        'line' => 231,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Assets/Asset.zep',
                      'line' => 231,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 232,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 234,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'targetUri',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 234,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 235,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the real target uri for the generated HTML
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
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 214,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 214,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 213,
          'last-line' => 239,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isAutoVersion',
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
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 242,
                  'char' => 15,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'autoVersion',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 242,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 242,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 243,
              'char' => 2,
            ),
          ),
          'docblock' => '**
     * Checks if resource is using auto version
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
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 241,
                'char' => 2,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 241,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 240,
          'last-line' => 247,
          'char' => 16,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 248,
              'char' => 51,
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
                  'property' => 'attributes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 250,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 250,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 252,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 252,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 253,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets extra HTML attributes
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 249,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 249,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 249,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 248,
          'last-line' => 257,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setFilter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 258,
              'char' => 42,
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
                  'property' => 'filter',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filter',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 260,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 260,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 262,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 262,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 263,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the asset must be filtered or not
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 259,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 259,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 259,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 258,
          'last-line' => 267,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setLocal',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'local',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 268,
              'char' => 40,
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
                  'property' => 'local',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'local',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 270,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 270,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 272,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 272,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 273,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the asset is local or external
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 269,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 269,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 269,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 268,
          'last-line' => 277,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setSourcePath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sourcePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 278,
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
                  'property' => 'sourcePath',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sourcePath',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 280,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 280,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 282,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 282,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 283,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the asset\'s source path
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 279,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 279,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 279,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 278,
          'last-line' => 287,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTargetPath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'targetPath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 288,
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
                  'property' => 'targetPath',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'targetPath',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 290,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 290,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 292,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 292,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 293,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the asset\'s target path
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 289,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 289,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 289,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 288,
          'last-line' => 297,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTargetUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'targetUri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 298,
              'char' => 50,
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
                  'property' => 'targetUri',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'targetUri',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 300,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 300,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 302,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 302,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 303,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a target uri for the generated HTML
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 299,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 299,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 299,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 298,
          'last-line' => 307,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 308,
              'char' => 40,
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
                  'property' => 'type',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 310,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 310,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 312,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 312,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 313,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the asset\'s type
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 309,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 309,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 309,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 308,
          'last-line' => 317,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPath',
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
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 318,
              'char' => 40,
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
                  'property' => 'path',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Assets/Asset.zep',
                    'line' => 320,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 320,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 322,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 322,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Asset.zep',
              'line' => 323,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the asset\'s path
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
                  'value' => 'AssetInterface',
                  'file' => '/app/phalcon/Assets/Asset.zep',
                  'line' => 319,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Asset.zep',
                'line' => 319,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Asset.zep',
            'line' => 319,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Asset.zep',
          'line' => 318,
          'last-line' => 324,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Assets/Asset.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Assets/Asset.zep',
    'line' => 20,
    'char' => 5,
  ),
);