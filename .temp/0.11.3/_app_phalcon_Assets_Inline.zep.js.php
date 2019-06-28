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
    'file' => '/app/phalcon/Assets/Inline.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Assets',
    'file' => '/app/phalcon/Assets/Inline.zep',
    'line' => 19,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents an inline asset
 *
 *```php
 * $inline = new \\Phalcon\\Assets\\Inline("js", "alert(\'hello world\');");
 *```
 *',
    'file' => '/app/phalcon/Assets/Inline.zep',
    'line' => 20,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Inline',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'AssetInterface',
        'file' => '/app/phalcon/Assets/Inline.zep',
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
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 25,
              'char' => 32,
            ),
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
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
          'name' => 'content',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 30,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
          'line' => 34,
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
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 35,
              'char' => 28,
            ),
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
          'line' => 39,
          'char' => 6,
        ),
        3 => 
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
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 40,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
          'line' => 44,
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
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 45,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'content',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 45,
              'char' => 60,
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
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 45,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 45,
              'char' => 80,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 45,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 45,
              'char' => 103,
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
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 47,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 47,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'content',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'content',
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 48,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 48,
                  'char' => 36,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'filter',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'filter',
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 49,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 49,
                  'char' => 34,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'attributes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'attributes',
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 50,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 50,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 51,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Assets\\Inline constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Assets/Inline.zep',
            'line' => 46,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
          'line' => 45,
          'last-line' => 55,
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
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 58,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 60,
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
                          'file' => '/app/phalcon/Assets/Inline.zep',
                          'line' => 60,
                          'char' => 24,
                        ),
                        'name' => 'getType',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Assets/Inline.zep',
                        'line' => 60,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => ':',
                        'file' => '/app/phalcon/Assets/Inline.zep',
                        'line' => 60,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Assets/Inline.zep',
                      'line' => 60,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Assets/Inline.zep',
                        'line' => 60,
                        'char' => 46,
                      ),
                      'name' => 'getContent',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Assets/Inline.zep',
                      'line' => 60,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 60,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 60,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 62,
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
                      'file' => '/app/phalcon/Assets/Inline.zep',
                      'line' => 62,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 62,
                    'char' => 23,
                  ),
                ),
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 62,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 63,
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
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 57,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Inline.zep',
            'line' => 57,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
          'line' => 56,
          'last-line' => 67,
          'char' => 19,
        ),
        2 => 
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
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 68,
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
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 70,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 70,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 72,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 72,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 73,
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
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 69,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 69,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Inline.zep',
            'line' => 69,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
          'line' => 68,
          'last-line' => 77,
          'char' => 19,
        ),
        3 => 
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
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 78,
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
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 80,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 80,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 82,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 82,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 83,
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
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 79,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 79,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Inline.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
          'line' => 78,
          'last-line' => 87,
          'char' => 19,
        ),
        4 => 
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
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 88,
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
                    'file' => '/app/phalcon/Assets/Inline.zep',
                    'line' => 90,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 90,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 92,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 92,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Assets/Inline.zep',
              'line' => 93,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the inline\'s type
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
                  'file' => '/app/phalcon/Assets/Inline.zep',
                  'line' => 89,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Assets/Inline.zep',
                'line' => 89,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Assets/Inline.zep',
            'line' => 89,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Assets/Inline.zep',
          'line' => 88,
          'last-line' => 94,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Assets/Inline.zep',
      'line' => 20,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Assets/Inline.zep',
    'line' => 20,
    'char' => 5,
  ),
);