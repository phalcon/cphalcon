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
    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Html',
    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
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
        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
    'line' => 21,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Html\\Breadcrumbs
 *
 * This component offers an easy way to create breadcrumbs for your application.
 * The resulting HTML when calling `render()` will have each breadcrumb enclosed
 * in `<dt>` tags, while the whole string is enclosed in `<dl>` tags.
 *',
    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
    'line' => 22,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Breadcrumbs',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'elements',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
            'line' => 29,
            'char' => 26,
          ),
          'docblock' => '**
     * Keeps all the breadcrumbs
     *
     * @var array
     *',
          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
          'line' => 35,
          'char' => 6,
        ),
        1 => 
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
            'value' => ' / ',
            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
            'line' => 36,
            'char' => 29,
          ),
          'docblock' => '**
     * Crumb separator
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 36,
              'char' => 34,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 36,
              'char' => 40,
            ),
          ),
          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
          'line' => 42,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'template',
          'default' => 
          array (
            'type' => 'string',
            'value' => '<dt><a href=\\"%link%\\">%label%</a></dt>',
            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
            'line' => 43,
            'char' => 63,
          ),
          'docblock' => '**
     * The HTML template to use to render the breadcrumbs.
     *
     * @var string
     *',
          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
          'line' => 55,
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
          'name' => 'add',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'label',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 56,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'link',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 56,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 56,
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'elements',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'link',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 58,
                      'char' => 32,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'label',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 58,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 58,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 60,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 60,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 61,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a new crumb.
     *
     * ```php
     * // Adding a crumb with a link
     * $breadcrumbs->add("Home", "/");
     *
     * // Adding a crumb without a link (normally the last one)
     * $breadcrumbs->add("Users");
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
                  'value' => 'Breadcrumbs',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 57,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 57,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
            'line' => 57,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
          'line' => 56,
          'last-line' => 69,
          'char' => 19,
        ),
        1 => 
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
                  'property' => 'elements',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 72,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 72,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Clears the crumbs
     *
     * ```php
     * $breadcrumbs->clear()
     * ```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
            'line' => 71,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
          'line' => 70,
          'last-line' => 84,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'remove',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'link',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 85,
              'char' => 39,
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
                  'variable' => 'elements',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 87,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 89,
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
                  'variable' => 'elements',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 89,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'elements',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 89,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 89,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 89,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 91,
              'char' => 13,
            ),
            2 => 
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
                    'value' => 'elements',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 91,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'link',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 91,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 91,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 91,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 93,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'elements',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'elements',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 93,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 93,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 94,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes crumb by url.
     *
     * ```php
     * $breadcrumbs->remove("/admin/user/create");
     *
     * // remove a crumb without an url (last link)
     * $breadcrumbs->remove();
     * ```
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
            'line' => 86,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
          'line' => 85,
          'last-line' => 102,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'render',
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
                  'variable' => 'element',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 105,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'elements',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 105,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'lastLabel',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 105,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'lastUrl',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 105,
                  'char' => 50,
                ),
                4 => 
                array (
                  'variable' => 'output',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 105,
                  'char' => 58,
                ),
                5 => 
                array (
                  'variable' => 'template',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 105,
                  'char' => 68,
                ),
                6 => 
                array (
                  'variable' => 'url',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 105,
                  'char' => 73,
                ),
                7 => 
                array (
                  'variable' => 'urls',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 105,
                  'char' => 79,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 107,
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
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 107,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 107,
                  'char' => 27,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'elements',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 108,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'elements',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 108,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 108,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 108,
                  'char' => 39,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'template',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 109,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'template',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 109,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 109,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 109,
                  'char' => 39,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'urls',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_keys',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'elements',
                          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                          'line' => 110,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                        'line' => 110,
                        'char' => 44,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 110,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 110,
                  'char' => 45,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'lastUrl',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'end',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'urls',
                          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                          'line' => 111,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                        'line' => 111,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 111,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 111,
                  'char' => 34,
                ),
                5 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'lastLabel',
                  'expr' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'elements',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 112,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'lastUrl',
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 112,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 112,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 112,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 114,
              'char' => 13,
            ),
            2 => 
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
                    'value' => 'elements',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 114,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'lastUrl',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 114,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 114,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 114,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 116,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'elements',
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 116,
                'char' => 38,
              ),
              'key' => 'url',
              'value' => 'element',
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
                      'variable' => 'output',
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
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '%label%',
                                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                    'line' => 119,
                                    'char' => 28,
                                  ),
                                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                  'line' => 119,
                                  'char' => 28,
                                ),
                                1 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '%link%',
                                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                    'line' => 121,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                  'line' => 121,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                              'line' => 121,
                              'char' => 18,
                            ),
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 121,
                            'char' => 18,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'element',
                                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                    'line' => 123,
                                    'char' => 28,
                                  ),
                                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                  'line' => 123,
                                  'char' => 28,
                                ),
                                1 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'url',
                                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                    'line' => 125,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                  'line' => 125,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                              'line' => 125,
                              'char' => 18,
                            ),
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 125,
                            'char' => 18,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'template',
                              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                              'line' => 127,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 127,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                        'line' => 127,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 127,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 128,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 133,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 133,
                  'char' => 16,
                ),
                'right' => 
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
                        'value' => 'elements',
                        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                        'line' => 133,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 133,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 133,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 133,
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
                      'assign-type' => 'variable-append',
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
                            'type' => 'string',
                            'value' => '<dt>',
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 134,
                            'char' => 33,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'lastLabel',
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 134,
                            'char' => 45,
                          ),
                          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                          'line' => 134,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '</dt>',
                          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                          'line' => 134,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                        'line' => 134,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 134,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 135,
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
                      'assign-type' => 'variable-append',
                      'operator' => 'assign',
                      'variable' => 'output',
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
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '%label%',
                                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                    'line' => 138,
                                    'char' => 28,
                                  ),
                                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                  'line' => 138,
                                  'char' => 28,
                                ),
                                1 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '%link%',
                                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                    'line' => 140,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                  'line' => 140,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                              'line' => 140,
                              'char' => 18,
                            ),
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 140,
                            'char' => 18,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'lastLabel',
                                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                    'line' => 142,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                  'line' => 142,
                                  'char' => 30,
                                ),
                                1 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'lastUrl',
                                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                    'line' => 144,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                  'line' => 144,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                              'line' => 144,
                              'char' => 18,
                            ),
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 144,
                            'char' => 18,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'template',
                              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                              'line' => 146,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 146,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                        'line' => 146,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                      'line' => 146,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 147,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 149,
              'char' => 14,
            ),
            5 => 
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
                    'value' => '<dl>',
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 149,
                    'char' => 21,
                  ),
                  'right' => 
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
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => '<dt>',
                              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                              'line' => 149,
                              'char' => 36,
                            ),
                            'right' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                'line' => 149,
                                'char' => 43,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'separator',
                                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                                'line' => 149,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                              'line' => 149,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 149,
                            'char' => 54,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '</dt>',
                            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                            'line' => 149,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                          'line' => 149,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                        'line' => 149,
                        'char' => 61,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'output',
                          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                          'line' => 149,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                        'line' => 149,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                    'line' => 149,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 149,
                  'char' => 71,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => '</dl>',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 149,
                  'char' => 78,
                ),
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 149,
                'char' => 78,
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 150,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Renders and outputs breadcrumbs based on previously set template.
     *
     * ```php
     * echo $breadcrumbs->render();
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
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 104,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
            'line' => 104,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
          'line' => 103,
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
          'name' => 'toArray',
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
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 157,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'elements',
                  'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                  'line' => 157,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 157,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Html/Breadcrumbs.zep',
              'line' => 158,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal breadcrumbs array
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
                'file' => '/app/phalcon/Html/Breadcrumbs.zep',
                'line' => 156,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Html/Breadcrumbs.zep',
            'line' => 156,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Html/Breadcrumbs.zep',
          'line' => 155,
          'last-line' => 159,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Html/Breadcrumbs.zep',
      'line' => 22,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Html/Breadcrumbs.zep',
    'line' => 22,
    'char' => 5,
  ),
);