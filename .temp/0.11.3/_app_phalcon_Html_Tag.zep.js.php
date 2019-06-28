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
    'file' => '/app/phalcon/Html/Tag.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html',
    'file' => '/app/phalcon/Html/Tag.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Html/Tag.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Html/Tag.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Html/Tag.zep',
        'line' => 14,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Html/Tag.zep',
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
        'name' => 'Phalcon\\Escaper',
        'file' => '/app/phalcon/Html/Tag.zep',
        'line' => 15,
        'char' => 20,
      ),
    ),
    'file' => '/app/phalcon/Html/Tag.zep',
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
        'name' => 'Phalcon\\EscaperInterface',
        'file' => '/app/phalcon/Html/Tag.zep',
        'line' => 16,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Html/Tag.zep',
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
        'name' => 'Phalcon\\Helper\\Arr',
        'file' => '/app/phalcon/Html/Tag.zep',
        'line' => 17,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Html/Tag.zep',
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
        'name' => 'Phalcon\\Html\\Exception',
        'file' => '/app/phalcon/Html/Tag.zep',
        'line' => 18,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Html/Tag.zep',
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
        'name' => 'Phalcon\\UrlInterface',
        'file' => '/app/phalcon/Html/Tag.zep',
        'line' => 19,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Html/Tag.zep',
    'line' => 26,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Tag
 *
 * Phalcon\\Html\\Tag is designed to simplify building of HTML tags. It provides a
 * set of helpers to dynamically generate HTML.
 *',
    'file' => '/app/phalcon/Html/Tag.zep',
    'line' => 27,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Tag',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Html/Tag.zep',
        'line' => 28,
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
          'name' => 'container',
          'docblock' => '**
     * @var DiInterface
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 36,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'append',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 37,
            'char' => 24,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 41,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'docType',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 42,
            'char' => 24,
          ),
          'docblock' => '**
     * @var int
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 46,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'escaper',
          'docblock' => '**
     * @var <EscaperInterface>
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 51,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'prepend',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 52,
            'char' => 25,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 56,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'separator',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 57,
            'char' => 25,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 61,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'title',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 62,
            'char' => 21,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 66,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'values',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 67,
            'char' => 24,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 71,
          'char' => 6,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'url',
          'docblock' => '**
     * @var <UrlInterface>
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 76,
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
              'name' => 'escaper',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'EscaperInterface',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 92,
                'char' => 58,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 92,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 92,
              'char' => 66,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'url',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'UrlInterface',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 92,
                'char' => 85,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 92,
                'char' => 93,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 92,
              'char' => 93,
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
                  'property' => 'escaper',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'escaper',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 94,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 94,
                  'char' => 36,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'url',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'url',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 95,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 95,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 96,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 92,
          'last-line' => 100,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'appendTitle',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'title',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 101,
              'char' => 42,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'title',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 103,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 103,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 103,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'append',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'title',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 104,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 104,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 105,
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
                      'property' => 'append',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'title',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 106,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 106,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 106,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 107,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 109,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 109,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 110,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Appends a text to current document title
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
                  'value' => 'Tag',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 102,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 102,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 102,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 101,
          'last-line' => 127,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'button',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 128,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 128,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 128,
              'char' => 63,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 130,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'button',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 130,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 130,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 130,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 130,
                    'char' => 46,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 130,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 130,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 130,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 131,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="button"] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->button(\'Click Me\');
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ button(\'Click Me\') }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 129,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 129,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 128,
          'last-line' => 136,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'clear',
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
                  'property' => 'append',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 139,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 139,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'docType',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 140,
                      'char' => 43,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'HTML5',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 140,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 140,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 140,
                  'char' => 43,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'prepend',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 141,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 141,
                  'char' => 34,
                ),
                3 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'separator',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 142,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 142,
                  'char' => 32,
                ),
                4 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'title',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 143,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 143,
                  'char' => 32,
                ),
                5 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'values',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 144,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 144,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 145,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resets the request and internal values to avoid those fields will have
     * any default value.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 138,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 137,
          'last-line' => 154,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'element',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tag',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 155,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 155,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 155,
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
                  'variable' => 'onlyStart',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 157,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 157,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'selfClose',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 157,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'useEol',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 157,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 159,
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
                  'variable' => 'useEol',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 159,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 159,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'useEol',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 159,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 159,
                        'char' => 52,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 159,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 159,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 159,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 159,
                  'char' => 60,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'onlyStart',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 160,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 160,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'onlyStart',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 160,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 160,
                        'char' => 55,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 160,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 160,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 160,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 160,
                  'char' => 63,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'selfClose',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 161,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 161,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'selfClose',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 161,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 161,
                        'char' => 55,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 161,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 161,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 161,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 161,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 166,
              'char' => 13,
            ),
            2 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 166,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'onlyStart',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 166,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 166,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 167,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 167,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'selfClose',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 167,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 167,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 168,
              'char' => 13,
            ),
            4 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 168,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'useEol',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 168,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 168,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 170,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 170,
                      'char' => 27,
                    ),
                    'name' => 'renderAttributes',
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
                            'type' => 'string',
                            'value' => '<',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 170,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tag',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 170,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 170,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 170,
                        'char' => 52,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 170,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 170,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 170,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 170,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 172,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 172,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'docType',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 172,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 172,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 172,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'HTML5',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 172,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 172,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 172,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'selfClose',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 173,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => ' />',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 174,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 174,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 175,
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
                            'type' => 'string',
                            'value' => '>',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 176,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 176,
                          'char' => 31,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 177,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 178,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'onlyStart',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 179,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '>',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 180,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 180,
                          'char' => 31,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 181,
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
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => '></',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 182,
                                'char' => 34,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'tag',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 182,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 182,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '>',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 182,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 182,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 182,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 183,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 184,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 186,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'useEol',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 186,
                'char' => 19,
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
                      'variable' => 'output',
                      'expr' => 
                      array (
                        'type' => 'constant',
                        'value' => 'PHP_EOL',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 187,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 187,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 188,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 190,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 190,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 191,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML tag
     *
     * Parameters
     * `onlyStart` Only process the start of th element
     * `selfClose` It is a self close element
     * `useEol`    Append PHP_EOL at the end
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 156,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 156,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 155,
          'last-line' => 217,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'elementClose',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tag',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 218,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 218,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 218,
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
                  'variable' => 'useEol',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 220,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 220,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 222,
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
                  'variable' => 'useEol',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 222,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 222,
                        'char' => 41,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'useEol',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 222,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 222,
                        'char' => 49,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 222,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 222,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 222,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 222,
                  'char' => 57,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 224,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'useEol',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 224,
                'char' => 19,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
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
                          'type' => 'string',
                          'value' => '</',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 225,
                          'char' => 23,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'tag',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 225,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 225,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '>',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 225,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 225,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'PHP_EOL',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 225,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 225,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 226,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 228,
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
                  'type' => 'concat',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => '</',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 228,
                    'char' => 19,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tag',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 228,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 228,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '>',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 228,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 228,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 230,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds the closing tag of an html element
     *
     * Parameters
     * `useEol`    Append PHP_EOL at the end
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tab = new Tag();
     *
     * echo $tag->elementClose(
     *     [
     *         \'name\' => \'aside\',
     *     ]
     * ); // </aside>
     *
     * echo $tag->elementClose(
     *     [
     *         \'name\'   => \'aside\',
     *         \'useEol\' => true,
     *     ]
     * ); // \'</aside>\' . PHP_EOL
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 219,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 219,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 218,
          'last-line' => 234,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'endForm',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'eol',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 235,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 235,
              'char' => 44,
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
                'value' => 'eol',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 237,
                'char' => 16,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => '</form>',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 238,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'PHP_EOL',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 238,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 238,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 239,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '</form>',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 240,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 241,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 242,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the closing tag of a form element
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 236,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 236,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 235,
          'last-line' => 267,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'form',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'action',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 268,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 268,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 268,
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
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 270,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'params',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 270,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'service',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 270,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 272,
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
                  'variable' => 'service',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 272,
                      'char' => 28,
                    ),
                    'name' => 'getService',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'url',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 272,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 272,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 272,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 272,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 274,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'method',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 274,
                      'char' => 30,
                    ),
                  ),
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 274,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 274,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'method',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 274,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 274,
                        'char' => 61,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'post',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 274,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 274,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 274,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 274,
                  'char' => 68,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'action',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 275,
                      'char' => 30,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'service',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 275,
                      'char' => 42,
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
                          'value' => 'action',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 275,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 275,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 275,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 275,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 280,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'params',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 280,
                  'char' => 49,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 280,
                    'char' => 36,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 280,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 280,
                  'char' => 49,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 280,
                'char' => 49,
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
                      'operator' => 'concat-assign',
                      'variable' => 'parameters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'action',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 281,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '?',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 281,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 281,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 281,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 281,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 283,
                  'char' => 17,
                ),
                1 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 283,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 283,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 283,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 284,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 286,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 286,
                        'char' => 27,
                      ),
                      'name' => 'renderAttributes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '<form',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 286,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 286,
                          'char' => 50,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'parameters',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 286,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 286,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 286,
                      'char' => 64,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '>',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 286,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 286,
                    'char' => 67,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 286,
                  'char' => 67,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 288,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 288,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 290,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML FORM tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tab = new Tag();
     *
     * echo $tag->form(\'posts/save\');
     *
     * echo $tag->form(
     *     \'posts/save\',
     *     [
     *         "method" => "post",
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ form(\'posts/save\') }}{% endraw %}
     * {% raw %}{{ form(\'posts/save\', [\'method\': \'post\') }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 269,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 269,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 268,
          'last-line' => 318,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'friendlyTitle',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 319,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 319,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 319,
              'char' => 70,
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
                  'variable' => 'count',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 321,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'from',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 321,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'locale',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 321,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'lowercase',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 321,
                  'char' => 43,
                ),
                4 => 
                array (
                  'variable' => 'replace',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 321,
                  'char' => 52,
                ),
                5 => 
                array (
                  'variable' => 'separator',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 321,
                  'char' => 63,
                ),
                6 => 
                array (
                  'variable' => 'to',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 321,
                  'char' => 67,
                ),
                7 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 321,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 323,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
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
                      'value' => 'iconv',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 323,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 323,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 323,
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
                      'variable' => 'locale',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'setlocale',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'LC_ALL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 327,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 327,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'en_US.UTF-8',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 327,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 327,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 327,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 327,
                      'char' => 56,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'text',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'iconv',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'UTF-8',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 328,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 328,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'ASCII//TRANSLIT',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 328,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 328,
                            'char' => 54,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 328,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 328,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 328,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 328,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 329,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 331,
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
                  'variable' => 'lowercase',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 331,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 331,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'lowercase',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 331,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 331,
                        'char' => 55,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 331,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 331,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 331,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 331,
                  'char' => 62,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'replace',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 332,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 332,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'replace',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 332,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 332,
                        'char' => 53,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'empty-array',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 332,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 332,
                        'char' => 57,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 332,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 332,
                  'char' => 58,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'separator',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 333,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 333,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'separator',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 333,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 333,
                        'char' => 55,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '-',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 333,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 333,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 333,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 333,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 335,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'replace',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 335,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 335,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 335,
                'char' => 27,
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
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'not-identical',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'replace',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 336,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 336,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 336,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 336,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'not-identical',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'replace',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 336,
                              'char' => 71,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 336,
                            'char' => 71,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 336,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 336,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 336,
                        'char' => 79,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 336,
                      'char' => 81,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 336,
                    'char' => 81,
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
                              'value' => 'Parameter replace must be an array or a string',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 339,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 339,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 339,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 340,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 342,
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
                        'value' => 'replace',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 342,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 342,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 342,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 342,
                    'char' => 42,
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
                          'variable' => 'from',
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
                                  'value' => 'replace',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 343,
                                  'char' => 36,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 343,
                                'char' => 36,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 343,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 343,
                          'char' => 37,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 344,
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
                          'variable' => 'from',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'replace',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 345,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 345,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 346,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 348,
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
                      'variable' => 'count',
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
                              'value' => 'from',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 348,
                              'char' => 35,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 348,
                            'char' => 35,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 348,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 348,
                      'char' => 36,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'to',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'array_fill',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 349,
                              'char' => 37,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 349,
                            'char' => 37,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'sub',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'count',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 349,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'int',
                                'value' => '1',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 349,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 349,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 349,
                            'char' => 48,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => ' ',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 349,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 349,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 349,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 349,
                      'char' => 52,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'text',
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
                              'value' => 'from',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 350,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 350,
                            'char' => 41,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'to',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 350,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 350,
                            'char' => 45,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 350,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 350,
                            'char' => 51,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 350,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 350,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 351,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 353,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_replace',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/[^a-zA-Z0-9\\\\/_|+ -]/',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 353,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 353,
                        'char' => 57,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 353,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 353,
                        'char' => 59,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 353,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 353,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 353,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 353,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 354,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'lowercase',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 354,
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
                      'variable' => 'output',
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
                              'value' => 'output',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 355,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 355,
                            'char' => 43,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 355,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 355,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 356,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 358,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_replace',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '/[\\\\/_|+ -]+/',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 358,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 358,
                        'char' => 48,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'separator',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 358,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 358,
                        'char' => 59,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'output',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 358,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 358,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 358,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 358,
                  'char' => 68,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'trim',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'output',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 359,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 359,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'separator',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 359,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 359,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 359,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 359,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 361,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
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
                      'value' => 'iconv',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 361,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 361,
                    'char' => 34,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 361,
                'char' => 36,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'setlocale',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LC_ALL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 365,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 365,
                        'char' => 29,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'locale',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 365,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 365,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 365,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 366,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 368,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 368,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 369,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Converts text to URL-friendly strings
     *
     * Parameters
     * `text`      The text to be processed
     * `separator` Separator to use (default \'-\')
     * `lowercase` Convert to lowercase
     * `replace`
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tab = new Tag();
     *
     * echo $tag->friendlyTitle(
     *     [
     *         \'text\'       => \'These are big important news\',
     *         \'separator\' => \'-\',
     *     ]
     * );
     * ```
     *
     * Volt Syntax:
     * ```php
     * {% raw %}{{ friendly_title([\'text\': \'These are big important news\', \'separator\': \'-\']) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 320,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 320,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 319,
          'last-line' => 373,
          'char' => 19,
        ),
        9 => 
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
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 376,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 376,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 376,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 377,
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
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 375,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 375,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 375,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 374,
          'last-line' => 382,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDocType',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 385,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'docType',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 386,
                  'char' => 9,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 386,
                'char' => 9,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '1',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 387,
                    'char' => 19,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD HTML 3.2 Final//EN\\">',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 388,
                          'char' => 82,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 388,
                          'char' => 91,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 388,
                        'char' => 91,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 391,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 391,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '2',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 391,
                    'char' => 19,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'type' => 'string',
                              'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD HTML 4.01//EN\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 392,
                              'char' => 76,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 392,
                              'char' => 86,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 392,
                            'char' => 86,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/html4/strict.dtd\\">',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 393,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 393,
                          'char' => 70,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 393,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 393,
                        'char' => 79,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 396,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 396,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '3',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 396,
                    'char' => 19,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'type' => 'string',
                              'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD HTML 4.01 Transitional//EN\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 397,
                              'char' => 89,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 397,
                              'char' => 99,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 397,
                            'char' => 99,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/html4/loose.dtd\\">',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 398,
                            'char' => 69,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 398,
                          'char' => 69,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 398,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 398,
                        'char' => 78,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 401,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 401,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '4',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 401,
                    'char' => 19,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'type' => 'string',
                              'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD HTML 4.01 Frameset//EN\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 402,
                              'char' => 85,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 402,
                              'char' => 95,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 402,
                            'char' => 95,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/html4/frameset.dtd\\">',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 403,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 403,
                          'char' => 72,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 403,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 403,
                        'char' => 81,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 406,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 406,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '6',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 406,
                    'char' => 19,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'type' => 'string',
                              'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD XHTML 1.0 Strict//EN\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 407,
                              'char' => 83,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 407,
                              'char' => 93,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 407,
                            'char' => 93,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\\">',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 408,
                            'char' => 82,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 408,
                          'char' => 82,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 408,
                          'char' => 91,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 408,
                        'char' => 91,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 411,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 411,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '7',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 411,
                    'char' => 19,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'type' => 'string',
                              'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD XHTML 1.0 Transitional//EN\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 412,
                              'char' => 89,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 412,
                              'char' => 99,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 412,
                            'char' => 99,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\\">',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 413,
                            'char' => 88,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 413,
                          'char' => 88,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 413,
                          'char' => 97,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 413,
                        'char' => 97,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 416,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 416,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '8',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 416,
                    'char' => 19,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'type' => 'string',
                              'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD XHTML 1.0 Frameset//EN\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 417,
                              'char' => 85,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 417,
                              'char' => 95,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 417,
                            'char' => 95,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\\">',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 418,
                            'char' => 84,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 418,
                          'char' => 84,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 418,
                          'char' => 93,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 418,
                        'char' => 93,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 421,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 421,
                  'char' => 16,
                ),
                7 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '9',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 421,
                    'char' => 19,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'type' => 'string',
                              'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD XHTML 1.1//EN\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 422,
                              'char' => 76,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 422,
                              'char' => 86,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 422,
                            'char' => 86,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\\">',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 423,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 423,
                          'char' => 77,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 423,
                          'char' => 86,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 423,
                        'char' => 86,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 426,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 426,
                  'char' => 16,
                ),
                8 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '10',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 426,
                    'char' => 20,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
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
                              'type' => 'string',
                              'value' => '<!DOCTYPE html PUBLIC \\"-//W3C//DTD XHTML 2.0//EN\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 427,
                              'char' => 76,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 427,
                              'char' => 86,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 427,
                            'char' => 86,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '\\t\\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\\">',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 428,
                            'char' => 72,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 428,
                          'char' => 72,
                        ),
                        'right' => 
                        array (
                          'type' => 'constant',
                          'value' => 'PHP_EOL',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 428,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 428,
                        'char' => 81,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 430,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 430,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 432,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'string',
                  'value' => '<!DOCTYPE html>',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 432,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'constant',
                  'value' => 'PHP_EOL',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 432,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 432,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 433,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the document type declaration of content. If the docType has not
     * been set properly, XHTML5 is returned
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 384,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 384,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 383,
          'last-line' => 459,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTitle',
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
                'value' => 'true',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 460,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 460,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'append',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 460,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 460,
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
                  'variable' => 'item',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 462,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 462,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'title',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 462,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'appendTitle',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 462,
                  'char' => 45,
                ),
                4 => 
                array (
                  'variable' => 'prependTitle',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 462,
                  'char' => 59,
                ),
                5 => 
                array (
                  'variable' => 'separator',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 462,
                  'char' => 70,
                ),
                6 => 
                array (
                  'variable' => 'escaper',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 462,
                  'char' => 79,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 463,
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
                  'variable' => 'items',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 463,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 465,
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
                  'variable' => 'escaper',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 465,
                      'char' => 30,
                    ),
                    'name' => 'getService',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'escaper',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 465,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 465,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 465,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 465,
                  'char' => 50,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'items',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 466,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 466,
                  'char' => 27,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 467,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 467,
                  'char' => 25,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'title',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'escaper',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 468,
                      'char' => 33,
                    ),
                    'name' => 'escapeHtml',
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
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 468,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'title',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 468,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 468,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 468,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 468,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 468,
                  'char' => 57,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'separator',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'escaper',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 469,
                      'char' => 33,
                    ),
                    'name' => 'escapeHtml',
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
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 469,
                            'char' => 50,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'separator',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 469,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 469,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 469,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 469,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 469,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 471,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'prepend',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 471,
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
                      'variable' => 'prependTitle',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 472,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prepend',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 472,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 472,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 472,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 474,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'prependTitle',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 474,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 474,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 474,
                    'char' => 36,
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
                          'variable' => 'prependArray',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'array_reverse',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'prependTitle',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 475,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 475,
                                'char' => 62,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 475,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 475,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 476,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'prependArray',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 476,
                        'char' => 42,
                      ),
                      'value' => 'item',
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
                              'variable' => 'items',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'escaper',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 477,
                                  'char' => 43,
                                ),
                                'name' => 'escapeHtml',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'item',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 477,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 477,
                                    'char' => 59,
                                  ),
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 477,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 477,
                              'char' => 60,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 478,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 479,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 480,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 482,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'title',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 482,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 482,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 482,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'items',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'title',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 483,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 483,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 484,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 486,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'append',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 486,
                'char' => 19,
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
                      'variable' => 'appendTitle',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 487,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'append',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 487,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 487,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 487,
                      'char' => 43,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 489,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'empty',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'appendTitle',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 489,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 489,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 489,
                    'char' => 35,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'for',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'appendTitle',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 490,
                        'char' => 41,
                      ),
                      'value' => 'item',
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
                              'variable' => 'items',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'escaper',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 491,
                                  'char' => 43,
                                ),
                                'name' => 'escapeHtml',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'item',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 491,
                                      'char' => 59,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 491,
                                    'char' => 59,
                                  ),
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 491,
                                'char' => 60,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 491,
                              'char' => 60,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 492,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 493,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 494,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 496,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'items',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 496,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 496,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 496,
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
                      'operator' => 'assign',
                      'variable' => 'output',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'implode',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'separator',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 497,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 497,
                            'char' => 43,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'items',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 497,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 497,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 497,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 497,
                      'char' => 51,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 498,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 500,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 500,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 501,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the current document title. The title will be automatically escaped.
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * $tag
     *        ->setTitleSeparator(\' \')
     *         ->prependTitle([\'Hello\'])
     *         ->setTitle(\'World\')
     *         ->appendTitle([\'from Phalcon\']);
     *
     * echo $tag->getTitle();             // Hello World from Phalcon
     * echo $tag->getTitle(false);        // World from Phalcon
     * echo $tag->getTitle(true, false);  // Hello World
     * echo $tag->getTitle(false, false); // World
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ get_title() }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 461,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 461,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 460,
          'last-line' => 518,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTitleSeparator',
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
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 521,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'separator',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 521,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 521,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 522,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the current document title separator
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->getTitleSeparator();
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ get_title_separator() }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 520,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 520,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 519,
          'last-line' => 527,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValue',
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
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 528,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 528,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 528,
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
                  'variable' => 'value',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 530,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 532,
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
                    'value' => 'value',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 532,
                    'char' => 44,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 532,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 532,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 532,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 532,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 532,
                'char' => 44,
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
                      'type' => 'fetch',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 536,
                        'char' => 49,
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
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 536,
                            'char' => 35,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'values',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 536,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 536,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 536,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 536,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 536,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 536,
                    'char' => 49,
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
                          'type' => 'fetch',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 540,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => '_POST',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 540,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 540,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 540,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 540,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 540,
                        'char' => 46,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 541,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 542,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 543,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 544,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 546,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'value',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 546,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 547,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Every helper calls this function to check whether a component has a
     * predefined value using `setAttribute` or value from $_POST
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 528,
                'char' => 73,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 529,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 529,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 528,
          'last-line' => 552,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hasValue',
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
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 553,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'or',
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
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 558,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'values',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 558,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 558,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 558,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 558,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 558,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => '_POST',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 558,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 558,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 558,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 558,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 558,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 559,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if a helper has a default value set using `setAttribute()` or
     * value from $_POST
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 554,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 554,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 553,
          'last-line' => 595,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'image',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'url',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 596,
                'char' => 40,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 596,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 596,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 596,
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
                  'variable' => 'local',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 598,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'service',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 598,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'src',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 598,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 598,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 600,
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
                  'variable' => 'local',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 600,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 600,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'local',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 600,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 600,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 600,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 600,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 600,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 600,
                  'char' => 54,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'src',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 601,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 601,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 601,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 601,
                        'char' => 45,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'url',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 601,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 601,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 601,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 601,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 606,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'local',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 606,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'service',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 607,
                          'char' => 32,
                        ),
                        'name' => 'getService',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'url',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 607,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 607,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 607,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 607,
                      'char' => 48,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'src',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'service',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 608,
                          'char' => 35,
                        ),
                        'name' => 'getStatic',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'url',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 608,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 608,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 608,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 608,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 609,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 611,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 611,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'local',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 611,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 611,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 613,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'src',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 613,
                      'char' => 27,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'src',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 613,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 613,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 615,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 615,
                        'char' => 27,
                      ),
                      'name' => 'renderAttributes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '<img',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 615,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 615,
                          'char' => 49,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'parameters',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 615,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 615,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 615,
                      'char' => 63,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 615,
                        'char' => 70,
                      ),
                      'name' => 'renderCloseTag',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 615,
                      'char' => 87,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 615,
                    'char' => 87,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 615,
                  'char' => 87,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 617,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 617,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 618,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds HTML IMG tags
     *
     * Parameters
     * `local` Local resource or not (default `true`)
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->image(\'img/bg.png\');
     *
     * echo $tag->image(
     *     \'img/photo.jpg\',
     *     [
     *         \'alt\' => \'Some Photo\',
     *     ]
     * );
     *
     * echo $tag->image(
     *     \'http://static.mywebsite.com/img/bg.png\',
     *     [
     *         \'local\' => false,
     *     ]
     * );
     * ```
     *
     * Volt Syntax:
     * ```php
     * {% raw %}{{ image(\'img/bg.png\') }}{% endraw %}
     * {% raw %}{{ image(\'img/photo.jpg\', [\'alt\': \'Some Photo\') }}{% endraw %}
     * {% raw %}{{ image(\'http://static.mywebsite.com/img/bg.png\', [\'local\': false]) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 597,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 597,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 596,
          'last-line' => 636,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputCheckbox',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 637,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 637,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 637,
              'char' => 70,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 639,
                  'char' => 21,
                ),
                'name' => 'renderInputChecked',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'checkbox',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 639,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 639,
                    'char' => 49,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 639,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 639,
                    'char' => 55,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 639,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 639,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 639,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 640,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="check"] tag
     *
     * ```php
     * echo $tag->inputCheckbox(
     *     [
     *         \'name\'  => \'terms,
     *         \'value\' => \'Y\',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_checkbox([\'name\': \'terms, \'value\': \'Y\']) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 638,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 638,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 637,
          'last-line' => 644,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputColor',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 645,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 645,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 645,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 647,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'color',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 647,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 647,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 647,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 647,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 647,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 647,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 647,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 648,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'color\'] tag
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 646,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 646,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 645,
          'last-line' => 670,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputDate',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 671,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 671,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 671,
              'char' => 66,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 673,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'date',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 673,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 673,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 673,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 673,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 673,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 673,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 673,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 674,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'date\'] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputDate(
     *     [
     *         \'name\'  => \'born\',
     *         \'value\' => \'14-12-1980\',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_date([\'name\':\'born\', \'value\':\'14-12-1980\']) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 672,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 672,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 671,
          'last-line' => 696,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputDateTime',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 697,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 697,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 697,
              'char' => 70,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 699,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'datetime',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 699,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 699,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 699,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 699,
                    'char' => 48,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 699,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 699,
                    'char' => 60,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 699,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 700,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Builds a HTML input[type=\'datetime\'] tag
    *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputDateTime(
     *     [
     *         \'name\'  => \'born\',
     *         \'value\' => \'14-12-1980\',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_date_time([\'name\':\'born\', \'value\':\'14-12-1980\']) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 698,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 698,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 697,
          'last-line' => 722,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputDateTimeLocal',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 723,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 723,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 723,
              'char' => 75,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 725,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'datetime-local',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 725,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 725,
                    'char' => 48,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 725,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 725,
                    'char' => 54,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 725,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 725,
                    'char' => 66,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 725,
                'char' => 67,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 726,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Builds a HTML input[type=\'datetime-local\'] tag
    *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputDateTimeLocal(
     *     [
     *         \'name\'  => \'born\',
     *         \'value\' => \'14-12-1980\',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_date_time_local([\'name\':\'born\', \'value\':\'14-12-1980\']) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 724,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 724,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 723,
          'last-line' => 747,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputEmail',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 748,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 748,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 748,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 750,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'email',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 750,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 750,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 750,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 750,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 750,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 750,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 750,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 751,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'email\'] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputEmail(
     *     [
     *         \'name\' => \'email\',
      *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_email([\'name\': \'email\']);{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 749,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 749,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 748,
          'last-line' => 772,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputFile',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 773,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 773,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 773,
              'char' => 66,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 775,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'file',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 775,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 775,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 775,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 775,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 775,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 775,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 775,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 776,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'file\'] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputFile(
     *     [
     *         \'name\' => \'file\',
      *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_file([\'name\': \'file\']){% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 774,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 774,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 773,
          'last-line' => 793,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputHidden',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 794,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 794,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 794,
              'char' => 68,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 796,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'hidden',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 796,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 796,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 796,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 796,
                    'char' => 46,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 796,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 796,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 796,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 797,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'hidden\'] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputHidden(
     *     [
     *         \'name\'  => \'my-field\',
     *         \'value\' => \'mike\',
     *     ]
     * );
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 795,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 795,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 794,
          'last-line' => 817,
          'char' => 19,
        ),
        24 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputImage',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 818,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 818,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 818,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 820,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'image',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 820,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 820,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 820,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 820,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 820,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 820,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 820,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 821,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="image"] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     * echo $tag->inputImage(
     *     [
     *         \'src\' => \'/img/button.png\',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_image([\'src\': \'/img/button.png\']) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 819,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 819,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 818,
          'last-line' => 825,
          'char' => 19,
        ),
        25 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputMonth',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 826,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 826,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 826,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 828,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'month',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 828,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 828,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 828,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 828,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 828,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 828,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 828,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 829,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'month\'] tag
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 827,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 827,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 826,
          'last-line' => 847,
          'char' => 19,
        ),
        26 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputNumeric',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 848,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 848,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 848,
              'char' => 69,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 850,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'numeric',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 850,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 850,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 850,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 850,
                    'char' => 47,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 850,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 850,
                    'char' => 59,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 850,
                'char' => 60,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 851,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'number\'] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->numericField(
     *     [
     *         \'name\' => \'price\',
     *         \'min\'  => \'1\',
     *         \'max\'  => \'5\',
     *     ]
     * );
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 849,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 849,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 848,
          'last-line' => 868,
          'char' => 19,
        ),
        27 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputPassword',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 869,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 869,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 869,
              'char' => 70,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 871,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'password',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 871,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 871,
                    'char' => 42,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 871,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 871,
                    'char' => 48,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 871,
                      'char' => 60,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 871,
                    'char' => 60,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 871,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 872,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'password\'] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->passwordField(
     *     [
     *         \'name\' => \'my-field\',
     *         \'size\' => 30,
     *     ]
     * );
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 870,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 870,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 869,
          'last-line' => 894,
          'char' => 19,
        ),
        28 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputRadio',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 895,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 895,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 895,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 897,
                  'char' => 21,
                ),
                'name' => 'renderInputChecked',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'radio',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 897,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 897,
                    'char' => 46,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 897,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 897,
                    'char' => 52,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 897,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 897,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 897,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 898,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="radio"] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputRadio(
     *     [
     *         \'name\'  => \'weather\',
     *         \'value" => \'hot\',
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ input_radio([\'name\': \'weather\', \'value": \'hot\']) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 896,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 896,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 895,
          'last-line' => 902,
          'char' => 19,
        ),
        29 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputRange',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 903,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 903,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 903,
              'char' => 67,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 905,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'range',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 905,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 905,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 905,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 905,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 905,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 905,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 905,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 906,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Builds a HTML input[type=\'range\'] tag
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 904,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 904,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 903,
          'last-line' => 910,
          'char' => 19,
        ),
        30 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputSearch',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 911,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 911,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 911,
              'char' => 68,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 913,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'search',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 913,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 913,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 913,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 913,
                    'char' => 46,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 913,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 913,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 913,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 914,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'search\'] tag
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 912,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 912,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 911,
          'last-line' => 918,
          'char' => 19,
        ),
        31 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputTel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 919,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 919,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 919,
              'char' => 65,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 921,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'tel',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 921,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 921,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 921,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 921,
                    'char' => 43,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 921,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 921,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 921,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 922,
              'char' => 5,
            ),
          ),
          'docblock' => '**
    * Builds a HTML input[type=\'tel\'] tag
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 920,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 920,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 919,
          'last-line' => 939,
          'char' => 19,
        ),
        32 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputText',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 940,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 940,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 940,
              'char' => 66,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 942,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'text',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 942,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 942,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 942,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 942,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 942,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 942,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 942,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 943,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'text\'] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->inputText(
     *     [
     *         \'name\' => \'my-field\',
     *         \'size\' => 30,
     *     ]
     * );
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 941,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 941,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 940,
          'last-line' => 947,
          'char' => 19,
        ),
        33 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputTime',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 948,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 948,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 948,
              'char' => 66,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 950,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'time',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 950,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 950,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 950,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 950,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 950,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 950,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 950,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 951,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'time\'] tag
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 949,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 949,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 948,
          'last-line' => 955,
          'char' => 19,
        ),
        34 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputUrl',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 956,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 956,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 956,
              'char' => 65,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 958,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'url',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 958,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 958,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 958,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 958,
                    'char' => 43,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 958,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 958,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 958,
                'char' => 56,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 959,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'url\'] tag
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 957,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 957,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 956,
          'last-line' => 963,
          'char' => 19,
        ),
        35 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'inputWeek',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 964,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 964,
                'char' => 66,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 964,
              'char' => 66,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 966,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'week',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 966,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 966,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 966,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 966,
                    'char' => 44,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 966,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 966,
                    'char' => 56,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 966,
                'char' => 57,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 967,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type=\'week\'] tag
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 965,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 965,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 964,
          'last-line' => 995,
          'char' => 19,
        ),
        36 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'javascript',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'url',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 996,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 996,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 996,
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
                  'variable' => 'service',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 998,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 998,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 999,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'local',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 999,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1001,
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
                  'variable' => 'local',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'bool',
                    'right' => 
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
                            'value' => 'parameters',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1001,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1001,
                          'char' => 47,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'local',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1001,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1001,
                          'char' => 54,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1001,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1001,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1001,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1001,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1001,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1006,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'local',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1006,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'service',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1007,
                          'char' => 42,
                        ),
                        'name' => 'getService',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'url',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1007,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1007,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1007,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1007,
                      'char' => 58,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parameters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1008,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'service',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1008,
                          'char' => 43,
                        ),
                        'name' => 'getStatic',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'url',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1008,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1008,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1008,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1008,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1009,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parameters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1010,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'url',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1010,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1010,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1011,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1013,
              'char' => 13,
            ),
            4 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1013,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'local',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1013,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1013,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1015,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1015,
                      'char' => 28,
                    ),
                  ),
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1015,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1015,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1015,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1015,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'text/javascript',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1015,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1015,
                        'char' => 74,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1015,
                    'char' => 75,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1015,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1017,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'greater-equal',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1017,
                      'char' => 17,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'docType',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1017,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1017,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1017,
                      'char' => 41,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'HTML5',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1017,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1017,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1017,
                  'char' => 41,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'string',
                    'value' => 'text/javascript',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1017,
                    'char' => 60,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1017,
                      'char' => 72,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1017,
                      'char' => 77,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1017,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1017,
                  'char' => 79,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1017,
                'char' => 79,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameters',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1018,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'type',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1018,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1018,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1018,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1019,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1021,
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
                  'variable' => 'output',
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
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1021,
                          'char' => 27,
                        ),
                        'name' => 'renderAttributes',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '<script',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1021,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1021,
                            'char' => 52,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1021,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1021,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1021,
                        'char' => 66,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '></script>',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1021,
                        'char' => 78,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1021,
                      'char' => 78,
                    ),
                    'right' => 
                    array (
                      'type' => 'constant',
                      'value' => 'PHP_EOL',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1021,
                      'char' => 87,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1021,
                    'char' => 87,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1021,
                  'char' => 87,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1023,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1023,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1025,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a script[type="javascript"] tag
     *
     * Parameters
     * `local` Local resource or not (default `true`)
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->javascript(
     *     \'http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js\',
     *        [
     *         \'local\' => false,
     *     ]
     * );
     *
     * echo $tag->javascript(\'javascript/jquery.js\');
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ javascript(\'http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js\', [\'local\': false]) }}{% endraw %}
     * {% raw %}{{ javascript(\'javascript/jquery.js\') }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 997,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 997,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 996,
          'last-line' => 1065,
          'char' => 19,
        ),
        37 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'link',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'url',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1066,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1066,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1066,
              'char' => 52,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1066,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1066,
              'char' => 75,
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
                  'variable' => 'local',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1068,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'query',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1068,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1068,
                  'char' => 33,
                ),
                3 => 
                array (
                  'variable' => 'service',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1068,
                  'char' => 42,
                ),
                4 => 
                array (
                  'variable' => 'text',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1068,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1070,
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
                  'variable' => 'service',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1070,
                      'char' => 28,
                    ),
                    'name' => 'getService',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'url',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1070,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1070,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1070,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1070,
                  'char' => 44,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'url',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1071,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1071,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'url',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1071,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1071,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'url',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1071,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1071,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1071,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1071,
                  'char' => 53,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'text',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1072,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1072,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'text',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1072,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1072,
                        'char' => 48,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1072,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1072,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1072,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1072,
                  'char' => 55,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'local',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1073,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1073,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'local',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1073,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1073,
                        'char' => 49,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1073,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1073,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1073,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1073,
                  'char' => 56,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'query',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1074,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1074,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'query',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1074,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1074,
                        'char' => 49,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1074,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1074,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1074,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1074,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1076,
              'char' => 13,
            ),
            2 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1076,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'url',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1076,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1076,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1077,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1077,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'local',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1077,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1077,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1078,
              'char' => 13,
            ),
            4 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1078,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'text',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1078,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1078,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1079,
              'char' => 13,
            ),
            5 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1079,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'query',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1079,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1079,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1081,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'href',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1081,
                      'char' => 28,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'service',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1081,
                      'char' => 40,
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
                          'value' => 'url',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1081,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1081,
                        'char' => 48,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'query',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1081,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1081,
                        'char' => 55,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'local',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1081,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1081,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1081,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1081,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1083,
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
                  'variable' => 'output',
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1083,
                            'char' => 27,
                          ),
                          'name' => 'renderAttributes',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '<a',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1083,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1083,
                              'char' => 47,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1083,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1083,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1083,
                          'char' => 61,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '>',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1083,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1083,
                        'char' => 65,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'text',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1083,
                        'char' => 72,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1083,
                      'char' => 72,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</a>',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1083,
                      'char' => 78,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1083,
                    'char' => 78,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1083,
                  'char' => 78,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1085,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1085,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1086,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML A tag using framework conventions
     *
     * Parameters
     * `local` Local resource or not (default `true`)
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->link(\'signup/register\', \'Register Here!\');
     *
     * echo $tag->link(
     *     \'signup/register\',
     *     \'Register Here!\',
     *     [
     *         \'class\' => \'btn-primary\',
     *     ]
     * );
     *
     * echo $tag->link(
     *     \'https://phalconphp.com/\',
     *     \'Phalcon!\',
     *     [
     *         \'local\' => false,
     *     ]
     * );
     *
     * echo $tag->link(
     *     \'https://phalconphp.com/\',
     *     \'Phalcon!\',
     *     [
     *         \'local\'  => false,
     *         \'target\' => \'_new\',
     *     ]
     * );
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1067,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1067,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1066,
          'last-line' => 1090,
          'char' => 19,
        ),
        38 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'prependTitle',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'title',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1091,
              'char' => 43,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'title',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1093,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1093,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1093,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1093,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'prepend',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'title',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1094,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1094,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1095,
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
                      'property' => 'prepend',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'title',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1096,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1096,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1096,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1097,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1099,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1099,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1100,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Prepends a text to current document title
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
                  'value' => 'Tag',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1092,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1092,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1092,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1091,
          'last-line' => 1125,
          'char' => 19,
        ),
        39 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'renderTitle',
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
                'value' => 'true',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1126,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1126,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'append',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1126,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1126,
              'char' => 72,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
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
                      'type' => 'string',
                      'value' => '<title>',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1128,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1128,
                        'char' => 31,
                      ),
                      'name' => 'getTitle',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'prepend',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1128,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1128,
                          'char' => 48,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'append',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1128,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1128,
                          'char' => 56,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1128,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1128,
                    'char' => 58,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => '</title>',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1128,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1128,
                  'char' => 69,
                ),
                'right' => 
                array (
                  'type' => 'constant',
                  'value' => 'PHP_EOL',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1128,
                  'char' => 78,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1128,
                'char' => 78,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders the title with title tags. The title is automaticall escaped
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * $tag
     *        ->setTitleSeparator(\' \')
     *         ->prependTitle([\'Hello\'])
     *         ->setTitle(\'World\')
     *         ->appendTitle([\'from Phalcon\']);
     *
     * echo $tag->renderTitle();             // <title>Hello World from Phalcon</title>
     * echo $tag->renderTitle(false);        // <title>World from Phalcon</title>
     * echo $tag->renderTitle(true, false);  // <title>Hello World</title>
     * echo $tag->renderTitle(false, false); // <title>World</title>
     * ```
     *
     * ```php
     * {% raw %}{{ render_title() }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1127,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1127,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1126,
          'last-line' => 1146,
          'char' => 19,
        ),
        40 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1147,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1147,
                'char' => 62,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1147,
              'char' => 62,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1149,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'reset',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1149,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1149,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1149,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1149,
                    'char' => 45,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1149,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1149,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1149,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1150,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="reset"] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->reset(\'Reset\')
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ reset(\'Save\') }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1148,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1148,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1147,
          'last-line' => 1197,
          'char' => 19,
        ),
        41 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'select',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1198,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1198,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1198,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1198,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1198,
              'char' => 76,
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
                  'variable' => 'emptyText',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1200,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'emptyValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1200,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'id',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1200,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1200,
                  'char' => 46,
                ),
                4 => 
                array (
                  'variable' => 'outputEmpty',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1200,
                  'char' => 59,
                ),
                5 => 
                array (
                  'variable' => 'useEmpty',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1200,
                  'char' => 69,
                ),
                6 => 
                array (
                  'variable' => 'using',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1200,
                  'char' => 76,
                ),
                7 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1200,
                  'char' => 83,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1202,
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
                  'variable' => 'id',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1202,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1202,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1202,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1202,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1202,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1202,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1202,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1202,
                  'char' => 64,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'name',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1203,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1203,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1203,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1203,
                        'char' => 59,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1203,
                          'char' => 65,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1203,
                        'char' => 65,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1203,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1203,
                  'char' => 66,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'useEmpty',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1204,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1204,
                        'char' => 53,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'useEmpty',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1204,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1204,
                        'char' => 63,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1204,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1204,
                        'char' => 70,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1204,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1204,
                  'char' => 71,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'using',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1205,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1205,
                  'char' => 36,
                ),
                4 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1206,
                      'char' => 28,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1206,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1206,
                  'char' => 36,
                ),
                5 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'id',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1207,
                      'char' => 26,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'id',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1207,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1207,
                  'char' => 34,
                ),
                6 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'outputEmpty',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1208,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1208,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1213,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1213,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1213,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1213,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1213,
                      'char' => 45,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1213,
                        'char' => 54,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1213,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1213,
                      'char' => 62,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1213,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1213,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1213,
                'char' => 64,
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
                          'value' => 'The dataset must be either an array or a ResultsetInterface',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1216,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1216,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1216,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1217,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1222,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'data',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1222,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1222,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1222,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1222,
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
                      'variable' => 'using',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1224,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1224,
                            'char' => 27,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'using',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1225,
                              'char' => 22,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1225,
                            'char' => 22,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'empty-array',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1227,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1227,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1227,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1227,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1229,
                  'char' => 14,
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
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'using',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1229,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1229,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'array',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1229,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1229,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'identical',
                      'left' => 
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
                              'value' => 'using',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1229,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1229,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1229,
                        'char' => 57,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '2',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1229,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1229,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1229,
                    'char' => 61,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'unset',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1230,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'using',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1230,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1230,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1231,
                      'char' => 13,
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
                              'value' => 'The \'using\' parameter is not a valid array',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1234,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1234,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1234,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1235,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1236,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1241,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'useEmpty',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1241,
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
                      'operator' => 'assign',
                      'variable' => 'emptyText',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1242,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1242,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'emptyText',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1242,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1242,
                            'char' => 61,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'Choose...',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1242,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1242,
                            'char' => 72,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1242,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1242,
                      'char' => 73,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'emptyValue',
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
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1243,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1243,
                            'char' => 50,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'emptyValue',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1243,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1243,
                            'char' => 62,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1243,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1243,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1243,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1243,
                      'char' => 65,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'outputEmpty',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'sprintf',
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
                                'type' => 'string',
                                'value' => '\\t<option value=\\"%s\\">%s</option>',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1245,
                                'char' => 56,
                              ),
                              'right' => 
                              array (
                                'type' => 'constant',
                                'value' => 'PHP_EOL',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1245,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1245,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1245,
                            'char' => 65,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'emptyValue',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1246,
                              'char' => 31,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1246,
                            'char' => 31,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'emptyText',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1248,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1248,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1248,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1248,
                      'char' => 18,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1250,
                  'char' => 17,
                ),
                1 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1250,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'useEmpty',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1250,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1250,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1251,
                  'char' => 17,
                ),
                2 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1251,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'emptyText',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1251,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1251,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1252,
                  'char' => 17,
                ),
                3 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1252,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'emptyValue',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1252,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1252,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1253,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1255,
              'char' => 10,
            ),
            5 => 
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
                    'value' => 'value',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1255,
                    'char' => 44,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1255,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1255,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1255,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1255,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1255,
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
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1256,
                          'char' => 30,
                        ),
                        'name' => 'getValue',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'id',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1256,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1256,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1256,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1256,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1256,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1256,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1257,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1258,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1258,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1258,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1259,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1261,
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
                  'variable' => 'output',
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1261,
                            'char' => 27,
                          ),
                          'name' => 'renderAttributes',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '<select',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1261,
                                'char' => 52,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1261,
                              'char' => 52,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1261,
                                'char' => 64,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1261,
                              'char' => 64,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1261,
                          'char' => 66,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '>',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1261,
                          'char' => 70,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1261,
                        'char' => 70,
                      ),
                      'right' => 
                      array (
                        'type' => 'constant',
                        'value' => 'PHP_EOL',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1262,
                        'char' => 20,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1262,
                      'char' => 20,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'outputEmpty',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1262,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1262,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1262,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1264,
              'char' => 10,
            ),
            7 => 
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
                    'value' => 'data',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1264,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1264,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1264,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1264,
                'char' => 34,
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
                      'variable' => 'output',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1268,
                          'char' => 31,
                        ),
                        'name' => 'renderSelectResultset',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'data',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1268,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1268,
                            'char' => 58,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'using',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1268,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1268,
                            'char' => 65,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1268,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1268,
                            'char' => 72,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => '</option>',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1268,
                                'char' => 84,
                              ),
                              'right' => 
                              array (
                                'type' => 'constant',
                                'value' => 'PHP_EOL',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1268,
                                'char' => 93,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1268,
                              'char' => 93,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1268,
                            'char' => 93,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1268,
                        'char' => 94,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1268,
                      'char' => 94,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1269,
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
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1269,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1269,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1269,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1269,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1273,
                              'char' => 31,
                            ),
                            'name' => 'renderSelectArray',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'data',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1273,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1273,
                                'char' => 54,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1273,
                                  'char' => 61,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1273,
                                'char' => 61,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '</option>',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1273,
                                    'char' => 73,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'constant',
                                    'value' => 'PHP_EOL',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1273,
                                    'char' => 82,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1273,
                                  'char' => 82,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1273,
                                'char' => 82,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1273,
                            'char' => 83,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1273,
                          'char' => 83,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1274,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1274,
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
                          'value' => 'Invalid data provided to SELECT helper',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1275,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1275,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1275,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1276,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1278,
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
                  'operator' => 'concat-assign',
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '</select>',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1278,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1278,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1280,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1280,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1281,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a select element. It accepts an array or a resultset from
     * a Phalcon\\Mvc\\Model
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->select(
     *     \'status\',
     *     [
     *         \'id\'        => \'status-id\',
     *         \'useEmpty\'  => true,
     *         \'emptyValue => \'\',
     *         \'emptyText\' => \'Choose Status...\',
     *     ],
     *     [
     *         \'A\' => \'Active\',
     *         \'I\' => \'Inactive\',
     *     ]
     * );
     *
     * echo $tag->select(
     *     \'status\',
     *     [
     *         \'id\'        => \'status-id\',
     *         \'useEmpty\'  => true,
     *         \'emptyValue => \'\',
     *         \'emptyText\' => \'Choose Type...\',
     *         \'using\'     => [
     *             \'id,
     *             \'name\',
     *         ],
     *     ],
     *     Robots::find(
     *         [
     *             \'conditions\' => \'type = :type:\',
     *             \'bind\'       => [
     *                 \'type\' => \'mechanical\',
     *             ]
     *         ]
     *     )
     * );
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1199,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1199,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1198,
          'last-line' => 1297,
          'char' => 19,
        ),
        42 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAttribute',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1298,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1298,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1300,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1300,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1300,
                'char' => 27,
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
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1301,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1301,
                            'char' => 40,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1301,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1301,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1301,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1301,
                            'char' => 65,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1301,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1301,
                          'char' => 73,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1301,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1301,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1301,
                    'char' => 75,
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
                              'value' => 'Only scalar values can be assigned to UI components',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1304,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1304,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1304,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1305,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1306,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1308,
              'char' => 11,
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
                  'property' => 'values',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1308,
                      'char' => 30,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1308,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1308,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1310,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1310,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1311,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Assigns default values to generated tags by helpers
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * // Assigning \'peter\' to \'name\' component
     * $tag->setAttribute(\'name\', \'peter\');
     *
     * // Later in the view
     * echo $tag->inputText(\'name\'); // Will have the value \'peter\' by default
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
                  'value' => 'Tag',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1299,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1299,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1299,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1298,
          'last-line' => 1331,
          'char' => 19,
        ),
        43 => 
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
              'name' => 'values',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1332,
              'char' => 48,
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1332,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1332,
              'char' => 68,
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1334,
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
                      'property' => 'values',
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
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1335,
                                'char' => 49,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'values',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1335,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1335,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1335,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'values',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1335,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1335,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1335,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1335,
                      'char' => 65,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1336,
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
                      'property' => 'values',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'values',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1337,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1337,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1338,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1340,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1340,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1341,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Assigns default values to generated tags by helpers
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * // Assigning \'peter\' to \'name\' component
     * $tag->setAttribute(
     *     [
     *         \'name\' => \'peter\',
     *     ]
     * );
     *
     * // Later in the view
     * echo $tag->inputText(\'name\'); // Will have the value \'peter\' by default
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
                  'value' => 'Tag',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1333,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1333,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1333,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1332,
          'last-line' => 1345,
          'char' => 19,
        ),
        44 => 
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1346,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1346,
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
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1348,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1348,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1349,
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
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1347,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1346,
          'last-line' => 1353,
          'char' => 19,
        ),
        45 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDocType',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'doctype',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1354,
              'char' => 43,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'list',
                'left' => 
                array (
                  'type' => 'or',
                  'left' => 
                  array (
                    'type' => 'less',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'doctype',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1356,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1356,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'HTML32',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1356,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1356,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1356,
                    'char' => 37,
                  ),
                  'right' => 
                  array (
                    'type' => 'greater',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'doctype',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1356,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1356,
                        'char' => 61,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'XHTML5',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1356,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1356,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1356,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1356,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1356,
                'char' => 63,
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
                      'property' => 'docType',
                      'expr' => 
                      array (
                        'type' => 'static-constant-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'self',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1357,
                          'char' => 44,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'HTML5',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1357,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1357,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1357,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1358,
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
                      'property' => 'docType',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'doctype',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1359,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1359,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1360,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1362,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1362,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1363,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the document type of content
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
                  'value' => 'Tag',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1355,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1355,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1355,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1354,
          'last-line' => 1375,
          'char' => 19,
        ),
        46 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTitle',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'title',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1376,
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
                  'property' => 'title',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'title',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1378,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1378,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1380,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1380,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1381,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the title separator of view content
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * $tag->setTitle(\'Phalcon Framework\');
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
                  'value' => 'Tag',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1377,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1377,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1377,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1376,
          'last-line' => 1393,
          'char' => 19,
        ),
        47 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTitleSeparator',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'separator',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1394,
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
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'separator',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'separator',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1396,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1396,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1398,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1398,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1399,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the title separator of view content
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->setTitleSeparator(\'-\');
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
                  'value' => 'Tag',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1395,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1395,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1395,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1394,
          'last-line' => 1427,
          'char' => 19,
        ),
        48 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'stylesheet',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'url',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1428,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1428,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1428,
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
                  'variable' => 'service',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1430,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1430,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1431,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'local',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1431,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1433,
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
                  'variable' => 'local',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'bool',
                    'right' => 
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
                            'value' => 'parameters',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1433,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1433,
                          'char' => 47,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'local',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1433,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1433,
                          'char' => 54,
                        ),
                        2 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1433,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1433,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1433,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1433,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1433,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1435,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1435,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'local',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1435,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1435,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1440,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'local',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1440,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'service',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1441,
                          'char' => 43,
                        ),
                        'name' => 'getService',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'url',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1441,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1441,
                            'char' => 58,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1441,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1441,
                      'char' => 59,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parameters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'href',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1442,
                          'char' => 32,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'service',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1442,
                          'char' => 44,
                        ),
                        'name' => 'getStatic',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'url',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1442,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1442,
                            'char' => 58,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1442,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1442,
                      'char' => 59,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1443,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parameters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'href',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1444,
                          'char' => 32,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'url',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1444,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1444,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1445,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1447,
              'char' => 10,
            ),
            5 => 
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
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1447,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'rel',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1447,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1447,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1447,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1447,
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
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parameters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'rel',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1448,
                          'char' => 31,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'stylesheet',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1448,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1448,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1449,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1451,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1451,
                      'char' => 28,
                    ),
                  ),
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1451,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1451,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1451,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1451,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'text/css',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1451,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1451,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1451,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1451,
                  'char' => 68,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1452,
                        'char' => 39,
                      ),
                      'name' => 'renderAttributes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '<link',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1452,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1452,
                          'char' => 62,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'parameters',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1452,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1452,
                          'char' => 74,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1452,
                      'char' => 76,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1452,
                        'char' => 83,
                      ),
                      'name' => 'renderCloseTag',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1452,
                            'char' => 103,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1452,
                          'char' => 103,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1452,
                      'char' => 104,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1452,
                    'char' => 104,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1452,
                  'char' => 104,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1454,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1454,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1455,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a LINK[rel="stylesheet"] tag
     *
     * Parameters
     * `local` Local resource or not (default `true`)
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->stylesheet(
     *     \'http://fonts.googleapis.com/css?family=Rosario\',
     *     [
     *         \'local\' => false,
     *     ]
     * );
     *
     * echo $tag->stylesheet(\'css/style.css\');
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ stylesheet(\'http://fonts.googleapis.com/css?family=Rosario\', [\'local\': false]) }}{% endraw %}
     * {% raw %}{{ stylesheet(\'css/style.css\') }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1429,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1429,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1428,
          'last-line' => 1472,
          'char' => 19,
        ),
        49 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'submit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1473,
              'char' => 40,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1473,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1473,
              'char' => 63,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1475,
                  'char' => 21,
                ),
                'name' => 'renderInput',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'submit',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1475,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1475,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1475,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1475,
                    'char' => 46,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1475,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1475,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1475,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1476,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML input[type="submit"] tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->submit(\'Save\');
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ submit(\'Save\') }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1474,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1474,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1473,
          'last-line' => 1499,
          'char' => 19,
        ),
        50 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'textArea',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1500,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1500,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1500,
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
                  'variable' => 'content',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1502,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1502,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1504,
              'char' => 11,
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
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'id',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1504,
                      'char' => 26,
                    ),
                  ),
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1504,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1504,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1504,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1504,
                        'char' => 55,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1504,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1504,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1504,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1504,
                  'char' => 62,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1505,
                      'char' => 28,
                    ),
                  ),
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1505,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1505,
                        'char' => 51,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1505,
                          'char' => 57,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1505,
                        'char' => 57,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1505,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1505,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1505,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1505,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1507,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'isset',
                'left' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1507,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'value',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1507,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1507,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1507,
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
                      'variable' => 'content',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1508,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1508,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1508,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1508,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1510,
                  'char' => 17,
                ),
                1 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1510,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1510,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1510,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1511,
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
                      'variable' => 'content',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1512,
                          'char' => 32,
                        ),
                        'name' => 'getValue',
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
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1512,
                                'char' => 52,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'id',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1512,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1512,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1512,
                            'char' => 56,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1512,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1512,
                            'char' => 68,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1512,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1512,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1513,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1516,
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
                  'variable' => 'output',
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
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1516,
                            'char' => 27,
                          ),
                          'name' => 'renderAttributes',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '<textarea',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1516,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1516,
                              'char' => 54,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1516,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1516,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1516,
                          'char' => 68,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '>',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1516,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1516,
                        'char' => 72,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'htmlspecialchars',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'content',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1517,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1517,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1517,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1517,
                      'char' => 48,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '</textarea>',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1517,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1517,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1517,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1519,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1519,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1520,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds a HTML TEXTAREA tag
     *
     * ```php
     * use Phalcon\\Html\\Tag;
     *
     * $tag = new Tag();
     *
     * echo $tag->textArea(
     *     \'comments\',
     *     [
     *         \'cols\' => 10,
     *         \'rows\' => 4,
     *     ]
     * );
     * ```
     *
     * Volt syntax:
     * ```php
     * {% raw %}{{ text_area(\'comments\', [\'cols\': 10, \'rows\': 4]) }}{% endraw %}
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
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1501,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1501,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1500,
          'last-line' => 1524,
          'char' => 19,
        ),
        51 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getService',
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
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1525,
              'char' => 44,
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
                  'variable' => 'service',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1527,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1527,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1529,
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
                  'type' => 'string',
                  'value' => 'escaper',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1529,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1529,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1529,
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
                      'variable' => 'service',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1530,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'escaper',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1530,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1530,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1530,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1531,
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
                      'variable' => 'service',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1532,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'url',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1532,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1532,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1532,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1533,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1535,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'service',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1535,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1535,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1535,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1535,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1536,
                          'char' => 34,
                        ),
                        'name' => 'getDI',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1536,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1536,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1538,
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
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1538,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1538,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1538,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1538,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1538,
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
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Exception',
                              'dynamic' => 0,
                              'name' => 'containerServiceNotFound',
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
                                        'value' => 'the \'',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1541,
                                        'char' => 31,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'name',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1541,
                                        'char' => 38,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1541,
                                      'char' => 38,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\' service',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1542,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1542,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1542,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1543,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1543,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1543,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1544,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1546,
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
                      'value' => 'escaper',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1546,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1546,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1546,
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
                          'variable' => 'service',
                          'expr' => 
                          array (
                            'type' => 'type-hint',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'EscaperInterface',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1547,
                              'char' => 82,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1547,
                                'char' => 66,
                              ),
                              'name' => 'getShared',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'name',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1547,
                                    'char' => 81,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1547,
                                  'char' => 81,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1547,
                              'char' => 82,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1547,
                            'char' => 82,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1547,
                          'char' => 82,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'escaper',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'service',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1548,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1548,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1549,
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
                          'variable' => 'service',
                          'expr' => 
                          array (
                            'type' => 'type-hint',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'UrlInterface',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1550,
                              'char' => 74,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1550,
                                'char' => 58,
                              ),
                              'name' => 'getShared',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'name',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1550,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1550,
                                  'char' => 73,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1550,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1550,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1550,
                          'char' => 74,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'url',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'service',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1551,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1551,
                          'char' => 40,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1552,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1553,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1555,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'service',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1555,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1556,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the escaper service from the DI container
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1525,
          'last-line' => 1560,
          'char' => 20,
        ),
        52 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'renderAttributes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'code',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1561,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1561,
              'char' => 70,
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
                  'variable' => 'attrs',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1563,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'escaper',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1563,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'escaped',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1563,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1563,
                  'char' => 41,
                ),
                4 => 
                array (
                  'variable' => 'newCode',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1563,
                  'char' => 50,
                ),
                5 => 
                array (
                  'variable' => 'intersect',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1563,
                  'char' => 61,
                ),
                6 => 
                array (
                  'variable' => 'order',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1563,
                  'char' => 68,
                ),
                7 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1563,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1565,
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
                  'variable' => 'order',
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
                          'value' => 'rel',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1566,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1566,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1566,
                        'char' => 26,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'type',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1567,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1567,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1567,
                        'char' => 26,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'for',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1568,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1568,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1568,
                        'char' => 26,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'src',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1569,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1569,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1569,
                        'char' => 26,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'href',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1570,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1570,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1570,
                        'char' => 26,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'action',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1571,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1571,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1571,
                        'char' => 26,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1572,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1572,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1572,
                        'char' => 26,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1573,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1573,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1573,
                        'char' => 26,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1574,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1574,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1574,
                        'char' => 26,
                      ),
                      9 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'string',
                          'value' => 'class',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1575,
                          'char' => 20,
                        ),
                        'value' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1576,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1576,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1576,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1576,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1578,
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
                  'variable' => 'intersect',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_intersect_key',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'order',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1578,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1578,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1578,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1578,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1578,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1578,
                  'char' => 63,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'attrs',
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
                          'type' => 'variable',
                          'value' => 'intersect',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1579,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1579,
                        'char' => 46,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'attributes',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1579,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1579,
                        'char' => 58,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1579,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1579,
                  'char' => 59,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'escaper',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1580,
                      'char' => 30,
                    ),
                    'name' => 'getService',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'escaper',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1580,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1580,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1580,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1580,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1582,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'attrs',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1582,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'escape',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1582,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1582,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1584,
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
                  'variable' => 'newCode',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'code',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1584,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1584,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1586,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'attrs',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1586,
                'char' => 33,
              ),
              'key' => 'key',
              'value' => 'value',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
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
                          'value' => 'key',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1587,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1587,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1587,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1587,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1587,
                        'char' => 48,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1587,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1587,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1587,
                    'char' => 55,
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
                          'type' => 'list',
                          'left' => 
                          array (
                            'type' => 'or',
                            'left' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'typeof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1588,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1588,
                                'char' => 44,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'array',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1588,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1588,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'equals',
                              'left' => 
                              array (
                                'type' => 'typeof',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1588,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1588,
                                'char' => 69,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'resource',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1588,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1588,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1588,
                            'char' => 79,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1588,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1588,
                        'char' => 81,
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'string',
                                          'value' => 'Value at index: \'',
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1590,
                                          'char' => 43,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'key',
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1590,
                                          'char' => 49,
                                        ),
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1590,
                                        'char' => 49,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\' type: \'',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1590,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1590,
                                      'char' => 61,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'gettype',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'value',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1590,
                                            'char' => 76,
                                          ),
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1590,
                                          'char' => 76,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1590,
                                      'char' => 78,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1590,
                                    'char' => 78,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '\' cannot be rendered',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1591,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1591,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1591,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1591,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1592,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1594,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'escaper',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1594,
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
                              'variable' => 'escaped',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'escaper',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1595,
                                  'char' => 43,
                                ),
                                'name' => 'escapeHtmlAttr',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'value',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1595,
                                      'char' => 64,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1595,
                                    'char' => 64,
                                  ),
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1595,
                                'char' => 65,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1595,
                              'char' => 65,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1596,
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
                              'variable' => 'escaped',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'value',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1597,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1597,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1598,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1600,
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
                          'operator' => 'concat-assign',
                          'variable' => 'newCode',
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
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'string',
                                    'value' => ' ',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1600,
                                    'char' => 33,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'key',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1600,
                                    'char' => 39,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1600,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'string',
                                  'value' => '=\\"',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1600,
                                  'char' => 45,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1600,
                                'char' => 45,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'escaped',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1600,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1600,
                              'char' => 55,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '\\"',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1600,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1600,
                            'char' => 59,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1600,
                          'char' => 59,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1601,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1602,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1604,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'newCode',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1604,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1605,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders the attributes of an HTML element
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1562,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1562,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1561,
          'last-line' => 1609,
          'char' => 20,
        ),
        53 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'renderCloseTag',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'addEol',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1610,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1610,
              'char' => 56,
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
                  'variable' => 'eol',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1612,
                    'char' => 19,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1612,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1614,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'addEol',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1614,
                'char' => 19,
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
                      'variable' => 'eol',
                      'expr' => 
                      array (
                        'type' => 'constant',
                        'value' => 'PHP_EOL',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1615,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1615,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1616,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1621,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1621,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'docType',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1621,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1621,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'static-constant-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'self',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1621,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'HTML5',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1621,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1621,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1621,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => ' />',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1622,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eol',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1622,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1622,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1623,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'string',
                      'value' => '>',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1624,
                      'char' => 22,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'eol',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1624,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1624,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1625,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1626,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the closing tag depending on the doctype
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1611,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1611,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1610,
          'last-line' => 1630,
          'char' => 20,
        ),
        54 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'renderInput',
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
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1631,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1631,
              'char' => 58,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1631,
                'char' => 81,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1631,
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1633,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'id',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1633,
                  'char' => 21,
                ),
                2 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1633,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1635,
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
                  'variable' => 'id',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1635,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1635,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1635,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1635,
                        'char' => 41,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1635,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1635,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1635,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1635,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1637,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'id',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1637,
                      'char' => 26,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'id',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1637,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1637,
                  'char' => 35,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1638,
                      'char' => 28,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1638,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1638,
                  'char' => 37,
                ),
                2 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1639,
                      'char' => 28,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1639,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1639,
                  'char' => 37,
                ),
                3 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1640,
                      'char' => 29,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1640,
                      'char' => 38,
                    ),
                    'name' => 'getValue',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'id',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1640,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1640,
                        'char' => 50,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1640,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1640,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1640,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1640,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1642,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1642,
                        'char' => 27,
                      ),
                      'name' => 'renderAttributes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '<input',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1642,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1642,
                          'char' => 51,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'parameters',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1642,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1642,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1642,
                      'char' => 65,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1642,
                        'char' => 72,
                      ),
                      'name' => 'renderCloseTag',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1642,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1642,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1642,
                  'char' => 89,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1644,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1644,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1645,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds `input` elements
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1632,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1632,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1631,
          'last-line' => 1648,
          'char' => 20,
        ),
        55 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'renderInputChecked',
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
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1649,
              'char' => 52,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1649,
              'char' => 65,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1649,
                'char' => 88,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1649,
              'char' => 88,
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
                  'variable' => 'currentValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1651,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'id',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1651,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1651,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1651,
                  'char' => 43,
                ),
                4 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1651,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1653,
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
                  'variable' => 'id',
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
                          'value' => 'parameters',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1653,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1653,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'id',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1653,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1653,
                        'char' => 41,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1653,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1653,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1653,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1653,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1658,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'currentValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1658,
                  'char' => 50,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'parameters',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1658,
                    'char' => 42,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'value',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1658,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1658,
                  'char' => 50,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1658,
                'char' => 50,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'unset',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameters',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1659,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'value',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1659,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1659,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1661,
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
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1661,
                          'char' => 30,
                        ),
                        'name' => 'getValue',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'id',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1661,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1661,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1661,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1661,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1661,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1661,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1663,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not-identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1663,
                        'char' => 24,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1663,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1663,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'currentValue',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1663,
                        'char' => 49,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1663,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1663,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1663,
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
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'parameters',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'checked',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1664,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'checked',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1664,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1664,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1665,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1667,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parameters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1667,
                          'char' => 33,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'currentValue',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1667,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1667,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1668,
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
                      'variable' => 'value',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1669,
                          'char' => 30,
                        ),
                        'name' => 'getValue',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'id',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1669,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1669,
                            'char' => 42,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1669,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1669,
                            'char' => 54,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1669,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1669,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1674,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1674,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1674,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1674,
                    'char' => 31,
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
                          'variable' => 'parameters',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'string',
                              'value' => 'checked',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1675,
                              'char' => 39,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'checked',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1675,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1675,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1676,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1681,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'parameters',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'value',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1681,
                          'char' => 33,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1681,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1681,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1682,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1684,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'id',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1684,
                      'char' => 26,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'id',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1684,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1684,
                  'char' => 35,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'name',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1685,
                      'char' => 28,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1685,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1685,
                  'char' => 37,
                ),
                2 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'type',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1686,
                      'char' => 28,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'type',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1686,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1686,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1688,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1688,
                        'char' => 27,
                      ),
                      'name' => 'renderAttributes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => '<input',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1688,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1688,
                          'char' => 51,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'parameters',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1688,
                            'char' => 63,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1688,
                          'char' => 63,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1688,
                      'char' => 65,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1688,
                        'char' => 72,
                      ),
                      'name' => 'renderCloseTag',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1688,
                      'char' => 89,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1688,
                    'char' => 89,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1688,
                  'char' => 89,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1690,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1690,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1691,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Builds INPUT tags that implements the checked attribute
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1650,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1650,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1649,
          'last-line' => 1695,
          'char' => 20,
        ),
        56 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'renderSelectArray',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1696,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1696,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'closeOption',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1696,
              'char' => 84,
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
                  'variable' => 'label',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1698,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'strOptionValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1698,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'strValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1698,
                  'char' => 44,
                ),
                3 => 
                array (
                  'variable' => 'optionText',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1698,
                  'char' => 56,
                ),
                4 => 
                array (
                  'variable' => 'optionValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1698,
                  'char' => 69,
                ),
                5 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1698,
                  'char' => 77,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1700,
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
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1700,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1700,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1702,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'options',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1702,
                'char' => 48,
              ),
              'key' => 'optionValue',
              'value' => 'optionText',
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
                      'variable' => 'label',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'htmlspecialchars',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'optionValue',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1703,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1703,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1703,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1703,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1708,
                  'char' => 15,
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
                        'value' => 'optionText',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1708,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1708,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1708,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1708,
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
                          'operator' => 'concat-assign',
                          'variable' => 'output',
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
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\t<optgroup label=\\"',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1709,
                                        'char' => 51,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'label',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1709,
                                        'char' => 59,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1709,
                                      'char' => 59,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1709,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1709,
                                    'char' => 65,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'constant',
                                    'value' => 'PHP_EOL',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1710,
                                    'char' => 29,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1710,
                                  'char' => 29,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1710,
                                    'char' => 36,
                                  ),
                                  'name' => 'renderSelectArray',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1710,
                                        'char' => 65,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1710,
                                      'char' => 65,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'value',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1710,
                                        'char' => 72,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1710,
                                      'char' => 72,
                                    ),
                                    2 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'closeOption',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1710,
                                        'char' => 85,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1710,
                                      'char' => 85,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1710,
                                  'char' => 87,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1710,
                                'char' => 87,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\\t</optgroup>',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1710,
                                'char' => 103,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1710,
                              'char' => 103,
                            ),
                            'right' => 
                            array (
                              'type' => 'constant',
                              'value' => 'PHP_EOL',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1710,
                              'char' => 112,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1710,
                            'char' => 112,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1710,
                          'char' => 112,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1712,
                      'char' => 24,
                    ),
                    1 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1713,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1715,
                  'char' => 15,
                ),
                2 => 
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
                        'value' => 'value',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1715,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1715,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1715,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1715,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
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
                              'value' => 'optionValue',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1716,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1716,
                            'char' => 40,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1716,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1716,
                            'char' => 47,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1716,
                        'char' => 49,
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
                              'variable' => 'output',
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\t<option selected=\\"selected\\" value=\\"',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1717,
                                        'char' => 75,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'label',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1717,
                                        'char' => 83,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1717,
                                      'char' => 83,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1718,
                                      'char' => 33,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1718,
                                    'char' => 33,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'optionText',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1718,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1718,
                                  'char' => 46,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'closeOption',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1718,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1718,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1718,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1719,
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
                                'type' => 'concat',
                                'left' => 
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
                                        'type' => 'string',
                                        'value' => '\\t<option value=\\"',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1720,
                                        'char' => 53,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'label',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1720,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1720,
                                      'char' => 61,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1720,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1720,
                                    'char' => 67,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'optionText',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1720,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1720,
                                  'char' => 80,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'closeOption',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1720,
                                  'char' => 93,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1720,
                                'char' => 93,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1720,
                              'char' => 93,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1721,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1722,
                      'char' => 14,
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
                          'variable' => 'strOptionValue',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'string',
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'optionValue',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1723,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1723,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1723,
                          'char' => 58,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'strValue',
                          'expr' => 
                          array (
                            'type' => 'cast',
                            'left' => 'string',
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'value',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1724,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1724,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1724,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1726,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'strOptionValue',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1726,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'strValue',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1726,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1726,
                        'char' => 48,
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
                              'variable' => 'output',
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
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '\\t<option selected=\\"selected\\" value=\\"',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1727,
                                        'char' => 75,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'label',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1727,
                                        'char' => 83,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1727,
                                      'char' => 83,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1728,
                                      'char' => 33,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1728,
                                    'char' => 33,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'optionText',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1728,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1728,
                                  'char' => 46,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'closeOption',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1728,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1728,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1728,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1729,
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
                                'type' => 'concat',
                                'left' => 
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
                                        'type' => 'string',
                                        'value' => '\\t<option value=\\"',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1730,
                                        'char' => 53,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'label',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1730,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1730,
                                      'char' => 61,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '\\">',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1730,
                                      'char' => 67,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1730,
                                    'char' => 67,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'optionText',
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1730,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1730,
                                  'char' => 80,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'closeOption',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1730,
                                  'char' => 93,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1730,
                                'char' => 93,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1730,
                              'char' => 93,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1731,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1732,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1733,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1735,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1735,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1736,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates the option values or optgroup from an array
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1697,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1697,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1696,
          'last-line' => 1740,
          'char' => 20,
        ),
        57 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'renderSelectResultset',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'resultset',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ResulsetInterface',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1741,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1741,
              'char' => 73,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'using',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1741,
              'char' => 80,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1741,
              'char' => 91,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'closeOption',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1741,
              'char' => 111,
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
                  'variable' => 'escaper',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1743,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'option',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1743,
                  'char' => 28,
                ),
                2 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1743,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'optionValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1743,
                  'char' => 49,
                ),
                4 => 
                array (
                  'variable' => 'optionText',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1743,
                  'char' => 61,
                ),
                5 => 
                array (
                  'variable' => 'parameters',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1743,
                  'char' => 73,
                ),
                6 => 
                array (
                  'variable' => 'strOptionValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1744,
                  'char' => 27,
                ),
                7 => 
                array (
                  'variable' => 'strValue',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1744,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1746,
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
                  'variable' => 'escaper',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1746,
                      'char' => 31,
                    ),
                    'name' => 'getService',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'escaper',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1746,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1746,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1746,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1746,
                  'char' => 51,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'parameters',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1747,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1747,
                  'char' => 28,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'output',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1748,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1748,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1754,
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
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'using',
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1754,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1754,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1754,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1754,
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
                      'variable' => 'optionValue',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'using',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1755,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1755,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1755,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1755,
                      'char' => 39,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'optionText',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'using',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1756,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1756,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1756,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1756,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1757,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1759,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'iterator',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'resultset',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1759,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1759,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1759,
                'char' => 43,
              ),
              'value' => 'option',
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
                        'type' => 'variable',
                        'value' => 'using',
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1761,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1761,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'array',
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1761,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Tag.zep',
                    'line' => 1761,
                    'char' => 38,
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
                            'value' => 'option',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1762,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1762,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1762,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1762,
                        'char' => 44,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'method_exists',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'option',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1763,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1763,
                                'char' => 44,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'readAttribute',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1763,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1763,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1763,
                            'char' => 61,
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
                                  'variable' => 'optionValue',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'option',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1764,
                                      'char' => 50,
                                    ),
                                    'name' => 'readAttribute',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'optionValue',
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1764,
                                          'char' => 76,
                                        ),
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1764,
                                        'char' => 76,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1764,
                                    'char' => 77,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1764,
                                  'char' => 77,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'optionText',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'option',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1765,
                                      'char' => 50,
                                    ),
                                    'name' => 'readAttribute',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'optionText',
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1765,
                                          'char' => 75,
                                        ),
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1765,
                                        'char' => 75,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1765,
                                    'char' => 76,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1765,
                                  'char' => 76,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1766,
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
                                  'variable' => 'optionValue',
                                  'expr' => 
                                  array (
                                    'type' => 'property-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'option',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1767,
                                      'char' => 50,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'optionValue',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1767,
                                      'char' => 62,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1767,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1767,
                                  'char' => 62,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'optionText',
                                  'expr' => 
                                  array (
                                    'type' => 'property-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'option',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1768,
                                      'char' => 50,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'optionText',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1768,
                                      'char' => 61,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1768,
                                    'char' => 61,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1768,
                                  'char' => 61,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1769,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1770,
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
                                  'value' => 'option',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1771,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1771,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'array',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1771,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1771,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1771,
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
                                      'type' => 'string',
                                      'value' => 'Resultset returned an invalid value',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1774,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1774,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1774,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1775,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1777,
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
                              'variable' => 'optionValue',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'option',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1777,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'optionValue',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1777,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1777,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1777,
                              'char' => 58,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'optionText',
                              'expr' => 
                              array (
                                'type' => 'array-access',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'option',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1778,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'optionText',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1778,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1778,
                                'char' => 57,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1778,
                              'char' => 57,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1779,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1781,
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
                          'variable' => 'optionValue',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'escaper',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1781,
                              'char' => 43,
                            ),
                            'name' => 'escapeHtmlAttr',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'optionValue',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1781,
                                  'char' => 70,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1781,
                                'char' => 70,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1781,
                            'char' => 71,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1781,
                          'char' => 71,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1782,
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
                          'variable' => 'optionText',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'escaper',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1782,
                              'char' => 43,
                            ),
                            'name' => 'escapeHtml',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'optionText',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1782,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1782,
                                'char' => 65,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1782,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1782,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1787,
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
                            'value' => 'value',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1787,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1787,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1787,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1787,
                        'char' => 42,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
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
                                  'value' => 'optionValue',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1788,
                                  'char' => 44,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1788,
                                'char' => 44,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1788,
                                  'char' => 51,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1788,
                                'char' => 51,
                              ),
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1788,
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
                                  'assign-type' => 'variable',
                                  'operator' => 'concat-assign',
                                  'variable' => 'output',
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\\t<option selected=\\"selected\\" value=\\"',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1789,
                                            'char' => 79,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'optionValue',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1789,
                                            'char' => 93,
                                          ),
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1789,
                                          'char' => 93,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\">',
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1790,
                                          'char' => 37,
                                        ),
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1790,
                                        'char' => 37,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1790,
                                        'char' => 50,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1790,
                                      'char' => 50,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'closeOption',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1790,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1790,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1790,
                                  'char' => 63,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1791,
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
                                  'operator' => 'concat-assign',
                                  'variable' => 'output',
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\\t<option value=\\"',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1792,
                                            'char' => 57,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'optionValue',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1792,
                                            'char' => 71,
                                          ),
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1792,
                                          'char' => 71,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\">',
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1792,
                                          'char' => 77,
                                        ),
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1792,
                                        'char' => 77,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1792,
                                        'char' => 90,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1792,
                                      'char' => 90,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'closeOption',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1792,
                                      'char' => 103,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1792,
                                    'char' => 103,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1792,
                                  'char' => 103,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1793,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1794,
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
                              'variable' => 'strOptionValue',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'string',
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'optionValue',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1795,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1795,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1795,
                              'char' => 62,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'strValue',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'string',
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'value',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1796,
                                  'char' => 56,
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1796,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1796,
                              'char' => 56,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1797,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'identical',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'strOptionValue',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1797,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'strValue',
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1797,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1797,
                            'char' => 52,
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
                                  'variable' => 'output',
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\\t<option selected=\\"selected\\" value=\\"',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1798,
                                            'char' => 79,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'strOptionValue',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1798,
                                            'char' => 96,
                                          ),
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1798,
                                          'char' => 96,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\">',
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1799,
                                          'char' => 37,
                                        ),
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1799,
                                        'char' => 37,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1799,
                                        'char' => 50,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1799,
                                      'char' => 50,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'closeOption',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1799,
                                      'char' => 63,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1799,
                                    'char' => 63,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1799,
                                  'char' => 63,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1800,
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
                                  'operator' => 'concat-assign',
                                  'variable' => 'output',
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
                                          'type' => 'concat',
                                          'left' => 
                                          array (
                                            'type' => 'string',
                                            'value' => '\\t<option value=\\"',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1801,
                                            'char' => 57,
                                          ),
                                          'right' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'strOptionValue',
                                            'file' => '/app/phalcon/Html/Tag.zep',
                                            'line' => 1801,
                                            'char' => 74,
                                          ),
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1801,
                                          'char' => 74,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '\\">',
                                          'file' => '/app/phalcon/Html/Tag.zep',
                                          'line' => 1801,
                                          'char' => 80,
                                        ),
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1801,
                                        'char' => 80,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'optionText',
                                        'file' => '/app/phalcon/Html/Tag.zep',
                                        'line' => 1801,
                                        'char' => 93,
                                      ),
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1801,
                                      'char' => 93,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'closeOption',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1801,
                                      'char' => 106,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1801,
                                    'char' => 106,
                                  ),
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1801,
                                  'char' => 106,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1802,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1803,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1804,
                      'char' => 13,
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
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'using',
                            'file' => '/app/phalcon/Html/Tag.zep',
                            'line' => 1809,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1809,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1809,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Html/Tag.zep',
                        'line' => 1809,
                        'char' => 43,
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
                              'variable' => 'parameters',
                              'index-expr' => 
                              array (
                                0 => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Html/Tag.zep',
                                  'line' => 1810,
                                  'char' => 37,
                                ),
                              ),
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'option',
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1810,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1810,
                              'char' => 47,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'concat-assign',
                              'variable' => 'output',
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
                                      'value' => 'using',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1811,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1811,
                                    'char' => 66,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'parameters',
                                      'file' => '/app/phalcon/Html/Tag.zep',
                                      'line' => 1811,
                                      'char' => 78,
                                    ),
                                    'file' => '/app/phalcon/Html/Tag.zep',
                                    'line' => 1811,
                                    'char' => 78,
                                  ),
                                ),
                                'file' => '/app/phalcon/Html/Tag.zep',
                                'line' => 1811,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Html/Tag.zep',
                              'line' => 1811,
                              'char' => 79,
                            ),
                          ),
                          'file' => '/app/phalcon/Html/Tag.zep',
                          'line' => 1812,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Html/Tag.zep',
                      'line' => 1813,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Tag.zep',
                  'line' => 1814,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1816,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'output',
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1816,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Html/Tag.zep',
              'line' => 1817,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates the option values from a resultset
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
                'file' => '/app/phalcon/Html/Tag.zep',
                'line' => 1742,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 1742,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 1741,
          'last-line' => 1818,
          'char' => 20,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'HTML32',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 77,
            'char' => 35,
          ),
          'docblock' => '**
     * Constants
     *',
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 78,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'HTML401_STRICT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 78,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 79,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'HTML401_TRANSITIONAL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 79,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 80,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'HTML401_FRAMESET',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 80,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 81,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'HTML5',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 81,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 82,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'XHTML10_STRICT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '6',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 82,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 83,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'XHTML10_TRANSITIONAL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '7',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 83,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 84,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'XHTML10_FRAMESET',
          'default' => 
          array (
            'type' => 'int',
            'value' => '8',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 84,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 85,
          'char' => 9,
        ),
        8 => 
        array (
          'type' => 'const',
          'name' => 'XHTML11',
          'default' => 
          array (
            'type' => 'int',
            'value' => '9',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 85,
            'char' => 35,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 86,
          'char' => 9,
        ),
        9 => 
        array (
          'type' => 'const',
          'name' => 'XHTML20',
          'default' => 
          array (
            'type' => 'int',
            'value' => '10',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 86,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 87,
          'char' => 9,
        ),
        10 => 
        array (
          'type' => 'const',
          'name' => 'XHTML5',
          'default' => 
          array (
            'type' => 'int',
            'value' => '11',
            'file' => '/app/phalcon/Html/Tag.zep',
            'line' => 87,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Html/Tag.zep',
          'line' => 91,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Html/Tag.zep',
      'line' => 27,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Tag.zep',
    'line' => 27,
    'char' => 5,
  ),
);