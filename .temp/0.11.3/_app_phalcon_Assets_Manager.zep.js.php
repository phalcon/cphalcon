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
    'file' => '/app/phalcon/Assets/Manager.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets',
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'name' => 'Phalcon\\Tag',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 13,
        'char' => 16,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'name' => 'Phalcon\\Assets\\Asset',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 14,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'name' => 'Phalcon\\Assets\\Collection',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 15,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'name' => 'Phalcon\\Assets\\Exception',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 16,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'name' => 'Phalcon\\Assets\\Asset\\Js',
        'alias' => 'AssetJs',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 17,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 18,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'name' => 'Phalcon\\Assets\\Inline\\Css',
        'alias' => 'InlineCss',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 19,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 20,
        'char' => 41,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 21,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
    'line' => 22,
    'char' => 3,
  ),
  11 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 22,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
    'line' => 28,
    'char' => 2,
  ),
  12 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Assets\\Manager
 *
 * Manages collections of CSS/Javascript assets
 *',
    'file' => '/app/phalcon/Assets/Manager.zep',
    'line' => 29,
    'char' => 5,
  ),
  13 => 
  array (
    'type' => 'class',
    'name' => 'Manager',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Assets/Manager.zep',
        'line' => 30,
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
          'name' => 'collections',
          'file' => '/app/phalcon/Assets/Manager.zep',
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
          'name' => 'container',
          'docblock' => '**
     * @var DiInterface
     *',
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 41,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'options',
          'docblock' => '**
     * Options configure
     * @var array
     *',
          'file' => '/app/phalcon/Assets/Manager.zep',
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
          'name' => 'implicitOutput',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 47,
            'char' => 36,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 51,
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
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 52,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 52,
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
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 54,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 54,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Assets\\Manager constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 53,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 52,
          'last-line' => 65,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
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
                'value' => 'Asset',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 66,
                'char' => 42,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 66,
              'char' => 43,
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 71,
                  'char' => 14,
                ),
                'name' => 'addAssetByType',
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
                        'value' => 'asset',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 72,
                        'char' => 19,
                      ),
                      'name' => 'getType',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 72,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 72,
                    'char' => 29,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'asset',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 74,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 74,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 74,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 76,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 76,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 77,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a raw asset to the manager
     *
     *```php
     * $assets->addAsset(
     *     new Phalcon\\Assets\\Asset("css", "css/style.css")
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 67,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 66,
          'last-line' => 88,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addAssetByType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 89,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'asset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Asset',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 89,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 89,
              'char' => 63,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 91,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 93,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collection',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 93,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 93,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collections',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 93,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 93,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 93,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 93,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 93,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 93,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Collection',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 94,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 94,
                      'char' => 59,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'object-property-array-index',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'collections',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 95,
                          'char' => 39,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collection',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 95,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 95,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 96,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 101,
              'char' => 18,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 101,
                  'char' => 20,
                ),
                'name' => 'add',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'asset',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 101,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 101,
                    'char' => 30,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 101,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 103,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 103,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 104,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a asset by its type
     *
     *```php
     * $assets->addAssetByType(
     *     "css",
     *     new \\Phalcon\\Assets\\Asset\\Css("css/style.css")
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
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 90,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 90,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 89,
          'last-line' => 113,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 115,
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
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 116,
                'char' => 25,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 116,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 117,
                'char' => 27,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 117,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 118,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 118,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 119,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 119,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 121,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 121,
              'char' => 5,
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 123,
                  'char' => 14,
                ),
                'name' => 'addAssetByType',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'css',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 124,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 124,
                    'char' => 16,
                  ),
                  1 => 
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
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 125,
                            'char' => 30,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 125,
                          'char' => 30,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'local',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 125,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 125,
                          'char' => 37,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filter',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 125,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 125,
                          'char' => 45,
                        ),
                        3 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attributes',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 125,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 125,
                          'char' => 57,
                        ),
                        4 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'version',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 125,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 125,
                          'char' => 66,
                        ),
                        5 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'autoVersion',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 125,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 125,
                          'char' => 79,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 126,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 126,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 126,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 128,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 128,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Adds a Css asset to the \'css\' collection
    *
    *```php
    * $assets->addCss("css/bootstrap.css");
    * $assets->addCss("http://bootstrap.my-cdn.com/style.css", false);
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 122,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 122,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 122,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 114,
          'last-line' => 133,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addInlineCode',
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 134,
                'char' => 47,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 134,
              'char' => 48,
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 139,
                  'char' => 14,
                ),
                'name' => 'addInlineCodeByType',
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
                        'value' => 'code',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 139,
                        'char' => 40,
                      ),
                      'name' => 'getType',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 139,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 139,
                    'char' => 50,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 139,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 139,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 139,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 141,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 141,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 142,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a raw inline code to the manager
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 135,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 135,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 135,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 134,
          'last-line' => 146,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addInlineCodeByType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 147,
              'char' => 53,
            ),
            1 => 
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 147,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 147,
              'char' => 68,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 149,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 151,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collection',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 151,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 151,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collections',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 151,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 151,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 151,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 151,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 151,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 151,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Collection',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 152,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 152,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 153,
                  'char' => 15,
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
                      'property' => 'collections',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 153,
                          'char' => 39,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collection',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 153,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 153,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 154,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 159,
              'char' => 18,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 159,
                  'char' => 20,
                ),
                'name' => 'addInline',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'code',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 159,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 159,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 159,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 161,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 161,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 162,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an inline code by its type
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 148,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 148,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 148,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 147,
          'last-line' => 166,
          'char' => 19,
        ),
        6 => 
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
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 167,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 167,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 167,
              'char' => 63,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 167,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 167,
              'char' => 86,
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 169,
                  'char' => 14,
                ),
                'name' => 'addInlineCodeByType',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'css',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 170,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 170,
                    'char' => 16,
                  ),
                  1 => 
                  array (
                    'parameter' => 
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
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 171,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 171,
                          'char' => 34,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filter',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 171,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 171,
                          'char' => 42,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attributes',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 171,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 171,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 172,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 172,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 172,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 174,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 174,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an inline Css to the \'css\' collection
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 168,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 168,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 168,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 167,
          'last-line' => 179,
          'char' => 19,
        ),
        7 => 
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
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 180,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'filter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 180,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 180,
              'char' => 62,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 180,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 180,
              'char' => 81,
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 182,
                  'char' => 14,
                ),
                'name' => 'addInlineCodeByType',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'js',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 183,
                      'char' => 15,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 183,
                    'char' => 15,
                  ),
                  1 => 
                  array (
                    'parameter' => 
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
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 184,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 184,
                          'char' => 33,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filter',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 184,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 184,
                          'char' => 41,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attributes',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 184,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 184,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 185,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 185,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 185,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 187,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 187,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 188,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds an inline javascript to the \'js\' collection
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 181,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 181,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 181,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 180,
          'last-line' => 197,
          'char' => 19,
        ),
        8 => 
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
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 199,
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
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 200,
                'char' => 25,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 200,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 201,
                'char' => 27,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 201,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 202,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 202,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 203,
                'char' => 30,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 203,
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 205,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 205,
              'char' => 5,
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 207,
                  'char' => 14,
                ),
                'name' => 'addAssetByType',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'js',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 208,
                      'char' => 15,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 208,
                    'char' => 15,
                  ),
                  1 => 
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
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 209,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 209,
                          'char' => 29,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'local',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 209,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 209,
                          'char' => 36,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filter',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 209,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 209,
                          'char' => 44,
                        ),
                        3 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'attributes',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 209,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 209,
                          'char' => 56,
                        ),
                        4 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'version',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 209,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 209,
                          'char' => 65,
                        ),
                        5 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'autoVersion',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 209,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 209,
                          'char' => 78,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 210,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 210,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 210,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 212,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 212,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 213,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a javascript asset to the \'js\' collection
     *
     *```php
     * $assets->addJs("scripts/jquery.js");
     * $assets->addJs("http://jquery.my-cdn.com/jquery.js", false);
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 206,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 206,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 206,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 198,
          'last-line' => 217,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'collection',
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
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 218,
              'char' => 43,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 220,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 222,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collection',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 222,
                    'char' => 55,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 222,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collections',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 222,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 222,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 222,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 222,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 222,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 222,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Collection',
                        'dynamic' => 0,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 223,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 223,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 224,
                  'char' => 15,
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
                      'property' => 'collections',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 224,
                          'char' => 39,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collection',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 224,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 224,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 225,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 227,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 227,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 228,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Creates/Returns a collection of assets
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 219,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 219,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 219,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 218,
          'last-line' => 232,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'collectionAssetsByType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'assets',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 233,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 233,
              'char' => 69,
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
                  'variable' => 'asset',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 235,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 236,
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
                  'variable' => 'filtered',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 236,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 236,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 238,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'assets',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 238,
                'char' => 29,
              ),
              'value' => 'asset',
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
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'asset',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 239,
                        'char' => 22,
                      ),
                      'name' => 'getType',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 239,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'type',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 239,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 239,
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
                          'variable' => 'filtered',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'asset',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 240,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 240,
                          'char' => 39,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 241,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 242,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 244,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'filtered',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 244,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 245,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Creates/Returns a collection of assets by type
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 234,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 234,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 233,
          'last-line' => 256,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'exists',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 257,
              'char' => 38,
            ),
          ),
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
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 259,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collections',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 259,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 259,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'id',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 259,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 259,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 259,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 260,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns true or false if collection exists.
     *
     * ```php
     * if ($assets->exists("jsHeader")) {
     *     // \\Phalcon\\Assets\\Collection
     *     $collection = $assets->get("jsHeader");
     * }
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 258,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 258,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 257,
          'last-line' => 268,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 269,
              'char' => 35,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 271,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 273,
              'char' => 10,
            ),
            1 => 
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
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 273,
                      'char' => 62,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 273,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collections',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 273,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 273,
                        'char' => 57,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'id',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 273,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 273,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 273,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 273,
                  'char' => 62,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 273,
                'char' => 62,
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
                          'value' => 'The collection does not exist in the manager',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 274,
                          'char' => 77,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 274,
                        'char' => 77,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 274,
                    'char' => 78,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 275,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 277,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 277,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 278,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a collection by its id.
     *
     * ```php
     * $scripts = $assets->get("js");
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
                  'value' => 'Collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 270,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 270,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 270,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 269,
          'last-line' => 282,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCollections',
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 285,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'collections',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 285,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 285,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 286,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns existing collections in the manager
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 284,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 284,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 284,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 283,
          'last-line' => 290,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCss',
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 293,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 299,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collection',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 299,
                    'char' => 54,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 299,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collections',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 299,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 299,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'css',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 299,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 299,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 299,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 299,
                'char' => 54,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 300,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 301,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 303,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 303,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 304,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the CSS collection of assets
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 292,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 292,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 292,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 291,
          'last-line' => 308,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDI',
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 311,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 311,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 311,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 312,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal dependency injector
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
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 310,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 310,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 310,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 309,
          'last-line' => 316,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getJs',
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 319,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 325,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collection',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 325,
                    'char' => 53,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 325,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'collections',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 325,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 325,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'js',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 325,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 325,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 325,
                  'char' => 53,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 325,
                'char' => 53,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Collection',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 326,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 327,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 329,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'collection',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 329,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 330,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the CSS collection of assets
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 318,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 318,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 318,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 317,
          'last-line' => 334,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOptions',
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
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 337,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'options',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 337,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 337,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 338,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the manager options
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 336,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 336,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 335,
          'last-line' => 345,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'output',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 346,
                'char' => 50,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 346,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'callback',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 346,
              'char' => 61,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 346,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 348,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 349,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'asset',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 349,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'assets',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 349,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'attributes',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 349,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'autoVersion',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 349,
                  'char' => 51,
                ),
                4 => 
                array (
                  'variable' => 'collectionSourcePath',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 349,
                  'char' => 73,
                ),
                5 => 
                array (
                  'variable' => 'collectionTargetPath',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 350,
                  'char' => 33,
                ),
                6 => 
                array (
                  'variable' => 'completeSourcePath',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 350,
                  'char' => 53,
                ),
                7 => 
                array (
                  'variable' => 'completeTargetPath',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 350,
                  'char' => 73,
                ),
                8 => 
                array (
                  'variable' => 'content',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 351,
                  'char' => 20,
                ),
                9 => 
                array (
                  'variable' => 'filter',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 351,
                  'char' => 28,
                ),
                10 => 
                array (
                  'variable' => 'filters',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 351,
                  'char' => 37,
                ),
                11 => 
                array (
                  'variable' => 'filteredContent',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 351,
                  'char' => 54,
                ),
                12 => 
                array (
                  'variable' => 'filteredJoinedContent',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 351,
                  'char' => 77,
                ),
                13 => 
                array (
                  'variable' => 'filterNeeded',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 352,
                  'char' => 25,
                ),
                14 => 
                array (
                  'variable' => 'html',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 352,
                  'char' => 31,
                ),
                15 => 
                array (
                  'variable' => 'join',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 352,
                  'char' => 37,
                ),
                16 => 
                array (
                  'variable' => 'local',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 352,
                  'char' => 44,
                ),
                17 => 
                array (
                  'variable' => 'modificationTime',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 352,
                  'char' => 62,
                ),
                18 => 
                array (
                  'variable' => 'mustFilter',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 352,
                  'char' => 74,
                ),
                19 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 353,
                  'char' => 20,
                ),
                20 => 
                array (
                  'variable' => 'parameters',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 353,
                  'char' => 32,
                ),
                21 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 353,
                  'char' => 38,
                ),
                22 => 
                array (
                  'variable' => 'prefixedPath',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 353,
                  'char' => 52,
                ),
                23 => 
                array (
                  'variable' => 'sourceBasePath',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 353,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 353,
                  'char' => 75,
                ),
                24 => 
                array (
                  'variable' => 'sourcePath',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 354,
                  'char' => 23,
                ),
                25 => 
                array (
                  'variable' => 'targetBasePath',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 354,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 354,
                  'char' => 47,
                ),
                26 => 
                array (
                  'variable' => 'targetPath',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 354,
                  'char' => 59,
                ),
                27 => 
                array (
                  'variable' => 'targetUri',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 354,
                  'char' => 70,
                ),
                28 => 
                array (
                  'variable' => 'typeCss',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 354,
                  'char' => 79,
                ),
                29 => 
                array (
                  'variable' => 'useImplicitOutput',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 355,
                  'char' => 30,
                ),
                30 => 
                array (
                  'variable' => 'version',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 355,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 357,
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
                  'variable' => 'useImplicitOutput',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 357,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'implicitOutput',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 357,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 357,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 357,
                  'char' => 53,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 358,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 358,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 363,
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
                  'variable' => 'assets',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 363,
                      'char' => 27,
                    ),
                    'name' => 'collectionAssetsByType',
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
                            'value' => 'collection',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 364,
                            'char' => 24,
                          ),
                          'name' => 'getAssets',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 364,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 364,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'type',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 366,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 366,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 366,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 366,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 371,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'filters',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 371,
                      'char' => 34,
                    ),
                    'name' => 'getFilters',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 371,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 371,
                  'char' => 47,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'typeCss',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => 'css',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 372,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 372,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 377,
              'char' => 10,
            ),
            5 => 
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
                      'value' => 'filters',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 377,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 377,
                    'char' => 25,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 377,
                'char' => 27,
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
                      'variable' => 'options',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 378,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'options',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 378,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 378,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 378,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 383,
                  'char' => 14,
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
                        'value' => 'options',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 383,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 383,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 383,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 383,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'fetch',
                      'expr' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sourceBasePath',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 388,
                          'char' => 62,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'options',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 388,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'sourceBasePath',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 388,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 388,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 388,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 394,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'fetch',
                      'expr' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'targetBasePath',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 394,
                          'char' => 62,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'options',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 394,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'targetBasePath',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 394,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 394,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 394,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 395,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 400,
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
                      'variable' => 'collectionSourcePath',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 400,
                          'char' => 51,
                        ),
                        'name' => 'getSourcePath',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 400,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 400,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 405,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collectionSourcePath',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 405,
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
                          'variable' => 'completeSourcePath',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'sourceBasePath',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 406,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collectionSourcePath',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 406,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 406,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 406,
                          'char' => 79,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 407,
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
                          'variable' => 'completeSourcePath',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'sourceBasePath',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 408,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 408,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 409,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 414,
                  'char' => 15,
                ),
                4 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'collectionTargetPath',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 414,
                          'char' => 51,
                        ),
                        'name' => 'getTargetPath',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 414,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 414,
                      'char' => 67,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 419,
                  'char' => 14,
                ),
                5 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collectionTargetPath',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 419,
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
                          'variable' => 'completeTargetPath',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'targetBasePath',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 420,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collectionTargetPath',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 420,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 420,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 420,
                          'char' => 79,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 421,
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
                          'variable' => 'completeTargetPath',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'targetBasePath',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 422,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 422,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 423,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 428,
                  'char' => 15,
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
                      'variable' => 'filteredJoinedContent',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 428,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 428,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 433,
                  'char' => 15,
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
                      'variable' => 'join',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'collection',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 433,
                          'char' => 35,
                        ),
                        'name' => 'getJoin',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 433,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 433,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 438,
                  'char' => 14,
                ),
                8 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'join',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 438,
                    'char' => 21,
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
                            'type' => 'variable',
                            'value' => 'completeTargetPath',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 442,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 442,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 442,
                        'char' => 49,
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
                                      'value' => 'Path \'',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 444,
                                      'char' => 32,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'completeTargetPath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 444,
                                      'char' => 53,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 444,
                                    'char' => 53,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\' is not a valid target path (1)',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 445,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 445,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 445,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 445,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 446,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 448,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'unlikely',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'is_dir',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'completeTargetPath',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 448,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 448,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 448,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 448,
                        'char' => 56,
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
                                      'value' => 'Path \'',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 450,
                                      'char' => 32,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'completeTargetPath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 450,
                                      'char' => 53,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 450,
                                    'char' => 53,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\' is not a valid target path (2), is dir.',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 451,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 451,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 451,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 451,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 452,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 453,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 454,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 459,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'assets',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 459,
                'char' => 29,
              ),
              'value' => 'asset',
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
                      'variable' => 'filterNeeded',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'false',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 460,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 460,
                      'char' => 37,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'type',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'asset',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 461,
                          'char' => 38,
                        ),
                        'name' => 'getType',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 461,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 461,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 466,
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
                      'variable' => 'local',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'asset',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 466,
                          'char' => 31,
                        ),
                        'name' => 'getLocal',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 466,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 466,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 472,
                  'char' => 14,
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
                          'value' => 'filters',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 472,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 472,
                        'char' => 29,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 472,
                    'char' => 31,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'local',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 473,
                        'char' => 26,
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
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'asset',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 477,
                                  'char' => 44,
                                ),
                                'name' => 'getRealSourcePath',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'completeSourcePath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 479,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 479,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 479,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 479,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 484,
                          'char' => 22,
                        ),
                        1 => 
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
                                'type' => 'variable',
                                'value' => 'sourcePath',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 484,
                                'char' => 45,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 484,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 484,
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
                                  'variable' => 'sourcePath',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'asset',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 485,
                                      'char' => 48,
                                    ),
                                    'name' => 'getPath',
                                    'call-type' => 1,
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 485,
                                    'char' => 58,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 485,
                                  'char' => 58,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 487,
                              'char' => 29,
                            ),
                            1 => 
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
                                          'value' => 'Asset \'',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 488,
                                          'char' => 37,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'sourcePath',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 488,
                                          'char' => 50,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 488,
                                        'char' => 50,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\' does not have a valid source path',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 489,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 489,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 489,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 489,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 490,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 491,
                          'char' => 17,
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
                              'variable' => 'sourcePath',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'asset',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 495,
                                  'char' => 44,
                                ),
                                'name' => 'getPath',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 495,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 495,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 500,
                          'char' => 23,
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
                              'variable' => 'filterNeeded',
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 500,
                                'char' => 44,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 500,
                              'char' => 44,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 501,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 507,
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
                          'variable' => 'targetPath',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 507,
                              'char' => 40,
                            ),
                            'name' => 'getRealTargetPath',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'completeTargetPath',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 507,
                                  'char' => 77,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 507,
                                'char' => 77,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 507,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 507,
                          'char' => 78,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 512,
                      'char' => 18,
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
                            'type' => 'variable',
                            'value' => 'targetPath',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 512,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 512,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 512,
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
                                      'value' => 'Asset \'',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 514,
                                      'char' => 33,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'sourcePath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 514,
                                      'char' => 46,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 514,
                                    'char' => 46,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\' does not have a valid target path',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 515,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 515,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 515,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 515,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 516,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 518,
                      'char' => 18,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'local',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 518,
                        'char' => 26,
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
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'targetPath',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 522,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'sourcePath',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 522,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 522,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 522,
                            'char' => 58,
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
                                          'value' => 'Asset \'',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 524,
                                          'char' => 37,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'targetPath',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 524,
                                          'char' => 50,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 524,
                                        'char' => 50,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\' have the same source and target paths',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 525,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 525,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 525,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 525,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 526,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 528,
                          'char' => 22,
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
                                  'value' => 'targetPath',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 528,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 528,
                                'char' => 46,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 528,
                            'char' => 48,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'compare_mtime',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'targetPath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 529,
                                      'char' => 52,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 529,
                                    'char' => 52,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'sourcePath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 529,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 529,
                                    'char' => 64,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 529,
                                'char' => 66,
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
                                      'variable' => 'filterNeeded',
                                      'expr' => 
                                      array (
                                        'type' => 'bool',
                                        'value' => 'true',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 530,
                                        'char' => 52,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 530,
                                      'char' => 52,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 531,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 532,
                              'char' => 21,
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
                                  'variable' => 'filterNeeded',
                                  'expr' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 533,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 533,
                                  'char' => 48,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 534,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 535,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 536,
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
                          'variable' => 'path',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 540,
                              'char' => 42,
                            ),
                            'name' => 'getRealTargetUri',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 540,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 540,
                          'char' => 61,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'prefixedPath',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 541,
                              'char' => 41,
                            ),
                            'name' => 'getPrefixedPath',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'collection',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 541,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 541,
                                'char' => 68,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'path',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 541,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 541,
                                'char' => 74,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 541,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 541,
                          'char' => 75,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 543,
                      'char' => 18,
                    ),
                    1 => 
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
                            'type' => 'null',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 543,
                            'char' => 27,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 543,
                              'char' => 35,
                            ),
                            'name' => 'getVersion',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 543,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 543,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'asset',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 543,
                            'char' => 58,
                          ),
                          'name' => 'isAutoVersion',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 543,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 543,
                        'char' => 75,
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
                              'variable' => 'version',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'collection',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 544,
                                  'char' => 35,
                                ),
                                'name' => 'getVersion',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 544,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 544,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'autoVersion',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'collection',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 545,
                                  'char' => 35,
                                ),
                                'name' => 'isAutoVersion',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 545,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 545,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 547,
                          'char' => 10,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'and',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'autoVersion',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 547,
                              'char' => 25,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'local',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 547,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 547,
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
                                            'value' => 'asset',
                                            'file' => '/app/phalcon/Assets/Manager.zep',
                                            'line' => 548,
                                            'char' => 52,
                                          ),
                                          'name' => 'getRealSourcePath',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 548,
                                          'char' => 72,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 548,
                                        'char' => 72,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 548,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 548,
                                  'char' => 73,
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
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 549,
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
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 549,
                                          'char' => 54,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '.',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 549,
                                          'char' => 58,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 549,
                                        'char' => 58,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'modificationTime',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 549,
                                        'char' => 77,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 549,
                                      'char' => 77,
                                    ),
                                    'extra' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'modificationTime',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 549,
                                      'char' => 95,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 549,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 549,
                                  'char' => 95,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 550,
                              'char' => 9,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 552,
                          'char' => 7,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'version',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 552,
                            'char' => 17,
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
                                  'variable' => 'prefixedPath',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'prefixedPath',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 553,
                                        'char' => 39,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '?ver=',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 553,
                                        'char' => 47,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 553,
                                      'char' => 47,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'version',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 553,
                                      'char' => 56,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 553,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 553,
                                  'char' => 56,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 554,
                              'char' => 6,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 555,
                          'char' => 5,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 560,
                      'char' => 19,
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
                          'variable' => 'attributes',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 560,
                              'char' => 40,
                            ),
                            'name' => 'getAttributes',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 560,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 560,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 565,
                      'char' => 18,
                    ),
                    3 => 
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
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 565,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 565,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 565,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 565,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'attributes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 566,
                                  'char' => 37,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'prefixedPath',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 566,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 566,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 567,
                          'char' => 23,
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
                              'variable' => 'parameters',
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
                                      'value' => 'attributes',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 567,
                                      'char' => 49,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 567,
                                    'char' => 49,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 567,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 567,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 568,
                          'char' => 17,
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
                              'variable' => 'parameters',
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
                                      'value' => 'prefixedPath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 569,
                                      'char' => 51,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 569,
                                    'char' => 51,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 569,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 569,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 570,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 571,
                      'char' => 19,
                    ),
                    4 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'parameters',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'local',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 571,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 571,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 576,
                      'char' => 19,
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
                          'variable' => 'html',
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
                                  'type' => 'variable',
                                  'value' => 'callback',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 576,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 576,
                                'char' => 57,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parameters',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 576,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 576,
                                'char' => 69,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 576,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 576,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 581,
                      'char' => 18,
                    ),
                    6 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'useImplicitOutput',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 581,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 581,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 581,
                        'char' => 46,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'echo',
                          'expressions' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'html',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 582,
                              'char' => 30,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 583,
                          'char' => 17,
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
                              'operator' => 'concat-assign',
                              'variable' => 'output',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'html',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 584,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 584,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 585,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 587,
                      'char' => 24,
                    ),
                    7 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 588,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 590,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filterNeeded',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 590,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 590,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 590,
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
                          'variable' => 'content',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 594,
                              'char' => 37,
                            ),
                            'name' => 'getContent',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'completeSourcePath',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 594,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 594,
                                'char' => 67,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 594,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 594,
                          'char' => 68,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 599,
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
                          'variable' => 'mustFilter',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 599,
                              'char' => 40,
                            ),
                            'name' => 'getFilter',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 599,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 599,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 604,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mustFilter',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 604,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 604,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 604,
                        'char' => 39,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filters',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 605,
                            'char' => 43,
                          ),
                          'value' => 'filter',
                          'reverse' => 0,
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
                                  'type' => 'not-equals',
                                  'left' => 
                                  array (
                                    'type' => 'typeof',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'filter',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 609,
                                      'char' => 52,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 609,
                                    'char' => 52,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'object',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 609,
                                    'char' => 61,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 609,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 609,
                                'char' => 61,
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
                                          'value' => 'Filter is invalid',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 610,
                                          'char' => 66,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 610,
                                        'char' => 66,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 610,
                                    'char' => 67,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 611,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 617,
                              'char' => 27,
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
                                  'variable' => 'filteredContent',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'filter',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 617,
                                      'char' => 54,
                                    ),
                                    'name' => 'filter',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'content',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 617,
                                          'char' => 69,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 617,
                                        'char' => 69,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 617,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 617,
                                  'char' => 70,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'content',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'filteredContent',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 618,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 618,
                                  'char' => 62,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 619,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 624,
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
                              'type' => 'variable',
                              'value' => 'join',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 624,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'bool',
                              'value' => 'true',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 624,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 624,
                            'char' => 37,
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
                                  'type' => 'variable',
                                  'value' => 'type',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 625,
                                  'char' => 34,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'typeCss',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 625,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 625,
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
                                      'operator' => 'concat-assign',
                                      'variable' => 'filteredJoinedContent',
                                      'expr' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'filteredContent',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 626,
                                        'char' => 72,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 626,
                                      'char' => 72,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 627,
                                  'char' => 25,
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
                                      'operator' => 'concat-assign',
                                      'variable' => 'filteredJoinedContent',
                                      'expr' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'filteredContent',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 628,
                                          'char' => 73,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => ';',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 628,
                                          'char' => 76,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 628,
                                        'char' => 76,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 628,
                                      'char' => 76,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 629,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 630,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 631,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'join',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 635,
                              'char' => 30,
                            ),
                            'right' => 
                            array (
                              'type' => 'bool',
                              'value' => 'true',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 635,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 635,
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
                                  'operator' => 'concat-assign',
                                  'variable' => 'filteredJoinedContent',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'content',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 636,
                                    'char' => 60,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 636,
                                  'char' => 60,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 637,
                              'char' => 21,
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
                                  'variable' => 'filteredContent',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'content',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 638,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 638,
                                  'char' => 54,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 639,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 640,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 642,
                      'char' => 18,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'join',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 642,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 642,
                        'char' => 26,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'fcall',
                          'expr' => 
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
                                  'value' => 'targetPath',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 647,
                                  'char' => 49,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 647,
                                'char' => 49,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filteredContent',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 647,
                                  'char' => 66,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 647,
                                'char' => 66,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 647,
                            'char' => 67,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 648,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 649,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 651,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'join',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 651,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 651,
                    'char' => 22,
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
                          'variable' => 'path',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 655,
                              'char' => 42,
                            ),
                            'name' => 'getRealTargetUri',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 655,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 655,
                          'char' => 61,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'prefixedPath',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 656,
                              'char' => 41,
                            ),
                            'name' => 'getPrefixedPath',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'collection',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 656,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 656,
                                'char' => 68,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'path',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 656,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 656,
                                'char' => 74,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 656,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 656,
                          'char' => 75,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 658,
                      'char' => 18,
                    ),
                    1 => 
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
                            'type' => 'null',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 658,
                            'char' => 27,
                          ),
                          'right' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 658,
                              'char' => 35,
                            ),
                            'name' => 'getVersion',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 658,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 658,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'asset',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 658,
                            'char' => 58,
                          ),
                          'name' => 'isAutoVersion',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 658,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 658,
                        'char' => 75,
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
                              'variable' => 'version',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'collection',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 659,
                                  'char' => 35,
                                ),
                                'name' => 'getVersion',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 659,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 659,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'autoVersion',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'collection',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 660,
                                  'char' => 35,
                                ),
                                'name' => 'isAutoVersion',
                                'call-type' => 1,
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 660,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 660,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 662,
                          'char' => 10,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'and',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'autoVersion',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 662,
                              'char' => 25,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'local',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 662,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 662,
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
                                            'value' => 'asset',
                                            'file' => '/app/phalcon/Assets/Manager.zep',
                                            'line' => 663,
                                            'char' => 52,
                                          ),
                                          'name' => 'getRealSourcePath',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 663,
                                          'char' => 72,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 663,
                                        'char' => 72,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 663,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 663,
                                  'char' => 73,
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
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 664,
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
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 664,
                                          'char' => 54,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '.',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 664,
                                          'char' => 58,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 664,
                                        'char' => 58,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'modificationTime',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 664,
                                        'char' => 77,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 664,
                                      'char' => 77,
                                    ),
                                    'extra' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'modificationTime',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 664,
                                      'char' => 95,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 664,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 664,
                                  'char' => 95,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 665,
                              'char' => 9,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 667,
                          'char' => 7,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'version',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 667,
                            'char' => 17,
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
                                  'variable' => 'prefixedPath',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'prefixedPath',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 668,
                                        'char' => 39,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '?ver=',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 668,
                                        'char' => 47,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 668,
                                      'char' => 47,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'version',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 668,
                                      'char' => 56,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 668,
                                    'char' => 56,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 668,
                                  'char' => 56,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 669,
                              'char' => 6,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 670,
                          'char' => 5,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 675,
                      'char' => 19,
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
                          'variable' => 'attributes',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'asset',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 675,
                              'char' => 40,
                            ),
                            'name' => 'getAttributes',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 675,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 675,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 680,
                      'char' => 19,
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
                          'variable' => 'local',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 680,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 680,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 685,
                      'char' => 18,
                    ),
                    4 => 
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
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 685,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 685,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 685,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 685,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'attributes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 686,
                                  'char' => 37,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'prefixedPath',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 686,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 686,
                              'char' => 53,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 687,
                          'char' => 23,
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
                              'variable' => 'parameters',
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
                                      'value' => 'attributes',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 687,
                                      'char' => 49,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 687,
                                    'char' => 49,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 687,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 687,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 688,
                          'char' => 17,
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
                              'variable' => 'parameters',
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
                                      'value' => 'prefixedPath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 689,
                                      'char' => 51,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 689,
                                    'char' => 51,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 689,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 689,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 690,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 691,
                      'char' => 19,
                    ),
                    5 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'parameters',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'local',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 691,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 691,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 696,
                      'char' => 19,
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
                          'variable' => 'html',
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
                                  'type' => 'variable',
                                  'value' => 'callback',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 696,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 696,
                                'char' => 57,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parameters',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 696,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 696,
                                'char' => 69,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 696,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 696,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 701,
                      'char' => 18,
                    ),
                    7 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'useImplicitOutput',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 701,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 701,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 701,
                        'char' => 46,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'echo',
                          'expressions' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'html',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 702,
                              'char' => 30,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 703,
                          'char' => 17,
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
                              'operator' => 'concat-assign',
                              'variable' => 'output',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'html',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 704,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 704,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 705,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 706,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 707,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 709,
              'char' => 10,
            ),
            7 => 
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
                      'value' => 'filters',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 709,
                      'char' => 25,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 709,
                    'char' => 25,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 709,
                'char' => 27,
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
                      'type' => 'variable',
                      'value' => 'join',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 710,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 710,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 710,
                    'char' => 29,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'fcall',
                      'expr' => 
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
                              'value' => 'completeTargetPath',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 715,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 715,
                            'char' => 53,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filteredJoinedContent',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 715,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 715,
                            'char' => 76,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 715,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 720,
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
                          'variable' => 'targetUri',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 720,
                              'char' => 47,
                            ),
                            'name' => 'getTargetUri',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 720,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 720,
                          'char' => 62,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'prefixedPath',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 721,
                              'char' => 41,
                            ),
                            'name' => 'getPrefixedPath',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'collection',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 721,
                                  'char' => 68,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 721,
                                'char' => 68,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'targetUri',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 721,
                                  'char' => 79,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 721,
                                'char' => 79,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 721,
                            'char' => 80,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 721,
                          'char' => 80,
                        ),
                        2 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'version',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 722,
                              'char' => 47,
                            ),
                            'name' => 'getVersion',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 722,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 722,
                          'char' => 60,
                        ),
                        3 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'autoVersion',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 723,
                              'char' => 47,
                            ),
                            'name' => 'isAutoVersion',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 723,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 723,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 725,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'autoVersion',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 725,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'local',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 725,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 725,
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
                                      'type' => 'variable',
                                      'value' => 'completeTargetPath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 726,
                                      'char' => 72,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 726,
                                    'char' => 72,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 726,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 726,
                              'char' => 73,
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
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 727,
                                  'char' => 52,
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
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 727,
                                      'char' => 62,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '.',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 727,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 727,
                                    'char' => 66,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'modificationTime',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 727,
                                    'char' => 85,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 727,
                                  'char' => 85,
                                ),
                                'extra' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'modificationTime',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 727,
                                  'char' => 103,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 727,
                                'char' => 103,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 727,
                              'char' => 103,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 728,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 730,
                      'char' => 18,
                    ),
                    3 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'version',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 730,
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
                              'variable' => 'prefixedPath',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'prefixedPath',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 731,
                                    'char' => 53,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '?ver=',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 731,
                                    'char' => 61,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 731,
                                  'char' => 61,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'version',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 731,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 731,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 731,
                              'char' => 70,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 732,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 737,
                      'char' => 19,
                    ),
                    4 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'attributes',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 737,
                              'char' => 45,
                            ),
                            'name' => 'getAttributes',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 737,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 737,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 742,
                      'char' => 19,
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
                          'variable' => 'local',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'collection',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 742,
                              'char' => 40,
                            ),
                            'name' => 'getTargetLocal',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 742,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 742,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 747,
                      'char' => 18,
                    ),
                    6 => 
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
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 747,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 747,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 747,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 747,
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
                              'assign-type' => 'array-index',
                              'operator' => 'assign',
                              'variable' => 'attributes',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 748,
                                  'char' => 37,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'prefixedPath',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 748,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 748,
                              'char' => 53,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'parameters',
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
                                      'value' => 'attributes',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 749,
                                      'char' => 49,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 749,
                                    'char' => 49,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 749,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 749,
                              'char' => 50,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 750,
                          'char' => 17,
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
                              'variable' => 'parameters',
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
                                      'value' => 'prefixedPath',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 751,
                                      'char' => 51,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 751,
                                    'char' => 51,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 751,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 751,
                              'char' => 52,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 752,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 753,
                      'char' => 19,
                    ),
                    7 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'parameters',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'local',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 753,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 753,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 758,
                      'char' => 19,
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
                          'variable' => 'html',
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
                                  'type' => 'variable',
                                  'value' => 'callback',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 758,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 758,
                                'char' => 57,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'parameters',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 758,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 758,
                                'char' => 69,
                              ),
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 758,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 758,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 763,
                      'char' => 18,
                    ),
                    9 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'useImplicitOutput',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 763,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 763,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 763,
                        'char' => 46,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'echo',
                          'expressions' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'html',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 764,
                              'char' => 30,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 765,
                          'char' => 17,
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
                              'operator' => 'concat-assign',
                              'variable' => 'output',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'html',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 766,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 766,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 767,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 768,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 769,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 771,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 771,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 772,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Traverses a collection calling the callback to generate its HTML
     *
     * @param callback callback
     * @param string type
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 346,
                'char' => 79,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 347,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 347,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 346,
          'last-line' => 776,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'outputCss',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collectionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 777,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 777,
              'char' => 59,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'callback',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 779,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 780,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 780,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 780,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'tag',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 780,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 782,
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
                  'type' => 'variable',
                  'value' => 'collectionName',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 782,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 782,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 783,
                          'char' => 35,
                        ),
                        'name' => 'getCss',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 783,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 783,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 784,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 785,
                          'char' => 35,
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
                              'value' => 'collectionName',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 785,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 785,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 785,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 785,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 786,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 788,
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
                  'variable' => 'callback',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'Phalcon\\\\Tag',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 788,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 788,
                        'char' => 38,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'stylesheetLink',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 788,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 788,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 788,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 788,
                  'char' => 55,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 789,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 789,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 789,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 789,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 791,
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
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 791,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 791,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 791,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 791,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 791,
                    'char' => 52,
                  ),
                  'name' => 'has',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'tag',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 791,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 791,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 791,
                  'char' => 62,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 791,
                'char' => 62,
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
                      'variable' => 'tag',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 792,
                          'char' => 38,
                        ),
                        'name' => 'getShared',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tag',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 792,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 792,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 792,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 792,
                      'char' => 53,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'callback',
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
                              'value' => 'tag',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 793,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 793,
                            'char' => 32,
                          ),
                          1 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'string',
                              'value' => 'stylesheetLink',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 793,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 793,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 793,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 793,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 794,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 796,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 796,
                  'char' => 21,
                ),
                'name' => 'output',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 796,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 796,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'callback',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 796,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 796,
                    'char' => 49,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'css',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 796,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 796,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 796,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 797,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prints the HTML for CSS assets
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 778,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 778,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 777,
          'last-line' => 803,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'outputInline',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 804,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 804,
              'char' => 57,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'type',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 804,
              'char' => 63,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'html',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 806,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'joinedContent',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 806,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 806,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 807,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'attributes',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 807,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'code',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 807,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'codes',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 807,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'content',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 807,
                  'char' => 45,
                ),
                4 => 
                array (
                  'variable' => 'filter',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 807,
                  'char' => 53,
                ),
                5 => 
                array (
                  'variable' => 'filters',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 807,
                  'char' => 62,
                ),
                6 => 
                array (
                  'variable' => 'join',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 807,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 809,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 809,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 809,
                  'char' => 29,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'html',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 810,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 810,
                  'char' => 29,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'joinedContent',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 811,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 811,
                  'char' => 29,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'codes',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 812,
                      'char' => 40,
                    ),
                    'name' => 'getCodes',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 812,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 812,
                  'char' => 51,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'filters',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 813,
                      'char' => 40,
                    ),
                    'name' => 'getFilters',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 813,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 813,
                  'char' => 53,
                ),
                5 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'join',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 814,
                      'char' => 40,
                    ),
                    'name' => 'getJoin',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 814,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 814,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 816,
              'char' => 10,
            ),
            3 => 
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
                      'value' => 'codes',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 816,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 816,
                    'char' => 23,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 816,
                'char' => 25,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'codes',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 817,
                    'char' => 31,
                  ),
                  'value' => 'code',
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
                          'variable' => 'attributes',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'code',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 818,
                              'char' => 39,
                            ),
                            'name' => 'getAttributes',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 818,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 818,
                          'char' => 55,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'content',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'code',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 819,
                              'char' => 36,
                            ),
                            'name' => 'getContent',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 819,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 819,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 821,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'filters',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 821,
                        'char' => 39,
                      ),
                      'value' => 'filter',
                      'reverse' => 0,
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
                              'type' => 'not-equals',
                              'left' => 
                              array (
                                'type' => 'typeof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filter',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 825,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 825,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'object',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 825,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 825,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 825,
                            'char' => 57,
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
                                      'value' => 'Filter is invalid',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 826,
                                      'char' => 62,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 826,
                                    'char' => 62,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 826,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 827,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 833,
                          'char' => 23,
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
                              'variable' => 'content',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'filter',
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 833,
                                  'char' => 42,
                                ),
                                'name' => 'filter',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'content',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 833,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 833,
                                    'char' => 57,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 833,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 833,
                              'char' => 58,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 834,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 836,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'join',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 836,
                        'char' => 25,
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
                              'operator' => 'concat-assign',
                              'variable' => 'joinedContent',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'content',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 837,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 837,
                              'char' => 48,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 838,
                          'char' => 17,
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
                              'operator' => 'concat-assign',
                              'variable' => 'html',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'scall',
                                    'dynamic-class' => 0,
                                    'class' => 'Tag',
                                    'dynamic' => 0,
                                    'name' => 'tagHtml',
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'type',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 839,
                                          'char' => 49,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 839,
                                        'char' => 49,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'attributes',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 839,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 839,
                                        'char' => 61,
                                      ),
                                      2 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'bool',
                                          'value' => 'false',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 839,
                                          'char' => 68,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 839,
                                        'char' => 68,
                                      ),
                                      3 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'bool',
                                          'value' => 'true',
                                          'file' => '/app/phalcon/Assets/Manager.zep',
                                          'line' => 839,
                                          'char' => 74,
                                        ),
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 839,
                                        'char' => 74,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 840,
                                    'char' => 31,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'content',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 841,
                                    'char' => 31,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 841,
                                  'char' => 31,
                                ),
                                'right' => 
                                array (
                                  'type' => 'scall',
                                  'dynamic-class' => 0,
                                  'class' => 'Tag',
                                  'dynamic' => 0,
                                  'name' => 'tagHtmlClose',
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'type',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 841,
                                        'char' => 55,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 841,
                                      'char' => 55,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'bool',
                                        'value' => 'true',
                                        'file' => '/app/phalcon/Assets/Manager.zep',
                                        'line' => 841,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 841,
                                      'char' => 61,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 841,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 841,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 841,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 842,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 843,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 845,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'join',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 845,
                    'char' => 21,
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
                          'operator' => 'concat-assign',
                          'variable' => 'html',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'scall',
                                'dynamic-class' => 0,
                                'class' => 'Tag',
                                'dynamic' => 0,
                                'name' => 'tagHtml',
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'type',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 846,
                                      'char' => 45,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 846,
                                    'char' => 45,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'attributes',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 846,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 846,
                                    'char' => 57,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'bool',
                                      'value' => 'false',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 846,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 846,
                                    'char' => 64,
                                  ),
                                  3 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'bool',
                                      'value' => 'true',
                                      'file' => '/app/phalcon/Assets/Manager.zep',
                                      'line' => 846,
                                      'char' => 70,
                                    ),
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 846,
                                    'char' => 70,
                                  ),
                                ),
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 847,
                                'char' => 27,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'joinedContent',
                                'file' => '/app/phalcon/Assets/Manager.zep',
                                'line' => 848,
                                'char' => 27,
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 848,
                              'char' => 27,
                            ),
                            'right' => 
                            array (
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Tag',
                              'dynamic' => 0,
                              'name' => 'tagHtmlClose',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'type',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 848,
                                    'char' => 51,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 848,
                                  'char' => 51,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Assets/Manager.zep',
                                    'line' => 848,
                                    'char' => 57,
                                  ),
                                  'file' => '/app/phalcon/Assets/Manager.zep',
                                  'line' => 848,
                                  'char' => 57,
                                ),
                              ),
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 848,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 848,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 848,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 849,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 854,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 854,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'implicitOutput',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 854,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 854,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'bool',
                      'value' => 'true',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 854,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 854,
                    'char' => 45,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'echo',
                      'expressions' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'html',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 855,
                          'char' => 26,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 856,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'html',
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 857,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 857,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 858,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 859,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 861,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 861,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 862,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Traverses a collection and generate its HTML
     *
     * @param string type
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 805,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 805,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 804,
          'last-line' => 866,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'outputInlineCss',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collectionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 867,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 867,
              'char' => 65,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 869,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 871,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'collectionName',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 871,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 871,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 872,
                          'char' => 35,
                        ),
                        'name' => 'getCss',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 872,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 872,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 873,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 874,
                          'char' => 35,
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
                              'value' => 'collectionName',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 874,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 874,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 874,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 874,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 875,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 877,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 877,
                  'char' => 21,
                ),
                'name' => 'outputInline',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 877,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 877,
                    'char' => 45,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'style',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 877,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 877,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 877,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 878,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prints the HTML for inline CSS
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 868,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 868,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 867,
          'last-line' => 882,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'outputInlineJs',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collectionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 883,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 883,
              'char' => 64,
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
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 885,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 887,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'collectionName',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 887,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 887,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 888,
                          'char' => 35,
                        ),
                        'name' => 'getJs',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 888,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 888,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 889,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 890,
                          'char' => 35,
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
                              'value' => 'collectionName',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 890,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 890,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 890,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 890,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 891,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 893,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 893,
                  'char' => 21,
                ),
                'name' => 'outputInline',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 893,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 893,
                    'char' => 45,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'script',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 893,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 893,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 893,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 894,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prints the HTML for inline JS
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 884,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 884,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 883,
          'last-line' => 898,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'outputJs',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collectionName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 899,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 899,
              'char' => 58,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'callback',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 901,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 902,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'collection',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 902,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 902,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'tag',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 902,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 904,
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
                  'type' => 'variable',
                  'value' => 'collectionName',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 904,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 904,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 905,
                          'char' => 35,
                        ),
                        'name' => 'getJs',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 905,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 905,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 906,
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
                      'variable' => 'collection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 907,
                          'char' => 35,
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
                              'value' => 'collectionName',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 907,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 907,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 907,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 907,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 908,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 910,
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
                  'variable' => 'callback',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'Phalcon\\\\Tag',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 910,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 910,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'value' => 
                        array (
                          'type' => 'string',
                          'value' => 'javascriptInclude',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 910,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 910,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 910,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 910,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 912,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 912,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 912,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 912,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 912,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 913,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 913,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 913,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 913,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 913,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 913,
                    'char' => 52,
                  ),
                  'name' => 'has',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'tag',
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 913,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 913,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 913,
                  'char' => 62,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 913,
                'char' => 62,
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
                      'variable' => 'tag',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Assets/Manager.zep',
                          'line' => 914,
                          'char' => 38,
                        ),
                        'name' => 'getShared',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'tag',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 914,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 914,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 914,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 914,
                      'char' => 53,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'callback',
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
                              'value' => 'tag',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 915,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 915,
                            'char' => 32,
                          ),
                          1 => 
                          array (
                            'value' => 
                            array (
                              'type' => 'string',
                              'value' => 'javascriptInclude',
                              'file' => '/app/phalcon/Assets/Manager.zep',
                              'line' => 915,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Assets/Manager.zep',
                            'line' => 915,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Assets/Manager.zep',
                        'line' => 915,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 915,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 916,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 918,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 918,
                  'char' => 21,
                ),
                'name' => 'output',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 918,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 918,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'callback',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 918,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 918,
                    'char' => 49,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'js',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 918,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 918,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 918,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 919,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prints the HTML for JS assets
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 900,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 900,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 899,
          'last-line' => 927,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'set',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 928,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 928,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 928,
              'char' => 60,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'collections',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'id',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 930,
                      'char' => 33,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collection',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 930,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 930,
                  'char' => 47,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 932,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 932,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 933,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a collection in the Assets Manager
     *
     *```php
     * $assets->set("js", $collection);
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 929,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 929,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 929,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 928,
          'last-line' => 937,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDI',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 938,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 938,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 940,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 940,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 941,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the dependency injector
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 939,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 938,
          'last-line' => 945,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setOptions',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 946,
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
                  'property' => 'options',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 948,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 948,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 950,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 950,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 951,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the manager options
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 947,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 947,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 947,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 946,
          'last-line' => 955,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useImplicitOutput',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'implicitOutput',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 956,
              'char' => 58,
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
                  'property' => 'implicitOutput',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'implicitOutput',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 958,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 958,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 960,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 960,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 961,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the HTML generated must be directly printed or returned
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
                  'value' => 'Manager',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 957,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 957,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 957,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 956,
          'last-line' => 965,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getPrefixedPath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'collection',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Collection',
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 966,
                'char' => 60,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 966,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 966,
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
                  'variable' => 'prefix',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 968,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 970,
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
                  'variable' => 'prefix',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'collection',
                      'file' => '/app/phalcon/Assets/Manager.zep',
                      'line' => 970,
                      'char' => 33,
                    ),
                    'name' => 'getPrefix',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 970,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 970,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 972,
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
                  'type' => 'variable',
                  'value' => 'prefix',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 972,
                  'char' => 20,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 972,
                'char' => 20,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Assets/Manager.zep',
                    'line' => 973,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 974,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 976,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'prefix',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 976,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'path',
                  'file' => '/app/phalcon/Assets/Manager.zep',
                  'line' => 976,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 976,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Assets/Manager.zep',
              'line' => 977,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the prefixed path
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
                'file' => '/app/phalcon/Assets/Manager.zep',
                'line' => 967,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Manager.zep',
            'line' => 967,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Manager.zep',
          'line' => 966,
          'last-line' => 978,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Assets/Manager.zep',
      'line' => 29,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Assets/Manager.zep',
    'line' => 29,
    'char' => 5,
  ),
);