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
    'file' => '/app/phalcon/Assets/Collection.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets',
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Countable',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 13,
        'char' => 14,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Iterator',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 14,
        'char' => 13,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Phalcon\\Assets\\Asset',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 15,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Phalcon\\Assets\\FilterInterface',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 16,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Phalcon\\Assets\\Inline',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 17,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Phalcon\\Assets\\Asset\\Css',
        'alias' => 'AssetCss',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 18,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Phalcon\\Assets\\Asset\\Js',
        'alias' => 'AssetJs',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 19,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Phalcon\\Assets\\Inline\\Js',
        'alias' => 'InlineJs',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 20,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
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
        'name' => 'Phalcon\\Assets\\Inline\\Css',
        'alias' => 'InlineCss',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 21,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
    'line' => 25,
    'char' => 2,
  ),
  11 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents a collection of assets
 *',
    'file' => '/app/phalcon/Assets/Collection.zep',
    'line' => 26,
    'char' => 5,
  ),
  12 => 
  array (
    'type' => 'class',
    'name' => 'Collection',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'Countable',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 26,
        'char' => 38,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'Iterator',
        'file' => '/app/phalcon/Assets/Collection.zep',
        'line' => 27,
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
          'name' => 'assets',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 31,
            'char' => 27,
          ),
          'docblock' => '**
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 31,
              'char' => 33,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 35,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'attributes',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 36,
            'char' => 31,
          ),
          'docblock' => '**
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 36,
              'char' => 37,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 41,
          'char' => 3,
        ),
        2 => 
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
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 42,
            'char' => 32,
          ),
          'docblock' => '**
	 * Should version be determined from file modification time
	 * @var bool
	 *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 42,
              'char' => 38,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 46,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'codes',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 47,
            'char' => 26,
          ),
          'docblock' => '**
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 47,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 51,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'filters',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 52,
            'char' => 28,
          ),
          'docblock' => '**
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 52,
              'char' => 34,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 56,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'includedAssets',
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 61,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'join',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 62,
            'char' => 27,
          ),
          'docblock' => '**
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 62,
              'char' => 33,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 66,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'local',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 67,
            'char' => 28,
          ),
          'docblock' => '**
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 67,
              'char' => 34,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 71,
          'char' => 6,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'prefix',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 72,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 76,
          'char' => 6,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'position',
          'docblock' => '**
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 77,
              'char' => 30,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 81,
          'char' => 6,
        ),
        10 => 
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
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 82,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 86,
          'char' => 6,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'targetLocal',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 87,
            'char' => 34,
          ),
          'docblock' => '**
     * @var bool
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 87,
              'char' => 40,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 91,
          'char' => 6,
        ),
        12 => 
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
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 92,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 96,
          'char' => 6,
        ),
        13 => 
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
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 97,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 102,
          'char' => 3,
        ),
        14 => 
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
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 103,
              'char' => 25,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 103,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 107,
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
                  'property' => 'includedAssets',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 110,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 110,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 111,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Assets\\Collection constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 108,
          'last-line' => 115,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'add',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'asset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AssetInterface',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 116,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 116,
              'char' => 47,
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
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 118,
                  'char' => 14,
                ),
                'name' => 'addAsset',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'asset',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 118,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 118,
                    'char' => 29,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 118,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 120,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 120,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 121,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a asset to the collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 117,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 117,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 117,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 116,
          'last-line' => 125,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addCss',
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
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 127,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'local',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 128,
                'char' => 25,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 128,
              'char' => 25,
            ),
            2 => 
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 129,
                'char' => 27,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 129,
              'char' => 27,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 130,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 130,
              'char' => 30,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'version',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 131,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 131,
              'char' => 30,
            ),
            5 => 
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 133,
                'char' => 2,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 133,
              'char' => 2,
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
                  'variable' => 'collectionLocal',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 135,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'collectionAttributes',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 135,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 137,
              'char' => 10,
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
                    'value' => 'local',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 137,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 137,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'boolean',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 137,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 137,
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
                      'variable' => 'collectionLocal',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'local',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 138,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 138,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 139,
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
                      'variable' => 'collectionLocal',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 140,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'local',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 140,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 140,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 140,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 141,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 143,
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
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 143,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 143,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 143,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 143,
                'char' => 39,
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
                      'variable' => 'collectionAttributes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 144,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 144,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 145,
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
                      'variable' => 'collectionAttributes',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 146,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 146,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 146,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 146,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 147,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 149,
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
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 149,
                  'char' => 14,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'new',
                      'class' => 'AssetCss',
                      'dynamic' => 0,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'path',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 150,
                            'char' => 30,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 150,
                          'char' => 30,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'collectionLocal',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 150,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 150,
                          'char' => 47,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filter',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 150,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 150,
                          'char' => 55,
                        ),
                        3 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'collectionAttributes',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 150,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 150,
                          'char' => 77,
                        ),
                        4 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'version',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 150,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 150,
                          'char' => 86,
                        ),
                        5 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'autoVersion',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 150,
                            'char' => 99,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 150,
                          'char' => 99,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 151,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 151,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 151,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 153,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 153,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 154,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a CSS asset to the collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 134,
                  'char' => 2,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 134,
                'char' => 2,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 134,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 126,
          'last-line' => 158,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addFilter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'FilterInterface',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 159,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 159,
              'char' => 55,
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'filters',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filter',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 161,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 161,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 163,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 163,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 164,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a filter to the collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 160,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 160,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 160,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 159,
          'last-line' => 168,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addInline',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Inline',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 169,
                'char' => 43,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 169,
              'char' => 44,
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
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 171,
                  'char' => 14,
                ),
                'name' => 'addAsset',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 171,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 171,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 171,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 173,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 173,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 174,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an inline code to the collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 170,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 170,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 170,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 169,
          'last-line' => 178,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addInlineCss',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 179,
              'char' => 48,
            ),
            1 => 
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 179,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 179,
              'char' => 68,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 179,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 179,
              'char' => 87,
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
                  'variable' => 'collectionAttributes',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 181,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 183,
              'char' => 10,
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
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 183,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 183,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 183,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 183,
                'char' => 39,
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
                      'variable' => 'collectionAttributes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 184,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 184,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 185,
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
                      'variable' => 'collectionAttributes',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 186,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 186,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 186,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 186,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 187,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 189,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'codes',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InlineCss',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'content',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 190,
                          'char' => 20,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 190,
                        'char' => 20,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filter',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 191,
                          'char' => 19,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 191,
                        'char' => 19,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collectionAttributes',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 193,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 193,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 193,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 193,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 195,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 195,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 196,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an inline CSS to the collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 180,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 180,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 180,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 179,
          'last-line' => 200,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addInlineJs',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 201,
              'char' => 47,
            ),
            1 => 
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 201,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 201,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 201,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 201,
              'char' => 86,
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
                  'variable' => 'collectionAttributes',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 203,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 205,
              'char' => 10,
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
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 205,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 205,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 205,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 205,
                'char' => 39,
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
                      'variable' => 'collectionAttributes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 206,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 206,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 207,
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
                      'variable' => 'collectionAttributes',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 208,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 208,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 208,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 208,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 209,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
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
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'codes',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'InlineJs',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'content',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 211,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 211,
                        'char' => 49,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filter',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 211,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 211,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collectionAttributes',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 211,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 211,
                        'char' => 79,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 211,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 211,
                  'char' => 80,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 213,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 213,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 214,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an inline javascript to the collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 202,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 202,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 202,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 201,
          'last-line' => 220,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addJs',
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
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 222,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'local',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 223,
                'char' => 25,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 223,
              'char' => 25,
            ),
            2 => 
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 224,
                'char' => 27,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 224,
              'char' => 27,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 225,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 225,
              'char' => 30,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'version',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 226,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 226,
              'char' => 30,
            ),
            5 => 
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 228,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 228,
              'char' => 5,
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
                  'variable' => 'collectionLocal',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 230,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'collectionAttributes',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 230,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 232,
              'char' => 10,
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
                    'value' => 'local',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 232,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 232,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'boolean',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 232,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 232,
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
                      'variable' => 'collectionLocal',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'local',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 233,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 233,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 234,
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
                      'variable' => 'collectionLocal',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 235,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'local',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 235,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 235,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 235,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 236,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 238,
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
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 238,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 238,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 238,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 238,
                'char' => 39,
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
                      'variable' => 'collectionAttributes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 239,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 239,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 240,
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
                      'variable' => 'collectionAttributes',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 241,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 241,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 241,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 241,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 242,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 244,
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
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 244,
                  'char' => 14,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'new',
                      'class' => 'AssetJs',
                      'dynamic' => 0,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'path',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 245,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 245,
                          'char' => 29,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'collectionLocal',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 245,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 245,
                          'char' => 46,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filter',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 245,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 245,
                          'char' => 54,
                        ),
                        3 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'collectionAttributes',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 245,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 245,
                          'char' => 76,
                        ),
                        4 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'version',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 245,
                            'char' => 85,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 245,
                          'char' => 85,
                        ),
                        5 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'autoVersion',
                            'file' => '/app/phalcon/Assets/Collection.zep',
                            'line' => 245,
                            'char' => 98,
                          ),
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 245,
                          'char' => 98,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 246,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 246,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 246,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 248,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 248,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 249,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a javascript asset to the collection
     *
     * @param array attributes
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 229,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 229,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 229,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 221,
          'last-line' => 253,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'count',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 256,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'assets',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 256,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 256,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 256,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 256,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 257,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the number of elements in the form
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 255,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 255,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 254,
          'last-line' => 261,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'current',
          'statements' => 
          array (
            0 => 
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
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 264,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'assets',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 264,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 264,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 264,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'position',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 264,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 264,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 264,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 265,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current asset in the iterator
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
                  'value' => 'Asset',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 263,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 263,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 263,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 262,
          'last-line' => 270,
          'char' => 19,
        ),
        10 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 271,
              'char' => 55,
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
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 273,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'completePath',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 273,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 275,
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
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 275,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'targetPath',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 275,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 275,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 275,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 280,
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
                  'variable' => 'completePath',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'basePath',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 280,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'targetPath',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 280,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 280,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 280,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 286,
              'char' => 10,
            ),
            3 => 
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
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 286,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 286,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 286,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'realPath',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'completePath',
                          'file' => '/app/phalcon/Assets/Collection.zep',
                          'line' => 287,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 287,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 287,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 288,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 290,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'completePath',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 290,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 291,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the complete location where the joined/filtered collection must
     * be written
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 272,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 272,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 271,
          'last-line' => 307,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'asset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AssetInterface',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 308,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 308,
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
                  'variable' => 'key',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 310,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'assets',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 310,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 312,
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
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'asset',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 312,
                      'char' => 25,
                    ),
                    'name' => 'getAssetKey',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 312,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 312,
                  'char' => 39,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'assets',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 313,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'includedAssets',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 313,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 313,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 313,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 315,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'in_array',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 315,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 315,
                    'char' => 28,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'assets',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 315,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 315,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 315,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 316,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks this the asset is added to the collection.
     *
     * ```php
     * use Phalcon\\Assets\\Asset;
     * use Phalcon\\Assets\\Collection;
     *
     * $collection = new Collection();
     *
     * $asset = new Asset("js", "js/jquery.js");
     *
     * $collection->add($asset);
     * $collection->has($asset); // true
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
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 309,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 309,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 308,
          'last-line' => 320,
          'char' => 19,
        ),
        12 => 
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
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 323,
                  'char' => 18,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'autoVersion',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 323,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 323,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 324,
              'char' => 2,
            ),
          ),
          'docblock' => '**
     * Checks if collection is using auto version
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 322,
                'char' => 2,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 322,
            'char' => 2,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 321,
          'last-line' => 329,
          'char' => 16,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'join',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'join',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 330,
              'char' => 35,
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
                  'property' => 'join',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'join',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 332,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 332,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 334,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 334,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 335,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if all filtered assets in the collection must be joined in a single
     * result file
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 331,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 331,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 331,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 330,
          'last-line' => 339,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'key',
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
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 342,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'position',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 342,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 342,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 343,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current position/key in the iterator
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 341,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 341,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 340,
          'last-line' => 347,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'next',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-incr',
                  'variable' => 'this',
                  'property' => 'position',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 350,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 351,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Moves the internal iteration pointer to the next position
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 349,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 348,
          'last-line' => 355,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rewind',
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
                  'property' => 'position',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 358,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 358,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 359,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rewinds the internal iterator
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 357,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 356,
          'last-line' => 363,
          'char' => 19,
        ),
        17 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 364,
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
                  'property' => 'attributes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 366,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 366,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 368,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 368,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 369,
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 365,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 365,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 365,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 364,
          'last-line' => 373,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setFilters',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 374,
              'char' => 46,
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
                  'property' => 'filters',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filters',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 376,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 376,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 378,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 378,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 379,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets an array of filters in the collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 375,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 375,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 375,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 374,
          'last-line' => 383,
          'char' => 19,
        ),
        19 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 384,
              'char' => 41,
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
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 386,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 386,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 388,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 388,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 389,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the collection uses local assets by default
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 385,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 385,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 385,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 384,
          'last-line' => 393,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPrefix',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'prefix',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 394,
              'char' => 45,
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
                  'property' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'prefix',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 396,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 396,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 398,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 398,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 399,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a common prefix for all the assets
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 395,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 395,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 395,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 394,
          'last-line' => 403,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTargetLocal',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'targetLocal',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 404,
              'char' => 53,
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
                  'property' => 'targetLocal',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'targetLocal',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 406,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 406,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 408,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 408,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 409,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the target local
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 405,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 405,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 405,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 404,
          'last-line' => 413,
          'char' => 19,
        ),
        22 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 414,
              'char' => 53,
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
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 416,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 416,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 418,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 418,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 419,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the target path of the file for the filtered/join output
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 415,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 415,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 415,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 414,
          'last-line' => 423,
          'char' => 19,
        ),
        23 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 424,
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
                  'property' => 'targetUri',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'targetUri',
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 426,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 426,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 428,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 428,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 429,
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 425,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 425,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 425,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 424,
          'last-line' => 433,
          'char' => 19,
        ),
        24 => 
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
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 434,
              'char' => 53,
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
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 436,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 436,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 438,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 438,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 439,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a base source path for all the assets in this collection
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 435,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 435,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 435,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 434,
          'last-line' => 443,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'valid',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
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
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 446,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'assets',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 446,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 446,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 446,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'position',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 446,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 446,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 446,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 446,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 447,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if the current element in the iterator is valid
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 445,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 445,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 444,
          'last-line' => 451,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'protected',
          ),
          'type' => 'method',
          'name' => 'addAsset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'asset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AssetInterface',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 452,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 452,
              'char' => 61,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 454,
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
                      'value' => 'asset',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 454,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 454,
                    'char' => 27,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 454,
                'char' => 29,
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
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 455,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 456,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 458,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'instanceof',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'asset',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 458,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'Asset',
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 458,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 458,
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
                      'assign-type' => 'object-property-append',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'assets',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'asset',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 459,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 459,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 460,
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
                      'assign-type' => 'object-property-append',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'codes',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'asset',
                        'file' => '/app/phalcon/Assets/Collection.zep',
                        'line' => 461,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 461,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 462,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 464,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'includedAssets',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'asset',
                      'file' => '/app/phalcon/Assets/Collection.zep',
                      'line' => 464,
                      'char' => 44,
                    ),
                    'name' => 'getAssetKey',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Assets/Collection.zep',
                    'line' => 464,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Assets/Collection.zep',
                  'line' => 464,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 466,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 466,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Collection.zep',
              'line' => 467,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a asset or inline-code to the collection
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
                'file' => '/app/phalcon/Assets/Collection.zep',
                'line' => 453,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Collection.zep',
            'line' => 453,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Collection.zep',
          'line' => 452,
          'last-line' => 468,
          'char' => 28,
        ),
      ),
      'file' => '/app/phalcon/Assets/Collection.zep',
      'line' => 26,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Assets/Collection.zep',
    'line' => 26,
    'char' => 5,
  ),
);